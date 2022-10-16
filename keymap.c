#include QMK_KEYBOARD_H
#include "layers.h"
#include "keymap.h"
#include "config.h"
#include "tapdance.c"
#include "keydefs.c"
#include "handlers.c"
#include "rgb.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(\
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,   XXXXXXX,   RGB_HUI,   RGB_SAI,   RGB_VAI,                       XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    HOME_A,   HOME_S,   HOME_D,   HOME_F,   XXXXXXX,                          XXXXXXX,    HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,   XXXXXXX, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   XXXXXXX,   RGB_HUD,   RGB_SAD,   RGB_VAD,                          XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, \
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  XXXXXXX,   XXXXXXX,   LT(_M1, KC_SPC),     XXXXXXX,  XXXXXXX,    XXXXXXX  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  [_M1] = LAYOUT_split_3x6_3(\
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,   XXXXXXX,   RGB_HUI,   RGB_SAI,   RGB_VAI,                       XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   XXXXXXX,   RGB_HUD,   RGB_SAD,   RGB_VAD,                          XXXXXXX,    KC_LEFT,   KC_DOWN,   KC_UP,   KC_RIGHT,   XXXXXXX, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                          XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, \
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,  XXXXXXX,    XXXXXXX  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯
};


void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

void matrix_init_user(void) {
   rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
}