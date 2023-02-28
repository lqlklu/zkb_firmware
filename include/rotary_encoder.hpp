#pragma once

#include <Arduino.h>

#include "key.hpp"
#include "keyboard.hpp"

namespace rotary_encoder {

// config
constexpr uint8_t _PIN_A = GPIO_NUM_2;
constexpr uint8_t _PIN_B = GPIO_NUM_3;
constexpr Key _KEY_A = Key::k(KEY_MEDIA_VOLUME_DOWN);
constexpr Key _KEY_B = Key::k(KEY_MEDIA_VOLUME_UP);

// status
volatile int _v = 0;
volatile int _lv = 0;
int _bAtLastLowA = -1;

void _updateEncoder() {
  int a = digitalRead(GPIO_NUM_5);
  int b = digitalRead(GPIO_NUM_4);
  if (a == HIGH) {
    if (b == HIGH) {
      _v++;
    } else if (b == LOW) {
      _v--;
    }
  } else if (a == LOW) {
    _bAtLastLowA = b;
  }
}

void begin() {
  pinMode(_PIN_A, INPUT_PULLUP);
  pinMode(_PIN_B, INPUT_PULLUP);
  attachInterrupt(_PIN_A, _updateEncoder, CHANGE);
  // attachInterrupt(_PIN_B, _updateEncoder, CHANGE);
}

void loop() {
  if (keyboard::isConnected()) {
    if (_v != _lv) {
      Serial.printf("%d,%d\n", _v, _lv);
      if (_v > _lv) {
        keyboard::write(_KEY_A);
      } else {
        keyboard::write(_KEY_B);
      }
      _lv = _v;
    }
  }
}

} // namespace rotary_encoder
