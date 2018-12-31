#include <iostream>
#include <list>
#include "Lexer.h"

using namespace std;

int my_main() {
    string s1 = "openDataServer 5400";
    string s2 = "connect 127.0.0.1 5402";
    Lexer l;

/////////////////////////////////////////////////////////////////////////////////

    string s3 = "var breaks=bind \"/controls/flight/speedbrake\"";
    string s4 = "var throttle = bind \"/controls/engines/engine/throttle\"";
    string s5 = "var heading = bind \"/instrumentation/heading-indicator/offset-deg\"";
    string s6 ="var airspeed = bind \"/instrumentation/airspeed-indicator/indicated-speed-kt\"";
    string s7= "var roll = bind\"/instrumentation/attitude-indicator/indicated-roll-deg\"";
    string s8 = "var pitch = bind\"/instrumentation/attitude-indicator/internal-pitch-deg\"";
    string s9 ="var rudder = bind \"/controls/flight/rudder\"";
    string s10 ="var aileron = bind \"/controls/flight/aileron\"";
    string s11 ="var elevator = bind \"/controls/flight/elevator\"";
    string s12 ="var alt = bind \"/instrumentation/altimeter/indicated-altitude-ft\"";
    string s13 ="breaks = 0";
    string s14 ="throttle = 1";
    string s15 ="var h0 = heading";
    string s16 ="while alt < 1000+h0";
    string s17 ="{";
    string s18 ="    rudder = (h0 -heading)/20";
    string s19 ="    aileron = -roll / 70";
    string s20 ="    elevator = pitch / 50";
    string s21 ="    print alt";
    string s22 ="    sleep 250";
    string s23 ="}";
    string s24 ="print \"done\"";
    ////////////////////////////////////////////////////////////////

    list<string> tokens3 = l.lexer(s3, ' ');
    for (string &s:tokens3) {
        cout << s << endl;
    }
    cout << "done 3" << endl;
    cout << "----------------------------------------------" << endl;



    cout << "----------------------------------------------" << endl;

    list<string> tokens = l.lexer(s1, ' ');
    for (string &s:tokens) {
        cout << s << endl;
    }
    cout << "done 1" << endl;
    cout << "----------------------------------------------" << endl;
    list<string> tokens2 = l.lexer(s2, ' ');
    for (string &s:tokens2) {
        cout << s << endl;
    }
    cout << "done 2" << endl;

    cout << "----------------------------------------------" << endl;

    list<string> tokens14 = l.lexer(s14, ' ');
    for (string &s:tokens14) {
        cout << s << endl;
    }
    cout << "done 14" << endl;
    cout << "----------------------------------------------" << endl;

    list<string> tokens15 = l.lexer(s15, ' ');
    for (string &s:tokens15) {
        cout << s << endl;
    }
    cout << "done 15" << endl;
    cout << "----------------------------------------------" << endl;

    list<string> tokens16 = l.lexer(s16, ' ');
    for (string &s:tokens16) {
        cout << s << endl;
    }
    cout << "done 16" << endl;
    cout << "----------------------------------------------" << endl;

    list<string> tokens17 = l.lexer(s17, ' ');
    for (string &s:tokens17) {
        cout << s << endl;
    }
    cout << "done 17" << endl;
    cout << "----------------------------------------------" << endl;

    list<string> tokens18 = l.lexer(s18, ' ');
    for (string &s:tokens18) {
        cout << s << endl;
    }
    cout << "done 18" << endl;
    cout << "----------------------------------------------" << endl;

    list<string> tokens19 = l.lexer(s19, ' ');
    for (string &s:tokens19) {
        cout << s << endl;
    }
    cout << "done 19" << endl;
    cout << "----------------------------------------------" << endl;

    list<string> tokens20 = l.lexer(s20, ' ');
    for (string &s:tokens20) {
        cout << s << endl;
    }
    cout << "done 20" << endl;
    cout << "----------------------------------------------" << endl;

    list<string> tokens21 = l.lexer(s21, ' ');
    for (string &s:tokens21) {
        cout << s << endl;
    }
    cout << "done 21" << endl;
    cout << "----------------------------------------------" << endl;

    list<string> tokens22 = l.lexer(s22, ' ');
    for (string &s:tokens22) {
        cout << s << endl;
    }
    cout << "done 22" << endl;
    cout << "----------------------------------------------" << endl;
    list<string> tokens23 = l.lexer(s23, ' ');
    for (string &s:tokens23) {
        cout << s << endl;
    }
    cout << "done 23" << endl;
    cout << "----------------------------------------------" << endl;
    list<string> tokens24 = l.lexer(s24, ' ');
    for (string &s:tokens24) {
        cout << s << endl;
    }
    cout << "done 24" << endl;
    cout << "----------------------------------------------" << endl;

    return 0;
}