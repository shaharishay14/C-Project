#pragma once

#include <iostream>
#include <string>
#include "CFlightCompException.h"

class CCrewMember;
class CPlane;
class CFlight;

using namespace std;



class CFlightCompany {
private:
    static const int MAX_CREWS = 10;
    static const int MAX_PLANES = 10;
    static const int MAX_FLIGHTS = 10;

    string name;
    CCrewMember* crews[MAX_CREWS];
    int crewsCount;
    CPlane* planes[MAX_PLANES];
    int planesCount;
    CFlight* flights[MAX_FLIGHTS];
    int flightsCount;

    void Clear();
    void CopyFrom(const CFlightCompany& other);


public:
    CFlightCompany() = delete; // Disables the default constructor

    // Constructor: Initializes the flight company with a name
    CFlightCompany(const string& name);
    
    // Constructor: Initializes the flight company from file
    CFlightCompany(const string& filename, int dummy);
	CFlightCompany(ifstream& inFile);

    // Copy constructor and destructor
    CFlightCompany(const CFlightCompany& other);
    ~CFlightCompany();

    // Getters
    const string& GetName() const;
    CCrewMember* GetCrewMember(const int index) const; // Get crew member by index
    CCrewMember* GetCrewMemberByName(const string& name) const; // Get crew member by name
    CFlight* GetFlightByNum(const int flightNumber) const; // Get flight by flight number
    CPlane* GetPlane(const int index) const; // Get plane by index
    int GetCargoCount() const; // Get cargo plane count
    int GetCrewCount() const;  // Get crew count
    int GetPlaneCount() const; // Get plane count
    int GetFlightCount() const; // Get flight count

    // Setters
    void SetName(const string& newName);

    // Print the flight company details
    void Print(ostream& os) const;

    // Assignment operator
    void operator=(const CFlightCompany& other);

    // Equality operator
    bool operator==(const CFlightCompany& other) const;

    // Array access operator
    CPlane& operator[](int index);
    const CPlane& operator[](int index) const;
    
    // File I/O methods
    void SaveToFile(const string &filename) const;
    void SaveToFile(ofstream& outFile) const;
    void LoadFromFile(const string& filename);
	void LoadFromFile(ifstream& inFile);

    // Stream operators
    friend ostream& operator<<(ostream& os, const CFlightCompany& flightCompany);

    // Add crew member
     bool AddCrewMember(const CCrewMember& crewMember); 

    // Add plane
    bool AddPlane(const CPlane& plane);

    // Add flight
    bool AddFlight(const CFlight& flight);

    // Add crew member to flight
    bool AddCrewToFlight(const int flightNumber, const int id);

    // Give holiday gift to all crew members
    void CrewGetPresent();

    // Give uniform to all crew members
    void CrewGetUniform();

    // Send pilots to simulator
    void PilotsToSimulator();
};