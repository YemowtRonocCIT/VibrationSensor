#ifndef VIBRATION_SENSOR_H
#define VIBRATION_SENSOR_H

class VibrationSensor {

public:
    void begin(int pin);
    float getVibrationReading();
    char convertReadingToChar(float vibration);

private:
    int _pin;
    
};

#endif