#include <string>

#include <stdio.h>
#include <unistd.h>

#include "color_utils.h"
#include "color_printer.h"

using namespace std;

// Default character to print out in different colors
#define DEFAULT_CHARACTER '*'

// Default number of milliseconds to wait for before
// printing the next colored character
#define DEFAULT_NUMBER_MILLISECONDS 1000


/**
 * Constructor
 */
ColorPrinter::ColorPrinter()
{
    this->output_color_brightness = FAINT;
    this->character_printed_in_different_colors = DEFAULT_CHARACTER;
    this->number_milliseconds_between_printouts = DEFAULT_NUMBER_MILLISECONDS;
}

/**
 * Toggle the brightness of the output colors.
 */
void ColorPrinter::toggle_output_color_brightness()
{
    if (output_color_brightness.compare(FAINT) == 0) {
        output_color_brightness = BRIGHT;
    }
    else {
        output_color_brightness = FAINT;
    }
}

/**
 * Set the character that is being printed out on each line in different colors.
 */
void ColorPrinter::set_character_printed_in_different_colors(const char &input_character)
{
    this->character_printed_in_different_colors = input_character;
}

/**
 * Set the number of milliseconds to wait/pause before printing out the next color.
 */
void ColorPrinter::set_number_milliseconds_between_printouts(const int &input_number_milliseconds)
{
    this->number_milliseconds_between_printouts = input_number_milliseconds;
}

/**
 * Helper function to "print_line_of_colored_characters()" - combines the color, brightness, 
 * and output character into a single string that can be printed out to stdout.
 */
string ColorPrinter::get_output_string(const string &current_color)
{
    string output_string = current_color; // \x1b[31:
    output_string += output_color_brightness; // 1m if brightness is enabled or m if disabled
    output_string += character_printed_in_different_colors; // a

    return output_string; // Overall -> "\x1b[31:0ma" will print red 'a'
}

/**
 * Print out a line consisting of the same character in different colors.
 */
void ColorPrinter::print_line_of_colored_characters()
{
    int i;
    int number_seconds_between_printouts = number_milliseconds_between_printouts / 1000;

    for (i = 0; i < NUM_COLORS; i++) {
        string output_string = get_output_string(output_order_of_colors[i]);
        printf("%s", output_string.c_str());
        fflush(stdout);
        sleep(number_seconds_between_printouts);
    }
    printf("\n");
}

/**
 * Destructor
 */
ColorPrinter::~ColorPrinter()
{
}
