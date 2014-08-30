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

#define NUM_COLORS 8

// Array containing the color macros in the order
// that the colors should appear in the output

const string output_order_of_colors[NUM_COLORS] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, BLACK};

// Color Brightness Macros

#define FAINT       string("22m")
#define BRIGHT      string("1m")

#endif // COLOR_UTILS_H
