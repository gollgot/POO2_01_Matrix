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

public:
    Matrix(int n, int m, int modulus);
    Matrix(const Matrix& m);

    Matrix addCopy(const Matrix& other) const;
    Matrix subCopy(const Matrix& other) const;
    Matrix multiplyCopy(const Matrix& other) const;

    Matrix* addDynamic(const Matrix& other) const;
    Matrix* subDynamic(const Matrix& other) const;
    Matrix* multiplyDynamic(const Matrix& other) const;

    Matrix& addModify(const Matrix& other);
    Matrix& subModify(const Matrix& other);
    Matrix& multiplyModify(const Matrix& other);

    Matrix& operator=(const Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    ~Matrix();

private:
    /**
     * Populate the Matrix with random values between 0 and modulus-1
     */
    void randomPopulate();

    /**
     * Perform arithmetic operation on current matrix (Matrix object on which this function is called will be modified)
     * @param other
     * @param op
     * @return
     */
    Matrix& calc(const Matrix& other, const Operator& op);

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

    /**
     * Returns a cyclic value (going from 0 to modulus) instead of a negative one if left operand of % is negative.
     * -1 % 5 will give 4 instead of -1.
     * Formula source: https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
     * @param lhs
     * @param rhs
     * @return
     */
    int trueModulus(int value, int mod) const;
};


#endif //POO2_Labo01_MATRIX_H
