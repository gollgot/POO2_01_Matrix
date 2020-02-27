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

public:
    Matrix(int n, int m, int modulus);

    Matrix addStatic(const Matrix& other) const;
    Matrix subStatic(const Matrix& other) const;
    Matrix multiplyStatic(const Matrix& other) const;

    // TODO addDynamic(), subDynamic(), multiplyDynamic()
    // TODO addModify(), subModify(), multiplyModify()

    // TODO operator=
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    ~Matrix();

private:
    int trueModulus(int value, int mod) const;
};


#endif //POO2_Labo01_MATRIX_H
