#include "quantum_keycodes.h"
#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif  // ACHORDION_ENABLE

// Layers used in my keyboards
enum layers {
	BASE,
	SYM,
	NUM,
	SYS
};

enum custom_keycodes {
	// Left hand side
	MKC_A = SAFE_RANGE,
	MKC_R,
	MKC_S,
	MKC_T,
	// Right hand side
	MKC_N,
	MKC_E,
	MKC_I,
	MKC_O,
};
// Too few fingers macros
#define M_CST LCTL(LSFT(KC_TAB)) // Ctrl + Shift + Tab
#define M_CT LCTL(KC_TAB) // Ctrl + Tab

// Layer macros
#define M_SPC LT(SYM, KC_SPACE)
#define M_BSPC LT(NUM, KC_BSPC)

// Left hand side macros
#define M_A MT(MOD_LCTL, KC_A)
#define M_R MT(MOD_LALT, KC_R)
#define M_S MT(MOD_LGUI, KC_S)
#define M_T MT(MOD_LSFT, KC_T)

// Right hand side macros
#define M_N MT(MOD_RSFT, KC_N)
#define M_E MT(MOD_RGUI, KC_E)
#define M_I MT(MOD_RALT, KC_I)
#define M_O MT(MOD_RCTL, KC_O)

// Norwegian macros
#define M_AE LALT(KC_QUOTE)
#define M_OE LALT(KC_O)
#define M_AA LALT(KC_A)

#ifdef SM_TAP_DANCE_ENABLE
#include "features/sm_td.h"
#endif  // SM_TAP_DANCE_ENABLE


#ifdef ACHORDION_ENABLE
bool achordion_eager_mod(uint8_t mod) {
	switch (mod) {
		// eagerly apply shift and cmd
		case MOD_LSFT:
		case MOD_LGUI:
		case MOD_RSFT:
		case MOD_RGUI:
			return true;
		default:
			return false;
	}
}
#endif  // ACHORDION_ENABLE

#ifdef SM_TAP_DANCE_ENABLE
smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
	switch (keycode) {
		SMTD_MT_ON_MKEY(MKC_A, KC_A, KC_LCTL)
		SMTD_MT_ON_MKEY(MKC_R, KC_R, KC_LALT)
		SMTD_MT_ON_MKEY(MKC_S, KC_S, KC_LGUI)
		SMTD_MT_ON_MKEY(MKC_T, KC_T, KC_LSFT)
		SMTD_MT_ON_MKEY(MKC_N, KC_N, KC_RSFT)
		SMTD_MT_ON_MKEY(MKC_E, KC_E, KC_RGUI)
		SMTD_MT_ON_MKEY(MKC_I, KC_I, KC_RALT)
		SMTD_MT_ON_MKEY(MKC_O, KC_O, KC_RCTL)
	}

  return SMTD_RESOLUTION_UNHANDLED;
}
#endif  // SM_TAP_DANCE_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) { return false; }
	#endif  // ACHORDION_ENABLE

	#ifdef SM_TAP_DANCE_ENABLE
	if (!process_smtd(keycode, record)) { return false; }
	#endif  // SM_TAP_DANCE_ENABLE
  return true;
}

#ifdef ACHORDION_ENABLE
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case M_SPC:
    case M_BSPC:
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}
#endif  // ACHORDION_ENABLE

void housekeeping_task_user(void) {
	#ifdef ACHORDION_ENABLE
  achordion_task();
	#endif  // ACHORDION_ENABLE
}
