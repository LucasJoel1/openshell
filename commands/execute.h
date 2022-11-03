#include "../libraries.h"

int execute(string option) {
    int pid, status, data;
    if (pid = fork()) {
        waitpid(pid, &status, 0);
    } else {
        string executable = "/bin/" + option;
        char exec_char[executable.length() + 1];
        for(int i = 0; i < sizeof(exec_char); i++) {
            exec_char[i] = executable[i];
            int data = execl(exec_char, exec_char, NULL);
        }
    }
    return data;
}