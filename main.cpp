#include "commands.h"
#include "libraries.h"

using commands_Functions = int (*)();


int main() {
    bool commandFound = false;
    // defining the commands
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
    // main loop
    while(true) {
        // setting the prompt
        cout << "[" << whoami() << "@" << systemname() << "]: ";
        getline(cin, option);
        // checking if the user enters a command premade with the shell or is exit
        parse(option);

    //     if(option == "exit") break;
    //     for (auto &command : commands_map) {
    //         if (option == command.first) {
    //             command.second();
    //             commandFound = true;
    //             break;
    //         }
    //     }
    //     // if the command the user enters is not in the shell, it will check the /bin folder for an executable that corrosponds to the command
    //     if(commandFound == false) execute(option);
    //     commandFound = false;
    }

    return 0;
}