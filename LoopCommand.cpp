//
// Created by dvir on 12/17/18.
//

#include "LoopCommand.h"

LoopCommand::LoopCommand(Parser* parser){
    this->parser = parser;

}

void LoopCommand::execute(list<string>::iterator &it) {
    // skip "while" token.
    it++;
    ExpressionReader er = ExpressionReader();
    this->leftExpression = er.getExpression(it);
    this->boolOperator = *it;
    it++;
    this->rightExpression = er.getExpression(it);
    if(*it != "{")
        throw runtime_error("invalid Syntax");
    // skip "{" token.
    it++;
    list<string> commandsList;
    while(*it != "}"){
        commandsList.push_back(*it);
        it++;
    }
    commandsList.push_back("\\n");
    while (LoopCommand::checkBoolExpression() == 1){
           this->parser->run(commandsList);
    }
    if(*it != "\\n")
        it++;
}

