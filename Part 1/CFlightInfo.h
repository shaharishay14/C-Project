#pragma once
#include <string>
#include <stdexcept>

class CFlightInfo
{
private:
    int         flightNumber;
    std::string destination;
    int         durationMinutes;
    int         distanceKm;

    void ValidateData() const;

public:
    CFlightInfo() = delete; 
    CFlightInfo(const std::string& destination, int flightNumber, int durationMinutes, int distanceKm);

    CFlightInfo(const CFlightInfo& other);
    ~CFlightInfo();

    // Getters
    int         GetFlightNumber() const;
    std::string GetDestination() const;
    int         GetDurationMinutes() const;
    int         GetDistanceKm() const;

	// Setters
    void SetDest(const std::string& dest);
    void SetDurationMinutes(int minutes);
    void SetDistanceKm(int km);
    void SetFlightNumber(int flightNumber);

    bool IsEqual(const CFlightInfo& other) const;

    void Print() const;
};
