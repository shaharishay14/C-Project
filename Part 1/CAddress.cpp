#include "CAddress.h"


void CAddress::validateData() const 
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

CAddress::CAddress(const std::string& city, const std::string& street, int houseNumber) 
    : city(city), street(street), houseNumber(houseNumber)
{
    validateData(); 
}

CAddress::CAddress(const CAddress& other) 
    : city(other.city), street(other.street), houseNumber(other.houseNumber){
    }

CAddress::~CAddress() {
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
    CAddress temp(city, street, houseNumber);
    
    this->city = city;
    this->street = street;
    this->houseNumber = houseNumber;
}