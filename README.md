## DS323x_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/DS323x_Generic.svg?)](https://www.ardu-badge.com/DS323x_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/DS323x_Generic.svg)](https://github.com/khoih-prog/DS323x_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/DS323x_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/DS323x_Generic.svg)](http://github.com/khoih-prog/DS323x_Generic/issues)

---
---

### Why do we need this [DS323x_Generic library](https://github.com/khoih-prog/DS323x_Generic)

This is an Arduino library for DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal

The DS323x is a low-cost, extremely accurate I2C real-time clock (RTC) with an integrated temperature-compensated crystal oscillator (TCXO) and crystal. The device incorporates a battery input, and maintains accurate timekeeping when main power to the device is interrupted.

The examples will demonstrate how to get the UTC time from NTP server, then update the RTC to make sure the time is perfectly correct.

This [**DS323x_Generic library**](https://github.com/khoih-prog/DS323x_Generic) is based on and modified from [**Hideaki Tai's DS323x Library**](https://github.com/hideakitai/DS323x) to add functions and support to many boards and shields.

---

### Releases v1.0.0

1. Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
2. Add support to ESP8266, ESP32, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1 with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields.
3. Fix bug. Add functions.
4. Completely new examples.

#### Supported Boards

  - **ESP8266**
  - **ESP32**
  - **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox etc.**.
  - **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**.
  - **Adafruit SAM21 (Itsy-Bitsy M0, Metro M0, Feather M0, Gemma M0, etc.)**.
  - **Adafruit SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
  - **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
  - **STM32 (Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32F1, STM32F3, STM32F4, STM32H7, STM32L0, etc.)**.
  - **STM32F/L/H/G/WB/MP1 (Nucleo-64 L053R8,Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32Fx, STM32H7, STM32Lx, STM32Gx, STM32WB, STM32MP1, etc.) having 64K+ Flash program memory.**
  
#### Currently Supported WiFi Modules/Shields

  - **ESP8266 built-in WiFi**
  - **ESP32 built-in WiFi**
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or [ESP8266_AT_WebServer](https://github.com/khoih-prog/ESP8266_AT_WebServer) library**.
  
#### Currently Supported Ethernet Modules/Shields

  - **W5x00's using Ethernet, EthernetLarge, Ethernet2 or Ethernet3 Library.**
  - **ENC28J60 using EthernetENC or UIPEthernet library.**
  - **LAN8742A using STM32Ethernet / STM32 LwIP libraries.**

---
---

## Prerequisite

 1. [`Arduino IDE v1.8.13+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino AVR core v1.8.3+`](https://github.com/arduino/ArduinoCore-avr) for Arduino AVR boards. Use Arduino Board Manager to install.
 3. [`ESP32 core v1.0.4+`](https://github.com/espressif/arduino-esp32/releases) for ESP32 boards
 4. [`ESP8266 core v2.7.4+` for Arduino](https://github.com/esp8266/Arduino#installing-with-boards-manager) for ESP8266 boards. To use ESP8266 core 2.7.1+ for LittleFS.
 5. [`Teensy core v1.53+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. **Not ready in v1.0.0.**
 6. [`Arduino SAM DUE core v1.6.12+`](https://www.arduino.cc/en/Guide/ArduinoDue) for SAM DUE ARM Cortex-M3 boards
 7. [`Arduino SAMD core v1.8.9+`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards (Nano 33 IoT, etc.).
 8. [`Adafruit SAMD core v1.6.3+`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Itsy-Bitsy M4, etc.)
 9. [`Adafruit nRF52 v0.21.0+`](https://www.adafruit.com/) for nRF52 boards such as AdaFruit Feather nRF52840 Express, NINA_B302_ublox, etc.
10. [`Arduino Core for STM32 v1.9.0+`](https://github.com/khoih-prog/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. To install go to Arduino IDE, select Boards Manager, search for **`STM32`**
11. [`Seeeduino SAMD core v1.7.9+`](https://www.seeedstudio.com/) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.)
12. [Time v1.6+](https://github.com/PaulStoffregen/Time)
13. Depending on which Ethernet card you're using:
   - [`Ethernet library v2.0.0+`](https://www.arduino.cc/en/Reference/Ethernet) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500 (Deprecated, use Arduino Ethernet library).
   - [`Ethernet3 library v1.5.3+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
14. [`WiFiNINA_Generic library v1.7.1+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic) if using WiFiNINA for boards such as Nano 33 IoT, nRF52, Teensy, etc.
15. [`WiFiWebServer library v1.0.7+`](https://github.com/khoih-prog/WiFiWebServer) to use WiFi/WiFiNINA modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
16. [`EthernetWebServer library v1.0.13+`](https://github.com/khoih-prog/EthernetWebServer) to use Ethernet modules/shields on boards other than STM32F/L/H/G/WB/MP1. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer).
17. [`EthernetWebServer_STM32 library v1.0.6+`](https://github.com/khoih-prog/EthernetWebServer_STM32) to use Ethernet modules/shields on STM32F/L/H/G/WB/MP1 boards. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32).
18. [`ESP8266_AT_WebServer library v1.1.1+`](https://github.com/khoih-prog/ESP8266_AT_WebServer) to use ESP8266-AT/ESP32-AT WiFi modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP8266_AT_WebServer.svg?)](https://www.ardu-badge.com/ESP8266_AT_WebServer)


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
3. Install [**DS323x_Generic** library](https://platformio.org/lib/show/xxxxx/DS323x_Generic) by using [Library Manager](https://platformio.org/lib/show/xxxxx/DS323x_Generic/installation). Search for UPnP_Generic in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---
---

### Packages' Patches

 1. **To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 0.21.0](Packages_Patches/adafruit/hardware/nrf52/0.21.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0). 

Supposing the Adafruit nRF52 version is 0.21.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/0.21.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

 2. **To be able to compile and run on Teensy boards**, you have to copy the file [Teensy boards.txt](Packages_Patches/hardware/teensy/avr/boards.txt) into Teensy hardware directory (./arduino-1.8.12/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.12. This file must be copied into the directory:

- `./arduino-1.8.12/hardware/teensy/avr/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`

 3. **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

 4. **To be able to compile without error and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards**, you have to copy the whole [Arduino SAMD cores 1.8.9](Packages_Patches/arduino/hardware/samd/1.8.9) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.9).
 
Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- **`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- **`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`**
 
 This is mandatory to fix the **notorious Arduino SAMD compiler error**. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

 5. **To be able to automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards**, you have to copy the file [Adafruit SAMD platform.txt](Packages_Patches/adafruit/hardware/samd/1.6.3) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.6.3). 

Supposing the Adafruit SAMD core version is 1.6.3. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.6.3/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`

 6. **To be able to automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards**, you have to copy the file [Seeeduino SAMD platform.txt](Packages_Patches/Seeeduino/hardware/samd/1.7.9) into Adafruit samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.7.9). 

Supposing the Seeeduino SAMD core version is 1.7.9. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.7.9/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`

7. **To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/1.9.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_L053R8/variant.h`

---

### Libraries' Patches

1. If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

2. To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:

- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

3. To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:

- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)

4. To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for this [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:

- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

6. **To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library**, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- For [UIPEthernet v2.0.8](https://github.com/UIPEthernet/UIPEthernet)

  - [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
  - [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
  - [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
  - [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

- For [UIPEthernet v2.0.9](https://github.com/UIPEthernet/UIPEthernet)

  - [UIPEthernet.h](LibraryPatches/UIPEthernet-2.0.9/UIPEthernet.h)
  - [UIPEthernet.cpp](LibraryPatches/UIPEthernet-2.0.9/UIPEthernet.cpp)
  - [Enc28J60Network.h](LibraryPatches/UIPEthernet-2.0.9/utility/Enc28J60Network.h)
  - [Enc28J60Network.cpp](LibraryPatches/UIPEthernet-2.0.9/utility/Enc28J60Network.cpp)

7. To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.12/hardware/espressif/cores/esp32) to overwrite the old file:

- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

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
 
### 2. Time

 4. [**RTC_Ethernet**](examples/Time/Ethernet/RTC_Ethernet)
 5. [**RTC_STM32_Ethernet**](examples/Time/Ethernet/RTC_STM32_Ethernet)
 6. [**RTC_WiFiNINA**](examples/Time/WiFiNINA/RTC_WiFiNINA)

---
---


### Example [RTC_Ethernet](examples/Time/Ethernet/RTC_Ethernet)

#### 1. File [RTC_Ethernet.ino](examples/Time/Ethernet/RTC_Ethernet/RTC_Ethernet.ino)

```cpp

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

void getNTPTime(void)
{
  static bool gotCurrentTime = false;

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
      //rtc.now( DateTime(year(epoch_t), month(epoch_t), day(epoch_t), hour(epoch_t), minute(epoch_t), second(epoch_t) ) );
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

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart RTC_Ethernet on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));

  Wire.begin();

#if USE_ETHERNET_WRAPPER

  EthernetInit();

#else

#if USE_ETHERNET
  ET_LOGWARN(F("=========== USE_ETHERNET ==========="));
#elif USE_ETHERNET2
  ET_LOGWARN(F("=========== USE_ETHERNET2 ==========="));
#elif USE_ETHERNET3
  ET_LOGWARN(F("=========== USE_ETHERNET3 ==========="));
#elif USE_ETHERNET_LARGE
  ET_LOGWARN(F("=========== USE_ETHERNET_LARGE ==========="));
#elif USE_ETHERNET_ESP8266
  ET_LOGWARN(F("=========== USE_ETHERNET_ESP8266 ==========="));
#else
  ET_LOGWARN(F("========================="));
#endif

  ET_LOGWARN(F("Default SPI pinout:"));
  ET_LOGWARN1(F("MOSI:"), MOSI);
  ET_LOGWARN1(F("MISO:"), MISO);
  ET_LOGWARN1(F("SCK:"),  SCK);
  ET_LOGWARN1(F("SS:"),   SS);
  ET_LOGWARN(F("========================="));

#if defined(ESP8266)
  // For ESP8266, change for other boards if necessary
#ifndef USE_THIS_SS_PIN
#define USE_THIS_SS_PIN   D2    // For ESP8266
#endif

  ET_LOGWARN1(F("ESP8266 setCsPin:"), USE_THIS_SS_PIN);

#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
  // For ESP8266
  // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
  // Ethernet           0                 X            X            X            X        0
  // Ethernet2          X                 X            X            X            X        0
  // Ethernet3          X                 X            X            X            X        0
  // EthernetLarge      X                 X            X            X            X        0
  // Ethernet_ESP8266   0                 0            0            0            0        0
  // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
  // Must use library patch for Ethernet, EthernetLarge libraries
  Ethernet.init (USE_THIS_SS_PIN);

#elif USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
#ifndef ETHERNET3_MAX_SOCK_NUM
#define ETHERNET3_MAX_SOCK_NUM      4
#endif

  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

#elif USE_CUSTOM_ETHERNET

  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  Ethernet.init(USE_THIS_SS_PIN);

#endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#elif defined(ESP32)

  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  //Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

#ifndef USE_THIS_SS_PIN
#define USE_THIS_SS_PIN   22    // For ESP32
#endif

  ET_LOGWARN1(F("ESP32 setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
  // Must use library patch for Ethernet, EthernetLarge libraries
  // ESP32 => GPIO2,4,5,13,15,21,22 OK with Ethernet, Ethernet2, EthernetLarge
  // ESP32 => GPIO2,4,5,15,21,22 OK with Ethernet3

  //Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (USE_THIS_SS_PIN);

#elif USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
#ifndef ETHERNET3_MAX_SOCK_NUM
#define ETHERNET3_MAX_SOCK_NUM      4
#endif

  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

#elif USE_CUSTOM_ETHERNET

  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  Ethernet.init(USE_THIS_SS_PIN);

#endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#else   //defined(ESP8266)
  // unknown board, do nothing, use default SS = 10
#ifndef USE_THIS_SS_PIN
#define USE_THIS_SS_PIN   10    // For other boards
#endif

  ET_LOGWARN3(F("Board :"), BOARD_NAME, F(", setCsPin:"), USE_THIS_SS_PIN);

  // For other boards, to change if necessary
#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2  || USE_ETHERNET_ENC )
  // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries

  Ethernet.init (USE_THIS_SS_PIN);

#elif USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
#ifndef ETHERNET3_MAX_SOCK_NUM
#define ETHERNET3_MAX_SOCK_NUM      4
#endif

  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

#elif USE_CUSTOM_ETHERNET

  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  Ethernet.init(USE_THIS_SS_PIN);

#endif  //( USE_ETHERNET || USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE )

#endif    //defined(ESP8266)


#endif  //USE_ETHERNET_WRAPPER


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
#if USE_ETHERNET3
  Serial.print(F("SPI_CS:"));
  Serial.println(SPI_CS);
#endif
  Serial.println(F("========================="));

  Serial.print(F("Using mac index = "));
  Serial.println(index);

  // you're connected now, so print out the data
  Serial.print(F("You're connected to the network, IP = "));
  Serial.println(Ethernet.localIP());

  Udp.begin(localPort);

  rtc.attach(Wire);
}

void loop()
{
  // Get time from NTP once, then update RTC
  // You certainly can make NTP check every hour/day to update RTC ti have better accuracy
  getNTPTime();

  // Display time from RTC
  DateTime now = rtc.now();

  Serial.println("============================");

  time_t utc = now.get_time_t();
  time_t local = myTZ.toLocal(utc, &tcr);
  
  printDateTime(utc, "UTC");
  printDateTime(local, tcr -> abbrev);
  
  delay(10000);
}

```

---

#### 2. File [defines.h](examples/Time/Ethernet/RTC_Ethernet/defines.h)

```cpp
#ifndef defines_h
#define defines_h

#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       3

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
#if defined(ETHERNET_USE_SAMD)
#undef ETHERNET_USE_SAMD
#endif
#define ETHERNET_USE_SAMD      true
#endif

#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )
#if defined(ETHERNET_USE_NRF528XX)
#undef ETHERNET_USE_NRF528XX
#endif
#define ETHERNET_USE_NRF528XX      true
#endif

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
#if defined(ETHERNET_USE_SAM_DUE)
#undef ETHERNET_USE_SAM_DUE
#endif
#define ETHERNET_USE_SAM_DUE      true
#endif

#if defined(ETHERNET_USE_SAMD)
// For SAMD
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if ( defined(ARDUINO_SAMD_ZERO) && !defined(SEEED_XIAO_M0) )
#define BOARD_TYPE      "SAMD Zero"
#elif defined(ARDUINO_SAMD_MKR1000)
#define BOARD_TYPE      "SAMD MKR1000"
#elif defined(ARDUINO_SAMD_MKRWIFI1010)
#define BOARD_TYPE      "SAMD MKRWIFI1010"
#elif defined(ARDUINO_SAMD_NANO_33_IOT)
#define BOARD_TYPE      "SAMD NANO_33_IOT"
#elif defined(ARDUINO_SAMD_MKRFox1200)
#define BOARD_TYPE      "SAMD MKRFox1200"
#elif ( defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) )
#define BOARD_TYPE      "SAMD MKRWAN13X0"
#elif defined(ARDUINO_SAMD_MKRGSM1400)
#define BOARD_TYPE      "SAMD MKRGSM1400"
#elif defined(ARDUINO_SAMD_MKRNB1500)
#define BOARD_TYPE      "SAMD MKRNB1500"
#elif defined(ARDUINO_SAMD_MKRVIDOR4000)
#define BOARD_TYPE      "SAMD MKRVIDOR4000"
#elif defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
#define BOARD_TYPE      "SAMD ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS"
#elif defined(ADAFRUIT_FEATHER_M0_EXPRESS)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_FEATHER_M0_EXPRESS"
#elif defined(ADAFRUIT_METRO_M0_EXPRESS)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_METRO_M0_EXPRESS"
#elif defined(ADAFRUIT_CIRCUITPLAYGROUND_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_CIRCUITPLAYGROUND_M0"
#elif defined(ADAFRUIT_GEMMA_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_GEMMA_M0"
#elif defined(ADAFRUIT_TRINKET_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_TRINKET_M0"
#elif defined(ADAFRUIT_ITSYBITSY_M0)
#define BOARD_TYPE      "SAMD21 ADAFRUIT_ITSYBITSY_M0"
#elif defined(ARDUINO_SAMD_HALLOWING_M0)
#define BOARD_TYPE      "SAMD21 ARDUINO_SAMD_HALLOWING_M0"
#elif defined(ADAFRUIT_METRO_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_EXPRESS"
#elif defined(ADAFRUIT_GRAND_CENTRAL_M4)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_GRAND_CENTRAL_M4"
#elif defined(ADAFRUIT_FEATHER_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_FEATHER_M4_EXPRESS"
#elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_ITSYBITSY_M4_EXPRESS"
#define USE_THIS_SS_PIN       10
#elif defined(ADAFRUIT_TRELLIS_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_TRELLIS_M4_EXPRESS"
#elif defined(ADAFRUIT_PYPORTAL)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL"
#elif defined(ADAFRUIT_PYPORTAL_M4_TITANO)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL_M4_TITANO"
#elif defined(ADAFRUIT_PYBADGE_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_M4_EXPRESS"
#elif defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_AIRLIFT_LITE"
#elif defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_M4_EXPRESS"
#elif defined(ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS"
#elif defined(ADAFRUIT_PYBADGE_AIRLIFT_M4)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_AIRLIFT_M4"
#elif defined(ADAFRUIT_MONSTER_M4SK_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_MONSTER_M4SK_EXPRESS"
#elif defined(ADAFRUIT_HALLOWING_M4_EXPRESS)
#define BOARD_TYPE      "SAMD51 ADAFRUIT_HALLOWING_M4_EXPRESS"
#elif defined(SEEED_WIO_TERMINAL)
#define BOARD_TYPE      "SAMD SEEED_WIO_TERMINAL"
#elif defined(SEEED_FEMTO_M0)
#define BOARD_TYPE      "SAMD SEEED_FEMTO_M0"
#elif defined(SEEED_XIAO_M0)
#define BOARD_TYPE      "SAMD SEEED_XIAO_M0"
#ifdef USE_THIS_SS_PIN
#undef USE_THIS_SS_PIN
#endif
#define USE_THIS_SS_PIN       A1
#warning define SEEED_XIAO_M0 USE_THIS_SS_PIN == A1
#elif defined(Wio_Lite_MG126)
#define BOARD_TYPE      "SAMD SEEED Wio_Lite_MG126"
#elif defined(WIO_GPS_BOARD)
#define BOARD_TYPE      "SAMD SEEED WIO_GPS_BOARD"
#elif defined(SEEEDUINO_ZERO)
#define BOARD_TYPE      "SAMD SEEEDUINO_ZERO"
#elif defined(SEEEDUINO_LORAWAN)
#define BOARD_TYPE      "SAMD SEEEDUINO_LORAWAN"
#elif defined(SEEED_GROVE_UI_WIRELESS)
#define BOARD_TYPE      "SAMD SEEED_GROVE_UI_WIRELESS"
#elif defined(__SAMD21E18A__)
#define BOARD_TYPE      "SAMD21E18A"
#elif defined(__SAMD21G18A__)
#define BOARD_TYPE      "SAMD21G18A"
#elif defined(__SAMD51G19A__)
#define BOARD_TYPE      "SAMD51G19A"
#elif defined(__SAMD51J19A__)
#define BOARD_TYPE      "SAMD51J19A"
#elif defined(__SAMD51J20A__)
#define BOARD_TYPE      "SAMD51J20A"
#elif defined(__SAM3X8E__)
#define BOARD_TYPE      "SAM3X8E"
#elif defined(__CPU_ARC__)
#define BOARD_TYPE      "CPU_ARC"
#elif defined(__SAMD51__)
#define BOARD_TYPE      "SAMD51"
#else
#define BOARD_TYPE      "SAMD Unknown"
#endif

#elif (ETHERNET_USE_SAM_DUE)
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10
#define BOARD_TYPE      "SAM DUE"

#elif (ETHERNET_USE_NRF528XX)
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if defined(NRF52840_FEATHER)
#define BOARD_TYPE      "NRF52840_FEATHER"
#elif defined(NRF52832_FEATHER)
#define BOARD_TYPE      "NRF52832_FEATHER"
#elif defined(NRF52840_FEATHER_SENSE)
#define BOARD_TYPE      "NRF52840_FEATHER_SENSE"
#elif defined(NRF52840_ITSYBITSY)
#define BOARD_TYPE      "NRF52840_ITSYBITSY"
#define USE_THIS_SS_PIN   10    // For other boards
#elif defined(NRF52840_CIRCUITPLAY)
#define BOARD_TYPE      "NRF52840_CIRCUITPLAY"
#elif defined(NRF52840_CLUE)
#define BOARD_TYPE      "NRF52840_CLUE"
#elif defined(NRF52840_METRO)
#define BOARD_TYPE      "NRF52840_METRO"
#elif defined(NRF52840_PCA10056)
#define BOARD_TYPE      "NRF52840_PCA10056"
#elif defined(NINA_B302_ublox)
#define BOARD_TYPE      "NINA_B302_ublox"
#elif defined(NINA_B112_ublox)
#define BOARD_TYPE      "NINA_B112_ublox"
#elif defined(PARTICLE_XENON)
#define BOARD_TYPE      "PARTICLE_XENON"
#elif defined(ARDUINO_NRF52_ADAFRUIT)
#define BOARD_TYPE      "ARDUINO_NRF52_ADAFRUIT"
#else
#define BOARD_TYPE      "nRF52 Unknown"
#endif

#elif ( defined(CORE_TEENSY) )
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

#if defined(__IMXRT1062__)
// For Teensy 4.1/4.0
#define BOARD_TYPE      "TEENSY 4.1/4.0"
#elif defined(__MK66FX1M0__)
#define BOARD_TYPE "Teensy 3.6"
#elif defined(__MK64FX512__)
#define BOARD_TYPE "Teensy 3.5"
#elif defined(__MKL26Z64__)
#define BOARD_TYPE "Teensy LC"
#elif defined(__MK20DX256__)
#define BOARD_TYPE "Teensy 3.2" // and Teensy 3.1 (obsolete)
#elif defined(__MK20DX128__)
#define BOARD_TYPE "Teensy 3.0"
#elif defined(__AVR_AT90USB1286__)
#error Teensy 2.0++ not supported yet
#elif defined(__AVR_ATmega32U4__)
#error Teensy 2.0 not supported yet
#else
// For Other Boards
#define BOARD_TYPE      "Unknown Teensy Board"
#endif

#elif ( defined(ESP8266) )
// For ESP8266
#warning Use ESP8266 architecture
#include <ESP8266mDNS.h>
#define ETHERNET_USE_ESP8266
#define BOARD_TYPE      "ESP8266"

#elif ( defined(ESP32) )
// For ESP32
#warning Use ESP32 architecture
#define ETHERNET_USE_ESP32
#define BOARD_TYPE      "ESP32"

#define W5500_RST_PORT   21

#else
// For Mega
// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10
#define BOARD_TYPE            "AVR Mega"
#endif

#ifndef BOARD_NAME
#define BOARD_NAME    BOARD_TYPE
#endif

#include <SPI.h>

//#define USE_ETHERNET_WRAPPER    true
#define USE_ETHERNET_WRAPPER    false

// Use true  for ENC28J60 and UIPEthernet library (https://github.com/UIPEthernet/UIPEthernet)
// Use false for W5x00 and Ethernetx library      (https://www.arduino.cc/en/Reference/Ethernet)

#define USE_UIP_ETHERNET   true
//#define USE_UIP_ETHERNET   false

//#define USE_CUSTOM_ETHERNET     true

// Note: To rename ESP628266 Ethernet lib files to Ethernet_ESP8266.h and Ethernet_ESP8266.cpp
// In order to USE_ETHERNET_ESP8266
#if ( !defined(USE_UIP_ETHERNET) || !USE_UIP_ETHERNET )

// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
// You can define here or customize for each board at same place with BOARD_TYPE
// Check @ defined(SEEED_XIAO_M0)
//#define USE_THIS_SS_PIN   22  //21  //5 //4 //2 //15

// Only one of the following to be true
#define USE_ETHERNET          false
#define USE_ETHERNET2         false
#define USE_ETHERNET3         false
#define USE_ETHERNET_LARGE    false
#define USE_ETHERNET_ESP8266  false
#define USE_ETHERNET_ENC      true
#define USE_CUSTOM_ETHERNET   false

#if !USE_ETHERNET_WRAPPER

#if ( USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC )
#ifdef USE_CUSTOM_ETHERNET
#undef USE_CUSTOM_ETHERNET
#endif
#define USE_CUSTOM_ETHERNET   false //true
#endif

#if USE_ETHERNET3
#include "Ethernet3.h"
#warning Using Ethernet3 lib
#define SHIELD_TYPE           "W5x00 using Ethernet3 Library"
#elif USE_ETHERNET2
#include "Ethernet2.h"
#warning Using Ethernet2 lib
#define SHIELD_TYPE           "W5x00 using Ethernet2 Library"
#elif USE_ETHERNET_LARGE
#include "EthernetLarge.h"
#warning Using EthernetLarge lib
#define SHIELD_TYPE           "W5x00 using EthernetLarge Library"
#elif USE_ETHERNET_ESP8266
#include "Ethernet_ESP8266.h"
#warning Using Ethernet_ESP8266 lib
#define SHIELD_TYPE           "W5x00 using Ethernet_ESP8266 Library"
#elif USE_ETHERNET_ENC
#include "EthernetENC.h"
#warning Using EthernetENC lib
#define SHIELD_TYPE           "ENC28J60 using EthernetENC Library"
#elif USE_CUSTOM_ETHERNET
//#include "Ethernet_XYZ.h"
#include "EthernetENC.h"
#warning Using Custom Ethernet library. You must include a library and initialize.
#define SHIELD_TYPE           "Custom Ethernet using Ethernet_XYZ Library"
#else
#define USE_ETHERNET          true
#include "Ethernet.h"
#warning Using Ethernet lib
#define SHIELD_TYPE           "W5x00 using Ethernet Library"
#endif

// Ethernet_Shield_W5200, EtherCard, EtherSia not supported
// Select just 1 of the following #include if uncomment #define USE_CUSTOM_ETHERNET
// Otherwise, standard Ethernet library will be used for W5x00

#endif    //  USE_ETHERNET_WRAPPER
#elif USE_UIP_ETHERNET
#include "UIPEthernet.h"
#warning Using UIPEthernet library
#define SHIELD_TYPE           "ENC28J60 using UIPEthernet Library"
#endif      // #if !USE_UIP_ETHERNET

#include <EthernetWebServer.h>

#ifndef SHIELD_TYPE
#define SHIELD_TYPE     "Unknown Ethernet shield/library"
#endif

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x14 },
};

// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 222);

#endif    //defines_h
```


---
---

### Debug Termimal Output Samples

1. The following is debug terminal output when running example [**Alarm_Ethernet**](examples/Alarm/Ethernet/Alarm_Ethernet) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using EthernetENC Library

```
Start Alarm_Ethernet on NRF52840_FEATHER with ENC28J60 using EthernetENC Library
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

2. The following is debug terminal output when running example [**Alarm_STM32_Ethernet**](examples/Alarm/Ethernet/Alarm_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start Alarm_STM32_Ethernet on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
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

3. The following is debug terminal output when running example [**RTC_WiFiNINA**](examples/Time/WiFiNINA/RTC_WiFiNINA) on Arduino SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Start RTC_WiFiNINA on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
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

4. The following is debug terminal output when running example [**RTC_Ethernet**](examples/Time/Ethernet/RTC_Ethernet) on Adafruit NRF52840_FEATHER with W5500 using EthernetLarge Library

```
Start RTC_Ethernet on NRF52840_FEATHER with W5x00 using EthernetLarge Library
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

5. The following is debug terminal output when running example [**RTC_STM32_Ethernet**](examples/Time/Ethernet/RTC_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start RTC_STM32_Ethernet on NUCLEO_F767ZI, using LAN8742A Ethernet & STM32Ethernet Library
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

6. The following is debug terminal output when running example [**RTC_STM32_Ethernet**](examples/Time/Ethernet/RTC_STM32_Ethernet) on STM32F7 Nucleo-144 NUCLEO_F767ZI with W5500 using Ethernet2 Library


```
Start RTC_STM32_Ethernet on NUCLEO_F767ZI, using W5x00 & Ethernet2 Library
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

7. The following is debug terminal output when running example [**RTC_Ethernet**](examples/Time/Ethernet/RTC_Ethernet) on Arduino SAM DUE with W5500 using EthernetLarge Library

```
Start RTC_Ethernet on SAM DUE with W5x00 using EthernetLarge Library
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
---

## Releases

### Releases v1.0.0

1. Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
2. Add support to ESP8266, ESP32, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1 with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields.
3. Fix bug. Add functions.
4. Completely new examples.

#### Currently Supported Boards

  - **ESP8266**
  - **ESP32**
  - **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox etc.**.
  - **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**.
  - **Adafruit SAM21 (Itsy-Bitsy M0, Metro M0, Feather M0, Gemma M0, etc.)**.
  - **Adafruit SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
  - **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
  - **STM32 (Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32F1, STM32F3, STM32F4, STM32H7, STM32L0, etc.)**.
  - **STM32F/L/H/G/WB/MP1 (Nucleo-64 L053R8,Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32Fx, STM32H7, STM32Lx, STM32Gx, STM32WB, STM32MP1, etc.) having 64K+ Flash program memory.**
  
#### Currently Supported WiFi Modules/Shields

  - **ESP8266 built-in WiFi**
  - **ESP32 built-in WiFi**
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or [ESP8266_AT_WebServer](https://github.com/khoih-prog/ESP8266_AT_WebServer) library**.
  
#### Currently Supported Ethernet Modules/Shields

  - **W5x00's using Ethernet, EthernetLarge, Ethernet2 or Ethernet3 Library.**
  - **ENC28J60 using EthernetENC or UIPEthernet library.**
  - **LAN8742A using STM32Ethernet / STM32 LwIP libraries.**
  
---
---

### Issues ###

Submit issues to: [DS323x_Generic issues](https://github.com/khoih-prog/DS323x_Generic/issues)

---

### TO DO

1. Bug Searching and Killing
2. Add more examples


### DONE

 1. Add support to **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**
 2. Add support to **Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.)**.
 3. Add support to **Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
 4. Add support to **Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**.
 5. Add support to SAM DUE.
 6. Add support to Ethernet W5x00, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/adafruit/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 7. Add support to Ethernet ENC28J60, using [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
 8. Add support to ESP32 and ESP8266
 9. Add support to Seeeduino SAMD21/SAMD51: LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, Wio Terminal, Grove UI Wireless
10. Add support to [`EthernetENC`](https://github.com/jandrassy/EthernetENC)
 
---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on and modified from the [**Hideaki Tai's DS323x Library**](https://github.com/hideakitai/DS323x).

<table>
  <tr>
    <td align="center"><a href="https://github.com/hideakitai"><img src="https://github.com/hideakitai.png" width="100px;" alt="hideakitai"/><br /><sub><b>⭐️ Hideaki Tai</b></sub></a><br /></td>
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


