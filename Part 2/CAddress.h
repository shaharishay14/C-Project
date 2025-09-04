#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

class CAddress {
    private:
        string city;
        string street;
        int houseNumber;

    public:
        CAddress() = delete; // Disables the default constructor

        // Constructor with default city ("Tel Aviv")
        CAddress(int houseNumber, const string &street,
                const string &city = "Tel Aviv");

        // Copy-ctor & Dtor
        CAddress(const CAddress &other);
        ~CAddress();

        // Getters
        const string &GetCity() const;
        const string &GetStreet() const;
        int GetHouseNumber() const;

        // Updates the address atomically with validation
        void UpdateAddress(const string &newCity, const string &newStreet,
                            int newHouseNumber);

        // Prints the address details - Replaced with << operator
        // void Print() const;

        // Check if two addresses are equal - Replaced with == operator
        // bool IsEqual(const CAddress &other) const;

        // Assignment operator
        void operator=(const CAddress &other);

        // Stream operators
        friend ostream &operator<<(ostream &os, const CAddress &address);
        friend istream &operator>>(istream &is, CAddress &address);

        // Equality operator
        bool operator==(const CAddress &other) const;

        // Inequality operator
        bool operator!=(const CAddress &other) const;

        string GetCurrentAddress() const;
};
