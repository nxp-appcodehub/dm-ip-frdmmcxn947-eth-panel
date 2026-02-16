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



void setup_scr_cpu_performance_screen(lv_ui *ui)
{
    //Write codes cpu_performance_screen
    ui->cpu_performance_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->cpu_performance_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->cpu_performance_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for cpu_performance_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->cpu_performance_screen, &_Slide2_RGB565A8_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->cpu_performance_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->cpu_performance_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_1
    ui->cpu_performance_screen_label_1 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_1, 117, 5);
    lv_obj_set_size(ui->cpu_performance_screen_label_1, 46, 9);
    lv_label_set_text(ui->cpu_performance_screen_label_1, "MCU:");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_1, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_2
    ui->cpu_performance_screen_label_2 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_2, 229, 5);
    lv_obj_set_size(ui->cpu_performance_screen_label_2, 46, 9);
    lv_label_set_text(ui->cpu_performance_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_2, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_3
    ui->cpu_performance_screen_label_3 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_3, 135, 30);
    lv_obj_set_size(ui->cpu_performance_screen_label_3, 206, 23);
    lv_label_set_text(ui->cpu_performance_screen_label_3, "Performance");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_3, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_3, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_3, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_4
    ui->cpu_performance_screen_label_4 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_4, 210, 200);
    lv_obj_set_size(ui->cpu_performance_screen_label_4, 5, 5);
    lv_label_set_text(ui->cpu_performance_screen_label_4, "");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_4, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->cpu_performance_screen_label_4, lv_color_hex(0x0EAFE0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->cpu_performance_screen_label_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_5
    ui->cpu_performance_screen_label_5 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_5, 210, 180);
    lv_obj_set_size(ui->cpu_performance_screen_label_5, 5, 5);
    lv_label_set_text(ui->cpu_performance_screen_label_5, "");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_5, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_5, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->cpu_performance_screen_label_5, lv_color_hex(0xEBE7DD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->cpu_performance_screen_label_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_6
    ui->cpu_performance_screen_label_6 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_6, 210, 140);
    lv_obj_set_size(ui->cpu_performance_screen_label_6, 5, 5);
    lv_label_set_text(ui->cpu_performance_screen_label_6, "");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_6, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->cpu_performance_screen_label_6, lv_color_hex(0x00A700), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->cpu_performance_screen_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_7
    ui->cpu_performance_screen_label_7 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_7, 210, 160);
    lv_obj_set_size(ui->cpu_performance_screen_label_7, 5, 5);
    lv_label_set_text(ui->cpu_performance_screen_label_7, "");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_7, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_7, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->cpu_performance_screen_label_7, lv_color_hex(0x0068DF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->cpu_performance_screen_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_8
    ui->cpu_performance_screen_label_8 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_8, 210, 120);
    lv_obj_set_size(ui->cpu_performance_screen_label_8, 5, 5);
    lv_label_set_text(ui->cpu_performance_screen_label_8, "");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_8, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_8, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->cpu_performance_screen_label_8, lv_color_hex(0xFF7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->cpu_performance_screen_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_9
    ui->cpu_performance_screen_label_9 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_9, 220, 117);
    lv_obj_set_size(ui->cpu_performance_screen_label_9, 51, 11);
    lv_label_set_text(ui->cpu_performance_screen_label_9, "Idle");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_9, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_9, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_10
    ui->cpu_performance_screen_label_10 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_10, 220, 137);
    lv_obj_set_size(ui->cpu_performance_screen_label_10, 51, 11);
    lv_label_set_text(ui->cpu_performance_screen_label_10, "Ethernet");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_10, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_10, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_11
    ui->cpu_performance_screen_label_11 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_11, 220, 157);
    lv_obj_set_size(ui->cpu_performance_screen_label_11, 51, 11);
    lv_label_set_text(ui->cpu_performance_screen_label_11, "LVGL");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_11, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_11, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_11, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_12
    ui->cpu_performance_screen_label_12 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_12, 220, 177);
    lv_obj_set_size(ui->cpu_performance_screen_label_12, 51, 11);
    lv_label_set_text(ui->cpu_performance_screen_label_12, "Sensors");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_12, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_12, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_12, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_13
    ui->cpu_performance_screen_label_13 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_13, 220, 197);
    lv_obj_set_size(ui->cpu_performance_screen_label_13, 51, 11);
    lv_label_set_text(ui->cpu_performance_screen_label_13, "Motor Control");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_13, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_13, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_13, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_14
    ui->cpu_performance_screen_label_14 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_14, 90, 85);
    lv_obj_set_size(ui->cpu_performance_screen_label_14, 51, 11);
    lv_label_set_text(ui->cpu_performance_screen_label_14, "Core 1");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_14, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_14, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_14, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_label_15
    ui->cpu_performance_screen_label_15 = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_label_15, 320, 85);
    lv_obj_set_size(ui->cpu_performance_screen_label_15, 51, 11);
    lv_label_set_text(ui->cpu_performance_screen_label_15, "Core 2");
    lv_label_set_long_mode(ui->cpu_performance_screen_label_15, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_label_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_label_15, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_BRDTempLabel
    ui->cpu_performance_screen_BRDTempLabel = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_BRDTempLabel, 265, 5);
    lv_obj_set_size(ui->cpu_performance_screen_BRDTempLabel, 69, 9);
    lv_label_set_text(ui->cpu_performance_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->cpu_performance_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_MCUTempLabel
    ui->cpu_performance_screen_MCUTempLabel = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->cpu_performance_screen_MCUTempLabel, 69, 9);
    lv_label_set_text(ui->cpu_performance_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->cpu_performance_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_HourLabel
    ui->cpu_performance_screen_HourLabel = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_HourLabel, 3, 5);
    lv_obj_set_size(ui->cpu_performance_screen_HourLabel, 105, 10);
    lv_label_set_text(ui->cpu_performance_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->cpu_performance_screen_HourLabel, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_DateLabel
    ui->cpu_performance_screen_DateLabel = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->cpu_performance_screen_DateLabel, 143, 12);
    lv_label_set_text(ui->cpu_performance_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->cpu_performance_screen_DateLabel, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_IPLabel
    ui->cpu_performance_screen_IPLabel = lv_label_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_IPLabel, 180, 305);
    lv_obj_set_size(ui->cpu_performance_screen_IPLabel, 120, 12);
    lv_label_set_text(ui->cpu_performance_screen_IPLabel, "192.168.001.100");
    lv_label_set_long_mode(ui->cpu_performance_screen_IPLabel, LV_LABEL_LONG_WRAP);

    //Write style for cpu_performance_screen_IPLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_IPLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_IPLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_IPLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_IPLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_MenuBTN
    ui->cpu_performance_screen_MenuBTN = lv_button_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_MenuBTN, 15, 280);
    lv_obj_set_size(ui->cpu_performance_screen_MenuBTN, 120, 30);
    ui->cpu_performance_screen_MenuBTN_label = lv_label_create(ui->cpu_performance_screen_MenuBTN);
    lv_label_set_text(ui->cpu_performance_screen_MenuBTN_label, "Menu");
    lv_label_set_long_mode(ui->cpu_performance_screen_MenuBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->cpu_performance_screen_MenuBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->cpu_performance_screen_MenuBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->cpu_performance_screen_MenuBTN_label, LV_PCT(100));

    //Write style for cpu_performance_screen_MenuBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->cpu_performance_screen_MenuBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->cpu_performance_screen_MenuBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->cpu_performance_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_MenuBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->cpu_performance_screen_MenuBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->cpu_performance_screen_MenuBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->cpu_performance_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->cpu_performance_screen_MenuBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_LvglArc
    ui->cpu_performance_screen_LvglArc = lv_arc_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_LvglArc, 50, 85);
    lv_obj_set_size(ui->cpu_performance_screen_LvglArc, 150, 150);
    lv_arc_set_mode(ui->cpu_performance_screen_LvglArc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->cpu_performance_screen_LvglArc, 0, 360);
    lv_arc_set_bg_angles(ui->cpu_performance_screen_LvglArc, 0, 359);
    lv_arc_set_value(ui->cpu_performance_screen_LvglArc, 72);
    lv_arc_set_rotation(ui->cpu_performance_screen_LvglArc, 0);

    //Write style for cpu_performance_screen_LvglArc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_LvglArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->cpu_performance_screen_LvglArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_LvglArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_LvglArc, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_LvglArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_LvglArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_LvglArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_LvglArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_LvglArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_LvglArc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->cpu_performance_screen_LvglArc, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_LvglArc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->cpu_performance_screen_LvglArc, lv_color_hex(0x0068DF), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->cpu_performance_screen_LvglArc, false, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_LvglArc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_LvglArc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->cpu_performance_screen_LvglArc, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_EthernetArc
    ui->cpu_performance_screen_EthernetArc = lv_arc_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_EthernetArc, 50, 85);
    lv_obj_set_size(ui->cpu_performance_screen_EthernetArc, 150, 150);
    lv_arc_set_mode(ui->cpu_performance_screen_EthernetArc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->cpu_performance_screen_EthernetArc, 0, 360);
    lv_arc_set_bg_angles(ui->cpu_performance_screen_EthernetArc, 0, 359);
    lv_arc_set_value(ui->cpu_performance_screen_EthernetArc, 72);
    lv_arc_set_rotation(ui->cpu_performance_screen_EthernetArc, 72);

    //Write style for cpu_performance_screen_EthernetArc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_EthernetArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->cpu_performance_screen_EthernetArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_EthernetArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_EthernetArc, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_EthernetArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_EthernetArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_EthernetArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_EthernetArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_EthernetArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_EthernetArc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->cpu_performance_screen_EthernetArc, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_EthernetArc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->cpu_performance_screen_EthernetArc, lv_color_hex(0x00A700), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->cpu_performance_screen_EthernetArc, false, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_EthernetArc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_EthernetArc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->cpu_performance_screen_EthernetArc, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_SensorArc
    ui->cpu_performance_screen_SensorArc = lv_arc_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_SensorArc, 50, 85);
    lv_obj_set_size(ui->cpu_performance_screen_SensorArc, 150, 150);
    lv_arc_set_mode(ui->cpu_performance_screen_SensorArc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->cpu_performance_screen_SensorArc, 0, 360);
    lv_arc_set_bg_angles(ui->cpu_performance_screen_SensorArc, 0, 359);
    lv_arc_set_value(ui->cpu_performance_screen_SensorArc, 72);
    lv_arc_set_rotation(ui->cpu_performance_screen_SensorArc, 216);

    //Write style for cpu_performance_screen_SensorArc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_SensorArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->cpu_performance_screen_SensorArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_SensorArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_SensorArc, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_SensorArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_SensorArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_SensorArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_SensorArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_SensorArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_SensorArc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->cpu_performance_screen_SensorArc, 5, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_SensorArc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->cpu_performance_screen_SensorArc, lv_color_hex(0xbfbfbf), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->cpu_performance_screen_SensorArc, false, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_SensorArc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_SensorArc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->cpu_performance_screen_SensorArc, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_IdleArc1
    ui->cpu_performance_screen_IdleArc1 = lv_arc_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_IdleArc1, 50, 85);
    lv_obj_set_size(ui->cpu_performance_screen_IdleArc1, 150, 150);
    lv_arc_set_mode(ui->cpu_performance_screen_IdleArc1, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->cpu_performance_screen_IdleArc1, 0, 360);
    lv_arc_set_bg_angles(ui->cpu_performance_screen_IdleArc1, 0, 359);
    lv_arc_set_value(ui->cpu_performance_screen_IdleArc1, 72);
    lv_arc_set_rotation(ui->cpu_performance_screen_IdleArc1, 144);

    //Write style for cpu_performance_screen_IdleArc1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_IdleArc1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->cpu_performance_screen_IdleArc1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_IdleArc1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_IdleArc1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_IdleArc1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_IdleArc1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_IdleArc1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_IdleArc1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_IdleArc1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_IdleArc1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->cpu_performance_screen_IdleArc1, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_IdleArc1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->cpu_performance_screen_IdleArc1, lv_color_hex(0xFF7400), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->cpu_performance_screen_IdleArc1, false, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_IdleArc1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_IdleArc1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->cpu_performance_screen_IdleArc1, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_MotorControlArc
    ui->cpu_performance_screen_MotorControlArc = lv_arc_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_MotorControlArc, 50, 85);
    lv_obj_set_size(ui->cpu_performance_screen_MotorControlArc, 150, 150);
    lv_arc_set_mode(ui->cpu_performance_screen_MotorControlArc, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->cpu_performance_screen_MotorControlArc, 0, 360);
    lv_arc_set_bg_angles(ui->cpu_performance_screen_MotorControlArc, 0, 359);
    lv_arc_set_value(ui->cpu_performance_screen_MotorControlArc, 72);
    lv_arc_set_rotation(ui->cpu_performance_screen_MotorControlArc, 288);

    //Write style for cpu_performance_screen_MotorControlArc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_MotorControlArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->cpu_performance_screen_MotorControlArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_MotorControlArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_MotorControlArc, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_MotorControlArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_MotorControlArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_MotorControlArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_MotorControlArc, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_MotorControlArc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_MotorControlArc, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->cpu_performance_screen_MotorControlArc, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_MotorControlArc, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->cpu_performance_screen_MotorControlArc, lv_color_hex(0x0EAFE0), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->cpu_performance_screen_MotorControlArc, false, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_MotorControlArc, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_MotorControlArc, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->cpu_performance_screen_MotorControlArc, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_IdleArc2
    ui->cpu_performance_screen_IdleArc2 = lv_arc_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_IdleArc2, 280, 85);
    lv_obj_set_size(ui->cpu_performance_screen_IdleArc2, 150, 150);
    lv_arc_set_mode(ui->cpu_performance_screen_IdleArc2, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->cpu_performance_screen_IdleArc2, 0, 360);
    lv_arc_set_bg_angles(ui->cpu_performance_screen_IdleArc2, 0, 359);
    lv_arc_set_value(ui->cpu_performance_screen_IdleArc2, 360);
    lv_arc_set_rotation(ui->cpu_performance_screen_IdleArc2, 0);

    //Write style for cpu_performance_screen_IdleArc2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_IdleArc2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->cpu_performance_screen_IdleArc2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_IdleArc2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->cpu_performance_screen_IdleArc2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->cpu_performance_screen_IdleArc2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->cpu_performance_screen_IdleArc2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->cpu_performance_screen_IdleArc2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->cpu_performance_screen_IdleArc2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->cpu_performance_screen_IdleArc2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_IdleArc2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->cpu_performance_screen_IdleArc2, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->cpu_performance_screen_IdleArc2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->cpu_performance_screen_IdleArc2, lv_color_hex(0xFF7400), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->cpu_performance_screen_IdleArc2, false, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for cpu_performance_screen_IdleArc2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->cpu_performance_screen_IdleArc2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->cpu_performance_screen_IdleArc2, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes cpu_performance_screen_img_2
    ui->cpu_performance_screen_img_2 = lv_image_create(ui->cpu_performance_screen);
    lv_obj_set_pos(ui->cpu_performance_screen_img_2, 22, 60);
    lv_obj_set_size(ui->cpu_performance_screen_img_2, 441, 202);
    lv_obj_add_flag(ui->cpu_performance_screen_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_pivot(ui->cpu_performance_screen_img_2, 50,50);
    lv_image_set_rotation(ui->cpu_performance_screen_img_2, 0);

    //Write style for cpu_performance_screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->cpu_performance_screen_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->cpu_performance_screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of cpu_performance_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->cpu_performance_screen);

    //Init events for screen.
    events_init_cpu_performance_screen(ui);
}
