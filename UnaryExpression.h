//
// Created by dvir on 12/13/18.
//

#ifndef PROJECT_UNARYEXPRESSION_H
#define PROJECT_UNARYEXPRESSION_H


#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression *argument;
public:

    UnaryExpression(Expression *argument);

    Expression *getArgument();
    void setValue(Expression *argument);

};


#endif //PROJECT_UNARYEXPRESSION_H
