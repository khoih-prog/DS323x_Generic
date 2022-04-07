/****************************************************************************************************************************
  defines.h
  
  For ESP8266, ESP32
  
  DS323x_Generic Arduino library for DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal.
  
  Based on and modified from Hideaki Tai's DS323x Library (https://github.com/hideakitai/DS323x)
  Built by Khoi Hoang https://github.com/khoih-prog/DS323x_Generic
  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#if !(ESP32 || ESP8266)
  #error This code is designed to run on ESP32/ESP8266 platform! Please check your Tools->Board setting.
#endif 

#define _TZ_LOGLEVEL_                       2

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

char ssid[] = "HueNet1";        // your network SSID (name)
char pass[] = "jenniqqs";        // your network password
//char ssid[] = "YOUR_SSID";        // your network SSID (name)
//char pass[] = "12345678";        // your network password

#endif    //defines_h
