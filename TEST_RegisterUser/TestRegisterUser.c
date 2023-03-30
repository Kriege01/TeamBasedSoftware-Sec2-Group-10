#include "../TeamBasedSoftware-Sec2-Group 10/UserAuthentication.h"

void test_registerUser() {
    // Test adding a new user
    int result = registerUser("user1", "password1");
    assert(result == 1 && num_users == 1 && strcmp(users[0].username, "user1") == 0 && strcmp(users[0].password, "password1") == 0);

    // Test adding another new user
    result = registerUser("user2", "password2");
    assert(result == 1 && num_users == 2 && strcmp(users[1].username, "user2") == 0 && strcmp(users[1].password, "password2") == 0);

    // Test adding a duplicate user
    result = registerUser("user1", "password3");
    assert(result == 0 && num_users == 2);
}
