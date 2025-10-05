#include "CPlaneCrewFactory.h"
#include "CFlightCompany.h"
#include "CPlane.h"
#include "CCrewMember.h"
#include "CPilot.h"
#include "CHost.h"
#include "CCargo.h"
#include "CAddress.h"
#include "CFlightInfo.h"
#include "CFlight.h"
#include "CCompStringException.h"
#include "CCompLimitException.h"
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
    try {
        cout << "=== Getting Company Data from User ===" << endl;

        // Get crew members from user
        cout << "\n--- Adding Crew Members ---" << endl;
        int crewCount;
        cout << "How many crew members do you want to add? ";
        cin >> crewCount;
        if (crewCount < 0) throw CCompStringException("Crew count cannot be negative");

        for (int i = 0; i < crewCount; i++) {
            cout << "\nCrew Member " << (i + 1) << ":" << endl;
            CCrewMember* crew = GetCrewFromUser();
            if (crew) {
                comp.AddCrewMember(*crew);
                delete crew;
            }
        }

        // Get planes from user
        cout << "\n--- Adding Planes ---" << endl;
        int planeCount;
        cout << "How many planes do you want to add? ";
        cin >> planeCount;
        if (planeCount < 0) throw CCompStringException("Plane count cannot be negative");

        for (int i = 0; i < planeCount; i++) {
            cout << "\nPlane " << (i + 1) << ":" << endl;
            CPlane* plane = GetPlaneFromUser();
            if (plane) {
                comp.AddPlane(*plane);
                delete plane;
            }
        }

        // Get flights from user
        cout << "\n--- Adding Flights ---" << endl;
        int flightCount;
        cout << "How many flights do you want to add? ";
        cin >> flightCount;
        if (flightCount < 0) throw CCompStringException("Flight count cannot be negative");

        for (int i = 0; i < flightCount; i++) {
            cout << "\nFlight " << (i + 1) << ":" << endl;
            CFlight* flight = GetFlightFromUser(comp);
            if (flight) {
                comp.AddFlight(*flight);
                delete flight;
            }
        }

        cout << "\n=== Company data setup complete! ===" << endl;
    }
    catch (const CFlightCompException& e) {
        cout << "Error setting up company data: ";
        e.Show();
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

CPlane* CPlaneCrewFactory::GetPlaneFromUser() {
    try {
        cout << "Enter plane details:" << endl;
        cout << "Seat count: ";
        int seats;
        cin >> seats;
        if (seats < 0) throw CCompStringException("Seat count cannot be negative");

        cout << "Model: ";
        string model;
        cin >> model;
        if (model.empty()) throw CCompStringException("Plane model cannot be empty");

        cout << "Plane type (0=Regular, 1=Cargo): ";
        int type;
        cin >> type;
        if (type != eRegular && type != eCargo) {
            throw CCompStringException("Invalid plane type. Must be 0 (Regular) or 1 (Cargo)");
        }

        if (type == eCargo) {
            cout << "Max weight (kg): ";
            float maxKg;
            cin >> maxKg;
            if (maxKg <= 0) throw CCompStringException("Max weight must be positive");

            cout << "Max volume (m³): ";
            float maxVolume;
            cin >> maxVolume;
            if (maxVolume <= 0) throw CCompStringException("Max volume must be positive");

            return new CCargo(seats, model, maxKg, maxVolume);
        } else {
            return new CPlane(seats, model);
        }
    }
    catch (const CFlightCompException& e) {
        cout << "Error creating plane: ";
        e.Show();
        cin.clear();
        cin.ignore(10000, '\n');
        return nullptr;
    }
}

CCrewMember* CPlaneCrewFactory::GetCrewFromUser() {
    try {
        cout << "Enter crew member details:" << endl;
        cout << "Name: ";
        string name;
        cin >> name;
        if (name.empty()) throw CCompStringException("Crew member name cannot be empty");

        cout << "Address (city street house): ";
        string city, street;
        int house;
        cin >> city >> street >> house;
        if (city.empty() || street.empty()) throw CCompStringException("Address fields cannot be empty");

        CAddress address(house, street, city);

        cout << "Crew type (0=Host, 1=Pilot): ";
        int type;
        cin >> type;
        if (type != eHost && type != ePilot) throw CCompStringException("Invalid crew type. Must be 0 (Host) or 1 (Pilot)");

        if (type == ePilot) {
            return new CPilot(name, address);
        } else {
            cout << "Host type (0=Regular, 1=Superior): ";
            int hostType;
            cin >> hostType;
            if (hostType != CHost::eRegular && hostType != CHost::eSuper) {
                throw CCompStringException("Invalid host type. Must be 0 (Regular) or 1 (Superior)");
            }
            return new CHost(name, static_cast<CHost::eHostType>(hostType), new CAddress(address));
        }
    }
    catch (const CFlightCompException& e) {
        cout << "Error creating crew member: ";
        e.Show();
        cin.clear();
        cin.ignore(10000, '\n'); // Clear the input buffer
        return nullptr;
    }
}

CFlight* CPlaneCrewFactory::GetFlightFromUser(CFlightCompany& company) {
    try {
        cout << "=== Creating New Flight ===" << endl;
        
        cout << "Enter flight destination: ";
        string destination;
        cin >> destination;
        if (destination.empty()) throw CCompStringException("Flight destination cannot be empty");

        cout << "Enter flight number: ";
        int flightNumber;
        cin >> flightNumber;
        if (flightNumber <= 0) throw CCompStringException("Flight number must be positive");

        cout << "Enter flight duration (minutes): ";
        int duration;
        cin >> duration;
        if (duration <= 0) throw CCompStringException("Flight duration must be positive");

        cout << "Enter flight distance (km): ";
        int distance;
        cin >> distance;
        if (distance <= 0) throw CCompStringException("Flight distance must be positive");

        // Create flight info
        CFlightInfo info(destination, flightNumber, duration, distance);

        cout << "Does this flight have a plane? (1=Yes, 0=No): ";
        int hasPlane;
        cin >> hasPlane;
        if (hasPlane != 0 && hasPlane != 1) throw CCompStringException("Invalid choice. Must be 0 (No) or 1 (Yes)");

        CFlight* flight = nullptr;
        if (hasPlane == 1) {
            if (company.GetPlaneCount() == 0) {
                throw CCompStringException("No planes available in company");
            }

            cout << "Available planes:" << endl;
            for (int i = 0; i < company.GetPlaneCount(); i++) {
                try {
                    CPlane* plane = company.GetPlane(i);
                    cout << "Index " << i << ": " << plane->GetModel() 
                         << " (Serial: " << plane->GetSerialNumber() << ")" << endl;
                } catch (const CFlightCompException& e) {
                    cout << "Index " << i << ": Invalid plane" << endl;
                }
            }

            cout << "Enter plane index (0 to " << (company.GetPlaneCount() - 1) << "): ";
            int planeIndex;
            cin >> planeIndex;
            
            if (planeIndex < 0 || planeIndex >= company.GetPlaneCount()) {
                throw CCompLimitException(company.GetPlaneCount() - 1);
            }

            CPlane* plane = company.GetPlane(planeIndex);
            flight = new CFlight(info, plane);
            cout << "Assigned plane " << plane->GetModel() 
                 << " (Serial: " << plane->GetSerialNumber() << ") to flight " << flightNumber << endl;
        } else {
            flight = new CFlight(info);
        }

        // Get crew members for this flight
        cout << "\n--- Adding Crew Members to Flight ---" << endl;
        int crewCount;
        cout << "How many crew members do you want to add to this flight? ";
        cin >> crewCount;
        if (crewCount < 0) throw CCompStringException("Crew count cannot be negative");

        for (int i = 0; i < crewCount; i++) {
            cout << "\nCrew Member " << (i + 1) << ":" << endl;
            cout << "Enter crew member name: ";
            string crewName;
            cin >> crewName;
            if (crewName.empty()) throw CCompStringException("Crew member name cannot be empty");

            CCrewMember* crew = company.GetCrewMemberByName(crewName);
            if (crew) {
                *flight + *crew;
                cout << "Added " << crewName << " to flight " << flightNumber << endl;
            } else {
                cout << "Crew member '" << crewName << "' not found in company!" << endl;
            }
        }

        cout << "=== Flight created successfully! ===" << endl;
        return flight;
    }
    catch (const CFlightCompException& e) {
        cout << "Error creating flight: ";
        e.Show();
        cin.clear();
        cin.ignore(10000, '\n');
        return nullptr;
    }
}

CCrewMember* CPlaneCrewFactory::GetCrewMemberFromFile(ifstream& inFile) {
    string name;
    int airTime;
    int crewType;
    
    if (!(inFile >> crewType >> name >> airTime))
      return nullptr; // failed to read basic information
    
    if (crewType == eHost) {
      int hostType;
      
        if (!(inFile >> hostType))
          return nullptr; // failed to read host info
        return new CHost(name, static_cast<CHost::eHostType>(hostType), nullptr, airTime);
    }
    else if (crewType == ePilot) {
        string city, street;
        int house, hasAddress, isCaptain;
        CAddress *address = nullptr;
        if (!(inFile >> hasAddress >> house >> street >> city >> isCaptain))
          return nullptr; // failed to read pilot address
        if (hasAddress == 1) {
            address = new CAddress(house, street, city);
        }
        return new CPilot(name, isCaptain, address, airTime);
    }

    return nullptr; // unknown crewType
}

CPlane* CPlaneCrewFactory::GetPlaneFromFile(ifstream& inFile) {
    int planeType;
    int currentID;
    string model;
    int seats; 

    inFile >> planeType;
    
    if (planeType == 0) { // Regular plane
        inFile >> currentID >> model >> seats;
        return new CPlane(seats, model);
    }
    
    else if (planeType == 1) { // Cargo plane
        inFile >> currentID >> model >> seats;
        float maxVolume, maxKg, currentVolume, currentKg;
        inFile >> maxVolume >> maxKg >> currentVolume >> currentKg;
        
        CCargo* cargo = new CCargo(seats, model, maxKg, maxVolume, currentID);
        cargo->SetCurrentKg(currentKg);
        cargo->SetCurrentVolume(currentVolume);
        return cargo;
    }

    return nullptr; // unknown planeType
}

CFlight* CPlaneCrewFactory::GetFlightFromFile(ifstream& inFile, CFlightCompany* company) {

    string dest;
    
    int fnum, duration, distance, hasPlane, planeID;
    inFile >> dest >> fnum >> duration >> distance >> hasPlane >> planeID;
    CFlight *flight = nullptr;
    CFlightInfo info(dest, fnum, duration, distance);
    if (hasPlane == 1) {
        int planeIndex = planeID - 100;
        flight = new CFlight(info, company->GetPlane(planeIndex));
    }
    else {
        flight = new CFlight(info);
    }


    int crewCount;
    inFile >> crewCount;
    for (int i = 0; i < crewCount; i++) {
        CCrewMember* crew = GetCrewMemberFromFile(inFile);
        if (crew) {
            *flight + crew;
        }
    }    
    return flight;
}

void CPlaneCrewFactory::SaveCrewMemberToFile(ofstream& outFile, const CCrewMember* crew) {
    if (!crew) return;
    
    CrewType type = GetCrewType(crew);
    outFile << type << " " << crew->GetName() << " " << crew->GetAirTime();
    
    if (type == eHost) {
        const CHost* host = dynamic_cast<const CHost*>(crew);
        outFile << " " << host->GetHostType();
    }
    else if (type == ePilot) {
        const CPilot* pilot = dynamic_cast<const CPilot*>(crew);
        const CAddress* address = pilot->GetAddress();
        if (address) {
            outFile << " 1 " << address->GetHouseNumber() << " " 
                    << address->GetStreet() << " " << address->GetCity() 
                    << " " << (pilot->GetIsCaptain() ? 1 : 0);
        } else {
            outFile << " 0 0 empty empty 0";
        }
    }
    outFile << endl;
}

void CPlaneCrewFactory::SavePlaneToFile(ofstream& outFile, const CPlane* plane) {
    if (!plane) return;
    
    PlaneType type = GetPlaneType(plane);
    if (type == eRegular) {
        // Format: planeType currentID model seats
        outFile << "0 " << plane->GetSerialNumber() 
                << " " << plane->GetModel() << " " << plane->GetSeatCount() << endl;
    }
    else if (type == eCargo) {
        const CCargo* cargo = dynamic_cast<const CCargo*>(plane);
        // Format: planeType currentID model seats
        outFile << "1 " << plane->GetSerialNumber() << " " << plane->GetModel() 
                << " " << plane->GetSeatCount() << endl;
        // Format: maxVolume maxKg currentVolume currentKg
        outFile << cargo->GetMaxVolume() << " " << cargo->GetMaxKg() << " " 
                << cargo->GetCurrentVolume() << " " << cargo->GetCurrentKg() << endl;
    }
}

void CPlaneCrewFactory::SaveFlightToFile(ofstream& outFile, const CFlight* flight) {
    if (!flight) return;
    
    const CFlightInfo& info = flight->GetFlightInfo();
    const CPlane* plane = flight->GetPlane();
    
    // Save flight info
    outFile << info.GetDestination() << " " << info.GetFNum() << " " 
            << info.GetDurationMinutes() << " " << info.GetDistanceKm() << " ";
    
    if (plane) {
        outFile << "1 " << plane->GetSerialNumber() << endl;
    } else {
        outFile << "0 0" << endl;
    }

    // Save crew count and crew members
    int crewCount = flight->GetCrewCount();
    outFile << crewCount << endl;
    for (int i = 0; i < crewCount; i++) {
        const CCrewMember* crew = flight->GetCrewMember(i);
        SaveCrewMemberToFile(outFile, crew);
    }
}