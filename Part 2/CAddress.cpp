#include <string>

#include "CAddress.h"

// Constructor: Initializes the address
CAddress::CAddress(int houseNumberPar, const string& streetPar, const string& cityPar)
    : city("Tel Aviv")   
    , street("Unknown")  
    , houseNumber(1)     
{
    // Apply provided values; UpdateAddress ignores any invalid fields
    UpdateAddress(cityPar, streetPar, houseNumberPar);
}
// Copy constructor: Initializes the address from another instance
CAddress::CAddress(const CAddress& other)
    : city(other.city)
    , street(other.street)
    , houseNumber(other.houseNumber)
{
}

// Destructor
CAddress::~CAddress() 
{
    // Nothing to release
}

// Getters
const string& CAddress::GetCity() const
{
    return city;
}

const string& CAddress::GetStreet() const
{
    return street;
}

int CAddress::GetHouseNumber() const
{
    return houseNumber;
}

// Updates the address with new values after validation
void CAddress::UpdateAddress(const string& city, const string& street, int houseNumber)
{
    if (!city.empty())       
        this->city = city;
    // else: ignore invalid (leave as-is if empty)

    if (!street.empty())     
        this->street = street;
    // else: ignore invalid (leave as-is if empty)

    if (houseNumber > 0)     
        this->houseNumber = houseNumber;
    // else: ignore invalid (leave as-is if it is non positive)
}


string CAddress::GetCurrentAddress() const {
    string s = street + " " + to_string(houseNumber) + " " + city;
    return s;
}

// Prints the address details
// void CAddress::Print() const {
//   cout << "Street: " << street << ", House Number: " <<
//   to_string(houseNumber)
//        << ", City: " << city << endl;
// }

// // Compares two addresses for equality
// bool CAddress::IsEqual(const CAddress &other) const {
//   return city == other.city && street == other.street &&
//          houseNumber == other.houseNumber;
// }

// Assignment operator
void CAddress::operator=(const CAddress &other) {
    if (this != &other) {
        city = other.city;
        street = other.street;
        houseNumber = other.houseNumber;
    }
}

// Equality operator
bool CAddress::operator==(const CAddress &other) const {
    return city == other.city && street == other.street &&
            houseNumber == other.houseNumber;
}

// Inequality operator
bool CAddress::operator!=(const CAddress &other) const {
    return !(*this == other);
}

// Stream operators
ostream &operator>>(ostream &os, const CAddress &address) {
    cout << address.GetCity() << " " << address.GetStreet() << " "
        << address.GetHouseNumber();
    return os;
}

istream &operator>>(istream &is, CAddress &address) {
    string city, street;
    int houseNumber;
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter street: ";
    cin >> street;
    cout << "Enter house number: ";
    cin >> houseNumber;
    // Use the constructor to validate the data
    address = CAddress(houseNumber, street, city);
    return is;
}