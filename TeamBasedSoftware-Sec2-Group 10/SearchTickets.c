#include "CustomerSupport.h"

// Function to search for support tickets
void searchTickets(char* searchCriteria) {
    printf("Search Results:\n");
    printf("----------------\n");
    for (int i = 0; i < ticketIDCounter; i++) {
        struct ticket ticket = tickets[i];
        if (strstr(ticket.name, searchCriteria) != NULL || strstr(ticket.status, searchCriteria) != NULL || strstr(ticket.dateTime, searchCriteria) != NULL) {
            printf("Ticket ID: %d\n", ticket.ticketID);
            printf("Customer Name: %s\n", ticket.name);
            printf("Contact Information: %s\n", ticket.contactInfo);
            printf("Issue Description: %s\n", ticket.description);
            printf("Date/Time Created: %s\n", ticket.dateTime);
            printf("Status: %s\n", ticket.status);
            printf("\n");
        }
    }
}