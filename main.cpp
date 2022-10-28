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

int read() {
    return 0;
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


int main() {
    string option;
    cout << "what do you want to do: ";
    getline(cin, option);
    // vector<string> command;
    // if (option.find("-")) {
    //     command = parseInput(option);
    // } else {
    //     command.push_back(option);
    // }
    // for(int i = 0; i < command.size(); i++) {
    //     cout << command[i] << endl;
    // }

    if (option == "edit") {
        edit();
    } else if (option == "rmf") {
        rmf();
    } else if (option == "rmd")
    {
        rmd();
    }
}