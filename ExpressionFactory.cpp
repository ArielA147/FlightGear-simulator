//
// Created by dvir on 12/13/18.
//

#include "ExpressionFactory.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Div.h"
#include "Mult.h"

enum priority {
    SPACIAL,SECOND, FIRST
};

/*
ExpressionFactory::ExpressionFactory(CommandDataBase &db) {
    this->db = db;
}*/

bool isNum(string &token) {
    bool checkNegative = 0;
    bool showDot = 0;
    for (int i = 0; i < token.length(); i++) {
        if (!checkNegative){
            checkNegative = 1;
            if(token[i] == '-' && token.length() > 1)
                continue;
       }
        if (isdigit(token[i])) {
            continue;
        } else if (token[i] == '.' && !showDot) {
            showDot = true;
            continue;
        } else
            return false;
    }
    return true;
}

// convert postfix string to expression.
Expression *stringToExpression(list<string> tokens) {
    stack<Expression *> expressionStack;
    for (list<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
        if (isNum(*it))
            expressionStack.push(new Number(*it));
        else if(*it == "--"){
            if (expressionStack.empty())
                throw runtime_error("not enough arguments or invalid argument");
            Expression *e1 = expressionStack.top();
            expressionStack.pop();
            expressionStack.push(new Minus(new Number("0"), e1));
        }
        else {
            if (expressionStack.size() < 2)
                throw runtime_error("not enough arguments or invalid argument");
            Expression *e2 = expressionStack.top();
            expressionStack.pop();
            Expression *e1 = expressionStack.top();
            expressionStack.pop();

            if (*it == "+")
                expressionStack.push(new Plus(e1, e2));
            else if (*it == "-")
                expressionStack.push(new Minus(e1, e2));
            else if (*it == "/")
                expressionStack.push(new Div(e1, e2));
            else if (*it == "*")
                expressionStack.push(new Mult(e1, e2));
            else
                throw runtime_error("no such argument");
        }
    }
    Expression *expressionResult = expressionStack.top();
    expressionStack.pop();
    if (!expressionStack.empty())
        throw runtime_error("invalid pattern");
    return expressionResult;
}

Expression *shuntingYard(list<string> tokens) {
    // create fifo and s data structures.
    list<string> fifo;
    stack<string> s;
    map<string, int> op_priority;
    // set map with priority of operators.
    op_priority["+"] = SECOND;
    op_priority["-"] = SECOND;
    op_priority["*"] = FIRST;
    op_priority["/"] = FIRST;
    op_priority["("] = SPACIAL;
    // represent negative operator;
    op_priority["--"] = FIRST;

    string strBefore = tokens.begin().operator*();
    for (string &str : tokens) {
        // in case of first token, check if first operator is minus
        if(strBefore == str && str == "-"){
            s.push("--");
            continue;
        }
        // check if previous string was operator and this string is minus operator.
        else if(op_priority.count(strBefore) && str == "-"){
            strBefore = str;
            s.push("--");
            continue;
        }
        strBefore = str;
        // in case of digit, place into fifo.
        if (isNum(str))
            fifo.push_back(str);
        // in case of invalid operator, throw exaction.
        else if(!(op_priority.count(str)) && str != ")" )
            throw runtime_error("invalid operator");
        else if (str == ")") {
            while (s.top() != "(") {
                fifo.push_back(s.top());
                s.pop();
            }
            // pop out '(' operator.
            s.pop();
        } else {
            if (s.size() > 0) {
                // in case of high priority operator, insert him.
                if (op_priority[s.top()] >= op_priority[str] && str != "(") {
                    fifo.push_back(s.top());
                    s.pop();
                }
            }
            s.push(str);
        }
    }
    // while there is operators in stack, input them in fifo.
    while (!s.empty()) {
        fifo.push_back(s.top());
        s.pop();
    }
    Expression *result = stringToExpression(fifo);
    return result;
}

Expression *ExpressionFactory::create(list<string> tokens){
    list<string> strExpression;
    // for each token in tokens, search for var's value and replace.
    for(list<string>::iterator it = tokens.begin(); it!= tokens.end();it++){
        // in case variable is in data base.
        if(SymbolTable::instance()->getVarTable().count(*it) == 1){
            // get variable value.
            double argumentValue = SymbolTable::instance()->getValue(*it);
            strExpression.push_back(to_string(argumentValue));
            continue;
        }
        strExpression.push_back(*it);
    }
    Expression* expression = shuntingYard(strExpression);
    return expression;
}