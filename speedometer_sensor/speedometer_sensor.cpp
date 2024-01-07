#include "speedometer_sensor.h"
#include <cmath>

double SpeedometerSensor::getValue() const
{
    static const double coefficients[] = {1.0, 0.5, 0.75, 2.3, 1.7};
    static const double periods[] = {1.0, 2.0, 0.5, 1.5, 2.5};

    auto current_time = std::chrono::steady_clock::now();
    double elapsed_time = std::chrono::duration<double>(current_time - last_sent_time_).count();

    double sum = 0.0;
    for (int i = 0; i < 3; ++i)
    {
        sum += coefficients[i] * std::sin(2 * M_PI / periods[i] * elapsed_time);
    }
    return std::abs(sum * 100);
}
