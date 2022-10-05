//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Panel: Displaying the bitmaps and texts
//

#include "h/panel.h"

// Removes a digit bitmap from a position
//
void clear_position(int x, int y)
{
    fill_rectangle(COLOR_WHITE, x * 128, y * 128, 128, 128);
    refresh_screen(30);
}

// Draws a digit bitmap in a position
//
void draw_position(bitmap number, int x, int y)
{
    draw_bitmap(number, x * 128, y * 128);
    refresh_screen(30);
}

// Draws the bitmaps corresponding to a sample of digits
//
void draw_position_10_bitmaps(bitmap bitmaps[10], int y)
{
    for (int i = 0; i < 10; i++)
        draw_bitmap(bitmaps[i], i * 128, y * 128);
}

// Display headers to the program
//
void display_texts()
{
    draw_text("Identifying:", COLOR_STEEL_BLUE, "arial", 100, 100, 768);
    draw_text("Predicted:", COLOR_RED, font_named("arial"), 100, 590, 768);
    refresh_screen(30);
}
