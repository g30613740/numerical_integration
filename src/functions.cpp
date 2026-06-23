#include "functions.h"


long double math_f (long double par_point) {

    // return sin (par_point);
    // return (5.0 * pow (point, 4) + 4.0 * pow (point, 3) + 3.0 * pow (point, 2) + 2.0 * point + 1.0);
    // return (3.0 * pow (point, 2) + 2.0 * point + 1.0);
    return (pow (par_point, 7));
}

long double math_integral (long double par_a, long double par_b) {

    return ((pow (par_b, 8) - pow (par_a, 8)) / 8.0);
    // return (cos (par_a) - cos (par_b));
    // return (((pow (par_b, 5) + pow (par_b, 4) + pow (par_b, 3) + pow (par_b, 2) + par_b)) - (pow (par_a, 5) + pow (par_a, 4) + pow (par_a, 3) + pow (par_a, 2) + par_a));
    // return (((pow (par_b, 3) + pow (par_b, 2) + par_b)) - (pow (par_a, 3) + pow (par_a, 2) + par_a));
}

void get_integrals (
    long double* &par_integrals_value,
    const size_t par_K,
    const long double par_a,
    const long double par_b,
    const size_t o) {

    const size_t rec = 0 + 5 * o,
                 tra = 1 + 5 * o,
                 sim = 2 + 5 * o,
                 nek = 3 + 5 * o,
                 gau = 4 + 5 * o;
    const long double h = abs (par_b - par_a) / par_K;
    const long double half_h = h / 2.0;

    long double boundaries_sum = math_f (par_a) + math_f (par_b);
    par_integrals_value[rec] = math_f (par_a + half_h) + math_f (par_b - half_h);
    par_integrals_value[tra] = boundaries_sum / 2.0 + math_f (par_b - h);
    par_integrals_value[sim] = boundaries_sum;
    par_integrals_value[sim] += 2.0 * (2.0 * (math_f (par_a + half_h) + math_f (par_b - half_h)) + math_f (par_b - h));
    par_integrals_value[nek] = 7.0 * (boundaries_sum + 2 * math_f (par_b - h));
    par_integrals_value[nek] += 12.0 * (math_f (par_a + half_h) + math_f (par_b - half_h));
    par_integrals_value[nek] += 32.0 * (math_f (par_a + h / 4.0) + math_f (par_a + 0.75 * h) + math_f (par_b - h / 4.0) + math_f (par_b - 0.75 * h));
    par_integrals_value[gau] = 8.0 / 9.0 * (math_f (par_a + half_h) + math_f (par_b - half_h));
    par_integrals_value[gau] += 5.0 / 9.0 * (math_f (par_a + half_h - sqrt (0.6) * half_h) + math_f (par_a + half_h + sqrt (0.6) * half_h));
    par_integrals_value[gau] += 5.0 / 9.0 * (math_f (par_b - half_h + sqrt (0.6) * half_h) + math_f (par_b - half_h - sqrt (0.6) * half_h));

    long double x = par_a + h;
    for (size_t i = 0; i < par_K - 2; ++i) {
        const long double math_f_x = math_f (x);
        // const long double math_f_x_plus_h = math_f (x + h);
        const long double math_f_x_plus_half_h = math_f (x + half_h);
        par_integrals_value[rec] += math_f_x_plus_half_h;
        par_integrals_value[tra] += math_f_x; // 0.5 1.0 1.0 ... 1.0 1.0 0.5
        par_integrals_value[sim] += 2.0 * math_f_x; // 1.0 4.0 1.0
        par_integrals_value[sim] += 4.0 * math_f_x_plus_half_h;
        par_integrals_value[nek] += 14.0 * math_f_x; // 7.0 32.0 12.0 32.0 7.0
        par_integrals_value[nek] += 32.0 * (math_f (x + h / 4.0) + math_f (x + 0.75 * h));
        par_integrals_value[nek] += 12.0 * math_f_x_plus_half_h;
        par_integrals_value[gau] += 5.0 / 9.0 * (math_f (x + half_h - sqrt (0.6) * half_h) + math_f (x + half_h + sqrt (0.6) * half_h));
        par_integrals_value[gau] += 8.0 / 9.0 * math_f_x_plus_half_h;
        x += h;
    }
    par_integrals_value[rec] = h * par_integrals_value[rec];
    par_integrals_value[tra] = h * par_integrals_value[tra];
    par_integrals_value[sim] = h / 6.0 * par_integrals_value[sim];
    par_integrals_value[nek] =  h / 90.0 * par_integrals_value[nek];  // h / 90.0 = 2 * h / (45.0 * 4)
    par_integrals_value[gau] = half_h * par_integrals_value[gau];
}

void evaluate_and_print_errors (
    const long double *par_integrals_value,
    const long double par_math_integral) {

    cout << "\n       Table of relative errors\n";
    print_line (40);
    cout << '|' << setw (15) << "|";
    cout << setw (11) << "     K     " << '|';
    cout << setw (11) << "   2 * K   " << '|';
    cout << "\n";
    print_line (40);

    cout << left;              // alignment
    cout << scientific;        // floating-point output
    cout << setprecision (3);  // precision
    for (size_t i = 0; i < 5; ++i) {
        cout << '|' << setw (14);
        if (i == 0)
            cout << "  Rectangle";
        else if (i == 1)
            cout << "  Trapezoid";
        else if (i == 2)
            cout << "   Simpson";
        else if (i == 3)
            cout << " Newton-Kotes";
        else if (i == 4)
            cout << "    Gauss";
        cout << "| " << setw (6) << abs (par_integrals_value[i] - par_math_integral) / par_math_integral << " | ";
        cout << setw (6) << abs (par_integrals_value[i+5] - par_math_integral) / par_math_integral << " | " << endl;
        print_line (40);
    }
    cout << endl;
}

void print_line (const size_t par_number_of_hyphens) {

    for (size_t i = 0; i < par_number_of_hyphens; ++i)
        cout << "–";
    cout << "\n";
}