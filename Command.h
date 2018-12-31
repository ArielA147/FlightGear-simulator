//
// Created by dvir on 12/14/18.
//

#ifndef PROJECT_COMMAND_H
#define PROJECT_COMMAND_H

#include <list>
#include <string>

using namespace std;

// Command interface
class Command {
public:
    /**
     * the function execute the command.
     * @param it
     */
    virtual  void execute(list<string>::iterator &it) = 0;
    virtual ~Command(){}
};

#endif //PROJECT_COMMAND_H
