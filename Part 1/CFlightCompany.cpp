#include "CFlightCompany.h"

void CFlightCompany::validateData() const
{
    if (name.empty()) {
        throw std::invalid_argument("Name cannot be empty");
    }
}

CFlightCompany::CFlightCompany(const std::string& name)
    : name(name)
{}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
    : name(other.name)
{}

CFlightCompany::~CFlightCompany() {}

std::string CFlightCompany::getName() const
{
    return name;
}

std::string CFlightCompany::print() const
{
    return "Name: " + name;
}