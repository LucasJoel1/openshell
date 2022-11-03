#include "../libraries.h"

int clear() {
    cout << "\033[2J\033[1;1H";
    return 0;
}