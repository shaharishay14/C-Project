#pragma once

#include <string>
#include <iostream>
using namespace std;

class CFlightInfo
{
private:
    int    flightNumber;
    string destination;
    int    durationMinutes;
    int    distanceKm;

public:
    CFlightInfo() = delete; // Disables the default constructor

    // Constructor: Initializes the flight info with all required details
    CFlightInfo(const string& destination, int flightNumber, int durationMinutes, int distanceKm);

    // Copy constructor and destructor
    CFlightInfo(const CFlightInfo& other);
    ~CFlightInfo();

    // Getters
    int           GetFlightNumber() const;
    const string& GetDestination() const;
    int           GetDurationMinutes() const;
    int           GetDistanceKm() const;

	// Setters
    void SetDest(const string& dest);
    void SetDurationMinutes(int minutes);
    void SetDistanceKm(int km);
    void SetFlightNumber(int flightNumber);

	// Check if two flight info objects are equal
    bool IsEqual(const CFlightInfo& other) const;

	// Print flight information
    void Print() const;
};
