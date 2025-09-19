#pragma once

#include <iostream>
#include <string>
#include "CFlightCompany.h"
#include "CFlightInfo.h"
#include "CPlane.h"
#include "CCrewMember.h"

using namespace std;

class CFlight {
private:
    static const int MAX_CREW = 10;

    CFlightInfo flightInfo;
    const CPlane* plane = nullptr; // optional assignment; may be nullptr
    CCrewMember* crew[MAX_CREW];
    int crewCount;

    int FindCrewIndex(const CCrewMember &candidate) const;

public:
    CFlight() = delete; // Disables default constructor

    // Ctor with required flight info and optional plane
    CFlight(const CFlightInfo& flightInfo, const CPlane* plane = nullptr);

	// Copy constructor and destructor
    CFlight(const CFlight& other);
    ~CFlight();

    // Getters
    const CFlightInfo& GetFlightInfo() const;
    const CPlane* GetPlane() const;
    int GetCrewCount() const;
    CCrewMember* GetCrewMember(int index) const;

    // Update plane assignment (can set nullptr)
    void SetPlane(const CPlane* newPlane);

    // Assignment operator
    CFlight& operator=(const CFlight& other);

    // Add crew member (by copy) if space and not already exists (by name)
    CFlight &operator+(const CCrewMember &crewMember);
    CFlight &operator+(CCrewMember *crewMember);

    // Equality by flight info
    bool operator==(const CFlight& other) const;

    // Stream output
    friend ostream &operator<<(ostream &os, const CFlight &flight);

    // Helper to count pilots and superior hosts
    void CountPilotsAndSuperiorHosts(int &pilotCount, int &superiorHostCount) const;

    bool TakeOff();
};