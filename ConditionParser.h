//
// Created by dvir on 12/15/18.
//

#ifndef PROJECT_CONDITIONPARSER_H
#define PROJECT_CONDITIONPARSER_H

#include "Command.h"
#include "CommandDataBase.h"
#include "ExpressionFactory.h"
#include "BoolExpression.h"
#include "ExpressionReader.h"
#include "Parser.h"

/*
 * check for boolean condition, execute list of commends
 *
 */
class ConditionParser : public Command {
protected:
    CommandDataBase* db;
    list<string> leftExpression;
    list<string> rightExpression;
    string boolOperator;
    Parser* parser;

public:
    virtual void execute(list<string>::iterator &it) = 0;
    double checkBoolExpression();

};


#endif //PROJECT_CONDITIONPARSER_H
