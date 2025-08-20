#include "FlightInfo.h"

// Constructor: Initializes the flight info
CFlightInfo::CFlightInfo(const string& destinationPar, int flightNumberPar, int durationMinutesPar, int distanceKmPar)
    : flightNumber(1)        
    , destination("Unknown")
    , durationMinutes(0)     
    , distanceKm(0)         
{
    SetFlightNumber(flightNumberPar);   // ignores invalid
    SetDest(destinationPar);            // ignores invalid
    SetDurationMinutes(durationMinutesPar); // ignores invalid
    SetDistanceKm(distanceKmPar);       // ignores invalid
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
int CFlightInfo::GetFlightNumber() const
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

// Checks if this flight info is equal to another flight info based on the flight number
bool CFlightInfo::IsEqual(const CFlightInfo& other) const 
{
    return flightNumber == other.flightNumber; 
}

// Prints the flight information to the console
void CFlightInfo::Print() const 
{
    cout << "Flight info dest: " << destination
         << " Number: " << flightNumber 
         << " minutes: " << durationMinutes
         << " KM " << distanceKm << endl;
}
