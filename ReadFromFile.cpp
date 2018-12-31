//
// Created by ariel on 12/22/18.
//

#include "ReadFromFile.h"

#define END_FILE_SIGN ("\\n")

ReadFromFile::ReadFromFile(const string &_fileName) : _fileName(_fileName) {}

//long ReadFromFile::countLines(string fileName) {
list<string> ReadFromFile::readFile() {
    ifstream instream;
    string cur_line;

    instream.open(this->_fileName, ios::in);
    if (instream.fail()) {
        return this->lines;
    }
    while (!instream.eof()) {
        getline(instream, cur_line);
        this->lines.push_back(cur_line);
    }
    instream.close();
//    this->lines.pop_back(); // the last cell is empty from data- we dont need it
    this->lines.push_back(END_FILE_SIGN); // sings we got to the end of the fil
    return this->lines;
}