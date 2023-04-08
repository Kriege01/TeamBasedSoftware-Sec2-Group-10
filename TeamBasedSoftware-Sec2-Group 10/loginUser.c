#include "UserAuthentication.h"

int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    int userIndex = getUserIndex(username);
    if (userIndex == -1) {
        printf("User %s not found.\n", username);
        return 0;
    }
    if (strcmp(users[userIndex].password, password) != 0) {
        printf("Incorrect password for user %s.\n", username);
        return 0;
    }
    printf("User %s logged in successfully.\n", username);
    return 1;
}


