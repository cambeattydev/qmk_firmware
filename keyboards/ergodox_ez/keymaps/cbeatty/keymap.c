#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define KC_SearchEverywhere     LCTL(KC_T)
#define KC_AttachToProcess      LCTL(LALT(KC_P))
#define KC_Find                 LCTL(KC_F)
#define KC_UsagesOfSymbol       LALT(LSFT(KC_F12))
#define KC_CUT                  LCTL(KC_X)
#define KC_COPY                 LCTL(KC_C)
#define KC_PASTE                LCTL(KC_V)
#define KC_UNDO                 LCTL(KC_Z)
#define KC_CTL_SPC              LCTL(KC_SPC)
#define KC_ALT_TAB              LALT(KC_TAB)
#define KC_FN3                  MO(NAV)

#define BASE 0 // default layer
#define CODENUM 1 // Code and Numbers
#define MDIA 2 // media keys
#define NAV 3 //windows navigation

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Redo   |   1  |   2  |   3  |   4  |   5  |  =   |           |  `   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  Cut |           |1Shot |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |  L1  |------+------+------+------+------+--------|
 * | Undo   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------| Copy |           |PASTE |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L1  |  L3  |AltShf|  (   |   )  |                                       |  {   |  }   |   [  |   ]  |  L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Left | Right|       | App  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+-------.
 *                                 |      |      | Esc  |       |  Up  |        | Space |
 *                                 | Enter|  Del |------|       |------|  Back  |/Shift |
 *                                 |      |      | LGui |       | Down | space  |       |
 *                                 `--------------------'       `-----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        LCTL(KC_Y),         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        KC_TAB,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_CUT,
        KC_UNDO,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,  KC_COPY,
        KC_FN1,KC_FN3,  LALT(KC_LSFT),  LSFT(KC_9),LSFT(KC_0),
                                                      KC_LEFT,KC_RGHT,
                                                              KC_ESC,
                                 MT(MOD_LSFT, KC_ENT),KC_DEL,KC_LGUI,
        // right hand
             KC_GRV,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_MINS,
             OSL(CODENUM),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_QUOT,
             KC_PASTE,KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  LSFT(KC_LBRC),LSFT(KC_RBRC) ,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_APP,        CTL_T(KC_ESC),
             KC_UP,
             KC_DOWN,KC_BSPACE, MT(MOD_RSFT, KC_SPC)
    ),
/* Keymap 1: Coding and numbers
 *
 * ,-------------------------------------------------------.           ,--------------------------------------------------.
 * |Escape     |  F1  |  F2  |  F3  |  F4  |  F5    |      |           | CALC |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |-----------+------+------+------+------+--------+------|           |------+------+------+------+------+------+--------|
 * |           |   x  |   x  |   x  |   x  |Ctrl(T) |Alt ` |           |  +   |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |-----------+------+------+------+------+--------|      |           |      |------+------+------+------+------+--------|
 * |AltShiftF12|   x  | Save |   x  | Find |   x    |------|           |------| Down |   4  |   5  |   6  |   /  | Clear  |
 * |-----------+------+------+------+------+--------|Alt   |           |  -   |------+------+------+------+------+--------|
 * | CtrlAlt P |   x  |   x  |   x  |   x  |CtlSpace|Enter |           |      |   &  |   1  |   2  |   3  |   =  |        |
 * `-----------+------+------+------+------+---------------'           `-------------+------+------+------+------+--------'
 *   |         |      |      |      |      |                                       |   0  |    . |   0  |   =  |      |
 *   `-------------------------------------'                                       `----------------------------------'
 *                                             ,-------------.       ,-------------.
 *                                             |      |      |       |      |      |
 *                                      ,------|------|------|       |------+------+------.
 *                                      |      |      |      |       |      |      |      |
 *                                      |      |      |------|       |------|      |      |
 *                                      |      |      |      |       |      |      |      |
 *                                      `--------------------'       `--------------------'
 */
// Code and Numbers
[CODENUM] = LAYOUT_ergodox(
       // left hand
       KC_ESC,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_NO,KC_NO,KC_NO,KC_NO,KC_SearchEverywhere,LALT(KC_GRV),
       KC_UsagesOfSymbol,KC_NO,LCTL(KC_S), KC_NO,KC_Find,KC_GRV,
       KC_AttachToProcess,KC_NO,KC_NO,KC_NO,KC_NO,KC_CTL_SPC,LALT(KC_ENT),
          KC_TRNS,KC_NO,KC_NO,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_CALC, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_PLUS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_SLSH, KC_CLEAR,
       KC_MINS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_EQL, KC_TRNS,
                         KC_0,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      | Wheel|           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  Up  |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| Wheel|           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Down |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_WH_U,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
/* Keymap 3: Navigation between windows and desktops
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |Right | Down | Left |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |RESET |      | Alt  |  Tab |CTRLF4|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |WINCTL|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NAVIGATION
[NAV] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RESET, KC_TRNS, KC_LALT, KC_TAB, LCTL(KC_F4),
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, LGUI(KC_LCTL),
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(CODENUM)                // FN1 - Momentary Layer 1 (CODENUM)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
