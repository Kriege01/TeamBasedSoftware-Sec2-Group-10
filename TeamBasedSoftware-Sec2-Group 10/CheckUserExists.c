#include "UserAuthentication.h"

int checkUserExists(char* username) {
	for (int i = 0; i < numUsers; i++) {
		if (strcmp(users[i].username, username) == 0) {
			return 1;
		}
	}
	return 0;
}
