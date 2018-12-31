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
       // pthread_mutex_t* mutex = MutexClass::getInstance()->getMutex();
       // pthread_mutex_lock(mutex);
        this->pathTable[key] = value;
       // pthread_mutex_unlock(mutex);
    }
    inline string getValue(const string &key){
        //pthread_mutex_t* mutex = MutexClass::getInstance()->getMutex();
        //pthread_mutex_lock(mutex);
        if(this->pathTable.count(key) ==  1){
            string s = this->pathTable[key];
          //  pthread_mutex_unlock(mutex);
            return s;
        }
        else{
//            pthread_mutex_unlock(mutex);
            return "";
        }
    }

    ~BindTable(){
        delete  map_instance;
    }

};


#endif //PROJECT_BINDTABLE_H
