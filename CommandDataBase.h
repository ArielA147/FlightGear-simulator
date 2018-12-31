//
// Created by dvir on 12/14/18.
//

#ifndef PROJECT_COMMANDDATABASE_H
#define PROJECT_COMMANDDATABASE_H

#include <map>
#include <string>
#include <vector>
#include "Command.h"

using namespace std;


/*
 * class created in order to store var and their current values.
 */
class CommandDataBase {
    // db of the paths from the xml and their double values from the simulator
    map <string, double> xmlPathTable;

    map<string, double> symbolTable;
    map<string, string> pathTable;
    map<string, Command*> commandTable;

public:
/**
 * constractor for the db map tables
 */
    CommandDataBase();

    //todo :: if we have time - to change this function to reading from xml
    // file in dynamic and not creating this map in hard coded way like now
    /**
     * the function build in hard coded way the xml path of the simulator
     */
    void buildXmlMap();

    // get varTable.
    const map<string, double> &getVarTable() const;
    void updateVar(string varName, double value);
    double getValueFromTable(const string &varName);

    // getVarPath
    const map<string, string> &getPathTable() const;
    void updatePath(string varName, string path);
    string getPathFromTable(const string &varName);

    // getCommand
    const map<string, Command*> &getCommandTable() const;
    void addCommand(string varName, Command* command);
    Command* getCommand(const string &CommandName);
    vector<string> getXmlPathKeyByXmlOrder();
    void setXmlPathMap(string key , double value);
};

#endif //PROJECT_COMMANDDATABASE_H