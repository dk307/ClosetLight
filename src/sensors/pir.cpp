
#include <Arduino.h>
#include "pir.h"

pir_sensor::pir_sensor(uint8_t pin) : gpio_pin(pin)
{
}

void pir_sensor::begin()
{
    pinMode(gpio_pin, INPUT_PULLUP);
}

void pir_sensor::loop()
{
    state = digitalRead(gpio_pin) == HIGH;

    if (state)
    {
        // Serial.println("Motion detected");
        last_high_time = millis();
    }
}

bool pir_sensor::is_triggered_within(uint32_t timeMs)
{
    const auto current_time = millis();
    return (current_time - last_high_time) <= timeMs;
}

