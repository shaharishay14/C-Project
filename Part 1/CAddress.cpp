#include <iostream>

#include "Address.h"

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

CAddress::CAddress(int houseNumber, const std::string& street, const std::string& city)
    : city(city), street(street), houseNumber(houseNumber)
{
    ValidateData();
}

CAddress::CAddress(const CAddress& other) = default;

CAddress::~CAddress() = default;

std::string CAddress::GetCity() const 
{
    return city;
}

std::string CAddress::GetStreet() const
{
    return street;
}

int CAddress::GetHouseNumber() const
{
    return houseNumber;
}

void CAddress::UpdateAddress(const std::string& newCity, const std::string& newStreet, int newHouseNumber)
{
    CAddress tmp(newHouseNumber, newStreet, newCity);
    *this = tmp; 
}

void CAddress::Print() const
{
    std::cout << "Street: " << street << ", House Number: " << std::to_string(houseNumber) << ", City: " << city << std::endl;
}

bool CAddress::IsEqual(const CAddress& other) const
{
    return city == other.city && street == other.street && houseNumber == other.houseNumber;
}
