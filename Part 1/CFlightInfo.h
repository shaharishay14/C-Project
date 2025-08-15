#pragma once

#include <string>

using namespace std;

class CFlightInfo
{
    private:
        int flightNumber;
        string destination;
        int duration;
        int distance;
        void validateData() const;
    public:
        CFlightInfo(int flightNumber, const string& destination, int duration, int distance);
        CFlightInfo(const CFlightInfo& other);
        ~CFlightInfo();
        int getFlightNumber() const;
        string getDestination() const;
        int getDuration() const;
        int getDistance() const;
        void setFlightNumber(int flightNumber);
        void setDestination(const string& destination);
        void setDuration(int duration);
        void setDistance(int distance);
        bool isEqual(const CFlightInfo& other) const;
        string print() const;
}