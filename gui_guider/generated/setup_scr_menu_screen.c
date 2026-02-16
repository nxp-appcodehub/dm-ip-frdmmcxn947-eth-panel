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



void setup_scr_menu_screen(lv_ui *ui)
{
    //Write codes menu_screen
    ui->menu_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->menu_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->menu_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for menu_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->menu_screen, &_Slide2_RGB565A8_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->menu_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->menu_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_label_1
    ui->menu_screen_label_1 = lv_label_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_label_1, 117, 5);
    lv_obj_set_size(ui->menu_screen_label_1, 46, 9);
    lv_label_set_text(ui->menu_screen_label_1, "MCU:");
    lv_label_set_long_mode(ui->menu_screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for menu_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_label_1, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_label_2
    ui->menu_screen_label_2 = lv_label_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_label_2, 229, 5);
    lv_obj_set_size(ui->menu_screen_label_2, 46, 9);
    lv_label_set_text(ui->menu_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->menu_screen_label_2, LV_LABEL_LONG_WRAP);

    //Write style for menu_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_label_3
    ui->menu_screen_label_3 = lv_label_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_label_3, 135, 30);
    lv_obj_set_size(ui->menu_screen_label_3, 206, 23);
    lv_label_set_text(ui->menu_screen_label_3, "Main Menu");
    lv_label_set_long_mode(ui->menu_screen_label_3, LV_LABEL_LONG_WRAP);

    //Write style for menu_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_label_3, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_label_3, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_HourLabel
    ui->menu_screen_HourLabel = lv_label_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_HourLabel, 3, 5);
    lv_obj_set_size(ui->menu_screen_HourLabel, 105, 10);
    lv_label_set_text(ui->menu_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->menu_screen_HourLabel, LV_LABEL_LONG_WRAP);

    //Write style for menu_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_MCUTempLabel
    ui->menu_screen_MCUTempLabel = lv_label_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->menu_screen_MCUTempLabel, 69, 9);
    lv_label_set_text(ui->menu_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->menu_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for menu_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_BRDTempLabel
    ui->menu_screen_BRDTempLabel = lv_label_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_BRDTempLabel, 265, 5);
    lv_obj_set_size(ui->menu_screen_BRDTempLabel, 69, 9);
    lv_label_set_text(ui->menu_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->menu_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for menu_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_DateLabel
    ui->menu_screen_DateLabel = lv_label_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->menu_screen_DateLabel, 143, 12);
    lv_label_set_text(ui->menu_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->menu_screen_DateLabel, LV_LABEL_LONG_WRAP);

    //Write style for menu_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_IPLabel
    ui->menu_screen_IPLabel = lv_label_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_IPLabel, 180, 305);
    lv_obj_set_size(ui->menu_screen_IPLabel, 120, 12);
    lv_label_set_text(ui->menu_screen_IPLabel, "192.168.001.100");
    lv_label_set_long_mode(ui->menu_screen_IPLabel, LV_LABEL_LONG_WRAP);

    //Write style for menu_screen_IPLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_IPLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_IPLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_IPLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_IPLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_PerformanceBTN
    ui->menu_screen_PerformanceBTN = lv_button_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_PerformanceBTN, 80, 81);
    lv_obj_set_size(ui->menu_screen_PerformanceBTN, 140, 40);
    ui->menu_screen_PerformanceBTN_label = lv_label_create(ui->menu_screen_PerformanceBTN);
    lv_label_set_text(ui->menu_screen_PerformanceBTN_label, "Performance");
    lv_label_set_long_mode(ui->menu_screen_PerformanceBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menu_screen_PerformanceBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menu_screen_PerformanceBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->menu_screen_PerformanceBTN_label, LV_PCT(100));

    //Write style for menu_screen_PerformanceBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_screen_PerformanceBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_screen_PerformanceBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_screen_PerformanceBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_screen_PerformanceBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_PerformanceBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_PerformanceBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_PerformanceBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_PerformanceBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_PerformanceBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_PerformanceBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_TemperatureBTN
    ui->menu_screen_TemperatureBTN = lv_button_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_TemperatureBTN, 80, 137);
    lv_obj_set_size(ui->menu_screen_TemperatureBTN, 140, 40);
    ui->menu_screen_TemperatureBTN_label = lv_label_create(ui->menu_screen_TemperatureBTN);
    lv_label_set_text(ui->menu_screen_TemperatureBTN_label, "Temperature");
    lv_label_set_long_mode(ui->menu_screen_TemperatureBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menu_screen_TemperatureBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menu_screen_TemperatureBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->menu_screen_TemperatureBTN_label, LV_PCT(100));

    //Write style for menu_screen_TemperatureBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_screen_TemperatureBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_screen_TemperatureBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_screen_TemperatureBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_screen_TemperatureBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_TemperatureBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_TemperatureBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_TemperatureBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_TemperatureBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_TemperatureBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_TemperatureBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_AccelBTN
    ui->menu_screen_AccelBTN = lv_button_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_AccelBTN, 80, 193);
    lv_obj_set_size(ui->menu_screen_AccelBTN, 140, 40);
    ui->menu_screen_AccelBTN_label = lv_label_create(ui->menu_screen_AccelBTN);
    lv_label_set_text(ui->menu_screen_AccelBTN_label, "Accelerometer");
    lv_label_set_long_mode(ui->menu_screen_AccelBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menu_screen_AccelBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menu_screen_AccelBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->menu_screen_AccelBTN_label, LV_PCT(100));

    //Write style for menu_screen_AccelBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_screen_AccelBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_screen_AccelBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_screen_AccelBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_screen_AccelBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_AccelBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_AccelBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_AccelBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_AccelBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_AccelBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_AccelBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_TouchSenseBTN
    ui->menu_screen_TouchSenseBTN = lv_button_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_TouchSenseBTN, 253, 81);
    lv_obj_set_size(ui->menu_screen_TouchSenseBTN, 140, 40);
    ui->menu_screen_TouchSenseBTN_label = lv_label_create(ui->menu_screen_TouchSenseBTN);
    lv_label_set_text(ui->menu_screen_TouchSenseBTN_label, "Touch Sense");
    lv_label_set_long_mode(ui->menu_screen_TouchSenseBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menu_screen_TouchSenseBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menu_screen_TouchSenseBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->menu_screen_TouchSenseBTN_label, LV_PCT(100));

    //Write style for menu_screen_TouchSenseBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_screen_TouchSenseBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_screen_TouchSenseBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_screen_TouchSenseBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_screen_TouchSenseBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_TouchSenseBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_TouchSenseBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_TouchSenseBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_TouchSenseBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_TouchSenseBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_TouchSenseBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_TimeBTN
    ui->menu_screen_TimeBTN = lv_button_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_TimeBTN, 253, 137);
    lv_obj_set_size(ui->menu_screen_TimeBTN, 140, 40);
    ui->menu_screen_TimeBTN_label = lv_label_create(ui->menu_screen_TimeBTN);
    lv_label_set_text(ui->menu_screen_TimeBTN_label, "Set Time");
    lv_label_set_long_mode(ui->menu_screen_TimeBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menu_screen_TimeBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menu_screen_TimeBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->menu_screen_TimeBTN_label, LV_PCT(100));

    //Write style for menu_screen_TimeBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_screen_TimeBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_screen_TimeBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_screen_TimeBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_screen_TimeBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_TimeBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_TimeBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_TimeBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_TimeBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_TimeBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_TimeBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes menu_screen_PanelBTN
    ui->menu_screen_PanelBTN = lv_button_create(ui->menu_screen);
    lv_obj_set_pos(ui->menu_screen_PanelBTN, 253, 193);
    lv_obj_set_size(ui->menu_screen_PanelBTN, 140, 40);
    ui->menu_screen_PanelBTN_label = lv_label_create(ui->menu_screen_PanelBTN);
    lv_label_set_text(ui->menu_screen_PanelBTN_label, "Control Panel");
    lv_label_set_long_mode(ui->menu_screen_PanelBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->menu_screen_PanelBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->menu_screen_PanelBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->menu_screen_PanelBTN_label, LV_PCT(100));

    //Write style for menu_screen_PanelBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->menu_screen_PanelBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->menu_screen_PanelBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->menu_screen_PanelBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->menu_screen_PanelBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->menu_screen_PanelBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->menu_screen_PanelBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->menu_screen_PanelBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->menu_screen_PanelBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->menu_screen_PanelBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->menu_screen_PanelBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of menu_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->menu_screen);

    //Init events for screen.
    events_init_menu_screen(ui);
}
