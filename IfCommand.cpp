//
// Created by dvir on 12/18/18.
//

#include "IfCommand.h"

#define END_OF_FILE "\\n"

IfCommand::IfCommand(Parser* parser) {
    this->parser = parser;
}

void IfCommand::execute(list<string>::iterator &it) {
    int counter = 0;
    // skip "while" token.
    it++;
    ExpressionReader er = ExpressionReader();
    list<string> leftExpression = er.getExpression(it);
    string boolOperator = *it;
    it++;
    list<string> rightExpression = er.getExpression(it);
    if (*it != "{")
        throw runtime_error("invalid Syntax in if command");
    // skip "{" token.
    it++;
    list<string> commandsList;
    int brakes = 0;
    while(!(*it == "}" && brakes == 0)){
        if (*it == "{")
            brakes++;
        if (*it == "}")
            brakes--;
        commandsList.push_back(*it);
        if(*it != END_OF_FILE)
            it++;
    }
    commandsList.push_back(END_OF_FILE);

    if (IfCommand::checkBoolExpression(leftExpression,boolOperator,rightExpression) == 1) {
        this->parser->run(commandsList);
    }

    if(*it != END_OF_FILE)
        it++;
}
