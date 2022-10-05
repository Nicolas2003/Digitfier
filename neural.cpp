//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Neural: The heart of Digitfier: Creating, training and running a Neural Network
//         This module utilizes the Genann library: https://github.com/codeplea/genann
//

#include "lib/genann/genann.h"
#include "h/neural.h"
#include "h/image.h"
#include "h/sample.h"
#include "h/panel.h"
#include "splashkit.h"
#include <math.h>
#include <stdio.h>

using namespace std;

#define NEURAL_INPUTS 256
#define HIDDEN_LAYERS 2
#define NEURONS 256
#define NEURAL_OUTPUT 10
#define LEARNING_RATE 0.1
#define TRAINING_LOOPS 1200

// Convert a neural network output into a digit
//
int to_digit(double const *nn_output)
{
    double greatest_value = 0.0;
    int greatest_index;

    for (int i = 0; i < 10; i++)
    {
        if (nn_output[i] > greatest_value)
        {
            greatest_index = i;
            greatest_value = nn_output[i];
        }
    }

    return (greatest_index);
}

// Creates a new Neural Network
//
genann *create_network()
{
    srand(time(0));
    return genann_init(NEURAL_INPUTS, HIDDEN_LAYERS, NEURONS, NEURAL_OUTPUT);
}

// Trains a Neural Network with a set of simplified image samples
//
void train_network(genann *ann, int n, Sample *samples)
{
    const double nn_outputs[10][10] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    };

    for (int i = 0; i < TRAINING_LOOPS; i++)
    {
        write_line("Training loop: " + to_string(i));
        for (int digit = 0; digit < 10; digit++)
            for (int s = 0; s < n; s++)
            {
                genann_train(ann, samples[s].images[digit].extraction, nn_outputs[digit], LEARNING_RATE);
            }
    }
}

// Executes a Neural Network to identify the digit from a simplified image
//
int run_network(genann *ann, double const *nn_input)
{
    double const *nn_output = genann_run(ann, nn_input);
    return to_digit(nn_output);
}
