#pragma once

#include "CCrewMember.h"
#include "CFlightCompException.h"
#include <string>
#include <fstream>

using namespace std;

class CPilot : public CCrewMember {

private:
    bool isCaptain;

public:
    CPilot() = delete; // Disables the default constructor

    // Constructor: Initializes the pilot with
    CPilot(const string& name, bool isCaptain, CAddress* address,
        int airTime = 0);

    // Constructor without address for unregistered pilots
    CPilot(const string& name, bool isCaptain, int airTime = 0);

	// Constructor with name and address, defaults to not a captain
	CPilot(const string& name, CAddress address, int airTime = 0);
    
    // File constructor
    CPilot(ifstream& inFile);

    // Copy constructor and destructor
    CPilot(const CPilot& other);
    virtual ~CPilot();

    // Getters
    bool GetIsCaptain() const;

    // Setters
    void SetIsCaptain(bool isCaptain);

    // Assignment operator
    void operator=(const CPilot& other);

    // Addition operator
    bool operator+=(int deltaMinutes) override;

    // Stream operators
    virtual void toOs(ostream& os) const override;

    // Virtual functions
    virtual CCrewMember* Clone() const override;
    void ReceiveGift(ostream& os) override;
    void ReceiveUniform(ostream& os) override;
    void ToSimulator(ostream& os) const;

};