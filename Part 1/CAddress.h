#pragna once
#include <string>

class CAddress {
    private:
        std::string city;
        std::string street;
        int houseNumber;
    public:
        CAddress(const std::string& city = "Tel Aviv", const std::string& street = "", int houseNumber = 0);
        std::string getCity() const;
        std::string getStreet() const;
        int getHouseNumber() const;
        std::string print() const;
        void updateAddress(const std::string& city, const std::string& street, int houseNumber);
        ~CAddress();
}