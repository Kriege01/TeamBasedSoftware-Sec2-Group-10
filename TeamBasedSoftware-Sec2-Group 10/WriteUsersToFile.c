#include "UserAuthentication.h"

void writeUsersToFile(char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < numUsers; i++) {
        fprintf(fp, "%s %s\n", users[i].username, users[i].password);
    }
    fclose(fp);
}