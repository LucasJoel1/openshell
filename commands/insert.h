#include "../libraries.h"

int insert() {
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