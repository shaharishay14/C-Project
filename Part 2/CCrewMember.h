#pragma once

#include "CAddress.h"
#include <stdexcept>
#include <string>

class CCrewMember {
    private:
        static int nextId;
        string name;
        CAddress address;
        int airTime;
        int id;

    public:
        CCrewMember() = delete; // Disables the default constructor

        // Constructor: Initializes the crew member with optional default air time (0)
        CCrewMember(const string &name, const CAddress &address, int airTime = 0);

        // Copy-ctor & Dtor
        CCrewMember(const CCrewMember &other);
        ~CCrewMember();

        // Getters
        const string &GetName() const;
        int GetAirTime() const;
        const CAddress &GetAddress() const;
        int GetId() const;

        // Set/Update
        void SetName(const string &newName);
        void SetAddress(const CAddress &newAddress);
        bool UpdateMinutes(int deltaMinutes);

        // Check if two crew members are equal - Replaced with == operator
        // bool IsEqual(const CCrewMember &other) const;

        // Print the crew member's details - Replaced with << operator
        // void Print() const;

        // Assignment operator
        void operator=(const CCrewMember &other);

        // Equality operator
        bool operator==(const CCrewMember &other) const;

        // Stream operators
        friend ostream &operator<<(ostream &os, const CCrewMember &crewMember);
        // friend istream &operator>>(istream &is, CCrewMember &crewMember);
};
