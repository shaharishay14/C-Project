#include "CCrewMember.h"

int CCrewMember::nextId = CCrewMember::START_ID;

// Constructor: Initializes the crew member  with name and address and air time
CCrewMember::CCrewMember(const string& namePar, const CAddress& addressPar, int airTimePar)
    : name("Unknown")
    , address(addressPar) // copy validated CAddress value (CAddress enforces its own invariants)
    , airTime(0)
    , id(nextId++)
{
    SetName(namePar);            // ignores invalid 
    operator+=(airTimePar);   // ignores invalid
}

// Constructor: Initializes the crew member with name and optional air time
CCrewMember::CCrewMember(const string& namePar, int airTimePar)
    : name("Unknown")
    , address(CAddress(1, "Unknown"))
    , airTime(0)
    , id(nextId++)
{
    SetName(namePar);            // ignores invalid 
    operator+=(airTimePar);   // ignores invalid
}
// Copy constructor
CCrewMember::CCrewMember(const CCrewMember& other)
    : name(other.name)
    , address(other.address)
    , airTime(other.airTime)
    , id(other.id)
{
}

// Destructor
CCrewMember::~CCrewMember()
{
    // Nothing to release
}

// Getters
const string& CCrewMember::GetName() const
{ 
    return name; 
}

int CCrewMember::GetAirTime() const 
{
    return airTime;
}

const CAddress& CCrewMember::GetAddress() const 
{
    return address;
}

int CCrewMember::GetId() const 
{
    return id;
}

// Setters
void CCrewMember::SetName(const string& newName)
{
    if (!newName.empty())
        name = newName;
    // else: ignore invalid (leave as-is if empty)
}

void CCrewMember::SetAddress(const CAddress& newAddress)
{
	address = newAddress; // CAddress itself ensures validity at its construction sites and when changing address
}

//Compares two crew members for equality based on their ids
bool CCrewMember::IsEqual(const CCrewMember &other) const {
  return id == other.id;
}


// Assignment operator
void CCrewMember::operator=(const CCrewMember &other) {
    if (this != &other) {
        name = other.name;
        address = other.address;
        airTime = other.airTime;
        id = other.id;
    }
}

bool CCrewMember::operator+=(int deltaMinutes) {
    if (deltaMinutes < 0)
        return false;
    airTime += deltaMinutes;
    return true;
}

// Equality operator
bool CCrewMember::operator==(const CCrewMember &other) const {
    return name == other.name;
}

// Stream operators
ostream &operator<<(ostream &os, const CCrewMember &crewMember) {
    os << "Crewmember: " <<crewMember.GetName() << " Minutes: " << to_string(crewMember.GetAirTime()) << endl;
    return os;
}