/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_set_time_screen(lv_ui *ui)
{
    //Write codes set_time_screen
    ui->set_time_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->set_time_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->set_time_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for set_time_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->set_time_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->set_time_screen, &_Slide2_RGB565A8_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->set_time_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->set_time_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_label_1
    ui->set_time_screen_label_1 = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_label_1, 117, 5);
    lv_obj_set_size(ui->set_time_screen_label_1, 46, 9);
    lv_label_set_text(ui->set_time_screen_label_1, "MCU:");
    lv_label_set_long_mode(ui->set_time_screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_label_1, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_label_2
    ui->set_time_screen_label_2 = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_label_2, 229, 5);
    lv_obj_set_size(ui->set_time_screen_label_2, 46, 9);
    lv_label_set_text(ui->set_time_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->set_time_screen_label_2, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_label_3
    ui->set_time_screen_label_3 = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_label_3, 135, 30);
    lv_obj_set_size(ui->set_time_screen_label_3, 206, 23);
    lv_label_set_text(ui->set_time_screen_label_3, "Config Time");
    lv_label_set_long_mode(ui->set_time_screen_label_3, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_label_3, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_label_3, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_label_4
    ui->set_time_screen_label_4 = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_label_4, 118, 81);
    lv_obj_set_size(ui->set_time_screen_label_4, 105, 10);
    lv_label_set_text(ui->set_time_screen_label_4, "Hours");
    lv_label_set_long_mode(ui->set_time_screen_label_4, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_label_4, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_label_5
    ui->set_time_screen_label_5 = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_label_5, 258, 81);
    lv_obj_set_size(ui->set_time_screen_label_5, 105, 10);
    lv_label_set_text(ui->set_time_screen_label_5, "Minutes");
    lv_label_set_long_mode(ui->set_time_screen_label_5, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_label_5, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_MenuBTN
    ui->set_time_screen_MenuBTN = lv_button_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_MenuBTN, 15, 280);
    lv_obj_set_size(ui->set_time_screen_MenuBTN, 120, 30);
    ui->set_time_screen_MenuBTN_label = lv_label_create(ui->set_time_screen_MenuBTN);
    lv_label_set_text(ui->set_time_screen_MenuBTN_label, "Menu");
    lv_label_set_long_mode(ui->set_time_screen_MenuBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->set_time_screen_MenuBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->set_time_screen_MenuBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->set_time_screen_MenuBTN_label, LV_PCT(100));

    //Write style for set_time_screen_MenuBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->set_time_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_MenuBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_MenuBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->set_time_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_MenuBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_MenuBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_MenuBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_MenuBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_SetBtn
    ui->set_time_screen_SetBtn = lv_button_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_SetBtn, 180, 205);
    lv_obj_set_size(ui->set_time_screen_SetBtn, 120, 30);
    ui->set_time_screen_SetBtn_label = lv_label_create(ui->set_time_screen_SetBtn);
    lv_label_set_text(ui->set_time_screen_SetBtn_label, "Set");
    lv_label_set_long_mode(ui->set_time_screen_SetBtn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->set_time_screen_SetBtn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->set_time_screen_SetBtn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->set_time_screen_SetBtn_label, LV_PCT(100));

    //Write style for set_time_screen_SetBtn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->set_time_screen_SetBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_SetBtn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_SetBtn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->set_time_screen_SetBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_SetBtn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_SetBtn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_SetBtn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_SetBtn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_SetBtn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_SetBtn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_MCUTempLabel
    ui->set_time_screen_MCUTempLabel = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->set_time_screen_MCUTempLabel, 69, 9);
    lv_label_set_text(ui->set_time_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->set_time_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_BRDTempLabel
    ui->set_time_screen_BRDTempLabel = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_BRDTempLabel, 265, 5);
    lv_obj_set_size(ui->set_time_screen_BRDTempLabel, 69, 9);
    lv_label_set_text(ui->set_time_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->set_time_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_DateLabel
    ui->set_time_screen_DateLabel = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->set_time_screen_DateLabel, 143, 12);
    lv_label_set_text(ui->set_time_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->set_time_screen_DateLabel, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_HourLabel
    ui->set_time_screen_HourLabel = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_HourLabel, 3, 5);
    lv_obj_set_size(ui->set_time_screen_HourLabel, 105, 10);
    lv_label_set_text(ui->set_time_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->set_time_screen_HourLabel, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_IPLabel
    ui->set_time_screen_IPLabel = lv_label_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_IPLabel, 180, 305);
    lv_obj_set_size(ui->set_time_screen_IPLabel, 120, 12);
    lv_label_set_text(ui->set_time_screen_IPLabel, "192.168.001.100");
    lv_label_set_long_mode(ui->set_time_screen_IPLabel, LV_LABEL_LONG_WRAP);

    //Write style for set_time_screen_IPLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_IPLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_IPLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_IPLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_IPLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes set_time_screen_HourRoller
    ui->set_time_screen_HourRoller = lv_roller_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_HourRoller, 120, 100);
    lv_obj_set_width(ui->set_time_screen_HourRoller, 100);
    lv_roller_set_options(ui->set_time_screen_HourRoller, "01\n02\n03\n04\n05\n06\n07\n08\n09\n10\n11\n12", LV_ROLLER_MODE_INFINITE);

    //Write style for set_time_screen_HourRoller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->set_time_screen_HourRoller, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_HourRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_HourRoller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_HourRoller, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_HourRoller, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_HourRoller, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_HourRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_HourRoller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->set_time_screen_HourRoller, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->set_time_screen_HourRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->set_time_screen_HourRoller, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->set_time_screen_HourRoller, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_HourRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_HourRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_HourRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for set_time_screen_HourRoller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->set_time_screen_HourRoller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_HourRoller, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_HourRoller, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_HourRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_HourRoller, &lv_font_montserratMedium_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_HourRoller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->set_time_screen_HourRoller, 3);
    //Write codes set_time_screen_MinutesTensRoller
    ui->set_time_screen_MinutesTensRoller = lv_roller_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_MinutesTensRoller, 285, 100);
    lv_obj_set_width(ui->set_time_screen_MinutesTensRoller, 23);
    lv_roller_set_options(ui->set_time_screen_MinutesTensRoller, "0\n1\n2\n3\n4\n5", LV_ROLLER_MODE_INFINITE);

    //Write style for set_time_screen_MinutesTensRoller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->set_time_screen_MinutesTensRoller, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_MinutesTensRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_MinutesTensRoller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_MinutesTensRoller, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_MinutesTensRoller, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_MinutesTensRoller, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_MinutesTensRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_MinutesTensRoller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->set_time_screen_MinutesTensRoller, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->set_time_screen_MinutesTensRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->set_time_screen_MinutesTensRoller, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->set_time_screen_MinutesTensRoller, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_MinutesTensRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_MinutesTensRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_MinutesTensRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for set_time_screen_MinutesTensRoller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->set_time_screen_MinutesTensRoller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_MinutesTensRoller, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_MinutesTensRoller, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_MinutesTensRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_MinutesTensRoller, &lv_font_montserratMedium_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_MinutesTensRoller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->set_time_screen_MinutesTensRoller, 3);
    //Write codes set_time_screen_MinutesUnitsRoller
    ui->set_time_screen_MinutesUnitsRoller = lv_roller_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_MinutesUnitsRoller, 312, 100);
    lv_obj_set_width(ui->set_time_screen_MinutesUnitsRoller, 23);
    lv_roller_set_options(ui->set_time_screen_MinutesUnitsRoller, "0\n1\n2\n3\n4\n5\n6\n7\n8\n9", LV_ROLLER_MODE_INFINITE);

    //Write style for set_time_screen_MinutesUnitsRoller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->set_time_screen_MinutesUnitsRoller, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_MinutesUnitsRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_MinutesUnitsRoller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_MinutesUnitsRoller, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_MinutesUnitsRoller, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_MinutesUnitsRoller, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_MinutesUnitsRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_MinutesUnitsRoller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->set_time_screen_MinutesUnitsRoller, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->set_time_screen_MinutesUnitsRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->set_time_screen_MinutesUnitsRoller, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->set_time_screen_MinutesUnitsRoller, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_MinutesUnitsRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_MinutesUnitsRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_MinutesUnitsRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for set_time_screen_MinutesUnitsRoller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->set_time_screen_MinutesUnitsRoller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_MinutesUnitsRoller, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_MinutesUnitsRoller, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_MinutesUnitsRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_MinutesUnitsRoller, &lv_font_montserratMedium_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_MinutesUnitsRoller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->set_time_screen_MinutesUnitsRoller, 3);
    //Write codes set_time_screen_MeridianRoller
    ui->set_time_screen_MeridianRoller = lv_roller_create(ui->set_time_screen);
    lv_obj_set_pos(ui->set_time_screen_MeridianRoller, 363, 100);
    lv_obj_set_width(ui->set_time_screen_MeridianRoller, 42);
    lv_roller_set_options(ui->set_time_screen_MeridianRoller, "am\npm", LV_ROLLER_MODE_INFINITE);

    //Write style for set_time_screen_MeridianRoller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->set_time_screen_MeridianRoller, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->set_time_screen_MeridianRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_MeridianRoller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_MeridianRoller, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_MeridianRoller, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_MeridianRoller, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_MeridianRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->set_time_screen_MeridianRoller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->set_time_screen_MeridianRoller, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->set_time_screen_MeridianRoller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->set_time_screen_MeridianRoller, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->set_time_screen_MeridianRoller, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->set_time_screen_MeridianRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->set_time_screen_MeridianRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->set_time_screen_MeridianRoller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for set_time_screen_MeridianRoller, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->set_time_screen_MeridianRoller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->set_time_screen_MeridianRoller, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->set_time_screen_MeridianRoller, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->set_time_screen_MeridianRoller, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->set_time_screen_MeridianRoller, &lv_font_montserratMedium_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->set_time_screen_MeridianRoller, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->set_time_screen_MeridianRoller, 3);
    //The custom code of set_time_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->set_time_screen);

    //Init events for screen.
    events_init_set_time_screen(ui);
}
