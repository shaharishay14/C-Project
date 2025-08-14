#include <iostream>

#include "FlightInfo.h"

void CFlightInfo::ValidateData() const 
{
    if (flightNumber <= 0) {
        throw std::invalid_argument("Flight number must be positive");
    }
    if (destination.empty())
    {
        throw std::invalid_argument("Destination cannot be empty");
    }
    if (durationMinutes < 0)
    {
        throw std::invalid_argument("Duration must be non negative");
    }
    if (distanceKm < 0)
    {
        throw std::invalid_argument("Distance must be non negative");
    }
}

CFlightInfo::CFlightInfo( const std::string& destination, int flightNumber, int durationMinutes, int distanceKm)
    : flightNumber(flightNumber), destination(destination),
    durationMinutes(durationMinutes), distanceKm(distanceKm) 
{
    ValidateData();
}

CFlightInfo::CFlightInfo(const CFlightInfo& other) = default;
CFlightInfo::~CFlightInfo() = default;

int CFlightInfo::GetFlightNumber() const
{
    return flightNumber;
}

std::string CFlightInfo::GetDestination() const 
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

void CFlightInfo::SetDest(const std::string& dest) 
{
    if (dest.empty())
    {
        throw std::invalid_argument("Destination cannot be empty");
    }
    destination = dest;
}

void CFlightInfo::SetDurationMinutes(int minutes) 
{
    if (minutes < 0)
    {
        throw std::invalid_argument("Duration must be non negative");
    }
    durationMinutes = minutes;
}

void CFlightInfo::SetDistanceKm(int km) 
{
    if (km < 0)
    {
        throw std::invalid_argument("Distance must be non negative");
    }
    distanceKm = km;
}

void CFlightInfo::SetFlightNumber(int newFlightnNumber)
{
    if (flightNumber < 0) {
        throw std::invalid_argument("Flight number must be non negative");
    }
    flightNumber = newFlightnNumber;
}

bool CFlightInfo::IsEqual(const CFlightInfo& other) const 
{
    return flightNumber == other.flightNumber; 
}

void CFlightInfo::Print() const 
{
    std::cout << "Flight info dest: " << destination << " Number: " << std::to_string(flightNumber) <<
        " minutes: " << std::to_string(durationMinutes) << " KM " << std::to_string(distanceKm) << std::endl;
}
