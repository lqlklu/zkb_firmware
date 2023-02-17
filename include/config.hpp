#pragma once

#include <array>

#include <Arduino.h>

#include "key.hpp"

constexpr uint32_t DELAY = 10;

// c3
constexpr size_t LAYER_NUM = 2;
constexpr size_t ROW_NUM = 2;
constexpr size_t COL_NUM = 3;

constexpr std::array<uint8_t, ROW_NUM> ROW_PINS{{
    GPIO_NUM_0,
    GPIO_NUM_1,
}};

constexpr std::array<uint8_t, COL_NUM> COL_PINS{{
    GPIO_NUM_2,
    GPIO_NUM_3,
    GPIO_NUM_10,
}};

// s3
// constexpr int LAYER_NUM = 2;
// constexpr int ROW_NUM = 2;
// constexpr int COL_NUM = 3;

// constexpr std::array<uint8_t, ROW_NUM> ROW_PINS{{
//     GPIO_NUM_7,
//     GPIO_NUM_15,
// }};

// constexpr std::array<uint8_t, COL_NUM> COL_PINS{{
//     GPIO_NUM_16,
//     GPIO_NUM_17,
//     GPIO_NUM_18,
// }};

constexpr std::array<std::array<Key, COL_NUM>, ROW_NUM> KEY_MAP{{
    {Key::ch('h'), Key::ch('l'), Key::mk(KEY_MEDIA_VOLUME_UP)},
    {Key::ch(KEY_DOWN_ARROW), Key::ch(KEY_UP_ARROW), Key::mk(KEY_MEDIA_VOLUME_DOWN)},
}};
