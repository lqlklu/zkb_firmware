#include "key_matrix.hpp"

namespace key_matrix {

// config
constexpr size_t _LAYER_NUM = 2;
constexpr size_t _ROW_NUM = 2;
constexpr size_t _COL_NUM = 2;

constexpr std::array<uint8_t, _ROW_NUM> _ROW_PINS{{
    GPIO_NUM_0,
    GPIO_NUM_1,
}};

constexpr std::array<uint8_t, _COL_NUM> _COL_PINS{{
    GPIO_NUM_2,
    GPIO_NUM_3,
}};

constexpr std::array<std::array<Key, _COL_NUM>, _ROW_NUM> _KEY_MAP{{
    {Key::k('q'), Key::k('w')},
    {Key::k('a'), Key::k('s')},
}};

// status
std::array<std::array<int, _COL_NUM>, _ROW_NUM> _key_status = {LOW};

void begin() {
  for (auto& i : _ROW_PINS) {
    pinMode(i, INPUT_PULLDOWN);
  }
  for (auto& i : _COL_PINS) {
    pinMode(i, OUTPUT);
  }
}

std::array<std::array<int, _COL_NUM>, _ROW_NUM> _res = {LOW};

void loop() {
  if (keyboard::isConnected) {
    for (int i = 0; i < _COL_NUM; i++) {
      auto cur_write_pin = _COL_PINS[i];
      for (auto& p : _COL_PINS) {
        if (p == cur_write_pin) {
          digitalWrite(p, HIGH);
        } else {
          digitalWrite(p, LOW);
        }
      }
      delay(1); // !important
      for (int j = 0; j < _ROW_NUM; j++) {
        auto cur_read_pin = _ROW_PINS[j];
        int x = digitalRead(cur_read_pin);
        int last = _key_status[j][i];
        _key_status[j][i] = x;
        if (x == HIGH && last == LOW) {
          keyboard::press(_KEY_MAP[j][i]);
        } else if (x == LOW && last == HIGH) {
          keyboard::release(_KEY_MAP[j][i]);
        }
      }
    }
  }
}

} // namespace key_matrix
