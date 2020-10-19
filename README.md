# DS323x

Arduino library for DS3231/DS3232 Extremely Accurate I2C-Integrated RTC/TCXO/Crystal


## Usage

### Time

``` C++
#include <DS323x.h>
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

### Square Wave

``` C++
#include <DS323x.h>
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

## Alarm

``` C++
#include <DS323x.h>
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

## License

MIT
