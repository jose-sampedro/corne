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
        {24, 0x00,0x0f,0x33}, {23, 0x00,0x14,0x42}, {18, 0x1d,0x00,0x61}, {17, 0x24,0x00,0x66}, {10, 0x30,0x06,0x93}, {9, 0x18,0x08,0x68},
        {25, 0x00,0x1d,0x33}, {22, 0x01,0x30,0x37}, {19, 0x00,0x41,0x52}, {16, 0x00,0x57,0x66}, {11, 0x00,0x73,0x75}, {8, 0x00,0x6b,0x1b},
        {26, 0x00,0x2e,0x23}, {21, 0x01,0x56,0x41}, {20, 0x00,0x8a,0x4e}, {15, 0x1b,0xa3,0x00}, {12, 0x74,0xc2,0x00}, {7, 0xa3,0x8d,0x00},
        {14, 0xf5,0xf9,0x01}, {13, 0xfa,0xa0,0x05}, {6,  0xf6,0x09,0x09},

        {51, 0x00,0x0f,0x33}, {50, 0x00,0x14,0x42}, {45, 0x1d,0x00,0x61}, {44, 0x24,0x00,0x66}, {37, 0x30,0x06,0x93}, {36, 0x18,0x08,0x68},
        {52, 0x00,0x1d,0x33}, {49, 0x01,0x30,0x37}, {46, 0x00,0x41,0x52}, {43, 0x00,0x57,0x66}, {38, 0x00,0x73,0x75}, {35, 0x00,0x6b,0x1b},
        {53, 0x00,0x2e,0x23}, {48, 0x01,0x56,0x41}, {47, 0x00,0x8a,0x4e}, {42, 0x1b,0xa3,0x00}, {39, 0x74,0xc2,0x00}, {34, 0xa3,0x8d,0x00},
        {41, 0xf5,0xf9,0x01}, {40, 0xfa,0xa0,0x05}, {33, 0xf6,0x09,0x09}
    }
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    unsigned char index;
    rgb_led led;

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _M1:
            for( index = 1; index <= 53; index++) {
                rgb_matrix_set_color(index, 0x00, 0x2e, 0x23);
            }
            break;

        case _M2:
            for( index = 1; index <= 53; index++) {
                rgb_matrix_set_color(index, 0x30, 0x06, 0x93);
            }
            break;

        case _M3:
            for( index = 1; index <= 53; index++) {
                rgb_matrix_set_color(index, 0xf5, 0xf9, 0x01);
            }
            break;

        case _M4:
            for( index = 1; index <= 53; index++) {
                rgb_matrix_set_color(index, 0xf6, 0x09, 0x09);
            }
            break;

        case _BASE:
            for( index = 0; index < 42; index++) {
                led = leds_theme[0][index];
                rgb_matrix_set_color(led.number, led.R, led.G, led.B);
            }

            break;
    }


    if (is_caps_word_on() | host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(0, RGB_RED);
        rgb_matrix_set_color(1, RGB_RED);
        rgb_matrix_set_color(2, RGB_RED);
        rgb_matrix_set_color(3, RGB_RED);
        rgb_matrix_set_color(4, RGB_RED);
        rgb_matrix_set_color(5, RGB_RED);
    }
}