#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "color_printer.h"

#define SUCCESS_EXIT_STATUS 0
#define FAILURE_EXIT_STATUS 1

// Global variables for processing command-line options and values

struct option long_options[] = {
    {"verbose", no_argument, 0, 'v'},
    {"single-line", no_argument, 0, 's'},
    {"pause-in-ms", required_argument, 0, 'p'},
    {"character-to-print", required_argument, 0, 'c'}
};

void print_usage(char *program_name)
{
    printf("%s [-p] [-c] [-v] [-s]\n", program_name);
    printf("%-30s%30s\n", "-p (--pause-in-ms):", "Number of milliseconds to wait before printing each character.");
    printf("%-30s%30s\n", "-c (--character-to-print):", "Character to print on each line in different colors.");
    printf("%-30s%30s\n", "-v (--verbose):", "Display program's command-line usage information.");
    printf("%-30s%30s\n", "-s (--single-line):", "Stay on the same line.");
}

void parse_command_line_arguments(int argc, char *argv[], ColorPrinter *cp)
{
    char character;
    int option, option_index, num_millis;

    while((option = getopt_long(argc, argv, "p:c:sv", long_options, &option_index)) != -1) {
        switch(option) {

            // Pause in milliseconds - how long to wait before printing out next character
            // creates a progress-bar-like effect
            case 'p':
                num_millis = atoi(optarg);

                // R2.2 - If user value for # of milliseconds is invalid, then we will print an
                // error message and continue executing with the default value.
                if (cp->set_number_milliseconds_between_printouts(num_millis) == false) {
                    fprintf(stderr, "The number of milliseconds to wait between character printouts must be strictly greater than 0.\n");
                }
                break;

            // Character being printed out in different colors in each line
            case 'c':
                character = optarg[0]; // R3.2
                cp->set_character_printed_in_different_colors(character);
                break;

            // Instead of printing a new line of colored characters with every cyclic executive cycle,
            // return to the beginning of the same line.
            case 's':
                cp->set_stay_on_same_line(true);
                break;

            // Verbose option to display program's command-line usage information
            // Program will execute normally after that, using the default values.
            case 'v':
                print_usage(argv[0]);
                break;

            // Invalid command-line arguments - Print the usage in addition to the error-message and exit.
            default:
                print_usage(argv[0]);
                exit(FAILURE_EXIT_STATUS);
                break;
        }
    }
}

int main(int argc, char *argv[])
{
    ColorPrinter cp;

    parse_command_line_arguments(argc, argv, &cp);

    // R4 - All actions shall be executed from within a cyclic executive.
    for (;;) {
        cp.print_line_of_colored_characters();

        // R1.2
        cp.toggle_output_color_brightness();
    }
    return 0;
}
