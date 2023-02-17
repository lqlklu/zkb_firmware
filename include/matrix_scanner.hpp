#pragma once

#include <array>

#include <Arduino.h>

template <size_t _row_num, size_t _col_num>
class MatrixScanner {
public:
  MatrixScanner(const std::array<uint8_t, _row_num>& rows, const std::array<uint8_t, _col_num>& cols)
      : _row_pins(rows), _col_pins(cols) {}

  void begin() {
    for (auto& i : _row_pins) {
      pinMode(i, OUTPUT);
    }
    for (auto& i : _col_pins) {
      pinMode(i, INPUT_PULLDOWN);
    }
  }

  std::vector<std::vector<bool>> scan() {
    std::vector<std::vector<bool>> res(_row_num, std::vector<bool>(_col_num, false));
    for (int i = 0; i < _row_num; i++) {
      auto cur_row_pin = _row_pins[i];
      for (auto& p : _row_pins) {
        if (p == cur_row_pin) {
          digitalWrite(p, HIGH);
        } else {
          digitalWrite(p, LOW);
        }
      }
      for (int j = 0; j < _col_num; j++) {
        auto cur_col_pin = _col_pins[j];
        if (digitalRead(cur_col_pin) == HIGH) {
          res[i][j] = true;
        }
      }
    }
    return res;
  }

private:
  std::array<uint8_t, _row_num> _row_pins;
  std::array<uint8_t, _col_num> _col_pins;
};
