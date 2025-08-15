#pragma once
#include <string>
#include <stdexcept>

using namespace std;

class CAddress {
    private:
        string city;
        string street;
        int houseNumber;
        void validateData() const;
    public:
        CAddress(const string& city, const string& street, int houseNumber);
        CAddress(const CAddress& other);
        ~CAddress();
        string getCity() const;
        string getStreet() const;
        int getHouseNumber() const;
        string print() const;
        void updateAddress(const string& city, const string& street, int houseNumber);
};