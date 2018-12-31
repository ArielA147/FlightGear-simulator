//
// Created by dvir on 12/18/18.
//

#include "IfCommand.h"


IfCommand::IfCommand(Parser* parser) {
    this->parser = parser;
}

void IfCommand::execute(list<string>::iterator &it) {
    int counter = 0;
    // skip "while" token.
    it++;
    ExpressionReader er = ExpressionReader();
    this->leftExpression = er.getExpression(it);
    this->boolOperator = *it;
    it++;
    this->rightExpression = er.getExpression(it);
    if (*it != "{")
        throw runtime_error("invalid Syntax");
    // skip "{" token.
    it++;
    list<string> commandsList;
    while (*it != "}") {
        commandsList.push_back(*it);
        it++;
    }
    if (IfCommand::checkBoolExpression() == 1) {
        this->parser->run(commandsList);
    }
}
