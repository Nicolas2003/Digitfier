//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Sample: Working with samples of handwritten digit images
//

#include "lib/bitmap/libbmp.h"
#include "splashkit.h"
#include "h/sample.h"
#include "h/image.h"
#include "h/panel.h"

// Reads a sample given a sample id
//
Sample read_sample(int sample_id)
{
    Sample sample;
    sample.sample_id = sample_id;

    for (int digit = 0; digit < 10; digit++)
    {
        string bitmap_name = build_pathway(digit, sample_id);
        write_line(bitmap_name);

        sample.bitmaps[digit] = read_bitmap(bitmap_name);

        sample.images[digit] = read_image(bitmap_name);
        print_bitmap(sample.images[digit]);

        refresh_screen(30);
    }
    return sample;
}
