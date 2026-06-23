#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;


long double math_f (long double point);
long double math_integral (long double par_a, long double par_b);
void get_integrals (
    long double* &par_x,
    const size_t par_K,
    const long double par_a,
    const long double par_b,
    const size_t o);
void evaluate_and_print_errors (
    const long double *par_integrals_value,
    const long double par_math_integral);
void print_line (const size_t par_number_of_hyphens);