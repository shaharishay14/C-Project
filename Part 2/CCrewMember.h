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
    
        static const int START_ID = 1000 ; // starts at 1000

        CCrewMember() = delete; // Disables the default constructor

        // Constructor: Initializes the crew member with name, address and optional default air time (0)
        CCrewMember(const string &name, const CAddress &address, int airTime = 0);

        // Constructor: Initializes the crew member with name and optional air time
        CCrewMember(const string &name, int airTime = 0);

        // Copy-ctor & Dtor
        CCrewMember(const CCrewMember &other);
        ~CCrewMember();

        // Getters
        const string &GetName() const;
        int GetAirTime() const;
        const CAddress &GetAddress() const;
        int GetId() const;

        // Setters/Updates
        void SetName(const string &newName);
        void SetAddress(const CAddress &newAddress);

        // Check if two crew members are equal by id
        bool IsEqual(const CCrewMember &other) const;

        // Assignment operator
        void operator=(const CCrewMember &other);

        // Addition operator
        bool operator+=(int deltaMinutes);

        // Equality operator
        bool operator==(const CCrewMember &other) const;

        // Stream operators
        friend ostream &operator<<(ostream &os, const CCrewMember &crewMember);
};
