#include "UserAuthentication.h"

void freeUserMemory(char** users, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(users[i]);
    }
    free(users);
}