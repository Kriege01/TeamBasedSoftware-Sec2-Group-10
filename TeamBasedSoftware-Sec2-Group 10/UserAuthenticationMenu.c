#include "UserAuthentication.h"

int main() {
readUsersFromFile("users.txt");
int choice = 0;
while (choice != 6) {
	printf("Select an option:\n");
	printf("1. Register user\n");
	printf("2. Delete user\n");
	printf("3. Login\n");
	printf("4. Update password\n");
	printf("5. Display registered users\n");
	printf("6. Quit\n");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		registerUser();
		break;
	case 2:
		deleteUser();
		break;
	case 3:
		loginUser();
		break;
	case 4:
		updateUserPassword();
		break;
	case 5:
		displayUsers();
		break;
	case 6:
		printf("Goodbye!\n");
		break;
	default:
		printf("Invalid choice. Please try again.\n");
	}
}
return 0;
}



