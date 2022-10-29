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

using namespace std;




int edit() {
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
    return 0;
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

// vector<string> parseInput(string input) {
//     vector<string> result;
//     string command;
//     string temp;
//     command = input.substr(0, input.find("-"));
//     vector<string> parameters;
//     for (int i = 1; i < input.length(); i++) {
//         if (input[i] == '-') {
//             for (int j = i + 1; 1 != 2; i++) {
//                 if (!input[j] == '-') {
//                     temp = temp + input[j];
//                 } else {
//                     parameters.push_back(temp);
//                     temp.clear();
//                     break;
//                 }
//             }
//     }
//     return result;
// }

string getUserName() {
    string env_user = getenv("USER");
    return env_user;
}

string getMachineName() {
    string env_machine = getenv("HOSTNAME");
    return env_machine;
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}


int main() {
    clearScreen();
    string option;
    while(option != "exit") {
        cout << "{" << getUserName() << "@" << getMachineName() << "}: ";
        getline(cin, option);
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
}