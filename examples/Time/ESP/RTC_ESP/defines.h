/****************************************************************************************************************************
  defines.h
  
  For ESP8266, ESP32
  
  DS323x_Generic Arduino library for DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal.
  
  Based on and modified from Hideaki Tai's DS323x Library (https://github.com/hideakitai/DS323x)
  Built by Khoi Hoang https://github.com/khoih-prog/DS323x_Generic
  Licensed under MIT license
  Version: 1.1.0
  
  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0  K Hoang      19/10/2020 Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
  1.1.0  K Hoang      09/01/2021 Add examples for ESP32/ESP8266 using LittleFS/SPIFFS, and support to  AVR, UNO WiFi Rev2, etc.
                                 Fix compiler warnings.
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if !(ESP32 || ESP8266)
  #error This code is designed to run on ESP32/ESP8266 platform! Please check your Tools->Board setting.
#endif 

#if (ESP8266)
  // For ESP8266
  #warning Use ESP8266 architecture
  #include <ESP8266mDNS.h>
  #include <ESP8266WiFi.h>
  #define ETHERNET_USE_ESP8266
  #define BOARD_TYPE      "ESP8266"
  
  #define USE_LITTLEFS      true
  #define USE_SPIFFS        false

#elif (ESP32)
  // For ESP32
  #warning Use ESP32 architecture
  #include <WiFi.h>
  #define ETHERNET_USE_ESP32
  #define BOARD_TYPE      "ESP32"
  
  #define W5500_RST_PORT   21

  #define USE_LITTLEFS      true
  #define USE_SPIFFS        false 
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    ARDUINO_BOARD
#endif

char ssid[] = "****";        // your network SSID (name)
char pass[] = "****";        // your network password

#endif    //defines_h
