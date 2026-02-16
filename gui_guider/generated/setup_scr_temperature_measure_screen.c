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



void setup_scr_temperature_measure_screen(lv_ui *ui)
{
    //Write codes temperature_measure_screen
    ui->temperature_measure_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->temperature_measure_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->temperature_measure_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for temperature_measure_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->temperature_measure_screen, &_Slide2_RGB565A8_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->temperature_measure_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->temperature_measure_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_label_1
    ui->temperature_measure_screen_label_1 = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_label_1, 117, 5);
    lv_obj_set_size(ui->temperature_measure_screen_label_1, 46, 9);
    lv_label_set_text(ui->temperature_measure_screen_label_1, "MCU:");
    lv_label_set_long_mode(ui->temperature_measure_screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_label_1, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_label_2
    ui->temperature_measure_screen_label_2 = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_label_2, 229, 5);
    lv_obj_set_size(ui->temperature_measure_screen_label_2, 46, 9);
    lv_label_set_text(ui->temperature_measure_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->temperature_measure_screen_label_2, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_label_3
    ui->temperature_measure_screen_label_3 = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_label_3, 135, 30);
    lv_obj_set_size(ui->temperature_measure_screen_label_3, 206, 23);
    lv_label_set_text(ui->temperature_measure_screen_label_3, "Temperature");
    lv_label_set_long_mode(ui->temperature_measure_screen_label_3, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_label_3, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_label_3, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_MCUTempLabel
    ui->temperature_measure_screen_MCUTempLabel = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->temperature_measure_screen_MCUTempLabel, 69, 9);
    lv_label_set_text(ui->temperature_measure_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->temperature_measure_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_BRDTempLabel
    ui->temperature_measure_screen_BRDTempLabel = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_BRDTempLabel, 265, 5);
    lv_obj_set_size(ui->temperature_measure_screen_BRDTempLabel, 69, 9);
    lv_label_set_text(ui->temperature_measure_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->temperature_measure_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_HourLabel
    ui->temperature_measure_screen_HourLabel = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_HourLabel, 3, 5);
    lv_obj_set_size(ui->temperature_measure_screen_HourLabel, 105, 10);
    lv_label_set_text(ui->temperature_measure_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->temperature_measure_screen_HourLabel, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_DateLabel
    ui->temperature_measure_screen_DateLabel = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->temperature_measure_screen_DateLabel, 143, 12);
    lv_label_set_text(ui->temperature_measure_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->temperature_measure_screen_DateLabel, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_IPLabel
    ui->temperature_measure_screen_IPLabel = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_IPLabel, 180, 305);
    lv_obj_set_size(ui->temperature_measure_screen_IPLabel, 120, 12);
    lv_label_set_text(ui->temperature_measure_screen_IPLabel, "192.168.001.100");
    lv_label_set_long_mode(ui->temperature_measure_screen_IPLabel, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_IPLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_IPLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_IPLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_IPLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_IPLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_MenuBTN
    ui->temperature_measure_screen_MenuBTN = lv_button_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_MenuBTN, 15, 280);
    lv_obj_set_size(ui->temperature_measure_screen_MenuBTN, 120, 30);
    ui->temperature_measure_screen_MenuBTN_label = lv_label_create(ui->temperature_measure_screen_MenuBTN);
    lv_label_set_text(ui->temperature_measure_screen_MenuBTN_label, "Menu");
    lv_label_set_long_mode(ui->temperature_measure_screen_MenuBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->temperature_measure_screen_MenuBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->temperature_measure_screen_MenuBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->temperature_measure_screen_MenuBTN_label, LV_PCT(100));

    //Write style for temperature_measure_screen_MenuBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->temperature_measure_screen_MenuBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->temperature_measure_screen_MenuBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->temperature_measure_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_MenuBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_MenuBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_MenuBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_MenuBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_MCUTempMeter
    ui->temperature_measure_screen_MCUTempMeter = lv_scale_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_MCUTempMeter, 50, 70);
    lv_obj_set_size(ui->temperature_measure_screen_MCUTempMeter, 180, 180);
    lv_obj_update_layout(ui->temperature_measure_screen_MCUTempMeter);
    lv_scale_set_mode(ui->temperature_measure_screen_MCUTempMeter, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_total_tick_count(ui->temperature_measure_screen_MCUTempMeter, 71);
    lv_scale_set_major_tick_every(ui->temperature_measure_screen_MCUTempMeter, 10);
    lv_scale_set_label_show(ui->temperature_measure_screen_MCUTempMeter, true);
    lv_scale_set_range(ui->temperature_measure_screen_MCUTempMeter, -10, 60);
    lv_scale_set_angle_range(ui->temperature_measure_screen_MCUTempMeter, 270);
    lv_scale_set_rotation(ui->temperature_measure_screen_MCUTempMeter, 135);
    lv_scale_set_post_draw(ui->temperature_measure_screen_MCUTempMeter, true);
    lv_scale_section_t * temperature_measure_screen_MCUTempMeter_section_0 = lv_scale_add_section(ui->temperature_measure_screen_MCUTempMeter);
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_0_minor_tick_style;
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_0_label_style;
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_0_main_line_style;
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_0_label_style);
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_0_minor_tick_style);
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_0_main_line_style);

    lv_scale_section_set_range(temperature_measure_screen_MCUTempMeter_section_0, 0, 40);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_0, LV_PART_INDICATOR, &temperature_measure_screen_MCUTempMeter_section_0_label_style);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_0, LV_PART_MAIN, &temperature_measure_screen_MCUTempMeter_section_0_main_line_style);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_0, LV_PART_ITEMS, &temperature_measure_screen_MCUTempMeter_section_0_minor_tick_style);

    lv_style_set_text_color(&temperature_measure_screen_MCUTempMeter_section_0_label_style, lv_color_hex(0xffffff));
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_0_label_style, lv_color_hex(0x00A700));
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_0_minor_tick_style, lv_color_hex(0x00A700));
    lv_style_set_line_width(&temperature_measure_screen_MCUTempMeter_section_0_minor_tick_style, 2);
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_0_label_style, lv_color_hex(0x00A700));
    lv_style_set_line_width(&temperature_measure_screen_MCUTempMeter_section_0_label_style, 2);
    lv_style_set_arc_color(&temperature_measure_screen_MCUTempMeter_section_0_main_line_style, lv_color_hex(0x00A700));
    lv_style_set_arc_width(&temperature_measure_screen_MCUTempMeter_section_0_main_line_style, 0);
    lv_scale_section_t * temperature_measure_screen_MCUTempMeter_section_1 = lv_scale_add_section(ui->temperature_measure_screen_MCUTempMeter);
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_1_minor_tick_style;
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_1_label_style;
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_1_main_line_style;
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_1_label_style);
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_1_minor_tick_style);
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_1_main_line_style);

    lv_scale_section_set_range(temperature_measure_screen_MCUTempMeter_section_1, -10, 0);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_1, LV_PART_INDICATOR, &temperature_measure_screen_MCUTempMeter_section_1_label_style);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_1, LV_PART_MAIN, &temperature_measure_screen_MCUTempMeter_section_1_main_line_style);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_1, LV_PART_ITEMS, &temperature_measure_screen_MCUTempMeter_section_1_minor_tick_style);

    lv_style_set_text_color(&temperature_measure_screen_MCUTempMeter_section_1_label_style, lv_color_hex(0xffffff));
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_1_label_style, lv_color_hex(0x0000ff));
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_1_minor_tick_style, lv_color_hex(0x0000ff));
    lv_style_set_line_width(&temperature_measure_screen_MCUTempMeter_section_1_minor_tick_style, 2);
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_1_label_style, lv_color_hex(0x0000ff));
    lv_style_set_line_width(&temperature_measure_screen_MCUTempMeter_section_1_label_style, 2);
    lv_style_set_arc_color(&temperature_measure_screen_MCUTempMeter_section_1_main_line_style, lv_color_hex(0x0000ff));
    lv_style_set_arc_width(&temperature_measure_screen_MCUTempMeter_section_1_main_line_style, 0);
    lv_scale_section_t * temperature_measure_screen_MCUTempMeter_section_2 = lv_scale_add_section(ui->temperature_measure_screen_MCUTempMeter);
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_2_minor_tick_style;
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_2_label_style;
    static lv_style_t temperature_measure_screen_MCUTempMeter_section_2_main_line_style;
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_2_label_style);
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_2_minor_tick_style);
    lv_style_init(&temperature_measure_screen_MCUTempMeter_section_2_main_line_style);

    lv_scale_section_set_range(temperature_measure_screen_MCUTempMeter_section_2, 40, 60);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_2, LV_PART_INDICATOR, &temperature_measure_screen_MCUTempMeter_section_2_label_style);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_2, LV_PART_MAIN, &temperature_measure_screen_MCUTempMeter_section_2_main_line_style);
    lv_scale_section_set_style(temperature_measure_screen_MCUTempMeter_section_2, LV_PART_ITEMS, &temperature_measure_screen_MCUTempMeter_section_2_minor_tick_style);

    lv_style_set_text_color(&temperature_measure_screen_MCUTempMeter_section_2_label_style, lv_color_hex(0xffffff));
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_2_label_style, lv_color_hex(0xf00000));
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_2_minor_tick_style, lv_color_hex(0xf00000));
    lv_style_set_line_width(&temperature_measure_screen_MCUTempMeter_section_2_minor_tick_style, 2);
    lv_style_set_line_color(&temperature_measure_screen_MCUTempMeter_section_2_label_style, lv_color_hex(0xf00000));
    lv_style_set_line_width(&temperature_measure_screen_MCUTempMeter_section_2_label_style, 2);
    lv_style_set_arc_color(&temperature_measure_screen_MCUTempMeter_section_2_main_line_style, lv_color_hex(0xf00000));
    lv_style_set_arc_width(&temperature_measure_screen_MCUTempMeter_section_2_main_line_style, 0);

    ui->temperature_measure_screen_MCUTempMeter_ndline_0 = lv_line_create(ui->temperature_measure_screen_MCUTempMeter);
    lv_obj_set_style_line_width(ui->temperature_measure_screen_MCUTempMeter_ndline_0, 2, LV_PART_MAIN);
    lv_obj_set_style_line_color(ui->temperature_measure_screen_MCUTempMeter_ndline_0, lv_color_hex(0xFF7400), LV_PART_MAIN);
    lv_obj_set_style_line_rounded(ui->temperature_measure_screen_MCUTempMeter_ndline_0, true, LV_PART_MAIN);
    lv_scale_set_line_needle_value(ui->temperature_measure_screen_MCUTempMeter, ui->temperature_measure_screen_MCUTempMeter_ndline_0, 75, 25);


    //Write style for temperature_measure_screen_MCUTempMeter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_MCUTempMeter, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->temperature_measure_screen_MCUTempMeter, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->temperature_measure_screen_MCUTempMeter, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_MCUTempMeter, 180, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_MCUTempMeter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->temperature_measure_screen_MCUTempMeter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_MCUTempMeter, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_MCUTempMeter, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_MCUTempMeter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for temperature_measure_screen_MCUTempMeter, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_length(ui->temperature_measure_screen_MCUTempMeter, 9, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->temperature_measure_screen_MCUTempMeter, 2, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->temperature_measure_screen_MCUTempMeter, lv_color_hex(0x757575), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->temperature_measure_screen_MCUTempMeter, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style for temperature_measure_screen_MCUTempMeter, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_length(ui->temperature_measure_screen_MCUTempMeter, 18, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->temperature_measure_screen_MCUTempMeter, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->temperature_measure_screen_MCUTempMeter, lv_color_hex(0x757575), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->temperature_measure_screen_MCUTempMeter, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_BRDTempMeter
    ui->temperature_measure_screen_BRDTempMeter = lv_scale_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_BRDTempMeter, 250, 70);
    lv_obj_set_size(ui->temperature_measure_screen_BRDTempMeter, 180, 180);
    lv_obj_update_layout(ui->temperature_measure_screen_BRDTempMeter);
    lv_scale_set_mode(ui->temperature_measure_screen_BRDTempMeter, LV_SCALE_MODE_ROUND_INNER);
    lv_scale_set_total_tick_count(ui->temperature_measure_screen_BRDTempMeter, 71);
    lv_scale_set_major_tick_every(ui->temperature_measure_screen_BRDTempMeter, 10);
    lv_scale_set_label_show(ui->temperature_measure_screen_BRDTempMeter, true);
    lv_scale_set_range(ui->temperature_measure_screen_BRDTempMeter, -10, 60);
    lv_scale_set_angle_range(ui->temperature_measure_screen_BRDTempMeter, 270);
    lv_scale_set_rotation(ui->temperature_measure_screen_BRDTempMeter, 135);
    lv_scale_set_post_draw(ui->temperature_measure_screen_BRDTempMeter, true);
    lv_scale_section_t * temperature_measure_screen_BRDTempMeter_section_0 = lv_scale_add_section(ui->temperature_measure_screen_BRDTempMeter);
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_0_minor_tick_style;
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_0_label_style;
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_0_main_line_style;
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_0_label_style);
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_0_minor_tick_style);
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_0_main_line_style);

    lv_scale_section_set_range(temperature_measure_screen_BRDTempMeter_section_0, 0, 40);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_0, LV_PART_INDICATOR, &temperature_measure_screen_BRDTempMeter_section_0_label_style);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_0, LV_PART_MAIN, &temperature_measure_screen_BRDTempMeter_section_0_main_line_style);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_0, LV_PART_ITEMS, &temperature_measure_screen_BRDTempMeter_section_0_minor_tick_style);

    lv_style_set_text_color(&temperature_measure_screen_BRDTempMeter_section_0_label_style, lv_color_hex(0xffffff));
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_0_label_style, lv_color_hex(0x00A700));
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_0_minor_tick_style, lv_color_hex(0x00A700));
    lv_style_set_line_width(&temperature_measure_screen_BRDTempMeter_section_0_minor_tick_style, 2);
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_0_label_style, lv_color_hex(0x00A700));
    lv_style_set_line_width(&temperature_measure_screen_BRDTempMeter_section_0_label_style, 2);
    lv_style_set_arc_color(&temperature_measure_screen_BRDTempMeter_section_0_main_line_style, lv_color_hex(0x00A700));
    lv_style_set_arc_width(&temperature_measure_screen_BRDTempMeter_section_0_main_line_style, 0);
    lv_scale_section_t * temperature_measure_screen_BRDTempMeter_section_1 = lv_scale_add_section(ui->temperature_measure_screen_BRDTempMeter);
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_1_minor_tick_style;
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_1_label_style;
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_1_main_line_style;
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_1_label_style);
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_1_minor_tick_style);
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_1_main_line_style);

    lv_scale_section_set_range(temperature_measure_screen_BRDTempMeter_section_1, -10, 0);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_1, LV_PART_INDICATOR, &temperature_measure_screen_BRDTempMeter_section_1_label_style);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_1, LV_PART_MAIN, &temperature_measure_screen_BRDTempMeter_section_1_main_line_style);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_1, LV_PART_ITEMS, &temperature_measure_screen_BRDTempMeter_section_1_minor_tick_style);

    lv_style_set_text_color(&temperature_measure_screen_BRDTempMeter_section_1_label_style, lv_color_hex(0xffffff));
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_1_label_style, lv_color_hex(0x0000ff));
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_1_minor_tick_style, lv_color_hex(0x0000ff));
    lv_style_set_line_width(&temperature_measure_screen_BRDTempMeter_section_1_minor_tick_style, 2);
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_1_label_style, lv_color_hex(0x0000ff));
    lv_style_set_line_width(&temperature_measure_screen_BRDTempMeter_section_1_label_style, 2);
    lv_style_set_arc_color(&temperature_measure_screen_BRDTempMeter_section_1_main_line_style, lv_color_hex(0x0000ff));
    lv_style_set_arc_width(&temperature_measure_screen_BRDTempMeter_section_1_main_line_style, 0);
    lv_scale_section_t * temperature_measure_screen_BRDTempMeter_section_2 = lv_scale_add_section(ui->temperature_measure_screen_BRDTempMeter);
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_2_minor_tick_style;
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_2_label_style;
    static lv_style_t temperature_measure_screen_BRDTempMeter_section_2_main_line_style;
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_2_label_style);
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_2_minor_tick_style);
    lv_style_init(&temperature_measure_screen_BRDTempMeter_section_2_main_line_style);

    lv_scale_section_set_range(temperature_measure_screen_BRDTempMeter_section_2, 40, 60);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_2, LV_PART_INDICATOR, &temperature_measure_screen_BRDTempMeter_section_2_label_style);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_2, LV_PART_MAIN, &temperature_measure_screen_BRDTempMeter_section_2_main_line_style);
    lv_scale_section_set_style(temperature_measure_screen_BRDTempMeter_section_2, LV_PART_ITEMS, &temperature_measure_screen_BRDTempMeter_section_2_minor_tick_style);

    lv_style_set_text_color(&temperature_measure_screen_BRDTempMeter_section_2_label_style, lv_color_hex(0xffffff));
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_2_label_style, lv_color_hex(0xf00000));
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_2_minor_tick_style, lv_color_hex(0xf00000));
    lv_style_set_line_width(&temperature_measure_screen_BRDTempMeter_section_2_minor_tick_style, 2);
    lv_style_set_line_color(&temperature_measure_screen_BRDTempMeter_section_2_label_style, lv_color_hex(0xf00000));
    lv_style_set_line_width(&temperature_measure_screen_BRDTempMeter_section_2_label_style, 2);
    lv_style_set_arc_color(&temperature_measure_screen_BRDTempMeter_section_2_main_line_style, lv_color_hex(0xf00000));
    lv_style_set_arc_width(&temperature_measure_screen_BRDTempMeter_section_2_main_line_style, 0);

    ui->temperature_measure_screen_BRDTempMeter_ndline_0 = lv_line_create(ui->temperature_measure_screen_BRDTempMeter);
    lv_obj_set_style_line_width(ui->temperature_measure_screen_BRDTempMeter_ndline_0, 2, LV_PART_MAIN);
    lv_obj_set_style_line_color(ui->temperature_measure_screen_BRDTempMeter_ndline_0, lv_color_hex(0xFF7400), LV_PART_MAIN);
    lv_obj_set_style_line_rounded(ui->temperature_measure_screen_BRDTempMeter_ndline_0, true, LV_PART_MAIN);
    lv_scale_set_line_needle_value(ui->temperature_measure_screen_BRDTempMeter, ui->temperature_measure_screen_BRDTempMeter_ndline_0, 75, 25);


    //Write style for temperature_measure_screen_BRDTempMeter, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_BRDTempMeter, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->temperature_measure_screen_BRDTempMeter, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->temperature_measure_screen_BRDTempMeter, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_BRDTempMeter, 180, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_BRDTempMeter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->temperature_measure_screen_BRDTempMeter, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_BRDTempMeter, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_BRDTempMeter, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_BRDTempMeter, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for temperature_measure_screen_BRDTempMeter, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_length(ui->temperature_measure_screen_BRDTempMeter, 9, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->temperature_measure_screen_BRDTempMeter, 2, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->temperature_measure_screen_BRDTempMeter, lv_color_hex(0x757575), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->temperature_measure_screen_BRDTempMeter, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write style for temperature_measure_screen_BRDTempMeter, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_length(ui->temperature_measure_screen_BRDTempMeter, 18, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->temperature_measure_screen_BRDTempMeter, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->temperature_measure_screen_BRDTempMeter, lv_color_hex(0x757575), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->temperature_measure_screen_BRDTempMeter, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_label_4
    ui->temperature_measure_screen_label_4 = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_label_4, 135, 155);
    lv_obj_set_size(ui->temperature_measure_screen_label_4, 10, 10);
    lv_label_set_text(ui->temperature_measure_screen_label_4, "");
    lv_label_set_long_mode(ui->temperature_measure_screen_label_4, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_label_4, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->temperature_measure_screen_label_4, lv_color_hex(0xFF7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->temperature_measure_screen_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_label_5
    ui->temperature_measure_screen_label_5 = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_label_5, 335, 155);
    lv_obj_set_size(ui->temperature_measure_screen_label_5, 10, 10);
    lv_label_set_text(ui->temperature_measure_screen_label_5, "");
    lv_label_set_long_mode(ui->temperature_measure_screen_label_5, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_label_5, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->temperature_measure_screen_label_5, lv_color_hex(0xFF7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->temperature_measure_screen_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_label_6
    ui->temperature_measure_screen_label_6 = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_label_6, 116, 210);
    lv_obj_set_size(ui->temperature_measure_screen_label_6, 49, 11);
    lv_label_set_text(ui->temperature_measure_screen_label_6, "MCU");
    lv_label_set_long_mode(ui->temperature_measure_screen_label_6, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_label_6, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_label_7
    ui->temperature_measure_screen_label_7 = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_label_7, 316, 210);
    lv_obj_set_size(ui->temperature_measure_screen_label_7, 49, 11);
    lv_label_set_text(ui->temperature_measure_screen_label_7, "Board");
    lv_label_set_long_mode(ui->temperature_measure_screen_label_7, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_label_7, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_MCUTempScreenLabel
    ui->temperature_measure_screen_MCUTempScreenLabel = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_MCUTempScreenLabel, 110, 227);
    lv_obj_set_size(ui->temperature_measure_screen_MCUTempScreenLabel, 60, 11);
    lv_label_set_text(ui->temperature_measure_screen_MCUTempScreenLabel, "25.00°C");
    lv_label_set_long_mode(ui->temperature_measure_screen_MCUTempScreenLabel, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_MCUTempScreenLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_MCUTempScreenLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_MCUTempScreenLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_MCUTempScreenLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_MCUTempScreenLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_MCUTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes temperature_measure_screen_BRDTempScreenLabel
    ui->temperature_measure_screen_BRDTempScreenLabel = lv_label_create(ui->temperature_measure_screen);
    lv_obj_set_pos(ui->temperature_measure_screen_BRDTempScreenLabel, 310, 227);
    lv_obj_set_size(ui->temperature_measure_screen_BRDTempScreenLabel, 60, 11);
    lv_label_set_text(ui->temperature_measure_screen_BRDTempScreenLabel, "25.00°C");
    lv_label_set_long_mode(ui->temperature_measure_screen_BRDTempScreenLabel, LV_LABEL_LONG_WRAP);

    //Write style for temperature_measure_screen_BRDTempScreenLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->temperature_measure_screen_BRDTempScreenLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->temperature_measure_screen_BRDTempScreenLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->temperature_measure_screen_BRDTempScreenLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->temperature_measure_screen_BRDTempScreenLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->temperature_measure_screen_BRDTempScreenLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of temperature_measure_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->temperature_measure_screen);

    //Init events for screen.
    events_init_temperature_measure_screen(ui);
}
