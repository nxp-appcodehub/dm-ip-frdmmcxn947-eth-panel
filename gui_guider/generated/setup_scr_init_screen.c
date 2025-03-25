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



void setup_scr_init_screen(lv_ui *ui)
{
    //Write codes init_screen
    ui->init_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->init_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->init_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for init_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->init_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->init_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->init_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->init_screen, &_Slide2_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->init_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->init_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes init_screen_master_btn
    ui->init_screen_master_btn = lv_btn_create(ui->init_screen);
    ui->init_screen_master_btn_label = lv_label_create(ui->init_screen_master_btn);
    lv_label_set_text(ui->init_screen_master_btn_label, "Master");
    lv_label_set_long_mode(ui->init_screen_master_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->init_screen_master_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->init_screen_master_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->init_screen_master_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->init_screen_master_btn, 159, 91);
    lv_obj_set_size(ui->init_screen_master_btn, 163, 50);

    //Write style for init_screen_master_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->init_screen_master_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->init_screen_master_btn, lv_color_hex(0x0068DF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->init_screen_master_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->init_screen_master_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_master_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_master_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_master_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_master_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_master_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_master_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for init_screen_master_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->init_screen_master_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->init_screen_master_btn, lv_color_hex(0xFF7400), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->init_screen_master_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->init_screen_master_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->init_screen_master_btn, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->init_screen_master_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->init_screen_master_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->init_screen_master_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->init_screen_master_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes init_screen_interface_btn
    ui->init_screen_interface_btn = lv_btn_create(ui->init_screen);
    ui->init_screen_interface_btn_label = lv_label_create(ui->init_screen_interface_btn);
    lv_label_set_text(ui->init_screen_interface_btn_label, "Interface");
    lv_label_set_long_mode(ui->init_screen_interface_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->init_screen_interface_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->init_screen_interface_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->init_screen_interface_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->init_screen_interface_btn, 159, 175);
    lv_obj_set_size(ui->init_screen_interface_btn, 163, 50);

    //Write style for init_screen_interface_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->init_screen_interface_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->init_screen_interface_btn, lv_color_hex(0x0068DF), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->init_screen_interface_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->init_screen_interface_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_interface_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_interface_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_interface_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_interface_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_interface_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_interface_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for init_screen_interface_btn, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->init_screen_interface_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->init_screen_interface_btn, lv_color_hex(0xFF7400), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->init_screen_interface_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->init_screen_interface_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->init_screen_interface_btn, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->init_screen_interface_btn, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->init_screen_interface_btn, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->init_screen_interface_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->init_screen_interface_btn, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes init_screen_HourLabel
    ui->init_screen_HourLabel = lv_label_create(ui->init_screen);
    lv_label_set_text(ui->init_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->init_screen_HourLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->init_screen_HourLabel, 3, 5);
    lv_obj_set_size(ui->init_screen_HourLabel, 105, 10);

    //Write style for init_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->init_screen_HourLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes init_screen_MCUTempLabel
    ui->init_screen_MCUTempLabel = lv_label_create(ui->init_screen);
    lv_label_set_text(ui->init_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->init_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->init_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->init_screen_MCUTempLabel, 69, 9);

    //Write style for init_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->init_screen_MCUTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes init_screen_BRDTempLabel
    ui->init_screen_BRDTempLabel = lv_label_create(ui->init_screen);
    lv_label_set_text(ui->init_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->init_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->init_screen_BRDTempLabel, 264, 5);
    lv_obj_set_size(ui->init_screen_BRDTempLabel, 69, 9);

    //Write style for init_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->init_screen_BRDTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes init_screen_label_3
    ui->init_screen_label_3 = lv_label_create(ui->init_screen);
    lv_label_set_text(ui->init_screen_label_3, "MCU:");
    lv_label_set_long_mode(ui->init_screen_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->init_screen_label_3, 117, 5);
    lv_obj_set_size(ui->init_screen_label_3, 46, 9);

    //Write style for init_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_label_3, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->init_screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes init_screen_label_2
    ui->init_screen_label_2 = lv_label_create(ui->init_screen);
    lv_label_set_text(ui->init_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->init_screen_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->init_screen_label_2, 229, 5);
    lv_obj_set_size(ui->init_screen_label_2, 46, 9);

    //Write style for init_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->init_screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes init_screen_DateLabel
    ui->init_screen_DateLabel = lv_label_create(ui->init_screen);
    lv_label_set_text(ui->init_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->init_screen_DateLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->init_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->init_screen_DateLabel, 143, 12);

    //Write style for init_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->init_screen_DateLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes init_screen_label_4
    ui->init_screen_label_4 = lv_label_create(ui->init_screen);
    lv_label_set_text(ui->init_screen_label_4, "Mode Select");
    lv_label_set_long_mode(ui->init_screen_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->init_screen_label_4, 140, 30);
    lv_obj_set_size(ui->init_screen_label_4, 200, 20);

    //Write style for init_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_label_4, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_label_4, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->init_screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->init_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes init_screen_ip_manual_check_box
    ui->init_screen_ip_manual_check_box = lv_checkbox_create(ui->init_screen);
    lv_checkbox_set_text(ui->init_screen_ip_manual_check_box, "Manual");
    lv_obj_set_pos(ui->init_screen_ip_manual_check_box, 25, 285);

    //Write style for init_screen_ip_manual_check_box, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_top(ui->init_screen_ip_manual_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->init_screen_ip_manual_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->init_screen_ip_manual_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->init_screen_ip_manual_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->init_screen_ip_manual_check_box, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->init_screen_ip_manual_check_box, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->init_screen_ip_manual_check_box, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->init_screen_ip_manual_check_box, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->init_screen_ip_manual_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_ip_manual_check_box, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_ip_manual_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->init_screen_ip_manual_check_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for init_screen_ip_manual_check_box, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_pad_all(ui->init_screen_ip_manual_check_box, 3, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->init_screen_ip_manual_check_box, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->init_screen_ip_manual_check_box, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->init_screen_ip_manual_check_box, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->init_screen_ip_manual_check_box, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->init_screen_ip_manual_check_box, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->init_screen_ip_manual_check_box, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->init_screen_ip_manual_check_box, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->init_screen_ip_manual_check_box, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for init_screen_ip_manual_check_box, Part: LV_PART_INDICATOR, State: LV_STATE_PRESSED.
    lv_obj_set_style_pad_all(ui->init_screen_ip_manual_check_box, 3, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->init_screen_ip_manual_check_box, 2, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui->init_screen_ip_manual_check_box, 255, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui->init_screen_ip_manual_check_box, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui->init_screen_ip_manual_check_box, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->init_screen_ip_manual_check_box, 6, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui->init_screen_ip_manual_check_box, 255, LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->init_screen_ip_manual_check_box, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->init_screen_ip_manual_check_box, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_PRESSED);

    //Write style for init_screen_ip_manual_check_box, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_pad_all(ui->init_screen_ip_manual_check_box, 3, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->init_screen_ip_manual_check_box, 2, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui->init_screen_ip_manual_check_box, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui->init_screen_ip_manual_check_box, lv_color_hex(0x0068DF), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_side(ui->init_screen_ip_manual_check_box, LV_BORDER_SIDE_FULL, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->init_screen_ip_manual_check_box, 6, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui->init_screen_ip_manual_check_box, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->init_screen_ip_manual_check_box, lv_color_hex(0x0068DF), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->init_screen_ip_manual_check_box, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //The custom code of init_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->init_screen);

    //Init events for screen.
    events_init_init_screen(ui);
}
