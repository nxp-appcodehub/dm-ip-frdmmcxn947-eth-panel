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



void setup_scr_control_panel_screen(lv_ui *ui)
{
    //Write codes control_panel_screen
    ui->control_panel_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->control_panel_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->control_panel_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for control_panel_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_panel_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_panel_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_panel_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->control_panel_screen, &_Slide2_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->control_panel_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->control_panel_screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_DateLabel
    ui->control_panel_screen_DateLabel = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->control_panel_screen_DateLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_DateLabel, 333, 305);
    lv_obj_set_size(ui->control_panel_screen_DateLabel, 143, 12);

    //Write style for control_panel_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_DateLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_DateLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_DateLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_HourLabel
    ui->control_panel_screen_HourLabel = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_HourLabel, "00:00:00 pm");
    lv_label_set_long_mode(ui->control_panel_screen_HourLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_HourLabel, 4, 5);
    lv_obj_set_size(ui->control_panel_screen_HourLabel, 105, 10);

    //Write style for control_panel_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_HourLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_HourLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_HourLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_MCUTempLabel
    ui->control_panel_screen_MCUTempLabel = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_MCUTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->control_panel_screen_MCUTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_MCUTempLabel, 154, 5);
    lv_obj_set_size(ui->control_panel_screen_MCUTempLabel, 69, 9);

    //Write style for control_panel_screen_MCUTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_MCUTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_MCUTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_MCUTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_MCUTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_MCUTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_MCUTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_BRDTempLabel
    ui->control_panel_screen_BRDTempLabel = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_BRDTempLabel, "25.00°C");
    lv_label_set_long_mode(ui->control_panel_screen_BRDTempLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_BRDTempLabel, 264, 5);
    lv_obj_set_size(ui->control_panel_screen_BRDTempLabel, 69, 9);

    //Write style for control_panel_screen_BRDTempLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_BRDTempLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_BRDTempLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_BRDTempLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_BRDTempLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_BRDTempLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_BRDTempLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_label_3
    ui->control_panel_screen_label_3 = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_label_3, "MCU:");
    lv_label_set_long_mode(ui->control_panel_screen_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_label_3, 117, 5);
    lv_obj_set_size(ui->control_panel_screen_label_3, 46, 9);

    //Write style for control_panel_screen_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_label_3, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_label_2
    ui->control_panel_screen_label_2 = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_label_2, "BRD:");
    lv_label_set_long_mode(ui->control_panel_screen_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_label_2, 229, 5);
    lv_obj_set_size(ui->control_panel_screen_label_2, 46, 9);

    //Write style for control_panel_screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_label_2, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_label_1
    ui->control_panel_screen_label_1 = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_label_1, "Control Panel");
    lv_label_set_long_mode(ui->control_panel_screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_label_1, 140, 30);
    lv_obj_set_size(ui->control_panel_screen_label_1, 200, 20);

    //Write style for control_panel_screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_label_1, lv_color_hex(0xff7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_MenuBTN
    ui->control_panel_screen_MenuBTN = lv_btn_create(ui->control_panel_screen);
    ui->control_panel_screen_MenuBTN_label = lv_label_create(ui->control_panel_screen_MenuBTN);
    lv_label_set_text(ui->control_panel_screen_MenuBTN_label, "Menu");
    lv_label_set_long_mode(ui->control_panel_screen_MenuBTN_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->control_panel_screen_MenuBTN_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->control_panel_screen_MenuBTN, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->control_panel_screen_MenuBTN_label, LV_PCT(100));
    lv_obj_set_pos(ui->control_panel_screen_MenuBTN, 15, 280);
    lv_obj_set_size(ui->control_panel_screen_MenuBTN, 120, 30);

    //Write style for control_panel_screen_MenuBTN, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_panel_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_panel_screen_MenuBTN, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_panel_screen_MenuBTN, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->control_panel_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_MenuBTN, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_MenuBTN, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_MenuBTN, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_MenuBTN, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_MenuBTN, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_MenuBTN, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_RPMChart
    ui->control_panel_screen_RPMChart = lv_chart_create(ui->control_panel_screen);
    lv_chart_set_type(ui->control_panel_screen_RPMChart, LV_CHART_TYPE_LINE);
    lv_chart_set_div_line_count(ui->control_panel_screen_RPMChart, 2, 10);
    lv_chart_set_point_count(ui->control_panel_screen_RPMChart, 21);
    lv_chart_set_range(ui->control_panel_screen_RPMChart, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
    lv_chart_set_axis_tick(ui->control_panel_screen_RPMChart, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 5, true, 40);
    lv_chart_set_range(ui->control_panel_screen_RPMChart, LV_CHART_AXIS_SECONDARY_Y, 0, 100);
    lv_chart_set_axis_tick(ui->control_panel_screen_RPMChart, LV_CHART_AXIS_PRIMARY_X, 10, 5, 3, 10, true, 40);
    ui->control_panel_screen_RPMChart_0 = lv_chart_add_series(ui->control_panel_screen_RPMChart, lv_color_hex(0xffffff), LV_CHART_AXIS_PRIMARY_Y);
#if LV_USE_FREEMASTER == 0
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 1);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 1000);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
    lv_chart_set_next_value(ui->control_panel_screen_RPMChart, ui->control_panel_screen_RPMChart_0, 0);
#endif
    lv_obj_set_pos(ui->control_panel_screen_RPMChart, 50, 90);
    lv_obj_set_size(ui->control_panel_screen_RPMChart, 380, 125);
    lv_obj_set_scrollbar_mode(ui->control_panel_screen_RPMChart, LV_SCROLLBAR_MODE_OFF);

    //Write style for control_panel_screen_RPMChart, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_panel_screen_RPMChart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_panel_screen_RPMChart, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_panel_screen_RPMChart, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->control_panel_screen_RPMChart, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->control_panel_screen_RPMChart, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->control_panel_screen_RPMChart, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->control_panel_screen_RPMChart, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_RPMChart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->control_panel_screen_RPMChart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_RPMChart, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for control_panel_screen_RPMChart, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->control_panel_screen_RPMChart, lv_color_hex(0xffffff), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_RPMChart, &lv_font_montserratMedium_11, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_RPMChart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_width(ui->control_panel_screen_RPMChart, 2, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->control_panel_screen_RPMChart, lv_color_hex(0xe8e8e8), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->control_panel_screen_RPMChart, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_label_4
    ui->control_panel_screen_label_4 = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_label_4, "RPM:");
    lv_label_set_long_mode(ui->control_panel_screen_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_label_4, 163, 69);
    lv_obj_set_size(ui->control_panel_screen_label_4, 79, 17);

    //Write style for control_panel_screen_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_label_4, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_RPMSlider
    ui->control_panel_screen_RPMSlider = lv_slider_create(ui->control_panel_screen);
    lv_slider_set_range(ui->control_panel_screen_RPMSlider, 0, 100);
    lv_slider_set_mode(ui->control_panel_screen_RPMSlider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->control_panel_screen_RPMSlider, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->control_panel_screen_RPMSlider, 100, 235);
    lv_obj_set_size(ui->control_panel_screen_RPMSlider, 280, 8);

    //Write style for control_panel_screen_RPMSlider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_panel_screen_RPMSlider, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_panel_screen_RPMSlider, lv_color_hex(0xFF7400), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_panel_screen_RPMSlider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_RPMSlider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->control_panel_screen_RPMSlider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_RPMSlider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for control_panel_screen_RPMSlider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_panel_screen_RPMSlider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_panel_screen_RPMSlider, lv_color_hex(0xFF7400), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_panel_screen_RPMSlider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_RPMSlider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for control_panel_screen_RPMSlider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->control_panel_screen_RPMSlider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->control_panel_screen_RPMSlider, lv_color_hex(0xFF7400), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->control_panel_screen_RPMSlider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_RPMSlider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_RPMLabel
    ui->control_panel_screen_RPMLabel = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_RPMLabel, "0000");
    lv_label_set_long_mode(ui->control_panel_screen_RPMLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_RPMLabel, 244, 69);
    lv_obj_set_size(ui->control_panel_screen_RPMLabel, 85, 18);

    //Write style for control_panel_screen_RPMLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_RPMLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_RPMLabel, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_RPMLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_RPMLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_RPMLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_RPMLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes control_panel_screen_IPLabel
    ui->control_panel_screen_IPLabel = lv_label_create(ui->control_panel_screen);
    lv_label_set_text(ui->control_panel_screen_IPLabel, "192.168.001.100");
    lv_label_set_long_mode(ui->control_panel_screen_IPLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->control_panel_screen_IPLabel, 180, 305);
    lv_obj_set_size(ui->control_panel_screen_IPLabel, 120, 12);

    //Write style for control_panel_screen_IPLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->control_panel_screen_IPLabel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->control_panel_screen_IPLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->control_panel_screen_IPLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->control_panel_screen_IPLabel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->control_panel_screen_IPLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->control_panel_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of control_panel_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->control_panel_screen);

    //Init events for screen.
    events_init_control_panel_screen(ui);
}
