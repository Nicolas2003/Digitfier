//
// Digitfier - Identifying handwritten digits via image recognition
// Created by Nicolas Subasic de Azevedo, 2022
//
// Main Program
//

#include "splashkit.h"
#include "lib/genann/genann.h"
#include "lib/bitmap/libbmp.h"
#include "h/neural.h"
#include "h/image.h"
#include "h/panel.h"
#include "h/sample.h"

// Defining changable values for variables
//
#define FIRST_SAMPLE_ID 10
#define LAST_SAMPLE_ID 19
#define SAMPLE_SIZE (LAST_SAMPLE_ID - FIRST_SAMPLE_ID + 1)
#define TEST_SAMPLE_ID (LAST_SAMPLE_ID + 1)

using namespace std;

// reads a digit from the terminal given a prompt
//
int read_digit(string prompt)
{
    write(prompt);
    string response = read_line();

    if (is_integer(response))
    {
        int number = convert_to_integer(response);
        if (number >= 0 && number <= 9)
            return number;
    }

    return read_digit(prompt);
}

// reads the user's input from the terminal given a prompt
//
string read_str(string prompt)
{
    write(prompt);
    return read_line();
}

// Returns the pathway for the bitmap that user wants to be identified
//
string choose_bitmap_file()
{
    int digit = read_digit("Which digit do you want the image recognition to identify? ");
    return build_pathway(digit, TEST_SAMPLE_ID);
}

// Asks the user if they want to continue
//
bool keep_running()
{
    string response = to_lowercase(read_str("Do you want to continue testing the neural network? "));
    if (response == "" || response == "y" || response == "yes")
    {
        return true;
    }
    else if (response == "n" || response == "no")
    {
        return false;
    }
    else
    {
        write_line("Your answered couldn't be interpreted");
        return keep_running();
    }
}

// Executes the main program
//
int main()
{
    Sample samples[SAMPLE_SIZE];

    open_window("Number Recognition", 1300, 1000);
    genann *ann = create_network();

    // Reads the Samples
    //
    write_line("Reading Samples");
    for (int si = 0; si < SAMPLE_SIZE; si++)
    {
        int sample_id = FIRST_SAMPLE_ID + si;

        samples[si] = read_sample(sample_id);
        draw_position_10_bitmaps(samples[si].bitmaps, si % 5);
        write_line("This for loop is being executed. sample: " + to_string(sample_id));
        refresh_screen(30);
    }

    // Trains the Neural Network
    //
    write_line("Training with Samples...");
    train_network(ann, SAMPLE_SIZE, samples);
    display_texts();

    // Identifies the digit in bitmaps
    //
    do
    {
        write_line();
        clear_position(2, 6);
        clear_position(6, 6);

        string bitmap_name = choose_bitmap_file();
        write_line(bitmap_name);

        bitmap digit_image = read_bitmap(bitmap_name);
        draw_position(digit_image, 2, 6);
        refresh_screen(30);

        Image image = read_image(bitmap_name);
        int recognised_digit = run_network(ann, image.extraction);

        bitmap recognised_image = read_bitmap(build_pathway(recognised_digit, LAST_SAMPLE_ID));
        draw_position(recognised_image, 6, 6);

        write_line("The Image has a " + to_string(recognised_digit));

        process_events();
    } while (keep_running());

    exit(0);
}
