#include <iostream>
#include <filesystem>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>

using namespace std;

int edit() {
    unsigned char buffer[16];
    cout << "Enter Some Text";
    cin >> buffer;
    int fd = open("./hello.txt", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    return 0;
}

void rmf() {
    char file[] = "./lol.txt";
    remove(file);
}

void rmd() {
    remove("./test");
}

void mkf() {

}

void mkd() {

}

int main() {
    string option;
    cout << "what do you want to do: ";
    cin >> option;
    if (option == "edit") {
        edit();
    } else if (option == "rmf") {
        rmf();
    } else if (option == "rmd")
    {
        rmd();
    }
    
    
}