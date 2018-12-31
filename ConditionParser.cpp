//
// Created by dvir on 12/15/18.
//

#include "ConditionParser.h"

#define WHILE_CONDITION "while"

/*
ConditionParser::ConditionParser(CommandDataBase &db) {
    this->db = db;
    this->parser = new Parser(db);

}
*/

// check if booleanExpression is equal to true or false.
double ConditionParser::checkBoolExpression() {
    // TODO dinamic allocation, to delete.
    ExpressionFactory factory = ExpressionFactory();
    Expression *leftExpr = factory.create(this->leftExpression);
    Expression *rightExpr = factory.create(this->rightExpression);
    Expression *boolExpression = new BoolExpression(leftExpr, this->boolOperator, rightExpr);
    double result = boolExpression->calculate();
    //delete leftExpr;
    //delete rightExpr;
    //delete boolExpression;
    return result;

}
/*
void ConditionParser::execute(list<string>::iterator &it) {
    ExpressionReader er = ExpressionReader();
    string condition = *it;
    it++;
    this->leftExpression = er.getExpression(it);
    this->boolOperator = *it;
    it++;
    this->rightExpression = er.getExpression(it);
    if(*it != "{")
        throw runtime_error("invalid Syntax");
    it++;
    list<string> commandsList;
    while(*it != "}"){
        commandsList.push_back(*it);
        it++;
    }
    this->commandList = commandsList;

}

 */