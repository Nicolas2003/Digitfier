//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Panel: Displaying the bitmaps and texts
//

#include "splashkit.h"

#ifndef PANEL_HEADER
#define PANEL_HEADER

void clear_position(int x, int y);
void draw_position(bitmap number, int x, int y);
void draw_position_10_bitmaps(bitmap bitmaps[10], int y);

void display_texts();

#endif
