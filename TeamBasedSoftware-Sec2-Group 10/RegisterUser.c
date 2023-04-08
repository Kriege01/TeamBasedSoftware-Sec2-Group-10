#include "UserAuthentication.h"


int registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a username: ");
    scanf("%s", username);
    printf("Enter a password: ");
    scanf("%s", password);
    if (checkUserExists(username)) {
        printf("Username %s already exists. Please choose a different username.\n", username);
        return 0;
    }
    if (numUsers >= MAX_USERS) {
        printf("Too many users. Please try again later.\n");
        return 0;
    }
    strncpy(users[numUsers].username, username, sizeof(users[numUsers].username));
    strncpy(users[numUsers].password, password, sizeof(users[numUsers].password));
    numUsers++;
    writeUsersToFile("users.txt");
    printf("User %s registered successfully.\n", username);
    return 1;
}










