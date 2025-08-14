#include <iostream>
#include <stdexcept>

#include "FlightCompany.h"

void CFlightCompany::ValidateData() const 
{
    if (name.empty())
    {
        throw std::invalid_argument("Company name cannot be empty");
    }
}

CFlightCompany::CFlightCompany(const std::string& name)
    : name(name) 
{
    ValidateData();
}

CFlightCompany::CFlightCompany(const CFlightCompany& other) = default;
CFlightCompany::~CFlightCompany() = default;

std::string CFlightCompany::GetName() const 
{
    return name;
}

void CFlightCompany::SetName(const std::string& newName) 
{
    if (newName.empty())
    {
        throw std::invalid_argument("Company name cannot be empty");
    }
    name = newName;
}

void CFlightCompany::Print() const 
{
    std::cout << "Flight company: " << name << std::endl;
}
