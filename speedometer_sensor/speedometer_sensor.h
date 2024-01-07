#ifndef SPEEDOMETER_SENSOR_H
#define SPEEDOMETER_SENSOR_H

#include <chrono>

class SpeedometerSensor
{
public:
    // The function generate value depending on time.
    // The sum of sines with different periods and coefficients.
    double getValue() const;

private:
    std::chrono::steady_clock::time_point last_sent_time_; // last time value generated
};

#endif // SPEEDOMETER_SENSOR_H
