#include "CrewMember.h"

// Validates the crew member's data (name and air time)
void CCrewMember::ValidateData() const {
    if (name.empty())
    {
        throw invalid_argument("Name cannot be empty");
    }
    if (airTime < 0) 
    {
        throw invalid_argument("Air time must be non negative");
    }
}

// Constructor: Initializes the crew member and validates the data
CCrewMember::CCrewMember(const string& name, const CAddress& address, int airTime)
    : name(name), address(address), airTime(airTime)
{
    ValidateData();
}

// Default copy constructor
CCrewMember::CCrewMember(const CCrewMember& other) = default;

// Default destructor
CCrewMember::~CCrewMember() = default;

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
    if (newName.empty())
    {
        throw invalid_argument("Name cannot be empty");
    }
    name = newName;
}

void CCrewMember::SetAddress(const CAddress& newAddress)
{
    address = newAddress;
}

// Updates the air time by adding deltaMinutes; returns success status
bool CCrewMember::UpdateMinutes(int deltaMinutes)
{
    if (deltaMinutes < 0)
    {
        return 0;
    }
    airTime += deltaMinutes;
    return 1;
}

// Compares two crew members for equality based on their names
bool CCrewMember::IsEqual(const CCrewMember& other) const
{
    return name == other.name;
}

// Print the crew member's details
void CCrewMember::Print() const 
{
    cout << "Crewmember " << name << " minutes " << to_string(airTime) << endl;
}
