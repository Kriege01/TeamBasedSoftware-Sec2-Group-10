#include "CustomerSupport.h"

int main() {
    int choice = 0;
    char name[100], description[100], feedback[100], fileName[100];
    int ticketNumber, status;
    Ticket* foundTicket;

    // allocate memory for ticket array
    tickets = (Ticket**)malloc(sizeof(Ticket*));

    // main menu loop
    int running = 1;
    while (running) {
        printf("Welcome to the Customer Support Module\n");
        printf("1. Employee Menu\n");
        printf("2. Customer Menu\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Employee Menu\n");
            printf("1. Update Ticket Status\n");
            printf("2. View All Tickets\n");
            printf("3. Add Feedback\n");
            printf("4. Search Tickets\n");
            printf("5. Return to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                printf("Enter ticket number: ");
                scanf("%d", &ticketNumber);
                printf("Enter status (0 for open, 1 for in progress, 2 for resolved): ");
                scanf("%d", &status);
                updateTicketStatus(ticketNumber, status);
                break;
            case 2:
                viewAllTickets();
                break;
            case 3:
                printf("Enter ticket number: ");
                scanf("%d", &ticketNumber);
                printf("Enter feedback: ");
                scanf("%s", feedback);
                addFeedback(ticketNumber, feedback);
                break;
            case 4:
                printf("Enter customer name: ");
                scanf("%s", name);
                foundTicket = searchTickets(name);
                if (foundTicket == NULL) {
                    printf("No tickets found for customer %s\n", name);
                }
                else {
                    printf("Ticket found: %d\n", foundTicket->ticketNumber);
                    viewTicketDetails(foundTicket->ticketNumber);
                }
                break;
            case 5:
                choice = 0; // reset choice to trigger menu prompt again
                break;
            default:
                printf("Invalid choice\n");
                choice = 0; // reset choice to trigger menu prompt again
                break;
            }
            break;
        case 2:
            printf("Customer Menu\n");
            printf("1. Create Ticket\n");
            printf("2. View Ticket Details\n");
            printf("3. Return to Main Menu\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter issue description: ");
                scanf("%s", description);
                createTicket(name, description);
                printf("Ticket created with number %d\n", nextTicketNumber);
                nextTicketNumber++;
                break;
            case 2:
                printf("Enter ticket number: ");
                scanf("%d", &ticketNumber);
                viewTicketDetails(ticketNumber);
                break;
            case 3:
                freeTickets();
                running = 0; // set running to false to exit the loop
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
            break;
        case 3:
            freeTickets();
            running = 0; // set running to false to exit the loop
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}


void createTicket(char* customerName, char* issueDescription) {
    // allocate memory for a new ticket
    Ticket* newTicket = (Ticket*)malloc(sizeof(Ticket));
    if (newTicket == NULL) {
        printf("Error: memory allocation failed\n");
        return;
    }

    // initialize ticket fields
    newTicket->ticketNumber = nextTicketNumber;

    // read customer name
    printf("Enter customer name: ");
    fflush(stdin); // flush the input buffer to prevent reading leftover characters
    fgets(customerName, MAX_NAME_LENGTH, stdin);
    customerName[strcspn(customerName, "\n")] = '\0'; // remove newline character at end of string
    newTicket->customerName = _strdup(customerName);

    // read issue description
    printf("Enter issue description: ");
    fflush(stdin); // flush the input buffer to prevent reading leftover characters
    fgets(issueDescription, MAX_ISSUE_LENGTH, stdin);
    issueDescription[strcspn(issueDescription, "\n")] = '\0'; // remove newline character at end of string
    newTicket->issueDescription = _strdup(issueDescription);

    newTicket->status = 0; // open status by default
    newTicket->feedback = NULL;

    // add new ticket to array
    numTickets++;
    tickets = (Ticket**)realloc(tickets, numTickets * sizeof(Ticket*));
    tickets[numTickets - 1] = newTicket;
}


   void createTicketWrapper() {
        char customerName[100], issueDescription[100];
        printf("Enter your name: ");
        scanf("%s", customerName);
        printf("Enter issue description: ");
        getchar(); // consume newline character
        fgets(issueDescription, 100, stdin);
        // remove trailing newline character from issue description
        issueDescription[strcspn(issueDescription, "\n")] = '\0';
        createTicket(customerName, issueDescription);
        printf("Ticket created with number %d\n", nextTicketNumber);
        nextTicketNumber++;
    }


void updateTicketStatus(int ticketNumber, int status) {
    int i;
    for (i = 0; i < numTickets; i++) {
        if (tickets[i]->ticketNumber == ticketNumber) {
            tickets[i]->status = status;
            return;
        }
    }
    printf("Ticket not found\n");
}

void viewAllTickets() {
    int i;
    printf("Ticket Number\tCustomer Name\tIssue Description\tStatus\n");
    for (i = 0; i < numTickets; i++) {
        printf("%d\t%s\t%s\t%d\n", tickets[i]->ticketNumber, tickets[i]->customerName, tickets[i]->issueDescription, tickets[i]->status);
    }
}

void viewTicketDetails(int ticketNumber) {
    int i;
    for (i = 0; i < numTickets; i++) {
        if (tickets[i]->ticketNumber == ticketNumber) {
            printf("Ticket Number: %d\n", tickets[i]->ticketNumber);
            printf("Customer Name: %s\n", tickets[i]->customerName);
            printf("Issue Description: %s\n", tickets[i]->issueDescription);
            printf("Status: %d\n", tickets[i]->status);
            if (tickets[i]->feedback != NULL) {
                printf("Feedback: %s\n", tickets[i]->feedback);
            }
            return;
        }
    }
    printf("Ticket not found\n");
}

void addFeedback(int ticketNumber, char* feedback) {
    // find the ticket with the given number
    int i;
    for (i = 0; i < numTickets; i++) {
        if (tickets[i]->ticketNumber == ticketNumber) {
            // allocate memory for the feedback string
            tickets[i]->feedback = (char*)malloc(MAX_FEEDBACK_LENGTH * sizeof(char));

            // prompt user to enter feedback
            printf("Enter feedback: ");
            fgets(tickets[i]->feedback, MAX_FEEDBACK_LENGTH, stdin);

            // remove trailing newline character from input
            tickets[i]->feedback[strcspn(tickets[i]->feedback, "\n")] = '\0';
            break;
        }
    }
    if (i == numTickets) {
        printf("Ticket not found\n");
    }
}


void saveTickets(char* fileName) {
    int i;
    FILE* fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(fp, "%d\n", numTickets);
    for (i = 0; i < numTickets; i++) {
        fprintf(fp, "%d %s %s %d", tickets[i]->ticketNumber, tickets[i]->customerName, tickets[i]->issueDescription, tickets[i]->status);
        if (tickets[i]->feedback != NULL) {
            fprintf(fp, " %s", tickets[i]->feedback);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void loadTickets(char* fileName) {
    int i, n, ticketNumber, status;
    char customerName[MAX_NAME_LENGTH], issueDescription[MAX_ISSUE_LENGTH], feedback[MAX_FEEDBACK_LENGTH];
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d %s %s %d", &ticketNumber, customerName, issueDescription, &status);
        fgets(feedback, MAX_FEEDBACK_LENGTH, fp);
        if (feedback[strlen(feedback) - 1] == '\n') {
            feedback[strlen(feedback) - 1] = '\0';
        }
        createTicket(customerName, issueDescription);
        tickets[i]->ticketNumber = ticketNumber;
        tickets[i]->status = status;
        if (strcmp(feedback, "NULL") != 0) {
            tickets[i]->feedback = _strdup(feedback);
        }
    }
    fclose(fp);
}

void freeTickets() {
    int i;
    for (i = 0; i < numTickets; i++) {
        free(tickets[i]->customerName);
        free(tickets[i]->issueDescription);
        if (tickets[i]->feedback != NULL) {
            free(tickets[i]->feedback);
        }
        free(tickets[i]);
    }
    free(tickets);
}

Ticket* searchTickets(char* customerName) {
    int i;
    for (i = 0; i < numTickets; i++) {
        if (strcmp(tickets[i]->customerName, customerName) == 0) {
            return tickets[i];
        }
    }
    return NULL;
}