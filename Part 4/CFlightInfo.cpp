#include "CFlightInfo.h"

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
    // Nothing to release
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
    if (!dest.empty())
        destination = dest;
    // else: ignore invalid (leave as-is if empty)
}

void CFlightInfo::SetDurationMinutes(int minutes)
{
    if (minutes >= 0)
        durationMinutes = minutes;
    // else: ignore invalid (leave as-is if it is negative)
}

void CFlightInfo::SetDistanceKm(int km)
{
    if (km >= 0)
        distanceKm = km;
    // else: ignore invalid (leave as-is if it is negative)
}

void CFlightInfo::SetFlightNumber(int newFlightnNumber)
{
    if (newFlightnNumber > 0)
        flightNumber = newFlightnNumber;
    // else: ignore invalid (leave as-is if it is non positive)
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