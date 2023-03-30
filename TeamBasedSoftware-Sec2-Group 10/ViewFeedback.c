#include "CustomerSupport.h"

// Function to view feedback ratings
void viewFeedback() {
    printf("Feedback Ratings:\n");
    printf("------------------\n");
    for (int i = 0; i < ticketIDCounter; i++) {
        if (tickets[i].rating != -1) {
            printf("Ticket ID: %d\n", tickets[i].ticketID);
            printf("Rating: %d stars\n", tickets[i].rating);
        }
    }
}