#pragma once

#include <iostream>
#include <string>
using namespace std;

class CPlane {
    private:
        static int nextSerialNumber; // Auto-incrementing serial counter
        int serialNumber;
        string model;
        int seatCount;

    public:
        CPlane() = delete; // Disables the default constructor

        // Constructor: Initializes the plane with seat count and model
        // Serial number is automatically assigned
        CPlane(int seatCount, const string &model);

        // Copy constructor and destructor
        CPlane(const CPlane &other);
        ~CPlane();

        // Getters
        int GetSerialNumber() const;
        const string &GetModel() const;
        int GetSeatCount() const;

        // Setters
        void SetModel(const string &newModel);
        void SetSeatCount(int newSeatCount);
        // void SetFlightNumber(int sn); // Removed setter for serial number

        // Check if two planes are equal - Replaced with == operator
        // bool IsEqual(const CPlane &other) const;

        // Print plane information - Replaced with << operator
        // void Print() const;

        // Assignment operator
        void operator=(const CPlane &other);

        // Equality operator
        bool operator==(const CPlane &other) const;

        // Stream operators
        friend ostream &operator<<(ostream &os, const CPlane &plane);
        // friend istream &operator>>(istream &is, CPlane &plane);

        // Increment operator - Prefix increment
        const CPlane &operator++();
};
