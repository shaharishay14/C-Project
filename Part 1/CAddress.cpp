#include "CAddress.h"

using namespace std;

void CAddress::validateData() const 
{
    if (city.empty()) {
        throw invalid_argument("City cannot be empty");
    }
    if (street.empty()) {
        throw invalid_argument("Street cannot be empty");
    }
    if (houseNumber <= 0) {
        throw invalid_argument("House number must be positive");
    }
}

CAddress::CAddress(const string& city, const string& street, int houseNumber) 
    : city(city), street(street), houseNumber(houseNumber)
{
    validateData(); 
}

CAddress::CAddress(const CAddress& other) 
    : city(other.city), street(other.street), houseNumber(other.houseNumber){
    }

CAddress::~CAddress() {
}

string CAddress::getCity() const 
{
    return city;
}

string CAddress::getStreet() const 
{
    return street;
}

int CAddress::getHouseNumber() const
{
    return houseNumber;
}

string CAddress::print() const
{
    return "City: " + city + ", Street: " + street + ", House Number: " + to_string(houseNumber);
}

void CAddress::updateAddress(const string& city, const string& street, int houseNumber)
{
    CAddress temp(city, street, houseNumber);
    
    this->city = city;
    this->street = street;
    this->houseNumber = houseNumber;
}