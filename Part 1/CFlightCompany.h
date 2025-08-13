#pragma once

#include <string>

class CFlightCompany
{
    private:
        std::string name;
        void validateData() const;
    public:
        CFlightCompany(const std::string& name);
        CFlightCompany(const CFlightCompany& other);
        ~CFlightCompany();
        std::string getName() const;
        std::string print() const;

}