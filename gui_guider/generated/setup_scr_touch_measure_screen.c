/*
* Copyright 2025 NXP
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



void setup_scr_touch_measure_screen(lv_ui *ui)
{
    //Write codes touch_measure_screen
    ui->touch_measure_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->touch_measure_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->touch_measure_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for touch_measure_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->touch_measure_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->touch_measure_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->touch_measure_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->touch_measure_screen, &_Slide2_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->touch_measure_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->touch_measure_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_DateLabel
    ui->touch_measure_screen_DateLabel = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->touch_measure_screen_DateLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->touch_measure_screen_DateLabel, 143, 12);

    //Write style for touch_measure_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_DateLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_HourLabel
    ui->touch_measure_screen_HourLabel = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->touch_measure_screen_HourLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_HourLabel, 4, 5);
    lv_obj_set_size(ui->touch_measure_screen_HourLabel, 105, 10);

    //Write style for touch_measure_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_HourLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_MCUTempLabel
    ui->touch_measure_screen_MCUTempLabel = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->touch_measure_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->touch_measure_screen_MCUTempLabel, 69, 9);

    //Write style for touch_measure_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_MCUTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_BRDTempLabel
    ui->touch_measure_screen_BRDTempLabel = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->touch_measure_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_BRDTempLabel, 264, 5);
    lv_obj_set_size(ui->touch_measure_screen_BRDTempLabel, 69, 9);

    //Write style for touch_measure_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_BRDTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_label_3
    ui->touch_measure_screen_label_3 = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_label_3, "MCU:");
    lv_label_set_long_mode(ui->touch_measure_screen_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_label_3, 117, 5);
    lv_obj_set_size(ui->touch_measure_screen_label_3, 46, 9);

    //Write style for touch_measure_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_label_3, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_label_2
    ui->touch_measure_screen_label_2 = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->touch_measure_screen_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_label_2, 229, 5);
    lv_obj_set_size(ui->touch_measure_screen_label_2, 46, 9);

    //Write style for touch_measure_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_label_1
    ui->touch_measure_screen_label_1 = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_label_1, "Touch Sense");
    lv_label_set_long_mode(ui->touch_measure_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_label_1, 140, 30);
    lv_obj_set_size(ui->touch_measure_screen_label_1, 200, 20);

    //Write style for touch_measure_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_label_1, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_MenuBTN
    ui->touch_measure_screen_MenuBTN = lv_btn_create(ui->touch_measure_screen);
    ui->touch_measure_screen_MenuBTN_label = lv_label_create(ui->touch_measure_screen_MenuBTN);
    lv_label_set_text(ui->touch_measure_screen_MenuBTN_label, "Menu");
    lv_label_set_long_mode(ui->touch_measure_screen_MenuBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->touch_measure_screen_MenuBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->touch_measure_screen_MenuBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->touch_measure_screen_MenuBTN_label, LV_PCT(100));
    lv_obj_set_pos(ui->touch_measure_screen_MenuBTN, 15, 280);
    lv_obj_set_size(ui->touch_measure_screen_MenuBTN, 120, 30);

    //Write style for touch_measure_screen_MenuBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->touch_measure_screen_MenuBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->touch_measure_screen_MenuBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->touch_measure_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_MenuBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_MenuBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_MenuBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_MenuBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_TouchArc
    ui->touch_measure_screen_TouchArc = lv_arc_create(ui->touch_measure_screen);
    lv_arc_set_mode(ui->touch_measure_screen_TouchArc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->touch_measure_screen_TouchArc, 0, 100);
    lv_arc_set_bg_angles(ui->touch_measure_screen_TouchArc, 135, 45);
    lv_arc_set_value(ui->touch_measure_screen_TouchArc, 20);
    lv_arc_set_rotation(ui->touch_measure_screen_TouchArc, 0);
    lv_obj_set_pos(ui->touch_measure_screen_TouchArc, 150, 70);
    lv_obj_set_size(ui->touch_measure_screen_TouchArc, 180, 180);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->touch_measure_screen_TouchArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->touch_measure_screen_TouchArc, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->touch_measure_screen_TouchArc, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_TouchArc, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_arc_width(ui->touch_measure_screen_TouchArc, 20, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_arc_opa(ui->touch_measure_screen_TouchArc, 100, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_arc_color(ui->touch_measure_screen_TouchArc, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui->touch_measure_screen_TouchArc, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_FOCUSED);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->touch_measure_screen_TouchArc, 6, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_arc_width(ui->touch_measure_screen_TouchArc, 20, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_arc_opa(ui->touch_measure_screen_TouchArc, 100, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_arc_color(ui->touch_measure_screen_TouchArc, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_TouchArc, 10, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_TouchArc, 0, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->touch_measure_screen_TouchArc, 20, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->touch_measure_screen_TouchArc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->touch_measure_screen_TouchArc, lv_color_hex(0xC6EB00), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_INDICATOR, State: LV_STATE_FOCUSED.
    lv_obj_set_style_arc_width(ui->touch_measure_screen_TouchArc, 20, LV_PART_INDICATOR|LV_STATE_FOCUSED);
    lv_obj_set_style_arc_opa(ui->touch_measure_screen_TouchArc, 255, LV_PART_INDICATOR|LV_STATE_FOCUSED);
    lv_obj_set_style_arc_color(ui->touch_measure_screen_TouchArc, lv_color_hex(0xC6EB00), LV_PART_INDICATOR|LV_STATE_FOCUSED);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_INDICATOR, State: LV_STATE_DISABLED.
    lv_obj_set_style_arc_width(ui->touch_measure_screen_TouchArc, 20, LV_PART_INDICATOR|LV_STATE_DISABLED);
    lv_obj_set_style_arc_opa(ui->touch_measure_screen_TouchArc, 255, LV_PART_INDICATOR|LV_STATE_DISABLED);
    lv_obj_set_style_arc_color(ui->touch_measure_screen_TouchArc, lv_color_hex(0xC6EB00), LV_PART_INDICATOR|LV_STATE_DISABLED);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_TouchArc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->touch_measure_screen_TouchArc, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_KNOB, State: LV_STATE_FOCUSED.
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_TouchArc, 0, LV_PART_KNOB|LV_STATE_FOCUSED);
    lv_obj_set_style_pad_all(ui->touch_measure_screen_TouchArc, 5, LV_PART_KNOB|LV_STATE_FOCUSED);

    //Write style for touch_measure_screen_TouchArc, Part: LV_PART_KNOB, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_TouchArc, 0, LV_PART_KNOB|LV_STATE_DISABLED);
    lv_obj_set_style_pad_all(ui->touch_measure_screen_TouchArc, 5, LV_PART_KNOB|LV_STATE_DISABLED);

    //Write codes touch_measure_screen_label_5
    ui->touch_measure_screen_label_5 = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_label_5, "Electrode");
    lv_label_set_long_mode(ui->touch_measure_screen_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_label_5, 190, 147);
    lv_obj_set_size(ui->touch_measure_screen_label_5, 100, 15);

    //Write style for touch_measure_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_label_5, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_ElectrodeLabel
    ui->touch_measure_screen_ElectrodeLabel = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_ElectrodeLabel, "0.00 v");
    lv_label_set_long_mode(ui->touch_measure_screen_ElectrodeLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_ElectrodeLabel, 190, 168);
    lv_obj_set_size(ui->touch_measure_screen_ElectrodeLabel, 100, 15);

    //Write style for touch_measure_screen_ElectrodeLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_ElectrodeLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_ElectrodeLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_ElectrodeLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_ElectrodeLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_ElectrodeLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_ElectrodeLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_img_1
    ui->touch_measure_screen_img_1 = lv_img_create(ui->touch_measure_screen);
    lv_obj_add_flag(ui->touch_measure_screen_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_pivot(ui->touch_measure_screen_img_1, 50,50);
    lv_img_set_angle(ui->touch_measure_screen_img_1, 0);
    lv_obj_set_pos(ui->touch_measure_screen_img_1, 54, 68);
    lv_obj_set_size(ui->touch_measure_screen_img_1, 375, 183);

    //Write style for touch_measure_screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->touch_measure_screen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->touch_measure_screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->touch_measure_screen_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes touch_measure_screen_IPLabel
    ui->touch_measure_screen_IPLabel = lv_label_create(ui->touch_measure_screen);
    lv_label_set_text(ui->touch_measure_screen_IPLabel, "192.168.001.100");
    lv_label_set_long_mode(ui->touch_measure_screen_IPLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->touch_measure_screen_IPLabel, 180, 305);
    lv_obj_set_size(ui->touch_measure_screen_IPLabel, 120, 12);

    //Write style for touch_measure_screen_IPLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->touch_measure_screen_IPLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->touch_measure_screen_IPLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->touch_measure_screen_IPLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->touch_measure_screen_IPLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->touch_measure_screen_IPLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->touch_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of touch_measure_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->touch_measure_screen);

    //Init events for screen.
    events_init_touch_measure_screen(ui);
}
