//
// Created by ariel on 12/12/18.
// the class will be responsibe for the lexer in the prject .
// the lexer will create list of token from a given string.


#ifndef PROJECT_LEXER_H
#define PROJECT_LEXER_H

#include <string>
#include <list>
#include <regex>

using namespace std;

class Lexer {

private:
    // all the special sings
    list<string> specialSigns{"+", "<", ">", "==", "<=", ">=","/\"", "/", "(",
                              ")",
                              "*", "-", "=", "\"", ",", "{","}", "\t"};

public:

    /**
 * the function create list of tokens. tab will not be contain as a token .
 * brackets and mathematical operation will be saved in various tokens
 * @param s the current string line
 * @param delimiter the sign we want to split the string
 * @return list of strings of all the tokens
 */
    list<string> lexer(string &s, char delimiter);

    /**
     * the function will chage all the occurences of a substring to wanted
     * substring
     * @param subject the string we want to chage
     * @param search the substring we are looking for
     * @param replace the sub string we want to treplace
     * @return a string of the subject were all the occureses of search is
     * replaced with string replace
     */
    string replaceSubString(string subject, const string &search,
            const string &replace);


    /**
     * the function adds spasces before and after the special signs if its valid
     * @param s the string we want to update
     */
    void addSpaces(string &s);



    vector<string> baseSplit(string &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};


#endif //PROJECT_LEXER_H
