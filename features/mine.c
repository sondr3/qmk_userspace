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
#define M_SPC LT(SYM, KC_SPACE)
#define M_BSPC LT(NUM, KC_SPACE)

// Left hand side macros
#define M_A MT(KC_LGUI, KC_A)
#define M_R MT(KC_LALT, KC_R)
#define M_S MT(KC_LCTL, KC_S)
#define M_T MT(KC_LSFT, KC_T)

// Right hand side macros
#define M_N MT(KC_RSFT, KC_N)
#define M_E MT(KC_RCTL, KC_E)
#define M_I MT(KC_RALT, KC_I)
#define M_O MT(KC_RGUI, KC_O)

// Norwegian macros
#define M_AE LALT(KC_QUOTE)
#define M_OE LALT(KC_O)
#define M_AA LALT(KC_A)

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  return true;
}

void housekeeping_task_user(void) {
  achordion_task();
}
