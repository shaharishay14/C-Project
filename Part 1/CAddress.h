#pragma once
#include <string>
#include <stdexcept>


class CAddress 
{
private:
    std::string city;
    std::string street;
    int houseNumber;

    void ValidateData() const;

public:
    CAddress() = delete; 

    // Constructor with default city ("Tel Aviv")
    CAddress(int houseNumber, const std::string& street, const std::string& city = "Tel Aviv");

    // Copy-ctor & Dtor
    CAddress(const CAddress& other);
    ~CAddress();

    // Getters
    std::string GetCity() const;
    std::string GetStreet() const;
    int         GetHouseNumber() const;

    // Atomic update with validation without duplication – uses a constructor to validate
    void UpdateAddress(const std::string& newCity, const std::string& newStreet, int newHouseNumber);

    void Print() const;

    bool IsEqual(const CAddress& other) const;
};
