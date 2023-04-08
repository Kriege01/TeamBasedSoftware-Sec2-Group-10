#include "UserAuthentication.h"


int deleteUser() {
    char username[MAX_USERNAME_LENGTH];
    printf("Enter the username of the user you want to delete: ");
    scanf("%s", username);
    int userIndex = getUserIndex(username);
    if (userIndex == -1) {
        printf("User %s not found.\n", username);
        return 0;
    }
    for (int i = userIndex; i < numUsers - 1; i++) {
        users[i] = users[i + 1];
    }
    numUsers--;
    writeUsersToFile("users.txt");
    printf("User %s deleted successfully.\n", username);
    return 1;
}
