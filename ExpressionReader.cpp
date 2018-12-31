

#include "ExpressionReader.h"

#define DIV_OP "/"
#define MULT_OP "*"
#define PLUS_OP "+"
#define MINUS_OP "-"

bool isOperator(const list<string>::iterator &it){
    if(*it == DIV_OP || *it == MULT_OP || *it == PLUS_OP || *it == MINUS_OP)
        return true;
    return false;
}

list<string> ExpressionReader::getExpression(list<string>::iterator &it) {
    bool endOfExpression = false;
    int argumentsLeft = 1;
    list<string> expression;
    while (!endOfExpression) {
        if (isOperator(it)) {
            expression.push_back(*it);
            argumentsLeft = 1;

        } else if (argumentsLeft) {
            if(*it == "("){
                while (*it != ")"){
                    expression.push_back(*it);
                    it++;
                }
                continue;
            }
            expression.push_back(*it);
            argumentsLeft--;

        } else {
            endOfExpression = true;
            continue;
        }
        it++;
    }
    return expression;
}

