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
    this->stay_on_same_line = false;

    // R2.1
    this->character_printed_in_different_colors = DEFAULT_CHARACTER;

    // R3.1
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
 * Set stay_on_same_line to the specified value.
 * If stay_on_same_line is true, we will print '\r' after the line we just printed.
 * Otherwise, we will print '\n' after the line of colored characters.
 */
void ColorPrinter::set_stay_on_same_line(const bool &input_stay_on_same_line)
{
    this->stay_on_same_line = input_stay_on_same_line;
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
 * Preconditions:
 *      input_number_milliseconds > 0
 * Return Value:
 *      a boolean - true if precondition was observed and number_milliseconds_between_printouts
 *                  was successfully updated; false otherwise
 */
bool ColorPrinter::set_number_milliseconds_between_printouts(const int &input_number_milliseconds)
{
    // R2.2
    if (input_number_milliseconds >= 0) {
        this->number_milliseconds_between_printouts = input_number_milliseconds;
        return true;
    }
    return false;
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

    // R1.1
    for (i = 0; i < NUM_COLORS; i++) {
        string output_string = get_output_string(output_order_of_colors[i]);
        printf("%s", output_string.c_str());
        fflush(stdout);
        sleep(number_seconds_between_printouts);
    }

    if (stay_on_same_line == true) {
        printf("\r");
    }
    else {
        printf("\n");
    }
}

/**
 * Destructor
 */
ColorPrinter::~ColorPrinter()
{
}
