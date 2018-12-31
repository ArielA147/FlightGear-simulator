//
// Created by dvir on 12/20/18.
//

#ifndef PROJECT_COMMANDFACTORY_H
#define PROJECT_COMMANDFACTORY_H


#include <string>
#include <iterator>
#include <list>
#include "CommandDataBase.h"

using namespace std;

class CommandFactory{
protected:
    CommandDataBase db;

public:
    virtual Command* update(list<string>::iterator &it) = 0;
};


#endif //PROJECT_COMMANDFACTORY_H
