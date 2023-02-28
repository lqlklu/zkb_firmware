#include <Arduino.h>

#include "key_matrix.hpp"
#include "keyboard.hpp"
#include "rotary_encoder.hpp"

void setup() {
  Serial.begin(115200);
  keyboard::begin();
  key_matrix::begin();
  rotary_encoder::begin();
}

void loop() {
  key_matrix::loop();
  rotary_encoder::loop();
}
