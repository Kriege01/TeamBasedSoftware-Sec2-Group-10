#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

static User users[MAX_USERS];
static int num_users = 0;

int registerUser(char* username, char* password);
int loginUser(char* username, char* password);
int checkUserExists(char* username);
int updateUserPassword(char* username, char* newPassword);
int deleteUser(char* username);
User** readUsersFromFile(char* filepath);
int writeUsersToFile(char* filepath, User** users);
void freeUserMemory(char** users, int numUsers);

