#include "commands.h"
#include "libraries.h"

using commands_Functions = int (*)();


int main() {
    bool commandFound = false;
    map<string, commands_Functions> commands_map;
    commands_map["bash"] = bash;
    commands_map["clear"] = clear;
    commands_map["insert"] = insert;
    commands_map["mk"] = mk;
    commands_map["mkdir"] = mkdir;
    commands_map["read"] = read;
    commands_map["rm"] = rm;
    commands_map["rmdir"] = rmdir;
    commands_map["systemname"] = systemname_int;
    commands_map["whoami"] = whoami_int;


    clear();
    string option;
    while(option != "exit") {
        cout << "[" << whoami() << "@" << systemname() << "]: ";
        getline(cin, option);
        for (auto &command : commands_map) {
            if (option == command.first) {
                command.second();
                commandFound = true;
                break;
            }
        }
        if(option == "exit") break;
        if(commandFound == false) execute(option);
        commandFound = false;
    }
    return 0;
}