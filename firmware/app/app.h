/**
 * @file app.h
 * @author Timon Burkard (timon.burkard@gwf.ch)
 *
 * @copyright Copyright (c) 2025 GWF AG
 *
 */

#ifndef APP_H_
#define APP_H_

#include <stdbool.h>
#include <stdint.h>

#include "max7219.h"

#define APP_LCD_TITLE            "GWF Schnupperlehre"
#define APP_LCD_TITLE_SEPARATION "-----------------"
#define APP_LCD_EMPTY_LINE       "                 "

#define APP_LCD_ROW_GAME_DIFFERENCE 14 // Difference between game rows [px]

#define APP_LCD_ROW_TITLE            0  // [px]
#define APP_LCD_ROW_TITLE_SEPARATION 10 // [px]
#define APP_LCD_ROW_GAME_NAME        25 // [px]
#define APP_LCD_ROW_GAME_DYNAMIC_0   (APP_LCD_ROW_GAME_NAME + APP_LCD_ROW_GAME_DIFFERENCE)
#define APP_LCD_ROW_GAME_DYNAMIC_1   (APP_LCD_ROW_GAME_NAME + 2 * APP_LCD_ROW_GAME_DIFFERENCE)

#define APP_LCD_COL_GAME_SELECTION_INDENTATION 14

#define BEEP_SHORT_MS 75
#define BEEP_LONG_MS  750

typedef enum button {
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_CENTER,
    BUTTON_NONE,
} button_t;

extern bool      matrix[MAX7219_COLUMN_AMOUNT][MAX7219_ROW_AMOUNT];
extern max7219_t max7219;

void     app(void);
void     app_beep(uint16_t duration_ms);
button_t app_get_user_input(void);
void     app_matrix_clean(bool matrix[MAX7219_COLUMN_AMOUNT][MAX7219_ROW_AMOUNT]);
void     app_lcd_print_title(void);

#endif /* APP_H_ */
