#include "CustomerSupport.h"

// Function: saveTickets
// Purpose: Save all support ticket data to an ASCII text file for backup and future reference.
// Parameters:
//     filename (char*): the filename and location to save the file.
// Returns: None.
void saveTickets(char* filename) {
    FILE* fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", filename);
        return;
    }
    // Loop through all tickets and save them to the file
    for (int i = 0; i < ticketIDCounter; i++) {
        fprintf(fp, "%d,%s,%s,%s,%s\n", tickets[i].ticketID, tickets[i].name, tickets[i].contactInfo, tickets[i].description, tickets[i].dateTime);
    }
    fclose(fp);
}