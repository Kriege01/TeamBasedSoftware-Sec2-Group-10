#include "UserAuthentication.h"

void readUsersFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    numUsers = 0;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    while (fscanf(fp, "%s %s", username, password) != EOF) {
        if (numUsers >= MAX_USERS) {
            fprintf(stderr, "Too many users\n");
            exit(1);
        }
        strncpy(users[numUsers].username, username, sizeof(users[numUsers].username));
        strncpy(users[numUsers].password, password, sizeof(users[numUsers].password));
        numUsers++;
    }
    fclose(fp);
}