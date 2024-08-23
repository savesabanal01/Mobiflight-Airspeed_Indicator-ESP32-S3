#pragma once

#include "Arduino.h"

class Airspeed_Indicator
{
public:
    Airspeed_Indicator(uint8_t Pin1, uint8_t Pin2);
    void begin();
    void attach(uint16_t Pin3, char *init);
    void detach();
    void set(int16_t messageID, char *setPoint);
    void update();

private:
    bool    _initialised;
    uint8_t _pin1, _pin2, _pin3;
    float scaleValue(float x, float in_min, float in_max, float out_min, float out_max);
    void drawASIGauge();
    void setInstrumentBrightnessRatio(float ratio);
    void setAirspeed(float value);
    void setPowerSave(bool enabled);
    void setScreenRotation(int rotation);

    // Variables
    float startTime;
    float endTime;
    float trueAirSpeed = 0;
    uint16_t altitude = 0;
    float verticalAirSpeed = 0;
    float baroPressure = 0;
    float instrumentBrightness = 1;
    float instrumentBrightnessRatio = 0;
    float ASIneedleRotation = 0; // angle of rotation of needle based on the Indicated AirSpeed
    float airSpeed = 0;
    bool powerSaveFlag;
    int screenRotation = 3;
    int prevScreenRotation = 3;
};