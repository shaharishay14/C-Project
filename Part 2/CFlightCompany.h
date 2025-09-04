#pragma once

#include <iostream>
#include <string>
using namespace std;

class CFlightCompany {
    private:
        string name;

    public:
        CFlightCompany() = delete; // Disables the default constructor

        // Constructor: Initializes the flight company with a name
        CFlightCompany(const string &name);

        // Copy constructor and destructor
        CFlightCompany(const CFlightCompany &other);
        ~CFlightCompany();

        // Getters
        const string &GetName() const;

        // Setters
        void SetName(const string &newName);

        // Print the flight company details - Replaced with << operator
        // void Print() const;

        // Assignment operator
        void operator=(const CFlightCompany &other);

        // Equality operator
        bool operator==(const CFlightCompany &other) const;

        // Stream operators
        friend ostream &operator<<(ostream &os, const CFlightCompany &flightCompany);
        // friend istream &operator>>(istream &is, CFlightCompany &flightCompany);
};
