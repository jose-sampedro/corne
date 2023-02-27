#include QMK_KEYBOARD_H
#include "layers.h"
#include "keymap.h"
#include "config.h"
#include "tapdance.c"
#include "features/oled/oled.c"
#include "keydefs.c"
#include "handlers.c"
#include "features/select_word.c"
#include "rgb.c"

// eliminar linea que no sea suprimir, si no eliminar
// aflojar intensidad de los leds
// ctrl + s
// alt tab se tiene que mejorar
// euro simbolo
// seleccionar todo
// zoom
// anadir el tema de hyper por ejemplo copiar y buscar
// ver como podemos hacer cuando pulsamos una tecla xxxx no aparezca 
// cambiar el tema de pasar de palabras como lo tengo en el papel
// hacer un print_r(clipboard);
// hacer que se pinte <?php o ?>
// ver si tenemos la tecla barra
// las capas m1 y m2 tendrian que estar intercambiadas tal vez ya que se dificulta tener en el mismo pulgar 
// mover las ventanas







const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(\
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     KC_ESC,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                       KC_Y,  KC_U,  KC_I,   KC_O,   KC_P,   KC_SLSH, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     TD(TD_UREDO),    CK_A,   CK_S,   CK_D,   CK_F,   KC_G,                          KC_H,    CK_J,   CK_K,   CK_L,   CK_SCLN,   CK_QUOT, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                          KC_N,    KC_M,   KC_COMM,   KC_DOT,   XXXXXXX,   CK_EQGT, \
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  ALT_TAB,   CK_MD1,   CK_MD2,     CK_MD4,  CK_MD3,    SELWORD  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  [_M1] = LAYOUT_split_3x6_3(\
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     KC_GRV,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                            KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     KC_SLSH, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_PLUS,    KC_LBRC,   KC_LCBR,   KC_DLR,   KC_LPRN,   KC_UNDS,                          KC_MINS,    KC_RPRN,   KC_EQL,   KC_RCBR,   KC_RBRC,   KC_AMPR, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     KC_LT,    KC_BSLS,   KC_PERC,   KC_CIRC,   KC_ASTR,   KC_TILD,                          KC_HASH,    KC_EXLM,   KC_QUES,   KC_AT,   KC_PIPE, KC_GT, \
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,  KC_BSPC,   SELWORD   ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯

  [_M2] = LAYOUT_split_3x6_3(\
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,   CK_CUT, CK_COPY, CK_PASTE,   CK_PGUP,                       KC_PGUP, CK_WW_LEFT,  KC_UP,   CK_WW_RIGHT,   XXXXXXX,   XXXXXXX, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     CAPSWRD,    XXXXXXX, XXXXXXX, KC_LSFT,   KC_LCTL,   CK_PGDN,                          KC_PGDN,    KC_LEFT,   KC_DOWN,   KC_RIGHT,   XXXXXXX,   XXXXXXX, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                          XXXXXXX,   KC_HOME,   CK_W_LEFT,   CK_W_RIGHT,  KC_END,   XXXXXXX, \
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  XXXXXXX,   KC_TAB,   XXXXXXX,     KC_ENT,  KC_BSPC,    SELWORD  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯


  [_M3] = LAYOUT_split_3x6_3(\
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,   XXXXXXX, KC_MS_U, XXXXXXX,   KC_WH_U,                       KC_BTN3,  KC_P7,     KC_P8,     KC_P9,   KC_PMNS,   KC_BSPC, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX, KC_MS_L, KC_MS_D,   KC_MS_R,   KC_WH_D,                          KC_BTN1,    KC_P4,     KC_P5,   KC_P6,   KC_PPLS,   KC_PDOT, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                          KC_BTN2,   KC_P1,     KC_P2,   KC_P3,   KC_PAST,   KC_PSLS, \
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,  XXXXXXX,    KC_P0  ),
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯


  [_M4] = LAYOUT_split_3x6_3(\
  //╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮                      ╭━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━╮
     XXXXXXX,    XXXXXXX,   KC_F7, KC_F8, KC_F9,   KC_F10,                       KC_F22,  KC_F13,     KC_F14,     KC_F15,   XXXXXXX,   XXXXXXX, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX, KC_F4, KC_F5,   KC_F6,   KC_F11,                          KC_F23,    KC_F16,     KC_F17,   KC_F18,   XXXXXXX,   XXXXXXX, \
  // ━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫                      ┣━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
     XXXXXXX,    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F12,                          KC_F24,   KC_F19,     KC_F20,   KC_F21,   XXXXXXX,   XXXXXXX, \
  //╰━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╮  ╭━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╯
                                                  XXXXXXX,   XXXXXXX,   XXXXXXX,     XXXXXXX,  XXXXXXX,    XXXXXXX  )
                                            //   ╰─━━━━━━━━┻━━━━━━━━━┻━━━━━━━━╯  ╰━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━╯
};


void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);


         pimoroni_trackball_set_precision(1.75);   //Start trackball with lower precision mode
      run_trackball_cleanup();
}