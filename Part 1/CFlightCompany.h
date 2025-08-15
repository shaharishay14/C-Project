#pragma once

#include <string>

using namespace std;

class CFlightCompany
{
    private:
        string name;
        void validateData() const;
    public:
        CFlightCompany(const std::string& name);
        CFlightCompany(const CFlightCompany& other);
        ~CFlightCompany();
        string getName() const;
        string print() const;

}