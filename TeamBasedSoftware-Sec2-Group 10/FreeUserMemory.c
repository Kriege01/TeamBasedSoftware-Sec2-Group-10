#include "UserAuthentication.h"

void freeUserMemory(User* user) {
    if (user != NULL) {
        free(user->username);
        free(user->password);
        free(user);
    }
}
