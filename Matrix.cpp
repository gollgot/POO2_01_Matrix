/*
 * File     : Matrix.cpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 21.02.2020
 */

#include <cstdlib>
#include <algorithm>
#include <ctime>

#include "Matrix.hpp"
#include "Operator.hpp"
#include "Addition.hpp"
#include "Subtraction.hpp"
#include "Multiply.hpp"

using namespace std;

Matrix::Matrix(int n, int m, int modulus) : n(n), m(m), modulus(modulus) {

    testModulus(modulus);
    testMatrixDimensions(n, m);

    // Initialize content array
    content = new int* [n];
    for(int i = 0; i < n; ++i)
        content[i] = new int[m];

    randomPopulate();
}

Matrix::Matrix(const Matrix& matrix) {
    // variables copy
    n = matrix.n;
    m = matrix.m;
    modulus = matrix.modulus;

    // Initialize new content array and copy same values as the cpy matrix content
    content = new int* [n];
    for(int i = 0; i < n; ++i) {
        content[i] = new int[m];
        for(int j = 0; j < m; j++) {
            content[i][j] = matrix.content[i][j];
        }
    }
}

void Matrix::randomPopulate() {
    // TODO fix randomness
    srand((unsigned int)(time(nullptr))); // Random seed

    for(int row = 0; row < n; ++row)
        for(int col = 0; col < m; ++col)
            content[row][col] = (int) (rand() / (RAND_MAX + 1.0) * modulus); // Random number [0;modulus[
}

void Matrix::testModulus(int mod) const {
    if(mod <= 0) {
        throw invalid_argument(
                "We cannot have a modulus of 0 because the matrix values must be between 0 and modulus - 1");
    }
}

void Matrix::testMatrixDimensions(int n, int m) const {
    if(n <= 0 || m <= 0)
        throw invalid_argument("Matrix dimension cannot be void or negative");
}

int Matrix::trueModulus(int lhs, int rhs) const {
    if(rhs < 0)
        throw runtime_error("Cannot operate with negative rhs modulus.");
    return (lhs % rhs + rhs) % rhs;
}

Matrix& Matrix::calc(const Matrix& other, const Operator& op) {
    if(this->modulus != other.modulus)
        throw invalid_argument("Both matrix must have same modulus");

    int maxN = max(this->n, other.n);
    int maxM = max(this->m, other.m);

    Matrix result(maxN, maxM, this->modulus);

    // Do the arithmetic operation component by component
    for(int row = 0; row < maxN; ++row) {
        for(int col = 0; col < maxM; ++col) {
            // Complete with 0 value if one of the matrices doesn't have the same dimensions
            int op1 = row >= this->n || col >= this->m ? 0 : this->content[row][col];
            int op2 = row >= other.n || col >= other.m ? 0 : other.content[row][col];

            int operationResult = op.calculate(op1, op2);

            result.content[row][col] = trueModulus(operationResult, result.modulus);
        }
    }

    swap(*this, result); // Actually modify current matrix
    return *this;
}

Matrix Matrix::addCopy(const Matrix& other) const {
    Addition op;
    Matrix result(*this);
    result.calc(other, op);
    return result;
}

Matrix Matrix::subCopy(const Matrix& other) const {
    Subtraction op;
    Matrix result(*this);
    result.calc(other, op);
    return result;
}

Matrix Matrix::multiplyCopy(const Matrix& other) const {
    Multiply op;
    Matrix result(*this);
    result.calc(other, op);
    return result;
}

Matrix* Matrix::addDynamic(const Matrix& other) const {
    Addition op;
    Matrix* result = new Matrix(*this);
    result->calc(other, op);
    return result;
}

Matrix* Matrix::subDynamic(const Matrix& other) const {
    Subtraction op;
    Matrix* result = new Matrix(*this);
    result->calc(other, op);
    return nullptr;
}

Matrix* Matrix::multiplyDynamic(const Matrix& other) const {
    Multiply op;
    Matrix* result = new Matrix(*this);
    result->calc(other, op);
    return nullptr;
}

Matrix& Matrix::addModify(const Matrix& other) {
    Addition op;
    calc(other, op);
    return *this;
}

Matrix& Matrix::subModify(const Matrix& other) {
    Subtraction op;
    calc(other, op);
    return *this;
}

Matrix& Matrix::multiplyModify(const Matrix& other) {
    Multiply op;
    calc(other, op);
    return *this;
}

Matrix& Matrix::operator=(const Matrix& matrix) {
    // Both object must be different to do the copy
    if(this != &matrix) {
        // Variables copy
        n = matrix.n;
        m = matrix.m;
        modulus = matrix.modulus;

        // Initialize new content array and copy same values as the cpy matrix content
        content = new int* [n];
        for(int i = 0; i < n; ++i) {
            content[i] = new int[m];
            for(int j = 0; j < m; j++) {
                content[i][j] = matrix.content[i][j];
            }
        }
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for(int i = 0; i < m.n; ++i) {
        for(int j = 0; j < m.m; ++j) {
            os << m.content[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matrix::~Matrix() {
    for(int i = 0; i < n; ++i) {
        delete[] content[i];
    }
    delete[] content;
}