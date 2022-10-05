//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Neural: The heart of Digitfier: Creating, training and running a Neural Network
//         This module utilizes the Genann library: https://github.com/codeplea/genann
//

#include "../lib/genann/genann.h"
#include "../lib/bitmap/libbmp.h"
#include "splashkit.h"
#include "sample.h"

#ifndef NEURAL_HEADER
#define NEURAL_HEADER

genann *create_network();
void train_network(genann *ann, int n, Sample *samples);
int run_network(genann *ann, double const *extraction);

#endif
