#include "Main.h"

int main() {
	UserAuthentication();


}

int MainMenu()
{
	int choice = 0;
	while (choice != 4) {
		printf("Welcome to Airline Reservation\n");
		printf("======================================\n");
		printf("Select an option:\n");
		printf("1. Seat Reservation Module\n");
		printf("2. Flight Info & Scheduling Module\n");
		printf("3. Customer Support\n");
		printf("4. Quit\n");
		printf("Enter your input\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			SeatReservation();
			break;
		case 2:
			FlightInfo();
			break;
		case 3:
			CustomerSupport();
			break;
		case 4:
			printf("Goodbye!\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			continue;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////// USER AUTHENTICATION
int UserAuthentication() {
	readUsersFromFile("users.txt");
	int choice = 0;
	while (choice != 6) {
		printf("Welcome to User Authentication Module\n");
		printf("======================================\n");
		printf("Select an option:\n");
		printf("1. Register user\n");
		printf("2. Delete user\n");
		printf("3. Login\n");
		printf("4. Update password\n");
		printf("5. Display registered users\n");
		printf("6. Quit\n");
		printf("Enter you input\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			registerUser();
			break;
		case 2:
			deleteUser();
			break;
		case 3:
			loginUser();
			break;
		case 4:
			updateUserPassword();
			break;
		case 5:
			displayUsers();
			break;
		case 6:
			printf("Goodbye!\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");

		}
	}
	return 0;
}

int checkUserExists(char* username) {
	for (int i = 0; i < numUsers; i++) {
		if (strcmp(users[i].username, username) == 0) {
			return 1;
		}
	}
	return 0;
}

int deleteUser() {
	char username[MAX_USERNAME_LENGTH];
	printf("Enter the username of the user you want to delete: ");
	scanf("%s", username);
	int userIndex = getUserIndex(username);
	if (userIndex == -1) {
		printf("User %s not found.\n", username);
		return 0;
	}
	for (int i = userIndex; i < numUsers - 1; i++) {
		users[i] = users[i + 1];
	}
	numUsers--;
	writeUsersToFile("users.txt");
	printf("User %s deleted successfully.\n", username);
	return 1;
}


void displayUsers() {
	printf("List of registered users:\n");
	for (int i = 0; i < numUsers; i++) {
		printf("%s\n", users[i].username);
	}
}

void freeUserMemory(User* user) {
	if (user != NULL) {
		free(user->username);
		free(user->password);
		free(user);
	}
}

int getUserIndex(char* username) {
	for (int i = 0; i < numUsers; i++) {
		if (strcmp(users[i].username, username) == 0) {
			return i;
		}
	}
	return -1;
}

int loginUser() {
	char username[MAX_USERNAME_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
	printf("Enter your username: ");
	scanf("%s", username);
	printf("Enter your password: ");
	scanf("%s", password);
	int userIndex = getUserIndex(username);
	if (userIndex == -1) {
		printf("User %s not found.\n", username);
		return 0;
	}
	if (strcmp(users[userIndex].password, password) != 0) {
		printf("Incorrect password for user %s.\n", username);
		return 0;
	}
	printf("User %s logged in successfully.\n", username);
	MainMenu();


}


void readUsersFromFile(char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Error opening file");
		exit(1);
	}
	numUsers = 0;
	char username[MAX_USERNAME_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
	while (fscanf(fp, "%s %s", username, password) != EOF) {
		if (numUsers >= MAX_USERS) {
			fprintf(stderr, "Too many users\n");
			exit(1);
		}
		strncpy(users[numUsers].username, username, sizeof(users[numUsers].username));
		strncpy(users[numUsers].password, password, sizeof(users[numUsers].password));
		numUsers++;
	}
	fclose(fp);
}

int registerUser() {
	char username[MAX_USERNAME_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
	printf("Enter a username: ");
	scanf("%s", username);
	printf("Enter a password: ");
	scanf("%s", password);
	if (checkUserExists(username)) {
		printf("Username %s already exists. Please choose a different username.\n", username);
		return 0;
	}
	if (numUsers >= MAX_USERS) {
		printf("Too many users. Please try again later.\n");
		return 0;
	}
	strncpy(users[numUsers].username, username, sizeof(users[numUsers].username));
	strncpy(users[numUsers].password, password, sizeof(users[numUsers].password));
	numUsers++;
	writeUsersToFile("users.txt");
	printf("User %s registered successfully.\n", username);
	return 1;
}

int updateUserPassword() {
	char username[MAX_USERNAME_LENGTH];
	char oldPassword[MAX_PASSWORD_LENGTH];
	char newPassword[MAX_PASSWORD_LENGTH];
	printf("Enter your username: ");
	scanf("%s", username);
	printf("Enter your old password: ");
	scanf("%s", oldPassword);
	int userIndex = getUserIndex(username);
	if (userIndex == -1) {
		printf("User %s not found.\n", username);
		return 0;
	}
	if (strcmp(users[userIndex].password, oldPassword) != 0) {
		printf("Incorrect password for user %s.\n", username);
		return 0;
	}
	printf("Enter your new password: ");
	scanf("%s", newPassword);
	strncpy(users[userIndex].password, newPassword, sizeof(users[userIndex].password));
	writeUsersToFile("users.txt");
	printf("Password for user %s updated successfully.\n", username);
	return 1;
}

void writeUsersToFile(char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		perror("Error opening file");
		exit(1);
	}
	for (int i = 0; i < numUsers; i++) {
		fprintf(fp, "%s %s\n", users[i].username, users[i].password);
	}
	fclose(fp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////// SEAT RESERVATION

int SeatReservation()
{
	//print_top_menu();
	FILE* fp;
	int ch = 0, id;
	extern struct Flight* flight;
	struct Flight tmp;

	//flightmenu();

	for (int i = 0; i < FLIGHTS; i++)
		for (int j = 0; j < CAPACITY; j++)
		{
			flights[i].seats[j].id = j;
			flights[i].seats[j].assigned = false;
		}

	if ((fp = fopen("Airline.dat", "rb")) == NULL)
	{
		fprintf(stderr, "Could not open file 'Airline.dat'.\n");
		exit(EXIT_FAILURE);
	}

	// read saved data into flights array
	while (fread(&tmp, flight_size, 1, fp) == 1)
	{
		int number = tmp.id;
		for (int i = 0; i < FLIGHTS; i++)
		{
			if (flights[i].id == number)
			{
				flights[i] = tmp;
				break;
			}
		}
	}


	// main program loop
	while (ch != 'f' && ch != 'F')
	{

		print_top_menu();
		if ((ch = getchar()) != '\n')
			while (getchar() != '\n') continue;
		puts("");
		switch (ch)
		{
		case ('a'):
		case ('A'):
			flight = &flights[0];
			break;
		case ('b'):
		case ('B'):
			flight = &flights[1];
			break;
		case ('c'):
		case ('C'):
			flight = &flights[2];
			break;
		case ('d'):
		case ('D'):
			flight = &flights[3];
			break;
		case ('e'):
		case ('E'):
			flight = &flights[4];
			break;
		case ('f'):
		case ('F'):
			goto Exit;


		default:
			puts("Invalid input. Try again.");
			continue;
		}

		flightmenu();
	}

Exit:
	fclose(fp);
	if ((fp = fopen("Airline.dat", "wb")) == NULL)
	{
		fprintf(stderr, "Could not open file 'Airline.dat' for write.\n");
		exit(EXIT_FAILURE);
	}

	if (fwrite(flights, flight_size, FLIGHTS, fp) != FLIGHTS)
	{
		fprintf(stderr, "Error writing to file 'Airline.dat'.\n");
	}

	fclose(fp);
	puts("Bye.");

	return 0;
}

char* get(char* string, int n)
{
	// wrapper for fgets that replaces first newline with null

	char* return_value = fgets(string, n, stdin);

	while (*string != '\0')
	{
		if (*string == '\n')
		{
			*string = '\0';
			break;
		}

		string++;
	}

	return return_value;
}

void print_top_menu(void)
{
	puts("To choose a flight, enter its letter label:");
	puts("a) 102");
	puts("b) 311");
	puts("c) 444");
	puts("d) 519");
	puts("e) 501");
	puts("f) Quit");

	return;
}

void flightmenu(void)
{
	int ch = 0;
	extern struct Flight* flight;

	while (ch != 'g' && ch != 'G')
	{
		printf("You have selected flight number %d.\n", flight->id);
		puts("To choose a function, enter its letter label:");
		puts("a) Show number of empty seats");
		puts("b) Show list of empty seats");
		puts("c) Show alphabetical list of seats");
		puts("d) Assign a customer to a seat assignment");
		puts("e) Delete a seat assignment");
		puts("f) Confirm a seat assignment");
		puts("g) Back to main menu");

		if ((ch = getchar()) != '\n')
			while (getchar() != '\n') continue;
		puts("");
		switch (ch)
		{
		case ('a'):
		case ('A'):
			countempty();
			break;
		case ('b'):
		case ('B'):
			listempty();
			break;
		case ('c'):
		case ('C'):
			showalphabetical();
			break;
		case ('d'):
		case ('D'):
			assigncustomer();
			break;
		case ('e'):
		case ('E'):
			deleteassignment();
			break;
		case ('f'):
		case ('F'):
			confirmassignment();
			break;
		case ('g'):
		case ('G'):
			break;
		default:
			puts("Invalid input. Try again.");
			continue;
		}
	}
	return;
}

void countempty(void)
{
	extern struct Flight* flight;

	// count empty seats on flight
	int count = 0;
	for (int i = 0; i < CAPACITY; i++)
		if (!flight->seats[i].assigned)
			count++;
	printf("There are %d empty seats on flight number %d.\n", count, flight->id);
}

void listempty(void)
{
	extern struct Flight* flight;
	// list empty seats
	printf("Here is a list of empty seats on flight number %d:\n", flight->id);
	for (int i = 0; i < CAPACITY; i++)
		if (!flight->seats[i].assigned)
			printf("Seat number %d is unassigned.\n", flight->seats[i].id);
}

void showalphabetical(void)
{
	extern struct Flight* flight;

	printf("Here is a list of seat assignments for flight number %d:\n", flight->id);
	printf("%-*s  %-*s  %-12s %-12s\n", MAXNAML, "Last Name", MAXNAML, "First Name",
		"Seat Number", "Status");
	for (int i = 0; i < CAPACITY; i++)
	{
		if (flight->seats[i].assigned)
			printf("%-*s  %-*s  %-12d %-12s\n", MAXNAML, flight->seats[i].last,
				MAXNAML, flight->seats[i].first, flight->seats[i].id,
				flight->seats[i].confirmed ? "Confirmed" : "Unconfirmed");
	}
}

void assigncustomer(void)
{
	int id, ch;
	struct Seat new;
	extern struct Flight* flight;

	printf("Enter seat id number: ");
	scanf("%d", &id);
	while (getchar() != '\n') continue;
	if (id < 0 && id >= CAPACITY)
	{
		puts("This seat number is invalid. Aborting.");
		return;
	}
	if (flight->seats[id].assigned)
	{
		puts("This seat is already assigned. Aborting.");
		return;
	}

	new.id = id;
	new.assigned = true;
	new.confirmed = false;
	printf("Enter passenger first name: ");
	get(new.first, MAXNAML);
	printf("Enter passenger last name: ");
	get(new.last, MAXNAML);

	puts("Here is the overview for your new seat assignment:");
	printf("Flight number: %d\nSeat number: %d\nFirst name: %s\n"
		"Last name: %s\n", flight->id, new.id, new.first, new.last);
	puts("Is this correct? Enter [n/N] to abort or any other key to continue.");

	if ((ch = getchar()) != '\n')
		while (getchar() != '\n') continue;
	if (ch == 'n' || ch == 'N')
	{
		puts("Aborting seat assignment.");
		return;
	}
	flight->seats[id] = new;
	return;
}

void deleteassignment(void)
{
	int id, ch = 0;
	extern struct Flight* flight;

	puts("Enter seat number of the assignment to delete: ");
	scanf("%d", &id);
	while (getchar() != '\n') continue;
	if (id < 0 && id >= CAPACITY)
	{
		puts("This seat number is invalid. Aborting.");
		return;
	}
	if (!flight->seats[id].assigned)
	{
		puts("This seat is not currently assigned. Aborting.");
		return;
	}
	puts("Here is the seat assignment you have selected:");
	printf("Flight number: %d\nSeat number: %d\nFirst name: %s\n"
		"Last name: %s\n", flight->id, flight->seats[id].id,
		flight->seats[id].first, flight->seats[id].last);
	puts("Would you like to delete this assignment? Enter [n/N] to abort "
		"or any other key to continue.");
	if ((ch = getchar()) != '\n')
		while (getchar() != '\n') continue;
	if (ch == 'n' || ch == 'N')
	{
		puts("Aborting seat assignment.");
		return;
	}
	flight->seats[id].first[0] = '\0';
	flight->seats[id].last[0] = '\0';
	flight->seats[id].assigned = false;
	flight->seats[id].confirmed = false;

	return;
}

void confirmassignment(void)
{
	int id;
	extern struct Flight* flight;

	printf("Enter seat id number to confirm: ");
	scanf("%d", &id);
	while (getchar() != '\n') continue;
	if (id < 0 && id >= CAPACITY)
	{
		puts("This seat number is invalid. Aborting.");
	}
	else if (!flight->seats[id].assigned)
	{
		puts("There is no current assignment for this seat. Aborting.");
	}
	else if (flight->seats[id].confirmed)
	{
		puts("This seat assignment is already confirmed.");
	}
	else
	{
		flight->seats[id].confirmed = true;
		puts("Your assignment has been confirmed.");
	}
	return;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////// FLIGHT INFO

void printAirport(Airport airport) {
	printf("%-4s %-25s %11.6f %12.6f\n", airport.code, airport.name, airport.latitude, airport.longitude);
}

void printAirports(Airport airports[MAX], int length) {
	printf("%-4s %-25s %11s %12s\n", "Code", "Name", "Latitude", "Longitude");
	for (int i = 0; i < length; i++) {
		printAirport(airports[i]);
	}
}

Airport findAirport(Airport airports[MAX], int length, char code[4]) {
	for (int i = 0; i < length; i++) {
		if (strcmp(airports[i].code, code) == 0) {
			return airports[i];
		}
	}
	// If the airport is not found, return a temporary struct with invalid values
	Airport temp;
	strcpy(temp.code, "-1");
	temp.latitude = -99999.0;
	temp.longitude = -99999.0;
	return temp;
}

double calculateDistance(Airport airport1, Airport airport2) {
	double R = 3959.0; // Earth's radius in miles
	double lat1 = airport1.latitude * M_PI / 180.0; // Convert latitude to radians
	double lat2 = airport2.latitude * M_PI / 180.0; // Convert latitude to radians
	double lon1 = airport1.longitude * M_PI / 180.0; // Convert longitude to radians
	double lon2 = airport2.longitude * M_PI / 180.0; // Convert longitude to radians
	double dlon = lon2 - lon1;
	double dlat = lat2 - lat1;
	double a = pow(sin(dlat / 2.0), 2.0) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2.0), 2.0);
	double c = 2.0 * atan2(sqrt(a), sqrt(1 - a));
	double distance = R * c;
	return distance;
}

void findInRange(Airport airports[MAX], int length, Airport origin, int range, Airport output[MAX], int* resultsLength) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		double distance = calculateDistance(origin, airports[i]);
		if (distance <= range) {
			output[count] = airports[i];
			count++;
		}
	}
	*resultsLength = count;
}



int fillAirports(Airport airports[MAX]) {
	// Add each airport to the array
	airports[0] = (Airport){ "SAT", "San Antonio Intl", 29.533958, -98.469056 };
	airports[1] = (Airport){ "BKK", "Bangkok Suvarnabhumi", 13.681108, 100.747283 };
	airports[2] = (Airport){ "CDG", "Paris Charles De Gaulle", 49.009722, 2.547780 };
	airports[3] = (Airport){ "GIG", "Rio De Janeiro Gale�o", -22.809999, -43.250555 };
	airports[4] = (Airport){ "HKG", "Hong Kong Intl", 22.308889, 113.914722 };
	airports[5] = (Airport){ "JFK", "New York-JFK", 40.639926, -73.778694 };
	airports[6] = (Airport){ "JNB", "O.R. Tambo Johannesburg", -26.133693, 28.242317 };
	airports[7] = (Airport){ "LAX", "Los Angeles Intl", 33.942496, -118.408048 };
	airports[8] = (Airport){ "LHR", "London Heathrow", 51.477500, -0.461388 };
	airports[9] = (Airport){ "MEX", "Mexico City Benito Juarez", 19.436303, -99.072096 };
	airports[10] = (Airport){ "SIN", "Singapore Changi", 1.359211, 103.989333 };
	airports[11] = (Airport){ "NRT", "Tokyo Narita", 35.765556, 140.385556 };

	// Return the number of airports added
	return 12;
}

void handleOption1(Airport* airports[MAX_AIRPORTS], int length) {
	char code[4];
	printf("Enter a 3-letter airport code: ");
	scanf("%s", code);
	printf("\n");
	Airport airport = findAirport(airports, length, code);
	if (airport.latitude == -99999.0 || airport.longitude == -99999.0) {
		printf("Error: airport not found\n");
	}
	else {
		printAirport(airport);
	}
}



void handleOption2(Airport airports[MAX_AIRPORTS], int length) {
	printAirports(airports, length);
}

void handleOption3(Airport airports[MAX_AIRPORTS], int length) {


	char code1[4], code2[4];
	printf("Enter first 3-letter airport code: ");
	scanf("%3s", code1);
	Airport airport1 = findAirport(airports, length, code1);
	if (airport1.latitude == -99999.0 || airport1.longitude == -99999.0) {
		printf("Error: first airport not found\n");
		return;
	}



	printf("Enter second 3-letter airport code: ");
	scanf("%3s", code2);

	Airport airport2 = findAirport(airports, length, code2);
	if (airport2.latitude == -99999.0 || airport2.longitude == -99999.0) {
		printf("Error: second airport not found\n");
		return;
	}
	double distance = calculateDistance(airport1, airport2);
	printf("Distance between %s and %s is %.2f miles\n", code1, code2, distance);
}

void handleOption4(Airport airports[MAX_AIRPORTS], int length) {
	Airport airport;
	//char Code[4];
	int range;
	printf("Enter a 3-letter airport code: ");
	scanf("%3s", airport.code);
	printf("Enter range in miles: ");
	scanf("%d", &range);
	Airport airport1 = findAirport(airports, length, airport.code);
	if (airport1.latitude == -99999.0 || airport1.longitude == -99999.0) {
		printf("Error: airport not found\n");
		return;
	}
	Airport output[MAX_AIRPORTS];
	int resultsLength = 0;
	findInRange(airports, length, airport1, range, output, &resultsLength);
	if (resultsLength == 0) {
		printf("No airports found within %d miles of %s\n", range, airport.code);
	}
	else {
		printf("%-4s %-25s %10s %11s\n", "Code", "Name", "Latitude", "Longitude");
		for (int i = 0; i < resultsLength; i++) {
			printAirport(output[i]);
		}
	}
}

int FlightInfo() {
	Airport airports[MAX_AIRPORTS];
	int length = fillAirports(airports);

	int option;
	do {
		printf("\n1. Find airport\n");
		printf("2. Print all airports\n");
		printf("3. Calculate distance between airports\n");
		printf("4. Find airports within range\n");
		printf("5. Quit\n");
		printf("Enter option: ");
		scanf("%d", &option);
		printf("\n");
		switch (option) {
		case 1:
			handleOption1(airports, length);
			break;
		case 2:
			handleOption2(airports, length);
			break;
		case 3:
			handleOption3(airports, length);
			break;
		case 4:
			handleOption4(airports, length);
			break;
		case 5:
			printf("Good-bye!\n");
			return 0;
		default:
			printf("Invalid choice\n");
			break;
		}
	} while (option != 5);
	return 0;
}



/////////////////////////////////////////////////////////////////////////// CUSTOMER SUPPORT
int CustomerSupport() {
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