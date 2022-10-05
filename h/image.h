//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Image: working with bitmaps and their simplified images
//		  This module utilizes the libbmp library: https://github.com/marc-q/libbmp
//

#include "splashkit.h"
#include "../lib/genann/genann.h"
#include "../lib/bitmap/libbmp.h"

#ifndef IMAGE_HEADER
#define IMAGE_HEADER

bitmap read_bitmap(string file_name);

struct Image
{
	string file_name;
	double extraction[256];
};

void print_bitmap(Image img);
Image read_image(string file_name);
Image bw_bitmap(string bitmap_name, int digit);

string build_pathway(int digit, int sample);

#endif

