//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Sample: Working with samples of handwritten digit images
//

#include "./image.h"
#include "splashkit.h"

#ifndef SAMPLE_HEADER
#define SAMPLE_HEADER

struct Sample
{
    int sample_id;
    Image images[10];
    bitmap bitmaps[10];
};

Sample read_sample(int sample_id);

#endif
