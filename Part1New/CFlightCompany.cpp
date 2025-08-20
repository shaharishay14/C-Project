#include "FlightCompany.h"

// Constructor: Initializes the flight company
CFlightCompany::CFlightCompany(const string& namePar)
    : name("Unknown") // safe non-empty default
{
    SetName(namePar);    // ignores invalid (empty)
}

// Copy constructor
CFlightCompany::CFlightCompany(const CFlightCompany& other)
    : name(other.name)
{
}

// Destructor
CFlightCompany::~CFlightCompany()
{
    // Nothing to release
}

// Getters
const string& CFlightCompany::GetName() const
{
    return name;
}

// Setters
void CFlightCompany::SetName(const string& newName)
{
    if (!newName.empty())
    {
        name = newName;
    }
    // else: ignore invalid (leave as-is if empty)
}

// Print the flight company details
void CFlightCompany::Print() const 
{
    cout << "Flight company: " << name << endl;
}
