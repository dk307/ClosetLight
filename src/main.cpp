#include <Arduino.h>
#include "sensors/pir.h"
#include "sensors/relay.h"

pir_sensor radar(2);
relay inbuilt_led(LED_BUILTIN, "LED");
relay led_relay(8, "Relay");

constexpr uint32_t motion_timeout = 30000;

void setup()
{
#ifdef SERIAL_LOG
  Serial.begin(115200);
  Serial.println("Starting...");
#endif
  inbuilt_led.begin();
  led_relay.begin();
  radar.begin();
}

void loop()
{
  radar.loop();
  inbuilt_led.ensure_state(radar.get_state());
  led_relay.ensure_state(radar.is_triggered_within(motion_timeout));
  delay(3);
}
