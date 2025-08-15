#include "CFlightInfo.h"

// Validates the flight data (flight number, destination, duration, and distance)
void CFlightInfo::ValidateData() const 
{
    if (flightNumber <= 0) {
        throw invalid_argument("Flight number must be positive");
    }
    if (destination.empty())
    {
        throw invalid_argument("Destination cannot be empty");
    }
    if (durationMinutes < 0)
    {
        throw invalid_argument("Duration must be non negative");
    }
    if (distanceKm < 0)
    {
        throw invalid_argument("Distance must be non negative");
    }
}

// Constructor: Initializes the flight info and validates the data
CFlightInfo::CFlightInfo( const string& destination, int flightNumber, int durationMinutes, int distanceKm)
    : flightNumber(flightNumber), destination(destination),
    durationMinutes(durationMinutes), distanceKm(distanceKm) 
{
    ValidateData();
}

// Default copy constructor
CFlightInfo::CFlightInfo(const CFlightInfo& other) = default;

// Default destructor
CFlightInfo::~CFlightInfo() = default;

// Getters
const int& CFlightInfo::GetFlightNumber() const
{
    return flightNumber;
}

const string& CFlightInfo::GetDestination() const 
{
    return destination;
}

const int& CFlightInfo::GetDurationMinutes() const 
{
    return durationMinutes;
}

const int& CFlightInfo::GetDistanceKm() const 
{
    return distanceKm;
}

// Setters
void CFlightInfo::SetDest(const string& dest) 
{
    if (dest.empty())
    {
        throw invalid_argument("Destination cannot be empty");
    }
    destination = dest;
}

void CFlightInfo::SetDurationMinutes(int minutes) 
{
    if (minutes < 0)
    {
        throw invalid_argument("Duration must be non negative");
    }
    durationMinutes = minutes;
}

void CFlightInfo::SetDistanceKm(int km) 
{
    if (km < 0)
    {
        throw invalid_argument("Distance must be non negative");
    }
    distanceKm = km;
}

void CFlightInfo::SetFlightNumber(int newFlightnNumber)
{
    if (flightNumber <= 0) {
        throw invalid_argument("Flight number must be positive");
    }
    flightNumber = newFlightnNumber;
}

// Checks if this flight info is equal to another flight info based on the flight number
bool CFlightInfo::IsEqual(const CFlightInfo& other) const 
{
    return flightNumber == other.flightNumber; 
}

// Prints the flight information to the console
void CFlightInfo::Print() const 
{
    cout << "Flight info dest: " << destination << " Number: " << to_string(flightNumber) <<
        " minutes: " << to_string(durationMinutes) << " KM " << to_string(distanceKm) << endl;
}
