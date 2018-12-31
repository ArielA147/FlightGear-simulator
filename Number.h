//
// Created by dvir on 12/13/18.
//

#ifndef PROJECT_NUMBER_H
#define PROJECT_NUMBER_H


#include "Expression.h"

class Number : public Expression{
    double num;
public:
    Number(string num);
/**
 * calculating the number
 * @return double number
 */
    double calculate();

};


#endif //PROJECT_NUMBER_H
