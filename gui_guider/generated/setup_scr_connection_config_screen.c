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



void setup_scr_connection_config_screen(lv_ui *ui)
{
    //Write codes connection_config_screen
    ui->connection_config_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->connection_config_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->connection_config_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for connection_config_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->connection_config_screen, &_Slide2_RGB565A8_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->connection_config_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->connection_config_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_label_1
    ui->connection_config_screen_label_1 = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_label_1, 117, 5);
    lv_obj_set_size(ui->connection_config_screen_label_1, 46, 9);
    lv_label_set_text(ui->connection_config_screen_label_1, "MCU:");
    lv_label_set_long_mode(ui->connection_config_screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_label_1, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_label_2
    ui->connection_config_screen_label_2 = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_label_2, 229, 5);
    lv_obj_set_size(ui->connection_config_screen_label_2, 46, 9);
    lv_label_set_text(ui->connection_config_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->connection_config_screen_label_2, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_label_3
    ui->connection_config_screen_label_3 = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_label_3, 135, 30);
    lv_obj_set_size(ui->connection_config_screen_label_3, 206, 23);
    lv_label_set_text(ui->connection_config_screen_label_3, "IP Configuration");
    lv_label_set_long_mode(ui->connection_config_screen_label_3, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_label_3, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_label_3, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_label_4
    ui->connection_config_screen_label_4 = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_label_4, 64, 153);
    lv_obj_set_size(ui->connection_config_screen_label_4, 140, 35);
    lv_label_set_text(ui->connection_config_screen_label_4, "Select and write mask");
    lv_label_set_long_mode(ui->connection_config_screen_label_4, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_label_4, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_label_8
    ui->connection_config_screen_label_8 = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_label_8, 50, 202);
    lv_obj_set_size(ui->connection_config_screen_label_8, 215, 30);
    lv_label_set_text(ui->connection_config_screen_label_8, "");
    lv_label_set_long_mode(ui->connection_config_screen_label_8, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_label_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_label_8, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_label_5
    ui->connection_config_screen_label_5 = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_label_5, 100, 210);
    lv_obj_set_size(ui->connection_config_screen_label_5, 5, 15);
    lv_label_set_text(ui->connection_config_screen_label_5, ".");
    lv_label_set_long_mode(ui->connection_config_screen_label_5, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_label_5, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_label_6
    ui->connection_config_screen_label_6 = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_label_6, 155, 210);
    lv_obj_set_size(ui->connection_config_screen_label_6, 5, 15);
    lv_label_set_text(ui->connection_config_screen_label_6, ".");
    lv_label_set_long_mode(ui->connection_config_screen_label_6, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_label_6, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_label_7
    ui->connection_config_screen_label_7 = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_label_7, 210, 210);
    lv_obj_set_size(ui->connection_config_screen_label_7, 5, 15);
    lv_label_set_text(ui->connection_config_screen_label_7, ".");
    lv_label_set_long_mode(ui->connection_config_screen_label_7, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_label_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_label_7, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_HourLabel
    ui->connection_config_screen_HourLabel = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_HourLabel, 3, 5);
    lv_obj_set_size(ui->connection_config_screen_HourLabel, 105, 10);
    lv_label_set_text(ui->connection_config_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->connection_config_screen_HourLabel, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_MCUTempLabel
    ui->connection_config_screen_MCUTempLabel = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->connection_config_screen_MCUTempLabel, 69, 9);
    lv_label_set_text(ui->connection_config_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->connection_config_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_BRDTempLabel
    ui->connection_config_screen_BRDTempLabel = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_BRDTempLabel, 265, 5);
    lv_obj_set_size(ui->connection_config_screen_BRDTempLabel, 69, 9);
    lv_label_set_text(ui->connection_config_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->connection_config_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_DateLabel
    ui->connection_config_screen_DateLabel = lv_label_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->connection_config_screen_DateLabel, 143, 12);
    lv_label_set_text(ui->connection_config_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->connection_config_screen_DateLabel, LV_LABEL_LONG_WRAP);

    //Write style for connection_config_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_static_ip_check_box
    ui->connection_config_screen_static_ip_check_box = lv_checkbox_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_static_ip_check_box, 80, 95);
    lv_checkbox_set_text(ui->connection_config_screen_static_ip_check_box, "Static IP");

    //Write style for connection_config_screen_static_ip_check_box, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->connection_config_screen_static_ip_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->connection_config_screen_static_ip_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->connection_config_screen_static_ip_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->connection_config_screen_static_ip_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_static_ip_check_box, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_static_ip_check_box, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_static_ip_check_box, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->connection_config_screen_static_ip_check_box, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_static_ip_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_static_ip_check_box, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_static_ip_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_static_ip_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for connection_config_screen_static_ip_check_box, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->connection_config_screen_static_ip_check_box, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_static_ip_check_box, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->connection_config_screen_static_ip_check_box, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->connection_config_screen_static_ip_check_box, lv_color_hex(0x5cd624), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->connection_config_screen_static_ip_check_box, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_static_ip_check_box, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_static_ip_check_box, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_static_ip_check_box, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_static_ip_check_box, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for connection_config_screen_static_ip_check_box, Part: LV_PART_INDICATOR, State: LV_STATE_PRESSED.
    lv_obj_set_style_pad_all(ui->connection_config_screen_static_ip_check_box, 3, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->connection_config_screen_static_ip_check_box, 2, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->connection_config_screen_static_ip_check_box, 255, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->connection_config_screen_static_ip_check_box, lv_color_hex(0x5cd624), LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->connection_config_screen_static_ip_check_box, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->connection_config_screen_static_ip_check_box, 6, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_static_ip_check_box, 255, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->connection_config_screen_static_ip_check_box, lv_color_hex(0x5cd624), LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_static_ip_check_box, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_PRESSED);

    //Write style for connection_config_screen_static_ip_check_box, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_pad_all(ui->connection_config_screen_static_ip_check_box, 3, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->connection_config_screen_static_ip_check_box, 2, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->connection_config_screen_static_ip_check_box, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->connection_config_screen_static_ip_check_box, lv_color_hex(0x5cd624), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->connection_config_screen_static_ip_check_box, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->connection_config_screen_static_ip_check_box, 6, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->connection_config_screen_static_ip_check_box, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->connection_config_screen_static_ip_check_box, lv_color_hex(0x5cd624), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_static_ip_check_box, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write codes connection_config_screen_SaveIPBTN
    ui->connection_config_screen_SaveIPBTN = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_SaveIPBTN, 15, 280);
    lv_obj_set_size(ui->connection_config_screen_SaveIPBTN, 120, 30);
    ui->connection_config_screen_SaveIPBTN_label = lv_label_create(ui->connection_config_screen_SaveIPBTN);
    lv_label_set_text(ui->connection_config_screen_SaveIPBTN_label, "Save");
    lv_label_set_long_mode(ui->connection_config_screen_SaveIPBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_SaveIPBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_SaveIPBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_SaveIPBTN_label, LV_PCT(100));

    //Write style for connection_config_screen_SaveIPBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_SaveIPBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_SaveIPBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_SaveIPBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_SaveIPBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_SaveIPBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_SaveIPBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_SaveIPBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_SaveIPBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_SaveIPBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_SaveIPBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_IPCnf1
    ui->connection_config_screen_IPCnf1 = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_IPCnf1, 50, 202);
    lv_obj_set_size(ui->connection_config_screen_IPCnf1, 50, 30);
    ui->connection_config_screen_IPCnf1_label = lv_label_create(ui->connection_config_screen_IPCnf1);
    lv_label_set_text(ui->connection_config_screen_IPCnf1_label, "000");
    lv_label_set_long_mode(ui->connection_config_screen_IPCnf1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_IPCnf1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_IPCnf1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_IPCnf1_label, LV_PCT(100));

    //Write style for connection_config_screen_IPCnf1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_IPCnf1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_IPCnf1, lv_color_hex(0xdadada), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_IPCnf1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_IPCnf1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_IPCnf1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_IPCnf1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_IPCnf1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_IPCnf1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_IPCnf1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_IPCnf1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_IPCnf2
    ui->connection_config_screen_IPCnf2 = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_IPCnf2, 105, 202);
    lv_obj_set_size(ui->connection_config_screen_IPCnf2, 50, 30);
    ui->connection_config_screen_IPCnf2_label = lv_label_create(ui->connection_config_screen_IPCnf2);
    lv_label_set_text(ui->connection_config_screen_IPCnf2_label, "000");
    lv_label_set_long_mode(ui->connection_config_screen_IPCnf2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_IPCnf2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_IPCnf2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_IPCnf2_label, LV_PCT(100));

    //Write style for connection_config_screen_IPCnf2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_IPCnf2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_IPCnf2, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_IPCnf2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_IPCnf2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_IPCnf2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_IPCnf2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_IPCnf2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_IPCnf2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_IPCnf2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_IPCnf2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_IPCnf3
    ui->connection_config_screen_IPCnf3 = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_IPCnf3, 160, 202);
    lv_obj_set_size(ui->connection_config_screen_IPCnf3, 50, 30);
    ui->connection_config_screen_IPCnf3_label = lv_label_create(ui->connection_config_screen_IPCnf3);
    lv_label_set_text(ui->connection_config_screen_IPCnf3_label, "000");
    lv_label_set_long_mode(ui->connection_config_screen_IPCnf3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_IPCnf3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_IPCnf3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_IPCnf3_label, LV_PCT(100));

    //Write style for connection_config_screen_IPCnf3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_IPCnf3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_IPCnf3, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_IPCnf3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_IPCnf3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_IPCnf3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_IPCnf3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_IPCnf3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_IPCnf3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_IPCnf3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_IPCnf3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_IPCnf4
    ui->connection_config_screen_IPCnf4 = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_IPCnf4, 215, 202);
    lv_obj_set_size(ui->connection_config_screen_IPCnf4, 50, 30);
    ui->connection_config_screen_IPCnf4_label = lv_label_create(ui->connection_config_screen_IPCnf4);
    lv_label_set_text(ui->connection_config_screen_IPCnf4_label, "000");
    lv_label_set_long_mode(ui->connection_config_screen_IPCnf4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_IPCnf4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_IPCnf4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_IPCnf4_label, LV_PCT(100));

    //Write style for connection_config_screen_IPCnf4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_IPCnf4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_IPCnf4, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_IPCnf4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_IPCnf4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_IPCnf4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_IPCnf4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_IPCnf4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_IPCnf4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_IPCnf4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_IPCnf4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N1Btn
    ui->connection_config_screen_N1Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N1Btn, 278, 68);
    lv_obj_set_size(ui->connection_config_screen_N1Btn, 35, 35);
    ui->connection_config_screen_N1Btn_label = lv_label_create(ui->connection_config_screen_N1Btn);
    lv_label_set_text(ui->connection_config_screen_N1Btn_label, "1");
    lv_label_set_long_mode(ui->connection_config_screen_N1Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N1Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N1Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N1Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N1Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N1Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N1Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N1Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N1Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N1Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N1Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N1Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N1Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N1Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N1Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N2Btn
    ui->connection_config_screen_N2Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N2Btn, 328, 68);
    lv_obj_set_size(ui->connection_config_screen_N2Btn, 35, 35);
    ui->connection_config_screen_N2Btn_label = lv_label_create(ui->connection_config_screen_N2Btn);
    lv_label_set_text(ui->connection_config_screen_N2Btn_label, "2");
    lv_label_set_long_mode(ui->connection_config_screen_N2Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N2Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N2Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N2Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N2Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N2Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N2Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N2Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N2Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N2Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N2Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N2Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N2Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N2Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N2Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N3Btn
    ui->connection_config_screen_N3Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N3Btn, 378, 68);
    lv_obj_set_size(ui->connection_config_screen_N3Btn, 35, 35);
    ui->connection_config_screen_N3Btn_label = lv_label_create(ui->connection_config_screen_N3Btn);
    lv_label_set_text(ui->connection_config_screen_N3Btn_label, "3");
    lv_label_set_long_mode(ui->connection_config_screen_N3Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N3Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N3Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N3Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N3Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N3Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N3Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N3Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N3Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N3Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N3Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N3Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N3Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N3Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N3Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N4Btn
    ui->connection_config_screen_N4Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N4Btn, 278, 118);
    lv_obj_set_size(ui->connection_config_screen_N4Btn, 35, 35);
    ui->connection_config_screen_N4Btn_label = lv_label_create(ui->connection_config_screen_N4Btn);
    lv_label_set_text(ui->connection_config_screen_N4Btn_label, "4");
    lv_label_set_long_mode(ui->connection_config_screen_N4Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N4Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N4Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N4Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N4Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N4Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N4Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N4Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N4Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N4Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N4Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N4Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N4Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N4Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N4Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N5Btn
    ui->connection_config_screen_N5Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N5Btn, 328, 118);
    lv_obj_set_size(ui->connection_config_screen_N5Btn, 35, 35);
    ui->connection_config_screen_N5Btn_label = lv_label_create(ui->connection_config_screen_N5Btn);
    lv_label_set_text(ui->connection_config_screen_N5Btn_label, "5");
    lv_label_set_long_mode(ui->connection_config_screen_N5Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N5Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N5Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N5Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N5Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N5Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N5Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N5Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N5Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N5Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N5Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N5Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N5Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N5Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N5Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N6Btn
    ui->connection_config_screen_N6Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N6Btn, 378, 118);
    lv_obj_set_size(ui->connection_config_screen_N6Btn, 35, 35);
    ui->connection_config_screen_N6Btn_label = lv_label_create(ui->connection_config_screen_N6Btn);
    lv_label_set_text(ui->connection_config_screen_N6Btn_label, "6");
    lv_label_set_long_mode(ui->connection_config_screen_N6Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N6Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N6Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N6Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N6Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N6Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N6Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N6Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N6Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N6Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N6Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N6Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N6Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N6Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N6Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N7Btn
    ui->connection_config_screen_N7Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N7Btn, 278, 168);
    lv_obj_set_size(ui->connection_config_screen_N7Btn, 35, 35);
    ui->connection_config_screen_N7Btn_label = lv_label_create(ui->connection_config_screen_N7Btn);
    lv_label_set_text(ui->connection_config_screen_N7Btn_label, "7");
    lv_label_set_long_mode(ui->connection_config_screen_N7Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N7Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N7Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N7Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N7Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N7Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N7Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N7Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N7Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N7Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N7Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N7Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N7Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N7Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N7Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N8Btn
    ui->connection_config_screen_N8Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N8Btn, 328, 168);
    lv_obj_set_size(ui->connection_config_screen_N8Btn, 35, 35);
    ui->connection_config_screen_N8Btn_label = lv_label_create(ui->connection_config_screen_N8Btn);
    lv_label_set_text(ui->connection_config_screen_N8Btn_label, "8");
    lv_label_set_long_mode(ui->connection_config_screen_N8Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N8Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N8Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N8Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N8Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N8Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N8Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N8Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N8Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N8Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N8Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N8Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N8Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N8Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N8Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N9Btn
    ui->connection_config_screen_N9Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N9Btn, 378, 168);
    lv_obj_set_size(ui->connection_config_screen_N9Btn, 35, 35);
    ui->connection_config_screen_N9Btn_label = lv_label_create(ui->connection_config_screen_N9Btn);
    lv_label_set_text(ui->connection_config_screen_N9Btn_label, "9");
    lv_label_set_long_mode(ui->connection_config_screen_N9Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N9Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N9Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N9Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N9Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N9Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N9Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N9Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N9Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N9Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N9Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N9Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N9Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N9Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N9Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes connection_config_screen_N0Btn
    ui->connection_config_screen_N0Btn = lv_button_create(ui->connection_config_screen);
    lv_obj_set_pos(ui->connection_config_screen_N0Btn, 328, 218);
    lv_obj_set_size(ui->connection_config_screen_N0Btn, 35, 35);
    ui->connection_config_screen_N0Btn_label = lv_label_create(ui->connection_config_screen_N0Btn);
    lv_label_set_text(ui->connection_config_screen_N0Btn_label, "0");
    lv_label_set_long_mode(ui->connection_config_screen_N0Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->connection_config_screen_N0Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->connection_config_screen_N0Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->connection_config_screen_N0Btn_label, LV_PCT(100));

    //Write style for connection_config_screen_N0Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->connection_config_screen_N0Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->connection_config_screen_N0Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->connection_config_screen_N0Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->connection_config_screen_N0Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->connection_config_screen_N0Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->connection_config_screen_N0Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->connection_config_screen_N0Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->connection_config_screen_N0Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->connection_config_screen_N0Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->connection_config_screen_N0Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of connection_config_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->connection_config_screen);

    //Init events for screen.
    events_init_connection_config_screen(ui);
}
