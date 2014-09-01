#ifndef COLOR_PRINTER_H
#define COLOR_PRINTER_H

#include <string>

#include "color_utils.h"

using namespace std;

class ColorPrinter 
{
private:
    string output_color_brightness;
    char character_printed_in_different_colors;
    int number_milliseconds_between_printouts;
    string get_output_string(const string &current_color);

public:
    ColorPrinter(); // constructor
    void toggle_output_color_brightness();
    void set_character_printed_in_different_colors(const char &input_character);
    bool set_number_milliseconds_between_printouts(const int &input_number_milliseconds);
    void print_line_of_colored_characters();
    ~ColorPrinter(); // destructor
};

#endif // COLOR_PRINTER_H
