#pragma once

#include <string>
#include <stdexcept>

class CPlane 
{
private:
    int         serialNumber;
    std::string model;
    int         seatCount;

    void ValidateData() const;

public:
    CPlane() = delete; 
    CPlane(int serialNumber, int seatCount, const std::string& model);

    CPlane(const CPlane& other);
    ~CPlane();

    // Getters
    int         GetSerialNumber() const;
    std::string GetModel() const;
    int         GetSeatCount() const;

    // Setters
    void SetModel(const std::string& newModel);
    void SetSeatCount(int newSeatCount);
    void SetFlightNumber(int sn);

    bool IsEqual(const CPlane& other) const;

    void Print() const;
};
