#include "CFlightInfo.h"
#include "CCompStringException.h"


// Constructor: Initializes the flight info
CFlightInfo::CFlightInfo(const string& destinationPar, int flightNumberPar, int durationMinutesPar, int distanceKmPar)
    : flightNumber(1)
    , destination("Unknown")
    , durationMinutes(0)
    , distanceKm(0)
{
    SetFlightNumber(flightNumberPar);        // ignores invalid
    SetDest(destinationPar);                 // ignores invalid
    SetDurationMinutes(durationMinutesPar);  // ignores invalid
    SetDistanceKm(distanceKmPar);            // ignores invalid
}

// File constructor
CFlightInfo::CFlightInfo(ifstream& inFile) : flightNumber(0), destination(""), durationMinutes(0), distanceKm(0) {
    inFile >> flightNumber >> destination >> durationMinutes >> distanceKm;
}

// Copy constructor
CFlightInfo::CFlightInfo(const CFlightInfo& other)
    : flightNumber(other.flightNumber)
    , destination(other.destination)
    , durationMinutes(other.durationMinutes)
    , distanceKm(other.distanceKm)
{
}

// Destructor
CFlightInfo::~CFlightInfo()
{
    // Nothing to releasehe fi
}

// Getters
int CFlightInfo::GetFNum() const
{
    return flightNumber;
}

const string& CFlightInfo::GetDestination() const
{
    return destination;
}

int CFlightInfo::GetDurationMinutes() const
{
    return durationMinutes;
}

int CFlightInfo::GetDistanceKm() const
{
    return distanceKm;
}

// Setters
void CFlightInfo::SetDest(const string& dest)
{
    if (dest.empty()) {
        throw CCompStringException("Flight destination cannot be empty");
    }
    if (dest.length() > 12) {
        throw CCompStringException("Flight destination too long (max 12 characters)");
    }
    destination = dest;
}

void CFlightInfo::SetDurationMinutes(int minutes)
{
    if (minutes < 0) {
        throw invalid_argument("Flight duration cannot be negative: " + to_string(minutes));
    }
    durationMinutes = minutes;
}

void CFlightInfo::SetDistanceKm(int km)
{
    if (km < 0) {
        throw invalid_argument("Flight distance cannot be negative: " + to_string(km));
    }
    distanceKm = km;
}

void CFlightInfo::SetFlightNumber(int newFlightnNumber)
{
    if (newFlightnNumber <= 0) {
        throw invalid_argument("Flight number must be positive: " + to_string(newFlightnNumber));
    }
    flightNumber = newFlightnNumber;
}

// Assignment operator
void CFlightInfo::operator=(const CFlightInfo& other) {
    if (this != &other) {
        flightNumber = other.flightNumber;
        destination = other.destination;
        durationMinutes = other.durationMinutes;
        distanceKm = other.distanceKm;
    }
}

// Equality operator
bool CFlightInfo::operator==(const CFlightInfo& other) const {
    return flightNumber == other.flightNumber;
}

// Inequality operator
bool CFlightInfo::operator!=(const CFlightInfo& other) const {
    return !(*this == other);
}

// Stream operators
ostream& operator<<(ostream& os, const CFlightInfo& flightInfo) {
    os << "Flight info dest: " << flightInfo.GetDestination() << " Number "
        << to_string(flightInfo.GetFNum()) << " Minutes "
        << to_string(flightInfo.GetDurationMinutes()) << " "
        << to_string(flightInfo.GetDistanceKm()) << " KM" << endl;
    return os;
}

// Type conversion operators
CFlightInfo::operator int() {
    return GetDurationMinutes();
}