//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Image: working with bitmaps and their simplified images
//		  This module utilizes the libbmp library: https://github.com/marc-q/libbmp
//

#include <math.h>
#include "lib/bitmap/libbmp.h"
#include "h/image.h"
#include "h/sample.h"

using namespace std;

#define THRESHOLD 180  	// Maximum colour intensity for non-blank pixels
#define is_black(img) 	(img.blue_at(x, y) < THRESHOLD) || (img.green_at(x, y) < THRESHOLD) || (img.red_at(x, y) < THRESHOLD)
#define index(x,y)  	(x / 8 + 16 * (y / 8))

// File pathway directing to a digit's bitmap in a sample
//
string build_pathway(int digit, int sample)
{
    string file_name = "./images/digits/" + to_string(digit) + "/" + to_string(sample) + ".bmp";
    return file_name;
}

// Reads the bitmap in a file
//
bitmap read_bitmap(string file_name)
{
	bitmap bit_num = load_bitmap(file_name, file_name);
	bitmap_set_cell_details(bit_num, 128, 128, 1, 1, 1);
	return bit_num;
}

// Displays a digit's simplified image on the screen, using 0s and spaces
//
void print_bitmap(Image img)
{
	write_line("------------------");
	for (int i = 0; i < 256; i++)
	{
		string bit = round(img.extraction[i]) > 0.9 ? "O" : " ";
		if (i % 16 == 0)
			write_line();
		write(bit + " ");
	}
	write_line();
	write_line("------------------");
	write_line();
}

// Reads a digit's bitmap and converts it into a simplified image
//
Image read_image(string file_name)
{
	Image result;
	BmpImg img;

	img.read(file_name);
	result.file_name = file_name;

	// Use negative loops to improve performance
	for (int i = 255; i >= 0; i--)
	{
		result.extraction[i] = 0;
	}

	for (int y = img.get_height() - 1; y >= 0; y--)
	{
		for (int x = img.get_width() - 1; x >= 0; x--)
		{
			// checks whether the pixel can be considered as non-blank
			//
			if (is_black(img))
				result.extraction[index(x, y)]++;
		}
	}
	for (int i = 255; i >= 0; i--)
	{
		result.extraction[i] = (result.extraction[i] >= 8) ? 0.0 : 1.0;
	}

	return result;
}
