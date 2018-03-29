#include "VibrationSensor.h"
#include <Arduino.h>

void VibrationSensor::begin(int pin) {
    this->_pin = pin;
}

float VibrationSensor::getVibrationReading() {
    int piezoADC = analogRead(this->_pin);
    float piezoV = piezoADC / 1023.0 * 50.0;
    return piezoV;
}

char VibrationSensor::convertReadingToChar(float vibration) {
    const char ZERO_READING = 'Z';
    const char TEN_READING = 'B';
    const char TWENTY_READING = 'C';
    const char THIRTY_READING = 'D';
    const char FORTY_READING = 'E';
    const char FIFTY_READING = 'F';
    const char SIXTY_READING = 'G';
    const char SEVENTY_READING = 'H';
    const char EIGHTY_READING = 'I';
    const char NINETY_READING = 'J';
    const char HUNDRED_READING = 'K';
    const char OFF_SCALE_READING = 'L';

    char character = ZERO_READING;
    int i_vibration = (int) (vibration * 100);

    if (i_vibration == 0) {
        character = ZERO_READING;
    }
    else if (i_vibration <= 10) {
        character = TEN_READING;
    }
    else if (i_vibration <= 20) {
        character = TWENTY_READING;
    }
    else if (i_vibration <= 30) {
        character = THIRTY_READING;
    }
    else if (i_vibration <= 40) {
        character = FORTY_READING;
    }
    else if (i_vibration <= 50) {
        character = FIFTY_READING;
    }
    else if (i_vibration <= 60) {
        character = SIXTY_READING;
    }
    else if (i_vibration <= 70) {
        character = SEVENTY_READING;
    }
    else if (i_vibration <= 80) {
        character = EIGHTY_READING;
    }
    else if (i_vibration <= 90) {
        character = NINETY_READING;
    }
    else if (i_vibration <= 100) {
        character = HUNDRED_READING;
    }
    else {
        character = OFF_SCALE_READING;
    }

    return character;
}