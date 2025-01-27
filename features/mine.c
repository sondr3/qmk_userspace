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
	SMTD_KEYCODES_BEGIN = SAFE_RANGE,
	// Left hand side
	MKC_A,
	MKC_R,
	MKC_S,
	MKC_T,
	// Right hand side
	MKC_N,
	MKC_E,
	MKC_I,
	MKC_O,
	SMTD_KEYCODES_END
};

#ifdef SM_TAP_DANCE_ENABLE
#include "features/sm_td.h"
#endif  // SM_TAP_DANCE_ENABLE

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

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
	switch (keycode) {
		SMTD_MT(MKC_A, KC_A, KC_LCTL)
		SMTD_MT(MKC_R, KC_R, KC_LALT)
		SMTD_MT(MKC_S, KC_S, KC_LGUI)
		SMTD_MT(MKC_T, KC_T, KC_LSFT)
		SMTD_MT(MKC_N, KC_N, KC_RSFT)
		SMTD_MT(MKC_E, KC_E, KC_RGUI)
		SMTD_MT(MKC_I, KC_I, KC_RALT)
		SMTD_MT(MKC_O, KC_O, KC_RCTL)
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) { return false; }
	#endif  // ACHORDION_ENABLE

	#ifdef SM_TAP_DANCE_ENABLE
	if (!process_smtd(keycode, record)) { return false; }
	#endif  // SM_TAP_DANCE_ENABLE
  return true;
}

void housekeeping_task_user(void) {
	#ifdef ACHORDION_ENABLE
  achordion_task();
	#endif  // ACHORDION_ENABLE
}
