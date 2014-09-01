package main;

use strict;
use warnings;

# Constants
my $RESTORE_DEFAULT_ANSI_CODE = "\x1b[0m"; # Use to restore default color settings.
my $RED_ANSI_CODE = "\x1b[31m"; # Ansi code to display text in red
my $GREEN_ANSI_CODE = "\x1b[32m"; # Ansi code to display text in green

sub main {
    # List of requirements to search for
    my @string_array_requirements = ("R1.1", "R1.2", "R2.1", "R2.2", "R3.1", "R3.2", "R4");

    # Files to search in
    my $string_search_files = "*.h *.cpp";

    # Search for each requirement in the given files. If we don't find the requirement
    # in any of the files, then we have failed to satisfy it. Otherwise, we've passed it.
    for my $string_requirement (@string_array_requirements) {

        # Number of times that the current requirement appears in each input file
        my @int_array_counts=`grep -c $string_requirement $string_search_files | cut -d ':' -f2`;

        # Line numbers where this requirement occurred in the given files
        my @int_line_numbers=split('\n', `grep -n $string_requirement $string_search_files | cut -d ':' -f1,2`);

        # Sum of values in int_array_counts - the total # of times that this
        # requirement appears in the given number of files
        # If we passed this requirement, then this sum will be greater than 0.
        my $int_sum = 0;
        $int_sum += $_ for (@int_array_counts);

        # String to print out, indicating if requirement was met or not
        my $string_output = "Requirement $string_requirement - ";

        # If the sum was 0, then this requirement was not satisfied in any of the files,
        # so we have failed to meet it. Otherwise, we have satisfied it.
        if ($int_sum == 0) {
            $string_output = $RED_ANSI_CODE.$string_output."\tFAILED";   # Show failures in red.
        }
        else {
            $string_output = $GREEN_ANSI_CODE.$string_output."\tPASSED\t".join(',', @int_line_numbers);
        }

        $string_output = $string_output."\n$RESTORE_DEFAULT_ANSI_CODE";
        print($string_output);
    }
}

main();
