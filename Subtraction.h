/*
 * File     : Subtraction.h
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 21.02.2020
 */

#ifndef POO2_LABO01_SUBTRACTION_H
#define POO2_LABO01_SUBTRACTION_H

#include "Operator.h"

class Subtraction : public Operator {
    int calculate(int op1, int op2) override {
        return op1 - op2;
    }
};


#endif //POO2_LABO01_SUBTRACTION_H
