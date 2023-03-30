#include "UserAuthentication.h"

User** readUsersFromFile(char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        return NULL;
    }

    User** users = malloc(MAX_USERS * sizeof(User*));
    if (users == NULL) {
        return NULL;
    }

    // Initialize the users array
    for (int i = 0; i < MAX_USERS; i++) {
        users[i] = NULL;
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL && i < MAX_USERS) {
        char* username = strtok(line, ",");
        char* password = strtok(NULL, ",");
        if (username == NULL || password == NULL) {
            continue;
        }

        User* user = malloc(sizeof(User));
        if (user == NULL) {
            continue;
        }

        strcpy(user->username, username);
        strcpy(user->password, password);

        users[i++] = user;
    }

    num_users = i; // Update the number of users read from the file

    fclose(file);
    return users;
}
