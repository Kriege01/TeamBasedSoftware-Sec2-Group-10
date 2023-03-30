#pragma once

#include <stdio.h>
#include <string.h>

// Global variables
int ticketIDCounter = 0;

// Data structures
struct ticket {
    int ticketID;
    char name[50];
    char contactInfo[50];
    char description[100];
    char dateTime[50];
    char status[20];
    int rating;
};

// Function prototypes
int createTicket(char* name, char* contactInfo, char* description, char* dateTime);
char* updateTicketStatus(int ticketID, char* status);
void viewTicketDetails(int ticketID);
void addFeedback(int ticketID, int rating);
void viewFeedback();
void searchTickets(char* searchCriteria);
void saveTickets(char* filename);
void loadTickets(char* filename);

// Ticketing system database
struct ticket tickets[100];
