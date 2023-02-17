#pragma once

#include <BleKeyboard.h>

enum class KeyKind {
  None,
  Switch,
  Char,
  Media,
};

struct Key {
  constexpr Key(KeyKind kind, const uint8_t& c, const MediaKeyReport& m) : _kind(kind), _c{c}, _m{m} {}

  constexpr static Key ch(const uint8_t& c) {
    return {KeyKind::Char, c, KEY_MEDIA_MUTE};
  }

  constexpr static Key mk(const MediaKeyReport& mkp) {
    return {KeyKind::Media, 0, mkp};
  }

  KeyKind _kind;
  const uint8_t _c;
  const MediaKeyReport& _m;
};
