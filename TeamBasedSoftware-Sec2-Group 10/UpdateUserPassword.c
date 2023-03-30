#include "UserAuthentication.h"

int updateUserPassword(char* username, char* newPassword) {
    for (int i = 0; i < num_users; i++) {
        User* user = &users[i];
        if (strcmp(user->username, username) == 0) {
            strcpy(user->password, newPassword);
            return 1;
        }
    }

    return 0;
}