#include <stdexcept>

#include "FlightCompany.h"

// Validates the flight company's data (name)
void CFlightCompany::ValidateData() const 
{
    if (name.empty())
    {
        throw std::invalid_argument("Company name cannot be empty");
    }
}

// Constructor: Initializes the flight company and validates the name
CFlightCompany::CFlightCompany(const string& name)
    : name(name) 
{
    ValidateData();
}

// Default copy constructor
CFlightCompany::CFlightCompany(const CFlightCompany& other) = default;

// Default destructor
CFlightCompany::~CFlightCompany() = default;

// Getters
string CFlightCompany::GetName() const 
{
    return name;
}

// Setters
void CFlightCompany::SetName(const string& newName) 
{
    if (newName.empty())
    {
        throw std::invalid_argument("Company name cannot be empty");
    }
    name = newName;
}

// Print the flight company details
void CFlightCompany::Print() const 
{
    std::cout << "Flight company: " << name << endl;
}
