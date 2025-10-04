#pragma once

#include "CCrewMember.h"
#include "CFlightCompException.h"

class CHost : public CCrewMember {
public:
    enum eHostType { eRegular, eSuper, eCalcelan, eNumOfTypes };
    const string hostTypeStrings[eNumOfTypes] = { "Regular", "Super", "Calcelan" };

private:
    eHostType hostType;
public:
    CHost() = delete; // Disables the default constructor

    // Constructor: Initializes the host with name and host type
    CHost(const string& name, eHostType hostType);

    // Constructor: Initializes the host with name, host type, address and optional air time
    CHost(const string& name, eHostType hostType, CAddress* address,
        int airTime = 0);
    
    // File constructor
    CHost(ifstream& inFile);

    // Copy constructor and destructor
    CHost(const CHost& other);
    virtual ~CHost();

    // Getters
    eHostType GetHostType() const;

    // Setters
    void SetHostType(eHostType hostType);

    // Assignment operator
    void operator=(const CHost& other);

    // Stream operators
    virtual void toOs(ostream& os) const override;

    // Virtual functions
    virtual CCrewMember* Clone() const override;
    void ReceiveGift(ostream& os) override;
    void ReceiveUniform(ostream& os) override;

};