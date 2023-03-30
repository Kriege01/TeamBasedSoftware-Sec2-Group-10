#include "UserAuthentication.h"

int checkUserExists(char* username) {
    for (int i = 0; i < num_users; i++) {
        User user = users[i];
        if (strcmp(user.username, username) == 0) {
            return 1;
        }
    }

    return 0;
}