#pragma once
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants for ticket statuses
#define OPEN 0
#define IN_PROGRESS 1
#define RESOLVED 2
#define MAX_NAME_LENGTH     21
#define MAX_ISSUE_LENGTH    163
#define MAX_FEEDBACK_LENGTH 163

// define struct for ticket
typedef struct {
    int ticketNumber;
    char* customerName;
    char* issueDescription;
    int status;
    char* feedback;
} Ticket;

// define global variables
Ticket** tickets;
int numTickets = 0;
int nextTicketNumber = 1;

// function prototypes
void createTicket(char* customerName, char* issueDescription);
void updateTicketStatus(int ticketNumber, int status);
void viewAllTickets();
void viewTicketDetails(int ticketNumber);
void addFeedback(int ticketNumber, char* feedback);
void saveTickets(char* fileName);
void loadTickets(char* fileName);
void freeTickets();
Ticket* searchTickets(char* customerName);