#pragma once

#include <string>
#include <stdexcept>

using namespace std;

class CPlane
{
    private:
        int serialNumber;
        string model;
        int seats;
        void validateData() const;
    public:
        CPlane(int serialNumber, const string& model, int seats);
        CPlane(const CPlane& other);
        ~CPlane();
        int getSerialNumber() const;
        string getModel() const;
        int getSeats() const;
        string print() const;
        bool isEqual(const CPlane& other) const;
};