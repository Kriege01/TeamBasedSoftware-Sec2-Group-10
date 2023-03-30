#include "CustomerSupport.h"

// Function: loadTickets
// Purpose: Load support ticket data from an ASCII text file into the ticketing system upon program startup.
// Parameters:
//     filename (char*): the filename and location of the file to load.
// Returns: None.
void loadTickets(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for reading\n", filename);
        return;
    }
    // Loop through all lines in the file and create tickets from them
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        char* id_str = strtok(line, ",");
        char* name = strtok(NULL, ",");
        char* contactInfo = strtok(NULL, ",");
        char* description = strtok(NULL, ",");
        char* dateTime = strtok(NULL, ",");
        int id = atoi(id_str);
        createTicket(name, contactInfo, description, dateTime, id);
    }
    fclose(fp);
}