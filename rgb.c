#include QMK_KEYBOARD_H
#include "layers.h"
#include "rgb.h"

/*

  .-----------------------------------------------------------.
  |   24    |   23    |   18    |   17    |    10   |    9    |
  |---------+--------[2]--------+--------[1]-------[0]--------|
  |   25    |   22    |   19    |   16    |    11   |    8    |
  |---------+--------[3]--------+---------+---------+---------|
  |   26    |   21    |   20    |   15    |    12   |    7    |
  `---------+---------+---------+--------[4]-------[5]--------+---------.
                                           \   14   |   13    |    6    |
                                            `---------------------------´
*/

typedef struct {
    unsigned char number;
    unsigned char R;
    unsigned char G;
    unsigned char B;
} rgb_led;

static const rgb_led leds_theme[][42] = {
    {
        {24, 0x3b, 0x3b, 0x3b}, {23, 0x69, 0x69, 0x69}, {18, 0x78, 0x68, 0x73}, {17, 0x4f, 0x2a, 0x92}, {10, 0x30, 0x06, 0x93}, {9, 0x18, 0x08, 0x68},
        {25, 0x6e, 0x6e, 0x6e}, {22, 0x94, 0x94, 0x94}, {19, 0xc1, 0x8a, 0xbc}, {16, 0x9d, 0x73, 0xbf}, {11, 0x48, 0x10, 0x9e}, {8, 0x4f, 0x03, 0x81},
        {26, 0x91, 0x91, 0x91}, {21, 0xff, 0xff, 0xff}, {20, 0xff, 0xff, 0xff}, {15, 0xef, 0x9e, 0xff}, {12, 0xdf, 0x17, 0xee}, {7, 0xa2, 0x07, 0x54},
        {14, 0xf5, 0xf9, 0x01}, {13, 0xfa, 0xa0, 0x05}, {6, 0xa2, 0x07, 0x54},
        {51, 0x3b, 0x3b, 0x3b}, {50, 0x69, 0x69, 0x69}, {45, 0x78, 0x68, 0x73}, {44, 0x4f, 0x2a, 0x92}, {37, 0x30, 0x06, 0x93}, {36, 0x18, 0x08, 0x68},
        {52, 0x6e, 0x6e, 0x6e}, {49, 0x94, 0x94, 0x94}, {46, 0xc1, 0x8a, 0xbc}, {43, 0x9d, 0x73, 0xbf}, {38, 0x48, 0x10, 0x9e}, {35, 0x4f, 0x03, 0x81},
        {53, 0x91, 0x91, 0x91}, {48, 0xff, 0xff, 0xff}, {47, 0xff, 0xff, 0xff}, {42, 0xef, 0x9e, 0xff}, {39, 0xdf, 0x17, 0xee}, {34, 0xa2, 0x07, 0x54},
        {41, 0xf5, 0xf9, 0x01}, {40, 0xfa, 0xa0, 0x05}, {33, 0xf6, 0x09, 0x09}
    },

    {
        {18, 0xFF, 0x00, 0x00}, {22, 0xFF, 0x00, 0x00}, {19, 0xFF, 0x00, 0x00}, {16, 0xFF, 0x00, 0x00}
    }
};

 void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    unsigned char index;
    rgb_led led;

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(26, RGB_RED);
    }

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _M1:
            for( index = 0; index < 42; index++) {
                led = leds_theme[1][index];
                rgb_matrix_set_color(led.number,led.R, led.G, led.B);
            }
            break;

        case _BASE:
            for( index = 0; index < 42; index++) {
                led = leds_theme[0][index];
                rgb_matrix_set_color(led.number, led.R, led.G, led.B);
            }

            break;
    }
}