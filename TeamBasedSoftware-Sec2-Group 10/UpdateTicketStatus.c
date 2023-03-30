#include "CustomerSupport.h"

// Function to update the status of a support ticket
char* updateTicketStatus(int ticketID, char* status) {
    strcpy(tickets[ticketID - 1].status, status);
    return "Ticket status updated successfully.";
}