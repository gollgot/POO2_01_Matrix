/*
 * File     : Matrix.h
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 21.02.2020
 */

#ifndef POO2_Labo01_MATRIX_H
#define POO2_Labo01_MATRIX_H

#include <ostream>
#include "Operator.h"

class Matrix {
private:
    int n;
    int m;
    int modulus;
    int** content;

    /**
     * Populate the Matrix with values between 0 and modulus-1
     */
    void randomPopulate();

    /**
     * Perform an arithmetic operation
     * @param other
     * @param op
     * @return
     */
    Matrix calc(const Matrix& other, Operator& op) const;

    /**
     * Test a modulus. It cannot be 0 or minus because of the matrix values that must be between 0 and modulus-1
     * @param modulus The modulus
     * @throws RuntimeException if the modulus is 0 or minus
     */
    void testModulus(int modulus) const;

    /**
     * Test the matrix dimensions. We cannot have void or negative dimensions
     * @param n The row size of the Matrix
     * @param m The column size of the Matrix
     * @throws RuntimeException if a matrix dimension is 0 or negative
     */
    void testMatrixDimensions(int n, int m) const;

public:
    Matrix(int n, int m, int modulus);
    Matrix(const Matrix& m);

    Matrix addStatic(const Matrix& other) const;
    Matrix subStatic(const Matrix& other) const;
    Matrix multiplyStatic(const Matrix& other) const;

    // TODO addDynamic(), subDynamic(), multiplyDynamic()
    // TODO addModify(), subModify(), multiplyModify()

    Matrix& operator=(const Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    ~Matrix();

private:
    int trueModulus(int value, int mod) const;
};


#endif //POO2_Labo01_MATRIX_H
