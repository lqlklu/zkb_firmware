#pragma once

#include <BleKeyboard.h>

#include "key.hpp"

namespace keyboard {

void begin();

bool isConnected();

void press(const Key& k);

void release(const Key& k);

void write(const Key& k);

} // namespace keyboard
