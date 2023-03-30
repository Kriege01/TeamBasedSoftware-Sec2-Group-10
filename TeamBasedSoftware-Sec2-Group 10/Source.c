#include "UserAuthentication.h"

int main() {
    // Register a new user
    int result = registerUser("username", "password");
    if (result) {
        printf("User registered successfully\n");
    }
    else {
        printf("Failed to register user\n");
    }

    // Login with the registered user
    result = loginUser("username", "password");
    if (result) {
        printf("User logged in successfully\n");
    }
    else {
        printf("Failed to login user\n");
    }

    // Update the user's password
    result = updateUserPassword("username", "newpassword");
    if (result) {
        printf("User password updated successfully\n");
    }
    else {
        printf("Failed to update user password\n");
    }

    // Delete the user
    result = deleteUser("username");
    if (result) {
        printf("User deleted successfully\n");
    }
    else {
        printf("Failed to delete user\n");
    }

    // Read users from file
    User** users = readUsersFromFile("users.txt");
    if (users == NULL) {
        printf("Failed to read users from file\n");
    }
    else {
        printf("Read users from file successfully\n");
        // Use the users here
        // ...

        // Free memory allocated by readUsersFromFile function
        freeUserMemory((char**)users, MAX_USERS);
    }

    // Write users to file
    User user1 = { "username1", "password1" };
    User user2 = { "username2", "password2" };
    User* users_to_write[MAX_USERS] = { &user1, &user2, NULL };
    result = writeUsersToFile("users.txt", users_to_write);
    if (result) {
        printf("Users written to file successfully\n");
    }
    else {
        printf("Failed to write users to file\n");
    }

    return 0;
}

