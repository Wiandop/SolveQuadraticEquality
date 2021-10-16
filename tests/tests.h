#ifndef TESTS
#define TESTS

typedef enum {
    OK,
    ligma
} errors;

int run_all_tests();
errors test__isEqual();
errors test__calculation_linear();
errors test__calculation_square();

#endif