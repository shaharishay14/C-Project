#pragma once

#include <string>

class CFlightInfo
{
    private:
        int flightNumber;
        std::string destination;
        int duration;
        int distance;
        void validateData() const;
    public:
        CFlightInfo(int flightNumber, const std::string& destination, int duration, int distance);
        CFlightInfo(const CFlightInfo& other);
        ~CFlightInfo();
        int getFlightNumber() const;
        std::string getDestination() const;
        int getDuration() const;
        int getDistance() const;
        void setFlightNumber(int flightNumber);
        void setDestination(const std::string& destination);
        void setDuration(int duration);
        void setDistance(int distance);
        bool isEqual(const CFlightInfo& other) const;
        std::string print() const;
}