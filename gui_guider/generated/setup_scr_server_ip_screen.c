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



void setup_scr_server_ip_screen(lv_ui *ui)
{
    //Write codes server_ip_screen
    ui->server_ip_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->server_ip_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->server_ip_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for server_ip_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->server_ip_screen, &_Slide2_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->server_ip_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->server_ip_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_HourLabel
    ui->server_ip_screen_HourLabel = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->server_ip_screen_HourLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_HourLabel, 3, 5);
    lv_obj_set_size(ui->server_ip_screen_HourLabel, 105, 10);

    //Write style for server_ip_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_HourLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_MCUTempLabel
    ui->server_ip_screen_MCUTempLabel = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->server_ip_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->server_ip_screen_MCUTempLabel, 69, 9);

    //Write style for server_ip_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_MCUTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_BRDTempLabel
    ui->server_ip_screen_BRDTempLabel = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->server_ip_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_BRDTempLabel, 264, 5);
    lv_obj_set_size(ui->server_ip_screen_BRDTempLabel, 69, 9);

    //Write style for server_ip_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_BRDTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_label_4
    ui->server_ip_screen_label_4 = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_label_4, "MCU:");
    lv_label_set_long_mode(ui->server_ip_screen_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_label_4, 117, 5);
    lv_obj_set_size(ui->server_ip_screen_label_4, 46, 9);

    //Write style for server_ip_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_label_4, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_label_3
    ui->server_ip_screen_label_3 = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_label_3, "BRD:");
    lv_label_set_long_mode(ui->server_ip_screen_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_label_3, 229, 5);
    lv_obj_set_size(ui->server_ip_screen_label_3, 46, 9);

    //Write style for server_ip_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_label_3, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_DateLabel
    ui->server_ip_screen_DateLabel = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->server_ip_screen_DateLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->server_ip_screen_DateLabel, 143, 12);

    //Write style for server_ip_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_DateLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_label_1
    ui->server_ip_screen_label_1 = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_label_1, "Server IP");
    lv_label_set_long_mode(ui->server_ip_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_label_1, 137, 30);
    lv_obj_set_size(ui->server_ip_screen_label_1, 206, 23);

    //Write style for server_ip_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_label_1, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_SaveIPBTN
    ui->server_ip_screen_SaveIPBTN = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_SaveIPBTN_label = lv_label_create(ui->server_ip_screen_SaveIPBTN);
    lv_label_set_text(ui->server_ip_screen_SaveIPBTN_label, "Save");
    lv_label_set_long_mode(ui->server_ip_screen_SaveIPBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_SaveIPBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_SaveIPBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_SaveIPBTN_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_SaveIPBTN, 15, 280);
    lv_obj_set_size(ui->server_ip_screen_SaveIPBTN, 120, 30);

    //Write style for server_ip_screen_SaveIPBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_SaveIPBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_SaveIPBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_SaveIPBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_SaveIPBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_SaveIPBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_SaveIPBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_SaveIPBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_SaveIPBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_SaveIPBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_SaveIPBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N1Btn
    ui->server_ip_screen_N1Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N1Btn_label = lv_label_create(ui->server_ip_screen_N1Btn);
    lv_label_set_text(ui->server_ip_screen_N1Btn_label, "1");
    lv_label_set_long_mode(ui->server_ip_screen_N1Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N1Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N1Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N1Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N1Btn, 270, 68);
    lv_obj_set_size(ui->server_ip_screen_N1Btn, 35, 35);

    //Write style for server_ip_screen_N1Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N1Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N1Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N1Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N1Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N1Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N1Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N1Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N1Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N1Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N1Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N2Btn
    ui->server_ip_screen_N2Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N2Btn_label = lv_label_create(ui->server_ip_screen_N2Btn);
    lv_label_set_text(ui->server_ip_screen_N2Btn_label, "2");
    lv_label_set_long_mode(ui->server_ip_screen_N2Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N2Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N2Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N2Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N2Btn, 320, 68);
    lv_obj_set_size(ui->server_ip_screen_N2Btn, 35, 35);

    //Write style for server_ip_screen_N2Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N2Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N2Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N2Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N2Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N2Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N2Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N2Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N2Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N2Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N2Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N3Btn
    ui->server_ip_screen_N3Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N3Btn_label = lv_label_create(ui->server_ip_screen_N3Btn);
    lv_label_set_text(ui->server_ip_screen_N3Btn_label, "3");
    lv_label_set_long_mode(ui->server_ip_screen_N3Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N3Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N3Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N3Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N3Btn, 370, 68);
    lv_obj_set_size(ui->server_ip_screen_N3Btn, 35, 35);

    //Write style for server_ip_screen_N3Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N3Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N3Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N3Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N3Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N3Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N3Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N3Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N3Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N3Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N3Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N4Btn
    ui->server_ip_screen_N4Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N4Btn_label = lv_label_create(ui->server_ip_screen_N4Btn);
    lv_label_set_text(ui->server_ip_screen_N4Btn_label, "4");
    lv_label_set_long_mode(ui->server_ip_screen_N4Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N4Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N4Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N4Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N4Btn, 270, 118);
    lv_obj_set_size(ui->server_ip_screen_N4Btn, 35, 35);

    //Write style for server_ip_screen_N4Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N4Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N4Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N4Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N4Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N4Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N4Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N4Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N4Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N4Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N4Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N5Btn
    ui->server_ip_screen_N5Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N5Btn_label = lv_label_create(ui->server_ip_screen_N5Btn);
    lv_label_set_text(ui->server_ip_screen_N5Btn_label, "5");
    lv_label_set_long_mode(ui->server_ip_screen_N5Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N5Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N5Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N5Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N5Btn, 320, 118);
    lv_obj_set_size(ui->server_ip_screen_N5Btn, 35, 35);

    //Write style for server_ip_screen_N5Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N5Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N5Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N5Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N5Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N5Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N5Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N5Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N5Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N5Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N5Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N6Btn
    ui->server_ip_screen_N6Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N6Btn_label = lv_label_create(ui->server_ip_screen_N6Btn);
    lv_label_set_text(ui->server_ip_screen_N6Btn_label, "6");
    lv_label_set_long_mode(ui->server_ip_screen_N6Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N6Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N6Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N6Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N6Btn, 370, 118);
    lv_obj_set_size(ui->server_ip_screen_N6Btn, 35, 35);

    //Write style for server_ip_screen_N6Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N6Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N6Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N6Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N6Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N6Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N6Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N6Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N6Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N6Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N6Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N7Btn
    ui->server_ip_screen_N7Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N7Btn_label = lv_label_create(ui->server_ip_screen_N7Btn);
    lv_label_set_text(ui->server_ip_screen_N7Btn_label, "7");
    lv_label_set_long_mode(ui->server_ip_screen_N7Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N7Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N7Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N7Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N7Btn, 270, 168);
    lv_obj_set_size(ui->server_ip_screen_N7Btn, 35, 35);

    //Write style for server_ip_screen_N7Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N7Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N7Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N7Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N7Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N7Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N7Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N7Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N7Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N7Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N7Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N8Btn
    ui->server_ip_screen_N8Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N8Btn_label = lv_label_create(ui->server_ip_screen_N8Btn);
    lv_label_set_text(ui->server_ip_screen_N8Btn_label, "8");
    lv_label_set_long_mode(ui->server_ip_screen_N8Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N8Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N8Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N8Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N8Btn, 320, 168);
    lv_obj_set_size(ui->server_ip_screen_N8Btn, 35, 35);

    //Write style for server_ip_screen_N8Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N8Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N8Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N8Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N8Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N8Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N8Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N8Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N8Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N8Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N8Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N9Btn
    ui->server_ip_screen_N9Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N9Btn_label = lv_label_create(ui->server_ip_screen_N9Btn);
    lv_label_set_text(ui->server_ip_screen_N9Btn_label, "9");
    lv_label_set_long_mode(ui->server_ip_screen_N9Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N9Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N9Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N9Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N9Btn, 370, 168);
    lv_obj_set_size(ui->server_ip_screen_N9Btn, 35, 35);

    //Write style for server_ip_screen_N9Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N9Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N9Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N9Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N9Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N9Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N9Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N9Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N9Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N9Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N9Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_N0Btn
    ui->server_ip_screen_N0Btn = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_N0Btn_label = lv_label_create(ui->server_ip_screen_N0Btn);
    lv_label_set_text(ui->server_ip_screen_N0Btn_label, "0");
    lv_label_set_long_mode(ui->server_ip_screen_N0Btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_N0Btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_N0Btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_N0Btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_N0Btn, 320, 218);
    lv_obj_set_size(ui->server_ip_screen_N0Btn, 35, 35);

    //Write style for server_ip_screen_N0Btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_N0Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_N0Btn, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_N0Btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_N0Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_N0Btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_N0Btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_N0Btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_N0Btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_N0Btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_N0Btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_label_9
    ui->server_ip_screen_label_9 = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_label_9, "");
    lv_label_set_long_mode(ui->server_ip_screen_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_label_9, 50, 150);
    lv_obj_set_size(ui->server_ip_screen_label_9, 215, 30);

    //Write style for server_ip_screen_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_label_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_label_9, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_label_9, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_label_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_label_8
    ui->server_ip_screen_label_8 = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_label_8, ".");
    lv_label_set_long_mode(ui->server_ip_screen_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_label_8, 100, 158);
    lv_obj_set_size(ui->server_ip_screen_label_8, 5, 15);

    //Write style for server_ip_screen_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_label_8, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_label_7
    ui->server_ip_screen_label_7 = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_label_7, ".");
    lv_label_set_long_mode(ui->server_ip_screen_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_label_7, 155, 158);
    lv_obj_set_size(ui->server_ip_screen_label_7, 5, 15);

    //Write style for server_ip_screen_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_label_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_label_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_label_7, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_label_6
    ui->server_ip_screen_label_6 = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_label_6, ".");
    lv_label_set_long_mode(ui->server_ip_screen_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_label_6, 210, 158);
    lv_obj_set_size(ui->server_ip_screen_label_6, 5, 15);

    //Write style for server_ip_screen_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_label_6, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_label_5
    ui->server_ip_screen_label_5 = lv_label_create(ui->server_ip_screen);
    lv_label_set_text(ui->server_ip_screen_label_5, "Select and write mask");
    lv_label_set_long_mode(ui->server_ip_screen_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->server_ip_screen_label_5, 64, 85);
    lv_obj_set_size(ui->server_ip_screen_label_5, 140, 35);

    //Write style for server_ip_screen_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_label_5, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->server_ip_screen_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_IPCnf1
    ui->server_ip_screen_IPCnf1 = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_IPCnf1_label = lv_label_create(ui->server_ip_screen_IPCnf1);
    lv_label_set_text(ui->server_ip_screen_IPCnf1_label, "000");
    lv_label_set_long_mode(ui->server_ip_screen_IPCnf1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_IPCnf1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_IPCnf1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_IPCnf1_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_IPCnf1, 50, 150);
    lv_obj_set_size(ui->server_ip_screen_IPCnf1, 50, 30);

    //Write style for server_ip_screen_IPCnf1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_IPCnf1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_IPCnf1, lv_color_hex(0xdadada), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_IPCnf1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_IPCnf1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_IPCnf1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_IPCnf1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_IPCnf1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_IPCnf1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_IPCnf1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_IPCnf1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_IPCnf2
    ui->server_ip_screen_IPCnf2 = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_IPCnf2_label = lv_label_create(ui->server_ip_screen_IPCnf2);
    lv_label_set_text(ui->server_ip_screen_IPCnf2_label, "000");
    lv_label_set_long_mode(ui->server_ip_screen_IPCnf2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_IPCnf2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_IPCnf2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_IPCnf2_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_IPCnf2, 105, 150);
    lv_obj_set_size(ui->server_ip_screen_IPCnf2, 50, 30);

    //Write style for server_ip_screen_IPCnf2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_IPCnf2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_IPCnf2, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_IPCnf2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_IPCnf2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_IPCnf2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_IPCnf2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_IPCnf2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_IPCnf2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_IPCnf2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_IPCnf2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_IPCnf3
    ui->server_ip_screen_IPCnf3 = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_IPCnf3_label = lv_label_create(ui->server_ip_screen_IPCnf3);
    lv_label_set_text(ui->server_ip_screen_IPCnf3_label, "000");
    lv_label_set_long_mode(ui->server_ip_screen_IPCnf3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_IPCnf3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_IPCnf3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_IPCnf3_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_IPCnf3, 160, 150);
    lv_obj_set_size(ui->server_ip_screen_IPCnf3, 50, 30);

    //Write style for server_ip_screen_IPCnf3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_IPCnf3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_IPCnf3, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_IPCnf3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_IPCnf3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_IPCnf3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_IPCnf3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_IPCnf3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_IPCnf3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_IPCnf3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_IPCnf3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes server_ip_screen_IPCnf4
    ui->server_ip_screen_IPCnf4 = lv_btn_create(ui->server_ip_screen);
    ui->server_ip_screen_IPCnf4_label = lv_label_create(ui->server_ip_screen_IPCnf4);
    lv_label_set_text(ui->server_ip_screen_IPCnf4_label, "000");
    lv_label_set_long_mode(ui->server_ip_screen_IPCnf4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->server_ip_screen_IPCnf4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->server_ip_screen_IPCnf4, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->server_ip_screen_IPCnf4_label, LV_PCT(100));
    lv_obj_set_pos(ui->server_ip_screen_IPCnf4, 215, 150);
    lv_obj_set_size(ui->server_ip_screen_IPCnf4, 50, 30);

    //Write style for server_ip_screen_IPCnf4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->server_ip_screen_IPCnf4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->server_ip_screen_IPCnf4, lv_color_hex(0x848484), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->server_ip_screen_IPCnf4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->server_ip_screen_IPCnf4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->server_ip_screen_IPCnf4, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->server_ip_screen_IPCnf4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->server_ip_screen_IPCnf4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->server_ip_screen_IPCnf4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->server_ip_screen_IPCnf4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->server_ip_screen_IPCnf4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of server_ip_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->server_ip_screen);

    //Init events for screen.
    events_init_server_ip_screen(ui);
}
