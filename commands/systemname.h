#include "../libraries.h"

string systemname() {
    char hostname_c[1024];
    gethostname(hostname_c, 1024);
    return hostname_c;
}

int systemname_int() {
    cout << systemname() << endl;
    return 0;
}