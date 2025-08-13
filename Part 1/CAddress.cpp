#include "CAddress.h"

CAddress::CAddress(const std::string& city, const std::string& street, int houseNumber) 
{
    this->city = city;
    this->street = street;
    this->houseNumber = houseNumber;
}

std::string CAddress::getCity() const 
{
    return city;
}

std::string CAddress::getStreet() const 
{
    return street;
}

int CAddress::getHouseNumber() const
{
    return houseNumber;
}

std::string CAddress::print() const
{
    return "City: " + city + ", Street: " + street + ", House Number: " + std::to_string(houseNumber);
}

void CAddress::updateAddress(const std::string& city, const std::string& street, int houseNumber)
{
    this->city = city;
    this->street = street;
    this->houseNumber = houseNumber;
}