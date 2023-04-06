#include <stdio.h>
#include <string.h>
#include <math.h>
#include "FlightInfo.h"

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
    airports[3] = (Airport){ "GIG", "Rio De Janeiro Galeão", -22.809999, -43.250555 };
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

int main() {
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