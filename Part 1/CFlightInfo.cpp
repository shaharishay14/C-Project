#include "CFlightInfo.h"

using namespace std;

void CFlightInfo::validateData() const
{
    if (flightNumber < 0) {
        throw invalid_argument("Flight number must be non negative");
    }
    if (destination.empty()) {
        throw invalid_argument("Destination cannot be empty");
    }
    if (duration < 0){
        throw invalid_argument("Duration must be non negative");
    }
    if (distance < 0){
        throw invalid_argument("Distance must be non negative");
    }
}

CFlightInfo::CFlightInfo(int flightNumber, const string& destination, int duration, int distance)
    : flightNumber(flightNumber), destination(destination), duration(duration), distance(distance)
    {
        validateData();
    }

CFlightInfo::CFlightInfo(const CFlightInfo& other)
    : flightNumber(other.flightNumber), destination(other.destination), duration(other.duration), distance(other.distance)
    {

    }

CFlightInfo::~CFlightInfo() {}

int CFlightInfo::getFlightNumber() const
{
    return flightNumber;
}

string CFlightInfo::getDestination() const
{
    return destination;
}

int CFlightInfo::getDuration() const
{
    return duration;
}

int CFlightInfo::getDistance() const
{
    return distance;
}

void CFlightInfo::setFlightNumber(int flightNumber)
{
    if (flightNumber < 0) {
        throw invalid_argument("Flight number must be non negative");
    }
    this->flightNumber = flightNumber;
}

void CFlightInfo::setDestination(const string& destination)
{
    if (destination.empty()) {
        throw invalid_argument("Destination cannot be empty");
    }
    this->destination = destination;
}

void CFlightInfo::setDuration(int duration)
{
    if (duration < 0) {
        throw invalid_argument("Duration must be non negative");
    }
    this->duration = duration;
}

void CFlightInfo::setDistance(int distance)
{
    if (distance < 0) {
        throw invalid_argument("Distance must be non negative");
    }
    this->distance = distance;
}

bool CFlightInfo::isEqual(const CFlightInfo& other) const
{
    return flightNumber == other.flightNumber && destination == other.destination && duration == other.duration && distance == other.distance;
}

string CFlightInfo::print() const
{
    return "Flight Number: " + to_string(flightNumber) + ", Destination: " + destination + ", Duration: " + to_string(duration) + ", Distance: " + to_string(distance);
}