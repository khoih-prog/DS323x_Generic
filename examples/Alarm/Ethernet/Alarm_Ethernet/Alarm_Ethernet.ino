/****************************************************************************************************************************
  Alarm_Ethernet.ino

  For all Generic boards such as ESP8266, ESP32, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields
  
  DS323x_Generic Arduino library for DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal.
  
  Based on and modified from Hideaki Tai's DS323x Library (https://github.com/hideakitai/DS323x)
  Built by Khoi Hoang https://github.com/khoih-prog/DS323x_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

// Important Note: You have to modify and run example WriteRules in order to read from correct TZ file

#include "defines.h"

#include <Timezone_Generic.h>             // https://github.com/khoih-prog/Timezone_Generic

#include <DS323x_Generic.h>               // https://github.com/khoih-prog/DS323x_Generic

DS323x rtc;

//////////////////////////////////////////

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    //Daylight time = UTC - 4 hours
TimeChangeRule mySTD = {"EST", First,  Sun, Nov, 2, -300};     //Standard time = UTC - 5 hours
Timezone *myTZ;

TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev

//////////////////////////////////////////

char timeServer[]         = "time.nist.gov";  // NTP server
unsigned int localPort    = 2390;             // local port to listen for UDP packets

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message
const int UDP_TIMEOUT     = 2000;     // timeout in miliseconds to wait for an UDP packet to arrive

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

// send an NTP request to the time server at the given address
void sendNTPpacket(char *ntpSrv)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)

  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(ntpSrv, 123); //NTP requests are to port 123

  Udp.write(packetBuffer, NTP_PACKET_SIZE);

  Udp.endPacket();
}

bool gotCurrentTime = false;

void getNTPTime(void)
{  
  // Just get the correct ime once
  if (!gotCurrentTime)
  {
    sendNTPpacket(timeServer); // send an NTP packet to a time server
    // wait to see if a reply is available
    delay(1000);

    if (Udp.parsePacket())
    {
      Serial.println(F("Packet received"));
      // We've received a packet, read the data from it
      Udp.read(packetBuffer, NTP_PACKET_SIZE); // read the packet into the buffer

      //the timestamp starts at byte 40 of the received packet and is four bytes,
      // or two words, long. First, esxtract the two words:

      unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
      unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
      // combine the four bytes (two words) into a long integer
      // this is NTP time (seconds since Jan 1 1900):
      unsigned long secsSince1900 = highWord << 16 | lowWord;
      Serial.print(F("Seconds since Jan 1 1900 = "));
      Serial.println(secsSince1900);

      // now convert NTP time into everyday time:
      Serial.print(F("Unix time = "));
      // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
      const unsigned long seventyYears = 2208988800UL;
      // subtract seventy years:
      unsigned long epoch = secsSince1900 - seventyYears;

      // print Unix time:
      Serial.println(epoch);

      // Get the time_t from epoch
      time_t epoch_t = epoch;

      // set the system time to UTC
      // warning: assumes that compileTime() returns US EDT
      // adjust the following line accordingly if you're in another time zone
      setTime(epoch_t);

      // Update RTC
      // Can use either one of these functions
      
      // 1) DateTime(tmElements_t). Must create tmElements_t if not present
      //tmElements_t tm;
      //breakTime(epoch_t, tm);
      //rtc.now( DateTime(tm) );
      
      // 2) DateTime(year, month, day, hour, min, sec)
      //rtc.now( DateTime(year(epoch_t), month(epoch_t), day(epoch_t), hour(epoch_t), minute(epoch_t), second(epoch_t) ) );

      // 3) DateTime (time_t)
      //rtc.now( DateTime(epoch_t) );

      // 4) DateTime(unsigned long epoch). The best and easiest way
      rtc.now( DateTime((uint32_t) epoch) );

      // print the hour, minute and second:
      Serial.print(F("The UTC time is "));       // UTC is the time at Greenwich Meridian (GMT)
      Serial.print((epoch  % 86400L) / 3600); // print the hour (86400 equals secs per day)
      Serial.print(':');

      if (((epoch % 3600) / 60) < 10)
      {
        // In the first 10 minutes of each hour, we'll want a leading '0'
        Serial.print('0');
      }
      Serial.print((epoch  % 3600) / 60); // print the minute (3600 equals secs per minute)
      Serial.print(':');

      if ((epoch % 60) < 10)
      {
        // In the first 10 seconds of each minute, we'll want a leading '0'
        Serial.print('0');
      }
      Serial.println(epoch % 60); // print the second

      gotCurrentTime = true;
    }
    else
    {
      // wait ten seconds before asking for the time again
      delay(10000);
    }
  }
}

//////////////////////////////////////////

// format and print a time_t value, with a time zone appended.
void printDateTime(time_t t, const char *tz)
{
  char buf[32];
  char m[4];    // temporary storage for month string (DateStrings.cpp uses shared buffer)
  strcpy(m, monthShortStr(month(t)));
  sprintf(buf, "%.2d:%.2d:%.2d %s %.2d %s %d %s",
          hour(t), minute(t), second(t), dayShortStr(weekday(t)), day(t), m, year(t), tz);
  Serial.println(buf);
}

//////////////////////////////////////////

void set_RTC_Alarm1(DateTime& alarmTime)
{
  // set alarm1
  rtc.format(DS323x::AlarmSel::A1, DS323x::Format::H12);
  rtc.dydt(DS323x::AlarmSel::A1, DS323x::DYDT::DATE);

  rtc.ampm(DS323x::AlarmSel::A1, DS323x::AMPM::RTC_PM);
  //rtc.ampm(DS323x::AlarmSel::A1, DS323x::AMPM::AM);

  rtc.weekday(DS323x::AlarmSel::A1, 1);
  rtc.hour(DS323x::AlarmSel::A1, alarmTime.hour());
  rtc.minute(DS323x::AlarmSel::A1, alarmTime.minute());
  rtc.second(DS323x::AlarmSel::A1, alarmTime.second());
  rtc.rate(DS323x::A1Rate::MATCH_SECOND);
  //rtc.rate(DS323x::A1Rate::MATCH_SECOND_MINUTE_HOUR);

  Serial.print(F("Alarm 1 is set to  : "));
  Serial.println(rtc.alarm(DS323x::AlarmSel::A1).timestamp(DateTime::TIMESTAMP_TIME));
  Serial.print(F("Alarm 1 alarm rate : "));
  Serial.println((uint8_t)rtc.rateA1());

  // alarm flags must be cleard to get next alarm
  if (rtc.hasAlarmed(DS323x::AlarmSel::A1))
    rtc.clearAlarm(DS323x::AlarmSel::A1);

  // enable alarm1
  rtc.enableAlarm1(true);
}

void set_RTC_Alarm2(DateTime& alarmTime)
{
  // set alarm2
  rtc.format(DS323x::AlarmSel::A2, DS323x::Format::H24);
  rtc.dydt(DS323x::AlarmSel::A2, DS323x::DYDT::DAY);

  rtc.ampm(DS323x::AlarmSel::A2, DS323x::AMPM::RTC_PM);
  //rtc.ampm(DS323x::AlarmSel::A2, DS323x::AMPM::PM);

  rtc.day(DS323x::AlarmSel::A2, alarmTime.day());
  rtc.hour(DS323x::AlarmSel::A2, alarmTime.hour());
  rtc.minute(DS323x::AlarmSel::A2, alarmTime.minute());
  //rtc.rate(DS323x::A2Rate::MATCH_MINUTE);
  rtc.rate(DS323x::A2Rate::MATCH_MINUTE_HOUR);
  
  Serial.print(F("Alarm 2 is set to  : "));
  Serial.println(rtc.alarm(DS323x::AlarmSel::A2).timestamp(DateTime::TIMESTAMP_TIME));
  Serial.print(F("Alarm 2 alarm rate : "));
  Serial.println((uint8_t)rtc.rateA2());

  // alarm flags must be cleard to get next alarm
  if (rtc.hasAlarmed(DS323x::AlarmSel::A2))
    rtc.clearAlarm(DS323x::AlarmSel::A2);

  // enable alarm2
  rtc.enableAlarm2(true);
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  delay(200);

  Serial.print(F("\nStart Alarm_Ethernet on ")); Serial.print(BOARD_NAME);
  Serial.print(F(" with ")); Serial.println(SHIELD_TYPE);
  Serial.println(TIMEZONE_GENERIC_VERSION);
  Serial.println(DS323X_GENERIC_VERSION);

#if defined(PIN_WIRE_SDA)
  // Arduino core, ESP8266, Adafruit
  TZ_LOGWARN(F("Default DS323X pinout:"));
  TZ_LOGWARN1(F("SDA:"), PIN_WIRE_SDA);
  TZ_LOGWARN1(F("SCL:"), PIN_WIRE_SCL);
#elif defined(PIN_WIRE0_SDA)
  // arduino-pico core
  TZ_LOGWARN(F("Default DS323X pinout:"));
  TZ_LOGWARN1(F("SDA:"), PIN_WIRE0_SDA);
  TZ_LOGWARN1(F("SCL:"), PIN_WIRE0_SCL);
#elif defined(ESP32)
  // ESP32
  TZ_LOGWARN(F("Default DS323X pinout:"));
  TZ_LOGWARN1(F("SDA:"), SDA);
  TZ_LOGWARN1(F("SCL:"), SCL);
#endif

  Wire.begin();

#if USE_ETHERNET_PORTENTA_H7
  TZ_LOGWARN(F("======== USE_PORTENTA_H7_ETHERNET ========"));
#elif USE_NATIVE_ETHERNET
  TZ_LOGWARN(F("======== USE_NATIVE_ETHERNET ========"));
#elif USE_ETHERNET_GENERIC
  TZ_LOGWARN(F("=========== USE_ETHERNET_GENERIC ==========="));  
#elif USE_ETHERNET_ESP8266
  TZ_LOGWARN(F("=========== USE_ETHERNET_ESP8266 ==========="));
#elif USE_ETHERNET_ENC
  TZ_LOGWARN(F("=========== USE_ETHERNET_ENC ==========="));  
#else
  TZ_LOGWARN(F("========================="));
#endif

#if !(USE_NATIVE_ETHERNET || USE_ETHERNET_PORTENTA_H7)
  TZ_LOGWARN(F("Default SPI pinout:"));
  TZ_LOGWARN1(F("MOSI:"), MOSI);
  TZ_LOGWARN1(F("MISO:"), MISO);
  TZ_LOGWARN1(F("SCK:"),  SCK);
  TZ_LOGWARN1(F("SS:"),   SS);
  TZ_LOGWARN(F("========================="));

#if defined(ESP8266)
  // For ESP8266, change for other boards if necessary
  #ifndef USE_THIS_SS_PIN
    #define USE_THIS_SS_PIN   D2    // For ESP8266
  #endif

  TZ_LOGWARN1(F("ESP8266 setCsPin:"), USE_THIS_SS_PIN);

  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
    // For ESP8266
    // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
    // EthernetGeneric    X                 X            X            X            X        0
    // Ethernet_ESP8266   0                 0            0            0            0        0
    // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
    // Must use library patch for Ethernet, EthernetLarge libraries
    Ethernet.init (USE_THIS_SS_PIN);

  #elif USE_CUSTOM_ETHERNET
  
    // You have to add initialization for your Custom Ethernet here
    // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
    Ethernet.init(USE_THIS_SS_PIN);
  
  #endif  //( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )

#elif defined(ESP32)

  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  //Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

  #ifndef USE_THIS_SS_PIN
    #define USE_THIS_SS_PIN   5   //22    // For ESP32
  #endif

  TZ_LOGWARN1(F("ESP32 setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
    // Must use library patch for Ethernet, EthernetLarge libraries
    // ESP32 => GPIO2,4,5,13,15,21,22 OK with Ethernet, Ethernet2, EthernetLarge
    // ESP32 => GPIO2,4,5,15,21,22 OK with Ethernet3
  
    //Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (USE_THIS_SS_PIN);
  
  #elif USE_CUSTOM_ETHERNET
  
    // You have to add initialization for your Custom Ethernet here
    // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
    Ethernet.init(USE_THIS_SS_PIN); 
  
  #endif  //( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )

#elif ETHERNET_USE_RPIPICO

  pinMode(USE_THIS_SS_PIN, OUTPUT);
  digitalWrite(USE_THIS_SS_PIN, HIGH);
  
  // ETHERNET_USE_RPIPICO, use default SS = 5 or 17
  #ifndef USE_THIS_SS_PIN
    #if defined(ARDUINO_ARCH_MBED)
      #define USE_THIS_SS_PIN   17     // For Arduino Mbed core
    #else  
      #define USE_THIS_SS_PIN   17    // For E.Philhower core
    #endif
  #endif

  TZ_LOGWARN1(F("RPIPICO setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
    // Must use library patch for Ethernet, EthernetLarge libraries
    // For RPI Pico using Arduino Mbed RP2040 core
    // SCK: GPIO2,  MOSI: GPIO3, MISO: GPIO4, SS/CS: GPIO5
    // For RPI Pico using E. Philhower RP2040 core
    // SCK: GPIO18,  MOSI: GPIO19, MISO: GPIO16, SS/CS: GPIO17
    // Default pin 5/17 to SS/CS
  
    //Ethernet.setCsPin (USE_THIS_SS_PIN);
    Ethernet.init (USE_THIS_SS_PIN);
     
  #endif    //( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )

#else   //defined(ESP8266)
  // unknown board, do nothing, use default SS = 10
  #ifndef USE_THIS_SS_PIN
    #define USE_THIS_SS_PIN   10    // For other boards
  #endif

  #if defined(BOARD_NAME)
    TZ_LOGWARN3(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);
  #else
    TZ_LOGWARN1(F("Unknown board setCsPin:"), USE_THIS_SS_PIN);
  #endif

  // For other boards, to change if necessary
  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC || USE_NATIVE_ETHERNET )
    // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries
  
    Ethernet.init (USE_THIS_SS_PIN);
  
  #elif USE_CUSTOM_ETHERNET
  
    // You have to add initialization for your Custom Ethernet here
    // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
    Ethernet.init(USE_THIS_SS_PIN);
    
  #endif  //( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )

#endif    // defined(ESP8266)

#endif    // #if !(USE_NATIVE_ETHERNET)


  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  // Just info to know how to connect correctly
  Serial.println(F("========================="));
  Serial.println(F("Currently Used SPI pinout:"));
  Serial.print(F("MOSI:"));
  Serial.println(MOSI);
  Serial.print(F("MISO:"));
  Serial.println(MISO);
  Serial.print(F("SCK:"));
  Serial.println(SCK);
  Serial.print(F("SS:"));
  Serial.println(SS);
  Serial.println(F("========================="));

  Serial.print(F("Using mac index = "));
  Serial.println(index);

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(Ethernet.localIP());

  myTZ = new Timezone(myDST, mySTD);

  // Comment out for first time run to write TZ rule to filesystem
  myTZ->writeRules(0);    // write rules to address/offset 0

  Udp.begin(localPort);

  rtc.attach(Wire);
}

bool setAlarmDone = false;

void setAlarm(void)
{
  // RTC is using UTC, so everything must use UTC, not local time
  
  // Valid when RTC is already correct
  DateTime currentTime = rtc.now();

  time_t utc    = currentTime.get_time_t();

  // Alarm 1 time is 30s from now
  DateTime alarm1 = DateTime(utc + 30);

  // Alarm 2 time is start of next minute from now
  DateTime alarm2 = DateTime(utc + 60);

  set_RTC_Alarm1(alarm1);
  set_RTC_Alarm2(alarm2);

  setAlarmDone = true;
}

void loop()
{
  // Get time from NTP once, then update RTC
  // You certainly can make NTP check every hour/day to update RTC ti have better accuracy
  getNTPTime();

  if (!setAlarmDone && gotCurrentTime)
  {
    setAlarm();
  }

  static uint32_t prev_ms = millis();

  if (millis() > prev_ms + 1000)
  {
    prev_ms = millis();
    
    DateTime now = rtc.now();
    Serial.println(F("============================"));

    time_t utc = now.get_time_t();
    time_t local = myTZ->toLocal(utc, &tcr);

    printDateTime(utc, "UTC");
    printDateTime(local, tcr -> abbrev);
   
    // alarm flags must be cleard to get next alarm
    if (rtc.hasAlarmed(DS323x::AlarmSel::A1))
    {
      Serial.println(F("Alarm 1 activated"));
      rtc.clearAlarm(DS323x::AlarmSel::A1);
    }

    if (rtc.hasAlarmed(DS323x::AlarmSel::A2))
    {
      Serial.println(F("Alarm 2 activated"));
      rtc.clearAlarm(DS323x::AlarmSel::A2);
    }
  }
}
