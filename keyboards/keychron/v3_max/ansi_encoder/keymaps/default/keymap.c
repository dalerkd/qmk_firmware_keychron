/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"


//#define COMBO_ONLY_FROM_LAYER 4
//#define COMBO_TERM 100    // 设置触发时间ms


enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    COMBO_LAYER,
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,    KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), TO(COMBO_LAYER),    KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  QK_BOOT,  _______,  _______,  _______,              _______,              _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______),


    [COMBO_LAYER] = LAYOUT_tkl_ansi(
        KC_ESC,   KC_F1,    KC_F2,    QK_BOOT,     KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  KC_CTANA, RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_T,     KC_R,     KC_E,     KC_W,     KC_Q,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_G,     KC_F,     KC_D,     KC_S,     KC_A,     KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_B,     KC_V,     KC_C,     KC_X,     KC_Z,                 KC_RSFT,              KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN),  TO(WIN_BASE),    KC_LEFT,  KC_DOWN,  KC_RGHT),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [COMBO_LAYER] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on


bool first_run_shoud_disable_combo = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }

    /*
        仅在 COMBO_LAYER 层运行 并击组合键. 以避免普通模式下出现干扰误触等.
    */
    if (first_run_shoud_disable_combo){
        combo_disable();
        first_run_shoud_disable_combo = false;

    }else if (keycode == TO(COMBO_LAYER) && record->event.pressed) {
        combo_enable();
    }else if (keycode == TO(WIN_BASE) && record->event.pressed){
        combo_disable();
    }

    return true;
}



// 本文件由  空明码键位_键盘_算法.py 生成,用于放置在 keymap.c 文件中的代码片段,作用是定义 适合空明码的键位宏
// 组合键定义
enum combos {
    KC_W_KC_F_KC_SEMICOLON__ha,
    KC_W_KC_F_KC_L__hs,
    KC_W_KC_F_KC_K__hd,
    KC_W_KC_F_KC_J__hf,
    KC_W_KC_F_KC_H__hg,
    KC_W_KC_F_KC_SLASH__hz,
    KC_W_KC_F_KC_DOT__hx,
    KC_W_KC_F_KC_COMMA__hc,
    KC_W_KC_F_KC_M__hv,
    KC_W_KC_F_KC_N__hb,
    KC_W_KC_F_KC_P__hq,
    KC_W_KC_F_KC_O__hw,
    KC_W_KC_F_KC_I__he,
    KC_W_KC_F_KC_U__hr,
    KC_W_KC_F_KC_Y__ht,
    KC_W_KC_F_KC_I_KC_J__hy,
    KC_W_KC_F_KC_U_KC_I__hu,
    KC_W_KC_F_KC_I_KC_O__hi,
    KC_W_KC_F_KC_U_KC_O__ho,
    KC_W_KC_F_KC_U_KC_P__hp,
    KC_W_KC_F_KC_J_KC_O__hh,
    KC_W_KC_F_KC_J_KC_K__hj,
    KC_W_KC_F_KC_K_KC_L__hk,
    KC_W_KC_F_KC_J_KC_L__hl,
    KC_W_KC_F_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_W_KC_F_KC_L_KC_COMMA__hn,
    KC_W_KC_F_KC_M_KC_COMMA__hm,
    KC_W_KC_F_KC_COMMA_KC_DOT__nodisplaychar,
    KC_W_KC_F_KC_M_KC_DOT__nodisplaychar,
    KC_W_KC_F_KC_M_KC_SLASH__nodisplaychar,
    KC_W_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_W_KC_F_KC_DOT_KC_SLASH__nodisplaychar,
    KC_W_KC_F_KC_N_KC_M__nodisplaychar,
    KC_W_KC_F_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_D_KC_F_KC_SEMICOLON__ja,
    KC_D_KC_F_KC_L__js,
    KC_D_KC_F_KC_K__jd,
    KC_D_KC_F_KC_J__jf,
    KC_D_KC_F_KC_H__jg,
    KC_D_KC_F_KC_SLASH__jz,
    KC_D_KC_F_KC_DOT__jx,
    KC_D_KC_F_KC_COMMA__jc,
    KC_D_KC_F_KC_M__jv,
    KC_D_KC_F_KC_N__jb,
    KC_D_KC_F_KC_P__jq,
    KC_D_KC_F_KC_O__jw,
    KC_D_KC_F_KC_I__je,
    KC_D_KC_F_KC_U__jr,
    KC_D_KC_F_KC_Y__jt,
    KC_D_KC_F_KC_I_KC_J__jy,
    KC_D_KC_F_KC_U_KC_I__ju,
    KC_D_KC_F_KC_I_KC_O__ji,
    KC_D_KC_F_KC_U_KC_O__jo,
    KC_D_KC_F_KC_U_KC_P__jp,
    KC_D_KC_F_KC_J_KC_O__jh,
    KC_D_KC_F_KC_J_KC_K__jj,
    KC_D_KC_F_KC_K_KC_L__jk,
    KC_D_KC_F_KC_J_KC_L__jl,
    KC_D_KC_F_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_D_KC_F_KC_L_KC_COMMA__jn,
    KC_D_KC_F_KC_M_KC_COMMA__jm,
    KC_D_KC_F_KC_COMMA_KC_DOT__nodisplaychar,
    KC_D_KC_F_KC_M_KC_DOT__nodisplaychar,
    KC_D_KC_F_KC_M_KC_SLASH__nodisplaychar,
    KC_D_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_D_KC_F_KC_DOT_KC_SLASH__nodisplaychar,
    KC_D_KC_F_KC_N_KC_M__nodisplaychar,
    KC_D_KC_F_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_S_KC_D_KC_SEMICOLON__ka,
    KC_S_KC_D_KC_L__ks,
    KC_S_KC_D_KC_K__kd,
    KC_S_KC_D_KC_J__kf,
    KC_S_KC_D_KC_H__kg,
    KC_S_KC_D_KC_SLASH__kz,
    KC_S_KC_D_KC_DOT__kx,
    KC_S_KC_D_KC_COMMA__kc,
    KC_S_KC_D_KC_M__kv,
    KC_S_KC_D_KC_N__kb,
    KC_S_KC_D_KC_P__kq,
    KC_S_KC_D_KC_O__kw,
    KC_S_KC_D_KC_I__ke,
    KC_S_KC_D_KC_U__kr,
    KC_S_KC_D_KC_Y__kt,
    KC_S_KC_D_KC_I_KC_J__ky,
    KC_S_KC_D_KC_U_KC_I__ku,
    KC_S_KC_D_KC_I_KC_O__ki,
    KC_S_KC_D_KC_U_KC_O__ko,
    KC_S_KC_D_KC_U_KC_P__kp,
    KC_S_KC_D_KC_J_KC_O__kh,
    KC_S_KC_D_KC_J_KC_K__kj,
    KC_S_KC_D_KC_K_KC_L__kk,
    KC_S_KC_D_KC_J_KC_L__kl,
    KC_S_KC_D_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_S_KC_D_KC_L_KC_COMMA__kn,
    KC_S_KC_D_KC_M_KC_COMMA__km,
    KC_S_KC_D_KC_COMMA_KC_DOT__nodisplaychar,
    KC_S_KC_D_KC_M_KC_DOT__nodisplaychar,
    KC_S_KC_D_KC_M_KC_SLASH__nodisplaychar,
    KC_S_KC_D_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_S_KC_D_KC_DOT_KC_SLASH__nodisplaychar,
    KC_S_KC_D_KC_N_KC_M__nodisplaychar,
    KC_S_KC_D_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_S_KC_F_KC_SEMICOLON__la,
    KC_S_KC_F_KC_L__ls,
    KC_S_KC_F_KC_K__ld,
    KC_S_KC_F_KC_J__lf,
    KC_S_KC_F_KC_H__lg,
    KC_S_KC_F_KC_SLASH__lz,
    KC_S_KC_F_KC_DOT__lx,
    KC_S_KC_F_KC_COMMA__lc,
    KC_S_KC_F_KC_M__lv,
    KC_S_KC_F_KC_N__lb,
    KC_S_KC_F_KC_P__lq,
    KC_S_KC_F_KC_O__lw,
    KC_S_KC_F_KC_I__le,
    KC_S_KC_F_KC_U__lr,
    KC_S_KC_F_KC_Y__lt,
    KC_S_KC_F_KC_I_KC_J__ly,
    KC_S_KC_F_KC_U_KC_I__lu,
    KC_S_KC_F_KC_I_KC_O__li,
    KC_S_KC_F_KC_U_KC_O__lo,
    KC_S_KC_F_KC_U_KC_P__lp,
    KC_S_KC_F_KC_J_KC_O__lh,
    KC_S_KC_F_KC_J_KC_K__lj,
    KC_S_KC_F_KC_K_KC_L__lk,
    KC_S_KC_F_KC_J_KC_L__ll,
    KC_S_KC_F_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_S_KC_F_KC_L_KC_COMMA__ln,
    KC_S_KC_F_KC_M_KC_COMMA__lm,
    KC_S_KC_F_KC_COMMA_KC_DOT__nodisplaychar,
    KC_S_KC_F_KC_M_KC_DOT__nodisplaychar,
    KC_S_KC_F_KC_M_KC_SLASH__nodisplaychar,
    KC_S_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_S_KC_F_KC_DOT_KC_SLASH__nodisplaychar,
    KC_S_KC_F_KC_N_KC_M__nodisplaychar,
    KC_S_KC_F_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_F_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_F_KC_L__nodisplaychar,
    KC_A_KC_F_KC_K__nodisplaychar,
    KC_A_KC_F_KC_J__nodisplaychar,
    KC_A_KC_F_KC_H__nodisplaychar,
    KC_A_KC_F_KC_SLASH__nodisplaychar,
    KC_A_KC_F_KC_DOT__nodisplaychar,
    KC_A_KC_F_KC_COMMA__nodisplaychar,
    KC_A_KC_F_KC_M__nodisplaychar,
    KC_A_KC_F_KC_N__nodisplaychar,
    KC_A_KC_F_KC_P__nodisplaychar,
    KC_A_KC_F_KC_O__nodisplaychar,
    KC_A_KC_F_KC_I__nodisplaychar,
    KC_A_KC_F_KC_U__nodisplaychar,
    KC_A_KC_F_KC_Y__nodisplaychar,
    KC_A_KC_F_KC_I_KC_J__nodisplaychar,
    KC_A_KC_F_KC_U_KC_I__nodisplaychar,
    KC_A_KC_F_KC_I_KC_O__nodisplaychar,
    KC_A_KC_F_KC_U_KC_O__nodisplaychar,
    KC_A_KC_F_KC_U_KC_P__nodisplaychar,
    KC_A_KC_F_KC_J_KC_O__nodisplaychar,
    KC_A_KC_F_KC_J_KC_K__nodisplaychar,
    KC_A_KC_F_KC_K_KC_L__nodisplaychar,
    KC_A_KC_F_KC_J_KC_L__nodisplaychar,
    KC_A_KC_F_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_F_KC_L_KC_COMMA__nodisplaychar,
    KC_A_KC_F_KC_M_KC_COMMA__nodisplaychar,
    KC_A_KC_F_KC_COMMA_KC_DOT__nodisplaychar,
    KC_A_KC_F_KC_M_KC_DOT__nodisplaychar,
    KC_A_KC_F_KC_M_KC_SLASH__nodisplaychar,
    KC_A_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_A_KC_F_KC_DOT_KC_SLASH__nodisplaychar,
    KC_A_KC_F_KC_N_KC_M__nodisplaychar,
    KC_A_KC_F_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_S_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_S_KC_L__nodisplaychar,
    KC_A_KC_S_KC_K__nodisplaychar,
    KC_A_KC_S_KC_J__nodisplaychar,
    KC_A_KC_S_KC_H__nodisplaychar,
    KC_A_KC_S_KC_SLASH__nodisplaychar,
    KC_A_KC_S_KC_DOT__nodisplaychar,
    KC_A_KC_S_KC_COMMA__nodisplaychar,
    KC_A_KC_S_KC_M__nodisplaychar,
    KC_A_KC_S_KC_N__nodisplaychar,
    KC_A_KC_S_KC_P__nodisplaychar,
    KC_A_KC_S_KC_O__nodisplaychar,
    KC_A_KC_S_KC_I__nodisplaychar,
    KC_A_KC_S_KC_U__nodisplaychar,
    KC_A_KC_S_KC_Y__nodisplaychar,
    KC_A_KC_S_KC_I_KC_J__nodisplaychar,
    KC_A_KC_S_KC_U_KC_I__nodisplaychar,
    KC_A_KC_S_KC_I_KC_O__nodisplaychar,
    KC_A_KC_S_KC_U_KC_O__nodisplaychar,
    KC_A_KC_S_KC_U_KC_P__nodisplaychar,
    KC_A_KC_S_KC_J_KC_O__nodisplaychar,
    KC_A_KC_S_KC_J_KC_K__nodisplaychar,
    KC_A_KC_S_KC_K_KC_L__nodisplaychar,
    KC_A_KC_S_KC_J_KC_L__nodisplaychar,
    KC_A_KC_S_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_S_KC_L_KC_COMMA__nodisplaychar,
    KC_A_KC_S_KC_M_KC_COMMA__nodisplaychar,
    KC_A_KC_S_KC_COMMA_KC_DOT__nodisplaychar,
    KC_A_KC_S_KC_M_KC_DOT__nodisplaychar,
    KC_A_KC_S_KC_M_KC_SLASH__nodisplaychar,
    KC_A_KC_S_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_A_KC_S_KC_DOT_KC_SLASH__nodisplaychar,
    KC_A_KC_S_KC_N_KC_M__nodisplaychar,
    KC_A_KC_S_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_S_KC_C_KC_SEMICOLON__na,
    KC_S_KC_C_KC_L__ns,
    KC_S_KC_C_KC_K__nd,
    KC_S_KC_C_KC_J__nf,
    KC_S_KC_C_KC_H__ng,
    KC_S_KC_C_KC_SLASH__nz,
    KC_S_KC_C_KC_DOT__nx,
    KC_S_KC_C_KC_COMMA__nc,
    KC_S_KC_C_KC_M__nv,
    KC_S_KC_C_KC_N__nb,
    KC_S_KC_C_KC_P__nq,
    KC_S_KC_C_KC_O__nw,
    KC_S_KC_C_KC_I__ne,
    KC_S_KC_C_KC_U__nr,
    KC_S_KC_C_KC_Y__nt,
    KC_S_KC_C_KC_I_KC_J__ny,
    KC_S_KC_C_KC_U_KC_I__nu,
    KC_S_KC_C_KC_I_KC_O__ni,
    KC_S_KC_C_KC_U_KC_O__no,
    KC_S_KC_C_KC_U_KC_P__np,
    KC_S_KC_C_KC_J_KC_O__nh,
    KC_S_KC_C_KC_J_KC_K__nj,
    KC_S_KC_C_KC_K_KC_L__nk,
    KC_S_KC_C_KC_J_KC_L__nl,
    KC_S_KC_C_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_S_KC_C_KC_L_KC_COMMA__nn,
    KC_S_KC_C_KC_M_KC_COMMA__nm,
    KC_S_KC_C_KC_COMMA_KC_DOT__nodisplaychar,
    KC_S_KC_C_KC_M_KC_DOT__nodisplaychar,
    KC_S_KC_C_KC_M_KC_SLASH__nodisplaychar,
    KC_S_KC_C_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_S_KC_C_KC_DOT_KC_SLASH__nodisplaychar,
    KC_S_KC_C_KC_N_KC_M__nodisplaychar,
    KC_S_KC_C_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_C_KC_V_KC_SEMICOLON__ma,
    KC_C_KC_V_KC_L__ms,
    KC_C_KC_V_KC_K__md,
    KC_C_KC_V_KC_J__mf,
    KC_C_KC_V_KC_H__mg,
    KC_C_KC_V_KC_SLASH__mz,
    KC_C_KC_V_KC_DOT__mx,
    KC_C_KC_V_KC_COMMA__mc,
    KC_C_KC_V_KC_M__mv,
    KC_C_KC_V_KC_N__mb,
    KC_C_KC_V_KC_P__mq,
    KC_C_KC_V_KC_O__mw,
    KC_C_KC_V_KC_I__me,
    KC_C_KC_V_KC_U__mr,
    KC_C_KC_V_KC_Y__mt,
    KC_C_KC_V_KC_I_KC_J__my,
    KC_C_KC_V_KC_U_KC_I__mu,
    KC_C_KC_V_KC_I_KC_O__mi,
    KC_C_KC_V_KC_U_KC_O__mo,
    KC_C_KC_V_KC_U_KC_P__mp,
    KC_C_KC_V_KC_J_KC_O__mh,
    KC_C_KC_V_KC_J_KC_K__mj,
    KC_C_KC_V_KC_K_KC_L__mk,
    KC_C_KC_V_KC_J_KC_L__ml,
    KC_C_KC_V_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_C_KC_V_KC_L_KC_COMMA__mn,
    KC_C_KC_V_KC_M_KC_COMMA__mm,
    KC_C_KC_V_KC_COMMA_KC_DOT__nodisplaychar,
    KC_C_KC_V_KC_M_KC_DOT__nodisplaychar,
    KC_C_KC_V_KC_M_KC_SLASH__nodisplaychar,
    KC_C_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_C_KC_V_KC_DOT_KC_SLASH__nodisplaychar,
    KC_C_KC_V_KC_N_KC_M__nodisplaychar,
    KC_C_KC_V_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_X_KC_C_KC_SEMICOLON__nodisplaychar,
    KC_X_KC_C_KC_L__nodisplaychar,
    KC_X_KC_C_KC_K__nodisplaychar,
    KC_X_KC_C_KC_J__nodisplaychar,
    KC_X_KC_C_KC_H__nodisplaychar,
    KC_X_KC_C_KC_SLASH__nodisplaychar,
    KC_X_KC_C_KC_DOT__nodisplaychar,
    KC_X_KC_C_KC_COMMA__nodisplaychar,
    KC_X_KC_C_KC_M__nodisplaychar,
    KC_X_KC_C_KC_N__nodisplaychar,
    KC_X_KC_C_KC_P__nodisplaychar,
    KC_X_KC_C_KC_O__nodisplaychar,
    KC_X_KC_C_KC_I__nodisplaychar,
    KC_X_KC_C_KC_U__nodisplaychar,
    KC_X_KC_C_KC_Y__nodisplaychar,
    KC_X_KC_C_KC_I_KC_J__nodisplaychar,
    KC_X_KC_C_KC_U_KC_I__nodisplaychar,
    KC_X_KC_C_KC_I_KC_O__nodisplaychar,
    KC_X_KC_C_KC_U_KC_O__nodisplaychar,
    KC_X_KC_C_KC_U_KC_P__nodisplaychar,
    KC_X_KC_C_KC_J_KC_O__nodisplaychar,
    KC_X_KC_C_KC_J_KC_K__nodisplaychar,
    KC_X_KC_C_KC_K_KC_L__nodisplaychar,
    KC_X_KC_C_KC_J_KC_L__nodisplaychar,
    KC_X_KC_C_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_X_KC_C_KC_L_KC_COMMA__nodisplaychar,
    KC_X_KC_C_KC_M_KC_COMMA__nodisplaychar,
    KC_X_KC_C_KC_COMMA_KC_DOT__nodisplaychar,
    KC_X_KC_C_KC_M_KC_DOT__nodisplaychar,
    KC_X_KC_C_KC_M_KC_SLASH__nodisplaychar,
    KC_X_KC_C_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_X_KC_C_KC_DOT_KC_SLASH__nodisplaychar,
    KC_X_KC_C_KC_N_KC_M__nodisplaychar,
    KC_X_KC_C_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_T_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_T_KC_L__nodisplaychar,
    KC_A_KC_T_KC_K__nodisplaychar,
    KC_A_KC_T_KC_J__nodisplaychar,
    KC_A_KC_T_KC_H__nodisplaychar,
    KC_A_KC_T_KC_SLASH__nodisplaychar,
    KC_A_KC_T_KC_DOT__nodisplaychar,
    KC_A_KC_T_KC_COMMA__nodisplaychar,
    KC_A_KC_T_KC_M__nodisplaychar,
    KC_A_KC_T_KC_N__nodisplaychar,
    KC_A_KC_T_KC_P__nodisplaychar,
    KC_A_KC_T_KC_O__nodisplaychar,
    KC_A_KC_T_KC_I__nodisplaychar,
    KC_A_KC_T_KC_U__nodisplaychar,
    KC_A_KC_T_KC_Y__nodisplaychar,
    KC_A_KC_T_KC_I_KC_J__nodisplaychar,
    KC_A_KC_T_KC_U_KC_I__nodisplaychar,
    KC_A_KC_T_KC_I_KC_O__nodisplaychar,
    KC_A_KC_T_KC_U_KC_O__nodisplaychar,
    KC_A_KC_T_KC_U_KC_P__nodisplaychar,
    KC_A_KC_T_KC_J_KC_O__nodisplaychar,
    KC_A_KC_T_KC_J_KC_K__nodisplaychar,
    KC_A_KC_T_KC_K_KC_L__nodisplaychar,
    KC_A_KC_T_KC_J_KC_L__nodisplaychar,
    KC_A_KC_T_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_T_KC_L_KC_COMMA__nodisplaychar,
    KC_A_KC_T_KC_M_KC_COMMA__nodisplaychar,
    KC_A_KC_T_KC_COMMA_KC_DOT__nodisplaychar,
    KC_A_KC_T_KC_M_KC_DOT__nodisplaychar,
    KC_A_KC_T_KC_M_KC_SLASH__nodisplaychar,
    KC_A_KC_T_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_A_KC_T_KC_DOT_KC_SLASH__nodisplaychar,
    KC_A_KC_T_KC_N_KC_M__nodisplaychar,
    KC_A_KC_T_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_X_KC_V_KC_SEMICOLON__nodisplaychar,
    KC_X_KC_V_KC_L__nodisplaychar,
    KC_X_KC_V_KC_K__nodisplaychar,
    KC_X_KC_V_KC_J__nodisplaychar,
    KC_X_KC_V_KC_H__nodisplaychar,
    KC_X_KC_V_KC_SLASH__nodisplaychar,
    KC_X_KC_V_KC_DOT__nodisplaychar,
    KC_X_KC_V_KC_COMMA__nodisplaychar,
    KC_X_KC_V_KC_M__nodisplaychar,
    KC_X_KC_V_KC_N__nodisplaychar,
    KC_X_KC_V_KC_P__nodisplaychar,
    KC_X_KC_V_KC_O__nodisplaychar,
    KC_X_KC_V_KC_I__nodisplaychar,
    KC_X_KC_V_KC_U__nodisplaychar,
    KC_X_KC_V_KC_Y__nodisplaychar,
    KC_X_KC_V_KC_I_KC_J__nodisplaychar,
    KC_X_KC_V_KC_U_KC_I__nodisplaychar,
    KC_X_KC_V_KC_I_KC_O__nodisplaychar,
    KC_X_KC_V_KC_U_KC_O__nodisplaychar,
    KC_X_KC_V_KC_U_KC_P__nodisplaychar,
    KC_X_KC_V_KC_J_KC_O__nodisplaychar,
    KC_X_KC_V_KC_J_KC_K__nodisplaychar,
    KC_X_KC_V_KC_K_KC_L__nodisplaychar,
    KC_X_KC_V_KC_J_KC_L__nodisplaychar,
    KC_X_KC_V_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_X_KC_V_KC_L_KC_COMMA__nodisplaychar,
    KC_X_KC_V_KC_M_KC_COMMA__nodisplaychar,
    KC_X_KC_V_KC_COMMA_KC_DOT__nodisplaychar,
    KC_X_KC_V_KC_M_KC_DOT__nodisplaychar,
    KC_X_KC_V_KC_M_KC_SLASH__nodisplaychar,
    KC_X_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_X_KC_V_KC_DOT_KC_SLASH__nodisplaychar,
    KC_X_KC_V_KC_N_KC_M__nodisplaychar,
    KC_X_KC_V_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_Z_KC_V_KC_SEMICOLON__nodisplaychar,
    KC_Z_KC_V_KC_L__nodisplaychar,
    KC_Z_KC_V_KC_K__nodisplaychar,
    KC_Z_KC_V_KC_J__nodisplaychar,
    KC_Z_KC_V_KC_H__nodisplaychar,
    KC_Z_KC_V_KC_SLASH__nodisplaychar,
    KC_Z_KC_V_KC_DOT__nodisplaychar,
    KC_Z_KC_V_KC_COMMA__nodisplaychar,
    KC_Z_KC_V_KC_M__nodisplaychar,
    KC_Z_KC_V_KC_N__nodisplaychar,
    KC_Z_KC_V_KC_P__nodisplaychar,
    KC_Z_KC_V_KC_O__nodisplaychar,
    KC_Z_KC_V_KC_I__nodisplaychar,
    KC_Z_KC_V_KC_U__nodisplaychar,
    KC_Z_KC_V_KC_Y__nodisplaychar,
    KC_Z_KC_V_KC_I_KC_J__nodisplaychar,
    KC_Z_KC_V_KC_U_KC_I__nodisplaychar,
    KC_Z_KC_V_KC_I_KC_O__nodisplaychar,
    KC_Z_KC_V_KC_U_KC_O__nodisplaychar,
    KC_Z_KC_V_KC_U_KC_P__nodisplaychar,
    KC_Z_KC_V_KC_J_KC_O__nodisplaychar,
    KC_Z_KC_V_KC_J_KC_K__nodisplaychar,
    KC_Z_KC_V_KC_K_KC_L__nodisplaychar,
    KC_Z_KC_V_KC_J_KC_L__nodisplaychar,
    KC_Z_KC_V_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_Z_KC_V_KC_L_KC_COMMA__nodisplaychar,
    KC_Z_KC_V_KC_M_KC_COMMA__nodisplaychar,
    KC_Z_KC_V_KC_COMMA_KC_DOT__nodisplaychar,
    KC_Z_KC_V_KC_M_KC_DOT__nodisplaychar,
    KC_Z_KC_V_KC_M_KC_SLASH__nodisplaychar,
    KC_Z_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_Z_KC_V_KC_DOT_KC_SLASH__nodisplaychar,
    KC_Z_KC_V_KC_N_KC_M__nodisplaychar,
    KC_Z_KC_V_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_Z_KC_X_KC_SEMICOLON__nodisplaychar,
    KC_Z_KC_X_KC_L__nodisplaychar,
    KC_Z_KC_X_KC_K__nodisplaychar,
    KC_Z_KC_X_KC_J__nodisplaychar,
    KC_Z_KC_X_KC_H__nodisplaychar,
    KC_Z_KC_X_KC_SLASH__nodisplaychar,
    KC_Z_KC_X_KC_DOT__nodisplaychar,
    KC_Z_KC_X_KC_COMMA__nodisplaychar,
    KC_Z_KC_X_KC_M__nodisplaychar,
    KC_Z_KC_X_KC_N__nodisplaychar,
    KC_Z_KC_X_KC_P__nodisplaychar,
    KC_Z_KC_X_KC_O__nodisplaychar,
    KC_Z_KC_X_KC_I__nodisplaychar,
    KC_Z_KC_X_KC_U__nodisplaychar,
    KC_Z_KC_X_KC_Y__nodisplaychar,
    KC_Z_KC_X_KC_I_KC_J__nodisplaychar,
    KC_Z_KC_X_KC_U_KC_I__nodisplaychar,
    KC_Z_KC_X_KC_I_KC_O__nodisplaychar,
    KC_Z_KC_X_KC_U_KC_O__nodisplaychar,
    KC_Z_KC_X_KC_U_KC_P__nodisplaychar,
    KC_Z_KC_X_KC_J_KC_O__nodisplaychar,
    KC_Z_KC_X_KC_J_KC_K__nodisplaychar,
    KC_Z_KC_X_KC_K_KC_L__nodisplaychar,
    KC_Z_KC_X_KC_J_KC_L__nodisplaychar,
    KC_Z_KC_X_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_Z_KC_X_KC_L_KC_COMMA__nodisplaychar,
    KC_Z_KC_X_KC_M_KC_COMMA__nodisplaychar,
    KC_Z_KC_X_KC_COMMA_KC_DOT__nodisplaychar,
    KC_Z_KC_X_KC_M_KC_DOT__nodisplaychar,
    KC_Z_KC_X_KC_M_KC_SLASH__nodisplaychar,
    KC_Z_KC_X_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_Z_KC_X_KC_DOT_KC_SLASH__nodisplaychar,
    KC_Z_KC_X_KC_N_KC_M__nodisplaychar,
    KC_Z_KC_X_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_E_KC_F_KC_SEMICOLON__ya,
    KC_E_KC_F_KC_L__ys,
    KC_E_KC_F_KC_K__yd,
    KC_E_KC_F_KC_J__yf,
    KC_E_KC_F_KC_H__yg,
    KC_E_KC_F_KC_SLASH__yz,
    KC_E_KC_F_KC_DOT__yx,
    KC_E_KC_F_KC_COMMA__yc,
    KC_E_KC_F_KC_M__yv,
    KC_E_KC_F_KC_N__yb,
    KC_E_KC_F_KC_P__yq,
    KC_E_KC_F_KC_O__yw,
    KC_E_KC_F_KC_I__ye,
    KC_E_KC_F_KC_U__yr,
    KC_E_KC_F_KC_Y__yt,
    KC_E_KC_F_KC_I_KC_J__yy,
    KC_E_KC_F_KC_U_KC_I__yu,
    KC_E_KC_F_KC_I_KC_O__yi,
    KC_E_KC_F_KC_U_KC_O__yo,
    KC_E_KC_F_KC_U_KC_P__yp,
    KC_E_KC_F_KC_J_KC_O__yh,
    KC_E_KC_F_KC_J_KC_K__yj,
    KC_E_KC_F_KC_K_KC_L__yk,
    KC_E_KC_F_KC_J_KC_L__yl,
    KC_E_KC_F_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_E_KC_F_KC_L_KC_COMMA__yn,
    KC_E_KC_F_KC_M_KC_COMMA__ym,
    KC_E_KC_F_KC_COMMA_KC_DOT__nodisplaychar,
    KC_E_KC_F_KC_M_KC_DOT__nodisplaychar,
    KC_E_KC_F_KC_M_KC_SLASH__nodisplaychar,
    KC_E_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_E_KC_F_KC_DOT_KC_SLASH__nodisplaychar,
    KC_E_KC_F_KC_N_KC_M__nodisplaychar,
    KC_E_KC_F_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_E_KC_R_KC_SEMICOLON__ua,
    KC_E_KC_R_KC_L__us,
    KC_E_KC_R_KC_K__ud,
    KC_E_KC_R_KC_J__uf,
    KC_E_KC_R_KC_H__ug,
    KC_E_KC_R_KC_SLASH__uz,
    KC_E_KC_R_KC_DOT__ux,
    KC_E_KC_R_KC_COMMA__uc,
    KC_E_KC_R_KC_M__uv,
    KC_E_KC_R_KC_N__ub,
    KC_E_KC_R_KC_P__uq,
    KC_E_KC_R_KC_O__uw,
    KC_E_KC_R_KC_I__ue,
    KC_E_KC_R_KC_U__ur,
    KC_E_KC_R_KC_Y__ut,
    KC_E_KC_R_KC_I_KC_J__uy,
    KC_E_KC_R_KC_U_KC_I__uu,
    KC_E_KC_R_KC_I_KC_O__ui,
    KC_E_KC_R_KC_U_KC_O__uo,
    KC_E_KC_R_KC_U_KC_P__up,
    KC_E_KC_R_KC_J_KC_O__uh,
    KC_E_KC_R_KC_J_KC_K__uj,
    KC_E_KC_R_KC_K_KC_L__uk,
    KC_E_KC_R_KC_J_KC_L__ul,
    KC_E_KC_R_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_E_KC_R_KC_L_KC_COMMA__un,
    KC_E_KC_R_KC_M_KC_COMMA__um,
    KC_E_KC_R_KC_COMMA_KC_DOT__nodisplaychar,
    KC_E_KC_R_KC_M_KC_DOT__nodisplaychar,
    KC_E_KC_R_KC_M_KC_SLASH__nodisplaychar,
    KC_E_KC_R_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_E_KC_R_KC_DOT_KC_SLASH__nodisplaychar,
    KC_E_KC_R_KC_N_KC_M__nodisplaychar,
    KC_E_KC_R_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_W_KC_E_KC_SEMICOLON__ia,
    KC_W_KC_E_KC_L__is,
    KC_W_KC_E_KC_K__id,
    KC_W_KC_E_KC_J__if,
    KC_W_KC_E_KC_H__ig,
    KC_W_KC_E_KC_SLASH__iz,
    KC_W_KC_E_KC_DOT__ix,
    KC_W_KC_E_KC_COMMA__ic,
    KC_W_KC_E_KC_M__iv,
    KC_W_KC_E_KC_N__ib,
    KC_W_KC_E_KC_P__iq,
    KC_W_KC_E_KC_O__iw,
    KC_W_KC_E_KC_I__ie,
    KC_W_KC_E_KC_U__ir,
    KC_W_KC_E_KC_Y__it,
    KC_W_KC_E_KC_I_KC_J__iy,
    KC_W_KC_E_KC_U_KC_I__iu,
    KC_W_KC_E_KC_I_KC_O__ii,
    KC_W_KC_E_KC_U_KC_O__io,
    KC_W_KC_E_KC_U_KC_P__ip,
    KC_W_KC_E_KC_J_KC_O__ih,
    KC_W_KC_E_KC_J_KC_K__ij,
    KC_W_KC_E_KC_K_KC_L__ik,
    KC_W_KC_E_KC_J_KC_L__il,
    KC_W_KC_E_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_W_KC_E_KC_L_KC_COMMA__in,
    KC_W_KC_E_KC_M_KC_COMMA__im,
    KC_W_KC_E_KC_COMMA_KC_DOT__nodisplaychar,
    KC_W_KC_E_KC_M_KC_DOT__nodisplaychar,
    KC_W_KC_E_KC_M_KC_SLASH__nodisplaychar,
    KC_W_KC_E_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_W_KC_E_KC_DOT_KC_SLASH__nodisplaychar,
    KC_W_KC_E_KC_N_KC_M__nodisplaychar,
    KC_W_KC_E_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_W_KC_R_KC_SEMICOLON__oa,
    KC_W_KC_R_KC_L__os,
    KC_W_KC_R_KC_K__od,
    KC_W_KC_R_KC_J__of,
    KC_W_KC_R_KC_H__og,
    KC_W_KC_R_KC_SLASH__oz,
    KC_W_KC_R_KC_DOT__ox,
    KC_W_KC_R_KC_COMMA__oc,
    KC_W_KC_R_KC_M__ov,
    KC_W_KC_R_KC_N__ob,
    KC_W_KC_R_KC_P__oq,
    KC_W_KC_R_KC_O__ow,
    KC_W_KC_R_KC_I__oe,
    KC_W_KC_R_KC_U__or,
    KC_W_KC_R_KC_Y__ot,
    KC_W_KC_R_KC_I_KC_J__oy,
    KC_W_KC_R_KC_U_KC_I__ou,
    KC_W_KC_R_KC_I_KC_O__oi,
    KC_W_KC_R_KC_U_KC_O__oo,
    KC_W_KC_R_KC_U_KC_P__op,
    KC_W_KC_R_KC_J_KC_O__oh,
    KC_W_KC_R_KC_J_KC_K__oj,
    KC_W_KC_R_KC_K_KC_L__ok,
    KC_W_KC_R_KC_J_KC_L__ol,
    KC_W_KC_R_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_W_KC_R_KC_L_KC_COMMA__on,
    KC_W_KC_R_KC_M_KC_COMMA__om,
    KC_W_KC_R_KC_COMMA_KC_DOT__nodisplaychar,
    KC_W_KC_R_KC_M_KC_DOT__nodisplaychar,
    KC_W_KC_R_KC_M_KC_SLASH__nodisplaychar,
    KC_W_KC_R_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_W_KC_R_KC_DOT_KC_SLASH__nodisplaychar,
    KC_W_KC_R_KC_N_KC_M__nodisplaychar,
    KC_W_KC_R_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_R_KC_Q_KC_SEMICOLON__pa,
    KC_R_KC_Q_KC_L__ps,
    KC_R_KC_Q_KC_K__pd,
    KC_R_KC_Q_KC_J__pf,
    KC_R_KC_Q_KC_H__pg,
    KC_R_KC_Q_KC_SLASH__pz,
    KC_R_KC_Q_KC_DOT__px,
    KC_R_KC_Q_KC_COMMA__pc,
    KC_R_KC_Q_KC_M__pv,
    KC_R_KC_Q_KC_N__pb,
    KC_R_KC_Q_KC_P__pq,
    KC_R_KC_Q_KC_O__pw,
    KC_R_KC_Q_KC_I__pe,
    KC_R_KC_Q_KC_U__pr,
    KC_R_KC_Q_KC_Y__pt,
    KC_R_KC_Q_KC_I_KC_J__py,
    KC_R_KC_Q_KC_U_KC_I__pu,
    KC_R_KC_Q_KC_I_KC_O__pi,
    KC_R_KC_Q_KC_U_KC_O__po,
    KC_R_KC_Q_KC_U_KC_P__pp,
    KC_R_KC_Q_KC_J_KC_O__ph,
    KC_R_KC_Q_KC_J_KC_K__pj,
    KC_R_KC_Q_KC_K_KC_L__pk,
    KC_R_KC_Q_KC_J_KC_L__pl,
    KC_R_KC_Q_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_R_KC_Q_KC_L_KC_COMMA__pn,
    KC_R_KC_Q_KC_M_KC_COMMA__pm,
    KC_R_KC_Q_KC_COMMA_KC_DOT__nodisplaychar,
    KC_R_KC_Q_KC_M_KC_DOT__nodisplaychar,
    KC_R_KC_Q_KC_M_KC_SLASH__nodisplaychar,
    KC_R_KC_Q_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_R_KC_Q_KC_DOT_KC_SLASH__nodisplaychar,
    KC_R_KC_Q_KC_N_KC_M__nodisplaychar,
    KC_R_KC_Q_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_Q_KC_SEMICOLON__qa,
    KC_Q_KC_L__qs,
    KC_Q_KC_K__qd,
    KC_Q_KC_J__qf,
    KC_Q_KC_H__qg,
    KC_Q_KC_SLASH__qz,
    KC_Q_KC_DOT__qx,
    KC_Q_KC_COMMA__qc,
    KC_Q_KC_M__qv,
    KC_Q_KC_N__qb,
    KC_Q_KC_P__qq,
    KC_Q_KC_O__qw,
    KC_Q_KC_I__qe,
    KC_Q_KC_U__qr,
    KC_Q_KC_Y__qt,
    KC_Q_KC_I_KC_J__qy,
    KC_Q_KC_U_KC_I__qu,
    KC_Q_KC_I_KC_O__qi,
    KC_Q_KC_U_KC_O__qo,
    KC_Q_KC_U_KC_P__qp,
    KC_Q_KC_J_KC_O__qh,
    KC_Q_KC_J_KC_K__qj,
    KC_Q_KC_K_KC_L__qk,
    KC_Q_KC_J_KC_L__ql,
    KC_Q_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_Q_KC_L_KC_COMMA__qn,
    KC_Q_KC_M_KC_COMMA__qm,
    KC_Q_KC_COMMA_KC_DOT__nodisplaychar,
    KC_Q_KC_M_KC_DOT__nodisplaychar,
    KC_Q_KC_M_KC_SLASH__nodisplaychar,
    KC_Q_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_Q_KC_DOT_KC_SLASH__nodisplaychar,
    KC_Q_KC_N_KC_M__nodisplaychar,
    KC_Q_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_W_KC_SEMICOLON__wa,
    KC_W_KC_L__ws,
    KC_W_KC_K__wd,
    KC_W_KC_J__wf,
    KC_W_KC_H__wg,
    KC_W_KC_SLASH__wz,
    KC_W_KC_DOT__wx,
    KC_W_KC_COMMA__wc,
    KC_W_KC_M__wv,
    KC_W_KC_N__wb,
    KC_W_KC_P__wq,
    KC_W_KC_O__ww,
    KC_W_KC_I__we,
    KC_W_KC_U__wr,
    KC_W_KC_Y__wt,
    KC_W_KC_I_KC_J__wy,
    KC_W_KC_U_KC_I__wu,
    KC_W_KC_I_KC_O__wi,
    KC_W_KC_U_KC_O__wo,
    KC_W_KC_U_KC_P__wp,
    KC_W_KC_J_KC_O__wh,
    KC_W_KC_J_KC_K__wj,
    KC_W_KC_K_KC_L__wk,
    KC_W_KC_J_KC_L__wl,
    KC_W_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_W_KC_L_KC_COMMA__wn,
    KC_W_KC_M_KC_COMMA__wm,
    KC_W_KC_COMMA_KC_DOT__nodisplaychar,
    KC_W_KC_M_KC_DOT__nodisplaychar,
    KC_W_KC_M_KC_SLASH__nodisplaychar,
    KC_W_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_W_KC_DOT_KC_SLASH__nodisplaychar,
    KC_W_KC_N_KC_M__nodisplaychar,
    KC_W_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_E_KC_SEMICOLON__ea,
    KC_E_KC_L__es,
    KC_E_KC_K__ed,
    KC_E_KC_J__ef,
    KC_E_KC_H__eg,
    KC_E_KC_SLASH__ez,
    KC_E_KC_DOT__ex,
    KC_E_KC_COMMA__ec,
    KC_E_KC_M__ev,
    KC_E_KC_N__eb,
    KC_E_KC_P__eq,
    KC_E_KC_O__ew,
    KC_E_KC_I__ee,
    KC_E_KC_U__er,
    KC_E_KC_Y__et,
    KC_E_KC_I_KC_J__ey,
    KC_E_KC_U_KC_I__eu,
    KC_E_KC_I_KC_O__ei,
    KC_E_KC_U_KC_O__eo,
    KC_E_KC_U_KC_P__ep,
    KC_E_KC_J_KC_O__eh,
    KC_E_KC_J_KC_K__ej,
    KC_E_KC_K_KC_L__ek,
    KC_E_KC_J_KC_L__el,
    KC_E_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_E_KC_L_KC_COMMA__en,
    KC_E_KC_M_KC_COMMA__em,
    KC_E_KC_COMMA_KC_DOT__nodisplaychar,
    KC_E_KC_M_KC_DOT__nodisplaychar,
    KC_E_KC_M_KC_SLASH__nodisplaychar,
    KC_E_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_E_KC_DOT_KC_SLASH__nodisplaychar,
    KC_E_KC_N_KC_M__nodisplaychar,
    KC_E_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_R_KC_SEMICOLON__ra,
    KC_R_KC_L__rs,
    KC_R_KC_K__rd,
    KC_R_KC_J__rf,
    KC_R_KC_H__rg,
    KC_R_KC_SLASH__rz,
    KC_R_KC_DOT__rx,
    KC_R_KC_COMMA__rc,
    KC_R_KC_M__rv,
    KC_R_KC_N__rb,
    KC_R_KC_P__rq,
    KC_R_KC_O__rw,
    KC_R_KC_I__re,
    KC_R_KC_U__rr,
    KC_R_KC_Y__rt,
    KC_R_KC_I_KC_J__ry,
    KC_R_KC_U_KC_I__ru,
    KC_R_KC_I_KC_O__ri,
    KC_R_KC_U_KC_O__ro,
    KC_R_KC_U_KC_P__rp,
    KC_R_KC_J_KC_O__rh,
    KC_R_KC_J_KC_K__rj,
    KC_R_KC_K_KC_L__rk,
    KC_R_KC_J_KC_L__rl,
    KC_R_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_R_KC_L_KC_COMMA__rn,
    KC_R_KC_M_KC_COMMA__rm,
    KC_R_KC_COMMA_KC_DOT__nodisplaychar,
    KC_R_KC_M_KC_DOT__nodisplaychar,
    KC_R_KC_M_KC_SLASH__nodisplaychar,
    KC_R_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_R_KC_DOT_KC_SLASH__nodisplaychar,
    KC_R_KC_N_KC_M__nodisplaychar,
    KC_R_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_T_KC_SEMICOLON__ta,
    KC_T_KC_L__ts,
    KC_T_KC_K__td,
    KC_T_KC_J__tf,
    KC_T_KC_H__tg,
    KC_T_KC_SLASH__tz,
    KC_T_KC_DOT__tx,
    KC_T_KC_COMMA__tc,
    KC_T_KC_M__tv,
    KC_T_KC_N__tb,
    KC_T_KC_P__tq,
    KC_T_KC_O__tw,
    KC_T_KC_I__te,
    KC_T_KC_U__tr,
    KC_T_KC_Y__tt,
    KC_T_KC_I_KC_J__ty,
    KC_T_KC_U_KC_I__tu,
    KC_T_KC_I_KC_O__ti,
    KC_T_KC_U_KC_O__to,
    KC_T_KC_U_KC_P__tp,
    KC_T_KC_J_KC_O__th,
    KC_T_KC_J_KC_K__tj,
    KC_T_KC_K_KC_L__tk,
    KC_T_KC_J_KC_L__tl,
    KC_T_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_T_KC_L_KC_COMMA__tn,
    KC_T_KC_M_KC_COMMA__tm,
    KC_T_KC_COMMA_KC_DOT__nodisplaychar,
    KC_T_KC_M_KC_DOT__nodisplaychar,
    KC_T_KC_M_KC_SLASH__nodisplaychar,
    KC_T_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_T_KC_DOT_KC_SLASH__nodisplaychar,
    KC_T_KC_N_KC_M__nodisplaychar,
    KC_T_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_SEMICOLON__aa,
    KC_A_KC_L__as,
    KC_A_KC_K__ad,
    KC_A_KC_J__af,
    KC_A_KC_H__ag,
    KC_A_KC_SLASH__az,
    KC_A_KC_DOT__ax,
    KC_A_KC_COMMA__ac,
    KC_A_KC_M__av,
    KC_A_KC_N__ab,
    KC_A_KC_P__aq,
    KC_A_KC_O__aw,
    KC_A_KC_I__ae,
    KC_A_KC_U__ar,
    KC_A_KC_Y__at,
    KC_A_KC_I_KC_J__ay,
    KC_A_KC_U_KC_I__au,
    KC_A_KC_I_KC_O__ai,
    KC_A_KC_U_KC_O__ao,
    KC_A_KC_U_KC_P__ap,
    KC_A_KC_J_KC_O__ah,
    KC_A_KC_J_KC_K__aj,
    KC_A_KC_K_KC_L__ak,
    KC_A_KC_J_KC_L__al,
    KC_A_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_A_KC_L_KC_COMMA__an,
    KC_A_KC_M_KC_COMMA__am,
    KC_A_KC_COMMA_KC_DOT__nodisplaychar,
    KC_A_KC_M_KC_DOT__nodisplaychar,
    KC_A_KC_M_KC_SLASH__nodisplaychar,
    KC_A_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_A_KC_DOT_KC_SLASH__nodisplaychar,
    KC_A_KC_N_KC_M__nodisplaychar,
    KC_A_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_S_KC_SEMICOLON__sa,
    KC_S_KC_L__ss,
    KC_S_KC_K__sd,
    KC_S_KC_J__sf,
    KC_S_KC_H__sg,
    KC_S_KC_SLASH__sz,
    KC_S_KC_DOT__sx,
    KC_S_KC_COMMA__sc,
    KC_S_KC_M__sv,
    KC_S_KC_N__sb,
    KC_S_KC_P__sq,
    KC_S_KC_O__sw,
    KC_S_KC_I__se,
    KC_S_KC_U__sr,
    KC_S_KC_Y__st,
    KC_S_KC_I_KC_J__sy,
    KC_S_KC_U_KC_I__su,
    KC_S_KC_I_KC_O__si,
    KC_S_KC_U_KC_O__so,
    KC_S_KC_U_KC_P__sp,
    KC_S_KC_J_KC_O__sh,
    KC_S_KC_J_KC_K__sj,
    KC_S_KC_K_KC_L__sk,
    KC_S_KC_J_KC_L__sl,
    KC_S_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_S_KC_L_KC_COMMA__sn,
    KC_S_KC_M_KC_COMMA__sm,
    KC_S_KC_COMMA_KC_DOT__nodisplaychar,
    KC_S_KC_M_KC_DOT__nodisplaychar,
    KC_S_KC_M_KC_SLASH__nodisplaychar,
    KC_S_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_S_KC_DOT_KC_SLASH__nodisplaychar,
    KC_S_KC_N_KC_M__nodisplaychar,
    KC_S_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_D_KC_SEMICOLON__da,
    KC_D_KC_L__ds,
    KC_D_KC_K__dd,
    KC_D_KC_J__df,
    KC_D_KC_H__dg,
    KC_D_KC_SLASH__dz,
    KC_D_KC_DOT__dx,
    KC_D_KC_COMMA__dc,
    KC_D_KC_M__dv,
    KC_D_KC_N__db,
    KC_D_KC_P__dq,
    KC_D_KC_O__dw,
    KC_D_KC_I__de,
    KC_D_KC_U__dr,
    KC_D_KC_Y__dt,
    KC_D_KC_I_KC_J__dy,
    KC_D_KC_U_KC_I__du,
    KC_D_KC_I_KC_O__di,
    KC_D_KC_U_KC_O__do,
    KC_D_KC_U_KC_P__dp,
    KC_D_KC_J_KC_O__dh,
    KC_D_KC_J_KC_K__dj,
    KC_D_KC_K_KC_L__dk,
    KC_D_KC_J_KC_L__dl,
    KC_D_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_D_KC_L_KC_COMMA__dn,
    KC_D_KC_M_KC_COMMA__dm,
    KC_D_KC_COMMA_KC_DOT__nodisplaychar,
    KC_D_KC_M_KC_DOT__nodisplaychar,
    KC_D_KC_M_KC_SLASH__nodisplaychar,
    KC_D_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_D_KC_DOT_KC_SLASH__nodisplaychar,
    KC_D_KC_N_KC_M__nodisplaychar,
    KC_D_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_F_KC_SEMICOLON__fa,
    KC_F_KC_L__fs,
    KC_F_KC_K__fd,
    KC_F_KC_J__ff,
    KC_F_KC_H__fg,
    KC_F_KC_SLASH__fz,
    KC_F_KC_DOT__fx,
    KC_F_KC_COMMA__fc,
    KC_F_KC_M__fv,
    KC_F_KC_N__fb,
    KC_F_KC_P__fq,
    KC_F_KC_O__fw,
    KC_F_KC_I__fe,
    KC_F_KC_U__fr,
    KC_F_KC_Y__ft,
    KC_F_KC_I_KC_J__fy,
    KC_F_KC_U_KC_I__fu,
    KC_F_KC_I_KC_O__fi,
    KC_F_KC_U_KC_O__fo,
    KC_F_KC_U_KC_P__fp,
    KC_F_KC_J_KC_O__fh,
    KC_F_KC_J_KC_K__fj,
    KC_F_KC_K_KC_L__fk,
    KC_F_KC_J_KC_L__fl,
    KC_F_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_F_KC_L_KC_COMMA__fn,
    KC_F_KC_M_KC_COMMA__fm,
    KC_F_KC_COMMA_KC_DOT__nodisplaychar,
    KC_F_KC_M_KC_DOT__nodisplaychar,
    KC_F_KC_M_KC_SLASH__nodisplaychar,
    KC_F_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_F_KC_DOT_KC_SLASH__nodisplaychar,
    KC_F_KC_N_KC_M__nodisplaychar,
    KC_F_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_G_KC_SEMICOLON__ga,
    KC_G_KC_L__gs,
    KC_G_KC_K__gd,
    KC_G_KC_J__gf,
    KC_G_KC_H__gg,
    KC_G_KC_SLASH__gz,
    KC_G_KC_DOT__gx,
    KC_G_KC_COMMA__gc,
    KC_G_KC_M__gv,
    KC_G_KC_N__gb,
    KC_G_KC_P__gq,
    KC_G_KC_O__gw,
    KC_G_KC_I__ge,
    KC_G_KC_U__gr,
    KC_G_KC_Y__gt,
    KC_G_KC_I_KC_J__gy,
    KC_G_KC_U_KC_I__gu,
    KC_G_KC_I_KC_O__gi,
    KC_G_KC_U_KC_O__go,
    KC_G_KC_U_KC_P__gp,
    KC_G_KC_J_KC_O__gh,
    KC_G_KC_J_KC_K__gj,
    KC_G_KC_K_KC_L__gk,
    KC_G_KC_J_KC_L__gl,
    KC_G_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_G_KC_L_KC_COMMA__gn,
    KC_G_KC_M_KC_COMMA__gm,
    KC_G_KC_COMMA_KC_DOT__nodisplaychar,
    KC_G_KC_M_KC_DOT__nodisplaychar,
    KC_G_KC_M_KC_SLASH__nodisplaychar,
    KC_G_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_G_KC_DOT_KC_SLASH__nodisplaychar,
    KC_G_KC_N_KC_M__nodisplaychar,
    KC_G_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_Z_KC_SEMICOLON__za,
    KC_Z_KC_L__zs,
    KC_Z_KC_K__zd,
    KC_Z_KC_J__zf,
    KC_Z_KC_H__zg,
    KC_Z_KC_SLASH__zz,
    KC_Z_KC_DOT__zx,
    KC_Z_KC_COMMA__zc,
    KC_Z_KC_M__zv,
    KC_Z_KC_N__zb,
    KC_Z_KC_P__zq,
    KC_Z_KC_O__zw,
    KC_Z_KC_I__ze,
    KC_Z_KC_U__zr,
    KC_Z_KC_Y__zt,
    KC_Z_KC_I_KC_J__zy,
    KC_Z_KC_U_KC_I__zu,
    KC_Z_KC_I_KC_O__zi,
    KC_Z_KC_U_KC_O__zo,
    KC_Z_KC_U_KC_P__zp,
    KC_Z_KC_J_KC_O__zh,
    KC_Z_KC_J_KC_K__zj,
    KC_Z_KC_K_KC_L__zk,
    KC_Z_KC_J_KC_L__zl,
    KC_Z_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_Z_KC_L_KC_COMMA__zn,
    KC_Z_KC_M_KC_COMMA__zm,
    KC_Z_KC_COMMA_KC_DOT__nodisplaychar,
    KC_Z_KC_M_KC_DOT__nodisplaychar,
    KC_Z_KC_M_KC_SLASH__nodisplaychar,
    KC_Z_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_Z_KC_DOT_KC_SLASH__nodisplaychar,
    KC_Z_KC_N_KC_M__nodisplaychar,
    KC_Z_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_X_KC_SEMICOLON__xa,
    KC_X_KC_L__xs,
    KC_X_KC_K__xd,
    KC_X_KC_J__xf,
    KC_X_KC_H__xg,
    KC_X_KC_SLASH__xz,
    KC_X_KC_DOT__xx,
    KC_X_KC_COMMA__xc,
    KC_X_KC_M__xv,
    KC_X_KC_N__xb,
    KC_X_KC_P__xq,
    KC_X_KC_O__xw,
    KC_X_KC_I__xe,
    KC_X_KC_U__xr,
    KC_X_KC_Y__xt,
    KC_X_KC_I_KC_J__xy,
    KC_X_KC_U_KC_I__xu,
    KC_X_KC_I_KC_O__xi,
    KC_X_KC_U_KC_O__xo,
    KC_X_KC_U_KC_P__xp,
    KC_X_KC_J_KC_O__xh,
    KC_X_KC_J_KC_K__xj,
    KC_X_KC_K_KC_L__xk,
    KC_X_KC_J_KC_L__xl,
    KC_X_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_X_KC_L_KC_COMMA__xn,
    KC_X_KC_M_KC_COMMA__xm,
    KC_X_KC_COMMA_KC_DOT__nodisplaychar,
    KC_X_KC_M_KC_DOT__nodisplaychar,
    KC_X_KC_M_KC_SLASH__nodisplaychar,
    KC_X_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_X_KC_DOT_KC_SLASH__nodisplaychar,
    KC_X_KC_N_KC_M__nodisplaychar,
    KC_X_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_C_KC_SEMICOLON__ca,
    KC_C_KC_L__cs,
    KC_C_KC_K__cd,
    KC_C_KC_J__cf,
    KC_C_KC_H__cg,
    KC_C_KC_SLASH__cz,
    KC_C_KC_DOT__cx,
    KC_C_KC_COMMA__cc,
    KC_C_KC_M__cv,
    KC_C_KC_N__cb,
    KC_C_KC_P__cq,
    KC_C_KC_O__cw,
    KC_C_KC_I__ce,
    KC_C_KC_U__cr,
    KC_C_KC_Y__ct,
    KC_C_KC_I_KC_J__cy,
    KC_C_KC_U_KC_I__cu,
    KC_C_KC_I_KC_O__ci,
    KC_C_KC_U_KC_O__co,
    KC_C_KC_U_KC_P__cp,
    KC_C_KC_J_KC_O__ch,
    KC_C_KC_J_KC_K__cj,
    KC_C_KC_K_KC_L__ck,
    KC_C_KC_J_KC_L__cl,
    KC_C_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_C_KC_L_KC_COMMA__cn,
    KC_C_KC_M_KC_COMMA__cm,
    KC_C_KC_COMMA_KC_DOT__nodisplaychar,
    KC_C_KC_M_KC_DOT__nodisplaychar,
    KC_C_KC_M_KC_SLASH__nodisplaychar,
    KC_C_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_C_KC_DOT_KC_SLASH__nodisplaychar,
    KC_C_KC_N_KC_M__nodisplaychar,
    KC_C_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_V_KC_SEMICOLON__va,
    KC_V_KC_L__vs,
    KC_V_KC_K__vd,
    KC_V_KC_J__vf,
    KC_V_KC_H__vg,
    KC_V_KC_SLASH__vz,
    KC_V_KC_DOT__vx,
    KC_V_KC_COMMA__vc,
    KC_V_KC_M__vv,
    KC_V_KC_N__vb,
    KC_V_KC_P__vq,
    KC_V_KC_O__vw,
    KC_V_KC_I__ve,
    KC_V_KC_U__vr,
    KC_V_KC_Y__vt,
    KC_V_KC_I_KC_J__vy,
    KC_V_KC_U_KC_I__vu,
    KC_V_KC_I_KC_O__vi,
    KC_V_KC_U_KC_O__vo,
    KC_V_KC_U_KC_P__vp,
    KC_V_KC_J_KC_O__vh,
    KC_V_KC_J_KC_K__vj,
    KC_V_KC_K_KC_L__vk,
    KC_V_KC_J_KC_L__vl,
    KC_V_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_V_KC_L_KC_COMMA__vn,
    KC_V_KC_M_KC_COMMA__vm,
    KC_V_KC_COMMA_KC_DOT__nodisplaychar,
    KC_V_KC_M_KC_DOT__nodisplaychar,
    KC_V_KC_M_KC_SLASH__nodisplaychar,
    KC_V_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_V_KC_DOT_KC_SLASH__nodisplaychar,
    KC_V_KC_N_KC_M__nodisplaychar,
    KC_V_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_B_KC_SEMICOLON__ba,
    KC_B_KC_L__bs,
    KC_B_KC_K__bd,
    KC_B_KC_J__bf,
    KC_B_KC_H__bg,
    KC_B_KC_SLASH__bz,
    KC_B_KC_DOT__bx,
    KC_B_KC_COMMA__bc,
    KC_B_KC_M__bv,
    KC_B_KC_N__bb,
    KC_B_KC_P__bq,
    KC_B_KC_O__bw,
    KC_B_KC_I__be,
    KC_B_KC_U__br,
    KC_B_KC_Y__bt,
    KC_B_KC_I_KC_J__by,
    KC_B_KC_U_KC_I__bu,
    KC_B_KC_I_KC_O__bi,
    KC_B_KC_U_KC_O__bo,
    KC_B_KC_U_KC_P__bp,
    KC_B_KC_J_KC_O__bh,
    KC_B_KC_J_KC_K__bj,
    KC_B_KC_K_KC_L__bk,
    KC_B_KC_J_KC_L__bl,
    KC_B_KC_L_KC_SEMICOLON__nodisplaychar,
    KC_B_KC_L_KC_COMMA__bn,
    KC_B_KC_M_KC_COMMA__bm,
    KC_B_KC_COMMA_KC_DOT__nodisplaychar,
    KC_B_KC_M_KC_DOT__nodisplaychar,
    KC_B_KC_M_KC_SLASH__nodisplaychar,
    KC_B_KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_B_KC_DOT_KC_SLASH__nodisplaychar,
    KC_B_KC_N_KC_M__nodisplaychar,
    KC_B_KC_J_KC_SEMICOLON__nodisplaychar,
    KC_W_KC_F__h,
    KC_D_KC_F__j,
    KC_S_KC_D__k,
    KC_S_KC_F__l,
    KC_A_KC_F__nodisplaychar,
    KC_A_KC_S__nodisplaychar,
    KC_S_KC_C__n,
    KC_C_KC_V__m,
    KC_X_KC_C__nodisplaychar,
    KC_A_KC_T__nodisplaychar,
    KC_X_KC_V__nodisplaychar,
    KC_Z_KC_V__nodisplaychar,
    KC_Z_KC_X__nodisplaychar,
    KC_E_KC_F__y,
    KC_E_KC_R__u,
    KC_W_KC_E__i,
    KC_W_KC_R__o,
    KC_R_KC_Q__p,
    KC_I_KC_J__y,
    KC_U_KC_I__u,
    KC_I_KC_O__i,
    KC_U_KC_O__o,
    KC_U_KC_P__p,
    KC_J_KC_O__h,
    KC_J_KC_K__j,
    KC_K_KC_L__k,
    KC_J_KC_L__l,
    KC_L_KC_SEMICOLON__nodisplaychar,
    KC_L_KC_COMMA__n,
    KC_M_KC_COMMA__m,
    KC_COMMA_KC_DOT__nodisplaychar,
    KC_M_KC_DOT__nodisplaychar,
    KC_M_KC_SLASH__nodisplaychar,
    KC_SEMICOLON_KC_Y__nodisplaychar,
    KC_DOT_KC_SLASH__nodisplaychar,
    KC_N_KC_M__nodisplaychar,
    KC_J_KC_SEMICOLON__nodisplaychar,
    };

    // 定义组合键按键
    const uint16_t PROGMEM KC_W_KC_F_KC_SEMICOLON_[] = {KC_W, KC_F, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_L_[] = {KC_W, KC_F, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_K_[] = {KC_W, KC_F, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_J_[] = {KC_W, KC_F, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_H_[] = {KC_W, KC_F, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_SLASH_[] = {KC_W, KC_F, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_DOT_[] = {KC_W, KC_F, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_COMMA_[] = {KC_W, KC_F, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_M_[] = {KC_W, KC_F, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_N_[] = {KC_W, KC_F, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_P_[] = {KC_W, KC_F, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_O_[] = {KC_W, KC_F, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_I_[] = {KC_W, KC_F, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_U_[] = {KC_W, KC_F, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_Y_[] = {KC_W, KC_F, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_I_KC_J_[] = {KC_W, KC_F, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_U_KC_I_[] = {KC_W, KC_F, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_I_KC_O_[] = {KC_W, KC_F, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_U_KC_O_[] = {KC_W, KC_F, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_U_KC_P_[] = {KC_W, KC_F, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_J_KC_O_[] = {KC_W, KC_F, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_J_KC_K_[] = {KC_W, KC_F, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_K_KC_L_[] = {KC_W, KC_F, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_J_KC_L_[] = {KC_W, KC_F, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_L_KC_SEMICOLON_[] = {KC_W, KC_F, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_L_KC_COMMA_[] = {KC_W, KC_F, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_M_KC_COMMA_[] = {KC_W, KC_F, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_COMMA_KC_DOT_[] = {KC_W, KC_F, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_M_KC_DOT_[] = {KC_W, KC_F, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_M_KC_SLASH_[] = {KC_W, KC_F, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_SEMICOLON_KC_Y_[] = {KC_W, KC_F, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_DOT_KC_SLASH_[] = {KC_W, KC_F, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_N_KC_M_[] = {KC_W, KC_F, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_KC_J_KC_SEMICOLON_[] = {KC_W, KC_F, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_SEMICOLON_[] = {KC_D, KC_F, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_L_[] = {KC_D, KC_F, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_K_[] = {KC_D, KC_F, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_J_[] = {KC_D, KC_F, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_H_[] = {KC_D, KC_F, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_SLASH_[] = {KC_D, KC_F, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_DOT_[] = {KC_D, KC_F, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_COMMA_[] = {KC_D, KC_F, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_M_[] = {KC_D, KC_F, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_N_[] = {KC_D, KC_F, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_P_[] = {KC_D, KC_F, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_O_[] = {KC_D, KC_F, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_I_[] = {KC_D, KC_F, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_U_[] = {KC_D, KC_F, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_Y_[] = {KC_D, KC_F, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_I_KC_J_[] = {KC_D, KC_F, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_U_KC_I_[] = {KC_D, KC_F, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_I_KC_O_[] = {KC_D, KC_F, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_U_KC_O_[] = {KC_D, KC_F, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_U_KC_P_[] = {KC_D, KC_F, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_J_KC_O_[] = {KC_D, KC_F, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_J_KC_K_[] = {KC_D, KC_F, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_K_KC_L_[] = {KC_D, KC_F, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_J_KC_L_[] = {KC_D, KC_F, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_L_KC_SEMICOLON_[] = {KC_D, KC_F, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_L_KC_COMMA_[] = {KC_D, KC_F, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_M_KC_COMMA_[] = {KC_D, KC_F, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_COMMA_KC_DOT_[] = {KC_D, KC_F, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_M_KC_DOT_[] = {KC_D, KC_F, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_M_KC_SLASH_[] = {KC_D, KC_F, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_SEMICOLON_KC_Y_[] = {KC_D, KC_F, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_DOT_KC_SLASH_[] = {KC_D, KC_F, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_N_KC_M_[] = {KC_D, KC_F, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_KC_J_KC_SEMICOLON_[] = {KC_D, KC_F, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_SEMICOLON_[] = {KC_S, KC_D, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_L_[] = {KC_S, KC_D, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_K_[] = {KC_S, KC_D, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_J_[] = {KC_S, KC_D, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_H_[] = {KC_S, KC_D, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_SLASH_[] = {KC_S, KC_D, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_DOT_[] = {KC_S, KC_D, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_COMMA_[] = {KC_S, KC_D, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_M_[] = {KC_S, KC_D, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_N_[] = {KC_S, KC_D, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_P_[] = {KC_S, KC_D, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_O_[] = {KC_S, KC_D, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_I_[] = {KC_S, KC_D, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_U_[] = {KC_S, KC_D, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_Y_[] = {KC_S, KC_D, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_I_KC_J_[] = {KC_S, KC_D, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_U_KC_I_[] = {KC_S, KC_D, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_I_KC_O_[] = {KC_S, KC_D, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_U_KC_O_[] = {KC_S, KC_D, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_U_KC_P_[] = {KC_S, KC_D, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_J_KC_O_[] = {KC_S, KC_D, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_J_KC_K_[] = {KC_S, KC_D, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_K_KC_L_[] = {KC_S, KC_D, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_J_KC_L_[] = {KC_S, KC_D, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_L_KC_SEMICOLON_[] = {KC_S, KC_D, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_L_KC_COMMA_[] = {KC_S, KC_D, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_M_KC_COMMA_[] = {KC_S, KC_D, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_COMMA_KC_DOT_[] = {KC_S, KC_D, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_M_KC_DOT_[] = {KC_S, KC_D, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_M_KC_SLASH_[] = {KC_S, KC_D, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_SEMICOLON_KC_Y_[] = {KC_S, KC_D, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_DOT_KC_SLASH_[] = {KC_S, KC_D, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_N_KC_M_[] = {KC_S, KC_D, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_KC_J_KC_SEMICOLON_[] = {KC_S, KC_D, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_SEMICOLON_[] = {KC_S, KC_F, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_L_[] = {KC_S, KC_F, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_K_[] = {KC_S, KC_F, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_J_[] = {KC_S, KC_F, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_H_[] = {KC_S, KC_F, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_SLASH_[] = {KC_S, KC_F, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_DOT_[] = {KC_S, KC_F, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_COMMA_[] = {KC_S, KC_F, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_M_[] = {KC_S, KC_F, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_N_[] = {KC_S, KC_F, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_P_[] = {KC_S, KC_F, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_O_[] = {KC_S, KC_F, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_I_[] = {KC_S, KC_F, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_U_[] = {KC_S, KC_F, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_Y_[] = {KC_S, KC_F, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_I_KC_J_[] = {KC_S, KC_F, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_U_KC_I_[] = {KC_S, KC_F, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_I_KC_O_[] = {KC_S, KC_F, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_U_KC_O_[] = {KC_S, KC_F, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_U_KC_P_[] = {KC_S, KC_F, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_J_KC_O_[] = {KC_S, KC_F, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_J_KC_K_[] = {KC_S, KC_F, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_K_KC_L_[] = {KC_S, KC_F, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_J_KC_L_[] = {KC_S, KC_F, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_L_KC_SEMICOLON_[] = {KC_S, KC_F, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_L_KC_COMMA_[] = {KC_S, KC_F, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_M_KC_COMMA_[] = {KC_S, KC_F, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_COMMA_KC_DOT_[] = {KC_S, KC_F, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_M_KC_DOT_[] = {KC_S, KC_F, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_M_KC_SLASH_[] = {KC_S, KC_F, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_SEMICOLON_KC_Y_[] = {KC_S, KC_F, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_DOT_KC_SLASH_[] = {KC_S, KC_F, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_N_KC_M_[] = {KC_S, KC_F, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_KC_J_KC_SEMICOLON_[] = {KC_S, KC_F, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_SEMICOLON_[] = {KC_A, KC_F, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_L_[] = {KC_A, KC_F, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_K_[] = {KC_A, KC_F, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_J_[] = {KC_A, KC_F, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_H_[] = {KC_A, KC_F, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_SLASH_[] = {KC_A, KC_F, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_DOT_[] = {KC_A, KC_F, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_COMMA_[] = {KC_A, KC_F, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_M_[] = {KC_A, KC_F, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_N_[] = {KC_A, KC_F, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_P_[] = {KC_A, KC_F, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_O_[] = {KC_A, KC_F, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_I_[] = {KC_A, KC_F, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_U_[] = {KC_A, KC_F, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_Y_[] = {KC_A, KC_F, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_I_KC_J_[] = {KC_A, KC_F, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_U_KC_I_[] = {KC_A, KC_F, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_I_KC_O_[] = {KC_A, KC_F, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_U_KC_O_[] = {KC_A, KC_F, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_U_KC_P_[] = {KC_A, KC_F, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_J_KC_O_[] = {KC_A, KC_F, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_J_KC_K_[] = {KC_A, KC_F, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_K_KC_L_[] = {KC_A, KC_F, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_J_KC_L_[] = {KC_A, KC_F, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_L_KC_SEMICOLON_[] = {KC_A, KC_F, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_L_KC_COMMA_[] = {KC_A, KC_F, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_M_KC_COMMA_[] = {KC_A, KC_F, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_COMMA_KC_DOT_[] = {KC_A, KC_F, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_M_KC_DOT_[] = {KC_A, KC_F, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_M_KC_SLASH_[] = {KC_A, KC_F, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_SEMICOLON_KC_Y_[] = {KC_A, KC_F, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_DOT_KC_SLASH_[] = {KC_A, KC_F, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_N_KC_M_[] = {KC_A, KC_F, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_KC_J_KC_SEMICOLON_[] = {KC_A, KC_F, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_SEMICOLON_[] = {KC_A, KC_S, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_L_[] = {KC_A, KC_S, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_K_[] = {KC_A, KC_S, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_J_[] = {KC_A, KC_S, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_H_[] = {KC_A, KC_S, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_SLASH_[] = {KC_A, KC_S, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_DOT_[] = {KC_A, KC_S, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_COMMA_[] = {KC_A, KC_S, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_M_[] = {KC_A, KC_S, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_N_[] = {KC_A, KC_S, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_P_[] = {KC_A, KC_S, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_O_[] = {KC_A, KC_S, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_I_[] = {KC_A, KC_S, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_U_[] = {KC_A, KC_S, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_Y_[] = {KC_A, KC_S, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_I_KC_J_[] = {KC_A, KC_S, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_U_KC_I_[] = {KC_A, KC_S, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_I_KC_O_[] = {KC_A, KC_S, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_U_KC_O_[] = {KC_A, KC_S, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_U_KC_P_[] = {KC_A, KC_S, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_J_KC_O_[] = {KC_A, KC_S, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_J_KC_K_[] = {KC_A, KC_S, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_K_KC_L_[] = {KC_A, KC_S, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_J_KC_L_[] = {KC_A, KC_S, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_L_KC_SEMICOLON_[] = {KC_A, KC_S, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_L_KC_COMMA_[] = {KC_A, KC_S, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_M_KC_COMMA_[] = {KC_A, KC_S, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_COMMA_KC_DOT_[] = {KC_A, KC_S, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_M_KC_DOT_[] = {KC_A, KC_S, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_M_KC_SLASH_[] = {KC_A, KC_S, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_SEMICOLON_KC_Y_[] = {KC_A, KC_S, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_DOT_KC_SLASH_[] = {KC_A, KC_S, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_N_KC_M_[] = {KC_A, KC_S, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_KC_J_KC_SEMICOLON_[] = {KC_A, KC_S, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_SEMICOLON_[] = {KC_S, KC_C, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_L_[] = {KC_S, KC_C, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_K_[] = {KC_S, KC_C, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_J_[] = {KC_S, KC_C, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_H_[] = {KC_S, KC_C, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_SLASH_[] = {KC_S, KC_C, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_DOT_[] = {KC_S, KC_C, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_COMMA_[] = {KC_S, KC_C, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_M_[] = {KC_S, KC_C, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_N_[] = {KC_S, KC_C, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_P_[] = {KC_S, KC_C, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_O_[] = {KC_S, KC_C, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_I_[] = {KC_S, KC_C, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_U_[] = {KC_S, KC_C, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_Y_[] = {KC_S, KC_C, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_I_KC_J_[] = {KC_S, KC_C, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_U_KC_I_[] = {KC_S, KC_C, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_I_KC_O_[] = {KC_S, KC_C, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_U_KC_O_[] = {KC_S, KC_C, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_U_KC_P_[] = {KC_S, KC_C, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_J_KC_O_[] = {KC_S, KC_C, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_J_KC_K_[] = {KC_S, KC_C, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_K_KC_L_[] = {KC_S, KC_C, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_J_KC_L_[] = {KC_S, KC_C, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_L_KC_SEMICOLON_[] = {KC_S, KC_C, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_L_KC_COMMA_[] = {KC_S, KC_C, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_M_KC_COMMA_[] = {KC_S, KC_C, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_COMMA_KC_DOT_[] = {KC_S, KC_C, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_M_KC_DOT_[] = {KC_S, KC_C, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_M_KC_SLASH_[] = {KC_S, KC_C, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_SEMICOLON_KC_Y_[] = {KC_S, KC_C, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_DOT_KC_SLASH_[] = {KC_S, KC_C, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_N_KC_M_[] = {KC_S, KC_C, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_KC_J_KC_SEMICOLON_[] = {KC_S, KC_C, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_SEMICOLON_[] = {KC_C, KC_V, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_L_[] = {KC_C, KC_V, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_K_[] = {KC_C, KC_V, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_J_[] = {KC_C, KC_V, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_H_[] = {KC_C, KC_V, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_SLASH_[] = {KC_C, KC_V, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_DOT_[] = {KC_C, KC_V, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_COMMA_[] = {KC_C, KC_V, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_M_[] = {KC_C, KC_V, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_N_[] = {KC_C, KC_V, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_P_[] = {KC_C, KC_V, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_O_[] = {KC_C, KC_V, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_I_[] = {KC_C, KC_V, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_U_[] = {KC_C, KC_V, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_Y_[] = {KC_C, KC_V, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_I_KC_J_[] = {KC_C, KC_V, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_U_KC_I_[] = {KC_C, KC_V, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_I_KC_O_[] = {KC_C, KC_V, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_U_KC_O_[] = {KC_C, KC_V, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_U_KC_P_[] = {KC_C, KC_V, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_J_KC_O_[] = {KC_C, KC_V, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_J_KC_K_[] = {KC_C, KC_V, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_K_KC_L_[] = {KC_C, KC_V, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_J_KC_L_[] = {KC_C, KC_V, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_L_KC_SEMICOLON_[] = {KC_C, KC_V, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_L_KC_COMMA_[] = {KC_C, KC_V, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_M_KC_COMMA_[] = {KC_C, KC_V, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_COMMA_KC_DOT_[] = {KC_C, KC_V, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_M_KC_DOT_[] = {KC_C, KC_V, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_M_KC_SLASH_[] = {KC_C, KC_V, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_SEMICOLON_KC_Y_[] = {KC_C, KC_V, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_DOT_KC_SLASH_[] = {KC_C, KC_V, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_N_KC_M_[] = {KC_C, KC_V, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_KC_J_KC_SEMICOLON_[] = {KC_C, KC_V, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_SEMICOLON_[] = {KC_X, KC_C, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_L_[] = {KC_X, KC_C, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_K_[] = {KC_X, KC_C, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_J_[] = {KC_X, KC_C, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_H_[] = {KC_X, KC_C, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_SLASH_[] = {KC_X, KC_C, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_DOT_[] = {KC_X, KC_C, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_COMMA_[] = {KC_X, KC_C, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_M_[] = {KC_X, KC_C, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_N_[] = {KC_X, KC_C, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_P_[] = {KC_X, KC_C, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_O_[] = {KC_X, KC_C, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_I_[] = {KC_X, KC_C, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_U_[] = {KC_X, KC_C, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_Y_[] = {KC_X, KC_C, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_I_KC_J_[] = {KC_X, KC_C, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_U_KC_I_[] = {KC_X, KC_C, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_I_KC_O_[] = {KC_X, KC_C, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_U_KC_O_[] = {KC_X, KC_C, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_U_KC_P_[] = {KC_X, KC_C, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_J_KC_O_[] = {KC_X, KC_C, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_J_KC_K_[] = {KC_X, KC_C, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_K_KC_L_[] = {KC_X, KC_C, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_J_KC_L_[] = {KC_X, KC_C, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_L_KC_SEMICOLON_[] = {KC_X, KC_C, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_L_KC_COMMA_[] = {KC_X, KC_C, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_M_KC_COMMA_[] = {KC_X, KC_C, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_COMMA_KC_DOT_[] = {KC_X, KC_C, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_M_KC_DOT_[] = {KC_X, KC_C, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_M_KC_SLASH_[] = {KC_X, KC_C, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_SEMICOLON_KC_Y_[] = {KC_X, KC_C, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_DOT_KC_SLASH_[] = {KC_X, KC_C, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_N_KC_M_[] = {KC_X, KC_C, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_KC_J_KC_SEMICOLON_[] = {KC_X, KC_C, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_SEMICOLON_[] = {KC_A, KC_T, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_L_[] = {KC_A, KC_T, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_K_[] = {KC_A, KC_T, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_J_[] = {KC_A, KC_T, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_H_[] = {KC_A, KC_T, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_SLASH_[] = {KC_A, KC_T, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_DOT_[] = {KC_A, KC_T, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_COMMA_[] = {KC_A, KC_T, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_M_[] = {KC_A, KC_T, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_N_[] = {KC_A, KC_T, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_P_[] = {KC_A, KC_T, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_O_[] = {KC_A, KC_T, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_I_[] = {KC_A, KC_T, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_U_[] = {KC_A, KC_T, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_Y_[] = {KC_A, KC_T, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_I_KC_J_[] = {KC_A, KC_T, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_U_KC_I_[] = {KC_A, KC_T, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_I_KC_O_[] = {KC_A, KC_T, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_U_KC_O_[] = {KC_A, KC_T, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_U_KC_P_[] = {KC_A, KC_T, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_J_KC_O_[] = {KC_A, KC_T, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_J_KC_K_[] = {KC_A, KC_T, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_K_KC_L_[] = {KC_A, KC_T, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_J_KC_L_[] = {KC_A, KC_T, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_L_KC_SEMICOLON_[] = {KC_A, KC_T, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_L_KC_COMMA_[] = {KC_A, KC_T, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_M_KC_COMMA_[] = {KC_A, KC_T, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_COMMA_KC_DOT_[] = {KC_A, KC_T, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_M_KC_DOT_[] = {KC_A, KC_T, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_M_KC_SLASH_[] = {KC_A, KC_T, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_SEMICOLON_KC_Y_[] = {KC_A, KC_T, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_DOT_KC_SLASH_[] = {KC_A, KC_T, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_N_KC_M_[] = {KC_A, KC_T, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_KC_J_KC_SEMICOLON_[] = {KC_A, KC_T, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_SEMICOLON_[] = {KC_X, KC_V, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_L_[] = {KC_X, KC_V, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_K_[] = {KC_X, KC_V, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_J_[] = {KC_X, KC_V, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_H_[] = {KC_X, KC_V, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_SLASH_[] = {KC_X, KC_V, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_DOT_[] = {KC_X, KC_V, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_COMMA_[] = {KC_X, KC_V, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_M_[] = {KC_X, KC_V, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_N_[] = {KC_X, KC_V, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_P_[] = {KC_X, KC_V, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_O_[] = {KC_X, KC_V, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_I_[] = {KC_X, KC_V, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_U_[] = {KC_X, KC_V, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_Y_[] = {KC_X, KC_V, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_I_KC_J_[] = {KC_X, KC_V, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_U_KC_I_[] = {KC_X, KC_V, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_I_KC_O_[] = {KC_X, KC_V, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_U_KC_O_[] = {KC_X, KC_V, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_U_KC_P_[] = {KC_X, KC_V, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_J_KC_O_[] = {KC_X, KC_V, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_J_KC_K_[] = {KC_X, KC_V, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_K_KC_L_[] = {KC_X, KC_V, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_J_KC_L_[] = {KC_X, KC_V, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_L_KC_SEMICOLON_[] = {KC_X, KC_V, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_L_KC_COMMA_[] = {KC_X, KC_V, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_M_KC_COMMA_[] = {KC_X, KC_V, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_COMMA_KC_DOT_[] = {KC_X, KC_V, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_M_KC_DOT_[] = {KC_X, KC_V, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_M_KC_SLASH_[] = {KC_X, KC_V, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_SEMICOLON_KC_Y_[] = {KC_X, KC_V, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_DOT_KC_SLASH_[] = {KC_X, KC_V, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_N_KC_M_[] = {KC_X, KC_V, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_KC_J_KC_SEMICOLON_[] = {KC_X, KC_V, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_SEMICOLON_[] = {KC_Z, KC_V, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_L_[] = {KC_Z, KC_V, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_K_[] = {KC_Z, KC_V, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_J_[] = {KC_Z, KC_V, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_H_[] = {KC_Z, KC_V, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_SLASH_[] = {KC_Z, KC_V, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_DOT_[] = {KC_Z, KC_V, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_COMMA_[] = {KC_Z, KC_V, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_M_[] = {KC_Z, KC_V, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_N_[] = {KC_Z, KC_V, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_P_[] = {KC_Z, KC_V, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_O_[] = {KC_Z, KC_V, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_I_[] = {KC_Z, KC_V, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_U_[] = {KC_Z, KC_V, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_Y_[] = {KC_Z, KC_V, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_I_KC_J_[] = {KC_Z, KC_V, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_U_KC_I_[] = {KC_Z, KC_V, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_I_KC_O_[] = {KC_Z, KC_V, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_U_KC_O_[] = {KC_Z, KC_V, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_U_KC_P_[] = {KC_Z, KC_V, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_J_KC_O_[] = {KC_Z, KC_V, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_J_KC_K_[] = {KC_Z, KC_V, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_K_KC_L_[] = {KC_Z, KC_V, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_J_KC_L_[] = {KC_Z, KC_V, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_L_KC_SEMICOLON_[] = {KC_Z, KC_V, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_L_KC_COMMA_[] = {KC_Z, KC_V, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_M_KC_COMMA_[] = {KC_Z, KC_V, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_COMMA_KC_DOT_[] = {KC_Z, KC_V, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_M_KC_DOT_[] = {KC_Z, KC_V, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_M_KC_SLASH_[] = {KC_Z, KC_V, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_SEMICOLON_KC_Y_[] = {KC_Z, KC_V, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_DOT_KC_SLASH_[] = {KC_Z, KC_V, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_N_KC_M_[] = {KC_Z, KC_V, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_KC_J_KC_SEMICOLON_[] = {KC_Z, KC_V, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_SEMICOLON_[] = {KC_Z, KC_X, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_L_[] = {KC_Z, KC_X, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_K_[] = {KC_Z, KC_X, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_J_[] = {KC_Z, KC_X, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_H_[] = {KC_Z, KC_X, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_SLASH_[] = {KC_Z, KC_X, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_DOT_[] = {KC_Z, KC_X, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_COMMA_[] = {KC_Z, KC_X, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_M_[] = {KC_Z, KC_X, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_N_[] = {KC_Z, KC_X, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_P_[] = {KC_Z, KC_X, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_O_[] = {KC_Z, KC_X, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_I_[] = {KC_Z, KC_X, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_U_[] = {KC_Z, KC_X, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_Y_[] = {KC_Z, KC_X, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_I_KC_J_[] = {KC_Z, KC_X, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_U_KC_I_[] = {KC_Z, KC_X, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_I_KC_O_[] = {KC_Z, KC_X, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_U_KC_O_[] = {KC_Z, KC_X, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_U_KC_P_[] = {KC_Z, KC_X, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_J_KC_O_[] = {KC_Z, KC_X, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_J_KC_K_[] = {KC_Z, KC_X, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_K_KC_L_[] = {KC_Z, KC_X, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_J_KC_L_[] = {KC_Z, KC_X, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_L_KC_SEMICOLON_[] = {KC_Z, KC_X, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_L_KC_COMMA_[] = {KC_Z, KC_X, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_M_KC_COMMA_[] = {KC_Z, KC_X, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_COMMA_KC_DOT_[] = {KC_Z, KC_X, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_M_KC_DOT_[] = {KC_Z, KC_X, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_M_KC_SLASH_[] = {KC_Z, KC_X, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_SEMICOLON_KC_Y_[] = {KC_Z, KC_X, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_DOT_KC_SLASH_[] = {KC_Z, KC_X, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_N_KC_M_[] = {KC_Z, KC_X, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_KC_J_KC_SEMICOLON_[] = {KC_Z, KC_X, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_SEMICOLON_[] = {KC_E, KC_F, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_L_[] = {KC_E, KC_F, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_K_[] = {KC_E, KC_F, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_J_[] = {KC_E, KC_F, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_H_[] = {KC_E, KC_F, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_SLASH_[] = {KC_E, KC_F, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_DOT_[] = {KC_E, KC_F, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_COMMA_[] = {KC_E, KC_F, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_M_[] = {KC_E, KC_F, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_N_[] = {KC_E, KC_F, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_P_[] = {KC_E, KC_F, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_O_[] = {KC_E, KC_F, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_I_[] = {KC_E, KC_F, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_U_[] = {KC_E, KC_F, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_Y_[] = {KC_E, KC_F, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_I_KC_J_[] = {KC_E, KC_F, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_U_KC_I_[] = {KC_E, KC_F, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_I_KC_O_[] = {KC_E, KC_F, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_U_KC_O_[] = {KC_E, KC_F, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_U_KC_P_[] = {KC_E, KC_F, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_J_KC_O_[] = {KC_E, KC_F, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_J_KC_K_[] = {KC_E, KC_F, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_K_KC_L_[] = {KC_E, KC_F, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_J_KC_L_[] = {KC_E, KC_F, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_L_KC_SEMICOLON_[] = {KC_E, KC_F, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_L_KC_COMMA_[] = {KC_E, KC_F, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_M_KC_COMMA_[] = {KC_E, KC_F, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_COMMA_KC_DOT_[] = {KC_E, KC_F, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_M_KC_DOT_[] = {KC_E, KC_F, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_M_KC_SLASH_[] = {KC_E, KC_F, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_SEMICOLON_KC_Y_[] = {KC_E, KC_F, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_DOT_KC_SLASH_[] = {KC_E, KC_F, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_N_KC_M_[] = {KC_E, KC_F, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_KC_J_KC_SEMICOLON_[] = {KC_E, KC_F, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_SEMICOLON_[] = {KC_E, KC_R, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_L_[] = {KC_E, KC_R, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_K_[] = {KC_E, KC_R, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_J_[] = {KC_E, KC_R, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_H_[] = {KC_E, KC_R, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_SLASH_[] = {KC_E, KC_R, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_DOT_[] = {KC_E, KC_R, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_COMMA_[] = {KC_E, KC_R, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_M_[] = {KC_E, KC_R, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_N_[] = {KC_E, KC_R, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_P_[] = {KC_E, KC_R, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_O_[] = {KC_E, KC_R, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_I_[] = {KC_E, KC_R, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_U_[] = {KC_E, KC_R, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_Y_[] = {KC_E, KC_R, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_I_KC_J_[] = {KC_E, KC_R, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_U_KC_I_[] = {KC_E, KC_R, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_I_KC_O_[] = {KC_E, KC_R, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_U_KC_O_[] = {KC_E, KC_R, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_U_KC_P_[] = {KC_E, KC_R, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_J_KC_O_[] = {KC_E, KC_R, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_J_KC_K_[] = {KC_E, KC_R, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_K_KC_L_[] = {KC_E, KC_R, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_J_KC_L_[] = {KC_E, KC_R, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_L_KC_SEMICOLON_[] = {KC_E, KC_R, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_L_KC_COMMA_[] = {KC_E, KC_R, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_M_KC_COMMA_[] = {KC_E, KC_R, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_COMMA_KC_DOT_[] = {KC_E, KC_R, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_M_KC_DOT_[] = {KC_E, KC_R, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_M_KC_SLASH_[] = {KC_E, KC_R, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_SEMICOLON_KC_Y_[] = {KC_E, KC_R, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_DOT_KC_SLASH_[] = {KC_E, KC_R, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_N_KC_M_[] = {KC_E, KC_R, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_KC_J_KC_SEMICOLON_[] = {KC_E, KC_R, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_SEMICOLON_[] = {KC_W, KC_E, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_L_[] = {KC_W, KC_E, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_K_[] = {KC_W, KC_E, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_J_[] = {KC_W, KC_E, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_H_[] = {KC_W, KC_E, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_SLASH_[] = {KC_W, KC_E, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_DOT_[] = {KC_W, KC_E, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_COMMA_[] = {KC_W, KC_E, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_M_[] = {KC_W, KC_E, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_N_[] = {KC_W, KC_E, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_P_[] = {KC_W, KC_E, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_O_[] = {KC_W, KC_E, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_I_[] = {KC_W, KC_E, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_U_[] = {KC_W, KC_E, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_Y_[] = {KC_W, KC_E, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_I_KC_J_[] = {KC_W, KC_E, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_U_KC_I_[] = {KC_W, KC_E, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_I_KC_O_[] = {KC_W, KC_E, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_U_KC_O_[] = {KC_W, KC_E, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_U_KC_P_[] = {KC_W, KC_E, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_J_KC_O_[] = {KC_W, KC_E, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_J_KC_K_[] = {KC_W, KC_E, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_K_KC_L_[] = {KC_W, KC_E, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_J_KC_L_[] = {KC_W, KC_E, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_L_KC_SEMICOLON_[] = {KC_W, KC_E, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_L_KC_COMMA_[] = {KC_W, KC_E, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_M_KC_COMMA_[] = {KC_W, KC_E, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_COMMA_KC_DOT_[] = {KC_W, KC_E, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_M_KC_DOT_[] = {KC_W, KC_E, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_M_KC_SLASH_[] = {KC_W, KC_E, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_SEMICOLON_KC_Y_[] = {KC_W, KC_E, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_DOT_KC_SLASH_[] = {KC_W, KC_E, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_N_KC_M_[] = {KC_W, KC_E, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_KC_J_KC_SEMICOLON_[] = {KC_W, KC_E, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_SEMICOLON_[] = {KC_W, KC_R, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_L_[] = {KC_W, KC_R, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_K_[] = {KC_W, KC_R, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_J_[] = {KC_W, KC_R, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_H_[] = {KC_W, KC_R, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_SLASH_[] = {KC_W, KC_R, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_DOT_[] = {KC_W, KC_R, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_COMMA_[] = {KC_W, KC_R, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_M_[] = {KC_W, KC_R, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_N_[] = {KC_W, KC_R, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_P_[] = {KC_W, KC_R, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_O_[] = {KC_W, KC_R, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_I_[] = {KC_W, KC_R, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_U_[] = {KC_W, KC_R, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_Y_[] = {KC_W, KC_R, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_I_KC_J_[] = {KC_W, KC_R, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_U_KC_I_[] = {KC_W, KC_R, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_I_KC_O_[] = {KC_W, KC_R, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_U_KC_O_[] = {KC_W, KC_R, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_U_KC_P_[] = {KC_W, KC_R, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_J_KC_O_[] = {KC_W, KC_R, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_J_KC_K_[] = {KC_W, KC_R, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_K_KC_L_[] = {KC_W, KC_R, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_J_KC_L_[] = {KC_W, KC_R, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_L_KC_SEMICOLON_[] = {KC_W, KC_R, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_L_KC_COMMA_[] = {KC_W, KC_R, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_M_KC_COMMA_[] = {KC_W, KC_R, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_COMMA_KC_DOT_[] = {KC_W, KC_R, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_M_KC_DOT_[] = {KC_W, KC_R, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_M_KC_SLASH_[] = {KC_W, KC_R, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_SEMICOLON_KC_Y_[] = {KC_W, KC_R, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_DOT_KC_SLASH_[] = {KC_W, KC_R, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_N_KC_M_[] = {KC_W, KC_R, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_KC_J_KC_SEMICOLON_[] = {KC_W, KC_R, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_SEMICOLON_[] = {KC_R, KC_Q, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_L_[] = {KC_R, KC_Q, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_K_[] = {KC_R, KC_Q, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_J_[] = {KC_R, KC_Q, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_H_[] = {KC_R, KC_Q, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_SLASH_[] = {KC_R, KC_Q, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_DOT_[] = {KC_R, KC_Q, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_COMMA_[] = {KC_R, KC_Q, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_M_[] = {KC_R, KC_Q, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_N_[] = {KC_R, KC_Q, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_P_[] = {KC_R, KC_Q, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_O_[] = {KC_R, KC_Q, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_I_[] = {KC_R, KC_Q, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_U_[] = {KC_R, KC_Q, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_Y_[] = {KC_R, KC_Q, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_I_KC_J_[] = {KC_R, KC_Q, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_U_KC_I_[] = {KC_R, KC_Q, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_I_KC_O_[] = {KC_R, KC_Q, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_U_KC_O_[] = {KC_R, KC_Q, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_U_KC_P_[] = {KC_R, KC_Q, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_J_KC_O_[] = {KC_R, KC_Q, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_J_KC_K_[] = {KC_R, KC_Q, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_K_KC_L_[] = {KC_R, KC_Q, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_J_KC_L_[] = {KC_R, KC_Q, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_L_KC_SEMICOLON_[] = {KC_R, KC_Q, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_L_KC_COMMA_[] = {KC_R, KC_Q, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_M_KC_COMMA_[] = {KC_R, KC_Q, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_COMMA_KC_DOT_[] = {KC_R, KC_Q, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_M_KC_DOT_[] = {KC_R, KC_Q, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_M_KC_SLASH_[] = {KC_R, KC_Q, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_SEMICOLON_KC_Y_[] = {KC_R, KC_Q, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_DOT_KC_SLASH_[] = {KC_R, KC_Q, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_N_KC_M_[] = {KC_R, KC_Q, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_KC_J_KC_SEMICOLON_[] = {KC_R, KC_Q, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_SEMICOLON_[] = {KC_Q, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_L_[] = {KC_Q, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_K_[] = {KC_Q, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_J_[] = {KC_Q, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_H_[] = {KC_Q, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_SLASH_[] = {KC_Q, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_DOT_[] = {KC_Q, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_COMMA_[] = {KC_Q, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_M_[] = {KC_Q, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_N_[] = {KC_Q, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_P_[] = {KC_Q, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_O_[] = {KC_Q, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_I_[] = {KC_Q, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_U_[] = {KC_Q, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_Y_[] = {KC_Q, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_I_KC_J_[] = {KC_Q, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_U_KC_I_[] = {KC_Q, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_I_KC_O_[] = {KC_Q, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_U_KC_O_[] = {KC_Q, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_U_KC_P_[] = {KC_Q, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_J_KC_O_[] = {KC_Q, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_J_KC_K_[] = {KC_Q, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_K_KC_L_[] = {KC_Q, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_J_KC_L_[] = {KC_Q, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_L_KC_SEMICOLON_[] = {KC_Q, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_L_KC_COMMA_[] = {KC_Q, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_M_KC_COMMA_[] = {KC_Q, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_COMMA_KC_DOT_[] = {KC_Q, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_M_KC_DOT_[] = {KC_Q, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_M_KC_SLASH_[] = {KC_Q, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_SEMICOLON_KC_Y_[] = {KC_Q, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_DOT_KC_SLASH_[] = {KC_Q, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_N_KC_M_[] = {KC_Q, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_Q_KC_J_KC_SEMICOLON_[] = {KC_Q, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_SEMICOLON_[] = {KC_W, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_L_[] = {KC_W, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_K_[] = {KC_W, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_J_[] = {KC_W, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_H_[] = {KC_W, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_SLASH_[] = {KC_W, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_DOT_[] = {KC_W, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_COMMA_[] = {KC_W, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_M_[] = {KC_W, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_N_[] = {KC_W, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_P_[] = {KC_W, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_O_[] = {KC_W, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_I_[] = {KC_W, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_U_[] = {KC_W, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_Y_[] = {KC_W, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_I_KC_J_[] = {KC_W, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_U_KC_I_[] = {KC_W, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_I_KC_O_[] = {KC_W, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_U_KC_O_[] = {KC_W, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_U_KC_P_[] = {KC_W, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_J_KC_O_[] = {KC_W, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_J_KC_K_[] = {KC_W, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_K_KC_L_[] = {KC_W, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_J_KC_L_[] = {KC_W, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_L_KC_SEMICOLON_[] = {KC_W, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_L_KC_COMMA_[] = {KC_W, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_M_KC_COMMA_[] = {KC_W, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_COMMA_KC_DOT_[] = {KC_W, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_M_KC_DOT_[] = {KC_W, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_M_KC_SLASH_[] = {KC_W, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_SEMICOLON_KC_Y_[] = {KC_W, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_DOT_KC_SLASH_[] = {KC_W, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_N_KC_M_[] = {KC_W, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_J_KC_SEMICOLON_[] = {KC_W, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_SEMICOLON_[] = {KC_E, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_L_[] = {KC_E, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_K_[] = {KC_E, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_J_[] = {KC_E, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_H_[] = {KC_E, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_SLASH_[] = {KC_E, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_DOT_[] = {KC_E, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_COMMA_[] = {KC_E, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_M_[] = {KC_E, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_N_[] = {KC_E, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_P_[] = {KC_E, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_O_[] = {KC_E, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_I_[] = {KC_E, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_U_[] = {KC_E, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_Y_[] = {KC_E, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_I_KC_J_[] = {KC_E, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_U_KC_I_[] = {KC_E, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_I_KC_O_[] = {KC_E, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_U_KC_O_[] = {KC_E, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_U_KC_P_[] = {KC_E, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_J_KC_O_[] = {KC_E, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_J_KC_K_[] = {KC_E, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_K_KC_L_[] = {KC_E, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_J_KC_L_[] = {KC_E, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_L_KC_SEMICOLON_[] = {KC_E, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_L_KC_COMMA_[] = {KC_E, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_M_KC_COMMA_[] = {KC_E, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_COMMA_KC_DOT_[] = {KC_E, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_M_KC_DOT_[] = {KC_E, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_M_KC_SLASH_[] = {KC_E, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_SEMICOLON_KC_Y_[] = {KC_E, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_DOT_KC_SLASH_[] = {KC_E, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_N_KC_M_[] = {KC_E, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_J_KC_SEMICOLON_[] = {KC_E, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_SEMICOLON_[] = {KC_R, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_L_[] = {KC_R, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_K_[] = {KC_R, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_J_[] = {KC_R, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_H_[] = {KC_R, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_SLASH_[] = {KC_R, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_DOT_[] = {KC_R, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_COMMA_[] = {KC_R, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_M_[] = {KC_R, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_N_[] = {KC_R, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_P_[] = {KC_R, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_O_[] = {KC_R, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_I_[] = {KC_R, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_U_[] = {KC_R, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Y_[] = {KC_R, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_I_KC_J_[] = {KC_R, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_U_KC_I_[] = {KC_R, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_I_KC_O_[] = {KC_R, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_U_KC_O_[] = {KC_R, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_U_KC_P_[] = {KC_R, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_J_KC_O_[] = {KC_R, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_J_KC_K_[] = {KC_R, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_K_KC_L_[] = {KC_R, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_J_KC_L_[] = {KC_R, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_L_KC_SEMICOLON_[] = {KC_R, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_L_KC_COMMA_[] = {KC_R, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_M_KC_COMMA_[] = {KC_R, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_COMMA_KC_DOT_[] = {KC_R, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_M_KC_DOT_[] = {KC_R, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_M_KC_SLASH_[] = {KC_R, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_SEMICOLON_KC_Y_[] = {KC_R, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_DOT_KC_SLASH_[] = {KC_R, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_N_KC_M_[] = {KC_R, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_J_KC_SEMICOLON_[] = {KC_R, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_SEMICOLON_[] = {KC_T, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_L_[] = {KC_T, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_K_[] = {KC_T, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_J_[] = {KC_T, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_H_[] = {KC_T, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_SLASH_[] = {KC_T, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_DOT_[] = {KC_T, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_COMMA_[] = {KC_T, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_M_[] = {KC_T, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_N_[] = {KC_T, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_P_[] = {KC_T, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_O_[] = {KC_T, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_I_[] = {KC_T, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_U_[] = {KC_T, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_Y_[] = {KC_T, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_I_KC_J_[] = {KC_T, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_U_KC_I_[] = {KC_T, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_I_KC_O_[] = {KC_T, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_U_KC_O_[] = {KC_T, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_U_KC_P_[] = {KC_T, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_J_KC_O_[] = {KC_T, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_J_KC_K_[] = {KC_T, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_K_KC_L_[] = {KC_T, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_J_KC_L_[] = {KC_T, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_L_KC_SEMICOLON_[] = {KC_T, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_L_KC_COMMA_[] = {KC_T, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_M_KC_COMMA_[] = {KC_T, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_COMMA_KC_DOT_[] = {KC_T, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_M_KC_DOT_[] = {KC_T, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_M_KC_SLASH_[] = {KC_T, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_SEMICOLON_KC_Y_[] = {KC_T, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_DOT_KC_SLASH_[] = {KC_T, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_N_KC_M_[] = {KC_T, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_T_KC_J_KC_SEMICOLON_[] = {KC_T, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_SEMICOLON_[] = {KC_A, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_L_[] = {KC_A, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_K_[] = {KC_A, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_J_[] = {KC_A, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_H_[] = {KC_A, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_SLASH_[] = {KC_A, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_DOT_[] = {KC_A, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_COMMA_[] = {KC_A, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_M_[] = {KC_A, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_N_[] = {KC_A, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_P_[] = {KC_A, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_O_[] = {KC_A, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_I_[] = {KC_A, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_U_[] = {KC_A, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_Y_[] = {KC_A, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_I_KC_J_[] = {KC_A, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_U_KC_I_[] = {KC_A, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_I_KC_O_[] = {KC_A, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_U_KC_O_[] = {KC_A, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_U_KC_P_[] = {KC_A, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_J_KC_O_[] = {KC_A, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_J_KC_K_[] = {KC_A, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_K_KC_L_[] = {KC_A, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_J_KC_L_[] = {KC_A, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_L_KC_SEMICOLON_[] = {KC_A, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_L_KC_COMMA_[] = {KC_A, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_M_KC_COMMA_[] = {KC_A, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_COMMA_KC_DOT_[] = {KC_A, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_M_KC_DOT_[] = {KC_A, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_M_KC_SLASH_[] = {KC_A, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_SEMICOLON_KC_Y_[] = {KC_A, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_DOT_KC_SLASH_[] = {KC_A, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_N_KC_M_[] = {KC_A, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_J_KC_SEMICOLON_[] = {KC_A, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_SEMICOLON_[] = {KC_S, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_L_[] = {KC_S, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_K_[] = {KC_S, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_J_[] = {KC_S, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_H_[] = {KC_S, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_SLASH_[] = {KC_S, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_DOT_[] = {KC_S, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_COMMA_[] = {KC_S, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_M_[] = {KC_S, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_N_[] = {KC_S, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_P_[] = {KC_S, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_O_[] = {KC_S, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_I_[] = {KC_S, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_U_[] = {KC_S, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_Y_[] = {KC_S, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_I_KC_J_[] = {KC_S, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_U_KC_I_[] = {KC_S, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_I_KC_O_[] = {KC_S, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_U_KC_O_[] = {KC_S, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_U_KC_P_[] = {KC_S, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_J_KC_O_[] = {KC_S, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_J_KC_K_[] = {KC_S, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_K_KC_L_[] = {KC_S, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_J_KC_L_[] = {KC_S, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_L_KC_SEMICOLON_[] = {KC_S, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_L_KC_COMMA_[] = {KC_S, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_M_KC_COMMA_[] = {KC_S, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_COMMA_KC_DOT_[] = {KC_S, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_M_KC_DOT_[] = {KC_S, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_M_KC_SLASH_[] = {KC_S, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_SEMICOLON_KC_Y_[] = {KC_S, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_DOT_KC_SLASH_[] = {KC_S, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_N_KC_M_[] = {KC_S, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_J_KC_SEMICOLON_[] = {KC_S, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_SEMICOLON_[] = {KC_D, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_L_[] = {KC_D, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_K_[] = {KC_D, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_J_[] = {KC_D, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_H_[] = {KC_D, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_SLASH_[] = {KC_D, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_DOT_[] = {KC_D, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_COMMA_[] = {KC_D, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_M_[] = {KC_D, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_N_[] = {KC_D, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_P_[] = {KC_D, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_O_[] = {KC_D, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_I_[] = {KC_D, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_U_[] = {KC_D, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_Y_[] = {KC_D, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_I_KC_J_[] = {KC_D, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_U_KC_I_[] = {KC_D, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_I_KC_O_[] = {KC_D, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_U_KC_O_[] = {KC_D, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_U_KC_P_[] = {KC_D, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_J_KC_O_[] = {KC_D, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_J_KC_K_[] = {KC_D, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_K_KC_L_[] = {KC_D, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_J_KC_L_[] = {KC_D, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_L_KC_SEMICOLON_[] = {KC_D, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_L_KC_COMMA_[] = {KC_D, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_M_KC_COMMA_[] = {KC_D, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_COMMA_KC_DOT_[] = {KC_D, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_M_KC_DOT_[] = {KC_D, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_M_KC_SLASH_[] = {KC_D, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_SEMICOLON_KC_Y_[] = {KC_D, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_DOT_KC_SLASH_[] = {KC_D, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_N_KC_M_[] = {KC_D, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_J_KC_SEMICOLON_[] = {KC_D, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_SEMICOLON_[] = {KC_F, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_L_[] = {KC_F, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_K_[] = {KC_F, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_J_[] = {KC_F, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_H_[] = {KC_F, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_SLASH_[] = {KC_F, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_DOT_[] = {KC_F, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_COMMA_[] = {KC_F, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_M_[] = {KC_F, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_N_[] = {KC_F, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_P_[] = {KC_F, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_O_[] = {KC_F, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_I_[] = {KC_F, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_U_[] = {KC_F, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_Y_[] = {KC_F, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_I_KC_J_[] = {KC_F, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_U_KC_I_[] = {KC_F, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_I_KC_O_[] = {KC_F, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_U_KC_O_[] = {KC_F, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_U_KC_P_[] = {KC_F, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_J_KC_O_[] = {KC_F, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_J_KC_K_[] = {KC_F, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_K_KC_L_[] = {KC_F, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_J_KC_L_[] = {KC_F, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_L_KC_SEMICOLON_[] = {KC_F, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_L_KC_COMMA_[] = {KC_F, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_M_KC_COMMA_[] = {KC_F, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_COMMA_KC_DOT_[] = {KC_F, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_M_KC_DOT_[] = {KC_F, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_M_KC_SLASH_[] = {KC_F, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_SEMICOLON_KC_Y_[] = {KC_F, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_DOT_KC_SLASH_[] = {KC_F, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_N_KC_M_[] = {KC_F, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_F_KC_J_KC_SEMICOLON_[] = {KC_F, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_SEMICOLON_[] = {KC_G, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_L_[] = {KC_G, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_K_[] = {KC_G, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_J_[] = {KC_G, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_H_[] = {KC_G, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_SLASH_[] = {KC_G, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_DOT_[] = {KC_G, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_COMMA_[] = {KC_G, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_M_[] = {KC_G, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_N_[] = {KC_G, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_P_[] = {KC_G, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_O_[] = {KC_G, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_I_[] = {KC_G, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_U_[] = {KC_G, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_Y_[] = {KC_G, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_I_KC_J_[] = {KC_G, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_U_KC_I_[] = {KC_G, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_I_KC_O_[] = {KC_G, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_U_KC_O_[] = {KC_G, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_U_KC_P_[] = {KC_G, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_J_KC_O_[] = {KC_G, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_J_KC_K_[] = {KC_G, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_K_KC_L_[] = {KC_G, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_J_KC_L_[] = {KC_G, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_L_KC_SEMICOLON_[] = {KC_G, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_L_KC_COMMA_[] = {KC_G, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_M_KC_COMMA_[] = {KC_G, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_COMMA_KC_DOT_[] = {KC_G, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_M_KC_DOT_[] = {KC_G, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_M_KC_SLASH_[] = {KC_G, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_SEMICOLON_KC_Y_[] = {KC_G, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_DOT_KC_SLASH_[] = {KC_G, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_N_KC_M_[] = {KC_G, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_G_KC_J_KC_SEMICOLON_[] = {KC_G, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_SEMICOLON_[] = {KC_Z, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_L_[] = {KC_Z, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_K_[] = {KC_Z, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_J_[] = {KC_Z, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_H_[] = {KC_Z, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_SLASH_[] = {KC_Z, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_DOT_[] = {KC_Z, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_COMMA_[] = {KC_Z, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_M_[] = {KC_Z, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_N_[] = {KC_Z, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_P_[] = {KC_Z, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_O_[] = {KC_Z, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_I_[] = {KC_Z, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_U_[] = {KC_Z, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_Y_[] = {KC_Z, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_I_KC_J_[] = {KC_Z, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_U_KC_I_[] = {KC_Z, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_I_KC_O_[] = {KC_Z, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_U_KC_O_[] = {KC_Z, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_U_KC_P_[] = {KC_Z, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_J_KC_O_[] = {KC_Z, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_J_KC_K_[] = {KC_Z, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_K_KC_L_[] = {KC_Z, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_J_KC_L_[] = {KC_Z, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_L_KC_SEMICOLON_[] = {KC_Z, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_L_KC_COMMA_[] = {KC_Z, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_M_KC_COMMA_[] = {KC_Z, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_COMMA_KC_DOT_[] = {KC_Z, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_M_KC_DOT_[] = {KC_Z, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_M_KC_SLASH_[] = {KC_Z, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_SEMICOLON_KC_Y_[] = {KC_Z, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_DOT_KC_SLASH_[] = {KC_Z, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_N_KC_M_[] = {KC_Z, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_J_KC_SEMICOLON_[] = {KC_Z, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_SEMICOLON_[] = {KC_X, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_L_[] = {KC_X, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_K_[] = {KC_X, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_J_[] = {KC_X, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_H_[] = {KC_X, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_SLASH_[] = {KC_X, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_DOT_[] = {KC_X, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_COMMA_[] = {KC_X, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_M_[] = {KC_X, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_N_[] = {KC_X, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_P_[] = {KC_X, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_O_[] = {KC_X, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_I_[] = {KC_X, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_U_[] = {KC_X, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_Y_[] = {KC_X, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_I_KC_J_[] = {KC_X, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_U_KC_I_[] = {KC_X, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_I_KC_O_[] = {KC_X, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_U_KC_O_[] = {KC_X, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_U_KC_P_[] = {KC_X, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_J_KC_O_[] = {KC_X, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_J_KC_K_[] = {KC_X, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_K_KC_L_[] = {KC_X, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_J_KC_L_[] = {KC_X, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_L_KC_SEMICOLON_[] = {KC_X, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_L_KC_COMMA_[] = {KC_X, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_M_KC_COMMA_[] = {KC_X, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_COMMA_KC_DOT_[] = {KC_X, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_M_KC_DOT_[] = {KC_X, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_M_KC_SLASH_[] = {KC_X, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_SEMICOLON_KC_Y_[] = {KC_X, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_DOT_KC_SLASH_[] = {KC_X, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_N_KC_M_[] = {KC_X, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_J_KC_SEMICOLON_[] = {KC_X, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_SEMICOLON_[] = {KC_C, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_L_[] = {KC_C, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_K_[] = {KC_C, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_J_[] = {KC_C, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_H_[] = {KC_C, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_SLASH_[] = {KC_C, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_DOT_[] = {KC_C, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_COMMA_[] = {KC_C, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_M_[] = {KC_C, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_N_[] = {KC_C, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_P_[] = {KC_C, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_O_[] = {KC_C, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_I_[] = {KC_C, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_U_[] = {KC_C, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_Y_[] = {KC_C, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_I_KC_J_[] = {KC_C, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_U_KC_I_[] = {KC_C, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_I_KC_O_[] = {KC_C, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_U_KC_O_[] = {KC_C, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_U_KC_P_[] = {KC_C, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_J_KC_O_[] = {KC_C, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_J_KC_K_[] = {KC_C, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_K_KC_L_[] = {KC_C, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_J_KC_L_[] = {KC_C, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_L_KC_SEMICOLON_[] = {KC_C, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_L_KC_COMMA_[] = {KC_C, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_M_KC_COMMA_[] = {KC_C, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_COMMA_KC_DOT_[] = {KC_C, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_M_KC_DOT_[] = {KC_C, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_M_KC_SLASH_[] = {KC_C, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_SEMICOLON_KC_Y_[] = {KC_C, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_DOT_KC_SLASH_[] = {KC_C, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_N_KC_M_[] = {KC_C, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_J_KC_SEMICOLON_[] = {KC_C, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_SEMICOLON_[] = {KC_V, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_L_[] = {KC_V, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_K_[] = {KC_V, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_J_[] = {KC_V, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_H_[] = {KC_V, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_SLASH_[] = {KC_V, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_DOT_[] = {KC_V, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_COMMA_[] = {KC_V, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_M_[] = {KC_V, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_N_[] = {KC_V, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_P_[] = {KC_V, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_O_[] = {KC_V, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_I_[] = {KC_V, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_U_[] = {KC_V, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_Y_[] = {KC_V, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_I_KC_J_[] = {KC_V, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_U_KC_I_[] = {KC_V, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_I_KC_O_[] = {KC_V, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_U_KC_O_[] = {KC_V, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_U_KC_P_[] = {KC_V, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_J_KC_O_[] = {KC_V, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_J_KC_K_[] = {KC_V, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_K_KC_L_[] = {KC_V, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_J_KC_L_[] = {KC_V, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_L_KC_SEMICOLON_[] = {KC_V, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_L_KC_COMMA_[] = {KC_V, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_M_KC_COMMA_[] = {KC_V, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_COMMA_KC_DOT_[] = {KC_V, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_M_KC_DOT_[] = {KC_V, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_M_KC_SLASH_[] = {KC_V, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_SEMICOLON_KC_Y_[] = {KC_V, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_DOT_KC_SLASH_[] = {KC_V, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_N_KC_M_[] = {KC_V, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_V_KC_J_KC_SEMICOLON_[] = {KC_V, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_SEMICOLON_[] = {KC_B, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_L_[] = {KC_B, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_K_[] = {KC_B, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_J_[] = {KC_B, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_H_[] = {KC_B, KC_H, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_SLASH_[] = {KC_B, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_DOT_[] = {KC_B, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_COMMA_[] = {KC_B, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_M_[] = {KC_B, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_N_[] = {KC_B, KC_N, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_P_[] = {KC_B, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_O_[] = {KC_B, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_I_[] = {KC_B, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_U_[] = {KC_B, KC_U, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_Y_[] = {KC_B, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_I_KC_J_[] = {KC_B, KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_U_KC_I_[] = {KC_B, KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_I_KC_O_[] = {KC_B, KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_U_KC_O_[] = {KC_B, KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_U_KC_P_[] = {KC_B, KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_J_KC_O_[] = {KC_B, KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_J_KC_K_[] = {KC_B, KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_K_KC_L_[] = {KC_B, KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_J_KC_L_[] = {KC_B, KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_L_KC_SEMICOLON_[] = {KC_B, KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_L_KC_COMMA_[] = {KC_B, KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_M_KC_COMMA_[] = {KC_B, KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_COMMA_KC_DOT_[] = {KC_B, KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_M_KC_DOT_[] = {KC_B, KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_M_KC_SLASH_[] = {KC_B, KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_SEMICOLON_KC_Y_[] = {KC_B, KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_DOT_KC_SLASH_[] = {KC_B, KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_N_KC_M_[] = {KC_B, KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_B_KC_J_KC_SEMICOLON_[] = {KC_B, KC_J, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_F_[] = {KC_W, KC_F, COMBO_END};
    const uint16_t PROGMEM KC_D_KC_F_[] = {KC_D, KC_F, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_D_[] = {KC_S, KC_D, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_F_[] = {KC_S, KC_F, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_F_[] = {KC_A, KC_F, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_S_[] = {KC_A, KC_S, COMBO_END};
    const uint16_t PROGMEM KC_S_KC_C_[] = {KC_S, KC_C, COMBO_END};
    const uint16_t PROGMEM KC_C_KC_V_[] = {KC_C, KC_V, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_C_[] = {KC_X, KC_C, COMBO_END};
    const uint16_t PROGMEM KC_A_KC_T_[] = {KC_A, KC_T, COMBO_END};
    const uint16_t PROGMEM KC_X_KC_V_[] = {KC_X, KC_V, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_V_[] = {KC_Z, KC_V, COMBO_END};
    const uint16_t PROGMEM KC_Z_KC_X_[] = {KC_Z, KC_X, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_F_[] = {KC_E, KC_F, COMBO_END};
    const uint16_t PROGMEM KC_E_KC_R_[] = {KC_E, KC_R, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_E_[] = {KC_W, KC_E, COMBO_END};
    const uint16_t PROGMEM KC_W_KC_R_[] = {KC_W, KC_R, COMBO_END};
    const uint16_t PROGMEM KC_R_KC_Q_[] = {KC_R, KC_Q, COMBO_END};
    const uint16_t PROGMEM KC_I_KC_J_[] = {KC_I, KC_J, COMBO_END};
    const uint16_t PROGMEM KC_U_KC_I_[] = {KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM KC_I_KC_O_[] = {KC_I, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_U_KC_O_[] = {KC_U, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_U_KC_P_[] = {KC_U, KC_P, COMBO_END};
    const uint16_t PROGMEM KC_J_KC_O_[] = {KC_J, KC_O, COMBO_END};
    const uint16_t PROGMEM KC_J_KC_K_[] = {KC_J, KC_K, COMBO_END};
    const uint16_t PROGMEM KC_K_KC_L_[] = {KC_K, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_J_KC_L_[] = {KC_J, KC_L, COMBO_END};
    const uint16_t PROGMEM KC_L_KC_SEMICOLON_[] = {KC_L, KC_SEMICOLON, COMBO_END};
    const uint16_t PROGMEM KC_L_KC_COMMA_[] = {KC_L, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_M_KC_COMMA_[] = {KC_M, KC_COMMA, COMBO_END};
    const uint16_t PROGMEM KC_COMMA_KC_DOT_[] = {KC_COMMA, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_M_KC_DOT_[] = {KC_M, KC_DOT, COMBO_END};
    const uint16_t PROGMEM KC_M_KC_SLASH_[] = {KC_M, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_SEMICOLON_KC_Y_[] = {KC_SEMICOLON, KC_Y, COMBO_END};
    const uint16_t PROGMEM KC_DOT_KC_SLASH_[] = {KC_DOT, KC_SLASH, COMBO_END};
    const uint16_t PROGMEM KC_N_KC_M_[] = {KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM KC_J_KC_SEMICOLON_[] = {KC_J, KC_SEMICOLON, COMBO_END};

    // 关联组合键
    combo_t key_combos[] = {
        [KC_W_KC_F_KC_SEMICOLON__ha] = COMBO(KC_W_KC_F_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_F_KC_L__hs] = COMBO(KC_W_KC_F_KC_L_, KC_NO),
        [KC_W_KC_F_KC_K__hd] = COMBO(KC_W_KC_F_KC_K_, KC_NO),
        [KC_W_KC_F_KC_J__hf] = COMBO(KC_W_KC_F_KC_J_, KC_NO),
        [KC_W_KC_F_KC_H__hg] = COMBO(KC_W_KC_F_KC_H_, KC_NO),
        [KC_W_KC_F_KC_SLASH__hz] = COMBO(KC_W_KC_F_KC_SLASH_, KC_NO),
        [KC_W_KC_F_KC_DOT__hx] = COMBO(KC_W_KC_F_KC_DOT_, KC_NO),
        [KC_W_KC_F_KC_COMMA__hc] = COMBO(KC_W_KC_F_KC_COMMA_, KC_NO),
        [KC_W_KC_F_KC_M__hv] = COMBO(KC_W_KC_F_KC_M_, KC_NO),
        [KC_W_KC_F_KC_N__hb] = COMBO(KC_W_KC_F_KC_N_, KC_NO),
        [KC_W_KC_F_KC_P__hq] = COMBO(KC_W_KC_F_KC_P_, KC_NO),
        [KC_W_KC_F_KC_O__hw] = COMBO(KC_W_KC_F_KC_O_, KC_NO),
        [KC_W_KC_F_KC_I__he] = COMBO(KC_W_KC_F_KC_I_, KC_NO),
        [KC_W_KC_F_KC_U__hr] = COMBO(KC_W_KC_F_KC_U_, KC_NO),
        [KC_W_KC_F_KC_Y__ht] = COMBO(KC_W_KC_F_KC_Y_, KC_NO),
        [KC_W_KC_F_KC_I_KC_J__hy] = COMBO(KC_W_KC_F_KC_I_KC_J_, KC_NO),
        [KC_W_KC_F_KC_U_KC_I__hu] = COMBO(KC_W_KC_F_KC_U_KC_I_, KC_NO),
        [KC_W_KC_F_KC_I_KC_O__hi] = COMBO(KC_W_KC_F_KC_I_KC_O_, KC_NO),
        [KC_W_KC_F_KC_U_KC_O__ho] = COMBO(KC_W_KC_F_KC_U_KC_O_, KC_NO),
        [KC_W_KC_F_KC_U_KC_P__hp] = COMBO(KC_W_KC_F_KC_U_KC_P_, KC_NO),
        [KC_W_KC_F_KC_J_KC_O__hh] = COMBO(KC_W_KC_F_KC_J_KC_O_, KC_NO),
        [KC_W_KC_F_KC_J_KC_K__hj] = COMBO(KC_W_KC_F_KC_J_KC_K_, KC_NO),
        [KC_W_KC_F_KC_K_KC_L__hk] = COMBO(KC_W_KC_F_KC_K_KC_L_, KC_NO),
        [KC_W_KC_F_KC_J_KC_L__hl] = COMBO(KC_W_KC_F_KC_J_KC_L_, KC_NO),
        [KC_W_KC_F_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_W_KC_F_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_F_KC_L_KC_COMMA__hn] = COMBO(KC_W_KC_F_KC_L_KC_COMMA_, KC_NO),
        [KC_W_KC_F_KC_M_KC_COMMA__hm] = COMBO(KC_W_KC_F_KC_M_KC_COMMA_, KC_NO),
        [KC_W_KC_F_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_W_KC_F_KC_COMMA_KC_DOT_, KC_NO),
        [KC_W_KC_F_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_W_KC_F_KC_M_KC_DOT_, KC_NO),
        [KC_W_KC_F_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_W_KC_F_KC_M_KC_SLASH_, KC_NO),
        [KC_W_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_W_KC_F_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_W_KC_F_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_W_KC_F_KC_DOT_KC_SLASH_, KC_NO),
        [KC_W_KC_F_KC_N_KC_M__nodisplaychar] = COMBO(KC_W_KC_F_KC_N_KC_M_, KC_NO),
        [KC_W_KC_F_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_W_KC_F_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_D_KC_F_KC_SEMICOLON__ja] = COMBO(KC_D_KC_F_KC_SEMICOLON_, KC_NO),
        [KC_D_KC_F_KC_L__js] = COMBO(KC_D_KC_F_KC_L_, KC_NO),
        [KC_D_KC_F_KC_K__jd] = COMBO(KC_D_KC_F_KC_K_, KC_NO),
        [KC_D_KC_F_KC_J__jf] = COMBO(KC_D_KC_F_KC_J_, KC_NO),
        [KC_D_KC_F_KC_H__jg] = COMBO(KC_D_KC_F_KC_H_, KC_NO),
        [KC_D_KC_F_KC_SLASH__jz] = COMBO(KC_D_KC_F_KC_SLASH_, KC_NO),
        [KC_D_KC_F_KC_DOT__jx] = COMBO(KC_D_KC_F_KC_DOT_, KC_NO),
        [KC_D_KC_F_KC_COMMA__jc] = COMBO(KC_D_KC_F_KC_COMMA_, KC_NO),
        [KC_D_KC_F_KC_M__jv] = COMBO(KC_D_KC_F_KC_M_, KC_NO),
        [KC_D_KC_F_KC_N__jb] = COMBO(KC_D_KC_F_KC_N_, KC_NO),
        [KC_D_KC_F_KC_P__jq] = COMBO(KC_D_KC_F_KC_P_, KC_NO),
        [KC_D_KC_F_KC_O__jw] = COMBO(KC_D_KC_F_KC_O_, KC_NO),
        [KC_D_KC_F_KC_I__je] = COMBO(KC_D_KC_F_KC_I_, KC_NO),
        [KC_D_KC_F_KC_U__jr] = COMBO(KC_D_KC_F_KC_U_, KC_NO),
        [KC_D_KC_F_KC_Y__jt] = COMBO(KC_D_KC_F_KC_Y_, KC_NO),
        [KC_D_KC_F_KC_I_KC_J__jy] = COMBO(KC_D_KC_F_KC_I_KC_J_, KC_NO),
        [KC_D_KC_F_KC_U_KC_I__ju] = COMBO(KC_D_KC_F_KC_U_KC_I_, KC_NO),
        [KC_D_KC_F_KC_I_KC_O__ji] = COMBO(KC_D_KC_F_KC_I_KC_O_, KC_NO),
        [KC_D_KC_F_KC_U_KC_O__jo] = COMBO(KC_D_KC_F_KC_U_KC_O_, KC_NO),
        [KC_D_KC_F_KC_U_KC_P__jp] = COMBO(KC_D_KC_F_KC_U_KC_P_, KC_NO),
        [KC_D_KC_F_KC_J_KC_O__jh] = COMBO(KC_D_KC_F_KC_J_KC_O_, KC_NO),
        [KC_D_KC_F_KC_J_KC_K__jj] = COMBO(KC_D_KC_F_KC_J_KC_K_, KC_NO),
        [KC_D_KC_F_KC_K_KC_L__jk] = COMBO(KC_D_KC_F_KC_K_KC_L_, KC_NO),
        [KC_D_KC_F_KC_J_KC_L__jl] = COMBO(KC_D_KC_F_KC_J_KC_L_, KC_NO),
        [KC_D_KC_F_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_D_KC_F_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_D_KC_F_KC_L_KC_COMMA__jn] = COMBO(KC_D_KC_F_KC_L_KC_COMMA_, KC_NO),
        [KC_D_KC_F_KC_M_KC_COMMA__jm] = COMBO(KC_D_KC_F_KC_M_KC_COMMA_, KC_NO),
        [KC_D_KC_F_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_D_KC_F_KC_COMMA_KC_DOT_, KC_NO),
        [KC_D_KC_F_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_D_KC_F_KC_M_KC_DOT_, KC_NO),
        [KC_D_KC_F_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_D_KC_F_KC_M_KC_SLASH_, KC_NO),
        [KC_D_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_D_KC_F_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_D_KC_F_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_D_KC_F_KC_DOT_KC_SLASH_, KC_NO),
        [KC_D_KC_F_KC_N_KC_M__nodisplaychar] = COMBO(KC_D_KC_F_KC_N_KC_M_, KC_NO),
        [KC_D_KC_F_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_D_KC_F_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_D_KC_SEMICOLON__ka] = COMBO(KC_S_KC_D_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_D_KC_L__ks] = COMBO(KC_S_KC_D_KC_L_, KC_NO),
        [KC_S_KC_D_KC_K__kd] = COMBO(KC_S_KC_D_KC_K_, KC_NO),
        [KC_S_KC_D_KC_J__kf] = COMBO(KC_S_KC_D_KC_J_, KC_NO),
        [KC_S_KC_D_KC_H__kg] = COMBO(KC_S_KC_D_KC_H_, KC_NO),
        [KC_S_KC_D_KC_SLASH__kz] = COMBO(KC_S_KC_D_KC_SLASH_, KC_NO),
        [KC_S_KC_D_KC_DOT__kx] = COMBO(KC_S_KC_D_KC_DOT_, KC_NO),
        [KC_S_KC_D_KC_COMMA__kc] = COMBO(KC_S_KC_D_KC_COMMA_, KC_NO),
        [KC_S_KC_D_KC_M__kv] = COMBO(KC_S_KC_D_KC_M_, KC_NO),
        [KC_S_KC_D_KC_N__kb] = COMBO(KC_S_KC_D_KC_N_, KC_NO),
        [KC_S_KC_D_KC_P__kq] = COMBO(KC_S_KC_D_KC_P_, KC_NO),
        [KC_S_KC_D_KC_O__kw] = COMBO(KC_S_KC_D_KC_O_, KC_NO),
        [KC_S_KC_D_KC_I__ke] = COMBO(KC_S_KC_D_KC_I_, KC_NO),
        [KC_S_KC_D_KC_U__kr] = COMBO(KC_S_KC_D_KC_U_, KC_NO),
        [KC_S_KC_D_KC_Y__kt] = COMBO(KC_S_KC_D_KC_Y_, KC_NO),
        [KC_S_KC_D_KC_I_KC_J__ky] = COMBO(KC_S_KC_D_KC_I_KC_J_, KC_NO),
        [KC_S_KC_D_KC_U_KC_I__ku] = COMBO(KC_S_KC_D_KC_U_KC_I_, KC_NO),
        [KC_S_KC_D_KC_I_KC_O__ki] = COMBO(KC_S_KC_D_KC_I_KC_O_, KC_NO),
        [KC_S_KC_D_KC_U_KC_O__ko] = COMBO(KC_S_KC_D_KC_U_KC_O_, KC_NO),
        [KC_S_KC_D_KC_U_KC_P__kp] = COMBO(KC_S_KC_D_KC_U_KC_P_, KC_NO),
        [KC_S_KC_D_KC_J_KC_O__kh] = COMBO(KC_S_KC_D_KC_J_KC_O_, KC_NO),
        [KC_S_KC_D_KC_J_KC_K__kj] = COMBO(KC_S_KC_D_KC_J_KC_K_, KC_NO),
        [KC_S_KC_D_KC_K_KC_L__kk] = COMBO(KC_S_KC_D_KC_K_KC_L_, KC_NO),
        [KC_S_KC_D_KC_J_KC_L__kl] = COMBO(KC_S_KC_D_KC_J_KC_L_, KC_NO),
        [KC_S_KC_D_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_S_KC_D_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_D_KC_L_KC_COMMA__kn] = COMBO(KC_S_KC_D_KC_L_KC_COMMA_, KC_NO),
        [KC_S_KC_D_KC_M_KC_COMMA__km] = COMBO(KC_S_KC_D_KC_M_KC_COMMA_, KC_NO),
        [KC_S_KC_D_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_S_KC_D_KC_COMMA_KC_DOT_, KC_NO),
        [KC_S_KC_D_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_S_KC_D_KC_M_KC_DOT_, KC_NO),
        [KC_S_KC_D_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_S_KC_D_KC_M_KC_SLASH_, KC_NO),
        [KC_S_KC_D_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_S_KC_D_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_S_KC_D_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_S_KC_D_KC_DOT_KC_SLASH_, KC_NO),
        [KC_S_KC_D_KC_N_KC_M__nodisplaychar] = COMBO(KC_S_KC_D_KC_N_KC_M_, KC_NO),
        [KC_S_KC_D_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_S_KC_D_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_F_KC_SEMICOLON__la] = COMBO(KC_S_KC_F_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_F_KC_L__ls] = COMBO(KC_S_KC_F_KC_L_, KC_NO),
        [KC_S_KC_F_KC_K__ld] = COMBO(KC_S_KC_F_KC_K_, KC_NO),
        [KC_S_KC_F_KC_J__lf] = COMBO(KC_S_KC_F_KC_J_, KC_NO),
        [KC_S_KC_F_KC_H__lg] = COMBO(KC_S_KC_F_KC_H_, KC_NO),
        [KC_S_KC_F_KC_SLASH__lz] = COMBO(KC_S_KC_F_KC_SLASH_, KC_NO),
        [KC_S_KC_F_KC_DOT__lx] = COMBO(KC_S_KC_F_KC_DOT_, KC_NO),
        [KC_S_KC_F_KC_COMMA__lc] = COMBO(KC_S_KC_F_KC_COMMA_, KC_NO),
        [KC_S_KC_F_KC_M__lv] = COMBO(KC_S_KC_F_KC_M_, KC_NO),
        [KC_S_KC_F_KC_N__lb] = COMBO(KC_S_KC_F_KC_N_, KC_NO),
        [KC_S_KC_F_KC_P__lq] = COMBO(KC_S_KC_F_KC_P_, KC_NO),
        [KC_S_KC_F_KC_O__lw] = COMBO(KC_S_KC_F_KC_O_, KC_NO),
        [KC_S_KC_F_KC_I__le] = COMBO(KC_S_KC_F_KC_I_, KC_NO),
        [KC_S_KC_F_KC_U__lr] = COMBO(KC_S_KC_F_KC_U_, KC_NO),
        [KC_S_KC_F_KC_Y__lt] = COMBO(KC_S_KC_F_KC_Y_, KC_NO),
        [KC_S_KC_F_KC_I_KC_J__ly] = COMBO(KC_S_KC_F_KC_I_KC_J_, KC_NO),
        [KC_S_KC_F_KC_U_KC_I__lu] = COMBO(KC_S_KC_F_KC_U_KC_I_, KC_NO),
        [KC_S_KC_F_KC_I_KC_O__li] = COMBO(KC_S_KC_F_KC_I_KC_O_, KC_NO),
        [KC_S_KC_F_KC_U_KC_O__lo] = COMBO(KC_S_KC_F_KC_U_KC_O_, KC_NO),
        [KC_S_KC_F_KC_U_KC_P__lp] = COMBO(KC_S_KC_F_KC_U_KC_P_, KC_NO),
        [KC_S_KC_F_KC_J_KC_O__lh] = COMBO(KC_S_KC_F_KC_J_KC_O_, KC_NO),
        [KC_S_KC_F_KC_J_KC_K__lj] = COMBO(KC_S_KC_F_KC_J_KC_K_, KC_NO),
        [KC_S_KC_F_KC_K_KC_L__lk] = COMBO(KC_S_KC_F_KC_K_KC_L_, KC_NO),
        [KC_S_KC_F_KC_J_KC_L__ll] = COMBO(KC_S_KC_F_KC_J_KC_L_, KC_NO),
        [KC_S_KC_F_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_S_KC_F_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_F_KC_L_KC_COMMA__ln] = COMBO(KC_S_KC_F_KC_L_KC_COMMA_, KC_NO),
        [KC_S_KC_F_KC_M_KC_COMMA__lm] = COMBO(KC_S_KC_F_KC_M_KC_COMMA_, KC_NO),
        [KC_S_KC_F_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_S_KC_F_KC_COMMA_KC_DOT_, KC_NO),
        [KC_S_KC_F_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_S_KC_F_KC_M_KC_DOT_, KC_NO),
        [KC_S_KC_F_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_S_KC_F_KC_M_KC_SLASH_, KC_NO),
        [KC_S_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_S_KC_F_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_S_KC_F_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_S_KC_F_KC_DOT_KC_SLASH_, KC_NO),
        [KC_S_KC_F_KC_N_KC_M__nodisplaychar] = COMBO(KC_S_KC_F_KC_N_KC_M_, KC_NO),
        [KC_S_KC_F_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_S_KC_F_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_F_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_F_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_F_KC_L__nodisplaychar] = COMBO(KC_A_KC_F_KC_L_, KC_NO),
        [KC_A_KC_F_KC_K__nodisplaychar] = COMBO(KC_A_KC_F_KC_K_, KC_NO),
        [KC_A_KC_F_KC_J__nodisplaychar] = COMBO(KC_A_KC_F_KC_J_, KC_NO),
        [KC_A_KC_F_KC_H__nodisplaychar] = COMBO(KC_A_KC_F_KC_H_, KC_NO),
        [KC_A_KC_F_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_F_KC_SLASH_, KC_NO),
        [KC_A_KC_F_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_F_KC_DOT_, KC_NO),
        [KC_A_KC_F_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_F_KC_COMMA_, KC_NO),
        [KC_A_KC_F_KC_M__nodisplaychar] = COMBO(KC_A_KC_F_KC_M_, KC_NO),
        [KC_A_KC_F_KC_N__nodisplaychar] = COMBO(KC_A_KC_F_KC_N_, KC_NO),
        [KC_A_KC_F_KC_P__nodisplaychar] = COMBO(KC_A_KC_F_KC_P_, KC_NO),
        [KC_A_KC_F_KC_O__nodisplaychar] = COMBO(KC_A_KC_F_KC_O_, KC_NO),
        [KC_A_KC_F_KC_I__nodisplaychar] = COMBO(KC_A_KC_F_KC_I_, KC_NO),
        [KC_A_KC_F_KC_U__nodisplaychar] = COMBO(KC_A_KC_F_KC_U_, KC_NO),
        [KC_A_KC_F_KC_Y__nodisplaychar] = COMBO(KC_A_KC_F_KC_Y_, KC_NO),
        [KC_A_KC_F_KC_I_KC_J__nodisplaychar] = COMBO(KC_A_KC_F_KC_I_KC_J_, KC_NO),
        [KC_A_KC_F_KC_U_KC_I__nodisplaychar] = COMBO(KC_A_KC_F_KC_U_KC_I_, KC_NO),
        [KC_A_KC_F_KC_I_KC_O__nodisplaychar] = COMBO(KC_A_KC_F_KC_I_KC_O_, KC_NO),
        [KC_A_KC_F_KC_U_KC_O__nodisplaychar] = COMBO(KC_A_KC_F_KC_U_KC_O_, KC_NO),
        [KC_A_KC_F_KC_U_KC_P__nodisplaychar] = COMBO(KC_A_KC_F_KC_U_KC_P_, KC_NO),
        [KC_A_KC_F_KC_J_KC_O__nodisplaychar] = COMBO(KC_A_KC_F_KC_J_KC_O_, KC_NO),
        [KC_A_KC_F_KC_J_KC_K__nodisplaychar] = COMBO(KC_A_KC_F_KC_J_KC_K_, KC_NO),
        [KC_A_KC_F_KC_K_KC_L__nodisplaychar] = COMBO(KC_A_KC_F_KC_K_KC_L_, KC_NO),
        [KC_A_KC_F_KC_J_KC_L__nodisplaychar] = COMBO(KC_A_KC_F_KC_J_KC_L_, KC_NO),
        [KC_A_KC_F_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_F_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_F_KC_L_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_F_KC_L_KC_COMMA_, KC_NO),
        [KC_A_KC_F_KC_M_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_F_KC_M_KC_COMMA_, KC_NO),
        [KC_A_KC_F_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_F_KC_COMMA_KC_DOT_, KC_NO),
        [KC_A_KC_F_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_F_KC_M_KC_DOT_, KC_NO),
        [KC_A_KC_F_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_F_KC_M_KC_SLASH_, KC_NO),
        [KC_A_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_A_KC_F_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_A_KC_F_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_F_KC_DOT_KC_SLASH_, KC_NO),
        [KC_A_KC_F_KC_N_KC_M__nodisplaychar] = COMBO(KC_A_KC_F_KC_N_KC_M_, KC_NO),
        [KC_A_KC_F_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_F_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_S_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_S_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_S_KC_L__nodisplaychar] = COMBO(KC_A_KC_S_KC_L_, KC_NO),
        [KC_A_KC_S_KC_K__nodisplaychar] = COMBO(KC_A_KC_S_KC_K_, KC_NO),
        [KC_A_KC_S_KC_J__nodisplaychar] = COMBO(KC_A_KC_S_KC_J_, KC_NO),
        [KC_A_KC_S_KC_H__nodisplaychar] = COMBO(KC_A_KC_S_KC_H_, KC_NO),
        [KC_A_KC_S_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_S_KC_SLASH_, KC_NO),
        [KC_A_KC_S_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_S_KC_DOT_, KC_NO),
        [KC_A_KC_S_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_S_KC_COMMA_, KC_NO),
        [KC_A_KC_S_KC_M__nodisplaychar] = COMBO(KC_A_KC_S_KC_M_, KC_NO),
        [KC_A_KC_S_KC_N__nodisplaychar] = COMBO(KC_A_KC_S_KC_N_, KC_NO),
        [KC_A_KC_S_KC_P__nodisplaychar] = COMBO(KC_A_KC_S_KC_P_, KC_NO),
        [KC_A_KC_S_KC_O__nodisplaychar] = COMBO(KC_A_KC_S_KC_O_, KC_NO),
        [KC_A_KC_S_KC_I__nodisplaychar] = COMBO(KC_A_KC_S_KC_I_, KC_NO),
        [KC_A_KC_S_KC_U__nodisplaychar] = COMBO(KC_A_KC_S_KC_U_, KC_NO),
        [KC_A_KC_S_KC_Y__nodisplaychar] = COMBO(KC_A_KC_S_KC_Y_, KC_NO),
        [KC_A_KC_S_KC_I_KC_J__nodisplaychar] = COMBO(KC_A_KC_S_KC_I_KC_J_, KC_NO),
        [KC_A_KC_S_KC_U_KC_I__nodisplaychar] = COMBO(KC_A_KC_S_KC_U_KC_I_, KC_NO),
        [KC_A_KC_S_KC_I_KC_O__nodisplaychar] = COMBO(KC_A_KC_S_KC_I_KC_O_, KC_NO),
        [KC_A_KC_S_KC_U_KC_O__nodisplaychar] = COMBO(KC_A_KC_S_KC_U_KC_O_, KC_NO),
        [KC_A_KC_S_KC_U_KC_P__nodisplaychar] = COMBO(KC_A_KC_S_KC_U_KC_P_, KC_NO),
        [KC_A_KC_S_KC_J_KC_O__nodisplaychar] = COMBO(KC_A_KC_S_KC_J_KC_O_, KC_NO),
        [KC_A_KC_S_KC_J_KC_K__nodisplaychar] = COMBO(KC_A_KC_S_KC_J_KC_K_, KC_NO),
        [KC_A_KC_S_KC_K_KC_L__nodisplaychar] = COMBO(KC_A_KC_S_KC_K_KC_L_, KC_NO),
        [KC_A_KC_S_KC_J_KC_L__nodisplaychar] = COMBO(KC_A_KC_S_KC_J_KC_L_, KC_NO),
        [KC_A_KC_S_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_S_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_S_KC_L_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_S_KC_L_KC_COMMA_, KC_NO),
        [KC_A_KC_S_KC_M_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_S_KC_M_KC_COMMA_, KC_NO),
        [KC_A_KC_S_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_S_KC_COMMA_KC_DOT_, KC_NO),
        [KC_A_KC_S_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_S_KC_M_KC_DOT_, KC_NO),
        [KC_A_KC_S_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_S_KC_M_KC_SLASH_, KC_NO),
        [KC_A_KC_S_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_A_KC_S_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_A_KC_S_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_S_KC_DOT_KC_SLASH_, KC_NO),
        [KC_A_KC_S_KC_N_KC_M__nodisplaychar] = COMBO(KC_A_KC_S_KC_N_KC_M_, KC_NO),
        [KC_A_KC_S_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_S_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_C_KC_SEMICOLON__na] = COMBO(KC_S_KC_C_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_C_KC_L__ns] = COMBO(KC_S_KC_C_KC_L_, KC_NO),
        [KC_S_KC_C_KC_K__nd] = COMBO(KC_S_KC_C_KC_K_, KC_NO),
        [KC_S_KC_C_KC_J__nf] = COMBO(KC_S_KC_C_KC_J_, KC_NO),
        [KC_S_KC_C_KC_H__ng] = COMBO(KC_S_KC_C_KC_H_, KC_NO),
        [KC_S_KC_C_KC_SLASH__nz] = COMBO(KC_S_KC_C_KC_SLASH_, KC_NO),
        [KC_S_KC_C_KC_DOT__nx] = COMBO(KC_S_KC_C_KC_DOT_, KC_NO),
        [KC_S_KC_C_KC_COMMA__nc] = COMBO(KC_S_KC_C_KC_COMMA_, KC_NO),
        [KC_S_KC_C_KC_M__nv] = COMBO(KC_S_KC_C_KC_M_, KC_NO),
        [KC_S_KC_C_KC_N__nb] = COMBO(KC_S_KC_C_KC_N_, KC_NO),
        [KC_S_KC_C_KC_P__nq] = COMBO(KC_S_KC_C_KC_P_, KC_NO),
        [KC_S_KC_C_KC_O__nw] = COMBO(KC_S_KC_C_KC_O_, KC_NO),
        [KC_S_KC_C_KC_I__ne] = COMBO(KC_S_KC_C_KC_I_, KC_NO),
        [KC_S_KC_C_KC_U__nr] = COMBO(KC_S_KC_C_KC_U_, KC_NO),
        [KC_S_KC_C_KC_Y__nt] = COMBO(KC_S_KC_C_KC_Y_, KC_NO),
        [KC_S_KC_C_KC_I_KC_J__ny] = COMBO(KC_S_KC_C_KC_I_KC_J_, KC_NO),
        [KC_S_KC_C_KC_U_KC_I__nu] = COMBO(KC_S_KC_C_KC_U_KC_I_, KC_NO),
        [KC_S_KC_C_KC_I_KC_O__ni] = COMBO(KC_S_KC_C_KC_I_KC_O_, KC_NO),
        [KC_S_KC_C_KC_U_KC_O__no] = COMBO(KC_S_KC_C_KC_U_KC_O_, KC_NO),
        [KC_S_KC_C_KC_U_KC_P__np] = COMBO(KC_S_KC_C_KC_U_KC_P_, KC_NO),
        [KC_S_KC_C_KC_J_KC_O__nh] = COMBO(KC_S_KC_C_KC_J_KC_O_, KC_NO),
        [KC_S_KC_C_KC_J_KC_K__nj] = COMBO(KC_S_KC_C_KC_J_KC_K_, KC_NO),
        [KC_S_KC_C_KC_K_KC_L__nk] = COMBO(KC_S_KC_C_KC_K_KC_L_, KC_NO),
        [KC_S_KC_C_KC_J_KC_L__nl] = COMBO(KC_S_KC_C_KC_J_KC_L_, KC_NO),
        [KC_S_KC_C_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_S_KC_C_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_C_KC_L_KC_COMMA__nn] = COMBO(KC_S_KC_C_KC_L_KC_COMMA_, KC_NO),
        [KC_S_KC_C_KC_M_KC_COMMA__nm] = COMBO(KC_S_KC_C_KC_M_KC_COMMA_, KC_NO),
        [KC_S_KC_C_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_S_KC_C_KC_COMMA_KC_DOT_, KC_NO),
        [KC_S_KC_C_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_S_KC_C_KC_M_KC_DOT_, KC_NO),
        [KC_S_KC_C_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_S_KC_C_KC_M_KC_SLASH_, KC_NO),
        [KC_S_KC_C_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_S_KC_C_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_S_KC_C_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_S_KC_C_KC_DOT_KC_SLASH_, KC_NO),
        [KC_S_KC_C_KC_N_KC_M__nodisplaychar] = COMBO(KC_S_KC_C_KC_N_KC_M_, KC_NO),
        [KC_S_KC_C_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_S_KC_C_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_C_KC_V_KC_SEMICOLON__ma] = COMBO(KC_C_KC_V_KC_SEMICOLON_, KC_NO),
        [KC_C_KC_V_KC_L__ms] = COMBO(KC_C_KC_V_KC_L_, KC_NO),
        [KC_C_KC_V_KC_K__md] = COMBO(KC_C_KC_V_KC_K_, KC_NO),
        [KC_C_KC_V_KC_J__mf] = COMBO(KC_C_KC_V_KC_J_, KC_NO),
        [KC_C_KC_V_KC_H__mg] = COMBO(KC_C_KC_V_KC_H_, KC_NO),
        [KC_C_KC_V_KC_SLASH__mz] = COMBO(KC_C_KC_V_KC_SLASH_, KC_NO),
        [KC_C_KC_V_KC_DOT__mx] = COMBO(KC_C_KC_V_KC_DOT_, KC_NO),
        [KC_C_KC_V_KC_COMMA__mc] = COMBO(KC_C_KC_V_KC_COMMA_, KC_NO),
        [KC_C_KC_V_KC_M__mv] = COMBO(KC_C_KC_V_KC_M_, KC_NO),
        [KC_C_KC_V_KC_N__mb] = COMBO(KC_C_KC_V_KC_N_, KC_NO),
        [KC_C_KC_V_KC_P__mq] = COMBO(KC_C_KC_V_KC_P_, KC_NO),
        [KC_C_KC_V_KC_O__mw] = COMBO(KC_C_KC_V_KC_O_, KC_NO),
        [KC_C_KC_V_KC_I__me] = COMBO(KC_C_KC_V_KC_I_, KC_NO),
        [KC_C_KC_V_KC_U__mr] = COMBO(KC_C_KC_V_KC_U_, KC_NO),
        [KC_C_KC_V_KC_Y__mt] = COMBO(KC_C_KC_V_KC_Y_, KC_NO),
        [KC_C_KC_V_KC_I_KC_J__my] = COMBO(KC_C_KC_V_KC_I_KC_J_, KC_NO),
        [KC_C_KC_V_KC_U_KC_I__mu] = COMBO(KC_C_KC_V_KC_U_KC_I_, KC_NO),
        [KC_C_KC_V_KC_I_KC_O__mi] = COMBO(KC_C_KC_V_KC_I_KC_O_, KC_NO),
        [KC_C_KC_V_KC_U_KC_O__mo] = COMBO(KC_C_KC_V_KC_U_KC_O_, KC_NO),
        [KC_C_KC_V_KC_U_KC_P__mp] = COMBO(KC_C_KC_V_KC_U_KC_P_, KC_NO),
        [KC_C_KC_V_KC_J_KC_O__mh] = COMBO(KC_C_KC_V_KC_J_KC_O_, KC_NO),
        [KC_C_KC_V_KC_J_KC_K__mj] = COMBO(KC_C_KC_V_KC_J_KC_K_, KC_NO),
        [KC_C_KC_V_KC_K_KC_L__mk] = COMBO(KC_C_KC_V_KC_K_KC_L_, KC_NO),
        [KC_C_KC_V_KC_J_KC_L__ml] = COMBO(KC_C_KC_V_KC_J_KC_L_, KC_NO),
        [KC_C_KC_V_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_C_KC_V_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_C_KC_V_KC_L_KC_COMMA__mn] = COMBO(KC_C_KC_V_KC_L_KC_COMMA_, KC_NO),
        [KC_C_KC_V_KC_M_KC_COMMA__mm] = COMBO(KC_C_KC_V_KC_M_KC_COMMA_, KC_NO),
        [KC_C_KC_V_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_C_KC_V_KC_COMMA_KC_DOT_, KC_NO),
        [KC_C_KC_V_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_C_KC_V_KC_M_KC_DOT_, KC_NO),
        [KC_C_KC_V_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_C_KC_V_KC_M_KC_SLASH_, KC_NO),
        [KC_C_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_C_KC_V_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_C_KC_V_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_C_KC_V_KC_DOT_KC_SLASH_, KC_NO),
        [KC_C_KC_V_KC_N_KC_M__nodisplaychar] = COMBO(KC_C_KC_V_KC_N_KC_M_, KC_NO),
        [KC_C_KC_V_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_C_KC_V_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_C_KC_SEMICOLON__nodisplaychar] = COMBO(KC_X_KC_C_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_C_KC_L__nodisplaychar] = COMBO(KC_X_KC_C_KC_L_, KC_NO),
        [KC_X_KC_C_KC_K__nodisplaychar] = COMBO(KC_X_KC_C_KC_K_, KC_NO),
        [KC_X_KC_C_KC_J__nodisplaychar] = COMBO(KC_X_KC_C_KC_J_, KC_NO),
        [KC_X_KC_C_KC_H__nodisplaychar] = COMBO(KC_X_KC_C_KC_H_, KC_NO),
        [KC_X_KC_C_KC_SLASH__nodisplaychar] = COMBO(KC_X_KC_C_KC_SLASH_, KC_NO),
        [KC_X_KC_C_KC_DOT__nodisplaychar] = COMBO(KC_X_KC_C_KC_DOT_, KC_NO),
        [KC_X_KC_C_KC_COMMA__nodisplaychar] = COMBO(KC_X_KC_C_KC_COMMA_, KC_NO),
        [KC_X_KC_C_KC_M__nodisplaychar] = COMBO(KC_X_KC_C_KC_M_, KC_NO),
        [KC_X_KC_C_KC_N__nodisplaychar] = COMBO(KC_X_KC_C_KC_N_, KC_NO),
        [KC_X_KC_C_KC_P__nodisplaychar] = COMBO(KC_X_KC_C_KC_P_, KC_NO),
        [KC_X_KC_C_KC_O__nodisplaychar] = COMBO(KC_X_KC_C_KC_O_, KC_NO),
        [KC_X_KC_C_KC_I__nodisplaychar] = COMBO(KC_X_KC_C_KC_I_, KC_NO),
        [KC_X_KC_C_KC_U__nodisplaychar] = COMBO(KC_X_KC_C_KC_U_, KC_NO),
        [KC_X_KC_C_KC_Y__nodisplaychar] = COMBO(KC_X_KC_C_KC_Y_, KC_NO),
        [KC_X_KC_C_KC_I_KC_J__nodisplaychar] = COMBO(KC_X_KC_C_KC_I_KC_J_, KC_NO),
        [KC_X_KC_C_KC_U_KC_I__nodisplaychar] = COMBO(KC_X_KC_C_KC_U_KC_I_, KC_NO),
        [KC_X_KC_C_KC_I_KC_O__nodisplaychar] = COMBO(KC_X_KC_C_KC_I_KC_O_, KC_NO),
        [KC_X_KC_C_KC_U_KC_O__nodisplaychar] = COMBO(KC_X_KC_C_KC_U_KC_O_, KC_NO),
        [KC_X_KC_C_KC_U_KC_P__nodisplaychar] = COMBO(KC_X_KC_C_KC_U_KC_P_, KC_NO),
        [KC_X_KC_C_KC_J_KC_O__nodisplaychar] = COMBO(KC_X_KC_C_KC_J_KC_O_, KC_NO),
        [KC_X_KC_C_KC_J_KC_K__nodisplaychar] = COMBO(KC_X_KC_C_KC_J_KC_K_, KC_NO),
        [KC_X_KC_C_KC_K_KC_L__nodisplaychar] = COMBO(KC_X_KC_C_KC_K_KC_L_, KC_NO),
        [KC_X_KC_C_KC_J_KC_L__nodisplaychar] = COMBO(KC_X_KC_C_KC_J_KC_L_, KC_NO),
        [KC_X_KC_C_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_X_KC_C_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_C_KC_L_KC_COMMA__nodisplaychar] = COMBO(KC_X_KC_C_KC_L_KC_COMMA_, KC_NO),
        [KC_X_KC_C_KC_M_KC_COMMA__nodisplaychar] = COMBO(KC_X_KC_C_KC_M_KC_COMMA_, KC_NO),
        [KC_X_KC_C_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_X_KC_C_KC_COMMA_KC_DOT_, KC_NO),
        [KC_X_KC_C_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_X_KC_C_KC_M_KC_DOT_, KC_NO),
        [KC_X_KC_C_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_X_KC_C_KC_M_KC_SLASH_, KC_NO),
        [KC_X_KC_C_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_X_KC_C_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_X_KC_C_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_X_KC_C_KC_DOT_KC_SLASH_, KC_NO),
        [KC_X_KC_C_KC_N_KC_M__nodisplaychar] = COMBO(KC_X_KC_C_KC_N_KC_M_, KC_NO),
        [KC_X_KC_C_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_X_KC_C_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_T_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_T_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_T_KC_L__nodisplaychar] = COMBO(KC_A_KC_T_KC_L_, KC_NO),
        [KC_A_KC_T_KC_K__nodisplaychar] = COMBO(KC_A_KC_T_KC_K_, KC_NO),
        [KC_A_KC_T_KC_J__nodisplaychar] = COMBO(KC_A_KC_T_KC_J_, KC_NO),
        [KC_A_KC_T_KC_H__nodisplaychar] = COMBO(KC_A_KC_T_KC_H_, KC_NO),
        [KC_A_KC_T_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_T_KC_SLASH_, KC_NO),
        [KC_A_KC_T_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_T_KC_DOT_, KC_NO),
        [KC_A_KC_T_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_T_KC_COMMA_, KC_NO),
        [KC_A_KC_T_KC_M__nodisplaychar] = COMBO(KC_A_KC_T_KC_M_, KC_NO),
        [KC_A_KC_T_KC_N__nodisplaychar] = COMBO(KC_A_KC_T_KC_N_, KC_NO),
        [KC_A_KC_T_KC_P__nodisplaychar] = COMBO(KC_A_KC_T_KC_P_, KC_NO),
        [KC_A_KC_T_KC_O__nodisplaychar] = COMBO(KC_A_KC_T_KC_O_, KC_NO),
        [KC_A_KC_T_KC_I__nodisplaychar] = COMBO(KC_A_KC_T_KC_I_, KC_NO),
        [KC_A_KC_T_KC_U__nodisplaychar] = COMBO(KC_A_KC_T_KC_U_, KC_NO),
        [KC_A_KC_T_KC_Y__nodisplaychar] = COMBO(KC_A_KC_T_KC_Y_, KC_NO),
        [KC_A_KC_T_KC_I_KC_J__nodisplaychar] = COMBO(KC_A_KC_T_KC_I_KC_J_, KC_NO),
        [KC_A_KC_T_KC_U_KC_I__nodisplaychar] = COMBO(KC_A_KC_T_KC_U_KC_I_, KC_NO),
        [KC_A_KC_T_KC_I_KC_O__nodisplaychar] = COMBO(KC_A_KC_T_KC_I_KC_O_, KC_NO),
        [KC_A_KC_T_KC_U_KC_O__nodisplaychar] = COMBO(KC_A_KC_T_KC_U_KC_O_, KC_NO),
        [KC_A_KC_T_KC_U_KC_P__nodisplaychar] = COMBO(KC_A_KC_T_KC_U_KC_P_, KC_NO),
        [KC_A_KC_T_KC_J_KC_O__nodisplaychar] = COMBO(KC_A_KC_T_KC_J_KC_O_, KC_NO),
        [KC_A_KC_T_KC_J_KC_K__nodisplaychar] = COMBO(KC_A_KC_T_KC_J_KC_K_, KC_NO),
        [KC_A_KC_T_KC_K_KC_L__nodisplaychar] = COMBO(KC_A_KC_T_KC_K_KC_L_, KC_NO),
        [KC_A_KC_T_KC_J_KC_L__nodisplaychar] = COMBO(KC_A_KC_T_KC_J_KC_L_, KC_NO),
        [KC_A_KC_T_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_T_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_T_KC_L_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_T_KC_L_KC_COMMA_, KC_NO),
        [KC_A_KC_T_KC_M_KC_COMMA__nodisplaychar] = COMBO(KC_A_KC_T_KC_M_KC_COMMA_, KC_NO),
        [KC_A_KC_T_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_T_KC_COMMA_KC_DOT_, KC_NO),
        [KC_A_KC_T_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_T_KC_M_KC_DOT_, KC_NO),
        [KC_A_KC_T_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_T_KC_M_KC_SLASH_, KC_NO),
        [KC_A_KC_T_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_A_KC_T_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_A_KC_T_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_T_KC_DOT_KC_SLASH_, KC_NO),
        [KC_A_KC_T_KC_N_KC_M__nodisplaychar] = COMBO(KC_A_KC_T_KC_N_KC_M_, KC_NO),
        [KC_A_KC_T_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_T_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_V_KC_SEMICOLON__nodisplaychar] = COMBO(KC_X_KC_V_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_V_KC_L__nodisplaychar] = COMBO(KC_X_KC_V_KC_L_, KC_NO),
        [KC_X_KC_V_KC_K__nodisplaychar] = COMBO(KC_X_KC_V_KC_K_, KC_NO),
        [KC_X_KC_V_KC_J__nodisplaychar] = COMBO(KC_X_KC_V_KC_J_, KC_NO),
        [KC_X_KC_V_KC_H__nodisplaychar] = COMBO(KC_X_KC_V_KC_H_, KC_NO),
        [KC_X_KC_V_KC_SLASH__nodisplaychar] = COMBO(KC_X_KC_V_KC_SLASH_, KC_NO),
        [KC_X_KC_V_KC_DOT__nodisplaychar] = COMBO(KC_X_KC_V_KC_DOT_, KC_NO),
        [KC_X_KC_V_KC_COMMA__nodisplaychar] = COMBO(KC_X_KC_V_KC_COMMA_, KC_NO),
        [KC_X_KC_V_KC_M__nodisplaychar] = COMBO(KC_X_KC_V_KC_M_, KC_NO),
        [KC_X_KC_V_KC_N__nodisplaychar] = COMBO(KC_X_KC_V_KC_N_, KC_NO),
        [KC_X_KC_V_KC_P__nodisplaychar] = COMBO(KC_X_KC_V_KC_P_, KC_NO),
        [KC_X_KC_V_KC_O__nodisplaychar] = COMBO(KC_X_KC_V_KC_O_, KC_NO),
        [KC_X_KC_V_KC_I__nodisplaychar] = COMBO(KC_X_KC_V_KC_I_, KC_NO),
        [KC_X_KC_V_KC_U__nodisplaychar] = COMBO(KC_X_KC_V_KC_U_, KC_NO),
        [KC_X_KC_V_KC_Y__nodisplaychar] = COMBO(KC_X_KC_V_KC_Y_, KC_NO),
        [KC_X_KC_V_KC_I_KC_J__nodisplaychar] = COMBO(KC_X_KC_V_KC_I_KC_J_, KC_NO),
        [KC_X_KC_V_KC_U_KC_I__nodisplaychar] = COMBO(KC_X_KC_V_KC_U_KC_I_, KC_NO),
        [KC_X_KC_V_KC_I_KC_O__nodisplaychar] = COMBO(KC_X_KC_V_KC_I_KC_O_, KC_NO),
        [KC_X_KC_V_KC_U_KC_O__nodisplaychar] = COMBO(KC_X_KC_V_KC_U_KC_O_, KC_NO),
        [KC_X_KC_V_KC_U_KC_P__nodisplaychar] = COMBO(KC_X_KC_V_KC_U_KC_P_, KC_NO),
        [KC_X_KC_V_KC_J_KC_O__nodisplaychar] = COMBO(KC_X_KC_V_KC_J_KC_O_, KC_NO),
        [KC_X_KC_V_KC_J_KC_K__nodisplaychar] = COMBO(KC_X_KC_V_KC_J_KC_K_, KC_NO),
        [KC_X_KC_V_KC_K_KC_L__nodisplaychar] = COMBO(KC_X_KC_V_KC_K_KC_L_, KC_NO),
        [KC_X_KC_V_KC_J_KC_L__nodisplaychar] = COMBO(KC_X_KC_V_KC_J_KC_L_, KC_NO),
        [KC_X_KC_V_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_X_KC_V_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_V_KC_L_KC_COMMA__nodisplaychar] = COMBO(KC_X_KC_V_KC_L_KC_COMMA_, KC_NO),
        [KC_X_KC_V_KC_M_KC_COMMA__nodisplaychar] = COMBO(KC_X_KC_V_KC_M_KC_COMMA_, KC_NO),
        [KC_X_KC_V_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_X_KC_V_KC_COMMA_KC_DOT_, KC_NO),
        [KC_X_KC_V_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_X_KC_V_KC_M_KC_DOT_, KC_NO),
        [KC_X_KC_V_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_X_KC_V_KC_M_KC_SLASH_, KC_NO),
        [KC_X_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_X_KC_V_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_X_KC_V_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_X_KC_V_KC_DOT_KC_SLASH_, KC_NO),
        [KC_X_KC_V_KC_N_KC_M__nodisplaychar] = COMBO(KC_X_KC_V_KC_N_KC_M_, KC_NO),
        [KC_X_KC_V_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_X_KC_V_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_V_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Z_KC_V_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_V_KC_L__nodisplaychar] = COMBO(KC_Z_KC_V_KC_L_, KC_NO),
        [KC_Z_KC_V_KC_K__nodisplaychar] = COMBO(KC_Z_KC_V_KC_K_, KC_NO),
        [KC_Z_KC_V_KC_J__nodisplaychar] = COMBO(KC_Z_KC_V_KC_J_, KC_NO),
        [KC_Z_KC_V_KC_H__nodisplaychar] = COMBO(KC_Z_KC_V_KC_H_, KC_NO),
        [KC_Z_KC_V_KC_SLASH__nodisplaychar] = COMBO(KC_Z_KC_V_KC_SLASH_, KC_NO),
        [KC_Z_KC_V_KC_DOT__nodisplaychar] = COMBO(KC_Z_KC_V_KC_DOT_, KC_NO),
        [KC_Z_KC_V_KC_COMMA__nodisplaychar] = COMBO(KC_Z_KC_V_KC_COMMA_, KC_NO),
        [KC_Z_KC_V_KC_M__nodisplaychar] = COMBO(KC_Z_KC_V_KC_M_, KC_NO),
        [KC_Z_KC_V_KC_N__nodisplaychar] = COMBO(KC_Z_KC_V_KC_N_, KC_NO),
        [KC_Z_KC_V_KC_P__nodisplaychar] = COMBO(KC_Z_KC_V_KC_P_, KC_NO),
        [KC_Z_KC_V_KC_O__nodisplaychar] = COMBO(KC_Z_KC_V_KC_O_, KC_NO),
        [KC_Z_KC_V_KC_I__nodisplaychar] = COMBO(KC_Z_KC_V_KC_I_, KC_NO),
        [KC_Z_KC_V_KC_U__nodisplaychar] = COMBO(KC_Z_KC_V_KC_U_, KC_NO),
        [KC_Z_KC_V_KC_Y__nodisplaychar] = COMBO(KC_Z_KC_V_KC_Y_, KC_NO),
        [KC_Z_KC_V_KC_I_KC_J__nodisplaychar] = COMBO(KC_Z_KC_V_KC_I_KC_J_, KC_NO),
        [KC_Z_KC_V_KC_U_KC_I__nodisplaychar] = COMBO(KC_Z_KC_V_KC_U_KC_I_, KC_NO),
        [KC_Z_KC_V_KC_I_KC_O__nodisplaychar] = COMBO(KC_Z_KC_V_KC_I_KC_O_, KC_NO),
        [KC_Z_KC_V_KC_U_KC_O__nodisplaychar] = COMBO(KC_Z_KC_V_KC_U_KC_O_, KC_NO),
        [KC_Z_KC_V_KC_U_KC_P__nodisplaychar] = COMBO(KC_Z_KC_V_KC_U_KC_P_, KC_NO),
        [KC_Z_KC_V_KC_J_KC_O__nodisplaychar] = COMBO(KC_Z_KC_V_KC_J_KC_O_, KC_NO),
        [KC_Z_KC_V_KC_J_KC_K__nodisplaychar] = COMBO(KC_Z_KC_V_KC_J_KC_K_, KC_NO),
        [KC_Z_KC_V_KC_K_KC_L__nodisplaychar] = COMBO(KC_Z_KC_V_KC_K_KC_L_, KC_NO),
        [KC_Z_KC_V_KC_J_KC_L__nodisplaychar] = COMBO(KC_Z_KC_V_KC_J_KC_L_, KC_NO),
        [KC_Z_KC_V_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Z_KC_V_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_V_KC_L_KC_COMMA__nodisplaychar] = COMBO(KC_Z_KC_V_KC_L_KC_COMMA_, KC_NO),
        [KC_Z_KC_V_KC_M_KC_COMMA__nodisplaychar] = COMBO(KC_Z_KC_V_KC_M_KC_COMMA_, KC_NO),
        [KC_Z_KC_V_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_Z_KC_V_KC_COMMA_KC_DOT_, KC_NO),
        [KC_Z_KC_V_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_Z_KC_V_KC_M_KC_DOT_, KC_NO),
        [KC_Z_KC_V_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_Z_KC_V_KC_M_KC_SLASH_, KC_NO),
        [KC_Z_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_Z_KC_V_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_Z_KC_V_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_Z_KC_V_KC_DOT_KC_SLASH_, KC_NO),
        [KC_Z_KC_V_KC_N_KC_M__nodisplaychar] = COMBO(KC_Z_KC_V_KC_N_KC_M_, KC_NO),
        [KC_Z_KC_V_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Z_KC_V_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_X_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Z_KC_X_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_X_KC_L__nodisplaychar] = COMBO(KC_Z_KC_X_KC_L_, KC_NO),
        [KC_Z_KC_X_KC_K__nodisplaychar] = COMBO(KC_Z_KC_X_KC_K_, KC_NO),
        [KC_Z_KC_X_KC_J__nodisplaychar] = COMBO(KC_Z_KC_X_KC_J_, KC_NO),
        [KC_Z_KC_X_KC_H__nodisplaychar] = COMBO(KC_Z_KC_X_KC_H_, KC_NO),
        [KC_Z_KC_X_KC_SLASH__nodisplaychar] = COMBO(KC_Z_KC_X_KC_SLASH_, KC_NO),
        [KC_Z_KC_X_KC_DOT__nodisplaychar] = COMBO(KC_Z_KC_X_KC_DOT_, KC_NO),
        [KC_Z_KC_X_KC_COMMA__nodisplaychar] = COMBO(KC_Z_KC_X_KC_COMMA_, KC_NO),
        [KC_Z_KC_X_KC_M__nodisplaychar] = COMBO(KC_Z_KC_X_KC_M_, KC_NO),
        [KC_Z_KC_X_KC_N__nodisplaychar] = COMBO(KC_Z_KC_X_KC_N_, KC_NO),
        [KC_Z_KC_X_KC_P__nodisplaychar] = COMBO(KC_Z_KC_X_KC_P_, KC_NO),
        [KC_Z_KC_X_KC_O__nodisplaychar] = COMBO(KC_Z_KC_X_KC_O_, KC_NO),
        [KC_Z_KC_X_KC_I__nodisplaychar] = COMBO(KC_Z_KC_X_KC_I_, KC_NO),
        [KC_Z_KC_X_KC_U__nodisplaychar] = COMBO(KC_Z_KC_X_KC_U_, KC_NO),
        [KC_Z_KC_X_KC_Y__nodisplaychar] = COMBO(KC_Z_KC_X_KC_Y_, KC_NO),
        [KC_Z_KC_X_KC_I_KC_J__nodisplaychar] = COMBO(KC_Z_KC_X_KC_I_KC_J_, KC_NO),
        [KC_Z_KC_X_KC_U_KC_I__nodisplaychar] = COMBO(KC_Z_KC_X_KC_U_KC_I_, KC_NO),
        [KC_Z_KC_X_KC_I_KC_O__nodisplaychar] = COMBO(KC_Z_KC_X_KC_I_KC_O_, KC_NO),
        [KC_Z_KC_X_KC_U_KC_O__nodisplaychar] = COMBO(KC_Z_KC_X_KC_U_KC_O_, KC_NO),
        [KC_Z_KC_X_KC_U_KC_P__nodisplaychar] = COMBO(KC_Z_KC_X_KC_U_KC_P_, KC_NO),
        [KC_Z_KC_X_KC_J_KC_O__nodisplaychar] = COMBO(KC_Z_KC_X_KC_J_KC_O_, KC_NO),
        [KC_Z_KC_X_KC_J_KC_K__nodisplaychar] = COMBO(KC_Z_KC_X_KC_J_KC_K_, KC_NO),
        [KC_Z_KC_X_KC_K_KC_L__nodisplaychar] = COMBO(KC_Z_KC_X_KC_K_KC_L_, KC_NO),
        [KC_Z_KC_X_KC_J_KC_L__nodisplaychar] = COMBO(KC_Z_KC_X_KC_J_KC_L_, KC_NO),
        [KC_Z_KC_X_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Z_KC_X_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_X_KC_L_KC_COMMA__nodisplaychar] = COMBO(KC_Z_KC_X_KC_L_KC_COMMA_, KC_NO),
        [KC_Z_KC_X_KC_M_KC_COMMA__nodisplaychar] = COMBO(KC_Z_KC_X_KC_M_KC_COMMA_, KC_NO),
        [KC_Z_KC_X_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_Z_KC_X_KC_COMMA_KC_DOT_, KC_NO),
        [KC_Z_KC_X_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_Z_KC_X_KC_M_KC_DOT_, KC_NO),
        [KC_Z_KC_X_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_Z_KC_X_KC_M_KC_SLASH_, KC_NO),
        [KC_Z_KC_X_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_Z_KC_X_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_Z_KC_X_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_Z_KC_X_KC_DOT_KC_SLASH_, KC_NO),
        [KC_Z_KC_X_KC_N_KC_M__nodisplaychar] = COMBO(KC_Z_KC_X_KC_N_KC_M_, KC_NO),
        [KC_Z_KC_X_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Z_KC_X_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_F_KC_SEMICOLON__ya] = COMBO(KC_E_KC_F_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_F_KC_L__ys] = COMBO(KC_E_KC_F_KC_L_, KC_NO),
        [KC_E_KC_F_KC_K__yd] = COMBO(KC_E_KC_F_KC_K_, KC_NO),
        [KC_E_KC_F_KC_J__yf] = COMBO(KC_E_KC_F_KC_J_, KC_NO),
        [KC_E_KC_F_KC_H__yg] = COMBO(KC_E_KC_F_KC_H_, KC_NO),
        [KC_E_KC_F_KC_SLASH__yz] = COMBO(KC_E_KC_F_KC_SLASH_, KC_NO),
        [KC_E_KC_F_KC_DOT__yx] = COMBO(KC_E_KC_F_KC_DOT_, KC_NO),
        [KC_E_KC_F_KC_COMMA__yc] = COMBO(KC_E_KC_F_KC_COMMA_, KC_NO),
        [KC_E_KC_F_KC_M__yv] = COMBO(KC_E_KC_F_KC_M_, KC_NO),
        [KC_E_KC_F_KC_N__yb] = COMBO(KC_E_KC_F_KC_N_, KC_NO),
        [KC_E_KC_F_KC_P__yq] = COMBO(KC_E_KC_F_KC_P_, KC_NO),
        [KC_E_KC_F_KC_O__yw] = COMBO(KC_E_KC_F_KC_O_, KC_NO),
        [KC_E_KC_F_KC_I__ye] = COMBO(KC_E_KC_F_KC_I_, KC_NO),
        [KC_E_KC_F_KC_U__yr] = COMBO(KC_E_KC_F_KC_U_, KC_NO),
        [KC_E_KC_F_KC_Y__yt] = COMBO(KC_E_KC_F_KC_Y_, KC_NO),
        [KC_E_KC_F_KC_I_KC_J__yy] = COMBO(KC_E_KC_F_KC_I_KC_J_, KC_NO),
        [KC_E_KC_F_KC_U_KC_I__yu] = COMBO(KC_E_KC_F_KC_U_KC_I_, KC_NO),
        [KC_E_KC_F_KC_I_KC_O__yi] = COMBO(KC_E_KC_F_KC_I_KC_O_, KC_NO),
        [KC_E_KC_F_KC_U_KC_O__yo] = COMBO(KC_E_KC_F_KC_U_KC_O_, KC_NO),
        [KC_E_KC_F_KC_U_KC_P__yp] = COMBO(KC_E_KC_F_KC_U_KC_P_, KC_NO),
        [KC_E_KC_F_KC_J_KC_O__yh] = COMBO(KC_E_KC_F_KC_J_KC_O_, KC_NO),
        [KC_E_KC_F_KC_J_KC_K__yj] = COMBO(KC_E_KC_F_KC_J_KC_K_, KC_NO),
        [KC_E_KC_F_KC_K_KC_L__yk] = COMBO(KC_E_KC_F_KC_K_KC_L_, KC_NO),
        [KC_E_KC_F_KC_J_KC_L__yl] = COMBO(KC_E_KC_F_KC_J_KC_L_, KC_NO),
        [KC_E_KC_F_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_E_KC_F_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_F_KC_L_KC_COMMA__yn] = COMBO(KC_E_KC_F_KC_L_KC_COMMA_, KC_NO),
        [KC_E_KC_F_KC_M_KC_COMMA__ym] = COMBO(KC_E_KC_F_KC_M_KC_COMMA_, KC_NO),
        [KC_E_KC_F_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_E_KC_F_KC_COMMA_KC_DOT_, KC_NO),
        [KC_E_KC_F_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_E_KC_F_KC_M_KC_DOT_, KC_NO),
        [KC_E_KC_F_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_E_KC_F_KC_M_KC_SLASH_, KC_NO),
        [KC_E_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_E_KC_F_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_E_KC_F_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_E_KC_F_KC_DOT_KC_SLASH_, KC_NO),
        [KC_E_KC_F_KC_N_KC_M__nodisplaychar] = COMBO(KC_E_KC_F_KC_N_KC_M_, KC_NO),
        [KC_E_KC_F_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_E_KC_F_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_R_KC_SEMICOLON__ua] = COMBO(KC_E_KC_R_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_R_KC_L__us] = COMBO(KC_E_KC_R_KC_L_, KC_NO),
        [KC_E_KC_R_KC_K__ud] = COMBO(KC_E_KC_R_KC_K_, KC_NO),
        [KC_E_KC_R_KC_J__uf] = COMBO(KC_E_KC_R_KC_J_, KC_NO),
        [KC_E_KC_R_KC_H__ug] = COMBO(KC_E_KC_R_KC_H_, KC_NO),
        [KC_E_KC_R_KC_SLASH__uz] = COMBO(KC_E_KC_R_KC_SLASH_, KC_NO),
        [KC_E_KC_R_KC_DOT__ux] = COMBO(KC_E_KC_R_KC_DOT_, KC_NO),
        [KC_E_KC_R_KC_COMMA__uc] = COMBO(KC_E_KC_R_KC_COMMA_, KC_NO),
        [KC_E_KC_R_KC_M__uv] = COMBO(KC_E_KC_R_KC_M_, KC_NO),
        [KC_E_KC_R_KC_N__ub] = COMBO(KC_E_KC_R_KC_N_, KC_NO),
        [KC_E_KC_R_KC_P__uq] = COMBO(KC_E_KC_R_KC_P_, KC_NO),
        [KC_E_KC_R_KC_O__uw] = COMBO(KC_E_KC_R_KC_O_, KC_NO),
        [KC_E_KC_R_KC_I__ue] = COMBO(KC_E_KC_R_KC_I_, KC_NO),
        [KC_E_KC_R_KC_U__ur] = COMBO(KC_E_KC_R_KC_U_, KC_NO),
        [KC_E_KC_R_KC_Y__ut] = COMBO(KC_E_KC_R_KC_Y_, KC_NO),
        [KC_E_KC_R_KC_I_KC_J__uy] = COMBO(KC_E_KC_R_KC_I_KC_J_, KC_NO),
        [KC_E_KC_R_KC_U_KC_I__uu] = COMBO(KC_E_KC_R_KC_U_KC_I_, KC_NO),
        [KC_E_KC_R_KC_I_KC_O__ui] = COMBO(KC_E_KC_R_KC_I_KC_O_, KC_NO),
        [KC_E_KC_R_KC_U_KC_O__uo] = COMBO(KC_E_KC_R_KC_U_KC_O_, KC_NO),
        [KC_E_KC_R_KC_U_KC_P__up] = COMBO(KC_E_KC_R_KC_U_KC_P_, KC_NO),
        [KC_E_KC_R_KC_J_KC_O__uh] = COMBO(KC_E_KC_R_KC_J_KC_O_, KC_NO),
        [KC_E_KC_R_KC_J_KC_K__uj] = COMBO(KC_E_KC_R_KC_J_KC_K_, KC_NO),
        [KC_E_KC_R_KC_K_KC_L__uk] = COMBO(KC_E_KC_R_KC_K_KC_L_, KC_NO),
        [KC_E_KC_R_KC_J_KC_L__ul] = COMBO(KC_E_KC_R_KC_J_KC_L_, KC_NO),
        [KC_E_KC_R_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_E_KC_R_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_R_KC_L_KC_COMMA__un] = COMBO(KC_E_KC_R_KC_L_KC_COMMA_, KC_NO),
        [KC_E_KC_R_KC_M_KC_COMMA__um] = COMBO(KC_E_KC_R_KC_M_KC_COMMA_, KC_NO),
        [KC_E_KC_R_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_E_KC_R_KC_COMMA_KC_DOT_, KC_NO),
        [KC_E_KC_R_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_E_KC_R_KC_M_KC_DOT_, KC_NO),
        [KC_E_KC_R_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_E_KC_R_KC_M_KC_SLASH_, KC_NO),
        [KC_E_KC_R_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_E_KC_R_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_E_KC_R_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_E_KC_R_KC_DOT_KC_SLASH_, KC_NO),
        [KC_E_KC_R_KC_N_KC_M__nodisplaychar] = COMBO(KC_E_KC_R_KC_N_KC_M_, KC_NO),
        [KC_E_KC_R_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_E_KC_R_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_E_KC_SEMICOLON__ia] = COMBO(KC_W_KC_E_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_E_KC_L__is] = COMBO(KC_W_KC_E_KC_L_, KC_NO),
        [KC_W_KC_E_KC_K__id] = COMBO(KC_W_KC_E_KC_K_, KC_NO),
        [KC_W_KC_E_KC_J__if] = COMBO(KC_W_KC_E_KC_J_, KC_NO),
        [KC_W_KC_E_KC_H__ig] = COMBO(KC_W_KC_E_KC_H_, KC_NO),
        [KC_W_KC_E_KC_SLASH__iz] = COMBO(KC_W_KC_E_KC_SLASH_, KC_NO),
        [KC_W_KC_E_KC_DOT__ix] = COMBO(KC_W_KC_E_KC_DOT_, KC_NO),
        [KC_W_KC_E_KC_COMMA__ic] = COMBO(KC_W_KC_E_KC_COMMA_, KC_NO),
        [KC_W_KC_E_KC_M__iv] = COMBO(KC_W_KC_E_KC_M_, KC_NO),
        [KC_W_KC_E_KC_N__ib] = COMBO(KC_W_KC_E_KC_N_, KC_NO),
        [KC_W_KC_E_KC_P__iq] = COMBO(KC_W_KC_E_KC_P_, KC_NO),
        [KC_W_KC_E_KC_O__iw] = COMBO(KC_W_KC_E_KC_O_, KC_NO),
        [KC_W_KC_E_KC_I__ie] = COMBO(KC_W_KC_E_KC_I_, KC_NO),
        [KC_W_KC_E_KC_U__ir] = COMBO(KC_W_KC_E_KC_U_, KC_NO),
        [KC_W_KC_E_KC_Y__it] = COMBO(KC_W_KC_E_KC_Y_, KC_NO),
        [KC_W_KC_E_KC_I_KC_J__iy] = COMBO(KC_W_KC_E_KC_I_KC_J_, KC_NO),
        [KC_W_KC_E_KC_U_KC_I__iu] = COMBO(KC_W_KC_E_KC_U_KC_I_, KC_NO),
        [KC_W_KC_E_KC_I_KC_O__ii] = COMBO(KC_W_KC_E_KC_I_KC_O_, KC_NO),
        [KC_W_KC_E_KC_U_KC_O__io] = COMBO(KC_W_KC_E_KC_U_KC_O_, KC_NO),
        [KC_W_KC_E_KC_U_KC_P__ip] = COMBO(KC_W_KC_E_KC_U_KC_P_, KC_NO),
        [KC_W_KC_E_KC_J_KC_O__ih] = COMBO(KC_W_KC_E_KC_J_KC_O_, KC_NO),
        [KC_W_KC_E_KC_J_KC_K__ij] = COMBO(KC_W_KC_E_KC_J_KC_K_, KC_NO),
        [KC_W_KC_E_KC_K_KC_L__ik] = COMBO(KC_W_KC_E_KC_K_KC_L_, KC_NO),
        [KC_W_KC_E_KC_J_KC_L__il] = COMBO(KC_W_KC_E_KC_J_KC_L_, KC_NO),
        [KC_W_KC_E_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_W_KC_E_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_E_KC_L_KC_COMMA__in] = COMBO(KC_W_KC_E_KC_L_KC_COMMA_, KC_NO),
        [KC_W_KC_E_KC_M_KC_COMMA__im] = COMBO(KC_W_KC_E_KC_M_KC_COMMA_, KC_NO),
        [KC_W_KC_E_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_W_KC_E_KC_COMMA_KC_DOT_, KC_NO),
        [KC_W_KC_E_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_W_KC_E_KC_M_KC_DOT_, KC_NO),
        [KC_W_KC_E_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_W_KC_E_KC_M_KC_SLASH_, KC_NO),
        [KC_W_KC_E_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_W_KC_E_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_W_KC_E_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_W_KC_E_KC_DOT_KC_SLASH_, KC_NO),
        [KC_W_KC_E_KC_N_KC_M__nodisplaychar] = COMBO(KC_W_KC_E_KC_N_KC_M_, KC_NO),
        [KC_W_KC_E_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_W_KC_E_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_R_KC_SEMICOLON__oa] = COMBO(KC_W_KC_R_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_R_KC_L__os] = COMBO(KC_W_KC_R_KC_L_, KC_NO),
        [KC_W_KC_R_KC_K__od] = COMBO(KC_W_KC_R_KC_K_, KC_NO),
        [KC_W_KC_R_KC_J__of] = COMBO(KC_W_KC_R_KC_J_, KC_NO),
        [KC_W_KC_R_KC_H__og] = COMBO(KC_W_KC_R_KC_H_, KC_NO),
        [KC_W_KC_R_KC_SLASH__oz] = COMBO(KC_W_KC_R_KC_SLASH_, KC_NO),
        [KC_W_KC_R_KC_DOT__ox] = COMBO(KC_W_KC_R_KC_DOT_, KC_NO),
        [KC_W_KC_R_KC_COMMA__oc] = COMBO(KC_W_KC_R_KC_COMMA_, KC_NO),
        [KC_W_KC_R_KC_M__ov] = COMBO(KC_W_KC_R_KC_M_, KC_NO),
        [KC_W_KC_R_KC_N__ob] = COMBO(KC_W_KC_R_KC_N_, KC_NO),
        [KC_W_KC_R_KC_P__oq] = COMBO(KC_W_KC_R_KC_P_, KC_NO),
        [KC_W_KC_R_KC_O__ow] = COMBO(KC_W_KC_R_KC_O_, KC_NO),
        [KC_W_KC_R_KC_I__oe] = COMBO(KC_W_KC_R_KC_I_, KC_NO),
        [KC_W_KC_R_KC_U__or] = COMBO(KC_W_KC_R_KC_U_, KC_NO),
        [KC_W_KC_R_KC_Y__ot] = COMBO(KC_W_KC_R_KC_Y_, KC_NO),
        [KC_W_KC_R_KC_I_KC_J__oy] = COMBO(KC_W_KC_R_KC_I_KC_J_, KC_NO),
        [KC_W_KC_R_KC_U_KC_I__ou] = COMBO(KC_W_KC_R_KC_U_KC_I_, KC_NO),
        [KC_W_KC_R_KC_I_KC_O__oi] = COMBO(KC_W_KC_R_KC_I_KC_O_, KC_NO),
        [KC_W_KC_R_KC_U_KC_O__oo] = COMBO(KC_W_KC_R_KC_U_KC_O_, KC_NO),
        [KC_W_KC_R_KC_U_KC_P__op] = COMBO(KC_W_KC_R_KC_U_KC_P_, KC_NO),
        [KC_W_KC_R_KC_J_KC_O__oh] = COMBO(KC_W_KC_R_KC_J_KC_O_, KC_NO),
        [KC_W_KC_R_KC_J_KC_K__oj] = COMBO(KC_W_KC_R_KC_J_KC_K_, KC_NO),
        [KC_W_KC_R_KC_K_KC_L__ok] = COMBO(KC_W_KC_R_KC_K_KC_L_, KC_NO),
        [KC_W_KC_R_KC_J_KC_L__ol] = COMBO(KC_W_KC_R_KC_J_KC_L_, KC_NO),
        [KC_W_KC_R_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_W_KC_R_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_R_KC_L_KC_COMMA__on] = COMBO(KC_W_KC_R_KC_L_KC_COMMA_, KC_NO),
        [KC_W_KC_R_KC_M_KC_COMMA__om] = COMBO(KC_W_KC_R_KC_M_KC_COMMA_, KC_NO),
        [KC_W_KC_R_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_W_KC_R_KC_COMMA_KC_DOT_, KC_NO),
        [KC_W_KC_R_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_W_KC_R_KC_M_KC_DOT_, KC_NO),
        [KC_W_KC_R_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_W_KC_R_KC_M_KC_SLASH_, KC_NO),
        [KC_W_KC_R_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_W_KC_R_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_W_KC_R_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_W_KC_R_KC_DOT_KC_SLASH_, KC_NO),
        [KC_W_KC_R_KC_N_KC_M__nodisplaychar] = COMBO(KC_W_KC_R_KC_N_KC_M_, KC_NO),
        [KC_W_KC_R_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_W_KC_R_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_R_KC_Q_KC_SEMICOLON__pa] = COMBO(KC_R_KC_Q_KC_SEMICOLON_, KC_NO),
        [KC_R_KC_Q_KC_L__ps] = COMBO(KC_R_KC_Q_KC_L_, KC_NO),
        [KC_R_KC_Q_KC_K__pd] = COMBO(KC_R_KC_Q_KC_K_, KC_NO),
        [KC_R_KC_Q_KC_J__pf] = COMBO(KC_R_KC_Q_KC_J_, KC_NO),
        [KC_R_KC_Q_KC_H__pg] = COMBO(KC_R_KC_Q_KC_H_, KC_NO),
        [KC_R_KC_Q_KC_SLASH__pz] = COMBO(KC_R_KC_Q_KC_SLASH_, KC_NO),
        [KC_R_KC_Q_KC_DOT__px] = COMBO(KC_R_KC_Q_KC_DOT_, KC_NO),
        [KC_R_KC_Q_KC_COMMA__pc] = COMBO(KC_R_KC_Q_KC_COMMA_, KC_NO),
        [KC_R_KC_Q_KC_M__pv] = COMBO(KC_R_KC_Q_KC_M_, KC_NO),
        [KC_R_KC_Q_KC_N__pb] = COMBO(KC_R_KC_Q_KC_N_, KC_NO),
        [KC_R_KC_Q_KC_P__pq] = COMBO(KC_R_KC_Q_KC_P_, KC_NO),
        [KC_R_KC_Q_KC_O__pw] = COMBO(KC_R_KC_Q_KC_O_, KC_NO),
        [KC_R_KC_Q_KC_I__pe] = COMBO(KC_R_KC_Q_KC_I_, KC_NO),
        [KC_R_KC_Q_KC_U__pr] = COMBO(KC_R_KC_Q_KC_U_, KC_NO),
        [KC_R_KC_Q_KC_Y__pt] = COMBO(KC_R_KC_Q_KC_Y_, KC_NO),
        [KC_R_KC_Q_KC_I_KC_J__py] = COMBO(KC_R_KC_Q_KC_I_KC_J_, KC_NO),
        [KC_R_KC_Q_KC_U_KC_I__pu] = COMBO(KC_R_KC_Q_KC_U_KC_I_, KC_NO),
        [KC_R_KC_Q_KC_I_KC_O__pi] = COMBO(KC_R_KC_Q_KC_I_KC_O_, KC_NO),
        [KC_R_KC_Q_KC_U_KC_O__po] = COMBO(KC_R_KC_Q_KC_U_KC_O_, KC_NO),
        [KC_R_KC_Q_KC_U_KC_P__pp] = COMBO(KC_R_KC_Q_KC_U_KC_P_, KC_NO),
        [KC_R_KC_Q_KC_J_KC_O__ph] = COMBO(KC_R_KC_Q_KC_J_KC_O_, KC_NO),
        [KC_R_KC_Q_KC_J_KC_K__pj] = COMBO(KC_R_KC_Q_KC_J_KC_K_, KC_NO),
        [KC_R_KC_Q_KC_K_KC_L__pk] = COMBO(KC_R_KC_Q_KC_K_KC_L_, KC_NO),
        [KC_R_KC_Q_KC_J_KC_L__pl] = COMBO(KC_R_KC_Q_KC_J_KC_L_, KC_NO),
        [KC_R_KC_Q_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_R_KC_Q_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_R_KC_Q_KC_L_KC_COMMA__pn] = COMBO(KC_R_KC_Q_KC_L_KC_COMMA_, KC_NO),
        [KC_R_KC_Q_KC_M_KC_COMMA__pm] = COMBO(KC_R_KC_Q_KC_M_KC_COMMA_, KC_NO),
        [KC_R_KC_Q_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_R_KC_Q_KC_COMMA_KC_DOT_, KC_NO),
        [KC_R_KC_Q_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_R_KC_Q_KC_M_KC_DOT_, KC_NO),
        [KC_R_KC_Q_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_R_KC_Q_KC_M_KC_SLASH_, KC_NO),
        [KC_R_KC_Q_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_R_KC_Q_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_R_KC_Q_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_R_KC_Q_KC_DOT_KC_SLASH_, KC_NO),
        [KC_R_KC_Q_KC_N_KC_M__nodisplaychar] = COMBO(KC_R_KC_Q_KC_N_KC_M_, KC_NO),
        [KC_R_KC_Q_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_R_KC_Q_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_Q_KC_SEMICOLON__qa] = COMBO(KC_Q_KC_SEMICOLON_, KC_NO),
        [KC_Q_KC_L__qs] = COMBO(KC_Q_KC_L_, KC_NO),
        [KC_Q_KC_K__qd] = COMBO(KC_Q_KC_K_, KC_NO),
        [KC_Q_KC_J__qf] = COMBO(KC_Q_KC_J_, KC_NO),
        [KC_Q_KC_H__qg] = COMBO(KC_Q_KC_H_, KC_NO),
        [KC_Q_KC_SLASH__qz] = COMBO(KC_Q_KC_SLASH_, KC_NO),
        [KC_Q_KC_DOT__qx] = COMBO(KC_Q_KC_DOT_, KC_NO),
        [KC_Q_KC_COMMA__qc] = COMBO(KC_Q_KC_COMMA_, KC_NO),
        [KC_Q_KC_M__qv] = COMBO(KC_Q_KC_M_, KC_NO),
        [KC_Q_KC_N__qb] = COMBO(KC_Q_KC_N_, KC_NO),
        [KC_Q_KC_P__qq] = COMBO(KC_Q_KC_P_, KC_NO),
        [KC_Q_KC_O__qw] = COMBO(KC_Q_KC_O_, KC_NO),
        [KC_Q_KC_I__qe] = COMBO(KC_Q_KC_I_, KC_NO),
        [KC_Q_KC_U__qr] = COMBO(KC_Q_KC_U_, KC_NO),
        [KC_Q_KC_Y__qt] = COMBO(KC_Q_KC_Y_, KC_NO),
        [KC_Q_KC_I_KC_J__qy] = COMBO(KC_Q_KC_I_KC_J_, KC_NO),
        [KC_Q_KC_U_KC_I__qu] = COMBO(KC_Q_KC_U_KC_I_, KC_NO),
        [KC_Q_KC_I_KC_O__qi] = COMBO(KC_Q_KC_I_KC_O_, KC_NO),
        [KC_Q_KC_U_KC_O__qo] = COMBO(KC_Q_KC_U_KC_O_, KC_NO),
        [KC_Q_KC_U_KC_P__qp] = COMBO(KC_Q_KC_U_KC_P_, KC_NO),
        [KC_Q_KC_J_KC_O__qh] = COMBO(KC_Q_KC_J_KC_O_, KC_NO),
        [KC_Q_KC_J_KC_K__qj] = COMBO(KC_Q_KC_J_KC_K_, KC_NO),
        [KC_Q_KC_K_KC_L__qk] = COMBO(KC_Q_KC_K_KC_L_, KC_NO),
        [KC_Q_KC_J_KC_L__ql] = COMBO(KC_Q_KC_J_KC_L_, KC_NO),
        [KC_Q_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Q_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_Q_KC_L_KC_COMMA__qn] = COMBO(KC_Q_KC_L_KC_COMMA_, KC_NO),
        [KC_Q_KC_M_KC_COMMA__qm] = COMBO(KC_Q_KC_M_KC_COMMA_, KC_NO),
        [KC_Q_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_Q_KC_COMMA_KC_DOT_, KC_NO),
        [KC_Q_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_Q_KC_M_KC_DOT_, KC_NO),
        [KC_Q_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_Q_KC_M_KC_SLASH_, KC_NO),
        [KC_Q_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_Q_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_Q_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_Q_KC_DOT_KC_SLASH_, KC_NO),
        [KC_Q_KC_N_KC_M__nodisplaychar] = COMBO(KC_Q_KC_N_KC_M_, KC_NO),
        [KC_Q_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Q_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_SEMICOLON__wa] = COMBO(KC_W_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_L__ws] = COMBO(KC_W_KC_L_, KC_NO),
        [KC_W_KC_K__wd] = COMBO(KC_W_KC_K_, KC_NO),
        [KC_W_KC_J__wf] = COMBO(KC_W_KC_J_, KC_NO),
        [KC_W_KC_H__wg] = COMBO(KC_W_KC_H_, KC_NO),
        [KC_W_KC_SLASH__wz] = COMBO(KC_W_KC_SLASH_, KC_NO),
        [KC_W_KC_DOT__wx] = COMBO(KC_W_KC_DOT_, KC_NO),
        [KC_W_KC_COMMA__wc] = COMBO(KC_W_KC_COMMA_, KC_NO),
        [KC_W_KC_M__wv] = COMBO(KC_W_KC_M_, KC_NO),
        [KC_W_KC_N__wb] = COMBO(KC_W_KC_N_, KC_NO),
        [KC_W_KC_P__wq] = COMBO(KC_W_KC_P_, KC_NO),
        [KC_W_KC_O__ww] = COMBO(KC_W_KC_O_, KC_NO),
        [KC_W_KC_I__we] = COMBO(KC_W_KC_I_, KC_NO),
        [KC_W_KC_U__wr] = COMBO(KC_W_KC_U_, KC_NO),
        [KC_W_KC_Y__wt] = COMBO(KC_W_KC_Y_, KC_NO),
        [KC_W_KC_I_KC_J__wy] = COMBO(KC_W_KC_I_KC_J_, KC_NO),
        [KC_W_KC_U_KC_I__wu] = COMBO(KC_W_KC_U_KC_I_, KC_NO),
        [KC_W_KC_I_KC_O__wi] = COMBO(KC_W_KC_I_KC_O_, KC_NO),
        [KC_W_KC_U_KC_O__wo] = COMBO(KC_W_KC_U_KC_O_, KC_NO),
        [KC_W_KC_U_KC_P__wp] = COMBO(KC_W_KC_U_KC_P_, KC_NO),
        [KC_W_KC_J_KC_O__wh] = COMBO(KC_W_KC_J_KC_O_, KC_NO),
        [KC_W_KC_J_KC_K__wj] = COMBO(KC_W_KC_J_KC_K_, KC_NO),
        [KC_W_KC_K_KC_L__wk] = COMBO(KC_W_KC_K_KC_L_, KC_NO),
        [KC_W_KC_J_KC_L__wl] = COMBO(KC_W_KC_J_KC_L_, KC_NO),
        [KC_W_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_W_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_L_KC_COMMA__wn] = COMBO(KC_W_KC_L_KC_COMMA_, KC_NO),
        [KC_W_KC_M_KC_COMMA__wm] = COMBO(KC_W_KC_M_KC_COMMA_, KC_NO),
        [KC_W_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_W_KC_COMMA_KC_DOT_, KC_NO),
        [KC_W_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_W_KC_M_KC_DOT_, KC_NO),
        [KC_W_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_W_KC_M_KC_SLASH_, KC_NO),
        [KC_W_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_W_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_W_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_W_KC_DOT_KC_SLASH_, KC_NO),
        [KC_W_KC_N_KC_M__nodisplaychar] = COMBO(KC_W_KC_N_KC_M_, KC_NO),
        [KC_W_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_W_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_SEMICOLON__ea] = COMBO(KC_E_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_L__es] = COMBO(KC_E_KC_L_, KC_NO),
        [KC_E_KC_K__ed] = COMBO(KC_E_KC_K_, KC_NO),
        [KC_E_KC_J__ef] = COMBO(KC_E_KC_J_, KC_NO),
        [KC_E_KC_H__eg] = COMBO(KC_E_KC_H_, KC_NO),
        [KC_E_KC_SLASH__ez] = COMBO(KC_E_KC_SLASH_, KC_NO),
        [KC_E_KC_DOT__ex] = COMBO(KC_E_KC_DOT_, KC_NO),
        [KC_E_KC_COMMA__ec] = COMBO(KC_E_KC_COMMA_, KC_NO),
        [KC_E_KC_M__ev] = COMBO(KC_E_KC_M_, KC_NO),
        [KC_E_KC_N__eb] = COMBO(KC_E_KC_N_, KC_NO),
        [KC_E_KC_P__eq] = COMBO(KC_E_KC_P_, KC_NO),
        [KC_E_KC_O__ew] = COMBO(KC_E_KC_O_, KC_NO),
        [KC_E_KC_I__ee] = COMBO(KC_E_KC_I_, KC_NO),
        [KC_E_KC_U__er] = COMBO(KC_E_KC_U_, KC_NO),
        [KC_E_KC_Y__et] = COMBO(KC_E_KC_Y_, KC_NO),
        [KC_E_KC_I_KC_J__ey] = COMBO(KC_E_KC_I_KC_J_, KC_NO),
        [KC_E_KC_U_KC_I__eu] = COMBO(KC_E_KC_U_KC_I_, KC_NO),
        [KC_E_KC_I_KC_O__ei] = COMBO(KC_E_KC_I_KC_O_, KC_NO),
        [KC_E_KC_U_KC_O__eo] = COMBO(KC_E_KC_U_KC_O_, KC_NO),
        [KC_E_KC_U_KC_P__ep] = COMBO(KC_E_KC_U_KC_P_, KC_NO),
        [KC_E_KC_J_KC_O__eh] = COMBO(KC_E_KC_J_KC_O_, KC_NO),
        [KC_E_KC_J_KC_K__ej] = COMBO(KC_E_KC_J_KC_K_, KC_NO),
        [KC_E_KC_K_KC_L__ek] = COMBO(KC_E_KC_K_KC_L_, KC_NO),
        [KC_E_KC_J_KC_L__el] = COMBO(KC_E_KC_J_KC_L_, KC_NO),
        [KC_E_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_E_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_E_KC_L_KC_COMMA__en] = COMBO(KC_E_KC_L_KC_COMMA_, KC_NO),
        [KC_E_KC_M_KC_COMMA__em] = COMBO(KC_E_KC_M_KC_COMMA_, KC_NO),
        [KC_E_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_E_KC_COMMA_KC_DOT_, KC_NO),
        [KC_E_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_E_KC_M_KC_DOT_, KC_NO),
        [KC_E_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_E_KC_M_KC_SLASH_, KC_NO),
        [KC_E_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_E_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_E_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_E_KC_DOT_KC_SLASH_, KC_NO),
        [KC_E_KC_N_KC_M__nodisplaychar] = COMBO(KC_E_KC_N_KC_M_, KC_NO),
        [KC_E_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_E_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_R_KC_SEMICOLON__ra] = COMBO(KC_R_KC_SEMICOLON_, KC_NO),
        [KC_R_KC_L__rs] = COMBO(KC_R_KC_L_, KC_NO),
        [KC_R_KC_K__rd] = COMBO(KC_R_KC_K_, KC_NO),
        [KC_R_KC_J__rf] = COMBO(KC_R_KC_J_, KC_NO),
        [KC_R_KC_H__rg] = COMBO(KC_R_KC_H_, KC_NO),
        [KC_R_KC_SLASH__rz] = COMBO(KC_R_KC_SLASH_, KC_NO),
        [KC_R_KC_DOT__rx] = COMBO(KC_R_KC_DOT_, KC_NO),
        [KC_R_KC_COMMA__rc] = COMBO(KC_R_KC_COMMA_, KC_NO),
        [KC_R_KC_M__rv] = COMBO(KC_R_KC_M_, KC_NO),
        [KC_R_KC_N__rb] = COMBO(KC_R_KC_N_, KC_NO),
        [KC_R_KC_P__rq] = COMBO(KC_R_KC_P_, KC_NO),
        [KC_R_KC_O__rw] = COMBO(KC_R_KC_O_, KC_NO),
        [KC_R_KC_I__re] = COMBO(KC_R_KC_I_, KC_NO),
        [KC_R_KC_U__rr] = COMBO(KC_R_KC_U_, KC_NO),
        [KC_R_KC_Y__rt] = COMBO(KC_R_KC_Y_, KC_NO),
        [KC_R_KC_I_KC_J__ry] = COMBO(KC_R_KC_I_KC_J_, KC_NO),
        [KC_R_KC_U_KC_I__ru] = COMBO(KC_R_KC_U_KC_I_, KC_NO),
        [KC_R_KC_I_KC_O__ri] = COMBO(KC_R_KC_I_KC_O_, KC_NO),
        [KC_R_KC_U_KC_O__ro] = COMBO(KC_R_KC_U_KC_O_, KC_NO),
        [KC_R_KC_U_KC_P__rp] = COMBO(KC_R_KC_U_KC_P_, KC_NO),
        [KC_R_KC_J_KC_O__rh] = COMBO(KC_R_KC_J_KC_O_, KC_NO),
        [KC_R_KC_J_KC_K__rj] = COMBO(KC_R_KC_J_KC_K_, KC_NO),
        [KC_R_KC_K_KC_L__rk] = COMBO(KC_R_KC_K_KC_L_, KC_NO),
        [KC_R_KC_J_KC_L__rl] = COMBO(KC_R_KC_J_KC_L_, KC_NO),
        [KC_R_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_R_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_R_KC_L_KC_COMMA__rn] = COMBO(KC_R_KC_L_KC_COMMA_, KC_NO),
        [KC_R_KC_M_KC_COMMA__rm] = COMBO(KC_R_KC_M_KC_COMMA_, KC_NO),
        [KC_R_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_R_KC_COMMA_KC_DOT_, KC_NO),
        [KC_R_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_R_KC_M_KC_DOT_, KC_NO),
        [KC_R_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_R_KC_M_KC_SLASH_, KC_NO),
        [KC_R_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_R_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_R_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_R_KC_DOT_KC_SLASH_, KC_NO),
        [KC_R_KC_N_KC_M__nodisplaychar] = COMBO(KC_R_KC_N_KC_M_, KC_NO),
        [KC_R_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_R_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_T_KC_SEMICOLON__ta] = COMBO(KC_T_KC_SEMICOLON_, KC_NO),
        [KC_T_KC_L__ts] = COMBO(KC_T_KC_L_, KC_NO),
        [KC_T_KC_K__td] = COMBO(KC_T_KC_K_, KC_NO),
        [KC_T_KC_J__tf] = COMBO(KC_T_KC_J_, KC_NO),
        [KC_T_KC_H__tg] = COMBO(KC_T_KC_H_, KC_NO),
        [KC_T_KC_SLASH__tz] = COMBO(KC_T_KC_SLASH_, KC_NO),
        [KC_T_KC_DOT__tx] = COMBO(KC_T_KC_DOT_, KC_NO),
        [KC_T_KC_COMMA__tc] = COMBO(KC_T_KC_COMMA_, KC_NO),
        [KC_T_KC_M__tv] = COMBO(KC_T_KC_M_, KC_NO),
        [KC_T_KC_N__tb] = COMBO(KC_T_KC_N_, KC_NO),
        [KC_T_KC_P__tq] = COMBO(KC_T_KC_P_, KC_NO),
        [KC_T_KC_O__tw] = COMBO(KC_T_KC_O_, KC_NO),
        [KC_T_KC_I__te] = COMBO(KC_T_KC_I_, KC_NO),
        [KC_T_KC_U__tr] = COMBO(KC_T_KC_U_, KC_NO),
        [KC_T_KC_Y__tt] = COMBO(KC_T_KC_Y_, KC_NO),
        [KC_T_KC_I_KC_J__ty] = COMBO(KC_T_KC_I_KC_J_, KC_NO),
        [KC_T_KC_U_KC_I__tu] = COMBO(KC_T_KC_U_KC_I_, KC_NO),
        [KC_T_KC_I_KC_O__ti] = COMBO(KC_T_KC_I_KC_O_, KC_NO),
        [KC_T_KC_U_KC_O__to] = COMBO(KC_T_KC_U_KC_O_, KC_NO),
        [KC_T_KC_U_KC_P__tp] = COMBO(KC_T_KC_U_KC_P_, KC_NO),
        [KC_T_KC_J_KC_O__th] = COMBO(KC_T_KC_J_KC_O_, KC_NO),
        [KC_T_KC_J_KC_K__tj] = COMBO(KC_T_KC_J_KC_K_, KC_NO),
        [KC_T_KC_K_KC_L__tk] = COMBO(KC_T_KC_K_KC_L_, KC_NO),
        [KC_T_KC_J_KC_L__tl] = COMBO(KC_T_KC_J_KC_L_, KC_NO),
        [KC_T_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_T_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_T_KC_L_KC_COMMA__tn] = COMBO(KC_T_KC_L_KC_COMMA_, KC_NO),
        [KC_T_KC_M_KC_COMMA__tm] = COMBO(KC_T_KC_M_KC_COMMA_, KC_NO),
        [KC_T_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_T_KC_COMMA_KC_DOT_, KC_NO),
        [KC_T_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_T_KC_M_KC_DOT_, KC_NO),
        [KC_T_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_T_KC_M_KC_SLASH_, KC_NO),
        [KC_T_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_T_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_T_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_T_KC_DOT_KC_SLASH_, KC_NO),
        [KC_T_KC_N_KC_M__nodisplaychar] = COMBO(KC_T_KC_N_KC_M_, KC_NO),
        [KC_T_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_T_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_SEMICOLON__aa] = COMBO(KC_A_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_L__as] = COMBO(KC_A_KC_L_, KC_NO),
        [KC_A_KC_K__ad] = COMBO(KC_A_KC_K_, KC_NO),
        [KC_A_KC_J__af] = COMBO(KC_A_KC_J_, KC_NO),
        [KC_A_KC_H__ag] = COMBO(KC_A_KC_H_, KC_NO),
        [KC_A_KC_SLASH__az] = COMBO(KC_A_KC_SLASH_, KC_NO),
        [KC_A_KC_DOT__ax] = COMBO(KC_A_KC_DOT_, KC_NO),
        [KC_A_KC_COMMA__ac] = COMBO(KC_A_KC_COMMA_, KC_NO),
        [KC_A_KC_M__av] = COMBO(KC_A_KC_M_, KC_NO),
        [KC_A_KC_N__ab] = COMBO(KC_A_KC_N_, KC_NO),
        [KC_A_KC_P__aq] = COMBO(KC_A_KC_P_, KC_NO),
        [KC_A_KC_O__aw] = COMBO(KC_A_KC_O_, KC_NO),
        [KC_A_KC_I__ae] = COMBO(KC_A_KC_I_, KC_NO),
        [KC_A_KC_U__ar] = COMBO(KC_A_KC_U_, KC_NO),
        [KC_A_KC_Y__at] = COMBO(KC_A_KC_Y_, KC_NO),
        [KC_A_KC_I_KC_J__ay] = COMBO(KC_A_KC_I_KC_J_, KC_NO),
        [KC_A_KC_U_KC_I__au] = COMBO(KC_A_KC_U_KC_I_, KC_NO),
        [KC_A_KC_I_KC_O__ai] = COMBO(KC_A_KC_I_KC_O_, KC_NO),
        [KC_A_KC_U_KC_O__ao] = COMBO(KC_A_KC_U_KC_O_, KC_NO),
        [KC_A_KC_U_KC_P__ap] = COMBO(KC_A_KC_U_KC_P_, KC_NO),
        [KC_A_KC_J_KC_O__ah] = COMBO(KC_A_KC_J_KC_O_, KC_NO),
        [KC_A_KC_J_KC_K__aj] = COMBO(KC_A_KC_J_KC_K_, KC_NO),
        [KC_A_KC_K_KC_L__ak] = COMBO(KC_A_KC_K_KC_L_, KC_NO),
        [KC_A_KC_J_KC_L__al] = COMBO(KC_A_KC_J_KC_L_, KC_NO),
        [KC_A_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_A_KC_L_KC_COMMA__an] = COMBO(KC_A_KC_L_KC_COMMA_, KC_NO),
        [KC_A_KC_M_KC_COMMA__am] = COMBO(KC_A_KC_M_KC_COMMA_, KC_NO),
        [KC_A_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_COMMA_KC_DOT_, KC_NO),
        [KC_A_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_A_KC_M_KC_DOT_, KC_NO),
        [KC_A_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_M_KC_SLASH_, KC_NO),
        [KC_A_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_A_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_A_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_A_KC_DOT_KC_SLASH_, KC_NO),
        [KC_A_KC_N_KC_M__nodisplaychar] = COMBO(KC_A_KC_N_KC_M_, KC_NO),
        [KC_A_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_A_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_SEMICOLON__sa] = COMBO(KC_S_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_L__ss] = COMBO(KC_S_KC_L_, KC_NO),
        [KC_S_KC_K__sd] = COMBO(KC_S_KC_K_, KC_NO),
        [KC_S_KC_J__sf] = COMBO(KC_S_KC_J_, KC_NO),
        [KC_S_KC_H__sg] = COMBO(KC_S_KC_H_, KC_NO),
        [KC_S_KC_SLASH__sz] = COMBO(KC_S_KC_SLASH_, KC_NO),
        [KC_S_KC_DOT__sx] = COMBO(KC_S_KC_DOT_, KC_NO),
        [KC_S_KC_COMMA__sc] = COMBO(KC_S_KC_COMMA_, KC_NO),
        [KC_S_KC_M__sv] = COMBO(KC_S_KC_M_, KC_NO),
        [KC_S_KC_N__sb] = COMBO(KC_S_KC_N_, KC_NO),
        [KC_S_KC_P__sq] = COMBO(KC_S_KC_P_, KC_NO),
        [KC_S_KC_O__sw] = COMBO(KC_S_KC_O_, KC_NO),
        [KC_S_KC_I__se] = COMBO(KC_S_KC_I_, KC_NO),
        [KC_S_KC_U__sr] = COMBO(KC_S_KC_U_, KC_NO),
        [KC_S_KC_Y__st] = COMBO(KC_S_KC_Y_, KC_NO),
        [KC_S_KC_I_KC_J__sy] = COMBO(KC_S_KC_I_KC_J_, KC_NO),
        [KC_S_KC_U_KC_I__su] = COMBO(KC_S_KC_U_KC_I_, KC_NO),
        [KC_S_KC_I_KC_O__si] = COMBO(KC_S_KC_I_KC_O_, KC_NO),
        [KC_S_KC_U_KC_O__so] = COMBO(KC_S_KC_U_KC_O_, KC_NO),
        [KC_S_KC_U_KC_P__sp] = COMBO(KC_S_KC_U_KC_P_, KC_NO),
        [KC_S_KC_J_KC_O__sh] = COMBO(KC_S_KC_J_KC_O_, KC_NO),
        [KC_S_KC_J_KC_K__sj] = COMBO(KC_S_KC_J_KC_K_, KC_NO),
        [KC_S_KC_K_KC_L__sk] = COMBO(KC_S_KC_K_KC_L_, KC_NO),
        [KC_S_KC_J_KC_L__sl] = COMBO(KC_S_KC_J_KC_L_, KC_NO),
        [KC_S_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_S_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_S_KC_L_KC_COMMA__sn] = COMBO(KC_S_KC_L_KC_COMMA_, KC_NO),
        [KC_S_KC_M_KC_COMMA__sm] = COMBO(KC_S_KC_M_KC_COMMA_, KC_NO),
        [KC_S_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_S_KC_COMMA_KC_DOT_, KC_NO),
        [KC_S_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_S_KC_M_KC_DOT_, KC_NO),
        [KC_S_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_S_KC_M_KC_SLASH_, KC_NO),
        [KC_S_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_S_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_S_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_S_KC_DOT_KC_SLASH_, KC_NO),
        [KC_S_KC_N_KC_M__nodisplaychar] = COMBO(KC_S_KC_N_KC_M_, KC_NO),
        [KC_S_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_S_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_D_KC_SEMICOLON__da] = COMBO(KC_D_KC_SEMICOLON_, KC_NO),
        [KC_D_KC_L__ds] = COMBO(KC_D_KC_L_, KC_NO),
        [KC_D_KC_K__dd] = COMBO(KC_D_KC_K_, KC_NO),
        [KC_D_KC_J__df] = COMBO(KC_D_KC_J_, KC_NO),
        [KC_D_KC_H__dg] = COMBO(KC_D_KC_H_, KC_NO),
        [KC_D_KC_SLASH__dz] = COMBO(KC_D_KC_SLASH_, KC_NO),
        [KC_D_KC_DOT__dx] = COMBO(KC_D_KC_DOT_, KC_NO),
        [KC_D_KC_COMMA__dc] = COMBO(KC_D_KC_COMMA_, KC_NO),
        [KC_D_KC_M__dv] = COMBO(KC_D_KC_M_, KC_NO),
        [KC_D_KC_N__db] = COMBO(KC_D_KC_N_, KC_NO),
        [KC_D_KC_P__dq] = COMBO(KC_D_KC_P_, KC_NO),
        [KC_D_KC_O__dw] = COMBO(KC_D_KC_O_, KC_NO),
        [KC_D_KC_I__de] = COMBO(KC_D_KC_I_, KC_NO),
        [KC_D_KC_U__dr] = COMBO(KC_D_KC_U_, KC_NO),
        [KC_D_KC_Y__dt] = COMBO(KC_D_KC_Y_, KC_NO),
        [KC_D_KC_I_KC_J__dy] = COMBO(KC_D_KC_I_KC_J_, KC_NO),
        [KC_D_KC_U_KC_I__du] = COMBO(KC_D_KC_U_KC_I_, KC_NO),
        [KC_D_KC_I_KC_O__di] = COMBO(KC_D_KC_I_KC_O_, KC_NO),
        [KC_D_KC_U_KC_O__do] = COMBO(KC_D_KC_U_KC_O_, KC_NO),
        [KC_D_KC_U_KC_P__dp] = COMBO(KC_D_KC_U_KC_P_, KC_NO),
        [KC_D_KC_J_KC_O__dh] = COMBO(KC_D_KC_J_KC_O_, KC_NO),
        [KC_D_KC_J_KC_K__dj] = COMBO(KC_D_KC_J_KC_K_, KC_NO),
        [KC_D_KC_K_KC_L__dk] = COMBO(KC_D_KC_K_KC_L_, KC_NO),
        [KC_D_KC_J_KC_L__dl] = COMBO(KC_D_KC_J_KC_L_, KC_NO),
        [KC_D_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_D_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_D_KC_L_KC_COMMA__dn] = COMBO(KC_D_KC_L_KC_COMMA_, KC_NO),
        [KC_D_KC_M_KC_COMMA__dm] = COMBO(KC_D_KC_M_KC_COMMA_, KC_NO),
        [KC_D_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_D_KC_COMMA_KC_DOT_, KC_NO),
        [KC_D_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_D_KC_M_KC_DOT_, KC_NO),
        [KC_D_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_D_KC_M_KC_SLASH_, KC_NO),
        [KC_D_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_D_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_D_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_D_KC_DOT_KC_SLASH_, KC_NO),
        [KC_D_KC_N_KC_M__nodisplaychar] = COMBO(KC_D_KC_N_KC_M_, KC_NO),
        [KC_D_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_D_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_F_KC_SEMICOLON__fa] = COMBO(KC_F_KC_SEMICOLON_, KC_NO),
        [KC_F_KC_L__fs] = COMBO(KC_F_KC_L_, KC_NO),
        [KC_F_KC_K__fd] = COMBO(KC_F_KC_K_, KC_NO),
        [KC_F_KC_J__ff] = COMBO(KC_F_KC_J_, KC_NO),
        [KC_F_KC_H__fg] = COMBO(KC_F_KC_H_, KC_NO),
        [KC_F_KC_SLASH__fz] = COMBO(KC_F_KC_SLASH_, KC_NO),
        [KC_F_KC_DOT__fx] = COMBO(KC_F_KC_DOT_, KC_NO),
        [KC_F_KC_COMMA__fc] = COMBO(KC_F_KC_COMMA_, KC_NO),
        [KC_F_KC_M__fv] = COMBO(KC_F_KC_M_, KC_NO),
        [KC_F_KC_N__fb] = COMBO(KC_F_KC_N_, KC_NO),
        [KC_F_KC_P__fq] = COMBO(KC_F_KC_P_, KC_NO),
        [KC_F_KC_O__fw] = COMBO(KC_F_KC_O_, KC_NO),
        [KC_F_KC_I__fe] = COMBO(KC_F_KC_I_, KC_NO),
        [KC_F_KC_U__fr] = COMBO(KC_F_KC_U_, KC_NO),
        [KC_F_KC_Y__ft] = COMBO(KC_F_KC_Y_, KC_NO),
        [KC_F_KC_I_KC_J__fy] = COMBO(KC_F_KC_I_KC_J_, KC_NO),
        [KC_F_KC_U_KC_I__fu] = COMBO(KC_F_KC_U_KC_I_, KC_NO),
        [KC_F_KC_I_KC_O__fi] = COMBO(KC_F_KC_I_KC_O_, KC_NO),
        [KC_F_KC_U_KC_O__fo] = COMBO(KC_F_KC_U_KC_O_, KC_NO),
        [KC_F_KC_U_KC_P__fp] = COMBO(KC_F_KC_U_KC_P_, KC_NO),
        [KC_F_KC_J_KC_O__fh] = COMBO(KC_F_KC_J_KC_O_, KC_NO),
        [KC_F_KC_J_KC_K__fj] = COMBO(KC_F_KC_J_KC_K_, KC_NO),
        [KC_F_KC_K_KC_L__fk] = COMBO(KC_F_KC_K_KC_L_, KC_NO),
        [KC_F_KC_J_KC_L__fl] = COMBO(KC_F_KC_J_KC_L_, KC_NO),
        [KC_F_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_F_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_F_KC_L_KC_COMMA__fn] = COMBO(KC_F_KC_L_KC_COMMA_, KC_NO),
        [KC_F_KC_M_KC_COMMA__fm] = COMBO(KC_F_KC_M_KC_COMMA_, KC_NO),
        [KC_F_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_F_KC_COMMA_KC_DOT_, KC_NO),
        [KC_F_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_F_KC_M_KC_DOT_, KC_NO),
        [KC_F_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_F_KC_M_KC_SLASH_, KC_NO),
        [KC_F_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_F_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_F_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_F_KC_DOT_KC_SLASH_, KC_NO),
        [KC_F_KC_N_KC_M__nodisplaychar] = COMBO(KC_F_KC_N_KC_M_, KC_NO),
        [KC_F_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_F_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_G_KC_SEMICOLON__ga] = COMBO(KC_G_KC_SEMICOLON_, KC_NO),
        [KC_G_KC_L__gs] = COMBO(KC_G_KC_L_, KC_NO),
        [KC_G_KC_K__gd] = COMBO(KC_G_KC_K_, KC_NO),
        [KC_G_KC_J__gf] = COMBO(KC_G_KC_J_, KC_NO),
        [KC_G_KC_H__gg] = COMBO(KC_G_KC_H_, KC_NO),
        [KC_G_KC_SLASH__gz] = COMBO(KC_G_KC_SLASH_, KC_NO),
        [KC_G_KC_DOT__gx] = COMBO(KC_G_KC_DOT_, KC_NO),
        [KC_G_KC_COMMA__gc] = COMBO(KC_G_KC_COMMA_, KC_NO),
        [KC_G_KC_M__gv] = COMBO(KC_G_KC_M_, KC_NO),
        [KC_G_KC_N__gb] = COMBO(KC_G_KC_N_, KC_NO),
        [KC_G_KC_P__gq] = COMBO(KC_G_KC_P_, KC_NO),
        [KC_G_KC_O__gw] = COMBO(KC_G_KC_O_, KC_NO),
        [KC_G_KC_I__ge] = COMBO(KC_G_KC_I_, KC_NO),
        [KC_G_KC_U__gr] = COMBO(KC_G_KC_U_, KC_NO),
        [KC_G_KC_Y__gt] = COMBO(KC_G_KC_Y_, KC_NO),
        [KC_G_KC_I_KC_J__gy] = COMBO(KC_G_KC_I_KC_J_, KC_NO),
        [KC_G_KC_U_KC_I__gu] = COMBO(KC_G_KC_U_KC_I_, KC_NO),
        [KC_G_KC_I_KC_O__gi] = COMBO(KC_G_KC_I_KC_O_, KC_NO),
        [KC_G_KC_U_KC_O__go] = COMBO(KC_G_KC_U_KC_O_, KC_NO),
        [KC_G_KC_U_KC_P__gp] = COMBO(KC_G_KC_U_KC_P_, KC_NO),
        [KC_G_KC_J_KC_O__gh] = COMBO(KC_G_KC_J_KC_O_, KC_NO),
        [KC_G_KC_J_KC_K__gj] = COMBO(KC_G_KC_J_KC_K_, KC_NO),
        [KC_G_KC_K_KC_L__gk] = COMBO(KC_G_KC_K_KC_L_, KC_NO),
        [KC_G_KC_J_KC_L__gl] = COMBO(KC_G_KC_J_KC_L_, KC_NO),
        [KC_G_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_G_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_G_KC_L_KC_COMMA__gn] = COMBO(KC_G_KC_L_KC_COMMA_, KC_NO),
        [KC_G_KC_M_KC_COMMA__gm] = COMBO(KC_G_KC_M_KC_COMMA_, KC_NO),
        [KC_G_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_G_KC_COMMA_KC_DOT_, KC_NO),
        [KC_G_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_G_KC_M_KC_DOT_, KC_NO),
        [KC_G_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_G_KC_M_KC_SLASH_, KC_NO),
        [KC_G_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_G_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_G_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_G_KC_DOT_KC_SLASH_, KC_NO),
        [KC_G_KC_N_KC_M__nodisplaychar] = COMBO(KC_G_KC_N_KC_M_, KC_NO),
        [KC_G_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_G_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_SEMICOLON__za] = COMBO(KC_Z_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_L__zs] = COMBO(KC_Z_KC_L_, KC_NO),
        [KC_Z_KC_K__zd] = COMBO(KC_Z_KC_K_, KC_NO),
        [KC_Z_KC_J__zf] = COMBO(KC_Z_KC_J_, KC_NO),
        [KC_Z_KC_H__zg] = COMBO(KC_Z_KC_H_, KC_NO),
        [KC_Z_KC_SLASH__zz] = COMBO(KC_Z_KC_SLASH_, KC_NO),
        [KC_Z_KC_DOT__zx] = COMBO(KC_Z_KC_DOT_, KC_NO),
        [KC_Z_KC_COMMA__zc] = COMBO(KC_Z_KC_COMMA_, KC_NO),
        [KC_Z_KC_M__zv] = COMBO(KC_Z_KC_M_, KC_NO),
        [KC_Z_KC_N__zb] = COMBO(KC_Z_KC_N_, KC_NO),
        [KC_Z_KC_P__zq] = COMBO(KC_Z_KC_P_, KC_NO),
        [KC_Z_KC_O__zw] = COMBO(KC_Z_KC_O_, KC_NO),
        [KC_Z_KC_I__ze] = COMBO(KC_Z_KC_I_, KC_NO),
        [KC_Z_KC_U__zr] = COMBO(KC_Z_KC_U_, KC_NO),
        [KC_Z_KC_Y__zt] = COMBO(KC_Z_KC_Y_, KC_NO),
        [KC_Z_KC_I_KC_J__zy] = COMBO(KC_Z_KC_I_KC_J_, KC_NO),
        [KC_Z_KC_U_KC_I__zu] = COMBO(KC_Z_KC_U_KC_I_, KC_NO),
        [KC_Z_KC_I_KC_O__zi] = COMBO(KC_Z_KC_I_KC_O_, KC_NO),
        [KC_Z_KC_U_KC_O__zo] = COMBO(KC_Z_KC_U_KC_O_, KC_NO),
        [KC_Z_KC_U_KC_P__zp] = COMBO(KC_Z_KC_U_KC_P_, KC_NO),
        [KC_Z_KC_J_KC_O__zh] = COMBO(KC_Z_KC_J_KC_O_, KC_NO),
        [KC_Z_KC_J_KC_K__zj] = COMBO(KC_Z_KC_J_KC_K_, KC_NO),
        [KC_Z_KC_K_KC_L__zk] = COMBO(KC_Z_KC_K_KC_L_, KC_NO),
        [KC_Z_KC_J_KC_L__zl] = COMBO(KC_Z_KC_J_KC_L_, KC_NO),
        [KC_Z_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Z_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_Z_KC_L_KC_COMMA__zn] = COMBO(KC_Z_KC_L_KC_COMMA_, KC_NO),
        [KC_Z_KC_M_KC_COMMA__zm] = COMBO(KC_Z_KC_M_KC_COMMA_, KC_NO),
        [KC_Z_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_Z_KC_COMMA_KC_DOT_, KC_NO),
        [KC_Z_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_Z_KC_M_KC_DOT_, KC_NO),
        [KC_Z_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_Z_KC_M_KC_SLASH_, KC_NO),
        [KC_Z_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_Z_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_Z_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_Z_KC_DOT_KC_SLASH_, KC_NO),
        [KC_Z_KC_N_KC_M__nodisplaychar] = COMBO(KC_Z_KC_N_KC_M_, KC_NO),
        [KC_Z_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_Z_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_SEMICOLON__xa] = COMBO(KC_X_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_L__xs] = COMBO(KC_X_KC_L_, KC_NO),
        [KC_X_KC_K__xd] = COMBO(KC_X_KC_K_, KC_NO),
        [KC_X_KC_J__xf] = COMBO(KC_X_KC_J_, KC_NO),
        [KC_X_KC_H__xg] = COMBO(KC_X_KC_H_, KC_NO),
        [KC_X_KC_SLASH__xz] = COMBO(KC_X_KC_SLASH_, KC_NO),
        [KC_X_KC_DOT__xx] = COMBO(KC_X_KC_DOT_, KC_NO),
        [KC_X_KC_COMMA__xc] = COMBO(KC_X_KC_COMMA_, KC_NO),
        [KC_X_KC_M__xv] = COMBO(KC_X_KC_M_, KC_NO),
        [KC_X_KC_N__xb] = COMBO(KC_X_KC_N_, KC_NO),
        [KC_X_KC_P__xq] = COMBO(KC_X_KC_P_, KC_NO),
        [KC_X_KC_O__xw] = COMBO(KC_X_KC_O_, KC_NO),
        [KC_X_KC_I__xe] = COMBO(KC_X_KC_I_, KC_NO),
        [KC_X_KC_U__xr] = COMBO(KC_X_KC_U_, KC_NO),
        [KC_X_KC_Y__xt] = COMBO(KC_X_KC_Y_, KC_NO),
        [KC_X_KC_I_KC_J__xy] = COMBO(KC_X_KC_I_KC_J_, KC_NO),
        [KC_X_KC_U_KC_I__xu] = COMBO(KC_X_KC_U_KC_I_, KC_NO),
        [KC_X_KC_I_KC_O__xi] = COMBO(KC_X_KC_I_KC_O_, KC_NO),
        [KC_X_KC_U_KC_O__xo] = COMBO(KC_X_KC_U_KC_O_, KC_NO),
        [KC_X_KC_U_KC_P__xp] = COMBO(KC_X_KC_U_KC_P_, KC_NO),
        [KC_X_KC_J_KC_O__xh] = COMBO(KC_X_KC_J_KC_O_, KC_NO),
        [KC_X_KC_J_KC_K__xj] = COMBO(KC_X_KC_J_KC_K_, KC_NO),
        [KC_X_KC_K_KC_L__xk] = COMBO(KC_X_KC_K_KC_L_, KC_NO),
        [KC_X_KC_J_KC_L__xl] = COMBO(KC_X_KC_J_KC_L_, KC_NO),
        [KC_X_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_X_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_X_KC_L_KC_COMMA__xn] = COMBO(KC_X_KC_L_KC_COMMA_, KC_NO),
        [KC_X_KC_M_KC_COMMA__xm] = COMBO(KC_X_KC_M_KC_COMMA_, KC_NO),
        [KC_X_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_X_KC_COMMA_KC_DOT_, KC_NO),
        [KC_X_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_X_KC_M_KC_DOT_, KC_NO),
        [KC_X_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_X_KC_M_KC_SLASH_, KC_NO),
        [KC_X_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_X_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_X_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_X_KC_DOT_KC_SLASH_, KC_NO),
        [KC_X_KC_N_KC_M__nodisplaychar] = COMBO(KC_X_KC_N_KC_M_, KC_NO),
        [KC_X_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_X_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_C_KC_SEMICOLON__ca] = COMBO(KC_C_KC_SEMICOLON_, KC_NO),
        [KC_C_KC_L__cs] = COMBO(KC_C_KC_L_, KC_NO),
        [KC_C_KC_K__cd] = COMBO(KC_C_KC_K_, KC_NO),
        [KC_C_KC_J__cf] = COMBO(KC_C_KC_J_, KC_NO),
        [KC_C_KC_H__cg] = COMBO(KC_C_KC_H_, KC_NO),
        [KC_C_KC_SLASH__cz] = COMBO(KC_C_KC_SLASH_, KC_NO),
        [KC_C_KC_DOT__cx] = COMBO(KC_C_KC_DOT_, KC_NO),
        [KC_C_KC_COMMA__cc] = COMBO(KC_C_KC_COMMA_, KC_NO),
        [KC_C_KC_M__cv] = COMBO(KC_C_KC_M_, KC_NO),
        [KC_C_KC_N__cb] = COMBO(KC_C_KC_N_, KC_NO),
        [KC_C_KC_P__cq] = COMBO(KC_C_KC_P_, KC_NO),
        [KC_C_KC_O__cw] = COMBO(KC_C_KC_O_, KC_NO),
        [KC_C_KC_I__ce] = COMBO(KC_C_KC_I_, KC_NO),
        [KC_C_KC_U__cr] = COMBO(KC_C_KC_U_, KC_NO),
        [KC_C_KC_Y__ct] = COMBO(KC_C_KC_Y_, KC_NO),
        [KC_C_KC_I_KC_J__cy] = COMBO(KC_C_KC_I_KC_J_, KC_NO),
        [KC_C_KC_U_KC_I__cu] = COMBO(KC_C_KC_U_KC_I_, KC_NO),
        [KC_C_KC_I_KC_O__ci] = COMBO(KC_C_KC_I_KC_O_, KC_NO),
        [KC_C_KC_U_KC_O__co] = COMBO(KC_C_KC_U_KC_O_, KC_NO),
        [KC_C_KC_U_KC_P__cp] = COMBO(KC_C_KC_U_KC_P_, KC_NO),
        [KC_C_KC_J_KC_O__ch] = COMBO(KC_C_KC_J_KC_O_, KC_NO),
        [KC_C_KC_J_KC_K__cj] = COMBO(KC_C_KC_J_KC_K_, KC_NO),
        [KC_C_KC_K_KC_L__ck] = COMBO(KC_C_KC_K_KC_L_, KC_NO),
        [KC_C_KC_J_KC_L__cl] = COMBO(KC_C_KC_J_KC_L_, KC_NO),
        [KC_C_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_C_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_C_KC_L_KC_COMMA__cn] = COMBO(KC_C_KC_L_KC_COMMA_, KC_NO),
        [KC_C_KC_M_KC_COMMA__cm] = COMBO(KC_C_KC_M_KC_COMMA_, KC_NO),
        [KC_C_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_C_KC_COMMA_KC_DOT_, KC_NO),
        [KC_C_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_C_KC_M_KC_DOT_, KC_NO),
        [KC_C_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_C_KC_M_KC_SLASH_, KC_NO),
        [KC_C_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_C_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_C_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_C_KC_DOT_KC_SLASH_, KC_NO),
        [KC_C_KC_N_KC_M__nodisplaychar] = COMBO(KC_C_KC_N_KC_M_, KC_NO),
        [KC_C_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_C_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_V_KC_SEMICOLON__va] = COMBO(KC_V_KC_SEMICOLON_, KC_NO),
        [KC_V_KC_L__vs] = COMBO(KC_V_KC_L_, KC_NO),
        [KC_V_KC_K__vd] = COMBO(KC_V_KC_K_, KC_NO),
        [KC_V_KC_J__vf] = COMBO(KC_V_KC_J_, KC_NO),
        [KC_V_KC_H__vg] = COMBO(KC_V_KC_H_, KC_NO),
        [KC_V_KC_SLASH__vz] = COMBO(KC_V_KC_SLASH_, KC_NO),
        [KC_V_KC_DOT__vx] = COMBO(KC_V_KC_DOT_, KC_NO),
        [KC_V_KC_COMMA__vc] = COMBO(KC_V_KC_COMMA_, KC_NO),
        [KC_V_KC_M__vv] = COMBO(KC_V_KC_M_, KC_NO),
        [KC_V_KC_N__vb] = COMBO(KC_V_KC_N_, KC_NO),
        [KC_V_KC_P__vq] = COMBO(KC_V_KC_P_, KC_NO),
        [KC_V_KC_O__vw] = COMBO(KC_V_KC_O_, KC_NO),
        [KC_V_KC_I__ve] = COMBO(KC_V_KC_I_, KC_NO),
        [KC_V_KC_U__vr] = COMBO(KC_V_KC_U_, KC_NO),
        [KC_V_KC_Y__vt] = COMBO(KC_V_KC_Y_, KC_NO),
        [KC_V_KC_I_KC_J__vy] = COMBO(KC_V_KC_I_KC_J_, KC_NO),
        [KC_V_KC_U_KC_I__vu] = COMBO(KC_V_KC_U_KC_I_, KC_NO),
        [KC_V_KC_I_KC_O__vi] = COMBO(KC_V_KC_I_KC_O_, KC_NO),
        [KC_V_KC_U_KC_O__vo] = COMBO(KC_V_KC_U_KC_O_, KC_NO),
        [KC_V_KC_U_KC_P__vp] = COMBO(KC_V_KC_U_KC_P_, KC_NO),
        [KC_V_KC_J_KC_O__vh] = COMBO(KC_V_KC_J_KC_O_, KC_NO),
        [KC_V_KC_J_KC_K__vj] = COMBO(KC_V_KC_J_KC_K_, KC_NO),
        [KC_V_KC_K_KC_L__vk] = COMBO(KC_V_KC_K_KC_L_, KC_NO),
        [KC_V_KC_J_KC_L__vl] = COMBO(KC_V_KC_J_KC_L_, KC_NO),
        [KC_V_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_V_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_V_KC_L_KC_COMMA__vn] = COMBO(KC_V_KC_L_KC_COMMA_, KC_NO),
        [KC_V_KC_M_KC_COMMA__vm] = COMBO(KC_V_KC_M_KC_COMMA_, KC_NO),
        [KC_V_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_V_KC_COMMA_KC_DOT_, KC_NO),
        [KC_V_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_V_KC_M_KC_DOT_, KC_NO),
        [KC_V_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_V_KC_M_KC_SLASH_, KC_NO),
        [KC_V_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_V_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_V_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_V_KC_DOT_KC_SLASH_, KC_NO),
        [KC_V_KC_N_KC_M__nodisplaychar] = COMBO(KC_V_KC_N_KC_M_, KC_NO),
        [KC_V_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_V_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_B_KC_SEMICOLON__ba] = COMBO(KC_B_KC_SEMICOLON_, KC_NO),
        [KC_B_KC_L__bs] = COMBO(KC_B_KC_L_, KC_NO),
        [KC_B_KC_K__bd] = COMBO(KC_B_KC_K_, KC_NO),
        [KC_B_KC_J__bf] = COMBO(KC_B_KC_J_, KC_NO),
        [KC_B_KC_H__bg] = COMBO(KC_B_KC_H_, KC_NO),
        [KC_B_KC_SLASH__bz] = COMBO(KC_B_KC_SLASH_, KC_NO),
        [KC_B_KC_DOT__bx] = COMBO(KC_B_KC_DOT_, KC_NO),
        [KC_B_KC_COMMA__bc] = COMBO(KC_B_KC_COMMA_, KC_NO),
        [KC_B_KC_M__bv] = COMBO(KC_B_KC_M_, KC_NO),
        [KC_B_KC_N__bb] = COMBO(KC_B_KC_N_, KC_NO),
        [KC_B_KC_P__bq] = COMBO(KC_B_KC_P_, KC_NO),
        [KC_B_KC_O__bw] = COMBO(KC_B_KC_O_, KC_NO),
        [KC_B_KC_I__be] = COMBO(KC_B_KC_I_, KC_NO),
        [KC_B_KC_U__br] = COMBO(KC_B_KC_U_, KC_NO),
        [KC_B_KC_Y__bt] = COMBO(KC_B_KC_Y_, KC_NO),
        [KC_B_KC_I_KC_J__by] = COMBO(KC_B_KC_I_KC_J_, KC_NO),
        [KC_B_KC_U_KC_I__bu] = COMBO(KC_B_KC_U_KC_I_, KC_NO),
        [KC_B_KC_I_KC_O__bi] = COMBO(KC_B_KC_I_KC_O_, KC_NO),
        [KC_B_KC_U_KC_O__bo] = COMBO(KC_B_KC_U_KC_O_, KC_NO),
        [KC_B_KC_U_KC_P__bp] = COMBO(KC_B_KC_U_KC_P_, KC_NO),
        [KC_B_KC_J_KC_O__bh] = COMBO(KC_B_KC_J_KC_O_, KC_NO),
        [KC_B_KC_J_KC_K__bj] = COMBO(KC_B_KC_J_KC_K_, KC_NO),
        [KC_B_KC_K_KC_L__bk] = COMBO(KC_B_KC_K_KC_L_, KC_NO),
        [KC_B_KC_J_KC_L__bl] = COMBO(KC_B_KC_J_KC_L_, KC_NO),
        [KC_B_KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_B_KC_L_KC_SEMICOLON_, KC_NO),
        [KC_B_KC_L_KC_COMMA__bn] = COMBO(KC_B_KC_L_KC_COMMA_, KC_NO),
        [KC_B_KC_M_KC_COMMA__bm] = COMBO(KC_B_KC_M_KC_COMMA_, KC_NO),
        [KC_B_KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_B_KC_COMMA_KC_DOT_, KC_NO),
        [KC_B_KC_M_KC_DOT__nodisplaychar] = COMBO(KC_B_KC_M_KC_DOT_, KC_NO),
        [KC_B_KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_B_KC_M_KC_SLASH_, KC_NO),
        [KC_B_KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_B_KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_B_KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_B_KC_DOT_KC_SLASH_, KC_NO),
        [KC_B_KC_N_KC_M__nodisplaychar] = COMBO(KC_B_KC_N_KC_M_, KC_NO),
        [KC_B_KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_B_KC_J_KC_SEMICOLON_, KC_NO),
        [KC_W_KC_F__h] = COMBO(KC_W_KC_F_, KC_NO),
        [KC_D_KC_F__j] = COMBO(KC_D_KC_F_, KC_NO),
        [KC_S_KC_D__k] = COMBO(KC_S_KC_D_, KC_NO),
        [KC_S_KC_F__l] = COMBO(KC_S_KC_F_, KC_NO),
        [KC_A_KC_F__nodisplaychar] = COMBO(KC_A_KC_F_, KC_NO),
        [KC_A_KC_S__nodisplaychar] = COMBO(KC_A_KC_S_, KC_NO),
        [KC_S_KC_C__n] = COMBO(KC_S_KC_C_, KC_NO),
        [KC_C_KC_V__m] = COMBO(KC_C_KC_V_, KC_NO),
        [KC_X_KC_C__nodisplaychar] = COMBO(KC_X_KC_C_, KC_NO),
        [KC_A_KC_T__nodisplaychar] = COMBO(KC_A_KC_T_, KC_NO),
        [KC_X_KC_V__nodisplaychar] = COMBO(KC_X_KC_V_, KC_NO),
        [KC_Z_KC_V__nodisplaychar] = COMBO(KC_Z_KC_V_, KC_NO),
        [KC_Z_KC_X__nodisplaychar] = COMBO(KC_Z_KC_X_, KC_NO),
        [KC_E_KC_F__y] = COMBO(KC_E_KC_F_, KC_NO),
        [KC_E_KC_R__u] = COMBO(KC_E_KC_R_, KC_NO),
        [KC_W_KC_E__i] = COMBO(KC_W_KC_E_, KC_NO),
        [KC_W_KC_R__o] = COMBO(KC_W_KC_R_, KC_NO),
        [KC_R_KC_Q__p] = COMBO(KC_R_KC_Q_, KC_NO),
        [KC_I_KC_J__y] = COMBO(KC_I_KC_J_, KC_NO),
        [KC_U_KC_I__u] = COMBO(KC_U_KC_I_, KC_NO),
        [KC_I_KC_O__i] = COMBO(KC_I_KC_O_, KC_NO),
        [KC_U_KC_O__o] = COMBO(KC_U_KC_O_, KC_NO),
        [KC_U_KC_P__p] = COMBO(KC_U_KC_P_, KC_NO),
        [KC_J_KC_O__h] = COMBO(KC_J_KC_O_, KC_NO),
        [KC_J_KC_K__j] = COMBO(KC_J_KC_K_, KC_NO),
        [KC_K_KC_L__k] = COMBO(KC_K_KC_L_, KC_NO),
        [KC_J_KC_L__l] = COMBO(KC_J_KC_L_, KC_NO),
        [KC_L_KC_SEMICOLON__nodisplaychar] = COMBO(KC_L_KC_SEMICOLON_, KC_NO),
        [KC_L_KC_COMMA__n] = COMBO(KC_L_KC_COMMA_, KC_NO),
        [KC_M_KC_COMMA__m] = COMBO(KC_M_KC_COMMA_, KC_NO),
        [KC_COMMA_KC_DOT__nodisplaychar] = COMBO(KC_COMMA_KC_DOT_, KC_NO),
        [KC_M_KC_DOT__nodisplaychar] = COMBO(KC_M_KC_DOT_, KC_NO),
        [KC_M_KC_SLASH__nodisplaychar] = COMBO(KC_M_KC_SLASH_, KC_NO),
        [KC_SEMICOLON_KC_Y__nodisplaychar] = COMBO(KC_SEMICOLON_KC_Y_, KC_NO),
        [KC_DOT_KC_SLASH__nodisplaychar] = COMBO(KC_DOT_KC_SLASH_, KC_NO),
        [KC_N_KC_M__nodisplaychar] = COMBO(KC_N_KC_M_, KC_NO),
        [KC_J_KC_SEMICOLON__nodisplaychar] = COMBO(KC_J_KC_SEMICOLON_, KC_NO),
    };

    // 自定义处理逻辑（可选）
    void process_combo_event(uint16_t combo_index, bool (pressed)) {
        if (!pressed) {
        switch(combo_index) {
            case KC_W_KC_F_KC_SEMICOLON__ha : SEND_STRING_DELAY("ha",25);break;
            case KC_W_KC_F_KC_L__hs : SEND_STRING_DELAY("hs",25);break;
            case KC_W_KC_F_KC_K__hd : SEND_STRING_DELAY("hd",25);break;
            case KC_W_KC_F_KC_J__hf : SEND_STRING_DELAY("hf",25);break;
            case KC_W_KC_F_KC_H__hg : SEND_STRING_DELAY("hg",25);break;
            case KC_W_KC_F_KC_SLASH__hz : SEND_STRING_DELAY("hz",25);break;
            case KC_W_KC_F_KC_DOT__hx : SEND_STRING_DELAY("hx",25);break;
            case KC_W_KC_F_KC_COMMA__hc : SEND_STRING_DELAY("hc",25);break;
            case KC_W_KC_F_KC_M__hv : SEND_STRING_DELAY("hv",25);break;
            case KC_W_KC_F_KC_N__hb : SEND_STRING_DELAY("hb",25);break;
            case KC_W_KC_F_KC_P__hq : SEND_STRING_DELAY("hq",25);break;
            case KC_W_KC_F_KC_O__hw : SEND_STRING_DELAY("hw",25);break;
            case KC_W_KC_F_KC_I__he : SEND_STRING_DELAY("he",25);break;
            case KC_W_KC_F_KC_U__hr : SEND_STRING_DELAY("hr",25);break;
            case KC_W_KC_F_KC_Y__ht : SEND_STRING_DELAY("ht",25);break;
            case KC_W_KC_F_KC_I_KC_J__hy : SEND_STRING_DELAY("hy",25);break;
            case KC_W_KC_F_KC_U_KC_I__hu : SEND_STRING_DELAY("hu",25);break;
            case KC_W_KC_F_KC_I_KC_O__hi : SEND_STRING_DELAY("hi",25);break;
            case KC_W_KC_F_KC_U_KC_O__ho : SEND_STRING_DELAY("ho",25);break;
            case KC_W_KC_F_KC_U_KC_P__hp : SEND_STRING_DELAY("hp",25);break;
            case KC_W_KC_F_KC_J_KC_O__hh : SEND_STRING_DELAY("hh",25);break;
            case KC_W_KC_F_KC_J_KC_K__hj : SEND_STRING_DELAY("hj",25);break;
            case KC_W_KC_F_KC_K_KC_L__hk : SEND_STRING_DELAY("hk",25);break;
            case KC_W_KC_F_KC_J_KC_L__hl : SEND_STRING_DELAY("hl",25);break;
            case KC_W_KC_F_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("h:",25);break;
            case KC_W_KC_F_KC_L_KC_COMMA__hn : SEND_STRING_DELAY("hn",25);break;
            case KC_W_KC_F_KC_M_KC_COMMA__hm : SEND_STRING_DELAY("hm",25);break;
            case KC_W_KC_F_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("h,",25);break;
            case KC_W_KC_F_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("h.",25);break;
            case KC_W_KC_F_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("h/",25);break;
            case KC_W_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("h>",25);break;
            case KC_W_KC_F_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("h?",25);break;
            case KC_W_KC_F_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("h'",25);break;
            case KC_W_KC_F_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("h;",25);break;
            case KC_D_KC_F_KC_SEMICOLON__ja : SEND_STRING_DELAY("ja",25);break;
            case KC_D_KC_F_KC_L__js : SEND_STRING_DELAY("js",25);break;
            case KC_D_KC_F_KC_K__jd : SEND_STRING_DELAY("jd",25);break;
            case KC_D_KC_F_KC_J__jf : SEND_STRING_DELAY("jf",25);break;
            case KC_D_KC_F_KC_H__jg : SEND_STRING_DELAY("jg",25);break;
            case KC_D_KC_F_KC_SLASH__jz : SEND_STRING_DELAY("jz",25);break;
            case KC_D_KC_F_KC_DOT__jx : SEND_STRING_DELAY("jx",25);break;
            case KC_D_KC_F_KC_COMMA__jc : SEND_STRING_DELAY("jc",25);break;
            case KC_D_KC_F_KC_M__jv : SEND_STRING_DELAY("jv",25);break;
            case KC_D_KC_F_KC_N__jb : SEND_STRING_DELAY("jb",25);break;
            case KC_D_KC_F_KC_P__jq : SEND_STRING_DELAY("jq",25);break;
            case KC_D_KC_F_KC_O__jw : SEND_STRING_DELAY("jw",25);break;
            case KC_D_KC_F_KC_I__je : SEND_STRING_DELAY("je",25);break;
            case KC_D_KC_F_KC_U__jr : SEND_STRING_DELAY("jr",25);break;
            case KC_D_KC_F_KC_Y__jt : SEND_STRING_DELAY("jt",25);break;
            case KC_D_KC_F_KC_I_KC_J__jy : SEND_STRING_DELAY("jy",25);break;
            case KC_D_KC_F_KC_U_KC_I__ju : SEND_STRING_DELAY("ju",25);break;
            case KC_D_KC_F_KC_I_KC_O__ji : SEND_STRING_DELAY("ji",25);break;
            case KC_D_KC_F_KC_U_KC_O__jo : SEND_STRING_DELAY("jo",25);break;
            case KC_D_KC_F_KC_U_KC_P__jp : SEND_STRING_DELAY("jp",25);break;
            case KC_D_KC_F_KC_J_KC_O__jh : SEND_STRING_DELAY("jh",25);break;
            case KC_D_KC_F_KC_J_KC_K__jj : SEND_STRING_DELAY("jj",25);break;
            case KC_D_KC_F_KC_K_KC_L__jk : SEND_STRING_DELAY("jk",25);break;
            case KC_D_KC_F_KC_J_KC_L__jl : SEND_STRING_DELAY("jl",25);break;
            case KC_D_KC_F_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("j:",25);break;
            case KC_D_KC_F_KC_L_KC_COMMA__jn : SEND_STRING_DELAY("jn",25);break;
            case KC_D_KC_F_KC_M_KC_COMMA__jm : SEND_STRING_DELAY("jm",25);break;
            case KC_D_KC_F_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("j,",25);break;
            case KC_D_KC_F_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("j.",25);break;
            case KC_D_KC_F_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("j/",25);break;
            case KC_D_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("j>",25);break;
            case KC_D_KC_F_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("j?",25);break;
            case KC_D_KC_F_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("j'",25);break;
            case KC_D_KC_F_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("j;",25);break;
            case KC_S_KC_D_KC_SEMICOLON__ka : SEND_STRING_DELAY("ka",25);break;
            case KC_S_KC_D_KC_L__ks : SEND_STRING_DELAY("ks",25);break;
            case KC_S_KC_D_KC_K__kd : SEND_STRING_DELAY("kd",25);break;
            case KC_S_KC_D_KC_J__kf : SEND_STRING_DELAY("kf",25);break;
            case KC_S_KC_D_KC_H__kg : SEND_STRING_DELAY("kg",25);break;
            case KC_S_KC_D_KC_SLASH__kz : SEND_STRING_DELAY("kz",25);break;
            case KC_S_KC_D_KC_DOT__kx : SEND_STRING_DELAY("kx",25);break;
            case KC_S_KC_D_KC_COMMA__kc : SEND_STRING_DELAY("kc",25);break;
            case KC_S_KC_D_KC_M__kv : SEND_STRING_DELAY("kv",25);break;
            case KC_S_KC_D_KC_N__kb : SEND_STRING_DELAY("kb",25);break;
            case KC_S_KC_D_KC_P__kq : SEND_STRING_DELAY("kq",25);break;
            case KC_S_KC_D_KC_O__kw : SEND_STRING_DELAY("kw",25);break;
            case KC_S_KC_D_KC_I__ke : SEND_STRING_DELAY("ke",25);break;
            case KC_S_KC_D_KC_U__kr : SEND_STRING_DELAY("kr",25);break;
            case KC_S_KC_D_KC_Y__kt : SEND_STRING_DELAY("kt",25);break;
            case KC_S_KC_D_KC_I_KC_J__ky : SEND_STRING_DELAY("ky",25);break;
            case KC_S_KC_D_KC_U_KC_I__ku : SEND_STRING_DELAY("ku",25);break;
            case KC_S_KC_D_KC_I_KC_O__ki : SEND_STRING_DELAY("ki",25);break;
            case KC_S_KC_D_KC_U_KC_O__ko : SEND_STRING_DELAY("ko",25);break;
            case KC_S_KC_D_KC_U_KC_P__kp : SEND_STRING_DELAY("kp",25);break;
            case KC_S_KC_D_KC_J_KC_O__kh : SEND_STRING_DELAY("kh",25);break;
            case KC_S_KC_D_KC_J_KC_K__kj : SEND_STRING_DELAY("kj",25);break;
            case KC_S_KC_D_KC_K_KC_L__kk : SEND_STRING_DELAY("kk",25);break;
            case KC_S_KC_D_KC_J_KC_L__kl : SEND_STRING_DELAY("kl",25);break;
            case KC_S_KC_D_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("k:",25);break;
            case KC_S_KC_D_KC_L_KC_COMMA__kn : SEND_STRING_DELAY("kn",25);break;
            case KC_S_KC_D_KC_M_KC_COMMA__km : SEND_STRING_DELAY("km",25);break;
            case KC_S_KC_D_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("k,",25);break;
            case KC_S_KC_D_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("k.",25);break;
            case KC_S_KC_D_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("k/",25);break;
            case KC_S_KC_D_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("k>",25);break;
            case KC_S_KC_D_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("k?",25);break;
            case KC_S_KC_D_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("k'",25);break;
            case KC_S_KC_D_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("k;",25);break;
            case KC_S_KC_F_KC_SEMICOLON__la : SEND_STRING_DELAY("la",25);break;
            case KC_S_KC_F_KC_L__ls : SEND_STRING_DELAY("ls",25);break;
            case KC_S_KC_F_KC_K__ld : SEND_STRING_DELAY("ld",25);break;
            case KC_S_KC_F_KC_J__lf : SEND_STRING_DELAY("lf",25);break;
            case KC_S_KC_F_KC_H__lg : SEND_STRING_DELAY("lg",25);break;
            case KC_S_KC_F_KC_SLASH__lz : SEND_STRING_DELAY("lz",25);break;
            case KC_S_KC_F_KC_DOT__lx : SEND_STRING_DELAY("lx",25);break;
            case KC_S_KC_F_KC_COMMA__lc : SEND_STRING_DELAY("lc",25);break;
            case KC_S_KC_F_KC_M__lv : SEND_STRING_DELAY("lv",25);break;
            case KC_S_KC_F_KC_N__lb : SEND_STRING_DELAY("lb",25);break;
            case KC_S_KC_F_KC_P__lq : SEND_STRING_DELAY("lq",25);break;
            case KC_S_KC_F_KC_O__lw : SEND_STRING_DELAY("lw",25);break;
            case KC_S_KC_F_KC_I__le : SEND_STRING_DELAY("le",25);break;
            case KC_S_KC_F_KC_U__lr : SEND_STRING_DELAY("lr",25);break;
            case KC_S_KC_F_KC_Y__lt : SEND_STRING_DELAY("lt",25);break;
            case KC_S_KC_F_KC_I_KC_J__ly : SEND_STRING_DELAY("ly",25);break;
            case KC_S_KC_F_KC_U_KC_I__lu : SEND_STRING_DELAY("lu",25);break;
            case KC_S_KC_F_KC_I_KC_O__li : SEND_STRING_DELAY("li",25);break;
            case KC_S_KC_F_KC_U_KC_O__lo : SEND_STRING_DELAY("lo",25);break;
            case KC_S_KC_F_KC_U_KC_P__lp : SEND_STRING_DELAY("lp",25);break;
            case KC_S_KC_F_KC_J_KC_O__lh : SEND_STRING_DELAY("lh",25);break;
            case KC_S_KC_F_KC_J_KC_K__lj : SEND_STRING_DELAY("lj",25);break;
            case KC_S_KC_F_KC_K_KC_L__lk : SEND_STRING_DELAY("lk",25);break;
            case KC_S_KC_F_KC_J_KC_L__ll : SEND_STRING_DELAY("ll",25);break;
            case KC_S_KC_F_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("l:",25);break;
            case KC_S_KC_F_KC_L_KC_COMMA__ln : SEND_STRING_DELAY("ln",25);break;
            case KC_S_KC_F_KC_M_KC_COMMA__lm : SEND_STRING_DELAY("lm",25);break;
            case KC_S_KC_F_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("l,",25);break;
            case KC_S_KC_F_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("l.",25);break;
            case KC_S_KC_F_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("l/",25);break;
            case KC_S_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("l>",25);break;
            case KC_S_KC_F_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("l?",25);break;
            case KC_S_KC_F_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("l'",25);break;
            case KC_S_KC_F_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("l;",25);break;
            case KC_A_KC_F_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(";a",25);break;
            case KC_A_KC_F_KC_L__nodisplaychar : SEND_STRING_DELAY(";s",25);break;
            case KC_A_KC_F_KC_K__nodisplaychar : SEND_STRING_DELAY(";d",25);break;
            case KC_A_KC_F_KC_J__nodisplaychar : SEND_STRING_DELAY(";f",25);break;
            case KC_A_KC_F_KC_H__nodisplaychar : SEND_STRING_DELAY(";g",25);break;
            case KC_A_KC_F_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(";z",25);break;
            case KC_A_KC_F_KC_DOT__nodisplaychar : SEND_STRING_DELAY(";x",25);break;
            case KC_A_KC_F_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(";c",25);break;
            case KC_A_KC_F_KC_M__nodisplaychar : SEND_STRING_DELAY(";v",25);break;
            case KC_A_KC_F_KC_N__nodisplaychar : SEND_STRING_DELAY(";b",25);break;
            case KC_A_KC_F_KC_P__nodisplaychar : SEND_STRING_DELAY(";q",25);break;
            case KC_A_KC_F_KC_O__nodisplaychar : SEND_STRING_DELAY(";w",25);break;
            case KC_A_KC_F_KC_I__nodisplaychar : SEND_STRING_DELAY(";e",25);break;
            case KC_A_KC_F_KC_U__nodisplaychar : SEND_STRING_DELAY(";r",25);break;
            case KC_A_KC_F_KC_Y__nodisplaychar : SEND_STRING_DELAY(";t",25);break;
            case KC_A_KC_F_KC_I_KC_J__nodisplaychar : SEND_STRING_DELAY(";y",25);break;
            case KC_A_KC_F_KC_U_KC_I__nodisplaychar : SEND_STRING_DELAY(";u",25);break;
            case KC_A_KC_F_KC_I_KC_O__nodisplaychar : SEND_STRING_DELAY(";i",25);break;
            case KC_A_KC_F_KC_U_KC_O__nodisplaychar : SEND_STRING_DELAY(";o",25);break;
            case KC_A_KC_F_KC_U_KC_P__nodisplaychar : SEND_STRING_DELAY(";p",25);break;
            case KC_A_KC_F_KC_J_KC_O__nodisplaychar : SEND_STRING_DELAY(";h",25);break;
            case KC_A_KC_F_KC_J_KC_K__nodisplaychar : SEND_STRING_DELAY(";j",25);break;
            case KC_A_KC_F_KC_K_KC_L__nodisplaychar : SEND_STRING_DELAY(";k",25);break;
            case KC_A_KC_F_KC_J_KC_L__nodisplaychar : SEND_STRING_DELAY(";l",25);break;
            case KC_A_KC_F_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(";:",25);break;
            case KC_A_KC_F_KC_L_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(";n",25);break;
            case KC_A_KC_F_KC_M_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(";m",25);break;
            case KC_A_KC_F_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY(";,",25);break;
            case KC_A_KC_F_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY(";.",25);break;
            case KC_A_KC_F_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(";/",25);break;
            case KC_A_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY(";>",25);break;
            case KC_A_KC_F_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(";?",25);break;
            case KC_A_KC_F_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY(";'",25);break;
            case KC_A_KC_F_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(";;",25);break;
            case KC_A_KC_S_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(":a",25);break;
            case KC_A_KC_S_KC_L__nodisplaychar : SEND_STRING_DELAY(":s",25);break;
            case KC_A_KC_S_KC_K__nodisplaychar : SEND_STRING_DELAY(":d",25);break;
            case KC_A_KC_S_KC_J__nodisplaychar : SEND_STRING_DELAY(":f",25);break;
            case KC_A_KC_S_KC_H__nodisplaychar : SEND_STRING_DELAY(":g",25);break;
            case KC_A_KC_S_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(":z",25);break;
            case KC_A_KC_S_KC_DOT__nodisplaychar : SEND_STRING_DELAY(":x",25);break;
            case KC_A_KC_S_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(":c",25);break;
            case KC_A_KC_S_KC_M__nodisplaychar : SEND_STRING_DELAY(":v",25);break;
            case KC_A_KC_S_KC_N__nodisplaychar : SEND_STRING_DELAY(":b",25);break;
            case KC_A_KC_S_KC_P__nodisplaychar : SEND_STRING_DELAY(":q",25);break;
            case KC_A_KC_S_KC_O__nodisplaychar : SEND_STRING_DELAY(":w",25);break;
            case KC_A_KC_S_KC_I__nodisplaychar : SEND_STRING_DELAY(":e",25);break;
            case KC_A_KC_S_KC_U__nodisplaychar : SEND_STRING_DELAY(":r",25);break;
            case KC_A_KC_S_KC_Y__nodisplaychar : SEND_STRING_DELAY(":t",25);break;
            case KC_A_KC_S_KC_I_KC_J__nodisplaychar : SEND_STRING_DELAY(":y",25);break;
            case KC_A_KC_S_KC_U_KC_I__nodisplaychar : SEND_STRING_DELAY(":u",25);break;
            case KC_A_KC_S_KC_I_KC_O__nodisplaychar : SEND_STRING_DELAY(":i",25);break;
            case KC_A_KC_S_KC_U_KC_O__nodisplaychar : SEND_STRING_DELAY(":o",25);break;
            case KC_A_KC_S_KC_U_KC_P__nodisplaychar : SEND_STRING_DELAY(":p",25);break;
            case KC_A_KC_S_KC_J_KC_O__nodisplaychar : SEND_STRING_DELAY(":h",25);break;
            case KC_A_KC_S_KC_J_KC_K__nodisplaychar : SEND_STRING_DELAY(":j",25);break;
            case KC_A_KC_S_KC_K_KC_L__nodisplaychar : SEND_STRING_DELAY(":k",25);break;
            case KC_A_KC_S_KC_J_KC_L__nodisplaychar : SEND_STRING_DELAY(":l",25);break;
            case KC_A_KC_S_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("::",25);break;
            case KC_A_KC_S_KC_L_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(":n",25);break;
            case KC_A_KC_S_KC_M_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(":m",25);break;
            case KC_A_KC_S_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY(":,",25);break;
            case KC_A_KC_S_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY(":.",25);break;
            case KC_A_KC_S_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(":/",25);break;
            case KC_A_KC_S_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY(":>",25);break;
            case KC_A_KC_S_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(":?",25);break;
            case KC_A_KC_S_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY(":'",25);break;
            case KC_A_KC_S_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(":;",25);break;
            case KC_S_KC_C_KC_SEMICOLON__na : SEND_STRING_DELAY("na",25);break;
            case KC_S_KC_C_KC_L__ns : SEND_STRING_DELAY("ns",25);break;
            case KC_S_KC_C_KC_K__nd : SEND_STRING_DELAY("nd",25);break;
            case KC_S_KC_C_KC_J__nf : SEND_STRING_DELAY("nf",25);break;
            case KC_S_KC_C_KC_H__ng : SEND_STRING_DELAY("ng",25);break;
            case KC_S_KC_C_KC_SLASH__nz : SEND_STRING_DELAY("nz",25);break;
            case KC_S_KC_C_KC_DOT__nx : SEND_STRING_DELAY("nx",25);break;
            case KC_S_KC_C_KC_COMMA__nc : SEND_STRING_DELAY("nc",25);break;
            case KC_S_KC_C_KC_M__nv : SEND_STRING_DELAY("nv",25);break;
            case KC_S_KC_C_KC_N__nb : SEND_STRING_DELAY("nb",25);break;
            case KC_S_KC_C_KC_P__nq : SEND_STRING_DELAY("nq",25);break;
            case KC_S_KC_C_KC_O__nw : SEND_STRING_DELAY("nw",25);break;
            case KC_S_KC_C_KC_I__ne : SEND_STRING_DELAY("ne",25);break;
            case KC_S_KC_C_KC_U__nr : SEND_STRING_DELAY("nr",25);break;
            case KC_S_KC_C_KC_Y__nt : SEND_STRING_DELAY("nt",25);break;
            case KC_S_KC_C_KC_I_KC_J__ny : SEND_STRING_DELAY("ny",25);break;
            case KC_S_KC_C_KC_U_KC_I__nu : SEND_STRING_DELAY("nu",25);break;
            case KC_S_KC_C_KC_I_KC_O__ni : SEND_STRING_DELAY("ni",25);break;
            case KC_S_KC_C_KC_U_KC_O__no : SEND_STRING_DELAY("no",25);break;
            case KC_S_KC_C_KC_U_KC_P__np : SEND_STRING_DELAY("np",25);break;
            case KC_S_KC_C_KC_J_KC_O__nh : SEND_STRING_DELAY("nh",25);break;
            case KC_S_KC_C_KC_J_KC_K__nj : SEND_STRING_DELAY("nj",25);break;
            case KC_S_KC_C_KC_K_KC_L__nk : SEND_STRING_DELAY("nk",25);break;
            case KC_S_KC_C_KC_J_KC_L__nl : SEND_STRING_DELAY("nl",25);break;
            case KC_S_KC_C_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("n:",25);break;
            case KC_S_KC_C_KC_L_KC_COMMA__nn : SEND_STRING_DELAY("nn",25);break;
            case KC_S_KC_C_KC_M_KC_COMMA__nm : SEND_STRING_DELAY("nm",25);break;
            case KC_S_KC_C_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("n,",25);break;
            case KC_S_KC_C_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("n.",25);break;
            case KC_S_KC_C_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("n/",25);break;
            case KC_S_KC_C_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("n>",25);break;
            case KC_S_KC_C_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("n?",25);break;
            case KC_S_KC_C_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("n'",25);break;
            case KC_S_KC_C_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("n;",25);break;
            case KC_C_KC_V_KC_SEMICOLON__ma : SEND_STRING_DELAY("ma",25);break;
            case KC_C_KC_V_KC_L__ms : SEND_STRING_DELAY("ms",25);break;
            case KC_C_KC_V_KC_K__md : SEND_STRING_DELAY("md",25);break;
            case KC_C_KC_V_KC_J__mf : SEND_STRING_DELAY("mf",25);break;
            case KC_C_KC_V_KC_H__mg : SEND_STRING_DELAY("mg",25);break;
            case KC_C_KC_V_KC_SLASH__mz : SEND_STRING_DELAY("mz",25);break;
            case KC_C_KC_V_KC_DOT__mx : SEND_STRING_DELAY("mx",25);break;
            case KC_C_KC_V_KC_COMMA__mc : SEND_STRING_DELAY("mc",25);break;
            case KC_C_KC_V_KC_M__mv : SEND_STRING_DELAY("mv",25);break;
            case KC_C_KC_V_KC_N__mb : SEND_STRING_DELAY("mb",25);break;
            case KC_C_KC_V_KC_P__mq : SEND_STRING_DELAY("mq",25);break;
            case KC_C_KC_V_KC_O__mw : SEND_STRING_DELAY("mw",25);break;
            case KC_C_KC_V_KC_I__me : SEND_STRING_DELAY("me",25);break;
            case KC_C_KC_V_KC_U__mr : SEND_STRING_DELAY("mr",25);break;
            case KC_C_KC_V_KC_Y__mt : SEND_STRING_DELAY("mt",25);break;
            case KC_C_KC_V_KC_I_KC_J__my : SEND_STRING_DELAY("my",25);break;
            case KC_C_KC_V_KC_U_KC_I__mu : SEND_STRING_DELAY("mu",25);break;
            case KC_C_KC_V_KC_I_KC_O__mi : SEND_STRING_DELAY("mi",25);break;
            case KC_C_KC_V_KC_U_KC_O__mo : SEND_STRING_DELAY("mo",25);break;
            case KC_C_KC_V_KC_U_KC_P__mp : SEND_STRING_DELAY("mp",25);break;
            case KC_C_KC_V_KC_J_KC_O__mh : SEND_STRING_DELAY("mh",25);break;
            case KC_C_KC_V_KC_J_KC_K__mj : SEND_STRING_DELAY("mj",25);break;
            case KC_C_KC_V_KC_K_KC_L__mk : SEND_STRING_DELAY("mk",25);break;
            case KC_C_KC_V_KC_J_KC_L__ml : SEND_STRING_DELAY("ml",25);break;
            case KC_C_KC_V_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("m:",25);break;
            case KC_C_KC_V_KC_L_KC_COMMA__mn : SEND_STRING_DELAY("mn",25);break;
            case KC_C_KC_V_KC_M_KC_COMMA__mm : SEND_STRING_DELAY("mm",25);break;
            case KC_C_KC_V_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("m,",25);break;
            case KC_C_KC_V_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("m.",25);break;
            case KC_C_KC_V_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("m/",25);break;
            case KC_C_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("m>",25);break;
            case KC_C_KC_V_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("m?",25);break;
            case KC_C_KC_V_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("m'",25);break;
            case KC_C_KC_V_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("m;",25);break;
            case KC_X_KC_C_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(",a",25);break;
            case KC_X_KC_C_KC_L__nodisplaychar : SEND_STRING_DELAY(",s",25);break;
            case KC_X_KC_C_KC_K__nodisplaychar : SEND_STRING_DELAY(",d",25);break;
            case KC_X_KC_C_KC_J__nodisplaychar : SEND_STRING_DELAY(",f",25);break;
            case KC_X_KC_C_KC_H__nodisplaychar : SEND_STRING_DELAY(",g",25);break;
            case KC_X_KC_C_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(",z",25);break;
            case KC_X_KC_C_KC_DOT__nodisplaychar : SEND_STRING_DELAY(",x",25);break;
            case KC_X_KC_C_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(",c",25);break;
            case KC_X_KC_C_KC_M__nodisplaychar : SEND_STRING_DELAY(",v",25);break;
            case KC_X_KC_C_KC_N__nodisplaychar : SEND_STRING_DELAY(",b",25);break;
            case KC_X_KC_C_KC_P__nodisplaychar : SEND_STRING_DELAY(",q",25);break;
            case KC_X_KC_C_KC_O__nodisplaychar : SEND_STRING_DELAY(",w",25);break;
            case KC_X_KC_C_KC_I__nodisplaychar : SEND_STRING_DELAY(",e",25);break;
            case KC_X_KC_C_KC_U__nodisplaychar : SEND_STRING_DELAY(",r",25);break;
            case KC_X_KC_C_KC_Y__nodisplaychar : SEND_STRING_DELAY(",t",25);break;
            case KC_X_KC_C_KC_I_KC_J__nodisplaychar : SEND_STRING_DELAY(",y",25);break;
            case KC_X_KC_C_KC_U_KC_I__nodisplaychar : SEND_STRING_DELAY(",u",25);break;
            case KC_X_KC_C_KC_I_KC_O__nodisplaychar : SEND_STRING_DELAY(",i",25);break;
            case KC_X_KC_C_KC_U_KC_O__nodisplaychar : SEND_STRING_DELAY(",o",25);break;
            case KC_X_KC_C_KC_U_KC_P__nodisplaychar : SEND_STRING_DELAY(",p",25);break;
            case KC_X_KC_C_KC_J_KC_O__nodisplaychar : SEND_STRING_DELAY(",h",25);break;
            case KC_X_KC_C_KC_J_KC_K__nodisplaychar : SEND_STRING_DELAY(",j",25);break;
            case KC_X_KC_C_KC_K_KC_L__nodisplaychar : SEND_STRING_DELAY(",k",25);break;
            case KC_X_KC_C_KC_J_KC_L__nodisplaychar : SEND_STRING_DELAY(",l",25);break;
            case KC_X_KC_C_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(",:",25);break;
            case KC_X_KC_C_KC_L_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(",n",25);break;
            case KC_X_KC_C_KC_M_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(",m",25);break;
            case KC_X_KC_C_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY(",,",25);break;
            case KC_X_KC_C_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY(",.",25);break;
            case KC_X_KC_C_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(",/",25);break;
            case KC_X_KC_C_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY(",>",25);break;
            case KC_X_KC_C_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(",?",25);break;
            case KC_X_KC_C_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY(",'",25);break;
            case KC_X_KC_C_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(",;",25);break;
            case KC_A_KC_T_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("<a",25);break;
            case KC_A_KC_T_KC_L__nodisplaychar : SEND_STRING_DELAY("<s",25);break;
            case KC_A_KC_T_KC_K__nodisplaychar : SEND_STRING_DELAY("<d",25);break;
            case KC_A_KC_T_KC_J__nodisplaychar : SEND_STRING_DELAY("<f",25);break;
            case KC_A_KC_T_KC_H__nodisplaychar : SEND_STRING_DELAY("<g",25);break;
            case KC_A_KC_T_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("<z",25);break;
            case KC_A_KC_T_KC_DOT__nodisplaychar : SEND_STRING_DELAY("<x",25);break;
            case KC_A_KC_T_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("<c",25);break;
            case KC_A_KC_T_KC_M__nodisplaychar : SEND_STRING_DELAY("<v",25);break;
            case KC_A_KC_T_KC_N__nodisplaychar : SEND_STRING_DELAY("<b",25);break;
            case KC_A_KC_T_KC_P__nodisplaychar : SEND_STRING_DELAY("<q",25);break;
            case KC_A_KC_T_KC_O__nodisplaychar : SEND_STRING_DELAY("<w",25);break;
            case KC_A_KC_T_KC_I__nodisplaychar : SEND_STRING_DELAY("<e",25);break;
            case KC_A_KC_T_KC_U__nodisplaychar : SEND_STRING_DELAY("<r",25);break;
            case KC_A_KC_T_KC_Y__nodisplaychar : SEND_STRING_DELAY("<t",25);break;
            case KC_A_KC_T_KC_I_KC_J__nodisplaychar : SEND_STRING_DELAY("<y",25);break;
            case KC_A_KC_T_KC_U_KC_I__nodisplaychar : SEND_STRING_DELAY("<u",25);break;
            case KC_A_KC_T_KC_I_KC_O__nodisplaychar : SEND_STRING_DELAY("<i",25);break;
            case KC_A_KC_T_KC_U_KC_O__nodisplaychar : SEND_STRING_DELAY("<o",25);break;
            case KC_A_KC_T_KC_U_KC_P__nodisplaychar : SEND_STRING_DELAY("<p",25);break;
            case KC_A_KC_T_KC_J_KC_O__nodisplaychar : SEND_STRING_DELAY("<h",25);break;
            case KC_A_KC_T_KC_J_KC_K__nodisplaychar : SEND_STRING_DELAY("<j",25);break;
            case KC_A_KC_T_KC_K_KC_L__nodisplaychar : SEND_STRING_DELAY("<k",25);break;
            case KC_A_KC_T_KC_J_KC_L__nodisplaychar : SEND_STRING_DELAY("<l",25);break;
            case KC_A_KC_T_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("<:",25);break;
            case KC_A_KC_T_KC_L_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("<n",25);break;
            case KC_A_KC_T_KC_M_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("<m",25);break;
            case KC_A_KC_T_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("<,",25);break;
            case KC_A_KC_T_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("<.",25);break;
            case KC_A_KC_T_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("</",25);break;
            case KC_A_KC_T_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("<>",25);break;
            case KC_A_KC_T_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("<?",25);break;
            case KC_A_KC_T_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("<'",25);break;
            case KC_A_KC_T_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("<;",25);break;
            case KC_X_KC_V_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(".a",25);break;
            case KC_X_KC_V_KC_L__nodisplaychar : SEND_STRING_DELAY(".s",25);break;
            case KC_X_KC_V_KC_K__nodisplaychar : SEND_STRING_DELAY(".d",25);break;
            case KC_X_KC_V_KC_J__nodisplaychar : SEND_STRING_DELAY(".f",25);break;
            case KC_X_KC_V_KC_H__nodisplaychar : SEND_STRING_DELAY(".g",25);break;
            case KC_X_KC_V_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(".z",25);break;
            case KC_X_KC_V_KC_DOT__nodisplaychar : SEND_STRING_DELAY(".x",25);break;
            case KC_X_KC_V_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(".c",25);break;
            case KC_X_KC_V_KC_M__nodisplaychar : SEND_STRING_DELAY(".v",25);break;
            case KC_X_KC_V_KC_N__nodisplaychar : SEND_STRING_DELAY(".b",25);break;
            case KC_X_KC_V_KC_P__nodisplaychar : SEND_STRING_DELAY(".q",25);break;
            case KC_X_KC_V_KC_O__nodisplaychar : SEND_STRING_DELAY(".w",25);break;
            case KC_X_KC_V_KC_I__nodisplaychar : SEND_STRING_DELAY(".e",25);break;
            case KC_X_KC_V_KC_U__nodisplaychar : SEND_STRING_DELAY(".r",25);break;
            case KC_X_KC_V_KC_Y__nodisplaychar : SEND_STRING_DELAY(".t",25);break;
            case KC_X_KC_V_KC_I_KC_J__nodisplaychar : SEND_STRING_DELAY(".y",25);break;
            case KC_X_KC_V_KC_U_KC_I__nodisplaychar : SEND_STRING_DELAY(".u",25);break;
            case KC_X_KC_V_KC_I_KC_O__nodisplaychar : SEND_STRING_DELAY(".i",25);break;
            case KC_X_KC_V_KC_U_KC_O__nodisplaychar : SEND_STRING_DELAY(".o",25);break;
            case KC_X_KC_V_KC_U_KC_P__nodisplaychar : SEND_STRING_DELAY(".p",25);break;
            case KC_X_KC_V_KC_J_KC_O__nodisplaychar : SEND_STRING_DELAY(".h",25);break;
            case KC_X_KC_V_KC_J_KC_K__nodisplaychar : SEND_STRING_DELAY(".j",25);break;
            case KC_X_KC_V_KC_K_KC_L__nodisplaychar : SEND_STRING_DELAY(".k",25);break;
            case KC_X_KC_V_KC_J_KC_L__nodisplaychar : SEND_STRING_DELAY(".l",25);break;
            case KC_X_KC_V_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(".:",25);break;
            case KC_X_KC_V_KC_L_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(".n",25);break;
            case KC_X_KC_V_KC_M_KC_COMMA__nodisplaychar : SEND_STRING_DELAY(".m",25);break;
            case KC_X_KC_V_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY(".,",25);break;
            case KC_X_KC_V_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("..",25);break;
            case KC_X_KC_V_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("./",25);break;
            case KC_X_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY(".>",25);break;
            case KC_X_KC_V_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY(".?",25);break;
            case KC_X_KC_V_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY(".'",25);break;
            case KC_X_KC_V_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(".;",25);break;
            case KC_Z_KC_V_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("/a",25);break;
            case KC_Z_KC_V_KC_L__nodisplaychar : SEND_STRING_DELAY("/s",25);break;
            case KC_Z_KC_V_KC_K__nodisplaychar : SEND_STRING_DELAY("/d",25);break;
            case KC_Z_KC_V_KC_J__nodisplaychar : SEND_STRING_DELAY("/f",25);break;
            case KC_Z_KC_V_KC_H__nodisplaychar : SEND_STRING_DELAY("/g",25);break;
            case KC_Z_KC_V_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("/z",25);break;
            case KC_Z_KC_V_KC_DOT__nodisplaychar : SEND_STRING_DELAY("/x",25);break;
            case KC_Z_KC_V_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("/c",25);break;
            case KC_Z_KC_V_KC_M__nodisplaychar : SEND_STRING_DELAY("/v",25);break;
            case KC_Z_KC_V_KC_N__nodisplaychar : SEND_STRING_DELAY("/b",25);break;
            case KC_Z_KC_V_KC_P__nodisplaychar : SEND_STRING_DELAY("/q",25);break;
            case KC_Z_KC_V_KC_O__nodisplaychar : SEND_STRING_DELAY("/w",25);break;
            case KC_Z_KC_V_KC_I__nodisplaychar : SEND_STRING_DELAY("/e",25);break;
            case KC_Z_KC_V_KC_U__nodisplaychar : SEND_STRING_DELAY("/r",25);break;
            case KC_Z_KC_V_KC_Y__nodisplaychar : SEND_STRING_DELAY("/t",25);break;
            case KC_Z_KC_V_KC_I_KC_J__nodisplaychar : SEND_STRING_DELAY("/y",25);break;
            case KC_Z_KC_V_KC_U_KC_I__nodisplaychar : SEND_STRING_DELAY("/u",25);break;
            case KC_Z_KC_V_KC_I_KC_O__nodisplaychar : SEND_STRING_DELAY("/i",25);break;
            case KC_Z_KC_V_KC_U_KC_O__nodisplaychar : SEND_STRING_DELAY("/o",25);break;
            case KC_Z_KC_V_KC_U_KC_P__nodisplaychar : SEND_STRING_DELAY("/p",25);break;
            case KC_Z_KC_V_KC_J_KC_O__nodisplaychar : SEND_STRING_DELAY("/h",25);break;
            case KC_Z_KC_V_KC_J_KC_K__nodisplaychar : SEND_STRING_DELAY("/j",25);break;
            case KC_Z_KC_V_KC_K_KC_L__nodisplaychar : SEND_STRING_DELAY("/k",25);break;
            case KC_Z_KC_V_KC_J_KC_L__nodisplaychar : SEND_STRING_DELAY("/l",25);break;
            case KC_Z_KC_V_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("/:",25);break;
            case KC_Z_KC_V_KC_L_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("/n",25);break;
            case KC_Z_KC_V_KC_M_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("/m",25);break;
            case KC_Z_KC_V_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("/,",25);break;
            case KC_Z_KC_V_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("/.",25);break;
            case KC_Z_KC_V_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("//",25);break;
            case KC_Z_KC_V_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("/>",25);break;
            case KC_Z_KC_V_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("/?",25);break;
            case KC_Z_KC_V_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("/'",25);break;
            case KC_Z_KC_V_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("/;",25);break;
            case KC_Z_KC_X_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("?a",25);break;
            case KC_Z_KC_X_KC_L__nodisplaychar : SEND_STRING_DELAY("?s",25);break;
            case KC_Z_KC_X_KC_K__nodisplaychar : SEND_STRING_DELAY("?d",25);break;
            case KC_Z_KC_X_KC_J__nodisplaychar : SEND_STRING_DELAY("?f",25);break;
            case KC_Z_KC_X_KC_H__nodisplaychar : SEND_STRING_DELAY("?g",25);break;
            case KC_Z_KC_X_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("?z",25);break;
            case KC_Z_KC_X_KC_DOT__nodisplaychar : SEND_STRING_DELAY("?x",25);break;
            case KC_Z_KC_X_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("?c",25);break;
            case KC_Z_KC_X_KC_M__nodisplaychar : SEND_STRING_DELAY("?v",25);break;
            case KC_Z_KC_X_KC_N__nodisplaychar : SEND_STRING_DELAY("?b",25);break;
            case KC_Z_KC_X_KC_P__nodisplaychar : SEND_STRING_DELAY("?q",25);break;
            case KC_Z_KC_X_KC_O__nodisplaychar : SEND_STRING_DELAY("?w",25);break;
            case KC_Z_KC_X_KC_I__nodisplaychar : SEND_STRING_DELAY("?e",25);break;
            case KC_Z_KC_X_KC_U__nodisplaychar : SEND_STRING_DELAY("?r",25);break;
            case KC_Z_KC_X_KC_Y__nodisplaychar : SEND_STRING_DELAY("?t",25);break;
            case KC_Z_KC_X_KC_I_KC_J__nodisplaychar : SEND_STRING_DELAY("?y",25);break;
            case KC_Z_KC_X_KC_U_KC_I__nodisplaychar : SEND_STRING_DELAY("?u",25);break;
            case KC_Z_KC_X_KC_I_KC_O__nodisplaychar : SEND_STRING_DELAY("?i",25);break;
            case KC_Z_KC_X_KC_U_KC_O__nodisplaychar : SEND_STRING_DELAY("?o",25);break;
            case KC_Z_KC_X_KC_U_KC_P__nodisplaychar : SEND_STRING_DELAY("?p",25);break;
            case KC_Z_KC_X_KC_J_KC_O__nodisplaychar : SEND_STRING_DELAY("?h",25);break;
            case KC_Z_KC_X_KC_J_KC_K__nodisplaychar : SEND_STRING_DELAY("?j",25);break;
            case KC_Z_KC_X_KC_K_KC_L__nodisplaychar : SEND_STRING_DELAY("?k",25);break;
            case KC_Z_KC_X_KC_J_KC_L__nodisplaychar : SEND_STRING_DELAY("?l",25);break;
            case KC_Z_KC_X_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("?:",25);break;
            case KC_Z_KC_X_KC_L_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("?n",25);break;
            case KC_Z_KC_X_KC_M_KC_COMMA__nodisplaychar : SEND_STRING_DELAY("?m",25);break;
            case KC_Z_KC_X_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("?,",25);break;
            case KC_Z_KC_X_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("?.",25);break;
            case KC_Z_KC_X_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("?/",25);break;
            case KC_Z_KC_X_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("?>",25);break;
            case KC_Z_KC_X_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("??",25);break;
            case KC_Z_KC_X_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("?'",25);break;
            case KC_Z_KC_X_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("?;",25);break;
            case KC_E_KC_F_KC_SEMICOLON__ya : SEND_STRING_DELAY("ya",25);break;
            case KC_E_KC_F_KC_L__ys : SEND_STRING_DELAY("ys",25);break;
            case KC_E_KC_F_KC_K__yd : SEND_STRING_DELAY("yd",25);break;
            case KC_E_KC_F_KC_J__yf : SEND_STRING_DELAY("yf",25);break;
            case KC_E_KC_F_KC_H__yg : SEND_STRING_DELAY("yg",25);break;
            case KC_E_KC_F_KC_SLASH__yz : SEND_STRING_DELAY("yz",25);break;
            case KC_E_KC_F_KC_DOT__yx : SEND_STRING_DELAY("yx",25);break;
            case KC_E_KC_F_KC_COMMA__yc : SEND_STRING_DELAY("yc",25);break;
            case KC_E_KC_F_KC_M__yv : SEND_STRING_DELAY("yv",25);break;
            case KC_E_KC_F_KC_N__yb : SEND_STRING_DELAY("yb",25);break;
            case KC_E_KC_F_KC_P__yq : SEND_STRING_DELAY("yq",25);break;
            case KC_E_KC_F_KC_O__yw : SEND_STRING_DELAY("yw",25);break;
            case KC_E_KC_F_KC_I__ye : SEND_STRING_DELAY("ye",25);break;
            case KC_E_KC_F_KC_U__yr : SEND_STRING_DELAY("yr",25);break;
            case KC_E_KC_F_KC_Y__yt : SEND_STRING_DELAY("yt",25);break;
            case KC_E_KC_F_KC_I_KC_J__yy : SEND_STRING_DELAY("yy",25);break;
            case KC_E_KC_F_KC_U_KC_I__yu : SEND_STRING_DELAY("yu",25);break;
            case KC_E_KC_F_KC_I_KC_O__yi : SEND_STRING_DELAY("yi",25);break;
            case KC_E_KC_F_KC_U_KC_O__yo : SEND_STRING_DELAY("yo",25);break;
            case KC_E_KC_F_KC_U_KC_P__yp : SEND_STRING_DELAY("yp",25);break;
            case KC_E_KC_F_KC_J_KC_O__yh : SEND_STRING_DELAY("yh",25);break;
            case KC_E_KC_F_KC_J_KC_K__yj : SEND_STRING_DELAY("yj",25);break;
            case KC_E_KC_F_KC_K_KC_L__yk : SEND_STRING_DELAY("yk",25);break;
            case KC_E_KC_F_KC_J_KC_L__yl : SEND_STRING_DELAY("yl",25);break;
            case KC_E_KC_F_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("y:",25);break;
            case KC_E_KC_F_KC_L_KC_COMMA__yn : SEND_STRING_DELAY("yn",25);break;
            case KC_E_KC_F_KC_M_KC_COMMA__ym : SEND_STRING_DELAY("ym",25);break;
            case KC_E_KC_F_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("y,",25);break;
            case KC_E_KC_F_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("y.",25);break;
            case KC_E_KC_F_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("y/",25);break;
            case KC_E_KC_F_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("y>",25);break;
            case KC_E_KC_F_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("y?",25);break;
            case KC_E_KC_F_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("y'",25);break;
            case KC_E_KC_F_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("y;",25);break;
            case KC_E_KC_R_KC_SEMICOLON__ua : SEND_STRING_DELAY("ua",25);break;
            case KC_E_KC_R_KC_L__us : SEND_STRING_DELAY("us",25);break;
            case KC_E_KC_R_KC_K__ud : SEND_STRING_DELAY("ud",25);break;
            case KC_E_KC_R_KC_J__uf : SEND_STRING_DELAY("uf",25);break;
            case KC_E_KC_R_KC_H__ug : SEND_STRING_DELAY("ug",25);break;
            case KC_E_KC_R_KC_SLASH__uz : SEND_STRING_DELAY("uz",25);break;
            case KC_E_KC_R_KC_DOT__ux : SEND_STRING_DELAY("ux",25);break;
            case KC_E_KC_R_KC_COMMA__uc : SEND_STRING_DELAY("uc",25);break;
            case KC_E_KC_R_KC_M__uv : SEND_STRING_DELAY("uv",25);break;
            case KC_E_KC_R_KC_N__ub : SEND_STRING_DELAY("ub",25);break;
            case KC_E_KC_R_KC_P__uq : SEND_STRING_DELAY("uq",25);break;
            case KC_E_KC_R_KC_O__uw : SEND_STRING_DELAY("uw",25);break;
            case KC_E_KC_R_KC_I__ue : SEND_STRING_DELAY("ue",25);break;
            case KC_E_KC_R_KC_U__ur : SEND_STRING_DELAY("ur",25);break;
            case KC_E_KC_R_KC_Y__ut : SEND_STRING_DELAY("ut",25);break;
            case KC_E_KC_R_KC_I_KC_J__uy : SEND_STRING_DELAY("uy",25);break;
            case KC_E_KC_R_KC_U_KC_I__uu : SEND_STRING_DELAY("uu",25);break;
            case KC_E_KC_R_KC_I_KC_O__ui : SEND_STRING_DELAY("ui",25);break;
            case KC_E_KC_R_KC_U_KC_O__uo : SEND_STRING_DELAY("uo",25);break;
            case KC_E_KC_R_KC_U_KC_P__up : SEND_STRING_DELAY("up",25);break;
            case KC_E_KC_R_KC_J_KC_O__uh : SEND_STRING_DELAY("uh",25);break;
            case KC_E_KC_R_KC_J_KC_K__uj : SEND_STRING_DELAY("uj",25);break;
            case KC_E_KC_R_KC_K_KC_L__uk : SEND_STRING_DELAY("uk",25);break;
            case KC_E_KC_R_KC_J_KC_L__ul : SEND_STRING_DELAY("ul",25);break;
            case KC_E_KC_R_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("u:",25);break;
            case KC_E_KC_R_KC_L_KC_COMMA__un : SEND_STRING_DELAY("un",25);break;
            case KC_E_KC_R_KC_M_KC_COMMA__um : SEND_STRING_DELAY("um",25);break;
            case KC_E_KC_R_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("u,",25);break;
            case KC_E_KC_R_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("u.",25);break;
            case KC_E_KC_R_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("u/",25);break;
            case KC_E_KC_R_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("u>",25);break;
            case KC_E_KC_R_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("u?",25);break;
            case KC_E_KC_R_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("u'",25);break;
            case KC_E_KC_R_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("u;",25);break;
            case KC_W_KC_E_KC_SEMICOLON__ia : SEND_STRING_DELAY("ia",25);break;
            case KC_W_KC_E_KC_L__is : SEND_STRING_DELAY("is",25);break;
            case KC_W_KC_E_KC_K__id : SEND_STRING_DELAY("id",25);break;
            case KC_W_KC_E_KC_J__if : SEND_STRING_DELAY("if",25);break;
            case KC_W_KC_E_KC_H__ig : SEND_STRING_DELAY("ig",25);break;
            case KC_W_KC_E_KC_SLASH__iz : SEND_STRING_DELAY("iz",25);break;
            case KC_W_KC_E_KC_DOT__ix : SEND_STRING_DELAY("ix",25);break;
            case KC_W_KC_E_KC_COMMA__ic : SEND_STRING_DELAY("ic",25);break;
            case KC_W_KC_E_KC_M__iv : SEND_STRING_DELAY("iv",25);break;
            case KC_W_KC_E_KC_N__ib : SEND_STRING_DELAY("ib",25);break;
            case KC_W_KC_E_KC_P__iq : SEND_STRING_DELAY("iq",25);break;
            case KC_W_KC_E_KC_O__iw : SEND_STRING_DELAY("iw",25);break;
            case KC_W_KC_E_KC_I__ie : SEND_STRING_DELAY("ie",25);break;
            case KC_W_KC_E_KC_U__ir : SEND_STRING_DELAY("ir",25);break;
            case KC_W_KC_E_KC_Y__it : SEND_STRING_DELAY("it",25);break;
            case KC_W_KC_E_KC_I_KC_J__iy : SEND_STRING_DELAY("iy",25);break;
            case KC_W_KC_E_KC_U_KC_I__iu : SEND_STRING_DELAY("iu",25);break;
            case KC_W_KC_E_KC_I_KC_O__ii : SEND_STRING_DELAY("ii",25);break;
            case KC_W_KC_E_KC_U_KC_O__io : SEND_STRING_DELAY("io",25);break;
            case KC_W_KC_E_KC_U_KC_P__ip : SEND_STRING_DELAY("ip",25);break;
            case KC_W_KC_E_KC_J_KC_O__ih : SEND_STRING_DELAY("ih",25);break;
            case KC_W_KC_E_KC_J_KC_K__ij : SEND_STRING_DELAY("ij",25);break;
            case KC_W_KC_E_KC_K_KC_L__ik : SEND_STRING_DELAY("ik",25);break;
            case KC_W_KC_E_KC_J_KC_L__il : SEND_STRING_DELAY("il",25);break;
            case KC_W_KC_E_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("i:",25);break;
            case KC_W_KC_E_KC_L_KC_COMMA__in : SEND_STRING_DELAY("in",25);break;
            case KC_W_KC_E_KC_M_KC_COMMA__im : SEND_STRING_DELAY("im",25);break;
            case KC_W_KC_E_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("i,",25);break;
            case KC_W_KC_E_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("i.",25);break;
            case KC_W_KC_E_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("i/",25);break;
            case KC_W_KC_E_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("i>",25);break;
            case KC_W_KC_E_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("i?",25);break;
            case KC_W_KC_E_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("i'",25);break;
            case KC_W_KC_E_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("i;",25);break;
            case KC_W_KC_R_KC_SEMICOLON__oa : SEND_STRING_DELAY("oa",25);break;
            case KC_W_KC_R_KC_L__os : SEND_STRING_DELAY("os",25);break;
            case KC_W_KC_R_KC_K__od : SEND_STRING_DELAY("od",25);break;
            case KC_W_KC_R_KC_J__of : SEND_STRING_DELAY("of",25);break;
            case KC_W_KC_R_KC_H__og : SEND_STRING_DELAY("og",25);break;
            case KC_W_KC_R_KC_SLASH__oz : SEND_STRING_DELAY("oz",25);break;
            case KC_W_KC_R_KC_DOT__ox : SEND_STRING_DELAY("ox",25);break;
            case KC_W_KC_R_KC_COMMA__oc : SEND_STRING_DELAY("oc",25);break;
            case KC_W_KC_R_KC_M__ov : SEND_STRING_DELAY("ov",25);break;
            case KC_W_KC_R_KC_N__ob : SEND_STRING_DELAY("ob",25);break;
            case KC_W_KC_R_KC_P__oq : SEND_STRING_DELAY("oq",25);break;
            case KC_W_KC_R_KC_O__ow : SEND_STRING_DELAY("ow",25);break;
            case KC_W_KC_R_KC_I__oe : SEND_STRING_DELAY("oe",25);break;
            case KC_W_KC_R_KC_U__or : SEND_STRING_DELAY("or",25);break;
            case KC_W_KC_R_KC_Y__ot : SEND_STRING_DELAY("ot",25);break;
            case KC_W_KC_R_KC_I_KC_J__oy : SEND_STRING_DELAY("oy",25);break;
            case KC_W_KC_R_KC_U_KC_I__ou : SEND_STRING_DELAY("ou",25);break;
            case KC_W_KC_R_KC_I_KC_O__oi : SEND_STRING_DELAY("oi",25);break;
            case KC_W_KC_R_KC_U_KC_O__oo : SEND_STRING_DELAY("oo",25);break;
            case KC_W_KC_R_KC_U_KC_P__op : SEND_STRING_DELAY("op",25);break;
            case KC_W_KC_R_KC_J_KC_O__oh : SEND_STRING_DELAY("oh",25);break;
            case KC_W_KC_R_KC_J_KC_K__oj : SEND_STRING_DELAY("oj",25);break;
            case KC_W_KC_R_KC_K_KC_L__ok : SEND_STRING_DELAY("ok",25);break;
            case KC_W_KC_R_KC_J_KC_L__ol : SEND_STRING_DELAY("ol",25);break;
            case KC_W_KC_R_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("o:",25);break;
            case KC_W_KC_R_KC_L_KC_COMMA__on : SEND_STRING_DELAY("on",25);break;
            case KC_W_KC_R_KC_M_KC_COMMA__om : SEND_STRING_DELAY("om",25);break;
            case KC_W_KC_R_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("o,",25);break;
            case KC_W_KC_R_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("o.",25);break;
            case KC_W_KC_R_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("o/",25);break;
            case KC_W_KC_R_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("o>",25);break;
            case KC_W_KC_R_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("o?",25);break;
            case KC_W_KC_R_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("o'",25);break;
            case KC_W_KC_R_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("o;",25);break;
            case KC_R_KC_Q_KC_SEMICOLON__pa : SEND_STRING_DELAY("pa",25);break;
            case KC_R_KC_Q_KC_L__ps : SEND_STRING_DELAY("ps",25);break;
            case KC_R_KC_Q_KC_K__pd : SEND_STRING_DELAY("pd",25);break;
            case KC_R_KC_Q_KC_J__pf : SEND_STRING_DELAY("pf",25);break;
            case KC_R_KC_Q_KC_H__pg : SEND_STRING_DELAY("pg",25);break;
            case KC_R_KC_Q_KC_SLASH__pz : SEND_STRING_DELAY("pz",25);break;
            case KC_R_KC_Q_KC_DOT__px : SEND_STRING_DELAY("px",25);break;
            case KC_R_KC_Q_KC_COMMA__pc : SEND_STRING_DELAY("pc",25);break;
            case KC_R_KC_Q_KC_M__pv : SEND_STRING_DELAY("pv",25);break;
            case KC_R_KC_Q_KC_N__pb : SEND_STRING_DELAY("pb",25);break;
            case KC_R_KC_Q_KC_P__pq : SEND_STRING_DELAY("pq",25);break;
            case KC_R_KC_Q_KC_O__pw : SEND_STRING_DELAY("pw",25);break;
            case KC_R_KC_Q_KC_I__pe : SEND_STRING_DELAY("pe",25);break;
            case KC_R_KC_Q_KC_U__pr : SEND_STRING_DELAY("pr",25);break;
            case KC_R_KC_Q_KC_Y__pt : SEND_STRING_DELAY("pt",25);break;
            case KC_R_KC_Q_KC_I_KC_J__py : SEND_STRING_DELAY("py",25);break;
            case KC_R_KC_Q_KC_U_KC_I__pu : SEND_STRING_DELAY("pu",25);break;
            case KC_R_KC_Q_KC_I_KC_O__pi : SEND_STRING_DELAY("pi",25);break;
            case KC_R_KC_Q_KC_U_KC_O__po : SEND_STRING_DELAY("po",25);break;
            case KC_R_KC_Q_KC_U_KC_P__pp : SEND_STRING_DELAY("pp",25);break;
            case KC_R_KC_Q_KC_J_KC_O__ph : SEND_STRING_DELAY("ph",25);break;
            case KC_R_KC_Q_KC_J_KC_K__pj : SEND_STRING_DELAY("pj",25);break;
            case KC_R_KC_Q_KC_K_KC_L__pk : SEND_STRING_DELAY("pk",25);break;
            case KC_R_KC_Q_KC_J_KC_L__pl : SEND_STRING_DELAY("pl",25);break;
            case KC_R_KC_Q_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("p:",25);break;
            case KC_R_KC_Q_KC_L_KC_COMMA__pn : SEND_STRING_DELAY("pn",25);break;
            case KC_R_KC_Q_KC_M_KC_COMMA__pm : SEND_STRING_DELAY("pm",25);break;
            case KC_R_KC_Q_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("p,",25);break;
            case KC_R_KC_Q_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("p.",25);break;
            case KC_R_KC_Q_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("p/",25);break;
            case KC_R_KC_Q_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("p>",25);break;
            case KC_R_KC_Q_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("p?",25);break;
            case KC_R_KC_Q_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("p'",25);break;
            case KC_R_KC_Q_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("p;",25);break;
            case KC_Q_KC_SEMICOLON__qa : SEND_STRING_DELAY("qa",25);break;
            case KC_Q_KC_L__qs : SEND_STRING_DELAY("qs",25);break;
            case KC_Q_KC_K__qd : SEND_STRING_DELAY("qd",25);break;
            case KC_Q_KC_J__qf : SEND_STRING_DELAY("qf",25);break;
            case KC_Q_KC_H__qg : SEND_STRING_DELAY("qg",25);break;
            case KC_Q_KC_SLASH__qz : SEND_STRING_DELAY("qz",25);break;
            case KC_Q_KC_DOT__qx : SEND_STRING_DELAY("qx",25);break;
            case KC_Q_KC_COMMA__qc : SEND_STRING_DELAY("qc",25);break;
            case KC_Q_KC_M__qv : SEND_STRING_DELAY("qv",25);break;
            case KC_Q_KC_N__qb : SEND_STRING_DELAY("qb",25);break;
            case KC_Q_KC_P__qq : SEND_STRING_DELAY("qq",25);break;
            case KC_Q_KC_O__qw : SEND_STRING_DELAY("qw",25);break;
            case KC_Q_KC_I__qe : SEND_STRING_DELAY("qe",25);break;
            case KC_Q_KC_U__qr : SEND_STRING_DELAY("qr",25);break;
            case KC_Q_KC_Y__qt : SEND_STRING_DELAY("qt",25);break;
            case KC_Q_KC_I_KC_J__qy : SEND_STRING_DELAY("qy",25);break;
            case KC_Q_KC_U_KC_I__qu : SEND_STRING_DELAY("qu",25);break;
            case KC_Q_KC_I_KC_O__qi : SEND_STRING_DELAY("qi",25);break;
            case KC_Q_KC_U_KC_O__qo : SEND_STRING_DELAY("qo",25);break;
            case KC_Q_KC_U_KC_P__qp : SEND_STRING_DELAY("qp",25);break;
            case KC_Q_KC_J_KC_O__qh : SEND_STRING_DELAY("qh",25);break;
            case KC_Q_KC_J_KC_K__qj : SEND_STRING_DELAY("qj",25);break;
            case KC_Q_KC_K_KC_L__qk : SEND_STRING_DELAY("qk",25);break;
            case KC_Q_KC_J_KC_L__ql : SEND_STRING_DELAY("ql",25);break;
            case KC_Q_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("q:",25);break;
            case KC_Q_KC_L_KC_COMMA__qn : SEND_STRING_DELAY("qn",25);break;
            case KC_Q_KC_M_KC_COMMA__qm : SEND_STRING_DELAY("qm",25);break;
            case KC_Q_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("q,",25);break;
            case KC_Q_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("q.",25);break;
            case KC_Q_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("q/",25);break;
            case KC_Q_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("q>",25);break;
            case KC_Q_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("q?",25);break;
            case KC_Q_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("q'",25);break;
            case KC_Q_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("q;",25);break;
            case KC_W_KC_SEMICOLON__wa : SEND_STRING_DELAY("wa",25);break;
            case KC_W_KC_L__ws : SEND_STRING_DELAY("ws",25);break;
            case KC_W_KC_K__wd : SEND_STRING_DELAY("wd",25);break;
            case KC_W_KC_J__wf : SEND_STRING_DELAY("wf",25);break;
            case KC_W_KC_H__wg : SEND_STRING_DELAY("wg",25);break;
            case KC_W_KC_SLASH__wz : SEND_STRING_DELAY("wz",25);break;
            case KC_W_KC_DOT__wx : SEND_STRING_DELAY("wx",25);break;
            case KC_W_KC_COMMA__wc : SEND_STRING_DELAY("wc",25);break;
            case KC_W_KC_M__wv : SEND_STRING_DELAY("wv",25);break;
            case KC_W_KC_N__wb : SEND_STRING_DELAY("wb",25);break;
            case KC_W_KC_P__wq : SEND_STRING_DELAY("wq",25);break;
            case KC_W_KC_O__ww : SEND_STRING_DELAY("ww",25);break;
            case KC_W_KC_I__we : SEND_STRING_DELAY("we",25);break;
            case KC_W_KC_U__wr : SEND_STRING_DELAY("wr",25);break;
            case KC_W_KC_Y__wt : SEND_STRING_DELAY("wt",25);break;
            case KC_W_KC_I_KC_J__wy : SEND_STRING_DELAY("wy",25);break;
            case KC_W_KC_U_KC_I__wu : SEND_STRING_DELAY("wu",25);break;
            case KC_W_KC_I_KC_O__wi : SEND_STRING_DELAY("wi",25);break;
            case KC_W_KC_U_KC_O__wo : SEND_STRING_DELAY("wo",25);break;
            case KC_W_KC_U_KC_P__wp : SEND_STRING_DELAY("wp",25);break;
            case KC_W_KC_J_KC_O__wh : SEND_STRING_DELAY("wh",25);break;
            case KC_W_KC_J_KC_K__wj : SEND_STRING_DELAY("wj",25);break;
            case KC_W_KC_K_KC_L__wk : SEND_STRING_DELAY("wk",25);break;
            case KC_W_KC_J_KC_L__wl : SEND_STRING_DELAY("wl",25);break;
            case KC_W_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("w:",25);break;
            case KC_W_KC_L_KC_COMMA__wn : SEND_STRING_DELAY("wn",25);break;
            case KC_W_KC_M_KC_COMMA__wm : SEND_STRING_DELAY("wm",25);break;
            case KC_W_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("w,",25);break;
            case KC_W_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("w.",25);break;
            case KC_W_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("w/",25);break;
            case KC_W_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("w>",25);break;
            case KC_W_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("w?",25);break;
            case KC_W_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("w'",25);break;
            case KC_W_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("w;",25);break;
            case KC_E_KC_SEMICOLON__ea : SEND_STRING_DELAY("ea",25);break;
            case KC_E_KC_L__es : SEND_STRING_DELAY("es",25);break;
            case KC_E_KC_K__ed : SEND_STRING_DELAY("ed",25);break;
            case KC_E_KC_J__ef : SEND_STRING_DELAY("ef",25);break;
            case KC_E_KC_H__eg : SEND_STRING_DELAY("eg",25);break;
            case KC_E_KC_SLASH__ez : SEND_STRING_DELAY("ez",25);break;
            case KC_E_KC_DOT__ex : SEND_STRING_DELAY("ex",25);break;
            case KC_E_KC_COMMA__ec : SEND_STRING_DELAY("ec",25);break;
            case KC_E_KC_M__ev : SEND_STRING_DELAY("ev",25);break;
            case KC_E_KC_N__eb : SEND_STRING_DELAY("eb",25);break;
            case KC_E_KC_P__eq : SEND_STRING_DELAY("eq",25);break;
            case KC_E_KC_O__ew : SEND_STRING_DELAY("ew",25);break;
            case KC_E_KC_I__ee : SEND_STRING_DELAY("ee",25);break;
            case KC_E_KC_U__er : SEND_STRING_DELAY("er",25);break;
            case KC_E_KC_Y__et : SEND_STRING_DELAY("et",25);break;
            case KC_E_KC_I_KC_J__ey : SEND_STRING_DELAY("ey",25);break;
            case KC_E_KC_U_KC_I__eu : SEND_STRING_DELAY("eu",25);break;
            case KC_E_KC_I_KC_O__ei : SEND_STRING_DELAY("ei",25);break;
            case KC_E_KC_U_KC_O__eo : SEND_STRING_DELAY("eo",25);break;
            case KC_E_KC_U_KC_P__ep : SEND_STRING_DELAY("ep",25);break;
            case KC_E_KC_J_KC_O__eh : SEND_STRING_DELAY("eh",25);break;
            case KC_E_KC_J_KC_K__ej : SEND_STRING_DELAY("ej",25);break;
            case KC_E_KC_K_KC_L__ek : SEND_STRING_DELAY("ek",25);break;
            case KC_E_KC_J_KC_L__el : SEND_STRING_DELAY("el",25);break;
            case KC_E_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("e:",25);break;
            case KC_E_KC_L_KC_COMMA__en : SEND_STRING_DELAY("en",25);break;
            case KC_E_KC_M_KC_COMMA__em : SEND_STRING_DELAY("em",25);break;
            case KC_E_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("e,",25);break;
            case KC_E_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("e.",25);break;
            case KC_E_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("e/",25);break;
            case KC_E_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("e>",25);break;
            case KC_E_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("e?",25);break;
            case KC_E_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("e'",25);break;
            case KC_E_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("e;",25);break;
            case KC_R_KC_SEMICOLON__ra : SEND_STRING_DELAY("ra",25);break;
            case KC_R_KC_L__rs : SEND_STRING_DELAY("rs",25);break;
            case KC_R_KC_K__rd : SEND_STRING_DELAY("rd",25);break;
            case KC_R_KC_J__rf : SEND_STRING_DELAY("rf",25);break;
            case KC_R_KC_H__rg : SEND_STRING_DELAY("rg",25);break;
            case KC_R_KC_SLASH__rz : SEND_STRING_DELAY("rz",25);break;
            case KC_R_KC_DOT__rx : SEND_STRING_DELAY("rx",25);break;
            case KC_R_KC_COMMA__rc : SEND_STRING_DELAY("rc",25);break;
            case KC_R_KC_M__rv : SEND_STRING_DELAY("rv",25);break;
            case KC_R_KC_N__rb : SEND_STRING_DELAY("rb",25);break;
            case KC_R_KC_P__rq : SEND_STRING_DELAY("rq",25);break;
            case KC_R_KC_O__rw : SEND_STRING_DELAY("rw",25);break;
            case KC_R_KC_I__re : SEND_STRING_DELAY("re",25);break;
            case KC_R_KC_U__rr : SEND_STRING_DELAY("rr",25);break;
            case KC_R_KC_Y__rt : SEND_STRING_DELAY("rt",25);break;
            case KC_R_KC_I_KC_J__ry : SEND_STRING_DELAY("ry",25);break;
            case KC_R_KC_U_KC_I__ru : SEND_STRING_DELAY("ru",25);break;
            case KC_R_KC_I_KC_O__ri : SEND_STRING_DELAY("ri",25);break;
            case KC_R_KC_U_KC_O__ro : SEND_STRING_DELAY("ro",25);break;
            case KC_R_KC_U_KC_P__rp : SEND_STRING_DELAY("rp",25);break;
            case KC_R_KC_J_KC_O__rh : SEND_STRING_DELAY("rh",25);break;
            case KC_R_KC_J_KC_K__rj : SEND_STRING_DELAY("rj",25);break;
            case KC_R_KC_K_KC_L__rk : SEND_STRING_DELAY("rk",25);break;
            case KC_R_KC_J_KC_L__rl : SEND_STRING_DELAY("rl",25);break;
            case KC_R_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("r:",25);break;
            case KC_R_KC_L_KC_COMMA__rn : SEND_STRING_DELAY("rn",25);break;
            case KC_R_KC_M_KC_COMMA__rm : SEND_STRING_DELAY("rm",25);break;
            case KC_R_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("r,",25);break;
            case KC_R_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("r.",25);break;
            case KC_R_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("r/",25);break;
            case KC_R_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("r>",25);break;
            case KC_R_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("r?",25);break;
            case KC_R_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("r'",25);break;
            case KC_R_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("r;",25);break;
            case KC_T_KC_SEMICOLON__ta : SEND_STRING_DELAY("ta",25);break;
            case KC_T_KC_L__ts : SEND_STRING_DELAY("ts",25);break;
            case KC_T_KC_K__td : SEND_STRING_DELAY("td",25);break;
            case KC_T_KC_J__tf : SEND_STRING_DELAY("tf",25);break;
            case KC_T_KC_H__tg : SEND_STRING_DELAY("tg",25);break;
            case KC_T_KC_SLASH__tz : SEND_STRING_DELAY("tz",25);break;
            case KC_T_KC_DOT__tx : SEND_STRING_DELAY("tx",25);break;
            case KC_T_KC_COMMA__tc : SEND_STRING_DELAY("tc",25);break;
            case KC_T_KC_M__tv : SEND_STRING_DELAY("tv",25);break;
            case KC_T_KC_N__tb : SEND_STRING_DELAY("tb",25);break;
            case KC_T_KC_P__tq : SEND_STRING_DELAY("tq",25);break;
            case KC_T_KC_O__tw : SEND_STRING_DELAY("tw",25);break;
            case KC_T_KC_I__te : SEND_STRING_DELAY("te",25);break;
            case KC_T_KC_U__tr : SEND_STRING_DELAY("tr",25);break;
            case KC_T_KC_Y__tt : SEND_STRING_DELAY("tt",25);break;
            case KC_T_KC_I_KC_J__ty : SEND_STRING_DELAY("ty",25);break;
            case KC_T_KC_U_KC_I__tu : SEND_STRING_DELAY("tu",25);break;
            case KC_T_KC_I_KC_O__ti : SEND_STRING_DELAY("ti",25);break;
            case KC_T_KC_U_KC_O__to : SEND_STRING_DELAY("to",25);break;
            case KC_T_KC_U_KC_P__tp : SEND_STRING_DELAY("tp",25);break;
            case KC_T_KC_J_KC_O__th : SEND_STRING_DELAY("th",25);break;
            case KC_T_KC_J_KC_K__tj : SEND_STRING_DELAY("tj",25);break;
            case KC_T_KC_K_KC_L__tk : SEND_STRING_DELAY("tk",25);break;
            case KC_T_KC_J_KC_L__tl : SEND_STRING_DELAY("tl",25);break;
            case KC_T_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("t:",25);break;
            case KC_T_KC_L_KC_COMMA__tn : SEND_STRING_DELAY("tn",25);break;
            case KC_T_KC_M_KC_COMMA__tm : SEND_STRING_DELAY("tm",25);break;
            case KC_T_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("t,",25);break;
            case KC_T_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("t.",25);break;
            case KC_T_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("t/",25);break;
            case KC_T_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("t>",25);break;
            case KC_T_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("t?",25);break;
            case KC_T_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("t'",25);break;
            case KC_T_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("t;",25);break;
            case KC_A_KC_SEMICOLON__aa : SEND_STRING_DELAY("aa",25);break;
            case KC_A_KC_L__as : SEND_STRING_DELAY("as",25);break;
            case KC_A_KC_K__ad : SEND_STRING_DELAY("ad",25);break;
            case KC_A_KC_J__af : SEND_STRING_DELAY("af",25);break;
            case KC_A_KC_H__ag : SEND_STRING_DELAY("ag",25);break;
            case KC_A_KC_SLASH__az : SEND_STRING_DELAY("az",25);break;
            case KC_A_KC_DOT__ax : SEND_STRING_DELAY("ax",25);break;
            case KC_A_KC_COMMA__ac : SEND_STRING_DELAY("ac",25);break;
            case KC_A_KC_M__av : SEND_STRING_DELAY("av",25);break;
            case KC_A_KC_N__ab : SEND_STRING_DELAY("ab",25);break;
            case KC_A_KC_P__aq : SEND_STRING_DELAY("aq",25);break;
            case KC_A_KC_O__aw : SEND_STRING_DELAY("aw",25);break;
            case KC_A_KC_I__ae : SEND_STRING_DELAY("ae",25);break;
            case KC_A_KC_U__ar : SEND_STRING_DELAY("ar",25);break;
            case KC_A_KC_Y__at : SEND_STRING_DELAY("at",25);break;
            case KC_A_KC_I_KC_J__ay : SEND_STRING_DELAY("ay",25);break;
            case KC_A_KC_U_KC_I__au : SEND_STRING_DELAY("au",25);break;
            case KC_A_KC_I_KC_O__ai : SEND_STRING_DELAY("ai",25);break;
            case KC_A_KC_U_KC_O__ao : SEND_STRING_DELAY("ao",25);break;
            case KC_A_KC_U_KC_P__ap : SEND_STRING_DELAY("ap",25);break;
            case KC_A_KC_J_KC_O__ah : SEND_STRING_DELAY("ah",25);break;
            case KC_A_KC_J_KC_K__aj : SEND_STRING_DELAY("aj",25);break;
            case KC_A_KC_K_KC_L__ak : SEND_STRING_DELAY("ak",25);break;
            case KC_A_KC_J_KC_L__al : SEND_STRING_DELAY("al",25);break;
            case KC_A_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("a:",25);break;
            case KC_A_KC_L_KC_COMMA__an : SEND_STRING_DELAY("an",25);break;
            case KC_A_KC_M_KC_COMMA__am : SEND_STRING_DELAY("am",25);break;
            case KC_A_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("a,",25);break;
            case KC_A_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("a.",25);break;
            case KC_A_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("a/",25);break;
            case KC_A_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("a>",25);break;
            case KC_A_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("a?",25);break;
            case KC_A_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("a'",25);break;
            case KC_A_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("a;",25);break;
            case KC_S_KC_SEMICOLON__sa : SEND_STRING_DELAY("sa",25);break;
            case KC_S_KC_L__ss : SEND_STRING_DELAY("ss",25);break;
            case KC_S_KC_K__sd : SEND_STRING_DELAY("sd",25);break;
            case KC_S_KC_J__sf : SEND_STRING_DELAY("sf",25);break;
            case KC_S_KC_H__sg : SEND_STRING_DELAY("sg",25);break;
            case KC_S_KC_SLASH__sz : SEND_STRING_DELAY("sz",25);break;
            case KC_S_KC_DOT__sx : SEND_STRING_DELAY("sx",25);break;
            case KC_S_KC_COMMA__sc : SEND_STRING_DELAY("sc",25);break;
            case KC_S_KC_M__sv : SEND_STRING_DELAY("sv",25);break;
            case KC_S_KC_N__sb : SEND_STRING_DELAY("sb",25);break;
            case KC_S_KC_P__sq : SEND_STRING_DELAY("sq",25);break;
            case KC_S_KC_O__sw : SEND_STRING_DELAY("sw",25);break;
            case KC_S_KC_I__se : SEND_STRING_DELAY("se",25);break;
            case KC_S_KC_U__sr : SEND_STRING_DELAY("sr",25);break;
            case KC_S_KC_Y__st : SEND_STRING_DELAY("st",25);break;
            case KC_S_KC_I_KC_J__sy : SEND_STRING_DELAY("sy",25);break;
            case KC_S_KC_U_KC_I__su : SEND_STRING_DELAY("su",25);break;
            case KC_S_KC_I_KC_O__si : SEND_STRING_DELAY("si",25);break;
            case KC_S_KC_U_KC_O__so : SEND_STRING_DELAY("so",25);break;
            case KC_S_KC_U_KC_P__sp : SEND_STRING_DELAY("sp",25);break;
            case KC_S_KC_J_KC_O__sh : SEND_STRING_DELAY("sh",25);break;
            case KC_S_KC_J_KC_K__sj : SEND_STRING_DELAY("sj",25);break;
            case KC_S_KC_K_KC_L__sk : SEND_STRING_DELAY("sk",25);break;
            case KC_S_KC_J_KC_L__sl : SEND_STRING_DELAY("sl",25);break;
            case KC_S_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("s:",25);break;
            case KC_S_KC_L_KC_COMMA__sn : SEND_STRING_DELAY("sn",25);break;
            case KC_S_KC_M_KC_COMMA__sm : SEND_STRING_DELAY("sm",25);break;
            case KC_S_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("s,",25);break;
            case KC_S_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("s.",25);break;
            case KC_S_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("s/",25);break;
            case KC_S_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("s>",25);break;
            case KC_S_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("s?",25);break;
            case KC_S_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("s'",25);break;
            case KC_S_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("s;",25);break;
            case KC_D_KC_SEMICOLON__da : SEND_STRING_DELAY("da",25);break;
            case KC_D_KC_L__ds : SEND_STRING_DELAY("ds",25);break;
            case KC_D_KC_K__dd : SEND_STRING_DELAY("dd",25);break;
            case KC_D_KC_J__df : SEND_STRING_DELAY("df",25);break;
            case KC_D_KC_H__dg : SEND_STRING_DELAY("dg",25);break;
            case KC_D_KC_SLASH__dz : SEND_STRING_DELAY("dz",25);break;
            case KC_D_KC_DOT__dx : SEND_STRING_DELAY("dx",25);break;
            case KC_D_KC_COMMA__dc : SEND_STRING_DELAY("dc",25);break;
            case KC_D_KC_M__dv : SEND_STRING_DELAY("dv",25);break;
            case KC_D_KC_N__db : SEND_STRING_DELAY("db",25);break;
            case KC_D_KC_P__dq : SEND_STRING_DELAY("dq",25);break;
            case KC_D_KC_O__dw : SEND_STRING_DELAY("dw",25);break;
            case KC_D_KC_I__de : SEND_STRING_DELAY("de",25);break;
            case KC_D_KC_U__dr : SEND_STRING_DELAY("dr",25);break;
            case KC_D_KC_Y__dt : SEND_STRING_DELAY("dt",25);break;
            case KC_D_KC_I_KC_J__dy : SEND_STRING_DELAY("dy",25);break;
            case KC_D_KC_U_KC_I__du : SEND_STRING_DELAY("du",25);break;
            case KC_D_KC_I_KC_O__di : SEND_STRING_DELAY("di",25);break;
            case KC_D_KC_U_KC_O__do : SEND_STRING_DELAY("do",25);break;
            case KC_D_KC_U_KC_P__dp : SEND_STRING_DELAY("dp",25);break;
            case KC_D_KC_J_KC_O__dh : SEND_STRING_DELAY("dh",25);break;
            case KC_D_KC_J_KC_K__dj : SEND_STRING_DELAY("dj",25);break;
            case KC_D_KC_K_KC_L__dk : SEND_STRING_DELAY("dk",25);break;
            case KC_D_KC_J_KC_L__dl : SEND_STRING_DELAY("dl",25);break;
            case KC_D_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("d:",25);break;
            case KC_D_KC_L_KC_COMMA__dn : SEND_STRING_DELAY("dn",25);break;
            case KC_D_KC_M_KC_COMMA__dm : SEND_STRING_DELAY("dm",25);break;
            case KC_D_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("d,",25);break;
            case KC_D_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("d.",25);break;
            case KC_D_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("d/",25);break;
            case KC_D_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("d>",25);break;
            case KC_D_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("d?",25);break;
            case KC_D_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("d'",25);break;
            case KC_D_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("d;",25);break;
            case KC_F_KC_SEMICOLON__fa : SEND_STRING_DELAY("fa",25);break;
            case KC_F_KC_L__fs : SEND_STRING_DELAY("fs",25);break;
            case KC_F_KC_K__fd : SEND_STRING_DELAY("fd",25);break;
            case KC_F_KC_J__ff : SEND_STRING_DELAY("ff",25);break;
            case KC_F_KC_H__fg : SEND_STRING_DELAY("fg",25);break;
            case KC_F_KC_SLASH__fz : SEND_STRING_DELAY("fz",25);break;
            case KC_F_KC_DOT__fx : SEND_STRING_DELAY("fx",25);break;
            case KC_F_KC_COMMA__fc : SEND_STRING_DELAY("fc",25);break;
            case KC_F_KC_M__fv : SEND_STRING_DELAY("fv",25);break;
            case KC_F_KC_N__fb : SEND_STRING_DELAY("fb",25);break;
            case KC_F_KC_P__fq : SEND_STRING_DELAY("fq",25);break;
            case KC_F_KC_O__fw : SEND_STRING_DELAY("fw",25);break;
            case KC_F_KC_I__fe : SEND_STRING_DELAY("fe",25);break;
            case KC_F_KC_U__fr : SEND_STRING_DELAY("fr",25);break;
            case KC_F_KC_Y__ft : SEND_STRING_DELAY("ft",25);break;
            case KC_F_KC_I_KC_J__fy : SEND_STRING_DELAY("fy",25);break;
            case KC_F_KC_U_KC_I__fu : SEND_STRING_DELAY("fu",25);break;
            case KC_F_KC_I_KC_O__fi : SEND_STRING_DELAY("fi",25);break;
            case KC_F_KC_U_KC_O__fo : SEND_STRING_DELAY("fo",25);break;
            case KC_F_KC_U_KC_P__fp : SEND_STRING_DELAY("fp",25);break;
            case KC_F_KC_J_KC_O__fh : SEND_STRING_DELAY("fh",25);break;
            case KC_F_KC_J_KC_K__fj : SEND_STRING_DELAY("fj",25);break;
            case KC_F_KC_K_KC_L__fk : SEND_STRING_DELAY("fk",25);break;
            case KC_F_KC_J_KC_L__fl : SEND_STRING_DELAY("fl",25);break;
            case KC_F_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("f:",25);break;
            case KC_F_KC_L_KC_COMMA__fn : SEND_STRING_DELAY("fn",25);break;
            case KC_F_KC_M_KC_COMMA__fm : SEND_STRING_DELAY("fm",25);break;
            case KC_F_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("f,",25);break;
            case KC_F_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("f.",25);break;
            case KC_F_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("f/",25);break;
            case KC_F_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("f>",25);break;
            case KC_F_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("f?",25);break;
            case KC_F_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("f'",25);break;
            case KC_F_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("f;",25);break;
            case KC_G_KC_SEMICOLON__ga : SEND_STRING_DELAY("ga",25);break;
            case KC_G_KC_L__gs : SEND_STRING_DELAY("gs",25);break;
            case KC_G_KC_K__gd : SEND_STRING_DELAY("gd",25);break;
            case KC_G_KC_J__gf : SEND_STRING_DELAY("gf",25);break;
            case KC_G_KC_H__gg : SEND_STRING_DELAY("gg",25);break;
            case KC_G_KC_SLASH__gz : SEND_STRING_DELAY("gz",25);break;
            case KC_G_KC_DOT__gx : SEND_STRING_DELAY("gx",25);break;
            case KC_G_KC_COMMA__gc : SEND_STRING_DELAY("gc",25);break;
            case KC_G_KC_M__gv : SEND_STRING_DELAY("gv",25);break;
            case KC_G_KC_N__gb : SEND_STRING_DELAY("gb",25);break;
            case KC_G_KC_P__gq : SEND_STRING_DELAY("gq",25);break;
            case KC_G_KC_O__gw : SEND_STRING_DELAY("gw",25);break;
            case KC_G_KC_I__ge : SEND_STRING_DELAY("ge",25);break;
            case KC_G_KC_U__gr : SEND_STRING_DELAY("gr",25);break;
            case KC_G_KC_Y__gt : SEND_STRING_DELAY("gt",25);break;
            case KC_G_KC_I_KC_J__gy : SEND_STRING_DELAY("gy",25);break;
            case KC_G_KC_U_KC_I__gu : SEND_STRING_DELAY("gu",25);break;
            case KC_G_KC_I_KC_O__gi : SEND_STRING_DELAY("gi",25);break;
            case KC_G_KC_U_KC_O__go : SEND_STRING_DELAY("go",25);break;
            case KC_G_KC_U_KC_P__gp : SEND_STRING_DELAY("gp",25);break;
            case KC_G_KC_J_KC_O__gh : SEND_STRING_DELAY("gh",25);break;
            case KC_G_KC_J_KC_K__gj : SEND_STRING_DELAY("gj",25);break;
            case KC_G_KC_K_KC_L__gk : SEND_STRING_DELAY("gk",25);break;
            case KC_G_KC_J_KC_L__gl : SEND_STRING_DELAY("gl",25);break;
            case KC_G_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("g:",25);break;
            case KC_G_KC_L_KC_COMMA__gn : SEND_STRING_DELAY("gn",25);break;
            case KC_G_KC_M_KC_COMMA__gm : SEND_STRING_DELAY("gm",25);break;
            case KC_G_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("g,",25);break;
            case KC_G_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("g.",25);break;
            case KC_G_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("g/",25);break;
            case KC_G_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("g>",25);break;
            case KC_G_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("g?",25);break;
            case KC_G_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("g'",25);break;
            case KC_G_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("g;",25);break;
            case KC_Z_KC_SEMICOLON__za : SEND_STRING_DELAY("za",25);break;
            case KC_Z_KC_L__zs : SEND_STRING_DELAY("zs",25);break;
            case KC_Z_KC_K__zd : SEND_STRING_DELAY("zd",25);break;
            case KC_Z_KC_J__zf : SEND_STRING_DELAY("zf",25);break;
            case KC_Z_KC_H__zg : SEND_STRING_DELAY("zg",25);break;
            case KC_Z_KC_SLASH__zz : SEND_STRING_DELAY("zz",25);break;
            case KC_Z_KC_DOT__zx : SEND_STRING_DELAY("zx",25);break;
            case KC_Z_KC_COMMA__zc : SEND_STRING_DELAY("zc",25);break;
            case KC_Z_KC_M__zv : SEND_STRING_DELAY("zv",25);break;
            case KC_Z_KC_N__zb : SEND_STRING_DELAY("zb",25);break;
            case KC_Z_KC_P__zq : SEND_STRING_DELAY("zq",25);break;
            case KC_Z_KC_O__zw : SEND_STRING_DELAY("zw",25);break;
            case KC_Z_KC_I__ze : SEND_STRING_DELAY("ze",25);break;
            case KC_Z_KC_U__zr : SEND_STRING_DELAY("zr",25);break;
            case KC_Z_KC_Y__zt : SEND_STRING_DELAY("zt",25);break;
            case KC_Z_KC_I_KC_J__zy : SEND_STRING_DELAY("zy",25);break;
            case KC_Z_KC_U_KC_I__zu : SEND_STRING_DELAY("zu",25);break;
            case KC_Z_KC_I_KC_O__zi : SEND_STRING_DELAY("zi",25);break;
            case KC_Z_KC_U_KC_O__zo : SEND_STRING_DELAY("zo",25);break;
            case KC_Z_KC_U_KC_P__zp : SEND_STRING_DELAY("zp",25);break;
            case KC_Z_KC_J_KC_O__zh : SEND_STRING_DELAY("zh",25);break;
            case KC_Z_KC_J_KC_K__zj : SEND_STRING_DELAY("zj",25);break;
            case KC_Z_KC_K_KC_L__zk : SEND_STRING_DELAY("zk",25);break;
            case KC_Z_KC_J_KC_L__zl : SEND_STRING_DELAY("zl",25);break;
            case KC_Z_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("z:",25);break;
            case KC_Z_KC_L_KC_COMMA__zn : SEND_STRING_DELAY("zn",25);break;
            case KC_Z_KC_M_KC_COMMA__zm : SEND_STRING_DELAY("zm",25);break;
            case KC_Z_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("z,",25);break;
            case KC_Z_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("z.",25);break;
            case KC_Z_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("z/",25);break;
            case KC_Z_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("z>",25);break;
            case KC_Z_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("z?",25);break;
            case KC_Z_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("z'",25);break;
            case KC_Z_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("z;",25);break;
            case KC_X_KC_SEMICOLON__xa : SEND_STRING_DELAY("xa",25);break;
            case KC_X_KC_L__xs : SEND_STRING_DELAY("xs",25);break;
            case KC_X_KC_K__xd : SEND_STRING_DELAY("xd",25);break;
            case KC_X_KC_J__xf : SEND_STRING_DELAY("xf",25);break;
            case KC_X_KC_H__xg : SEND_STRING_DELAY("xg",25);break;
            case KC_X_KC_SLASH__xz : SEND_STRING_DELAY("xz",25);break;
            case KC_X_KC_DOT__xx : SEND_STRING_DELAY("xx",25);break;
            case KC_X_KC_COMMA__xc : SEND_STRING_DELAY("xc",25);break;
            case KC_X_KC_M__xv : SEND_STRING_DELAY("xv",25);break;
            case KC_X_KC_N__xb : SEND_STRING_DELAY("xb",25);break;
            case KC_X_KC_P__xq : SEND_STRING_DELAY("xq",25);break;
            case KC_X_KC_O__xw : SEND_STRING_DELAY("xw",25);break;
            case KC_X_KC_I__xe : SEND_STRING_DELAY("xe",25);break;
            case KC_X_KC_U__xr : SEND_STRING_DELAY("xr",25);break;
            case KC_X_KC_Y__xt : SEND_STRING_DELAY("xt",25);break;
            case KC_X_KC_I_KC_J__xy : SEND_STRING_DELAY("xy",25);break;
            case KC_X_KC_U_KC_I__xu : SEND_STRING_DELAY("xu",25);break;
            case KC_X_KC_I_KC_O__xi : SEND_STRING_DELAY("xi",25);break;
            case KC_X_KC_U_KC_O__xo : SEND_STRING_DELAY("xo",25);break;
            case KC_X_KC_U_KC_P__xp : SEND_STRING_DELAY("xp",25);break;
            case KC_X_KC_J_KC_O__xh : SEND_STRING_DELAY("xh",25);break;
            case KC_X_KC_J_KC_K__xj : SEND_STRING_DELAY("xj",25);break;
            case KC_X_KC_K_KC_L__xk : SEND_STRING_DELAY("xk",25);break;
            case KC_X_KC_J_KC_L__xl : SEND_STRING_DELAY("xl",25);break;
            case KC_X_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("x:",25);break;
            case KC_X_KC_L_KC_COMMA__xn : SEND_STRING_DELAY("xn",25);break;
            case KC_X_KC_M_KC_COMMA__xm : SEND_STRING_DELAY("xm",25);break;
            case KC_X_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("x,",25);break;
            case KC_X_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("x.",25);break;
            case KC_X_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("x/",25);break;
            case KC_X_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("x>",25);break;
            case KC_X_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("x?",25);break;
            case KC_X_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("x'",25);break;
            case KC_X_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("x;",25);break;
            case KC_C_KC_SEMICOLON__ca : SEND_STRING_DELAY("ca",25);break;
            case KC_C_KC_L__cs : SEND_STRING_DELAY("cs",25);break;
            case KC_C_KC_K__cd : SEND_STRING_DELAY("cd",25);break;
            case KC_C_KC_J__cf : SEND_STRING_DELAY("cf",25);break;
            case KC_C_KC_H__cg : SEND_STRING_DELAY("cg",25);break;
            case KC_C_KC_SLASH__cz : SEND_STRING_DELAY("cz",25);break;
            case KC_C_KC_DOT__cx : SEND_STRING_DELAY("cx",25);break;
            case KC_C_KC_COMMA__cc : SEND_STRING_DELAY("cc",25);break;
            case KC_C_KC_M__cv : SEND_STRING_DELAY("cv",25);break;
            case KC_C_KC_N__cb : SEND_STRING_DELAY("cb",25);break;
            case KC_C_KC_P__cq : SEND_STRING_DELAY("cq",25);break;
            case KC_C_KC_O__cw : SEND_STRING_DELAY("cw",25);break;
            case KC_C_KC_I__ce : SEND_STRING_DELAY("ce",25);break;
            case KC_C_KC_U__cr : SEND_STRING_DELAY("cr",25);break;
            case KC_C_KC_Y__ct : SEND_STRING_DELAY("ct",25);break;
            case KC_C_KC_I_KC_J__cy : SEND_STRING_DELAY("cy",25);break;
            case KC_C_KC_U_KC_I__cu : SEND_STRING_DELAY("cu",25);break;
            case KC_C_KC_I_KC_O__ci : SEND_STRING_DELAY("ci",25);break;
            case KC_C_KC_U_KC_O__co : SEND_STRING_DELAY("co",25);break;
            case KC_C_KC_U_KC_P__cp : SEND_STRING_DELAY("cp",25);break;
            case KC_C_KC_J_KC_O__ch : SEND_STRING_DELAY("ch",25);break;
            case KC_C_KC_J_KC_K__cj : SEND_STRING_DELAY("cj",25);break;
            case KC_C_KC_K_KC_L__ck : SEND_STRING_DELAY("ck",25);break;
            case KC_C_KC_J_KC_L__cl : SEND_STRING_DELAY("cl",25);break;
            case KC_C_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("c:",25);break;
            case KC_C_KC_L_KC_COMMA__cn : SEND_STRING_DELAY("cn",25);break;
            case KC_C_KC_M_KC_COMMA__cm : SEND_STRING_DELAY("cm",25);break;
            case KC_C_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("c,",25);break;
            case KC_C_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("c.",25);break;
            case KC_C_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("c/",25);break;
            case KC_C_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("c>",25);break;
            case KC_C_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("c?",25);break;
            case KC_C_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("c'",25);break;
            case KC_C_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("c;",25);break;
            case KC_V_KC_SEMICOLON__va : SEND_STRING_DELAY("va",25);break;
            case KC_V_KC_L__vs : SEND_STRING_DELAY("vs",25);break;
            case KC_V_KC_K__vd : SEND_STRING_DELAY("vd",25);break;
            case KC_V_KC_J__vf : SEND_STRING_DELAY("vf",25);break;
            case KC_V_KC_H__vg : SEND_STRING_DELAY("vg",25);break;
            case KC_V_KC_SLASH__vz : SEND_STRING_DELAY("vz",25);break;
            case KC_V_KC_DOT__vx : SEND_STRING_DELAY("vx",25);break;
            case KC_V_KC_COMMA__vc : SEND_STRING_DELAY("vc",25);break;
            case KC_V_KC_M__vv : SEND_STRING_DELAY("vv",25);break;
            case KC_V_KC_N__vb : SEND_STRING_DELAY("vb",25);break;
            case KC_V_KC_P__vq : SEND_STRING_DELAY("vq",25);break;
            case KC_V_KC_O__vw : SEND_STRING_DELAY("vw",25);break;
            case KC_V_KC_I__ve : SEND_STRING_DELAY("ve",25);break;
            case KC_V_KC_U__vr : SEND_STRING_DELAY("vr",25);break;
            case KC_V_KC_Y__vt : SEND_STRING_DELAY("vt",25);break;
            case KC_V_KC_I_KC_J__vy : SEND_STRING_DELAY("vy",25);break;
            case KC_V_KC_U_KC_I__vu : SEND_STRING_DELAY("vu",25);break;
            case KC_V_KC_I_KC_O__vi : SEND_STRING_DELAY("vi",25);break;
            case KC_V_KC_U_KC_O__vo : SEND_STRING_DELAY("vo",25);break;
            case KC_V_KC_U_KC_P__vp : SEND_STRING_DELAY("vp",25);break;
            case KC_V_KC_J_KC_O__vh : SEND_STRING_DELAY("vh",25);break;
            case KC_V_KC_J_KC_K__vj : SEND_STRING_DELAY("vj",25);break;
            case KC_V_KC_K_KC_L__vk : SEND_STRING_DELAY("vk",25);break;
            case KC_V_KC_J_KC_L__vl : SEND_STRING_DELAY("vl",25);break;
            case KC_V_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("v:",25);break;
            case KC_V_KC_L_KC_COMMA__vn : SEND_STRING_DELAY("vn",25);break;
            case KC_V_KC_M_KC_COMMA__vm : SEND_STRING_DELAY("vm",25);break;
            case KC_V_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("v,",25);break;
            case KC_V_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("v.",25);break;
            case KC_V_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("v/",25);break;
            case KC_V_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("v>",25);break;
            case KC_V_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("v?",25);break;
            case KC_V_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("v'",25);break;
            case KC_V_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("v;",25);break;
            case KC_B_KC_SEMICOLON__ba : SEND_STRING_DELAY("ba",25);break;
            case KC_B_KC_L__bs : SEND_STRING_DELAY("bs",25);break;
            case KC_B_KC_K__bd : SEND_STRING_DELAY("bd",25);break;
            case KC_B_KC_J__bf : SEND_STRING_DELAY("bf",25);break;
            case KC_B_KC_H__bg : SEND_STRING_DELAY("bg",25);break;
            case KC_B_KC_SLASH__bz : SEND_STRING_DELAY("bz",25);break;
            case KC_B_KC_DOT__bx : SEND_STRING_DELAY("bx",25);break;
            case KC_B_KC_COMMA__bc : SEND_STRING_DELAY("bc",25);break;
            case KC_B_KC_M__bv : SEND_STRING_DELAY("bv",25);break;
            case KC_B_KC_N__bb : SEND_STRING_DELAY("bb",25);break;
            case KC_B_KC_P__bq : SEND_STRING_DELAY("bq",25);break;
            case KC_B_KC_O__bw : SEND_STRING_DELAY("bw",25);break;
            case KC_B_KC_I__be : SEND_STRING_DELAY("be",25);break;
            case KC_B_KC_U__br : SEND_STRING_DELAY("br",25);break;
            case KC_B_KC_Y__bt : SEND_STRING_DELAY("bt",25);break;
            case KC_B_KC_I_KC_J__by : SEND_STRING_DELAY("by",25);break;
            case KC_B_KC_U_KC_I__bu : SEND_STRING_DELAY("bu",25);break;
            case KC_B_KC_I_KC_O__bi : SEND_STRING_DELAY("bi",25);break;
            case KC_B_KC_U_KC_O__bo : SEND_STRING_DELAY("bo",25);break;
            case KC_B_KC_U_KC_P__bp : SEND_STRING_DELAY("bp",25);break;
            case KC_B_KC_J_KC_O__bh : SEND_STRING_DELAY("bh",25);break;
            case KC_B_KC_J_KC_K__bj : SEND_STRING_DELAY("bj",25);break;
            case KC_B_KC_K_KC_L__bk : SEND_STRING_DELAY("bk",25);break;
            case KC_B_KC_J_KC_L__bl : SEND_STRING_DELAY("bl",25);break;
            case KC_B_KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("b:",25);break;
            case KC_B_KC_L_KC_COMMA__bn : SEND_STRING_DELAY("bn",25);break;
            case KC_B_KC_M_KC_COMMA__bm : SEND_STRING_DELAY("bm",25);break;
            case KC_B_KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY("b,",25);break;
            case KC_B_KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY("b.",25);break;
            case KC_B_KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("b/",25);break;
            case KC_B_KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY("b>",25);break;
            case KC_B_KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("b?",25);break;
            case KC_B_KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("b'",25);break;
            case KC_B_KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY("b;",25);break;
            case KC_W_KC_F__h : SEND_STRING_DELAY("h",25);break;
            case KC_D_KC_F__j : SEND_STRING_DELAY("j",25);break;
            case KC_S_KC_D__k : SEND_STRING_DELAY("k",25);break;
            case KC_S_KC_F__l : SEND_STRING_DELAY("l",25);break;
            case KC_A_KC_F__nodisplaychar : SEND_STRING_DELAY(";",25);break;
            case KC_A_KC_S__nodisplaychar : SEND_STRING_DELAY(":",25);break;
            case KC_S_KC_C__n : SEND_STRING_DELAY("n",25);break;
            case KC_C_KC_V__m : SEND_STRING_DELAY("m",25);break;
            case KC_X_KC_C__nodisplaychar : SEND_STRING_DELAY(",",25);break;
            case KC_A_KC_T__nodisplaychar : SEND_STRING_DELAY("<",25);break;
            case KC_X_KC_V__nodisplaychar : SEND_STRING_DELAY(".",25);break;
            case KC_Z_KC_V__nodisplaychar : SEND_STRING_DELAY("/",25);break;
            case KC_Z_KC_X__nodisplaychar : SEND_STRING_DELAY("?",25);break;
            case KC_E_KC_F__y : SEND_STRING_DELAY("y",25);break;
            case KC_E_KC_R__u : SEND_STRING_DELAY("u",25);break;
            case KC_W_KC_E__i : SEND_STRING_DELAY("i",25);break;
            case KC_W_KC_R__o : SEND_STRING_DELAY("o",25);break;
            case KC_R_KC_Q__p : SEND_STRING_DELAY("p",25);break;
            case KC_I_KC_J__y : SEND_STRING_DELAY("y",25);break;
            case KC_U_KC_I__u : SEND_STRING_DELAY("u",25);break;
            case KC_I_KC_O__i : SEND_STRING_DELAY("i",25);break;
            case KC_U_KC_O__o : SEND_STRING_DELAY("o",25);break;
            case KC_U_KC_P__p : SEND_STRING_DELAY("p",25);break;
            case KC_J_KC_O__h : SEND_STRING_DELAY("h",25);break;
            case KC_J_KC_K__j : SEND_STRING_DELAY("j",25);break;
            case KC_K_KC_L__k : SEND_STRING_DELAY("k",25);break;
            case KC_J_KC_L__l : SEND_STRING_DELAY("l",25);break;
            case KC_L_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(":",25);break;
            case KC_L_KC_COMMA__n : SEND_STRING_DELAY("n",25);break;
            case KC_M_KC_COMMA__m : SEND_STRING_DELAY("m",25);break;
            case KC_COMMA_KC_DOT__nodisplaychar : SEND_STRING_DELAY(",",25);break;
            case KC_M_KC_DOT__nodisplaychar : SEND_STRING_DELAY(".",25);break;
            case KC_M_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("/",25);break;
            case KC_SEMICOLON_KC_Y__nodisplaychar : SEND_STRING_DELAY(">",25);break;
            case KC_DOT_KC_SLASH__nodisplaychar : SEND_STRING_DELAY("?",25);break;
            case KC_N_KC_M__nodisplaychar : SEND_STRING_DELAY("'",25);break;
            case KC_J_KC_SEMICOLON__nodisplaychar : SEND_STRING_DELAY(";",25);break;
        }
        }
    }
