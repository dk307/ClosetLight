#pragma once

#include <Arduino.h>

class pir_sensor
{
public:
    pir_sensor(uint8_t gpiopin);

    void begin();
    void loop();
    bool is_triggered_within(uint32_t timeMs);

    bool get_state() const
    {
        return state;
    }   

private:
    const uint8_t gpio_pin;
    uint64_t last_high_time{0};
    bool state{false};
};
