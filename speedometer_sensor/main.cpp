
#include "ipc_writer.h"
#include "ipc_settings.h"
#include "speedometer_sensor.h"
#include <iostream>

int main()
{
    SpeedometerSensor sensor{};

    IPCWriter writer(speedometer_data_init);
    for (;;)
    {
        int const speed = sensor.getValue();
        writer.send(std::to_string(speed), fps);
        std::cout << "sent: " << speed << std::endl;
    }
    return 0;
}
