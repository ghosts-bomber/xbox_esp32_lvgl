// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Screen1_Slider1;
lv_obj_t * ui_Screen1_Slider2;
lv_obj_t * ui_Screen1_Slider3;
lv_obj_t * ui_Screen1_Slider4;
lv_obj_t * ui_Screen1_Button1;
lv_obj_t * ui_Screen1_Button2;
lv_obj_t * ui_Screen1_Button3;
lv_obj_t * ui_Screen1_Button4;
lv_obj_t * ui_Screen1_Button5;
lv_obj_t * ui_Screen1_Button6;
lv_obj_t * ui_Screen1_Button7;
lv_obj_t * ui_Screen1_Button8;
lv_obj_t * ui_Screen1_Button9;
lv_obj_t * ui_Screen1_Button10;
lv_obj_t * ui_Screen1_Button11;
lv_obj_t * ui_Screen1_Button12;
lv_obj_t * ui_Screen1_Slider5;
lv_obj_t * ui_Screen1_Slider6;
lv_obj_t * ui_Screen1_Button13;
lv_obj_t * ui_Screen1_Button14;
lv_obj_t * ui_Screen1_Button15;
lv_obj_t * ui_Screen1_Button16;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Slider1 = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_Screen1_Slider1, 0, 65536);
    lv_slider_set_value(ui_Screen1_Slider1, 255, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Screen1_Slider1) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Screen1_Slider1, 0,
                                                                                                    LV_ANIM_OFF);
    lv_obj_set_width(ui_Screen1_Slider1, 42);
    lv_obj_set_height(ui_Screen1_Slider1, 2);
    lv_obj_set_x(ui_Screen1_Slider1, -44);
    lv_obj_set_y(ui_Screen1_Slider1, -14);
    lv_obj_set_align(ui_Screen1_Slider1, LV_ALIGN_CENTER);

    lv_obj_set_style_pad_left(ui_Screen1_Slider1, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Screen1_Slider1, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Screen1_Slider1, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Screen1_Slider1, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Slider2 = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_Screen1_Slider2, 0, 65536);
    lv_slider_set_value(ui_Screen1_Slider2, 255, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Screen1_Slider2) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Screen1_Slider2, 0,
                                                                                                    LV_ANIM_OFF);
    lv_obj_set_width(ui_Screen1_Slider2, 42);
    lv_obj_set_height(ui_Screen1_Slider2, 2);
    lv_obj_set_x(ui_Screen1_Slider2, 49);
    lv_obj_set_y(ui_Screen1_Slider2, 32);
    lv_obj_set_align(ui_Screen1_Slider2, LV_ALIGN_CENTER);

    lv_obj_set_style_pad_left(ui_Screen1_Slider2, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Screen1_Slider2, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Screen1_Slider2, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Screen1_Slider2, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Slider3 = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_Screen1_Slider3, 0, 1023);
    lv_slider_set_value(ui_Screen1_Slider3, 255, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Screen1_Slider3) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Screen1_Slider3, 0,
                                                                                                    LV_ANIM_OFF);
    lv_obj_set_width(ui_Screen1_Slider3, 42);
    lv_obj_set_height(ui_Screen1_Slider3, 2);
    lv_obj_set_x(ui_Screen1_Slider3, -47);
    lv_obj_set_y(ui_Screen1_Slider3, -33);
    lv_obj_set_align(ui_Screen1_Slider3, LV_ALIGN_CENTER);

    lv_obj_set_style_pad_left(ui_Screen1_Slider3, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Screen1_Slider3, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Screen1_Slider3, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Screen1_Slider3, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Slider4 = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_Screen1_Slider4, 0, 1023);
    lv_slider_set_value(ui_Screen1_Slider4, 255, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Screen1_Slider4) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Screen1_Slider4, 0,
                                                                                                    LV_ANIM_OFF);
    lv_obj_set_width(ui_Screen1_Slider4, 42);
    lv_obj_set_height(ui_Screen1_Slider4, 2);
    lv_obj_set_x(ui_Screen1_Slider4, 51);
    lv_obj_set_y(ui_Screen1_Slider4, -33);
    lv_obj_set_align(ui_Screen1_Slider4, LV_ALIGN_CENTER);

    lv_obj_set_style_pad_left(ui_Screen1_Slider4, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Screen1_Slider4, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Screen1_Slider4, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Screen1_Slider4, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button1, 10);
    lv_obj_set_height(ui_Screen1_Button1, 10);
    lv_obj_set_x(ui_Screen1_Button1, 107);
    lv_obj_set_y(ui_Screen1_Button1, 39);
    lv_obj_add_flag(ui_Screen1_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button1, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button1, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button1, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button2, 10);
    lv_obj_set_height(ui_Screen1_Button2, 10);
    lv_obj_set_x(ui_Screen1_Button2, 122);
    lv_obj_set_y(ui_Screen1_Button2, 26);
    lv_obj_add_flag(ui_Screen1_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button2, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button2, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button2, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button2, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button2, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button3 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button3, 10);
    lv_obj_set_height(ui_Screen1_Button3, 10);
    lv_obj_set_x(ui_Screen1_Button3, 123);
    lv_obj_set_y(ui_Screen1_Button3, 53);
    lv_obj_add_flag(ui_Screen1_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button3, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button3, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button3, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button3, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button3, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button4 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button4, 10);
    lv_obj_set_height(ui_Screen1_Button4, 10);
    lv_obj_set_x(ui_Screen1_Button4, 138);
    lv_obj_set_y(ui_Screen1_Button4, 40);
    lv_obj_add_flag(ui_Screen1_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button4, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button4, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button4, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button4, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button4, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button5 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button5, 10);
    lv_obj_set_height(ui_Screen1_Button5, 10);
    lv_obj_set_x(ui_Screen1_Button5, 30);
    lv_obj_set_y(ui_Screen1_Button5, 32);
    lv_obj_add_flag(ui_Screen1_Button5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button5, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button5, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button5, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button5, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button5, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button5, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button6 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button6, 10);
    lv_obj_set_height(ui_Screen1_Button6, 10);
    lv_obj_set_x(ui_Screen1_Button6, 17);
    lv_obj_set_y(ui_Screen1_Button6, 46);
    lv_obj_add_flag(ui_Screen1_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button6, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button6, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button6, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button6, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button6, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button6, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button7 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button7, 10);
    lv_obj_set_height(ui_Screen1_Button7, 10);
    lv_obj_set_x(ui_Screen1_Button7, 30);
    lv_obj_set_y(ui_Screen1_Button7, 60);
    lv_obj_add_flag(ui_Screen1_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button7, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button7, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button7, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button7, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button7, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button7, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button8 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button8, 10);
    lv_obj_set_height(ui_Screen1_Button8, 10);
    lv_obj_set_x(ui_Screen1_Button8, 45);
    lv_obj_set_y(ui_Screen1_Button8, 45);
    lv_obj_add_flag(ui_Screen1_Button8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button8, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button8, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button8, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button8, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button8, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button8, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button8, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button8, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button8, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button9 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button9, 10);
    lv_obj_set_height(ui_Screen1_Button9, 10);
    lv_obj_set_x(ui_Screen1_Button9, 28);
    lv_obj_set_y(ui_Screen1_Button9, 10);
    lv_obj_add_flag(ui_Screen1_Button9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button9, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button9, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button9, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button9, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button9, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button9, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button10 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button10, 10);
    lv_obj_set_height(ui_Screen1_Button10, 10);
    lv_obj_set_x(ui_Screen1_Button10, 129);
    lv_obj_set_y(ui_Screen1_Button10, 11);
    lv_obj_add_flag(ui_Screen1_Button10, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button10, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button10, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button10, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button10, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button10, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button10, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button10, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button10, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button10, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button10, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button11 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button11, 10);
    lv_obj_set_height(ui_Screen1_Button11, 10);
    lv_obj_set_x(ui_Screen1_Button11, 68);
    lv_obj_set_y(ui_Screen1_Button11, 20);
    lv_obj_add_flag(ui_Screen1_Button11, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button11, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button11, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button11, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button11, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button11, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button11, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button11, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button11, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button11, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button12 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button12, 10);
    lv_obj_set_height(ui_Screen1_Button12, 10);
    lv_obj_set_x(ui_Screen1_Button12, 91);
    lv_obj_set_y(ui_Screen1_Button12, 20);
    lv_obj_add_flag(ui_Screen1_Button12, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button12, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button12, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button12, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button12, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button12, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button12, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button12, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button12, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button12, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button12, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button12, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Slider5 = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_Screen1_Slider5, 0, 65536);
    lv_slider_set_value(ui_Screen1_Slider5, 255, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Screen1_Slider5) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Screen1_Slider5, 0,
                                                                                                    LV_ANIM_OFF);
    lv_obj_set_width(ui_Screen1_Slider5, 2);
    lv_obj_set_height(ui_Screen1_Slider5, 21);
    lv_obj_set_x(ui_Screen1_Slider5, -73);
    lv_obj_set_y(ui_Screen1_Slider5, 0);
    lv_obj_set_align(ui_Screen1_Slider5, LV_ALIGN_CENTER);

    lv_obj_set_style_pad_left(ui_Screen1_Slider5, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Screen1_Slider5, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Screen1_Slider5, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Screen1_Slider5, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Slider6 = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_Screen1_Slider6, 0, 65536);
    lv_slider_set_value(ui_Screen1_Slider6, 255, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Screen1_Slider6) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Screen1_Slider6, 0,
                                                                                                    LV_ANIM_OFF);
    lv_obj_set_width(ui_Screen1_Slider6, 2);
    lv_obj_set_height(ui_Screen1_Slider6, 20);
    lv_obj_set_x(ui_Screen1_Slider6, 22);
    lv_obj_set_y(ui_Screen1_Slider6, 21);
    lv_obj_set_align(ui_Screen1_Slider6, LV_ALIGN_CENTER);

    lv_obj_set_style_pad_left(ui_Screen1_Slider6, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Screen1_Slider6, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Screen1_Slider6, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Screen1_Slider6, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Screen1_Button13 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button13, 10);
    lv_obj_set_height(ui_Screen1_Button13, 10);
    lv_obj_set_x(ui_Screen1_Button13, 1);
    lv_obj_set_y(ui_Screen1_Button13, 14);
    lv_obj_add_flag(ui_Screen1_Button13, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button13, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button13, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button13, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button13, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button13, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button13, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button13, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button13, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button13, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button13, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button13, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button14 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button14, 10);
    lv_obj_set_height(ui_Screen1_Button14, 10);
    lv_obj_set_x(ui_Screen1_Button14, 85);
    lv_obj_set_y(ui_Screen1_Button14, 60);
    lv_obj_add_flag(ui_Screen1_Button14, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button14, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button14, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button14, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button14, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button14, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button14, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button14, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button14, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button14, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button14, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button14, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button15 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button15, 10);
    lv_obj_set_height(ui_Screen1_Button15, 10);
    lv_obj_set_x(ui_Screen1_Button15, 77);
    lv_obj_set_y(ui_Screen1_Button15, 35);
    lv_obj_add_flag(ui_Screen1_Button15, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button15, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button15, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button15, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button15, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button15, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button15, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button15, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button15, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button15, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button15, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_Screen1_Button16 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Screen1_Button16, 10);
    lv_obj_set_height(ui_Screen1_Button16, 10);
    lv_obj_set_x(ui_Screen1_Button16, 78);
    lv_obj_set_y(ui_Screen1_Button16, 6);
    lv_obj_add_flag(ui_Screen1_Button16, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Screen1_Button16, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1_Button16, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Screen1_Button16, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Screen1_Button16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen1_Button16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Screen1_Button16, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Screen1_Button16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Screen1_Button16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Screen1_Button16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Button16, lv_color_hex(0xF13C3C), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_bg_opa(ui_Screen1_Button16, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_color(ui_Screen1_Button16, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_opa(ui_Screen1_Button16, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_Screen1_Button16, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_spread(ui_Screen1_Button16, 0, LV_PART_MAIN | LV_STATE_PRESSED);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
