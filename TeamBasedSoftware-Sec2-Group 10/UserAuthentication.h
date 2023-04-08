#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int numUsers;

void readUsersFromFile(char* filename);
void writeUsersToFile(char* filename);
int registerUser();
int deleteUser();
int loginUser();
int updateUserPassword();
int checkUserExists(char* username);
int getUserIndex(char* username);
void displayUsers();





