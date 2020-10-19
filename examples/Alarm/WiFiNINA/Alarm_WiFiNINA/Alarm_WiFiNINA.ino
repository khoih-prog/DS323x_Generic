/****************************************************************************************************************************
  Alarm_WiFiNINA.ino

  For all Generic boards such as ESP8266, ESP32, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields
  
  DS323x_Generic Arduino library for DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal.
  
  Based on and modified from Hideaki Tai's DS323x Library (https://github.com/hideakitai/DS323x)
  Built by Khoi Hoang https://github.com/khoih-prog/DS323x_Generic
  Licensed under MIT license
  Version: 1.0.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0  K Hoang      19/10/2020 Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
 *****************************************************************************************************************************/

#include "defines.h"

#include <Timezone_Generic.h>             // https://github.com/khoih-prog/Timezone_Generic

#include <DS323x_Generic.h>               // https://github.com/khoih-prog/DS323x_Generic

DS323x rtc;

//////////////////////////////////////////

// US Eastern Time Zone (New York, Detroit)
TimeChangeRule myDST = {"EDT", Second, Sun, Mar, 2, -240};    //Daylight time = UTC - 4 hours
TimeChangeRule mySTD = {"EST", First, Sun, Nov, 2, -300};     //Standard time = UTC - 5 hours
Timezone myTZ(myDST, mySTD);

TimeChangeRule *tcr;        //pointer to the time change rule, use to get TZ abbrev

//////////////////////////////////////////

int status = WL_IDLE_STATUS;      // the Wifi radio's status

char timeServer[]         = "time.nist.gov";  // NTP server
unsigned int localPort    = 2390;             // local port to listen for UDP packets

const int NTP_PACKET_SIZE = 48;       // NTP timestamp is in the first 48 bytes of the message
const int UDP_TIMEOUT     = 2000;     // timeout in miliseconds to wait for an UDP packet to arrive

byte packetBuffer[NTP_PACKET_SIZE];   // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;

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
      rtc.now( DateTime(epoch) );

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

  Serial.print("Alarm 1 is set to  : ");
  Serial.println(rtc.alarm(DS323x::AlarmSel::A1).timestamp(DateTime::TIMESTAMP_TIME));
  Serial.print("Alarm 1 alarm rate : ");
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
  
  Serial.print("Alarm 2 is set to  : ");
  Serial.println(rtc.alarm(DS323x::AlarmSel::A2).timestamp(DateTime::TIMESTAMP_TIME));
  Serial.print("Alarm 2 alarm rate : ");
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

  Serial.print("\nStart Alarm_WiFiNINA on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));

  Wire.begin();

  // check for the presence of the shield
#if USE_WIFI_NINA
  if (WiFi.status() == WL_NO_MODULE)
#else
  if (WiFi.status() == WL_NO_SHIELD)
#endif
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }

#if USE_WIFI_NINA
  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println(F("Please upgrade the firmware"));
  }
#endif

  // attempt to connect to WiFi network
  while ( status != WL_CONNECTED)
  {
    Serial.print(F("Connecting to WPA SSID: "));
    Serial.println(ssid);
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(WiFi.localIP());

  Udp.begin(localPort);

  rtc.attach(Wire);
}

bool setAlarmDone = false;

void setAlarm(void)
{
  // RTC is using UTC, so everything must use UTC, not local time
  
  // Valid when RTC is already correct
  DateTime currentTime = rtc.now();

  time_t utc = currentTime.get_time_t();

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
    Serial.println("============================");

    time_t utc = now.get_time_t();
    time_t local = myTZ.toLocal(utc, &tcr);

    printDateTime(utc, "UTC");
    printDateTime(local, tcr -> abbrev);
   
    // alarm flags must be cleard to get next alarm
    if (rtc.hasAlarmed(DS323x::AlarmSel::A1))
    {
      Serial.println("Alarm 1 activated");
      rtc.clearAlarm(DS323x::AlarmSel::A1);
    }

    if (rtc.hasAlarmed(DS323x::AlarmSel::A2))
    {
      Serial.println("Alarm 2 activated");
      rtc.clearAlarm(DS323x::AlarmSel::A2);
    }
  }
}
