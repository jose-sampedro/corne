#include "keydefs.h"
#include "rgb.h"
#include "features/select_word.h"
#include "features/oled/oled.h"

uint8_t mod_state;

bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.




   bool trackball_is_scrolling = true;    //Default mode is scrolling
   bool trackball_is_precision = false;   //Default mode is less precise
   bool was_scrolling = true; //Remember preferred state of trackball scrolling

static bool mouse_button_one, trackball_button_one;





void run_trackball_cleanup(void) {  //Set colour of trackball LED. Does not require RGBLIGHT_ENABLE if colour shorthands are not used.
      #ifdef POINTING_DEVICE_ENABLE
      if (trackball_is_scrolling) {
         pimoroni_trackball_set_rgbw(43, 153, 103, 0x00);
      } else if (!trackball_is_precision) {
         pimoroni_trackball_set_rgbw(0, 27, 199, 0x00);
      } else {
         pimoroni_trackball_set_rgbw(217, 165, 33, 0x00);   //RGB_GOLDENROD in number form. 
      }
      #endif
   }
   
   uint8_t pointing_device_handle_buttons(uint8_t buttons, bool pressed, pointing_device_buttons_t button) {
      if (pressed) {
         buttons |= 1 << (button);
         #ifdef HAPTIC_ENABLE //Haptic feedback when trackball button is pressed
            DRV_pulse(4);     //sharp_click
         #endif
      } else {
         buttons &= ~(1 << (button));
      }
      return buttons;
   }

   report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
      if (trackball_is_scrolling) {
         mouse_report.h = mouse_report.x;
         #ifndef PIMORONI_TRACKBALL_INVERT_X
            mouse_report.v = 0.3*mouse_report.y;   //Multiplier to lower scrolling sensitivity
         #else
            mouse_report.v = 0.3*-mouse_report.y;  //invert vertical scroll direction
         #endif
         mouse_report.x = mouse_report.y = 0;
      }
      return mouse_report;
   }

   #if !defined(MOUSEKEY_ENABLE) //Allows for button clicks on keymap even though mousekeys is not defined.
      static bool mouse_button_one, trackball_button_one;
   #endif

   void trackball_register_button(bool pressed, enum mouse_buttons button) {
      report_mouse_t currentReport = pointing_device_get_report();
      if (pressed) {
         currentReport.buttons |= button;
      } else {
         currentReport.buttons &= ~button;
      }
      pointing_device_set_report(currentReport);
   }






bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  static uint8_t saved_mods_shift   = 0;
  static uint8_t saved_mods_ctrl   = 0;

  if (!process_select_word(keycode, record, SELWORD)) { return false; }

  switch (keycode) {
case PM_SCROLL:
                    if (record->event.pressed) {
                        if (trackball_is_scrolling || was_scrolling){ //Enable toggling for trackball scrolling
                            trackball_is_scrolling=false;
                            was_scrolling=false; //Tracks status of scrolling setting. Works with holding of layer key for mouse mode.
                        } else{
                            trackball_is_scrolling=true;
                            was_scrolling=true;
                        }
                        run_trackball_cleanup();
                        break;
                    }
                case PM_PRECISION:
                    if (record->event.pressed) {
                        if (trackball_is_precision){ //Enable toggling for trackball precision
                            pimoroni_trackball_set_precision(1.75);
                            trackball_is_precision=false;
                        } else{
                            pimoroni_trackball_set_precision(0.8);
                            trackball_is_precision=true;
                        }
                        run_trackball_cleanup();
                        break;
                    }

                    case KC_MS_BTN1:
                        mouse_button_one = record->event.pressed;
                        trackball_register_button(mouse_button_one | trackball_button_one, MOUSE_BTN1);
                        break;
                    case KC_MS_BTN2:
                        trackball_register_button(record->event.pressed, MOUSE_BTN2);
                        break;
                    case KC_MS_BTN3:
                        trackball_register_button(record->event.pressed, MOUSE_BTN3);
                        break;






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