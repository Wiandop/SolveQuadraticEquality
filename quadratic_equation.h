#ifndef QUADRATIC_EQUANTION
#define QUADRATIC_EQUANTION


/**
 * @brief Enum type of possible calculating results
 * @detailed Creates a new data type in which
 * all possible counting results are entered for further comparison
 */

typedef enum {
    quadratic_two_roots, // enum first value
    quadratic_one_root, // enum second value
    quadratic_no_roots, // enum third value
    linear_one_root, // enum fourth value
    linear_no_roots, // enum fifth value
    linear_infinity_roots // enum sixth value
} solution_options;

void get_values (double *a, double *b, double *c);
int isEqual(double number);
solution_options calculation_linear(double b, double c, double *x);
solution_options calculation_square(double a, double b, double c, double *x1, double *x2);
void output(double x1, double x2, solution_options solution);

#endif
