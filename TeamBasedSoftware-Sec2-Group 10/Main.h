#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int MainMenu();

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
	char username[MAX_USERNAME_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int numUsers;

int UserAuthentication();
void readUsersFromFile(char* filename);
void writeUsersToFile(char* filename);
int registerUser();
int deleteUser();
int loginUser();
int updateUserPassword();
int checkUserExists(char* username);
int getUserIndex(char* username);
void displayUsers();







#define FLIGHTS 5
#define CAPACITY 12
#define MAXNAML 20



struct Seat
{
	int id;
	bool assigned;
	bool confirmed;
	char last[MAXNAML];
	char first[MAXNAML];
};

struct Flight
{
	int id;
	struct Seat seats[CAPACITY];
};

struct Flight flights[FLIGHTS] = {
	{102},
	{311},
	{444},
	{519},
	{501}
};

int flight_size = sizeof(struct Flight);

static struct Flight* flight;

char* get(char*, int);

int SeatReservation();
void print_top_menu(void);
void flightmenu(void);
void printmenu(void);
void countempty(void);
void listempty(void);
void showalphabetical(void);
void assigncustomer(void);
void deleteassignment(void);
void confirmassignment(void);




#pragma once

#define MAX 50 

/* boolean values */
#define TRUE 1
#define FALSE 0


typedef struct {
	char code[4];
	char name[50];
	double latitude;
	double longitude;
	char code1[4];
	char code2[4];
} Airport;

int FlightInfo();
void printAirport(Airport airport);
void printAirports(Airport airports[MAX], int length);
Airport findAirport(Airport airports[MAX], int length, char code[4]);
double calculateDistance(Airport airport1, Airport airport2);
void findInRange(Airport airports[MAX], int length, Airport origin, int range, Airport output[MAX], int* resultsLength);
int fillAirports(Airport airports[MAX]);

#include <stdio.h>
#include <string.h>
#include <math.h>


#define MAX_AIRPORTS 50
#define _USE_MATH_DEFINES
#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif


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
int CustomerSupport();
void createTicket(char* customerName, char* issueDescription);
void updateTicketStatus(int ticketNumber, int status);
void viewAllTickets();
void viewTicketDetails(int ticketNumber);
void addFeedback(int ticketNumber, char* feedback);
void saveTickets(char* fileName);
void loadTickets(char* fileName);
void freeTickets();
Ticket* searchTickets(char* customerName);