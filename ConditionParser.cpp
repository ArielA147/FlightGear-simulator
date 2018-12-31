//
// Created by dvir on 12/15/18.
//

#include "ConditionParser.h"

// check if booleanExpression is equal to true or false.
double ConditionParser::checkBoolExpression(list<string> leftExpression, string boolOperator,
        list<string> rightExpression) {
    ExpressionFactory factory = ExpressionFactory();
    Expression *leftExpr = factory.create(leftExpression);
    Expression *rightExpr = factory.create(rightExpression);
    Expression *boolExpression = new BoolExpression(leftExpr, boolOperator, rightExpr);
    double result = boolExpression->calculate();
    delete boolExpression;
    return result;

}
