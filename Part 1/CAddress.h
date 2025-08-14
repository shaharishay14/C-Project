#pragma once

#include <stdexcept>
#include <iostream>
using namespace std;

class CAddress 
{
private:
    string city; 
    string street;
    int houseNumber;

    // Validates the address data (city, street, house number)
    void ValidateData() const;

public:
    CAddress() = delete; // Disables the default constructor

    // Constructor with default city ("Tel Aviv")
    CAddress(int houseNumber, const string& street, const string& city = "Tel Aviv");

    // Copy-ctor & Dtor
    CAddress(const CAddress& other);
    ~CAddress();

    // Getters
    string GetCity() const;
    string GetStreet() const;
    int GetHouseNumber() const;

    // Updates the address atomically with validation
    void UpdateAddress(const string& newCity, const string& newStreet, int newHouseNumber);

	// Prints the address details
    void Print() const;

	// Check if two addresses are equal
    bool IsEqual(const CAddress& other) const;
};
