#pragma once

#include <string>
#include <stdexcept>
#include "Address.h"

class CCrewMember 
{
private:
    string   name;
    CAddress address;
    int      airTime; 

    void ValidateData() const;

public:
    CCrewMember() = delete; // Disables the default constructor

    // Constructor: Initializes the crew member with optional default air time (0)
    CCrewMember(const string& name, const CAddress& address, int airTime = 0);

    // Copy-ctor & Dtor
    CCrewMember(const CCrewMember& other);
    ~CCrewMember();

    // Getters
    string   GetName() const;
    int      GetAirTime() const;
    CAddress GetAddress() const; 

    // Set/Update
    void SetName(const string& newName);
    void SetAddress(const CAddress& newAddress);
    bool UpdateMinutes(int deltaMinutes); 

	// Check if two crew members are equal
    bool IsEqual(const CCrewMember& other) const;

    // Print the crew member's details
    void Print() const;
};
