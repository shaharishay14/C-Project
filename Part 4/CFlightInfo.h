#pragma once

#include <iostream>
#include <string>
using namespace std;

class CFlightInfo {
private:
    int flightNumber;
    string destination;
    int durationMinutes;
    int distanceKm;

public:
    CFlightInfo() = delete; // Disables the default constructor

    // Constructor: Initializes the flight info with all required details
    CFlightInfo(const string& destination, int flightNumber, int durationMinutes,
        int distanceKm);

    // Copy constructor and destructor
    CFlightInfo(const CFlightInfo& other);
    ~CFlightInfo();

    // Getters
    int GetFNum() const;
    const string& GetDestination() const;
    int GetDurationMinutes() const;
    int GetDistanceKm() const;

    // Setters
    void SetDest(const string& dest);
    void SetDurationMinutes(int minutes);
    void SetDistanceKm(int km);
    void SetFlightNumber(int flightNumber);

    // Assignment operator
    void operator=(const CFlightInfo& other);

    // Equality operator
    bool operator==(const CFlightInfo& other) const;

    // Inequality operator
    bool operator!=(const CFlightInfo& other) const;

    // Stream operators
    friend ostream& operator<<(ostream& os, const CFlightInfo& flightInfo);

    // Type conversion operators
    operator int();
};