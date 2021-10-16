#include "quadratic_equality.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

// safe input
/**
 * @brief Function for getting values
 * @details The user enters 3 numbers - the coefficients of the quadratic equation.
 * @param a Main coefficient
 * @param b Second coefficient
 * @param c Free coefficient
 */
void get_values (double *a, double *b, double *c) {
    printf("Hello! Please enter 3 numbers: \n");
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    // provided that the input is not a number
    while ((scanf("%lf %lf %lf", a, b, c)) != 3) {
        printf("Wrong value, please enter again \n");
        while (getchar() != '\n');
    }
}

// comparing numbers
/**
 * @brief Function for comparing numbers
 * @details Comparison numbers of double type
 * @param number The number to be compared
 * @return 3 values: -1, 0, 1
 */
int isEqual(double number) {
    double EPS = 1.0E-9;

    if (number > 0) {
        return 1;
    } else if (fabs(number) < EPS) {
        return 0;
    } else if (number < 0) {
        return -1;
    }
}

// calculating a linear equation
/**
 * @brief Function for calculating the root of a linear equation
 * @details Function is triggered if the main coefficient is 0.
 * The function considers three possible options:
 * one root, no roots, infinitely roots
 * @param b Second coefficient
 * @param c Free coefficient
 * @param x Root of equation
 * @see solution_options
 * isEqual
 * @return Returns one of three parameters from solution_options
 */
solution_options calculation_linear(double b, double c, double *x) {
    assert(x != NULL);

    if (isEqual(b) != 0) {
        *x = c / b; // calculating root

        return linear_one_root;
    } else {
        if (isEqual(c) != 0) {
            return linear_no_roots;
        } else {
            return linear_infinity_roots;
        }
    }
}

// calculating a quadratic equation
/**
 * @brief Function for calculating the roots of a quadratic equation
 * @details The function calculates the discriminant of the equation
 * and based on this gets three possible options:
 * two roots, one root, no roots
 * @param a Main coefficient
 * @param b Second coefficient
 * @param c Free coefficient
 * @param x1 First root of equation
 * @param x2 Second root of equation
 * @see solution_options
 * calculation_linear
 * isEqual
 * @return Returns one of three parameters from solution_options
 */
solution_options calculation_square(double a, double b, double c, double *x1, double *x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (isEqual(a) == 0) {
        calculation_linear(b, c, x1);
    } else {
        double D = (b * b) - (4 * a * c);

        if (isEqual(D) == 1) { // calculating two roots
            *x1 = ((-b + sqrt(D)) / (2 * a));
            *x2 = ((-b - sqrt(D)) / (2 * a));

            return quadratic_two_roots;
        } else if (isEqual(D) == 0) { // calculating root
            *x1 = (-b / (2 * a));

            return quadratic_one_root;
        } else if (isEqual(D) == -1) {
            return quadratic_no_roots;
        }
    }
}

// output of the result
/**
 * @brief Function for output of results
 * @details The value of solution is compared with the values from solution_options
 * and, if a match occurs, the result is output
 * @param x1 First root of equality
 * @param x2 Second root of equality
 * @param solution Suitable value from solution_options
 */
void output(double x1, double x2, solution_options solution) {
    switch (solution) {
        case quadratic_two_roots:
            printf("This is a quadratic equation. The equation has two roots. \n");
            printf("x1 = %lf; x2 = %lf. \n", x1, x2);
            break;
        case quadratic_one_root:
            printf("This is a quadratic equation. The equation has one root. \n");
            printf("x = %lf. \n", x1);
            break;
        case quadratic_no_roots:
            printf("This is a quadratic equation. The equation has no roots. \n");
            break;
        case linear_one_root:
            printf("This is a linear equation. The equation has one root. \n");
            printf("x = %lf. \n", x1);
            break;
        case linear_no_roots:
            printf("This is a linear equation. The equation has no roots. \n");
            break;
        case linear_infinity_roots:
            printf("This is a linear equation. The equation has infinity roots. \n");
            break;
    }
}