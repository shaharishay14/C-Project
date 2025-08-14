#include <iostream>

#include "CrewMember.h"
#include "Address.h"

void CCrewMember::ValidateData() const {
    if (name.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
    if (airTime < 0) 
    {
        throw std::invalid_argument("Air time must be non negative");
    }
}

CCrewMember::CCrewMember(const std::string& name, const CAddress& address, int airTime)
    : name(name), address(address), airTime(airTime)
{
    ValidateData();
}

CCrewMember::CCrewMember(const CCrewMember& other) = default;
CCrewMember::~CCrewMember() = default;

std::string CCrewMember::GetName() const 
{ 
    return name; 
}

int CCrewMember::GetAirTime() const 
{
    return airTime;
}

CAddress CCrewMember::GetAddress() const 
{
    return address;
}

void CCrewMember::SetName(const std::string& newName)
{
    if (newName.empty())
    {
        throw std::invalid_argument("Name cannot be empty");
    }
    name = newName;
}

void CCrewMember::SetAddress(const CAddress& newAddress)
{
    address = newAddress;
}

bool CCrewMember::UpdateMinutes(int deltaMinutes)
{
    if (deltaMinutes < 0)
    {
        return 0;
    }
    airTime += deltaMinutes;
    return 1;
}

bool CCrewMember::IsEqual(const CCrewMember& other) const
{
    return name == other.name;
}

void CCrewMember::Print() const 
{
    std::cout << "Crewmember " << name << " minutes " << std::to_string(airTime) << std::endl;
}
