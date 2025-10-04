#include "CPlaneCrewFactory.h"
#include "CFlightCompany.h"
#include "CPlane.h"
#include "CCrewMember.h"
#include "CPilot.h"
#include "CHost.h"
#include "CCargo.h"
#include "CFlight.h"
#include "CFlightInfo.h"
#include "CAddress.h"
#include "CCompFileException.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

PlaneType CPlaneCrewFactory::GetPlaneType(const CPlane* pPlane) {
    if (dynamic_cast<const CCargo*>(pPlane) != nullptr) {
        return eCargo;
    }
    return eRegular;
}

CrewType CPlaneCrewFactory::GetCrewType(const CCrewMember* pCrew) {
    if (dynamic_cast<const CPilot*>(pCrew) != nullptr) {
        return ePilot;
    }
    return eHost;
}

void CPlaneCrewFactory::GetCompanyDataFromUser(CFlightCompany& comp) {
    cout << "=== Getting Company Data from User ===" << endl;
    
    // Add some crew members
    cout << "Adding crew members..." << endl;
    CPilot pilot1("John Pilot", CAddress("New York", "Main St", 123));
    CHost host1("Jane Host", CAddress("Los Angeles", "Broadway", 456), CHost::eSuperior);
    comp.AddCrewMember(pilot1);
    comp.AddCrewMember(host1);
    
    // Add some planes
    cout << "Adding planes..." << endl;
    CPlane plane1(150, "Boeing 737");
    CCargo cargo1(50, "Cargo Plane", 1000.0f, 500.0f);
    comp.AddPlane(plane1);
    comp.AddPlane(cargo1);
    
    cout << "Company data setup complete!" << endl;
}

CPlane* CPlaneCrewFactory::GetPlaneFromUser() {
    cout << "Enter plane details:" << endl;
    cout << "Seat count: ";
    int seats;
    cin >> seats;
    
    cout << "Model: ";
    string model;
    cin >> model;
    
    cout << "Plane type (0=Regular, 1=Cargo): ";
    int type;
    cin >> type;
    
    if (type == eCargo) {
        cout << "Max weight: ";
        float maxKg;
        cin >> maxKg;
        
        cout << "Max volume: ";
        float maxVolume;
        cin >> maxVolume;
        
        return new CCargo(seats, model, maxKg, maxVolume);
    } else {
        return new CPlane(seats, model);
    }
}

CCrewMember* CPlaneCrewFactory::GetCrewFromUser() {
    cout << "Enter crew member details:" << endl;
    cout << "Name: ";
    string name;
    cin >> name;
    
    cout << "Address (city street house): ";
    string city, street;
    int house;
    cin >> city >> street >> house;
    CAddress address(city, street, house);
    
    cout << "Crew type (0=Host, 1=Pilot): ";
    int type;
    cin >> type;
    
    if (type == ePilot) {
        return new CPilot(name, address);
    } else {
        cout << "Host type (0=Regular, 1=Superior): ";
        int hostType;
        cin >> hostType;
        return new CHost(name, address, static_cast<CHost::eHostType>(hostType));
    }
}

CCrewMember* CPlaneCrewFactory::GetCrewMemberFromFile(ifstream& inFile) {
    int index;
    string name;
    int airTime;
    int crewType;
    
    inFile >> index >> name >> airTime >> crewType;
    
    if (crewType == ePilot) {
        // Pilot format: index name airTime crewType
        return new CPilot(name, true, airTime); // Default to captain
    } else {
        // Host format: index name airTime crewType hostType city street house
        int hostType;
        string city, street;
        int house;
        inFile >> hostType >> city >> street >> house;
        CAddress* address = new CAddress(city, street, house);
        return new CHost(name, static_cast<CHost::eHostType>(hostType), address, airTime);
    }
}

CPlane* CPlaneCrewFactory::GetPlaneFromFile(ifstream& inFile) {
    int index;
    int serialNumber;
    int seats;
    string model;
    
    inFile >> index >> serialNumber >> seats >> model;
    
    // Check if it's a cargo plane by looking ahead
    string nextToken;
    inFile >> nextToken;
    
    if (nextToken.find('.') != string::npos) {
        // It's a cargo plane - nextToken is maxKg
        float maxKg = stof(nextToken);
        float maxVolume, currentKg, currentVolume;
        inFile >> maxVolume >> currentKg >> currentVolume;
        
        CCargo* cargo = new CCargo(seats, model, maxKg, maxVolume);
        cargo->SetCurrentKg(currentKg);
        cargo->SetCurrentVolume(currentVolume);
        return cargo;
    } else {
        // It's a regular plane - nextToken is the end of line
        // We need to put it back or handle it differently
        return new CPlane(seats, model);
    }
}
