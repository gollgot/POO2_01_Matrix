/*
 * File     : Addition.hpp
 * Authors  : Robin Demarta, Loïc Dessaules
 * Date     : 21.02.2020
 */

#ifndef POO2_LABO01_ADDITION_HPP
#define POO2_LABO01_ADDITION_HPP

#include "Operator.hpp"

class Addition : public Operator {
    int calculate(int op1, int op2) const override {
        return op1 + op2;
    }
};

#endif //POO2_LABO01_ADDITION_HPP
