#pragma once

enum custom_keycodes {
  CK_QUOT,
  CK_REPEAT,
  CK_EQGT,
  SELWORD,
  ALT_TAB,
  BALL_HUI,
  BALL_WHT,              //cycles white
  BALL_DEC,              //decreased color
  BALL_SCR,              //scrolls
  BALL_NCL,              //left click
  BALL_RCL,              //right click
  BALL_MCL              //middle click
};

#define CK_A        LGUI_T(KC_A)
#define CK_S        ALGR_T(KC_S)
#define CK_D        LSFT_T(KC_D)
#define CK_F        LCTL_T(KC_F)
#define CK_J        RCTL_T(KC_J)
#define CK_K        RSFT_T(KC_K)
#define CK_L        LALT_T(KC_L)
#define CK_SCLN     RGUI_T(KC_SCLN)
#define CK_W_LEFT   A(KC_LEFT)
#define CK_W_RIGHT  A(KC_RIGHT)
#define CK_WW_LEFT  C(KC_LEFT)
#define CK_WW_RIGHT C(KC_RIGHT)
#define CK_COPY     C(KC_C)
#define CK_CUT      C(KC_X)
#define CK_PASTE    C(KC_V)
#define CK_PGUP     C(KC_PGUP)
#define CK_PGDN     C(KC_PGDN)


#define CK_MD1      LT(_M1, KC_TAB)
#define CK_MD2      LT(_M2, KC_SPC)
#define CK_MD3      LT(_M3, KC_BSPC)
#define CK_MD4      LT(_M4, KC_ENT)