#pragma once

#include <Arduino.h>
class relay
{
public:
    relay(uint8_t gpiopin, const String &name) : gpio_pin(gpiopin)
#ifdef SERIAL_LOG
                                                 ,
                                                 name(name)
#endif
    {
    }

    void begin()
    {
        pinMode(gpio_pin, OUTPUT);
        digitalWrite(gpio_pin, state ? HIGH : LOW);
    }

    void ensure_state(bool state)
    {
        if (state != this->state)
        {
            this->state = state;
#ifdef SERIAL_LOG
            Serial.print(name + " state: ");
            Serial.println(state ? "ON" : "OFF");
#endif
            digitalWrite(gpio_pin, state ? HIGH : LOW);
        }
    }

private:
    const uint8_t gpio_pin;
#ifdef SERIAL_LOG
    const String name;
#endif
    bool state{false};
};