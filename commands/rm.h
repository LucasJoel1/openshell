#include "../libraries.h"

int rm() {
    char file[] = "./hello.txt";
    unlink(file);
    return 0;
}