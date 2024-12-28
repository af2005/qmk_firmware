// using as reference
// https://docs.qmk.fm/#/keymap

// thanks to atlacat, hailbreno, itsaferbie and weeheavy...

// and special thanks to  AGausmann and drashna for the layer-activated RGB underglow
// https://www.reddit.com/r/olkb/comments/6t1vdu/update_layeractivated_rgb_underglow/
// https://github.com/AGausmann/qmk_firmware/blob/agausmann-v3.x/keyboards/nyquist/keymaps/agausmann/keymap.c

#include QMK_KEYBOARD_H

#define ______ KC_TRNS

#define DEFAULT_LAYER 0     // caps lock is gui key (windows/command)
#define GAMING_LAYER 1     // left space is always space
#define ARROW_LAYER 2   // wasd are arrows
#define GAMING_ARROW_LAYER 3
#define CONFIG_LAYER 4     // Function Layer



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap BL: Base Layer (Default Layer)
   *
   * ,-----------------------------------------------------------.
   * | ' | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |Backsp |
   * |-----------------------------------------------------------|
   * | Tab | q | w | e | r | t | y | u | i | o | p | [ | ] |enter|
   * |------------------------------------------------------     |
   * | Ctrl  | a | s | d | f | g | h | j | k | l | ; | ' | # |   |
   * |-----------------------------------------------------------|
   * |Shft| < | z | x | c | v | b | n | m | , | . | / |  Shift   |
   * |-----------------------------------------------------------|
   * |MO2 |Gui |Alt | Space  | Del | Space  |Alt |Gui | NL |Ctrl |
   * `-----------------------------------------------------------'
   */
    [DEFAULT_LAYER] = LAYOUT_60_iso_split(
    //  1          2          3          4          5          6          7          8          9          10         11         12         13         14
        QK_GESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,
        KC_TAB ,   KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_RBRC,
        KC_LGUI,   KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,   KC_NUHS,   KC_ENT,
        KC_LSFT,   KC_NUBS,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
        TO(GAMING_LAYER),   KC_LCTL,   KC_LALT, LT(ARROW_LAYER, KC_SPC)  ,    KC_DEL,    KC_SPC,     KC_RGUI, KC_RALT,   TO(GAMING_LAYER),    KC_RCTL),

    [GAMING_LAYER] = LAYOUT_60_iso_split(
     //  1          2          3          4          5          6          7          8          9          10         11         12         13         14
           KC_ESC,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
         _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
         _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
         _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
         TO(DEFAULT_LAYER),   _______,   _______,   KC_SPC,    KC_SPC,    KC_SPC,   _______,   _______,    _______,    _______),

   [CONFIG_LAYER] = LAYOUT_60_iso_split(
	//  1          2          3          4          5          6          7          8          9          10         11         12         13         14
	    KC_ESC,    TO(DEFAULT_LAYER),     TO(GAMING_LAYER), _______,     _______,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    RGB_VAD,   RGB_VAI,    RGB_TOG,
        _______ ,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_PSCR,   _______,   _______,
        _______,   KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,  KC_MS_RIGHT,_______,  _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RIGHT,  _______,   _______,   _______,
        _______,   _______,  _______,   LCTL(KC_X),    LCTL(KC_C),    LCTL(KC_V),KC_MS_BTN2,_______,   KC_HOME,   KC_PAGE_DOWN, KC_PAGE_UP,   KC_END,    _______,
        TO(DEFAULT_LAYER),   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______),


   [ARROW_LAYER] = LAYOUT_60_iso_split(
	//  1          2         3          4          5          6          7          8          9        10        11        12         13         14
	    KC_GRAVE,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_KB_VOLUME_DOWN,    KC_KB_VOLUME_UP, KC_KB_MUTE,
        _______,   KC_HOME,    KC_UP,     KC_END,     KC_PGUP,   _______,   _______,   KC_P4,     KC_P5,   KC_P6,    KC_PAST,   KC_PSLS,   _______,
        _______,   KC_LEFT,    KC_DOWN,     KC_RIGHT,     KC_PGDN,   _______,   _______,   KC_P1,     KC_P2,   KC_P3,    KC_PPLS,   KC_PMNS,   _______,   _______,
        _______,   _______,    _______,   _______,    _______,   _______,   _______,   _______,   KC_P0,   KC_COMM,  KC_DOT,    KC_PEQL,   _______,
        _______,   _______,  _______,   MO(CONFIG_LAYER), _______,    _______,   _______,   _______,   TG(GAMING_LAYER),  _______),

  [GAMING_ARROW_LAYER] = LAYOUT_60_iso_split(
	//  1          2          3          4          5          6          7          8          9          10         11         12         13         14
	    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   KC_HOME,    KC_UP,     KC_END,    KC_PGUP,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   KC_LEFT,    KC_DOWN,   KC_RIGHT,  KC_PGDN,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   MO(CONFIG_LAYER),    _______,    _______,   _______,   _______,    _______,    _______)

};


void matrix_init_user(void) {
  rgblight_enable();
    layer_move(DEFAULT_LAYER);
}

void set_two_tone(uint8_t r_top, uint8_t g_top, uint8_t b_top, uint8_t r_bottom, uint8_t g_bottom, uint8_t b_bottom){
	rgblight_driver.flush();
	for (uint8_t i = 0; i < 8; i++) {
		rgblight_driver.set_color(i, r_top, g_top, b_top);
		rgblight_driver.set_color(i+8, r_bottom, g_bottom, b_bottom);
	}

	rgblight_set();
}

void keyboard_post_init_user(void) {
    layer_move(DEFAULT_LAYER);
    rgblight_driver.init();
    rgblight_mode(RGBLIGHT_MODE_STATIC_GRADIENT);
    rgblight_setrgb(197,122,47);  // Default to red initially (we will update this per layer)
    set_two_tone(189, 133,78,189, 133,78);
}



// cold white: 205,177,149
// golden : 197,106,18
// light gold:  197,122,47
// gainsboro: 206, 154, 102
// blue: 0, 10, 100

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (biton32(state)) {
        case DEFAULT_LAYER:
            rgblight_setrgb(189, 133,78);
            break;
        case ARROW_LAYER:
            //set_two_tone(189, 133,78,197,122,47);
            break;
        case CONFIG_LAYER:
            //set_two_tone(205,177,149,205,177,149);
            break;
        case GAMING_LAYER:
            rgblight_setrgb(0, 10, 100);
            break;
        case GAMING_ARROW_LAYER:
            //rgblight_setrgb(0, 10, 120);
        break;
    }
    return state;
}
