#include "UserAuthentication.h"

void displayUsers() {
	printf("List of registered users:\n");
	for (int i = 0; i < numUsers; i++) {
		printf("%s\n", users[i].username);
	}
}