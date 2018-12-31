#include "AppendCommand.h"
#include "LoopCommand.h"
#include "SymbolTable.h"
#include "IfCommand.h"
#include "Initializer.h"
#include "BindValueTable.h"

SymbolTable *SymbolTable::map_instance = NULL;
BindTable *BindTable::map_instance = NULL;
BindValueTable *BindValueTable::map_instance = NULL;

void check_connection() {
//     this is test to heck if the connetcion withas client is good
    Client *client = new Client();
    ConnectCommand connect = ConnectCommand(*client);
    list<string> test = {"connect", "127.0.0.1", "5402", "\\n"};
    auto it = test.begin();
    connect.execute(it);
    client->sentMsg("hello there !");
    cin.ignore();
    cout << "done inint";
}


int main(int argc, char* argv[]) {

    if(argc == 1){
        throw "no file provided";
    }
    else if(argc == 2){
        Initializer init;
        init.start(argv[1], ' ');

    }
    else {
        throw "to many arguments";
    }
    return 0;

}