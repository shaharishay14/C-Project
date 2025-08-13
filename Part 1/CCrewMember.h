#pragma once

#include <string>
#include "CAddress.h"

class CCrewMember
{
    private:
        std::string name;
        int airTime;
        CAddress address;
        void validateData() const;
    public:
        CCrewMember(const std::string& name, int airTime, const CAddress& address);
        CCrewMember(const CCrewMember& other);
        ~CCrewMember();
        void updateAirTime(int airTime);
        std::string getName() const;
        int getAirTime() const;
        CAddress getAddress() const;
        void setName(const std::string& name);
        void setAddress(const CAddress& address);
        std::string print() const;
        bool isEqual(const CCrewMember& other) const;
};