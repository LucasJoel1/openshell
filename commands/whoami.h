#include "../libraries.h"

string whoami() {
    string env_user = "user";
    try {
        env_user = getenv("USER");
    } catch (const std::exception &e) {
        env_user = getenv("LOGNAME");
    }
    return env_user;
}

int whoami_int() {
    cout << whoami() << endl;
    return 0;
}