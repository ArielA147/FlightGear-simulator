//
// Created by dvir on 12/20/18.
//

#ifndef PROJECT_APPENDFACTORY_H
#define PROJECT_APPENDFACTORY_H


#include "CommandFactory.h"
#include "AppendCommand.h"

class AppendFactory : public CommandFactory{
    AppendCommand* appendCommand;

public:
    AppendFactory(CommandDataBase &db);
    Command* update(list<string>::iterator &it);


};


#endif //PROJECT_APPENDFACTORY_H
