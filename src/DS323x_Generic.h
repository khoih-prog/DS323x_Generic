/****************************************************************************************************************************
  DS323x_Generic.h

  For all Generic boards such as ESP8266, ESP32, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, RP2040-based boards
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, LAN8742A Ethernet modules/shields

  DS323x_Generic Arduino library for DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal.

  Based on and modified from Hideaki Tai's DS323x Library (https://github.com/hideakitai/DS323x)
  Built by Khoi Hoang https://github.com/khoih-prog/DS323x_Generic
  Licensed under MIT license

  Version: 1.3.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0  K Hoang      19/10/2020 Initial porting to many Generic boards using WiFi/Ethernet modules/shields.
  1.1.0  K Hoang      09/01/2021 Add examples for ESP32/ESP8266 using LittleFS/SPIFFS, and support to  AVR, UNO WiFi Rev2, etc.
                                 Fix compiler warnings.
  1.2.0  K Hoang      12/06/2021 Add support to RP2040-based boards and ESP32-S2/ESP32-C3
  1.2.1  K Hoang      26/06/2021 Using TimeLib instead of Time
  1.2.2  K Hoang      10/10/2021 Update `platform.ini` and `library.json`
  1.2.3  K Hoang      23/02/2022 Add ESP_Complex examples to update system time from RTC time. Optimize library.
  1.3.0  K Hoang      07/04/2022 Use Ethernet_Generic library as default. Add support to Portenta_H7 Ethernet and WiFi
  1.3.1  K Hoang      07/04/2022 Add support to Teensy 4.1 QNEthernet and NativeEthernet
 *****************************************************************************************************************************/

#pragma once

#ifndef DS323X_GENERIC_H
#define DS323X_GENERIC_H

#ifndef DS323X_GENERIC_VERSION
  #define DS323X_GENERIC_VERSION             "DS323x_Generic v1.3.1"

  #define DS323X_GENERIC_VERSION_MAJOR       1
  #define DS323X_GENERIC_VERSION_MINOR       3
  #define DS323X_GENERIC_VERSION_PATCH       1

  #define DS323X_GENERIC_VERSION_INT         1003001
#endif

#include <Wire.h>
#include "DateTime_Generic.h"

namespace ds323x_generic
{

template <typename WireType> class DS323x_
{
    static constexpr uint8_t I2C_ADDR = 0x68;
    static constexpr uint8_t MASK_HOUR_24H = 0b00111111;
    static constexpr uint8_t MASK_HOUR_12H = 0b00011111;
    static constexpr uint8_t MASK_MONTH = 0b00011111;
    static constexpr uint8_t MASK_ALARM_BIT = 0b10000000;
    static constexpr uint8_t MASK_ALARM_DAY = 0b00001111;
    static constexpr uint8_t MASK_ALARM_DATE = 0b00011111;
    // static constexpr uint8_t MASK_HOUR_FMT = 0b01000000;
    // static constexpr uint8_t MASK_HOUR_AMPM = 0b00100000;
    // static constexpr uint8_t MASK_CENTURY = 0b10000000;
    // static constexpr uint8_t MASK_OSF = 0b10000000;
    // static constexpr uint8_t MASK_EXC_OSF = 0b01111111;

    uint8_t mask_hour {MASK_HOUR_12H};
    uint8_t mask_a1_hour {MASK_HOUR_12H};
    uint8_t mask_a2_hour {MASK_HOUR_12H};
    uint8_t mask_a1_dydt {MASK_ALARM_DAY};
    uint8_t mask_a2_dydt {MASK_ALARM_DAY};

    DateTime datetime;
    DateTime datetime_a1;
    DateTime datetime_a2;

    WireType* wire;
    uint8_t status_;

  public:

    enum class Reg : uint8_t
    {
      SECONDS = 0x00,
      MINUTES,
      HOURS,
      DAY_OF_WEEK,
      DATE,
      MONTH_CENTURY,
      YEAR,
      A1_SECONDS,
      A1_MINUTES,
      A1_HOURS,
      A1_DAY_DATE,
      A2_MINUTES,
      A2_HOURS,
      A2_DAY_DATE,
      CONTROL,
      STATUS,
      AGING_OFFSET,
      MSB_TEMP,
      LSB_TEMP
    };

    enum class Format : uint8_t { H24, H12 };
    enum class AMPM :   uint8_t { RTC_AM, RTC_PM };
    enum class DYDT :   uint8_t { DATE, DAY };

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

    enum class InterruptCtrl :  uint8_t { SQW, ALARM };
    enum class AlarmSel :       uint8_t { A1, A2 };

    void attach(WireType& w)
    {
      wire = &w;
      mask_hour    = (format() == Format::H12) ? MASK_HOUR_12H : MASK_HOUR_24H;
      mask_a1_hour = (format(AlarmSel::A1) == Format::H12) ? MASK_HOUR_12H : MASK_HOUR_24H;
      mask_a2_hour = (format(AlarmSel::A2) == Format::H12) ? MASK_HOUR_12H : MASK_HOUR_24H;
      mask_a1_dydt = (dydt(AlarmSel::A1) == DYDT::DAY) ? MASK_ALARM_DAY : MASK_ALARM_DATE;
      mask_a2_dydt = (dydt(AlarmSel::A2) == DYDT::DAY) ? MASK_ALARM_DAY : MASK_ALARM_DATE;
    }


    // rtc getters

    DateTime now()
    {
      return DateTime(year(), month(), day(), hour(), minute(), second());
    }

    uint8_t second()
    {
      return bcd_to_dec(readByte(Reg::SECONDS));
    }

    uint8_t minute()
    {
      return bcd_to_dec(readByte(Reg::MINUTES));
    }

    uint8_t hour()
    {
      return bcd_to_dec(readByte(Reg::HOURS, mask_hour));
    }

    uint8_t weekday()
    {
      return bcd_to_dec(readByte(Reg::DAY_OF_WEEK));
    }

    uint8_t day()
    {
      return bcd_to_dec(readByte(Reg::DATE));
    }

    uint8_t month()
    {
      return (bcd_to_dec(readByte(Reg::MONTH_CENTURY, MASK_MONTH))) ;
    }

    uint8_t year()
    {
      return bcd_to_dec(readByte(Reg::YEAR));
    }

    AMPM ampm()
    {
      return readBit(Reg::HOURS, 5) ? AMPM::RTC_PM : AMPM::RTC_AM;
    }

    Format format()
    {
      return readBit(Reg::HOURS, 6) ? Format::H12 : Format::H24;
    }

    // rtc setters

    void now(const DateTime& n)
    {
      year(n.yearOffset());
      month(n.month());
      day(n.day());
      hour(n.hour());
      minute(n.minute());
      second(n.second());
    }

    bool second(const uint8_t& s)
    {
      return writeByte(Reg::SECONDS, dec_to_bcd(s));
    }

    bool minute(const uint8_t& m)
    {
      return writeByte(Reg::MINUTES, dec_to_bcd(m));
    }

    bool hour(const uint8_t& h)
    {
      return writeByte(Reg::HOURS, dec_to_bcd(h), mask_hour);
    }

    bool weekday(const uint8_t& w)
    {
      return writeByte(Reg::DAY_OF_WEEK, dec_to_bcd(w));
    }

    bool day(const uint8_t& d)
    {
      return writeByte(Reg::DATE, dec_to_bcd(d));
    }

    bool month(const uint8_t& m)
    {
      return writeByte(Reg::MONTH_CENTURY, dec_to_bcd(m));
    }

    bool year(const uint8_t& y)
    {
      return writeByte(Reg::YEAR, dec_to_bcd(y));
    }

    bool ampm(const AMPM& m)
    {
      return writeBit(Reg::HOURS, 5, (uint8_t)m);
    }

    bool format(const Format& f)
    {
      return writeBit(Reg::HOURS, 6, (uint8_t)f);
    }

    // alarm getters

    DateTime alarm(const AlarmSel& a)
    {
      return DateTime(0, 0, day(a), hour(a), minute(a), second(a));
    }

    uint8_t second(const AlarmSel& a)
    {
      if (a == AlarmSel::A2)
        return 0;

      return bcd_to_dec(readByte(Reg::A1_SECONDS, (uint8_t)~MASK_ALARM_BIT));
    }

    uint8_t minute(const AlarmSel& a)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_MINUTES : Reg::A2_MINUTES;

      return bcd_to_dec(readByte(r, (uint8_t)~MASK_ALARM_BIT));
    }

    uint8_t hour(const AlarmSel& a)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_HOURS : Reg::A2_HOURS;
      uint8_t m = (a == AlarmSel::A1) ? mask_a1_hour : mask_a2_hour;

      return bcd_to_dec(readByte(r, m));
    }

    uint8_t weekday(const AlarmSel& a)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_DAY_DATE : Reg::A2_DAY_DATE;
      uint8_t m = (a == AlarmSel::A1) ? mask_a1_dydt : mask_a2_dydt;

      return bcd_to_dec(readByte(r, m));
    }

    uint8_t day(const AlarmSel& a)
    {
      return weekday(a);
    }

    AMPM ampm(const AlarmSel& a)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_HOURS : Reg::A2_HOURS;

      return readBit(r, 5) ? AMPM::RTC_PM : AMPM::RTC_AM;
    }

    Format format(const AlarmSel& a)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_HOURS : Reg::A2_HOURS;

      return readBit(r, 6) ? Format::H12 : Format::H24;
    }

    DYDT dydt(const AlarmSel& a)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_DAY_DATE : Reg::A2_DAY_DATE;
      return readBit(r, 6) ? DYDT::DAY : DYDT::DATE;
    }

    bool a1m1()
    {
      return readBit(Reg::A1_SECONDS, 7)  != 0;
    }

    bool a1m2()
    {
      return readBit(Reg::A1_MINUTES, 7)  != 0;
    }

    bool a1m3()
    {
      return readBit(Reg::A1_HOURS, 7)    != 0;
    }

    bool a1m4()
    {
      return readBit(Reg::A1_DAY_DATE, 7) != 0;
    }

    A1Rate rateA1()
    {
      return checkRateA1(a1m1(), a1m2(), a1m3(), a1m4(), dydt(AlarmSel::A1));
    }

    bool a2m2()
    {
      return readBit(Reg::A2_MINUTES, 7)  != 0;
    }

    bool a2m3()
    {
      return readBit(Reg::A2_HOURS, 7)    != 0;
    }

    bool a2m4()
    {
      return readBit(Reg::A2_DAY_DATE, 7) != 0;
    }

    A2Rate rateA2()
    {
      return checkRateA2(a2m2(), a2m3(), a2m4(), dydt(AlarmSel::A2));
    }

    // alarm setters

    void alarm(const AlarmSel& a, const DateTime& n)
    {
      day(a, n.day());
      hour(a, n.hour());
      minute(a, n.minute());
      second(a, n.second());
    }

    bool second(const AlarmSel& a, const uint8_t& s)
    {
      if (a == AlarmSel::A2)
        return 0;

      return writeByte(Reg::A1_SECONDS, dec_to_bcd(s), (uint8_t)~MASK_ALARM_BIT);
    }

    bool minute(const AlarmSel& a, const uint8_t& m)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_MINUTES : Reg::A2_MINUTES;

      return writeByte(r, dec_to_bcd(m), (uint8_t)~MASK_ALARM_BIT);
    }

    bool hour(const AlarmSel& a, const uint8_t& h)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_HOURS : Reg::A2_HOURS;
      uint8_t m = (a == AlarmSel::A1) ? mask_a1_hour : mask_a2_hour;

      return writeByte(r, dec_to_bcd(h), m);
    }

    bool weekday(const AlarmSel& a, const uint8_t& w)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_DAY_DATE : Reg::A2_DAY_DATE;
      uint8_t m = (a == AlarmSel::A1) ? mask_a1_dydt : mask_a2_dydt;

      return writeByte(r, dec_to_bcd(w), m);
    }

    bool day(const AlarmSel& a, const uint8_t& d)
    {
      return weekday(a, d);
    }

    bool ampm(const AlarmSel& a, const AMPM& m)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_HOURS : Reg::A2_HOURS;

      return writeBit(r, 5, (uint8_t)m);
    }

    bool format(const AlarmSel& a, const Format& f)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_HOURS : Reg::A2_HOURS;

      return writeBit(r, 6, (uint8_t)f);
    }

    bool dydt(const AlarmSel& a, const DYDT& d)
    {
      Reg r = (a == AlarmSel::A1) ? Reg::A1_DAY_DATE : Reg::A2_DAY_DATE;

      return writeBit(r, 6, (uint8_t)d);
    }

    bool a1m1(const bool& b)
    {
      return writeBit(Reg::A1_SECONDS, 7, b);
    }

    bool a1m2(const bool& b)
    {
      return writeBit(Reg::A1_MINUTES, 7, b);
    }

    bool a1m3(const bool& b)
    {
      return writeBit(Reg::A1_HOURS, 7, b);
    }

    bool a1m4(const bool& b)
    {
      return writeBit(Reg::A1_DAY_DATE, 7, b);
    }

    bool rate(const A1Rate& a)
    {
      bool b = true;

      if (a == A1Rate::EVERY_SECOND)
      {
        b &= a1m1(true);
        b &= a1m2(true);
        b &= a1m3(true);
        b &= a1m4(true);
      }
      else if (a == A1Rate::MATCH_SECOND)
      {
        b &= a1m1(false);
        b &= a1m2(true);
        b &= a1m3(true);
        b &= a1m4(true);
      }
      else if (a == A1Rate::MATCH_SECOND_MINUTE)
      {
        b &= a1m1(false);
        b &= a1m2(false);
        b &= a1m3(true);
        b &= a1m4(true);
      }
      else if (a == A1Rate::MATCH_SECOND_MINUTE_HOUR)
      {
        b &= a1m1(false);
        b &= a1m2(false);
        b &= a1m3(false);
        b &= a1m4(true);
      }
      else if (a == A1Rate::MATCH_SECOND_MINUTE_HOUR_DATE)
      {
        b &= a1m1(false);
        b &= a1m2(false);
        b &= a1m3(false);
        b &= a1m4(false);
        b &= dydt(AlarmSel::A1, DYDT::DATE);
      }
      else if (a == A1Rate::MATCH_SECOND_MINUTE_HOUR_DAY)
      {
        b &= a1m1(false);
        b &= a1m2(false);
        b &= a1m3(false);
        b &= a1m4(false);
        b &= dydt(AlarmSel::A1, DYDT::DAY);
      }

      return b;
    }

    bool a2m2(const bool& b)
    {
      return writeBit(Reg::A2_MINUTES, 7, b);
    }

    bool a2m3(const bool& b)
    {
      return writeBit(Reg::A2_HOURS, 7, b);
    }

    bool a2m4(const bool& b)
    {
      return writeBit(Reg::A2_DAY_DATE, 7, b);
    }

    bool rate(const A2Rate& a)
    {
      bool b = true;

      if (a == A2Rate::EVERY_MINUTE)
      {
        b &= a2m2(true);
        b &= a2m3(true);
        b &= a2m4(true);
      }
      else if (a == A2Rate::MATCH_MINUTE)
      {
        b &= a2m2(false);
        b &= a2m3(true);
        b &= a2m4(true);
      }
      else if (a == A2Rate::MATCH_MINUTE_HOUR)
      {
        b &= a2m2(false);
        b &= a2m3(false);
        b &= a2m4(true);
      }
      else if (a == A2Rate::MATCH_MINUTE_HOUR_DATE)
      {
        b &= a2m2(false);
        b &= a2m3(false);
        b &= a2m4(false);
        b &= dydt(AlarmSel::A2, DYDT::DATE);
      }
      else if (a == A2Rate::MATCH_MINUTE_HOUR_DAY)
      {
        b &= a2m2(false);
        b &= a2m3(false);
        b &= a2m4(false);
        b &= dydt(AlarmSel::A2, DYDT::DAY);
      }

      return b;
    }

    // Control Registers

    // enable oscillator if RTC is powered only by battery power
    bool enableOscillator()
    {
      return !readBit(Reg::CONTROL, 7);
    }

    bool enableOscillator(const bool& b)
    {
      return writeBit(Reg::CONTROL, 7, !b);
    }

    // enable square wave even if Vcc < Vpf
    bool enableBatteryBackedSquareWave()
    {
      return readBit(Reg::CONTROL, 6);
    }

    bool enableBatteryBackedSquareWave(const bool& b)
    {
      return writeBit(Reg::CONTROL, 6, b);
    }

    // enable force temperature sensor to convert the temperature into digital code
    bool convertTemperature()
    {
      return readBit(Reg::CONTROL, 5);
    }

    bool convertTemperature(const bool& b)
    {
      return writeBit(Reg::CONTROL, 5, b);
    }

    SquareWaveFreq squareWaveFrequency()
    {
      uint8_t f = readBit(Reg::CONTROL, 3);
      f |= readBit(Reg::CONTROL, 4) << 1;

      return (SquareWaveFreq)f;
    }

    bool squareWaveFrequency(const SquareWaveFreq& f)
    {
      bool rs1 = (uint8_t)f & 0x01;
      bool rs2 = (uint8_t)f & 0x02;
      bool b = writeBit(Reg::CONTROL, 3, rs1);
      b &= writeBit(Reg::CONTROL, 4, rs2);

      return b;
    }

    InterruptCtrl interruptControl()
    {
      return (InterruptCtrl)(bool)readBit(Reg::CONTROL, 2);
    }

    bool interruptControl(const InterruptCtrl& i)
    {
      return writeBit(Reg::CONTROL, 2, (bool)i);
    }

    bool enableAlarm1()
    {
      return readBit(Reg::CONTROL, 0);
    }

    bool enableAlarm2()
    {
      return readBit(Reg::CONTROL, 1);
    }

    bool enableAlarm1(const bool& b)
    {
      return writeBit(Reg::CONTROL, 0, b);
    }

    bool enableAlarm2(const bool& b)
    {
      return writeBit(Reg::CONTROL, 1, b);
    }

    bool trigger()
    {
      // same as second(0)
      wire->beginTransmission(I2C_ADDR);
      wire->write(0);
      wire->write(0);
      status_ = wire->endTransmission();

      return (status_ == 0);
    }

    // Status Registers

    bool oscillatorStopFlag()
    {
      return readBit(Reg::STATUS, 7);
    }

    bool oscillatorStopFlag(const bool& b)
    {
      return writeBit(Reg::STATUS, 7, b);
    }

    bool enable32kHz()
    {
      return readBit(Reg::STATUS, 3);
    }

    bool enable32kHz(const bool& b)
    {
      return writeBit(Reg::STATUS, 3, b);
    }

    bool busy()
    {
      return readBit(Reg::STATUS, 2);
    }

    bool hasAlarmed(const AlarmSel& a)
    {
      return readBit(Reg::STATUS, (a == AlarmSel::A2));
    }

    bool clearAlarm(const AlarmSel& a)
    {
      return writeBit(Reg::STATUS, (a == AlarmSel::A2), 0);
    }

    int8_t agingOffset()
    {
      return (int8_t)readByte(Reg::AGING_OFFSET);
    }

    bool agingOffset(const int8_t& o)
    {
      return writeByte(Reg::AGING_OFFSET, (uint8_t)o);
    }

#if 1
    // Original from v0.1.1
    float temperature()
    {
      uint8_t val = readByte(Reg::MSB_TEMP);
      bool sign   = bool(val & 0x80);
      float temp  = float(sign ? -((uint8_t)~val + 1) : val);

      temp += float(readByte(Reg::LSB_TEMP) >> 6) * 0.25f;

      return temp;
    }
#else
    float temperature()
    {
      return ((float)(((uint16_t)readByte(Reg::MSB_TEMP) << 8) | (uint16_t)readByte(Reg::LSB_TEMP) >> 6)) * 0.25f;
    }
#endif

    /////////////////////////////////////////////////

  private:

    A1Rate checkRateA1(const bool& a1m1, const bool& a1m2, const bool& a1m3, const bool& a1m4, const DYDT& dydt)
    {
      if ( a1m1 &&  a1m2 &&  a1m3 &&  a1m4)
        return A1Rate::EVERY_SECOND;
      else if (!a1m1 &&  a1m2 &&  a1m3 &&  a1m4)
        return A1Rate::MATCH_SECOND;
      else if (!a1m1 && !a1m2 &&  a1m3 &&  a1m4)
        return A1Rate::MATCH_SECOND_MINUTE;
      else if (!a1m1 && !a1m2 && !a1m3 &&  a1m4)
        return A1Rate::MATCH_SECOND_MINUTE_HOUR;
      else if (!a1m1 && !a1m2 && !a1m3 && !a1m4)
      {
        if (dydt == DYDT::DATE)
          return A1Rate::MATCH_SECOND_MINUTE_HOUR_DATE;
        else
          return A1Rate::MATCH_SECOND_MINUTE_HOUR_DAY;
      }
      else
        // won't come here
        return A1Rate::EVERY_SECOND;
    }

    A2Rate checkRateA2(const bool& a2m2, const bool& a2m3, const bool& a2m4, const DYDT& dydt)
    {
      if ( a2m2 &&  a2m3 &&  a2m4)
        return A2Rate::EVERY_MINUTE;
      else if (!a2m2 &&  a2m3 &&  a2m4)
        return A2Rate::MATCH_MINUTE;
      else if (!a2m2 && !a2m3 &&  a2m4)
        return A2Rate::MATCH_MINUTE_HOUR;
      else if (!a2m2 && !a2m3 && !a2m4)
      {
        if (dydt == DYDT::DATE)
          return A2Rate::MATCH_MINUTE_HOUR_DATE;
        else
          return A2Rate::MATCH_MINUTE_HOUR_DAY;
      }
      else
        // won't come here
        return A2Rate::EVERY_MINUTE;
    }

    uint8_t dec_to_bcd(const uint8_t& v) const
    {
      return ((v / 10 * 16) + (v % 10));
    }

    uint8_t bcd_to_dec(const uint8_t& v) const
    {
      return ((v / 16 * 10) + (v % 16));
    }

    /////////////////////////////////////////////////

    // I2C utilities

    uint8_t status() const
    {
      return status_;
    }

    uint8_t readBit(const Reg& reg, const uint8_t& bit)
    {
      uint8_t b = readByte(reg);
      b &= (1 << bit);

      return b;
    }

    uint8_t readByte(const Reg& reg)
    {
      uint8_t data;
      readBytes(reg, 1, &data);

      return data;
    }

    uint8_t readByte(const Reg& reg, const uint8_t mask)
    {
      uint8_t data;
      readBytes(reg, 1, &data, &mask);

      return data;
    }

    uint16_t readWord(const Reg& reg)
    {
      uint16_t data;
      readWords(reg, 1, &data);

      return data;
    }

    uint16_t readWord(const Reg& reg, const uint16_t mask)
    {
      uint16_t data;
      readWords(reg, 1, &data, &mask);

      return data;
    }

    int8_t readBytes(const Reg& reg, const uint8_t& size, uint8_t *data)
    {
      wire->beginTransmission(I2C_ADDR);
      wire->write((uint8_t)reg);
      wire->endTransmission();

      wire->requestFrom((int) I2C_ADDR, (int) size);

      int8_t count = 0;

      while (wire->available())
        data[count++] = wire->read();

      return count;
    }

    int8_t readBytes(const Reg& reg, const uint8_t& size, uint8_t* data, const uint8_t* mask)
    {
      wire->beginTransmission(I2C_ADDR);
      wire->write((uint8_t)reg);
      wire->endTransmission();

      wire->requestFrom((int) I2C_ADDR, (int) size);

      int8_t count = 0;

      while (wire->available())
      {
        data[count] = wire->read() & mask[count];
        count++;
      }

      return count;
    }

    int8_t readWords(const Reg& reg, const uint8_t& size, const uint16_t *data)
    {
      wire->beginTransmission(I2C_ADDR);
      wire->write((uint8_t)reg);
      wire->endTransmission();
      wire->requestFrom(I2C_ADDR, (uint8_t)(size * 2));

      int8_t count = 0;
      bool msb = true;

      while (wire->available() && (count < size))
      {
        if (msb)
          data[count] = wire->read() << 8;
        else
          data[count++] |= wire->read();

        msb = !msb;
      }

      return count;
    }

    int8_t readWords(const Reg& reg, const uint8_t& size, const uint16_t *data, const uint16_t* mask)
    {
      wire->beginTransmission(I2C_ADDR);
      wire->write((uint8_t)reg);
      wire->endTransmission();
      wire->requestFrom(I2C_ADDR, (uint8_t)(size * 2));

      int8_t count = 0;
      bool msb = true;

      while (wire->available() && (count < size))
      {
        if (msb)
          data[count]  = wire->read() << 8;
        else
          data[count] |= wire->read();

        // Fix compile error in SAMD and nRF52 ???
        //data[count++] &= mask[count];
        data[count] = data[count] & mask[count];
        count++;

        msb = !msb;
      }

      return count;
    }

    bool writeBit(const Reg& reg, const uint8_t& bit, const uint8_t& data)
    {
      uint8_t b = readByte(reg);
      b = (data != 0) ? (b | (1 << bit)) : (b & ~(1 << bit));

      return writeByte(reg, b);
    }

    bool writeByte(const Reg& reg, const uint8_t data)
    {
      return writeBytes(reg, 1, &data);
    }

    bool writeByte(const Reg& reg, const uint8_t data, const uint8_t mask)
    {
      return writeBytes(reg, 1, &data, &mask);
    }

    bool writeWord(const Reg& reg, const uint16_t data)
    {
      return writeWords(reg, 1, &data);
    }

    bool writeWord(const Reg& reg, const uint16_t data, const uint16_t mask)
    {
      return writeWords(reg, 1, &data, &mask);
    }

    bool writeBytes(const Reg& reg, const uint8_t& size, const uint8_t* data)
    {
      wire->beginTransmission(I2C_ADDR);
      wire->write((uint8_t)reg);

      for (uint8_t i = 0; i < size; i++)
        wire->write(data[i]);

      status_ = wire->endTransmission();

      return (status_ == 0);
    }

    bool writeBytes(const Reg& reg, const uint8_t& size, const uint8_t* data, const uint8_t* mask)
    {
      uint8_t r[size];
      readBytes(reg, size, r);

      wire->beginTransmission(I2C_ADDR);
      wire->write((uint8_t)reg);

      for (uint8_t i = 0; i < size; i++)
        wire->write((data[i] & mask[i]) | (r[i] & ~mask[i]));

      status_ = wire->endTransmission();

      return (status_ == 0);
    }

    bool writeWords(const Reg& reg, const uint8_t& size, const uint16_t* data)
    {
      wire->beginTransmission(I2C_ADDR);
      wire->write((uint8_t)reg);

      for (uint8_t i = 0; i < size; i++)
      {
        wire->write((uint8_t)((data[i] >> 8) & 0x00FF));
        wire->write((uint8_t)((data[i] >> 0) & 0x00FF));
      }

      status_ = wire->endTransmission();

      return (status_ == 0);
    }

    bool writeWords(const Reg& reg, const uint8_t& size, const uint16_t* data, const uint16_t* mask = nullptr)
    {
      uint16_t r[size];
      readWords(reg, size, r);

      wire->beginTransmission(I2C_ADDR);
      wire->write((uint8_t)reg);

      for (uint8_t i = 0; i < size; i++)
      {
        data[i] = (data[i] & mask[i]) | (r[i] & ~mask[i]);
        wire->write((uint8_t)((data[i] >> 8) & 0x00FF));
        wire->write((uint8_t)((data[i] >> 0) & 0x00FF));
      }

      status_ = wire->endTransmission();

      return (status_ == 0);
    }

};

} // namespace ds323x_generic

using DS323x = ds323x_generic::DS323x_<TwoWire>;

#endif    // DS323X_GENERIC_H

