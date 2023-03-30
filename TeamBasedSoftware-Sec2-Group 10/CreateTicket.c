#include "CustomerSupport.h"

// Function to create a new support ticket
int createTicket(char* name, char* contactInfo, char* description, char* dateTime) {
    int ticketID = ++ticketIDCounter;
    struct ticket newTicket = { ticketID, "", "", "", "", "Open", -1 };
    strcpy(newTicket.name, name);
    strcpy(newTicket.contactInfo, contactInfo);
    strcpy(newTicket.description, description);
    strcpy(newTicket.dateTime, dateTime);
    tickets[ticketID - 1] = newTicket;
    return ticketID;
}