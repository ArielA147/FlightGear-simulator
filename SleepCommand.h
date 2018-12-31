//
// Created by dvir on 12/24/18.
//

#ifndef PROJECT_SLEEPCOMMAND_H
#define PROJECT_SLEEPCOMMAND_H


#include "Command.h"
#include "ExpressionReader.h"
#include "ExpressionFactory.h"

class SleepCommand : public Command{

public:
    /**
     * executing the sleeping command
     * @param it
     */
    void execute(list<string>::iterator &it);
};


#endif //PROJECT_SLEEPCOMMAND_H
