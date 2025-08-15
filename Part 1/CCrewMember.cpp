#include "CCrewMember.h"

using namespace std;

void CCrewMember::validateData() const
{
    if (name.empty()) {
        throw invalid_argument("Name cannot be empty");
    }
    if (airTime < 0) {
        throw invalid_argument("Air time must be non negative");
    }
    address.validateData();
}

CCrewMember::CCrewMember(const string& name, int airTime, const CAddress& address)
    : name(name), airTime(airTime), address(address)
{
    validateData();
}

CCrewMember::CCrewMember(const CCrewMember& other)
    : name(other.name), airTime(other.airTime), address(other.address)
{}

CCrewMember::~CCrewMember() {}

void CCrewMember::updateAirTime(int airTime)
{
    if (airTime < 0) {
        throw invalid_argument("Air time must be non negative");
    }
    this->airTime += airTime;
}

string CCrewMember::getName() const
{
    return name;
}

int CCrewMember::getAirTime() const
{
    return airTime;
}

CAddress CCrewMember::getAddress() const
{
    return address;
}

void CCrewMember::setName(const string& name)
{
    if (name.empty()) {
        throw invalid_argument("Name cannot be empty");
    }
    this->name = name;
}

void CCrewMember::setAddress(const CAddress& address)
{
    address.validateData();
    this->address = address;
}

bool CCrewMember::isEqual(const CCrewMember& other) const
{
    return name == other.name && airTime == other.airTime && address.isEqual(other.address);
}

string CCrewMember::print() const
{
    return "Name: " + name + ", Air Time: " + to_string(airTime) + ", Address: " + address.print();
}