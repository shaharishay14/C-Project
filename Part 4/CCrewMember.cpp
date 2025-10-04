#include "CCrewMember.h"
#include "CCompStringException.h"
#include "CCompLimitException.h"
#include "CCompFileException.h"


// Constructor: Initializes the crew member  with name and address and air time
CCrewMember::CCrewMember(const string& namePar, CAddress* addressPar,
    int airTimePar)
    : name("Unknown"),
    address(nullptr),
    airTime(0) {
    SetName(namePar);       
    operator+=(airTimePar); 
    SetAddress(addressPar);

}

// Constructor: Initializes the crew member with name and optional air time
CCrewMember::CCrewMember(const string& namePar, int airTimePar)
    : name("Unknown"), address(new CAddress(1, "Unknown")), airTime(0)
{
    SetName(namePar);       // Will throw exception if name is empty
    operator+=(airTimePar); // Will throw exception if airTime is negative
}

// Copy constructor
CCrewMember::CCrewMember(const CCrewMember& other)
    : name(other.name), airTime(other.airTime) {
    address = other.address;
}

// Destructor
CCrewMember::~CCrewMember() {
    address = nullptr;
}

// Getters
const string& CCrewMember::GetName() const { return name; }

int CCrewMember::GetAirTime() const { return airTime; }

const CAddress* CCrewMember::GetAddress() const { return address; }


// Setters
void CCrewMember::SetName(const string& newName) {
    if (newName.empty()) {
        throw CCompStringException("Crew member name cannot be empty");
    }
    name = newName;
}

void CCrewMember::SetAddress(CAddress* newAddress) {
    address = newAddress; // CAddress itself ensures validity at its construction
    // sites and when changing address
}

// Assignment operator
void CCrewMember::operator=(const CCrewMember& other) {
    if (this != &other) {
        name = other.name;
		address = other.address;
        airTime = other.airTime;
    }
}


bool CCrewMember::operator+=(int deltaMinutes) {
    if (deltaMinutes < 0) {
        throw CCompStringException("Delta minutes cannot be negative: " + to_string(deltaMinutes));
    }
    airTime += deltaMinutes;
    return true;
}

// Equality operator
bool CCrewMember::operator==(const CCrewMember& other) const {
    return name == other.name;
}

void CCrewMember::Print(ostream& os) const {
    toOs(os);  // Call the virtual function implemented in derived classes
}


void CCrewMember::toOs(ostream& os) const {}

// Stream operators
ostream& operator<<(ostream& os, const CCrewMember& crewMember) {
    crewMember.toOs(os);
    return os;
}