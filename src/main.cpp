#include "functions.h"

int main () {

	// Parameters of the program. //
    const long double a = 0.0, b = 1.0;
    const size_t K = 10;
    // long double rectangle_K, trapezoid_K, simpson_K, newton_kotes_K, gauss_K;
    // long double rectangle_2K, trapezoid_2K, simpson_2K, newton_kotes_2K, gauss_2K;
    long double *integrals_value = new long double [10];
    get_integrals (integrals_value, K, a, b, 0);
    get_integrals (integrals_value, 2 * K, a, b, 1);
    evaluate_and_print_errors (integrals_value, math_integral (a, b));
    // cout << "Math formula = " << math_integral (a, b) << endl;
    // cout << "rectangle_K = " << integrals_value[0] << endl;
    // cout << "rectangle_2K = " << integrals_value[5] << endl;
    // cout << "trapezoid_K = " << integrals_value[1] << endl;
    // cout << "trapezoid_2K = " << integrals_value[6] << endl;
    // cout << "simpson_K = " << integrals_value[2] << endl;
    // cout << "simpson_2K = " << integrals_value[7] << endl;
    // cout << "newton_kotes_K = " << integrals_value[3] << endl;
    // cout << "newton_kotes_2K = " << integrals_value[8] << endl;
    // cout << "gauss_K = " << integrals_value[4] << endl;
    // cout << "gauss_2K = " << integrals_value[9] << endl;

    delete [] integrals_value;

    return 0;
}