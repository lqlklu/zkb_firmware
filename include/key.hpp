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

  constexpr Key(const MediaKeyReport& m)
      : _kind{KeyKind::Media}, _c{0}, _m{m} {}

  constexpr Key(const uint8_t& c)
      : _kind{KeyKind::Char}, _c{c}, _m{} {}

  constexpr static Key ch(const uint8_t& c) {
    return {KeyKind::Char, c, KEY_MEDIA_MUTE};
  }

  constexpr static Key mk(const MediaKeyReport& mkp) {
    return {KeyKind::Media, 0, mkp};
  }

  constexpr static Key k(const uint8_t& c) {
    return {KeyKind::Char, c, KEY_MEDIA_MUTE};
  }

  constexpr static Key k(const MediaKeyReport& mkp) {
    return {KeyKind::Media, 0, mkp};
  }

  const KeyKind _kind;
  const uint8_t _c;
  const MediaKeyReport& _m;
};
