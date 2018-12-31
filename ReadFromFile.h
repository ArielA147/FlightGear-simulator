//
// Created by ariel on 12/22/18.
//

#ifndef PROJECT_READFROMFILE_H
#define PROJECT_READFROMFILE_H

#include <string>
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * the class will read from fill and will
 */
class ReadFromFile {
private:
    // the file name we want to read from.
    // must be in the format of "file_name.txt"
    string _fileName;
    list<string> lines; // every lin in the file will be in a list cell

public:
    ReadFromFile(const string &_fileName);

    /**
 * the function read all the file and create list of strings where every cell
 * is a line in file
 * @return list of all lines in the file
 */
    list<string> readFile();
};


#endif //PROJECT_READFROMFILE_H
