#include "CrewMember.h"

// Constructor: Initializes the crew member 
CCrewMember::CCrewMember(const string& namePar, const CAddress& addressPar, int airTimePar)
    : name("Unknown")
    , address(addressPar) // copy validated CAddress value (CAddress enforces its own invariants)
    , airTime(0)
{
    SetName(namePar);            // ignores invalid 
    UpdateMinutes(airTimePar);   // ignores invalid
}

// Copy constructor
CCrewMember::CCrewMember(const CCrewMember& other)
    : name(other.name)
    , address(other.address)
    , airTime(other.airTime)
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

bool CCrewMember::UpdateMinutes(int deltaMinutes)
{
    if (deltaMinutes < 0)
        return false;       // ignore invalid (leave as-is if it is negative)
    airTime += deltaMinutes;
    return true;
}

// Compares two crew members for equality based on their names
bool CCrewMember::IsEqual(const CCrewMember& other) const
{
    return name == other.name;
}

// Print the crew member's details
void CCrewMember::Print() const 
{
    cout << "Crewmember " << name 
         << " minutes " << to_string(airTime) << endl;
}
