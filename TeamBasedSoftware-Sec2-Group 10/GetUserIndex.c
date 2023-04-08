#include "UserAuthentication.h"

int getUserIndex(char* username) {
	for (int i = 0; i < numUsers; i++) {
		if (strcmp(users[i].username, username) == 0) {
			return i;
		}
	}
	return -1;
}