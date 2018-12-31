//
// Created by dvir on 12/18/18.
//

#ifndef PROJECT_IFCOMMAND_H
#define PROJECT_IFCOMMAND_H


#include "ConditionParser.h"

class IfCommand : public ConditionParser{
public:
    IfCommand(Parser* parser);
    void execute(list<string>::iterator &it);

};


#endif //PROJECT_IFCOMMAND_H
