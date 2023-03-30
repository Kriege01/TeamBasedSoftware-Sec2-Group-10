#include "CustomerSupport.h"

// Function to add feedback to a support ticket
void addFeedback(int ticketID, int rating) {
    tickets[ticketID - 1].rating = rating;
}