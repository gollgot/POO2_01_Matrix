/*
 * File     : main.cpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 21.02.2020
 */

#include <iostream>
#include "Matrix.hpp"

using namespace std;

/**
 * Tests the 3 different ways of applying operation on Matrix object.
 * @param n1
 * @param m1
 * @param n2
 * @param m2
 * @param modulus
 */
void testMatrix(int n1, int m1, int n2, int m2, int modulus) {

    cout << "The modulus is " << modulus << endl;

    Matrix matrix1(n1, m1, modulus);
    Matrix matrix2(n2, m2, modulus);
    cout << endl << "Testing \"Copy\" function" << endl << endl;
    cout << "one" << endl << matrix1 << endl << "two" << endl << matrix2 << endl;
    cout << "one + two" << endl << matrix1.addCopy(matrix2) << endl;
    cout << "one - two" << endl << matrix1.subCopy(matrix2) << endl;
    cout << "one * two" << endl << matrix1.multiplyCopy(matrix2) << endl;

    cout << "Testing \"Modify\" function" << endl << endl;
    cout << "one" << endl << matrix1 << endl << "two" << endl << matrix2 << endl;
    matrix1.addModify(matrix2);
    cout << "one + two" << endl << matrix1 << endl;

    cout << "Testing \"Dynamic\" function" << endl << endl;
    cout << "one" << endl << matrix1 << endl << "two" << endl << matrix2 << endl;
    Matrix* matrix3 = matrix1.addDynamic(matrix2);
    cout << "one + two" << endl << *matrix3 << endl;
    delete matrix3;

}

int main() {
    
    testMatrix(3, 4, 3, 5, 5);

    return EXIT_SUCCESS;
}