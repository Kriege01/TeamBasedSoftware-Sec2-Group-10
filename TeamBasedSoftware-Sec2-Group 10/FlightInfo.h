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

void printAirport(Airport airport);
void printAirports(Airport airports[MAX], int length);
Airport findAirport(Airport airports[MAX], int length, char code[4]);
double calculateDistance(Airport airport1, Airport airport2);
void findInRange(Airport airports[MAX], int length, Airport origin, int range, Airport output[MAX], int* resultsLength);
int fillAirports(Airport airports[MAX]);

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "FlightInfo.h"

#define MAX_AIRPORTS 50
#define _USE_MATH_DEFINES
#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif