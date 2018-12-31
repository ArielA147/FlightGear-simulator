//
// Created by dvir on 12/13/18.
//

#include "Number.h"

Number::Number(string num){
    // convert string to double.
    this->num = atof(num.c_str());
}

double Number::calculate() {
    return this->num;
}