## DS323x_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/DS323x_Generic.svg?)](https://www.ardu-badge.com/DS323x_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/DS323x_Generic.svg)](https://github.com/khoih-prog/DS323x_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/DS323x_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/DS323x_Generic.svg)](http://github.com/khoih-prog/DS323x_Generic/issues)

---
---

## Table of Contents

* [Why do we need this DS323x_Generic library](#why-do-we-need-this-ds323x_generic-library)
  * [Features](#features)
  * [Currently Supported Boards](#currently-supported-boards)
  * [Currently Supported WiFi Modules and Shields](#currently-supported-wifi-modules-and-shields)
  * [Currently Supported Ethernet Modules and Shields](#currently-supported-ethernet-modules-and-shields)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
  * [9. For Portenta_H7 boards using Arduino IDE in Linux](#9-for-portenta_h7-boards-using-arduino-ide-in-linux)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
  * [7. For fixing ESP32 compile error](#7-for-fixing-esp32-compile-error)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Usage](#usage)
  * [1. Time](#1-time)
  * [2. Square Wave](#2-square-wave)
  * [3. Alarm](#3-alarm)
* [Configurations](#configurations)
* [APIs](#apis)
* [Examples](#examples)
  * [1. Alarm](#1-Alarm) 
    * [1. **Alarm_Ethernet**](examples/Alarm/Ethernet/Alarm_Ethernet)
    * [2. **Alarm_STM32_Ethernet**](examples/Alarm/Ethernet/Alarm_STM32_Ethernet)
    * [3. **Alarm_WiFiNINA**](examples/Alarm/WiFiNINA/Alarm_WiFiNINA)
    * [4. **Alarm_ESP**](examples/Alarm/ESP/Alarm_ESP)
    * [5. **Alarm_ESP_Complex**](examples/Alarm/ESP/Alarm_ESP_Complex) **New**
  * [2. Time](#2-time)
    * [1. **RTC_Ethernet**](examples/Time/Ethernet/RTC_Ethernet)
    * [2. **RTC_STM32_Ethernet**](examples/Time/Ethernet/RTC_STM32_Ethernet)
    * [3. **RTC_WiFiNINA**](examples/Time/WiFiNINA/RTC_WiFiNINA)
    * [4. **RTC_ESP**](examples/Time/ESP/RTC_ESP)
    * [5. **RTC_ESP_Complex**](examples/Time/ESP/RTC_ESP_Complex) **New**
* [Example RTC_Ethernet](#example-rtc_ethernet)
  * [ 1. File RTC_Ethernet.ino](#1-file-rtc_ethernetino)
  * [ 2. File defines.h](#2-file-definesh) 
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [ 1. Alarm_Ethernet on NRF52840_FEATHER with ENC28J60](#1-alarm_ethernet-on-nrf52840_feather-with-enc28j60)
  * [ 2. Alarm_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A](#2-alarm_stm32_ethernet-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a)
  * [ 3. RTC_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA ](#3-rtc_wifinina-on-samd_nano_33_iot-with-wifinina)
  * [ 4. RTC_Ethernet on NRF52840_FEATHER with W5500](#4-rtc_ethernet-on-nrf52840_feather-with-w5500)
  * [ 5. RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A](#5-rtc_stm32_ethernet-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a)
  * [ 6. RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500](#6-rtc_stm32_ethernet-on-stm32f7-nucleo-144-nucleo_f767zi-with-w5500)
  * [ 7. RTC_Ethernet on SAM-DUE with W5500](#7-rtc_ethernet-on-sam-due-with-w5500)
  * [ 8. Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA](#8-alarm_wifinina-on-mbed-nano_rp2040_connect-with-wifinina)
  * [ 9. Alarm_Ethernet on MBED RASPBERRY_PI_PICO with W5500](#9-alarm_ethernet-on-mbed-raspberry_pi_pico-with-w5500)
  * [10. Alarm_Ethernet on RASPBERRY_PI_PICO with W5500](#10-alarm_ethernet-on-raspberry_pi_pico-with-w5500)
  * [11. RTC_ESP_Complex on ESP32_DEV](#11-RTC_ESP_Complex-on-ESP32_DEV)
  * [12. RTC_ESP_Complex on ESP8266_NODEMCU_ESP12E](#12-RTC_ESP_Complex-on-ESP8266_NODEMCU_ESP12E)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [DS323x_Generic library](https://github.com/khoih-prog/DS323x_Generic)

### Features

This is an Arduino library for **DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal**

The **DS323x** is a low-cost, extremely accurate I2C real-time clock (RTC) with an integrated temperature-compensated crystal oscillator (TCXO) and crystal. The device incorporates a battery input, and maintains accurate timekeeping when main power to the device is interrupted.

The examples will demonstrate how to get the UTC time from NTP server, then update the RTC to make sure the time is perfectly correct.

This [**DS323x_Generic library**](https://github.com/khoih-prog/DS323x_Generic) is based on and modified from [**Hideaki Tai's DS323x Library**](https://github.com/hideakitai/DS323x) to add functions and support to many boards and shields.

#### Currently Supported Boards

  - **ESP8266**
  - **ESP32 (including ESP32-S2 and ESP32-C3)**
  - **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox etc.**.
  - **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**.
  - **Adafruit SAM21 (Itsy-Bitsy M0, Metro M0, Feather M0, Gemma M0, etc.)**.
  - **Adafruit SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
  - **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
  - **STM32 (Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32F1, STM32F3, STM32F4, STM32H7, STM32L0, etc.)**.
  - **STM32F/L/H/G/WB/MP1 (Nucleo-64 L053R8,Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32Fx, STM32H7, STM32Lx, STM32Gx, STM32WB, STM32MP1, etc.) having 64K+ Flash program memory.**
  - **Arduino AVR boards (UNO, Nano, Mega, etc.)**
  - **Arduino MegaAVR boards (UNO WiFi Rev 2, Nano Every, etc.)**
  
#### Currently Supported WiFi Modules and Shields

  - **ESP8266 built-in WiFi**
  - **ESP32 built-in WiFi**
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or [ESP8266_AT_WebServer](https://github.com/khoih-prog/ESP8266_AT_WebServer) library**.
  
#### Currently Supported Ethernet Modules and Shields

  - **W5x00's using Ethernet, EthernetLarge, Ethernet2 or Ethernet3 Library.**
  - **ENC28J60 using EthernetENC or UIPEthernet library.**
  - **LAN8742A using STM32Ethernet / STM32 LwIP libraries.**
  
---
---


## Prerequisites

 1. [`Arduino IDE v1.8.19+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino AVR core 1.8.5+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) for AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 3. [`Arduino MegaAVR core v1.8.3+`](https://github.com/arduino/ArduinoCore-megaavr) for Arduino MegaAVR boards such as Arduino Uno WiFi Rev2. Use Arduino Board Manager to install. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-megaavr.svg)](https://github.com/arduino/ArduinoCore-megaavr/releases/latest)
 4. [`ESP32 Core 2.0.0+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 5. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS.
 6. [`Teensy core v1.56+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. **Not ready in v1.0.0.**
 7. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 8. [`Arduino SAMD core 1.8.12+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 9. [`Adafruit SAMD core 1.7.9+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
10. [`Seeeduino SAMD core 1.8.2+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)

11. [`Adafruit nRF52 v1.3.0`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
 
12. [`Arduino Core for STM32 v2.2.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)

13. [`Arduino mbed_rp2040 core 2.7.2+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino RP2040-based boards, such as **Arduino Nano RP2040 Connect, RASPBERRY_PI_PICO, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
14. [`Earle Philhower's arduino-pico core v1.12.0+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)


15. [`Time v1.6.1+`](https://github.com/PaulStoffregen/Time). [![GitHub release](https://img.shields.io/github/release/PaulStoffregen/Time.svg)](https://github.com/PaulStoffregen/Time/releases/latest)
16. Depending on which Ethernet card you're using:
   - [`Ethernet library v2.0.0+`](https://github.com/arduino-libraries/Ethernet) for W5100, W5200 and W5500.  [![GitHub release](https://img.shields.io/github/release/arduino-libraries/Ethernet.svg)](https://github.com/arduino-libraries/Ethernet/releases/latest)
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500. [![GitHub release](https://img.shields.io/github/release/adafruit/Ethernet2.svg)](https://github.com/adafruit/Ethernet2/releases/latest)
   - [`Ethernet3 library v1.5.5+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip. [![GitHub release](https://img.shields.io/github/release/sstaub/Ethernet3.svg)](https://github.com/sstaub/Ethernet3/releases/latest)
17. [`WiFiNINA_Generic library v1.8.14-3+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic) if using WiFiNINA for boards such as Nano 33 IoT, nRF52, Teensy, etc.
18. [`WiFiWebServer library v1.6.2+`](https://github.com/khoih-prog/WiFiWebServer) to use WiFi/WiFiNINA modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
19. [`EthernetWebServer library v2.0.0+`](https://github.com/khoih-prog/EthernetWebServer) to use Ethernet modules/shields on boards other than STM32F/L/H/G/WB/MP1. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer).
20. [`EthernetWebServer_STM32 library v1.3.3+`](https://github.com/khoih-prog/EthernetWebServer_STM32) to use Ethernet modules/shields on STM32F/L/H/G/WB/MP1 boards. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32).
21. [`ESP8266_AT_WebServer library v1.5.3+`](https://github.com/khoih-prog/ESP8266_AT_WebServer) to use ESP8266-AT/ESP32-AT WiFi modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP8266_AT_WebServer.svg?)](https://www.ardu-badge.com/ESP8266_AT_WebServer)
22. [`Timezone_Generic library v1.9.1+`](https://github.com/khoih-prog/Timezone_Generic) to use examples. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/Timezone_Generic.svg?)](https://www.ardu-badge.com/Timezone_Generic).

---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**DS323x_Generic**](https://github.com/khoih-prog/DS323x_Generic), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/DS323x_Generic.svg?)](https://www.ardu-badge.com/DS323x_Generic) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**DS323x_Generic**](https://github.com/khoih-prog/DS323x_Generic) page.
2. Download the latest release `DS323x_Generic-master.zip`.
3. Extract the zip file to `DS323x_Generic-master` directory 
4. Copy whole `DS323x_Generic-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**DS323x_Generic** library](https://registry.platformio.org/libraries/khoih-prog/DS323x_Generic) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/DS323x_Generic/installation). Search for **DS323x_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 Packages_Patches](Packages_Patches/adafruit/hardware/nrf52/1.3.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0). 

Supposing the Adafruit nRF52 version is 1.3.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.19/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.19. These files must be copied into the directory:

- `./arduino-1.8.19/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.12) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.12).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.12. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.12/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 5. For Adafruit SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the whole [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.9) directory into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.9). 

Supposing the Adafruit SAMD core version is 1.7.9. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.9/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.9/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.9/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the whole [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2). 

Supposing the Seeeduino SAMD core version is 1.8.2. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.2.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.2.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.2.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.2.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).


#### 9. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/2.7.2/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/2.7.2/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/2.7.2
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 2.7.2. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/2.7.2/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`



---

### Libraries' Patches

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

#### 7. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.12/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

#### 8. For STM32 core F3 and F4 using UIPEthernet library

Check if you need to install the UIPEthernet patch [new STM32 core F3/F4 compatibility](https://github.com/UIPEthernet/UIPEthernet/commit/c6d6519a260166b722b9cee5dd1f0fb2682e6782) to avoid errors `#include HardwareSPI.h` on some STM32 boards (Nucleo-32 F303K8, etc.)

---
---


### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

---
---


## Usage

### 1. Time

``` C++
#include <DS323x_Generic.h>

DS323x rtc;

void setup()
{
  Wire.begin();
  rtc.attach(Wire);
  rtc.now(DateTime(2020, 11, 23, 14, 23, 45));
}

void loop()
{
  DateTime now = rtc.now();
  Serial.println(now.timestamp());
  delay(1000);
}
```

### 2. Square Wave

``` C++
#include <DS323x_Generic.h>

DS323x rtc;

void setup()
{
  Wire.begin();
  rtc.attach(Wire);
  rtc.squareWaveFrequency(DS323x::SquareWaveFreq::SQWF_1_HZ);
  rtc.interruptControl(DS323x::InterruptCtrl::SQW); // default is ALRAM
  rtc.trigger(); // first falling edge comes 1sec after this (same as second(0))
}

void loop()
{
}
```

### 3. Alarm

``` C++
#include <DS323x_Generic.h>

DS323x rtc;

void setup()
{
  Wire.begin();
  rtc.attach(Wire);

  // set alarm
  rtc.second(DS323x::AlarmSel::A1, 56);
  rtc.rate(DS323x::A1Rate::MATCH_SECOND);

  // alarm flags must be cleard to get next alarm
  if (rtc.hasAlarmed(DS323x::AlarmSel::A1))
      rtc.clearAlarm(DS323x::AlarmSel::A1);

  // enable alarm
  rtc.interruptControl(DS323x::InterruptCtrl::ALARM);
  rtc.enableAlarm1(true);
}

void loop()
{
}

```

---
---

## Configurations

``` C++
enum class Format : uint8_t { H24, H12 };
enum class AMPM : uint8_t { AM, PM };
enum class DYDT : uint8_t { DATE, DAY };
enum class A1Rate : uint8_t
{
    EVERY_SECOND,
    MATCH_SECOND,
    MATCH_SECOND_MINUTE,
    MATCH_SECOND_MINUTE_HOUR,
    MATCH_SECOND_MINUTE_HOUR_DATE,
    MATCH_SECOND_MINUTE_HOUR_DAY
};
enum class A2Rate : uint8_t
{
    EVERY_MINUTE,
    MATCH_MINUTE,
    MATCH_MINUTE_HOUR,
    MATCH_MINUTE_HOUR_DATE,
    MATCH_MINUTE_HOUR_DAY
};
enum class SquareWaveFreq : uint8_t
{
    SQWF_1_HZ,
    SQWF_1024_HZ,
    SQWF_4096_HZ,
    SQWF_8192_HZ
};
enum class InterruptCtrl : uint8_t { SQW, ALARM };
enum class AlarmSel : uint8_t { A1, A2 };
```

---
---

## APIs

``` C++
void attach(WireType& w);

// rtc getters
DateTime now() const;
uint8_t second();
uint8_t minute();
uint8_t hour();
uint8_t weekday();
uint8_t day();
uint8_t month();
uint8_t year();
AMPM ampm();
Format format();

// rtc setters
void now(const DateTime& n);
bool second(const uint8_t s);
bool minute(const uint8_t m);
bool hour(const uint8_t h);
bool weekday(const uint8_t w);
bool day(const uint8_t d);
bool month(const uint8_t m);
bool year(const uint8_t y);
bool ampm(const AMPM m);
bool format(const Format f);

// alarm getters
const DateTime& alarm(const AlarmSel a);
uint8_t second(const AlarmSel a);
uint8_t minute(const AlarmSel a);
uint8_t hour(const AlarmSel a);
uint8_t weekday(const AlarmSel a);
uint8_t day(const AlarmSel a);
AMPM ampm(const AlarmSel a);
Format format(const AlarmSel a);
DYDT dydt(const AlarmSel a);
bool a1m1();
bool a1m2();
bool a1m3();
bool a1m4();
A1Rate rateA1();
bool a2m2();
bool a2m3();
bool a2m4();
A2Rate rateA2();

// alarm setters
void alarm(const AlarmSel a, const DateTime& n);
bool second(const AlarmSel a, const uint8_t s);
bool minute(const AlarmSel a, const uint8_t m);
bool hour(const AlarmSel a, const uint8_t h);
bool weekday(const AlarmSel a, const uint8_t w);
bool day(const AlarmSel a, const uint8_t d);
bool ampm(const AlarmSel a, const AMPM m);
bool format(const AlarmSel a, const Format f);
bool dydt(const AlarmSel a, const DYDT d);
bool a1m1(const bool b);
bool a1m2(const bool b);
bool a1m3(const bool b);
bool a1m4(const bool b);
bool rate(const A1Rate a);
bool a2m2(const bool b);
bool a2m3(const bool b);
bool a2m4(const bool b);
bool rate(const A2Rate a);

// Control Registers

// enable oscillator if RTC is powered only by battery power
bool enableOscillator();
bool enableOscillator(const bool b);
// enable square wave even if Vcc < Vpf
bool enableBatteryBackedSquareWave();
bool enableBatteryBackedSquareWave(const bool b);
// enable force temperature sensor to convert the temperature into digital code
bool convertTemperature();
bool convertTemperature(const bool b);
// square wave frequency
SquareWaveFreq squareWaveFrequency();
bool squareWaveFrequency(const SquareWaveFreq f);
// trigger timing of square wave
bool trigger();
// interrupt control
InterruptCtrl interruptControl();
bool interruptControl(const InterruptCtrl i);
// enable alarms
bool enableAlarm1();
bool enableAlarm2();
bool enableAlarm1(const bool b);
bool enableAlarm2(const bool b);

// Status Register

// getters
bool oscillatorStopFlag();
bool enable32kHz();
int8_t agingOffset();
bool busy();
bool hasAlarmed(const AlarmSel a);
float temperature();

// setters
bool oscillatorStopFlag(const bool b);
bool enable32kHz(const bool b);
bool agingOffset(const int8_t o);
bool clearAlarm(const AlarmSel a);
```


---
---

## Examples:

### 1. Alarm

 1. [**Alarm_Ethernet**](examples/Alarm/Ethernet/Alarm_Ethernet)
 2. [**Alarm_STM32_Ethernet**](examples/Alarm/Ethernet/Alarm_STM32_Ethernet)
 3. [**Alarm_WiFiNINA**](examples/Alarm/WiFiNINA/Alarm_WiFiNINA)
 4. [**Alarm_ESP**](examples/Alarm/ESP/Alarm_ESP)
 5. [**Alarm_ESP_Complex**](examples/Alarm/ESP/Alarm_ESP_Complex)
 
### 2. Time

 1. [**RTC_Ethernet**](examples/Time/Ethernet/RTC_Ethernet)
 2. [**RTC_STM32_Ethernet**](examples/Time/Ethernet/RTC_STM32_Ethernet)
 3. [**RTC_WiFiNINA**](examples/Time/WiFiNINA/RTC_WiFiNINA)
 4. [**RTC_ESP**](examples/Time/ESP/RTC_ESP)
 5. [**RTC_ESP_Complex**](examples/Time/ESP/RTC_ESP_Complex)

---
---


### Example [RTC_Ethernet](examples/Time/Ethernet/RTC_Ethernet)

#### 1. File [RTC_Ethernet.ino](examples/Time/Ethernet/RTC_Ethernet/RTC_Ethernet.ino)

https://github.com/khoih-prog/DS323x_Generic/blob/d9b6694e828fe33df1dfd31a9db494b83c4b091a/examples/Time/Ethernet/RTC_Ethernet/RTC_Ethernet.ino#L14-L385


---

#### 2. File [defines.h](examples/Time/Ethernet/RTC_Ethernet/defines.h)

https://github.com/khoih-prog/DS323x_Generic/blob/d9b6694e828fe33df1dfd31a9db494b83c4b091a/examples/Time/Ethernet/RTC_Ethernet/defines.h#L14-L418


---
---

### Debug Terminal Output Samples

### 1. Alarm_Ethernet on NRF52840_FEATHER with ENC28J60

The following is debug terminal output when running example [**Alarm_Ethernet**](examples/Alarm/Ethernet/Alarm_Ethernet) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library

```
Start Alarm_Ethernet on NRF52840_FEATHER with ENC28J60 using EthernetENC Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 25
[ETHERNET_WEBSERVER] MISO: 24
[ETHERNET_WEBSERVER] SCK: 26
[ETHERNET_WEBSERVER] SS: 5
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NRF52840_FEATHER , setCsPin: 10
=========================
Currently Used SPI pinout:
MOSI:25
MISO:24
SCK:26
SS:5
=========================
Using mac index = 6
You're connected to the network, IP = 192.168.2.97
Packet received
Seconds since Jan 1 1900 = 3812072094
Unix time = 1603083294
The UTC time is 4:54:54
Alarm 1 is set to  : 04:55:24
Alarm 1 alarm rate : 1
Alarm 2 is set to  : 04:55:00
Alarm 2 alarm rate : 2
============================
04:54:55 Mon 19 Oct 2020 UTC
00:54:55 Mon 19 Oct 2020 EDT
============================
04:54:56 Mon 19 Oct 2020 UTC
00:54:56 Mon 19 Oct 2020 EDT
============================
04:54:57 Mon 19 Oct 2020 UTC
00:54:57 Mon 19 Oct 2020 EDT
============================
04:54:58 Mon 19 Oct 2020 UTC
00:54:58 Mon 19 Oct 2020 EDT
============================
04:54:59 Mon 19 Oct 2020 UTC
00:54:59 Mon 19 Oct 2020 EDT
============================
04:55:00 Mon 19 Oct 2020 UTC
00:55:00 Mon 19 Oct 2020 EDT
Alarm 2 activated
============================
04:55:01 Mon 19 Oct 2020 UTC
00:55:01 Mon 19 Oct 2020 EDT
============================
04:55:02 Mon 19 Oct 2020 UTC
00:55:02 Mon 19 Oct 2020 EDT
============================
04:55:03 Mon 19 Oct 2020 UTC
00:55:03 Mon 19 Oct 2020 EDT
============================
...
============================
04:55:23 Mon 19 Oct 2020 UTC
00:55:23 Mon 19 Oct 2020 EDT
============================
04:55:24 Mon 19 Oct 2020 UTC
00:55:24 Mon 19 Oct 2020 EDT
Alarm 1 activated
============================
04:55:25 Mon 19 Oct 2020 UTC
00:55:25 Mon 19 Oct 2020 EDT
============================
```

---

### 2. Alarm_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A

The following is debug terminal output when running example [**Alarm_STM32_Ethernet**](examples/Alarm/Ethernet/Alarm_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start Alarm_STM32_Ethernet on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.159
Packet received
Seconds since Jan 1 1900 = 3812072751
Unix time = 1603083951
The UTC time is 5:05:51
Alarm 1 is set to  : 05:06:21
Alarm 1 alarm rate : 1
Alarm 2 is set to  : 05:06:00
Alarm 2 alarm rate : 2
============================
05:05:52 Mon 19 Oct 2020 UTC
01:05:52 Mon 19 Oct 2020 EDT
============================
05:05:52 Mon 19 Oct 2020 UTC
01:05:52 Mon 19 Oct 2020 EDT
============================
...
============================
05:06:00 Mon 19 Oct 2020 UTC
01:06:00 Mon 19 Oct 2020 EDT
Alarm 2 activated
============================
05:06:01 Mon 19 Oct 2020 UTC
01:06:01 Mon 19 Oct 2020 EDT
============================
...
============================
05:06:20 Mon 19 Oct 2020 UTC
01:06:20 Mon 19 Oct 2020 EDT
============================
05:06:21 Mon 19 Oct 2020 UTC
01:06:21 Mon 19 Oct 2020 EDT
Alarm 1 activated
============================
05:06:22 Mon 19 Oct 2020 UTC
01:06:22 Mon 19 Oct 2020 EDT
============================
```

---

### 3. RTC_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA 

The following is debug terminal output when running example [**RTC_WiFiNINA**](examples/Time/WiFiNINA/RTC_WiFiNINA) on Arduino SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Start RTC_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.128
Packet received
Seconds since Jan 1 1900 = 3812054945
Unix time = 1603066145
The UTC time is 0:09:05
============================
00:09:05 Mon 19 Oct 2020 UTC
20:09:05 Sun 18 Oct 2020 EDT
============================
00:09:14 Mon 19 Oct 2020 UTC
20:09:14 Sun 18 Oct 2020 EDT
```

---

### 4. RTC_Ethernet on NRF52840_FEATHER with W5500 

The following is debug terminal output when running example [**RTC_Ethernet**](examples/Time/Ethernet/RTC_Ethernet) on Adafruit NRF52840_FEATHER with W5500 using EthernetLarge Library

```
Start RTC_Ethernet on NRF52840_FEATHER with W5x00 using EthernetLarge Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
[ETHERNET_WEBSERVER] =========== USE_ETHERNET_LARGE ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 25
[ETHERNET_WEBSERVER] MISO: 24
[ETHERNET_WEBSERVER] SCK: 26
[ETHERNET_WEBSERVER] SS: 5
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : NRF52840_FEATHER , setCsPin: 10
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:25
MISO:24
SCK:26
SS:5
=========================
Using mac index = 3
You're connected to the network, IP = 192.168.2.99
Packet received
Seconds since Jan 1 1900 = 3812052464
Unix time = 1603063664
The UTC time is 23:27:44
============================
23:27:44 Sun 18 Oct 2020 UTC
19:27:44 Sun 18 Oct 2020 EDT
============================
23:27:53 Sun 18 Oct 2020 UTC
19:27:53 Sun 18 Oct 2020 EDT
```

---

### 5. RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A

The following is debug terminal output when running example [**RTC_STM32_Ethernet**](examples/Time/Ethernet/RTC_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start RTC_STM32_Ethernet on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.159
Packet received
Seconds since Jan 1 1900 = 3812054019
Unix time = 1603065219
The UTC time is 23:53:39
============================
23:53:39 Sun 18 Oct 2020 UTC
19:53:39 Sun 18 Oct 2020 EDT
============================
23:53:48 Sun 18 Oct 2020 UTC
19:53:48 Sun 18 Oct 2020 EDT
```

---

### 6. RTC_STM32_Ethernet on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500

The following is debug terminal output when running example [**RTC_STM32_Ethernet**](examples/Time/Ethernet/RTC_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500 using Ethernet2 Library


```
Start RTC_STM32_Ethernet on NUCLEO_F767ZI, using W5x00 & Ethernet2 Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
[ETHERNET_WEBSERVER] Board : NUCLEO_F767ZI , setCsPin: 10
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 11
[ETHERNET_WEBSERVER] MISO: 12
[ETHERNET_WEBSERVER] SCK: 13
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
You're connected to the network, IP = 192.168.2.117
Packet received
Seconds since Jan 1 1900 = 3812054437
Unix time = 1603065637
The UTC time is 0:00:37
============================
00:00:37 Mon 19 Oct 2020 UTC
20:00:37 Sun 18 Oct 2020 EDT
============================
00:00:46 Mon 19 Oct 2020 UTC
20:00:46 Sun 18 Oct 2020 EDT

```

---

### 7. RTC_Ethernet on SAM-DUE with W5500 

The following is debug terminal output when running example [**RTC_Ethernet**](examples/Time/Ethernet/RTC_Ethernet) on Arduino SAM DUE with W5500 using EthernetLarge Library

```
Start RTC_Ethernet on SAM DUE with W5x00 using EthernetLarge Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
[ETHERNET_WEBSERVER] =========== USE_ETHERNET_LARGE ===========
[ETHERNET_WEBSERVER] Default SPI pinout:
[ETHERNET_WEBSERVER] MOSI: 75
[ETHERNET_WEBSERVER] MISO: 74
[ETHERNET_WEBSERVER] SCK: 76
[ETHERNET_WEBSERVER] SS: 10
[ETHERNET_WEBSERVER] =========================
[ETHERNET_WEBSERVER] Board : SAM DUE , setCsPin: 10
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096
=========================
Currently Used SPI pinout:
MOSI:75
MISO:74
SCK:76
SS:10
=========================
Using mac index = 5
You're connected to the network, IP = 192.168.2.108
============================
18:30:45 Sun 18 Oct 2020 UTC
14:30:45 Sun 18 Oct 2020 EDT
```

---

### 8. Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA

The following is debug terminal output when running example [**Alarm_WiFiNINA**](examples/Alarm/WiFiNINA/Alarm_WiFiNINA) on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library

```
Start Alarm_WiFiNINA on MBED NANO_RP2040_CONNECT with WiFiNINA using WiFiNINA_Generic Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
Connecting to WPA SSID: HueNet1
You're connected to the network, IP = 192.168.2.153
Packet received
Seconds since Jan 1 1900 = 3832547372
Unix time = 1623558572
The UTC time is 4:29:32
Alarm 1 is set to  : 04:30:02
Alarm 1 alarm rate : 1
Alarm 2 is set to  : 04:30:00
Alarm 2 alarm rate : 2
============================
04:29:33 Sun 13 Jun 2021 UTC
00:29:33 Sun 13 Jun 2021 EDT
============================
04:29:34 Sun 13 Jun 2021 UTC
00:29:34 Sun 13 Jun 2021 EDT
...
============================
04:29:58 Sun 13 Jun 2021 UTC
00:29:58 Sun 13 Jun 2021 EDT
============================
04:29:59 Sun 13 Jun 2021 UTC
00:29:59 Sun 13 Jun 2021 EDT
============================
04:30:00 Sun 13 Jun 2021 UTC
00:30:00 Sun 13 Jun 2021 EDT
Alarm 2 activated
============================
04:30:01 Sun 13 Jun 2021 UTC
00:30:01 Sun 13 Jun 2021 EDT
============================
04:30:02 Sun 13 Jun 2021 UTC
00:30:02 Sun 13 Jun 2021 EDT
Alarm 1 activated
```

---

### 9. Alarm_Ethernet on MBED RASPBERRY_PI_PICO with W5500

The following is debug terminal output when running example [**Alarm_Ethernet**](examples/Alarm/Ethernet/Alarm_Ethernet) on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library

```
Start Alarm_Ethernet on MBED RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
[EWS] =========== USE_ETHERNET_LARGE ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 3
[EWS] MISO: 4
[EWS] SCK: 2
[EWS] SS: 5
[EWS] =========================
[EWS] Board : MBED RASPBERRY_PI_PICO , setCsPin: 5
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 5, new ss_pin = 10, W5100Class::ss_pin = 5
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:3
MISO:4
SCK:2
SS:5
=========================
Using mac index = 0
You're connected to the network, IP = 192.168.2.118
Packet received
Seconds since Jan 1 1900 = 3832545254
Unix time = 1623556454
The UTC time is 3:54:14
Alarm 1 is set to  : 03:54:44
Alarm 1 alarm rate : 1
Alarm 2 is set to  : 03:55:00
Alarm 2 alarm rate : 2
============================
03:54:15 Sun 13 Jun 2021 UTC
23:54:15 Sat 12 Jun 2021 EDT
============================
03:54:16 Sun 13 Jun 2021 UTC
23:54:16 Sat 12 Jun 2021 EDT
============================
03:54:17 Sun 13 Jun 2021 UTC
23:54:17 Sat 12 Jun 2021 EDT
...
============================
03:54:43 Sun 13 Jun 2021 UTC
23:54:43 Sat 12 Jun 2021 EDT
============================
03:54:44 Sun 13 Jun 2021 UTC
23:54:44 Sat 12 Jun 2021 EDT
Alarm 1 activated
============================
03:54:45 Sun 13 Jun 2021 UTC
23:54:45 Sat 12 Jun 2021 EDT
============================
03:54:46 Sun 13 Jun 2021 UTC
23:54:46 Sat 12 Jun 2021 EDT
...
============================
03:54:59 Sun 13 Jun 2021 UTC
23:54:59 Sat 12 Jun 2021 EDT
============================
03:55:00 Sun 13 Jun 2021 UTC
23:55:00 Sat 12 Jun 2021 EDT
Alarm 2 activated
============================
03:55:01 Sun 13 Jun 2021 UTC
23:55:01 Sat 12 Jun 2021 EDT

```


---

### 10. Alarm_Ethernet on RASPBERRY_PI_PICO with W5500

The following is debug terminal output when running example [**Alarm_Ethernet**](examples/Alarm/Ethernet/Alarm_Ethernet) on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library


```
Start Alarm_Ethernet on RASPBERRY_PI_PICO with W5x00 using EthernetLarge Library
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
[EWS] =========== USE_ETHERNET_LARGE ===========
[EWS] Default SPI pinout:
[EWS] MOSI: 19
[EWS] MISO: 16
[EWS] SCK: 18
[EWS] SS: 17
[EWS] =========================
[EWS] Board : RASPBERRY_PI_PICO , setCsPin: 17
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 17
W5100::init: W5500, SSIZE =8192
=========================
Currently Used SPI pinout:
MOSI:19
MISO:16
SCK:18
SS:17
=========================
Using mac index = 17
You're connected to the network, IP = 192.168.2.101
Packet received
Seconds since Jan 1 1900 = 3832544284
Unix time = 1623555484
The UTC time is 3:38:04
Alarm 1 is set to  : 03:38:34
Alarm 1 alarm rate : 1
Alarm 2 is set to  : 03:39:00
Alarm 2 alarm rate : 2
============================
03:38:05 Sun 13 Jun 2021 UTC
23:38:05 Sat 12 Jun 2021 EDT
============================
03:38:06 Sun 13 Jun 2021 UTC
23:38:06 Sat 12 Jun 2021 EDT
...
============================
03:38:33 Sun 13 Jun 2021 UTC
23:38:33 Sat 12 Jun 2021 EDT
============================
03:38:34 Sun 13 Jun 2021 UTC
23:38:34 Sat 12 Jun 2021 EDT
Alarm 1 activated
============================
03:38:35 Sun 13 Jun 2021 UTC
23:38:35 Sat 12 Jun 2021 EDT
============================
03:38:36 Sun 13 Jun 2021 UTC
23:38:36 Sat 12 Jun 2021 EDT
...
============================
03:38:59 Sun 13 Jun 2021 UTC
23:38:59 Sat 12 Jun 2021 EDT
============================
03:39:00 Sun 13 Jun 2021 UTC
23:39:00 Sat 12 Jun 2021 EDT
Alarm 2 activated
```

---

### 11. RTC_ESP_Complex on ESP32_DEV

The following is debug terminal output when running example [**RTC_ESP_Complex**](examples/Time/ESP/RTC_ESP_Complex) on `ESP32_DEV` to demonstrate how to update `system time` from `RTC time`


```
Start RTC_ESP_Complex on ESP32_DEV
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
Connecting to HueNet1
..............
You're connected to the network, IP = 192.168.2.93
Packet received
Seconds since Jan 1 1900 = 3854584816
Unix time = 1645596016
The UTC time is 6:00:16
============================
06:00:16 Wed 23 Feb 2022 UTC
01:00:16 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 06:00:16 2022

============================
06:00:25 Wed 23 Feb 2022 UTC
01:00:25 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 06:00:26 2022

============================
06:00:35 Wed 23 Feb 2022 UTC
01:00:35 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 06:00:36 2022

============================
06:00:45 Wed 23 Feb 2022 UTC
01:00:45 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 06:00:46 2022
```

---

### 12. RTC_ESP_Complex on ESP8266_NODEMCU_ESP12E

The following is debug terminal output when running example [**RTC_ESP_Complex**](examples/Time/ESP/RTC_ESP_Complex) on `ESP8266_NODEMCU_ESP12E` to demonstrate how to update `system time` from `RTC time`


```
Start RTC_ESP_Complex on ESP8266_NODEMCU_ESP12E
Timezone_Generic v1.9.1
DS323x_Generic v1.2.3
Connecting to HueNet1
...................
You're connected to the network, IP = 192.168.2.94
Packet received
Seconds since Jan 1 1900 = 3854581698
Unix time = 1645592898
The UTC time is 5:08:18
============================
05:08:18 Wed 23 Feb 2022 UTC
00:08:18 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 05:08:18 2022

============================
05:08:27 Wed 23 Feb 2022 UTC
00:08:27 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 05:08:28 2022

============================
05:08:37 Wed 23 Feb 2022 UTC
00:08:37 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 05:08:38 2022

============================
05:08:47 Wed 23 Feb 2022 UTC
00:08:47 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 05:08:48 2022

============================
05:08:57 Wed 23 Feb 2022 UTC
00:08:57 Wed 23 Feb 2022 EST
System Time UTC: Wed Feb 23 05:08:58 2022
```

---
---

### Issues

Submit issues to: [DS323x_Generic issues](https://github.com/khoih-prog/DS323x_Generic/issues)

---
---

### TO DO

1. Bug Searching and Killing
2. Add more examples

---

### DONE

 1. Add support to **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**
 2. Add support to **Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.)**.
 3. Add support to **Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
 4. Add support to **Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**.
 5. Add support to SAM DUE.
 6. Add support to Ethernet W5x00, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/adafruit/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 7. Add support to Ethernet ENC28J60, using [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
 8. Add support to ESP32 and ESP8266 using LittleFS or SPIFFS
 9. Add support to Seeeduino SAMD21/SAMD51: LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, Wio Terminal, Grove UI Wireless
10. Add support to [`EthernetENC`](https://github.com/jandrassy/EthernetENC)
11. Add support to Arduino AVR boards (UNO, Nano, Mega, etc.)
12. Add support to Arduino MegaAVR boards (UNO WiFi Rev 2, Nano Every, etc.)
13. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Earle Philhower's arduino-pico core**](https://github.com/earlephilhower/arduino-pico).
14. Add support to RP2040-based boards, such as **NANO_RP2040_CONNECT, RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed).
15. Add support to ESP32-S2/ESP32-C3
16. Optimize code by using passing by `reference` instead of by `value`
17. Add `ESP_Complex` examples to demonstrate how to update `system time` from `RTC` time. 


---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on and modified from the [**Hideaki Tai's DS323x Library**](https://github.com/hideakitai/DS323x).
2. Thanks to good work of [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) for initiating, inspriring, working with, developing, debugging and testing.
3. Thanks to [rnsi](https://github.com/rnsi) for the enhancement request [**setTime() does not set system time** #1](https://github.com/khoih-prog/DS323x_Generic/issues/1), leading to new version v1.2.3


<table>
  <tr>
    <td align="center"><a href="https://github.com/hideakitai"><img src="https://github.com/hideakitai.png" width="100px;" alt="hideakitai"/><br /><sub><b>⭐️ Hideaki Tai</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/rnsi"><img src="https://github.com/rnsi.png" width="100px;" alt="rnsi"/><br /><sub><b>rnsi</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/DS323x_Generic/blob/master/LICENSE)

---

## Copyright

- Copyright 2020- Hideaki Tai

- Copyright 2020- Khoi Hoang


