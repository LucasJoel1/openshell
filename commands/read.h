#include "../libraries.h"

int read() {
    string path = "./hello.txt";
    int fd = open(path.c_str(), O_RDONLY);
    char buffer[64];
    read(fd, buffer, sizeof(buffer));
    cout << buffer;
    return 0;
}