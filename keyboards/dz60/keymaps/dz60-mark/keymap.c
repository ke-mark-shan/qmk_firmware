#include "dz60.h"

#define _BASE_LAYER 0
#define _CAPS_FN_LAYER 1
#define _FN_LAYER 2
#define _SET_LAYER 15

#define XXXXX KC_NO

enum tapdance_states {
	USE_SPACE,
	USE_FN,
};

enum macro_keycodes {
  PRINT_CANCER,
};

enum {
  TD_SPC_FN = 0
};

int td_spc_fn;

// Space-FN Tapdance
void td_spc_fn_finished(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->pressed == 0) {
			register_code(KC_SPC);
			td_spc_fn = USE_SPACE;
    } else {
			layer_on(_FN_LAYER);
			td_spc_fn = USE_FN;
    }
}

void td_spc_fn_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (td_spc_fn == USE_SPACE) {
			unregister_code(KC_SPC);
    } else {
      layer_off(_FN_LAYER);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {                                                                                                                  
    [TD_SPC_FN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_spc_fn_finished, td_spc_fn_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE_LAYER] = LAYOUT(
		KC_GESC,        KC_1,           KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, XXXXX, KC_BSPC,
		KC_TAB,         KC_Q,           KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
	  MO(_FN_LAYER),  KC_A,           KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT,        XXXXX,          KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, XXXXX,
		KC_LCTL,        MO(_FN_LAYER),  KC_LALT, XXXXX, TD(TD_SPC_FN)/*KC_SPC*/, XXXXX, KC_LEFT, KC_DOWN, XXXXX, KC_UP, KC_RIGHT),

	[_FN_LAYER] = LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_INS, KC_HOME, KC_PGUP, KC_TRNS,  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, RESET,
		KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELETE, KC_END, KC_PGDOWN, RGB_TOG, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_LGUI, XXXXX, PRINT_CANCER, KC_RCTL),

	[_SET_LAYER] = LAYOUT(
		KC_TRNS, M(_FN_LAYER), M(_SET_LAYER), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    //set_unicode_input_mode(UC_LNX); // Linux
    //set_unicode_input_mode(UC_OSX); // Mac OSX
    //set_unicode_input_mode(UC_WIN); // Windows (with registry key, see wiki)
    //set_unicode_input_mode(UC_WINC); // Windows (with WinCompose, see wiki)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	
	if (record->event.pressed){
		//Keydown
		switch (keycode) {
			case PRINT_CANCER:
			SEND_STRING("QMK is the best thing ever!");
					return false;
  		}
	}
  

	return true;
}