#include "keydefs.h"
#include "rgb.h"
#include "features/select_word.h"
#include "features/oled/oled.h"

uint8_t mod_state;

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  static uint8_t saved_mods_shift   = 0;
  static uint8_t saved_mods_ctrl   = 0;

  if (!process_select_word(keycode, record, SELWORD)) { return false; }

  switch (keycode) {
    case LT(_M3, KC_BSPC):
        if (record->tap.count && record->event.pressed) {
            saved_mods_shift = get_mods() & MOD_MASK_SHIFT;
            saved_mods_ctrl = get_mods() & MOD_MASK_CTRL;

            if (saved_mods_shift == MOD_MASK_SHIFT) { 
                register_code(KC_DEL);
            }
            else if (saved_mods_ctrl == MOD_MASK_CTRL) { 
                SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSHIFT) SS_TAP(X_END) SS_TAP(X_DELETE) SS_UP(X_LSHIFT) SS_TAP(X_DELETE));
            } else if (saved_mods_shift) {
                del_mods(saved_mods_shift);
                register_code(KC_DEL);
                add_mods(saved_mods_shift);
            } else if (saved_mods_ctrl) {
                del_mods(saved_mods_ctrl);
                SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) SS_DOWN(X_LSHIFT) SS_TAP(X_END) SS_TAP(X_DELETE) SS_UP(X_LSHIFT) SS_TAP(X_DELETE));
                add_mods(saved_mods_ctrl);
            } else {
                register_code(KC_BSPC);
            }
        } else if (record->event.pressed) {
            layer_on(_M1);
        } else {
            unregister_code(KC_DEL);
            unregister_code(KC_BSPC);
            layer_off(_M1);
        }
        return false;

    case CK_F:
        if (record->event.pressed) {
            isOledCtrl = true;
        } else {
            isOledCtrl = false;
        }
    return true;

    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;


    case CK_EQGT:
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                send_string("=>");
                set_mods(mod_state);                
            } else {
                SEND_STRING("->");
            }
        }
    return false;
    
    case CK_QUOT:
      if (record->event.pressed) {
        if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          send_string("\"\"");
          tap_code(KC_LEFT);
          set_mods(mod_state);
        } else {
          SEND_STRING("''");
          tap_code(KC_LEFT);
        }          
      }

    return false;

        case CK_MD2:
            if (record->event.pressed) {
                isOledSpace  = true;
                showedJumpMegaman = false;
            } else {
                isOledSpace = false;
            }
            return true;

  }

  return true;
};

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 300) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}