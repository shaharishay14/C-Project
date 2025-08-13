#pragma once
#include <string>
#include <stdexcept>

class CAddress {
    private:
        std::string city;
        std::string street;
        int houseNumber;
        void validateData() const;
    public:
        CAddress(const std::string& city, const std::string& street, int houseNumber);
        CAddress(const CAddress& other);
        ~CAddress();
        std::string getCity() const;
        std::string getStreet() const;
        int getHouseNumber() const;
        std::string print() const;
        void updateAddress(const std::string& city, const std::string& street, int houseNumber);
};