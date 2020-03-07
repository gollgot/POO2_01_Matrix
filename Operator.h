/*
 * File     : Operator.h
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 21.02.2020
 */

#ifndef POO2_LABO01_OPERATOR_H
#define POO2_LABO01_OPERATOR_H

class Operator {
public:
    virtual int calculate(int op1, int op2)  const = 0;
};

#endif //POO2_LABO01_OPERATOR_H
