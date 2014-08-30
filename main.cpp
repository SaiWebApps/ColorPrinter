#include "color_printer.h"

int main()
{
    ColorPrinter cp;

    // Cyclic executive
    for (;;) {
        cp.print_line_of_colored_characters();
        cp.toggle_output_color_brightness();
    }
    return 0;
}
