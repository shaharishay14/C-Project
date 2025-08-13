#pragma once

#include <string>
#include <stdexcept>

class CPlane
{
    private:
        int serialNumber;
        std::string model;
        int seats;
        void validateData() const;
    public:
        CPlane(int serialNumber, const std::string& model, int seats);
        CPlane(const CPlane& other);
        ~CPlane();
        int getSerialNumber() const;
        std::string getModel() const;
        int getSeats() const;
        std::string print() const;
        bool isEqual(const CPlane& other) const;
};