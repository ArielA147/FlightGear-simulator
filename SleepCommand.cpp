//
// Created by dvir on 12/24/18.
//

#include <unistd.h>
#include <thread>
#include "SleepCommand.h"


void SleepCommand::execute(list<string>::iterator &it) {
    ExpressionReader er = ExpressionReader();
    ExpressionFactory factory = ExpressionFactory();
    // skip sleep token.
    it++;
    list<string> sleepTimeStr = er.getExpression(it);
    Expression *e1 = factory.create(sleepTimeStr);
    double sleepTime =  e1->calculate();
    this_thread::sleep_for(std::chrono::microseconds((int) (sleepTime)));
    delete e1;
}