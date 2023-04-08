#include "UserAuthentication.h"

int updateUserPassword() {
	char username[MAX_USERNAME_LENGTH];
	char oldPassword[MAX_PASSWORD_LENGTH];
	char newPassword[MAX_PASSWORD_LENGTH];
	printf("Enter your username: ");
	scanf("%s", username);
	printf("Enter your old password: ");
	scanf("%s", oldPassword);
	int userIndex = getUserIndex(username);
	if (userIndex == -1) {
		printf("User %s not found.\n", username);
		return 0;
	}
	if (strcmp(users[userIndex].password, oldPassword) != 0) {
		printf("Incorrect password for user %s.\n", username);
		return 0;
	}
	printf("Enter your new password: ");
	scanf("%s", newPassword);
	strncpy(users[userIndex].password, newPassword, sizeof(users[userIndex].password));
	writeUsersToFile("users.txt");
	printf("Password for user %s updated successfully.\n", username);
	return 1;
}






