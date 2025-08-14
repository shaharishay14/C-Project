#pragma once

#include <string>
#include <stdexcept>
#include "Address.h"

class CCrewMember 
{
private:
    std::string name;
    CAddress    address;
    int         airTime; 

    void ValidateData() const;

public:
    CCrewMember() = delete; 
    CCrewMember(const std::string& name, const CAddress& address, int airTime = 0);

    // Copy-ctor & Dtor
    CCrewMember(const CCrewMember& other);
    ~CCrewMember();

    // Getters
    std::string GetName() const;
    int         GetAirTime() const;
    CAddress    GetAddress() const; 

    // Set/Update
    void SetName(const std::string& newName);
    void SetAddress(const CAddress& newAddress);
    bool UpdateMinutes(int deltaMinutes); 

    bool IsEqual(const CCrewMember& other) const;

    void Print() const;
};
