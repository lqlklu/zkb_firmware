#include <array>
#include <vector>

#include <Arduino.h>
#include <BleKeyboard.h>

#include "config.hpp"
#include "matrix_scanner.hpp"

std::array<std::array<bool, COL_NUM>, ROW_NUM> key_status = {false};

MatrixScanner<ROW_NUM, COL_NUM> ms{ROW_PINS, COL_PINS};

BleKeyboard kb{"zkb", "zkbbbbb", 100};

void setup() {
  Serial.begin(115200);
  kb.begin();
  ms.begin();
}

void loop() {
  if (kb.isConnected()) {
    auto res = ms.scan();
    for (int i = 0; i < ROW_NUM; i++) {
      for (int j = 0; j < COL_NUM; j++) {
        if (!key_status[i][j] && res[i][j]) {
          key_status[i][j] = true;
          // press
          switch (KEY_MAP[i][j]._kind) {
          case KeyKind::Char: {
            kb.press(KEY_MAP[i][j]._c);
            break;
          }
          case KeyKind::Media: {
            kb.press(KEY_MAP[i][j]._m);
            break;
          }
          default:
            break;
          }
        } else if (key_status[i][j] && !res[i][j]) {
          key_status[i][j] = false;
          // release
          switch (KEY_MAP[i][j]._kind) {
          case KeyKind::Char: {
            kb.release(KEY_MAP[i][j]._c);
            break;
          }
          case KeyKind::Media: {
            kb.release(KEY_MAP[i][j]._m);
            break;
          }
          default:
            break;
          }
        }
      }
    }
#if DELAY > 0
    delay(DELAY);
#endif
  }
}
