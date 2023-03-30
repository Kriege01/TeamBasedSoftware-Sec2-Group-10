#include "UserAuthentication.h"

int loginUser(char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        User user = users[i];
        if (strcmp(user.username, username) == 0 && strcmp(user.password, password) == 0) {
            return 1;
        }
    }

    return 0;
}