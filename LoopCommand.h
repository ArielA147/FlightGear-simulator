//
// Created by dvir on 12/17/18.
//

#ifndef PROJECT_LOOPCOMMAND_H
#define PROJECT_LOOPCOMMAND_H


#include "ConditionParser.h"

class LoopCommand : public ConditionParser {
public:
    LoopCommand(Parser* parser);
    void execute(list<string>::iterator &it);

};


#endif //PROJECT_LOOPCOMMAND_H
