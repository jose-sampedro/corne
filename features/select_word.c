#include "select_word.h"

enum { STATE_NONE, STATE_SELECTED, STATE_WORD, STATE_FIRST_LINE, STATE_LINE };

bool process_select_word(uint16_t keycode, keyrecord_t* record,uint16_t sel_keycode) {
  static uint8_t state = STATE_NONE;

  if (keycode == KC_LSFT || keycode == KC_RSFT) {
    return true;
  }

  if (keycode == sel_keycode && record->event.pressed) {
    const uint8_t mods = get_mods();
    const uint8_t all_mods = mods;

    if ((all_mods & MOD_MASK_SHIFT) == 0) {  // Select word.
      register_code(KC_LCTL);

      if (state == STATE_NONE) {
        SEND_STRING(SS_TAP(X_RGHT) SS_TAP(X_LEFT));
      }
      register_code(KC_LSFT);
      register_code(KC_RGHT);
      state = STATE_WORD;
    } else {  // Select line.
      if (state == STATE_NONE) {
        clear_mods();
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
        set_mods(mods);
        state = STATE_FIRST_LINE;
      } else {
        register_code(KC_DOWN);
        state = STATE_LINE;
      }
    }
    return false;
  }

  switch (state) {
    case STATE_WORD:
      unregister_code(KC_RGHT);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);

      state = STATE_SELECTED;
      break;

    case STATE_FIRST_LINE:
      state = STATE_SELECTED;
      break;

    case STATE_LINE:
      unregister_code(KC_DOWN);
      state = STATE_SELECTED;
      break;

    case STATE_SELECTED:
      if (keycode == KC_ESC) {
        tap_code(KC_RGHT);
        state = STATE_NONE;
        return false;
      }
    default:
      state = STATE_NONE;
  }

  return true;
}