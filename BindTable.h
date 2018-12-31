//
// Created by dvir on 12/22/18.
//

#ifndef PROJECT_BINDTABLE_H
#define PROJECT_BINDTABLE_H


#include <string>
#include <map>
#include <mutex>
#include "MutexClass.h"
using namespace std;

class BindTable {

    static BindTable *map_instance;
    // map of the path <var name, path var in simulator>
    map<string,string> pathTable;

public:
/**
 * creating instance of the bind table
 * @return
 */
    static inline BindTable *instance(){
        if(map_instance == nullptr){
            map_instance = new BindTable();
        }
        return map_instance;
    }
/**
 *
 * @return map of the bind table
 */
    inline const map<string, string> &getBIndTable() const{
        return this->pathTable;
    }
/**
 * returning the value by key
 * @param key  the var name
 * @param value the path of the var
 */
    inline void setValue(string key, string value){
        this->pathTable[key] = value;
    }
/**
 *
 * @param key the var name
 * @return path of the var
 */
    inline string getValue(const string &key){
        if(this->pathTable.count(key) ==  1){
            string s = this->pathTable[key];
            return s;
        }
        else{
            return "";
        }
    }

    ~BindTable(){
        delete  map_instance;
    }

};


#endif //PROJECT_BINDTABLE_H
