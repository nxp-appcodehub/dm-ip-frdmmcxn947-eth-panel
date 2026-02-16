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



void setup_scr_stand_by_screen(lv_ui *ui)
{
    //Write codes stand_by_screen
    ui->stand_by_screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->stand_by_screen, 480, 320);
    lv_obj_set_scrollbar_mode(ui->stand_by_screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for stand_by_screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->stand_by_screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->stand_by_screen, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->stand_by_screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stand_by_screen_IPLabel
    ui->stand_by_screen_IPLabel = lv_label_create(ui->stand_by_screen);
    lv_obj_set_pos(ui->stand_by_screen_IPLabel, 180, 305);
    lv_obj_set_size(ui->stand_by_screen_IPLabel, 120, 12);
    lv_label_set_text(ui->stand_by_screen_IPLabel, "192.168.001.100");
    lv_label_set_long_mode(ui->stand_by_screen_IPLabel, LV_LABEL_LONG_WRAP);

    //Write style for stand_by_screen_IPLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->stand_by_screen_IPLabel, lv_color_hex(0x787878), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->stand_by_screen_IPLabel, &lv_font_montserratMedium_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->stand_by_screen_IPLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->stand_by_screen_IPLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->stand_by_screen_IPLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stand_by_screen_DateLabel
    ui->stand_by_screen_DateLabel = lv_label_create(ui->stand_by_screen);
    lv_obj_set_pos(ui->stand_by_screen_DateLabel, 115, 200);
    lv_obj_set_size(ui->stand_by_screen_DateLabel, 250, 20);
    lv_label_set_text(ui->stand_by_screen_DateLabel, "Jul, 01, 2024");
    lv_label_set_long_mode(ui->stand_by_screen_DateLabel, LV_LABEL_LONG_WRAP);

    //Write style for stand_by_screen_DateLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->stand_by_screen_DateLabel, lv_color_hex(0x787878), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->stand_by_screen_DateLabel, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->stand_by_screen_DateLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->stand_by_screen_DateLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->stand_by_screen_DateLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes stand_by_screen_HourLabel
    ui->stand_by_screen_HourLabel = lv_label_create(ui->stand_by_screen);
    lv_obj_set_pos(ui->stand_by_screen_HourLabel, 30, 110);
    lv_obj_set_size(ui->stand_by_screen_HourLabel, 420, 60);
    lv_label_set_text(ui->stand_by_screen_HourLabel, "12:00:00 am");
    lv_label_set_long_mode(ui->stand_by_screen_HourLabel, LV_LABEL_LONG_WRAP);

    //Write style for stand_by_screen_HourLabel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->stand_by_screen_HourLabel, lv_color_hex(0x787878), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->stand_by_screen_HourLabel, &lv_font_montserratMedium_60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->stand_by_screen_HourLabel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->stand_by_screen_HourLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->stand_by_screen_HourLabel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of stand_by_screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->stand_by_screen);

    //Init events for screen.
    events_init_stand_by_screen(ui);
}
