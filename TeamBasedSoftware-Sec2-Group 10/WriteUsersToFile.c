#include "UserAuthentication.h"

int writeUsersToFile(char* filepath, User** users) {
    FILE* file = fopen(filepath, "w");
    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < MAX_USERS; i++) {
        User* user = users[i];
        if (user != NULL) {
            fprintf(file, "%s,%s\n", user->username, user->password);
        }
    }

    fclose(file);
    return 1;
}