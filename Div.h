

#ifndef PROJECT_DIV_H
#define PROJECT_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    Div(Expression* leftValue, Expression* rightValue);
    double calculate();
};


#endif //PROJECT_DIV_H
