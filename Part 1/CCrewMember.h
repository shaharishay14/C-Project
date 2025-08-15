#pragma once

#include <string>
#include "CAddress.h"

using namespace std;

class CCrewMember
{
    private:
        string name;
        int airTime;
        CAddress address;
        void validateData() const;
    public:
        CCrewMember(const string& name, int airTime, const CAddress& address);
        CCrewMember(const CCrewMember& other);
        ~CCrewMember();
        void updateAirTime(int airTime);
        string getName() const;
        int getAirTime() const;
        CAddress getAddress() const;
        void setName(const string& name);
        void setAddress(const CAddress& address);
        std::string print() const;
        bool isEqual(const CCrewMember& other) const;
};