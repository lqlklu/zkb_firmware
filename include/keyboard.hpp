#pragma once

#include <BleKeyboard.h>

#include "key.hpp"

namespace keyboard {

BleKeyboard _zkb{"zkb", "zkb", 100};

void begin() {
  _zkb.begin();
}

bool isConnected() {
  return _zkb.isConnected();
}

void press(const Key& k) {
  switch (k._kind) {
  case KeyKind::Char: {
    _zkb.press(k._c);
    break;
  }
  case KeyKind::Media: {
    _zkb.press(k._m);
    break;
  }
  default:
    break;
  }
}

void release(const Key& k) {
  switch (k._kind) {
  case KeyKind::Char: {
    _zkb.release(k._c);
    break;
  }
  case KeyKind::Media: {
    _zkb.release(k._m);
    break;
  }
  default:
    break;
  }
}

void write(const Key& k) {
  switch (k._kind) {
  case KeyKind::Char: {
    _zkb.write(k._c);
    break;
  }
  case KeyKind::Media: {
    _zkb.write(k._m);
    break;
  }
  default:
    break;
  }
}

} // namespace keyboard
