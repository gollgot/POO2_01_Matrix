/*
 * File     : main.cpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 21.02.2020
 */

#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    const int MODULUS = 5;

    Matrix m1(3, 4, MODULUS);
    Matrix m2(3, 5, MODULUS);

    cout << "The modulus is " << MODULUS << endl;
    cout << "one" << endl << m1 << endl;
    cout << "two" << endl << m2 << endl;

    Matrix m3 = m1.addStatic(m2);
    cout << "one + two" << endl << m3 << endl;

    Matrix m4 = m1.subStatic(m2);
    cout << "one - two" << endl << m4 << endl;

    Matrix m5 = m1.multiplyStatic(m2);
    cout << "one + two" << endl << m5 << endl;

    return EXIT_SUCCESS;
}