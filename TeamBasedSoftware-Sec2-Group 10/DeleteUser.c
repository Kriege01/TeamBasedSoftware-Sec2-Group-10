#include "UserAuthentication.h"

int deleteUser(char* username) {
    for (int i = 0; i < num_users; i++) {
        User user = users[i];
        if (strcmp(user.username, username) == 0) {
            for (int j = i; j < num_users - 1; j++) {
                users[j] = users[j + 1];
            }
            num_users--;
            return 1;
        }
    }

    return 0;
}