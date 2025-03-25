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



void setup_scr_accelerometer_measure_screen(lv_ui *ui)
{
    //Write codes accelerometer_measure_screen
    ui->accelerometer_measure_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->accelerometer_measure_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->accelerometer_measure_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for accelerometer_measure_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->accelerometer_measure_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->accelerometer_measure_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->accelerometer_measure_screen, &_Slide2_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->accelerometer_measure_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->accelerometer_measure_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_DateLabel
    ui->accelerometer_measure_screen_DateLabel = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_DateLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->accelerometer_measure_screen_DateLabel, 143, 12);

    //Write style for accelerometer_measure_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_DateLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_HourLabel
    ui->accelerometer_measure_screen_HourLabel = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_HourLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_HourLabel, 4, 5);
    lv_obj_set_size(ui->accelerometer_measure_screen_HourLabel, 105, 10);

    //Write style for accelerometer_measure_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_HourLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_MCUTempLabel
    ui->accelerometer_measure_screen_MCUTempLabel = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->accelerometer_measure_screen_MCUTempLabel, 69, 9);

    //Write style for accelerometer_measure_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_MCUTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_BRDTempLabel
    ui->accelerometer_measure_screen_BRDTempLabel = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_BRDTempLabel, 264, 5);
    lv_obj_set_size(ui->accelerometer_measure_screen_BRDTempLabel, 69, 9);

    //Write style for accelerometer_measure_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_BRDTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_label_3
    ui->accelerometer_measure_screen_label_3 = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_label_3, "MCU:");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_label_3, 117, 5);
    lv_obj_set_size(ui->accelerometer_measure_screen_label_3, 46, 9);

    //Write style for accelerometer_measure_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_label_3, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_label_2
    ui->accelerometer_measure_screen_label_2 = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_label_2, 229, 5);
    lv_obj_set_size(ui->accelerometer_measure_screen_label_2, 46, 9);

    //Write style for accelerometer_measure_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_label_1
    ui->accelerometer_measure_screen_label_1 = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_label_1, "Accelerometer");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_label_1, 140, 30);
    lv_obj_set_size(ui->accelerometer_measure_screen_label_1, 200, 20);

    //Write style for accelerometer_measure_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_label_1, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_MenuBTN
    ui->accelerometer_measure_screen_MenuBTN = lv_btn_create(ui->accelerometer_measure_screen);
    ui->accelerometer_measure_screen_MenuBTN_label = lv_label_create(ui->accelerometer_measure_screen_MenuBTN);
    lv_label_set_text(ui->accelerometer_measure_screen_MenuBTN_label, "Menu");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_MenuBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->accelerometer_measure_screen_MenuBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->accelerometer_measure_screen_MenuBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->accelerometer_measure_screen_MenuBTN_label, LV_PCT(100));
    lv_obj_set_pos(ui->accelerometer_measure_screen_MenuBTN, 15, 280);
    lv_obj_set_size(ui->accelerometer_measure_screen_MenuBTN, 120, 30);

    //Write style for accelerometer_measure_screen_MenuBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->accelerometer_measure_screen_MenuBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->accelerometer_measure_screen_MenuBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_MenuBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_MenuBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_MenuBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_MenuBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_AccelXBar
    ui->accelerometer_measure_screen_AccelXBar = lv_bar_create(ui->accelerometer_measure_screen);
    lv_obj_set_style_anim_time(ui->accelerometer_measure_screen_AccelXBar, 1000, 0);
    lv_bar_set_mode(ui->accelerometer_measure_screen_AccelXBar, LV_BAR_MODE_SYMMETRICAL);
    lv_bar_set_range(ui->accelerometer_measure_screen_AccelXBar, -10, 10);
    lv_bar_set_value(ui->accelerometer_measure_screen_AccelXBar, 2, LV_ANIM_OFF);
    lv_obj_set_pos(ui->accelerometer_measure_screen_AccelXBar, 230, 90);
    lv_obj_set_size(ui->accelerometer_measure_screen_AccelXBar, 170, 40);

    //Write style for accelerometer_measure_screen_AccelXBar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelXBar, 96, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->accelerometer_measure_screen_AccelXBar, lv_color_hex(0x0068DF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->accelerometer_measure_screen_AccelXBar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelXBar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_AccelXBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for accelerometer_measure_screen_AccelXBar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelXBar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->accelerometer_measure_screen_AccelXBar, lv_color_hex(0x0068DF), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->accelerometer_measure_screen_AccelXBar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelXBar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_AccelYBar
    ui->accelerometer_measure_screen_AccelYBar = lv_bar_create(ui->accelerometer_measure_screen);
    lv_obj_set_style_anim_time(ui->accelerometer_measure_screen_AccelYBar, 1000, 0);
    lv_bar_set_mode(ui->accelerometer_measure_screen_AccelYBar, LV_BAR_MODE_SYMMETRICAL);
    lv_bar_set_range(ui->accelerometer_measure_screen_AccelYBar, -10, 10);
    lv_bar_set_value(ui->accelerometer_measure_screen_AccelYBar, -5, LV_ANIM_OFF);
    lv_obj_set_pos(ui->accelerometer_measure_screen_AccelYBar, 230, 140);
    lv_obj_set_size(ui->accelerometer_measure_screen_AccelYBar, 170, 40);

    //Write style for accelerometer_measure_screen_AccelYBar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelYBar, 96, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->accelerometer_measure_screen_AccelYBar, lv_color_hex(0xFF7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->accelerometer_measure_screen_AccelYBar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelYBar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_AccelYBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for accelerometer_measure_screen_AccelYBar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelYBar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->accelerometer_measure_screen_AccelYBar, lv_color_hex(0xFF7400), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->accelerometer_measure_screen_AccelYBar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelYBar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_AccelZBar
    ui->accelerometer_measure_screen_AccelZBar = lv_bar_create(ui->accelerometer_measure_screen);
    lv_obj_set_style_anim_time(ui->accelerometer_measure_screen_AccelZBar, 1000, 0);
    lv_bar_set_mode(ui->accelerometer_measure_screen_AccelZBar, LV_BAR_MODE_SYMMETRICAL);
    lv_bar_set_range(ui->accelerometer_measure_screen_AccelZBar, -10, 10);
    lv_bar_set_value(ui->accelerometer_measure_screen_AccelZBar, 5, LV_ANIM_OFF);
    lv_obj_set_pos(ui->accelerometer_measure_screen_AccelZBar, 231, 190);
    lv_obj_set_size(ui->accelerometer_measure_screen_AccelZBar, 170, 40);

    //Write style for accelerometer_measure_screen_AccelZBar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelZBar, 96, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->accelerometer_measure_screen_AccelZBar, lv_color_hex(0x00A700), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->accelerometer_measure_screen_AccelZBar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelZBar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_AccelZBar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for accelerometer_measure_screen_AccelZBar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelZBar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->accelerometer_measure_screen_AccelZBar, lv_color_hex(0x00A700), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->accelerometer_measure_screen_AccelZBar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelZBar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_label_4
    ui->accelerometer_measure_screen_label_4 = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_label_4, "Accel X:");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_label_4, 61, 105);
    lv_obj_set_size(ui->accelerometer_measure_screen_label_4, 62, 10);

    //Write style for accelerometer_measure_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_label_4, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_label_5
    ui->accelerometer_measure_screen_label_5 = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_label_5, "Accel Y:");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_label_5, 61, 155);
    lv_obj_set_size(ui->accelerometer_measure_screen_label_5, 62, 10);

    //Write style for accelerometer_measure_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_label_5, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_label_6
    ui->accelerometer_measure_screen_label_6 = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_label_6, "Accel Z:");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_label_6, 61, 205);
    lv_obj_set_size(ui->accelerometer_measure_screen_label_6, 62, 10);

    //Write style for accelerometer_measure_screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_label_6, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_label_6, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_AccelXLabel
    ui->accelerometer_measure_screen_AccelXLabel = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_AccelXLabel, " 00.00 m/s^2");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_AccelXLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_AccelXLabel, 123, 105);
    lv_obj_set_size(ui->accelerometer_measure_screen_AccelXLabel, 100, 11);

    //Write style for accelerometer_measure_screen_AccelXLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_AccelXLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_AccelXLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_AccelXLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_AccelXLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_AccelXLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_AccelXLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_AccelYLabel
    ui->accelerometer_measure_screen_AccelYLabel = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_AccelYLabel, " 00.00 m/s^2");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_AccelYLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_AccelYLabel, 123, 155);
    lv_obj_set_size(ui->accelerometer_measure_screen_AccelYLabel, 100, 11);

    //Write style for accelerometer_measure_screen_AccelYLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_AccelYLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_AccelYLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_AccelYLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_AccelYLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_AccelYLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_AccelYLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_AccelZLabel
    ui->accelerometer_measure_screen_AccelZLabel = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_AccelZLabel, " 00.00 m/s^2");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_AccelZLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_AccelZLabel, 123, 204);
    lv_obj_set_size(ui->accelerometer_measure_screen_AccelZLabel, 100, 11);

    //Write style for accelerometer_measure_screen_AccelZLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_AccelZLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_AccelZLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_AccelZLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_AccelZLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_AccelZLabel, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_AccelZLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes accelerometer_measure_screen_IPLabel
    ui->accelerometer_measure_screen_IPLabel = lv_label_create(ui->accelerometer_measure_screen);
    lv_label_set_text(ui->accelerometer_measure_screen_IPLabel, "192.168.001.100");
    lv_label_set_long_mode(ui->accelerometer_measure_screen_IPLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->accelerometer_measure_screen_IPLabel, 180, 305);
    lv_obj_set_size(ui->accelerometer_measure_screen_IPLabel, 120, 12);

    //Write style for accelerometer_measure_screen_IPLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->accelerometer_measure_screen_IPLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->accelerometer_measure_screen_IPLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->accelerometer_measure_screen_IPLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->accelerometer_measure_screen_IPLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->accelerometer_measure_screen_IPLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->accelerometer_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of accelerometer_measure_screen.
    //lv_obj_set_style_transform_angle(ui->AccelXBar,180,0);

    //Update current screen layout.
    lv_obj_update_layout(ui->accelerometer_measure_screen);

    //Init events for screen.
    events_init_accelerometer_measure_screen(ui);
}
