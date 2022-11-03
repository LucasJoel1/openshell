#include "../libraries.h"

int rmdir() {
    unlink("./test");
    return 0;
}