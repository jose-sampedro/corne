#include "tapdance.h"

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_UREDO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, uredo_end, uredo_end_finished),
};

void uredo_end(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
				register_code(KC_LCTRL);
				register_code(KC_Z);
	}
	else{
			register_code(KC_LCTRL);
			register_code(KC_Y);
    }
};

void uredo_end_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_LCTRL);
    unregister_code (KC_Z);
  } else {
    unregister_code (KC_LCTRL);
    unregister_code (KC_Y);
  }
}