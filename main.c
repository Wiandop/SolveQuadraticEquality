#include "quadratic_equality.c"

/**
 * OUTPUT_LANGUAGE = English
 * PROJECT_NAME = Quadratic equation
 * PROJECT_NUMBER = 1.0.0
 * PROJECT_BRIEF = A program for calculating the roots of a quadratic equation
 * OUTPUT_DIRECTORY = /doc
 */

/**
 * @brief Entry point
 * @detailed Execution of the program
 * starts here.
 * @see Ref
 * solution_options
 * get_values
 * calculation_square
 * output
 * @return Program exit status
 */

int main() {
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    solution_options solution;

    get_values(&a, &b, &c);
    solution = calculation_square(a, b, c, &x1, &x2);
    output(x1, x2, solution);
    return 0;
}
