#include "AppendCommand.h"
#include "LoopCommand.h"
#include "SymbolTable.h"
#include "IfCommand.h"
#include "Initializer.h"

SymbolTable* SymbolTable::map_instance = NULL;
BindTable*   BindTable::map_instance = NULL;

int main() {
//
//    CommandDataBase* db = new CommandDataBase();
//    SymbolTable::instance()->setValue("x",5);
//    list<string> g;
//
//    g.push_back("while");
//    g.push_back("x");
//    g.push_back("<");
//    g.push_back("40");
//    g.push_back("{");
//    g.push_back("while");
//    g.push_back("x");
//    g.push_back("<");
//    g.push_back("40");
//    g.push_back("{");
//    g.push_back("x");
//    g.push_back("=");
//    g.push_back("x");
//    g.push_back("+");
//    g.push_back("1");
//    g.push_back("}");
//    g.push_back("x");
//    g.push_back("=");
//    g.push_back("x");
//    g.push_back("+");
//    g.push_back("1");
//    g.push_back("}");
//    g.push_back("done");


//    list<string>::iterator it = g.begin();
    //ExpressionFactory exprFactory = ExpressionFactory(*db);
    //Expression* e = exprFactory.create(g);
    //Expression* e = exprFactory.create(g);
    //double a = e->calculate();
    //Expression* e2 = exprFactory.create(g);
    //double aa = e2->calculate();
    //int i = 20;

    //list<string>::iterator it = g.begin();

//    Command* appendCommand = new AppendCommand(*db);
 //   db->addCommand("updateVar",appendCommand);
  //  Command* loopCommand = new LoopCommand(db);
   // LoopCommand->execute(it);
   // double xx = SymbolTable::instance()->getValue("x");
   // int x = 50;

    Initializer init;
//    init.start("/home/ariel/CLionProjects/c_plus_plus/project/config.txt",' ');
    Client* client = new Client();
    ConnectCommand connect = ConnectCommand(*client);
    list<string> test = {"connect", "127.0.0.1", "5402", "\\n"};
    auto it = test.begin();
    connect.execute(it);
    client->sentMsg("hello there !");
    cin.ignore();
//cout<< "done inint";


    return 0;
}