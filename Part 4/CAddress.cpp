#include <stdexcept>
#include <string>

#include "CAddress.h"
#include "CCompStringException.h"
#include "CCompLimitExecption.h"
#include "CCompFileException.h"

// Constructor: Initializes the address
CAddress::CAddress(int houseNumberPar, const string& streetPar, const string& cityPar)
    : city("Tel Aviv")
    , street("Unknown")
    , houseNumber(1)
{
    // Apply provided values; UpdateAddress ignores any invalid fields
    UpdateAddress(cityPar, streetPar, houseNumberPar);
}

// Convenience constructor to handle C-string/null inputs
CAddress::CAddress(int houseNumberPar, const char* streetPar, const char* cityPar)
    : city("Tel Aviv")
    , street("Unknown")
    , houseNumber(1)
{
    const string safeStreet = (streetPar ? string(streetPar) : string());
    const string safeCity = (cityPar ? string(cityPar) : string());
    UpdateAddress(safeCity, safeStreet, houseNumberPar);
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
void CAddress::UpdateAddress(const string& city, const string& street, int houseNumber) noexcept(false)
{
    if (!city.empty())
        this->city = city;
    else {
      throw CCompStringException("City cannot be empty");
     };

    if (!street.empty())
        this->street = street;
    else {
      throw CCompStringException("Street cannot be empty");
    };

    if (houseNumber > 0)
        this->houseNumber = houseNumber;
    else {
      throw invalid_argument("House number must be positive");
    };
}


string CAddress::GetCurrentAddress() const {
    string s = this->street + " " + to_string(this->houseNumber) + " " + this->city;
    return s;
}

// Assignment operator
void CAddress::operator=(const CAddress& other) {
    if (this != &other) {
        city = other.city;
        street = other.street;
        houseNumber = other.houseNumber;
    }
}

// Equality operator
bool CAddress::operator==(const CAddress& other) const {
    return city == other.city && street == other.street &&
        houseNumber == other.houseNumber;
}

// Inequality operator
bool CAddress::operator!=(const CAddress& other) const {
    return !(*this == other);
}

// Stream operators
ostream& operator<<(ostream& os, const CAddress& address) {
    os << address.GetStreet() << " " << address.GetHouseNumber() << " "
        << address.GetCity();
    return os;
}

istream& operator>>(istream& is, CAddress& address) {
    cout << "Please enter house number, street name and city name:" << endl;
    is >> address.houseNumber >> address.street >> address.city;
    return is;
}