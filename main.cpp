#include <iostream>
#include <filesystem>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>
#include <vector>
#include <string>
// #include "commands.h"

using namespace std;

string getUserName() {
    string env_user = "user";
    try {
        env_user = getenv("USER");
    } catch (const std::exception &e) {
        env_user = getenv("LOGNAME");
    }
    return env_user;
}

string getMachineName() {
    char hostname_c[1024];
    gethostname(hostname_c, 1024);
    return hostname_c;
}

void edit() {
    unsigned char buffer[16];
    int sizeOfBuffer = 0;
    cout << "Enter Some Text: ";
    cin >> buffer;
    for (int i = 0; buffer[i] != 0; i++) {
        sizeOfBuffer++;
    }
    unsigned char temp[sizeOfBuffer];
    for (int i = 0; i < sizeOfBuffer; i++) {
        temp[i] = buffer[i];
    }
    int fd = open("./hello.txt", O_RDWR);
    read(fd, buffer, sizeof(temp));
    write(fd, temp, sizeof(temp));
    int fsync(int fd);
}

void bash() {
    system("mkdir test /home/workspaces/terminal");
}

string read(string path) {
    int fd = open(path.c_str(), O_RDONLY);
    char buffer[64];
    read(fd, buffer, sizeof(buffer));
    return buffer;
}

void rmf() {
    char file[] = "./hello.txt";
    unlink(file);
}

void rmd() {
    unlink("./test");
}

void mkf() {

}

void mkd() {

}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}


int main() {
    clearScreen();
    string option;
    while(option != "exit") {
        cout << "[" << getUserName() << "@" << getMachineName() << "]# ";
        getline(cin, option);

        if (option.find("bash")) {
            string command = option.substr(option.find(" ") + 1);
            // convert command into char
            char command_c[command.length() + 1];
            for (int i = 0; i < command.length(); i++) {
                command_c[i] = command[i];
            }
            command_c[command.length()] = '\0';
            system(command_c);
        }
        if (option == "edit") {
            edit();
        } else if (option == "rmf") {
            rmf();
        } else if (option == "rmd")
        {
            rmd();
        }
        else if (option == "clear") {
            clearScreen();
        }
    }
    return 0;
}