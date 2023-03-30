#include "CustomerSupport.h"

// Function to view the details of a support ticket
void viewTicketDetails(int ticketID) {
    struct ticket ticket = tickets[ticketID - 1];
    printf("Ticket ID: %d\n", ticket.ticketID);
    printf("Customer Name: %s\n", ticket.name);
    printf("Contact Information: %s\n", ticket.contactInfo);
    printf("Issue Description: %s\n", ticket.description);
    printf("Date/Time Created: %s\n", ticket.dateTime);
    printf("Status: %s\n", ticket.status);
}