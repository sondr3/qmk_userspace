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

// Too few fingers macros
#define M_CST LCTL(LSFT(KC_TAB)) // Ctrl + Shift + Tab
#define M_CT LCTL(KC_TAB) // Ctrl + Tab

// Layer macros
#define M_SPC LT(NUM, KC_SPACE)
#define M_BSPC LT(SYM, KC_BSPC)

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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) { return false; }
	#endif  // ACHORDION_ENABLE
  return true;
}

void housekeeping_task_user(void) {
	#ifdef ACHORDION_ENABLE
  achordion_task();
	#endif  // ACHORDION_ENABLE
}
