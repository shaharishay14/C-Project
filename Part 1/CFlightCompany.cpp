#include "CFlightCompany.h"

using namespace std;

void CFlightCompany::validateData() const
{
    if (name.empty()) {
        throw invalid_argument("Name cannot be empty");
    }
}

CFlightCompany::CFlightCompany(const string& name)
    : name(name)
{}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
    : name(other.name)
{}

CFlightCompany::~CFlightCompany() {}

string CFlightCompany::getName() const
{   
    return name;
}

string CFlightCompany::print() const
{
    return "Name: " + name;
}