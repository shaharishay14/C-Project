#include <string>

#include "Address.h"

// Validates the address data (city, street, house number)
void CAddress::ValidateData() const 
{
    if (city.empty()) {
        throw std::invalid_argument("City cannot be empty");
    }
    if (street.empty()) {
        throw std::invalid_argument("Street cannot be empty");
    }
    if (houseNumber <= 0) {
        throw std::invalid_argument("House number must be positive");
    }
}

// Constructor: Initializes the address and validates the data
CAddress::CAddress(int houseNumber, const string& street, const string& city)
    : city(city), street(street), houseNumber(houseNumber)
{
    ValidateData();
}

// Default copy constructor
CAddress::CAddress(const CAddress& other) = default;

// Default destructor
CAddress::~CAddress() = default;

// Getters
string CAddress::GetCity() const 
{
    return city;
}

string CAddress::GetStreet() const
{
    return street;
}

int CAddress::GetHouseNumber() const
{
    return houseNumber;
}

// Updates the address with new values after validation
void CAddress::UpdateAddress(const string& newCity, const string& newStreet, int newHouseNumber)
{
    CAddress tmp(newHouseNumber, newStreet, newCity);
    *this = tmp; 
}

// Prints the address details
void CAddress::Print() const
{
    std::cout << "Street: " << street << ", House Number: " << to_string(houseNumber) << ", City: " << city << endl;
}

// Compares two addresses for equality
bool CAddress::IsEqual(const CAddress& other) const
{
    return city == other.city && street == other.street && houseNumber == other.houseNumber;
}
