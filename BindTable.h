//
// Created by dvir on 12/22/18.
//

#ifndef PROJECT_BINDTABLE_H
#define PROJECT_BINDTABLE_H


#include <string>
#include <map>

using namespace std;


class BindTable {
    map<string,string> pathTable;
    static BindTable *map_instance;
public:
    static inline BindTable *instance(){
        if(map_instance == nullptr){
            map_instance = new BindTable();
        }
        return map_instance;
    }
    inline const map<string, string> &getBIndTable() const{
        return this->pathTable;
    }
    inline void setValue(string key, string value){
        this->pathTable[key] = value;
    }
    inline string getValue(const string &key){
        if(this->pathTable.count(key) ==  1)
            return this->pathTable[key];
        else
            return "";

    }


};


#endif //PROJECT_BINDTABLE_H
