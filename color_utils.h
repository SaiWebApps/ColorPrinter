#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H

#include <string>

using namespace std;

// Color Macros

#define BLACK       string("\x1b[30;")
#define RED         string("\x1b[31;")
#define GREEN       string("\x1b[32;")
#define YELLOW      string("\x1b[33;")
#define BLUE        string("\x1b[34;")
#define MAGENTA     string("\x1b[35;")
#define CYAN        string("\x1b[36;")
#define WHITE       string("\x1b[37;")

// Array containing the color macros in the order
// that the colors should appear in the output

const string output_order_of_colors[] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, BLACK};

// Macro retrieving the length of the output_order_of_colors array.

#define NUM_COLORS  sizeof(output_order_of_colors) / sizeof(output_order_of_colors[0])

// Color Brightness Macros

#define FAINT       string("22m")
#define BRIGHT      string("1m")

#endif // COLOR_UTILS_H
