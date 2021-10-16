#include "tests.h"
#include "../quadratic_equation.h"
#include <stdio.h>
#include <assert.h>

int run_all_tests() {
    assert(OK == test__isEqual());
    assert(OK == test__calculation_linear());
    assert(OK == test__calculation_square());
}

// Test isEqual()

errors test__isEqual() {
    printf("Testing isEqual(). \n");

    double test_number1 = 0.256158;     // The comparison of double > zero
    if (isEqual(test_number1) != 1) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    double test_number2 = 0;            // The comparison of double = zero
    if (isEqual(test_number2) != 0) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    double test_number3 = -0.25623;     // The comparison of double < zero
    if (isEqual(test_number3) != -1) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    printf("Testing isEqual() completed! \n \n");
    return OK;
}

// Test calculation_linear()

errors test__calculation_linear() {
    printf("Tested calculation_linear(). \n");

    double x = 0;
    double test_b1 = 2;
    double test_c1 = 5;                 // A linear equation has one root
    if (calculation_linear(test_b1, test_c1, &x) != linear_one_root) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    double test_b2 = 0;
    double test_c2 = 5;                 // A linear equation has an infinity of roots
    if (calculation_linear(test_b2, test_c2, &x) != linear_no_roots) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    double test_b3 = 0;
    double test_c3 = 0;                 // A linear equation has no roots
    if (calculation_linear(test_b3, test_c3, &x) != linear_infinity_roots) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    printf("Testing calculation_linear() completed! \n \n");
    return OK;
}

// Test calculation_square()

errors test__calculation_square() {
    printf("Tested calculation_square(). \n");

    double x1 = 0;
    double x2 = 0;
    double test_a1 = 0;
    double test_b1 = 2;
    double test_c1 = 5;                     // The quadratic equation becomes linear and has one root
    if (calculation_square(test_a1, test_b1, test_c1, &x1, &x2) != linear_one_root) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    double test_a2 = 1;
    double test_b2 = 5;
    double test_c2 = -6;                     // The quadratic equation has two roots
    if (calculation_square(test_a2, test_b2, test_c2, &x1, &x2) != quadratic_two_roots) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    double test_a3 = 1;
    double test_b3 = -4;
    double test_c3 = 4;                     // The quadratic equation has one root
    if (calculation_square(test_a3, test_b3, test_c3, &x1, &x2) != quadratic_one_root) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    double test_a4 = 1;
    double test_b4 = 2;
    double test_c4 = 5;                      // The quadratic equation has no roots
    if (calculation_square(test_a4, test_b4, test_c4, &x1, &x2) != quadratic_no_roots) {
        printf("Hey, your program is not working correctly! \n");
        return ligma;
    }

    printf("Testing calculation_linear() completed! \n \n");
    return OK;
}
