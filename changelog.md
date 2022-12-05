## DS323x_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/DS323x_Generic.svg?)](https://www.ardu-badge.com/DS323x_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/DS323x_Generic.svg)](https://github.com/khoih-prog/DS323x_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/DS323x_Generic/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/DS323x_Generic.svg)](http://github.com/khoih-prog/DS323x_Generic/issues)


<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.3.1](#releases-v131)
  * [Releases v1.3.0](#releases-v130)
  * [Releases v1.2.3](#releases-v123)
  * [Releases v1.2.2](#releases-v122)
  * [Releases v1.2.1](#releases-v121)
  * [Releases v1.2.0](#releases-v120)
  * [Releases v1.1.0](#releases-v110)
  * [Releases v1.0.0](#releases-v100)
  
---
---

## Changelog

### Releases v1.3.1

1. Add support to Teensy 4.1 QNEthernet and NativeEthernet

### Releases v1.3.0

1. Add support to `Portenta_H7 Ethernet and WiFi`
2. Use [Ethernet_Generic](https://github.com/khoih-prog/Ethernet_Generic) library as default for W5x00 Ethernet
3. Rewrite all examples for new features with better debug information.
4. Add examples `tzTest` and `WriteRules` and examples for `Portenta_H7 Ethernet and WiFi`
5. Update `Packages_Patches`

### Releases v1.2.3

1. Optimize code by using passing by `reference` instead of by `value`
2. Add `ESP_Complex` examples to update system time from RTC time. Check [setTime() does not set system time #1](https://github.com/khoih-prog/DS323x_Generic/issues/1)
3. Update `Packages' Patches`

### Releases v1.2.2

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Releases v1.2.1

1. Using TimeLib instead of Time to avoid case-insensitive issue with Windows and MacOS

### Releases v1.2.0

1. Add support to RP2040-based boards such as **NANO_RP2040_CONNECT, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040** using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico core**](https://github.com/earlephilhower/arduino-pico).
2. Add support to **ESP32-S2/ESP32-C3**

### Releases v1.1.0

1. Add examples for ESP32/ESP8266 using LittleFS/SPIFFS
2. Add support to AVR, UNO WiFi Rev2 boards.
3. Clean-up all compiler warnings possible.
4. Optimize library and examples to reduce memory usage by using Flash String whenever possible.
5. Add Table of Contents

### Releases v1.0.0

1. Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
2. Add support to **ESP8266, ESP32, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1** with **WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet** modules/shields.
3. Fix bug. Add functions.
4. Completely new examples.


