#include "UserAuthentication.h"

int registerUser(char* username, char* password) {
    if (num_users >= MAX_USERS) {
        return 0;
    }

    if (checkUserExists(username)) {
        return 0;
    }

    User user;
    strcpy(user.username, username);
    strcpy(user.password, password);
    users[num_users++] = user;

    return 1;
}











