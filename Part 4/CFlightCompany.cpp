#include "CFlightCompany.h"
#include "CCrewMember.h"
#include "CPlane.h"
#include "CFlight.h"
#include "CPilot.h"
#include "CCargo.h"
#include "CCompStringException.h"
#include "CCompLimitException.h"
#include "CCompFileException.h"
#include "CPlaneCrewFactory.h"
#include <fstream>
#include <iostream>

// Clear the flight company
void CFlightCompany::Clear() {
    for (int i = 0; i < crewsCount; ++i) delete crews[i], crews[i] = nullptr;
    for (int i = 0; i < planesCount; ++i) delete planes[i], planes[i] = nullptr;
    for (int i = 0; i < flightsCount; ++i) delete flights[i], flights[i] = nullptr;
    crewsCount = 0;
    planesCount = 0;
    flightsCount = 0;
}

// Copy the flight company
void CFlightCompany::CopyFrom(const CFlightCompany& other) {
    for (int i = 0; i < MAX_CREWS; ++i) crews[i] = nullptr;
    for (int i = 0; i < MAX_PLANES; ++i) planes[i] = nullptr;
    for (int i = 0; i < MAX_FLIGHTS; ++i) flights[i] = nullptr;

    name = other.name;

    for (int i = 0; i < other.crewsCount; ++i)
        crews[i] = other.crews[i] ? other.crews[i]->Clone() : nullptr;
    crewsCount = other.crewsCount;

    for (int i = 0; i < other.planesCount; ++i)
        planes[i] = other.planes[i] ? other.planes[i]->Clone() : nullptr;
    planesCount = other.planesCount;

    for (int i = 0; i < other.flightsCount; ++i)
        flights[i] = other.flights[i] ? new CFlight(*other.flights[i]) : nullptr;
    flightsCount = other.flightsCount;
}




// Constructor: Initializes the flight company
CFlightCompany::CFlightCompany(const string& namePar)
    : name("Unknown") // safe non-empty default,
    , crewsCount(0)
    , planesCount(0)
    , flightsCount(0)
{
    SetName(namePar);    // ignores invalid (empty)
    for (int i = 0; i < MAX_CREWS; i++) {
        crews[i] = nullptr;
    }
    for (int i = 0; i < MAX_PLANES; i++) {
        planes[i] = nullptr;
    }
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i] = nullptr;
    }
}

// Constructor: Initializes the flight company from file
CFlightCompany::CFlightCompany(const string& filename, int dummy)
    : name("Unknown")
    , crewsCount(0)
    , planesCount(0)
    , flightsCount(0)
{
    // Initialize arrays
    for (int i = 0; i < MAX_CREWS; i++) {
        crews[i] = nullptr;
    }
    for (int i = 0; i < MAX_PLANES; i++) {
        planes[i] = nullptr;
    }
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i] = nullptr;
    }
    
    // Try to load from file, if file doesn't exist, use default name
    try {
        LoadFromFile(filename);
    } catch (const CCompFileException& e) {
        // File doesn't exist, use default name
        SetName(filename);
    }
}

CFlightCompany::CFlightCompany(ifstream& inFile) 
    : name("Unknown")
    , crewsCount(0)
    , planesCount(0)
    , flightsCount(0)
{
    // Initialize arrays
    for (int i = 0; i < MAX_CREWS; i++) {
        crews[i] = nullptr;
    }
    for (int i = 0; i < MAX_PLANES; i++) {
        planes[i] = nullptr;
    }
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i] = nullptr;
    }

	// Load from file stream
    try
    {
        LoadFromFile(inFile);
    }
    catch (const CCompFileException& e)
    {
        throw "Could not load data from file"; // Rethrow exception to caller
	}
}

// Copy constructor
CFlightCompany::CFlightCompany(const CFlightCompany& other)
    : name(other.name), crewsCount(0), planesCount(0), flightsCount(0)
{
    CopyFrom(other);
}

// Destructor
CFlightCompany::~CFlightCompany()
{
    Clear();
}

// Getters
const string& CFlightCompany::GetName() const { return name; }
int CFlightCompany::GetCrewCount() const { return crewsCount; }
int CFlightCompany::GetPlaneCount() const { return planesCount; }
int CFlightCompany::GetFlightCount() const { return flightsCount; }




// Setters
void CFlightCompany::SetName(const string& newName)
{
    if (newName.empty()) {
        throw CCompStringException("Flight company name cannot be empty");
    }
    name = newName;
}

// Print the flight company details
void CFlightCompany::Print(ostream& os) const
{
    os << "Flight company: " << name << endl;

    os << "There are " << crewsCount << " Crew members" << endl;
    for (int i = 0; i < crewsCount; ++i) {
        if (crews[i]) os << *crews[i] << endl;
    }

    os << "There are " << planesCount << " Planes" << endl;
    for (int i = 0; i < planesCount; ++i) {
        if (planes[i]) os << *planes[i];
    }

    os << "There are " << flightsCount << " Flights" << endl;
    for (int i = 0; i < flightsCount; ++i) {
        if (flights[i]) os << *flights[i] << endl;
    }
}

// Assignment operator
void CFlightCompany::operator=(const CFlightCompany& other) {
    if (this == &other) return;
    Clear();
    CopyFrom(other);
}

// Equality operator
bool CFlightCompany::operator==(const CFlightCompany& other) const {
    return name == other.name;
}

// Array access operator - non-const version (allows modification)
CPlane& CFlightCompany::operator[](int index) {
    if (index < 0 || index >= planesCount) {
        throw CCompLimitException(planesCount - 1);
    }
    if (planes[index] == nullptr) {
        throw CCompStringException("Plane at index " + to_string(index) + " is null");
    }
    return *planes[index];
}

// Array access operator - const version (read-only)
const CPlane& CFlightCompany::operator[](int index) const {
    if (index < 0 || index >= planesCount) {
        throw CCompLimitException(planesCount - 1);
    }
    if (planes[index] == nullptr) {
        throw CCompStringException("Plane at index " + to_string(index) + " is null");
    }
    return *planes[index];
}

// Stream operators
ostream& operator<<(ostream& os, const CFlightCompany& fc) {
    fc.Print(os);
    return os;
}

// Add crew member using reference
bool CFlightCompany::AddCrewMember(const CCrewMember& crewMember) {
    if (crewsCount >= MAX_CREWS) { 
        throw CCompLimitException(MAX_CREWS);
    }

    // Check for duplicates (added check by name)
    for (int i = 0; i < crewsCount; ++i) {
        if (crews[i] && crews[i]->GetName() == crewMember.GetName()) {
            throw CCompStringException("Crew member with name '" + crewMember.GetName() + "' already exists");
        }
    }
    crews[crewsCount++] = crewMember.Clone();
    return true;
}


CCrewMember* CFlightCompany::GetCrewMember(const int index) const {
    if (index < 0 || index >= crewsCount) {
        throw CCompLimitException(crewsCount - 1);
    }
    if (crews[index] == nullptr) {
        throw CCompStringException("Crew member at index " + to_string(index) + " is null");
    }
    return crews[index];
}

CCrewMember* CFlightCompany::GetCrewMemberByName(const string& name) const {
    for (int i = 0; i < crewsCount; i++) {
        if (crews[i] && crews[i]->GetName() == name) {
            return crews[i];
        }
    }
    return nullptr; // Crew member not found
}


CFlight* CFlightCompany::GetFlightByNum(const int flightNumber) const {
    for (int i = 0; i < flightsCount; i++) {
        if (flights[i] && flights[i]->GetFlightInfo().GetFNum() == flightNumber) return flights[i];
    }
    return nullptr;
}

bool CFlightCompany::AddCrewToFlight(const int flightNumber, const int id)
{
    CFlight* flight = GetFlightByNum(flightNumber);
    if (flight == nullptr) {
        throw CCompStringException("Flight with number " + to_string(flightNumber) + " not found");
    }
    CCrewMember* crewMember = GetCrewMember(id);
    if (crewMember == nullptr) {
        throw CCompStringException("Crew member with id " + to_string(id) + " not found");
    }

    int before = flight->GetCrewCount();
    *flight + *crewMember;
    return before < flight->GetCrewCount();
}

CPlane* CFlightCompany::GetPlane(const int index) const {
    if (index < 0 || index >= planesCount) {
        throw CCompLimitException(planesCount - 1);
    }
    if (planes[index] == nullptr) {
        throw CCompStringException("Plane at index " + to_string(index) + " is null");
    }
    return planes[index];
}

bool CFlightCompany::AddPlane(const CPlane& plane) {
    if (planesCount >= MAX_PLANES) {
        throw CCompLimitException(MAX_PLANES);
    }
    for (int i = 0; i < planesCount; i++) {
        if (planes[i] && *planes[i] == plane) {
            throw CCompStringException("Plane already exists in company");
        }
    }
    planes[planesCount++] = plane.Clone();
    return true;
}


bool CFlightCompany::AddFlight(const CFlight& flight) {
    if (flightsCount >= MAX_FLIGHTS) {
        throw CCompLimitException(MAX_FLIGHTS);
    }
    CFlight* existingFlight = GetFlightByNum(flight.GetFlightInfo().GetFNum());
    if (existingFlight != nullptr) {
        throw CCompStringException("Flight with number " + to_string(flight.GetFlightInfo().GetFNum()) + " already exists");
    }
    CFlight* newFlight = new CFlight(flight);
    if (newFlight) {
        flights[flightsCount++] = newFlight;
    }
    return true;
}

int CFlightCompany::GetCargoCount() const {
    int count = 0;
    for (int i = 0; i < planesCount; i++) {
        if (planes[i] && dynamic_cast<const CCargo*>(planes[i]) != nullptr) {
            count++;
        }
    }
    return count;
}

void CFlightCompany::CrewGetPresent() {
    for (int i = 0; i < crewsCount; i++) {
        if (crews[i]) crews[i]->ReceiveGift(cout);
    }
}

void CFlightCompany::CrewGetUniform() {
    for (int i = 0; i < crewsCount; i++) {
        if (crews[i]) crews[i]->ReceiveUniform(cout);
    }
}

void CFlightCompany::PilotsToSimulator() {
    for (int i = 0; i < crewsCount; i++) {
        if (crews[i]) {
            const CPilot* pilot = dynamic_cast<const CPilot*>(crews[i]);
            if (pilot != nullptr) {
                pilot->ToSimulator(cout);
            }
        }
    }
}

// Save company data to stream
void CFlightCompany::SaveToFile(ofstream& outFile) const {
    if (!outFile.is_open()) {
        throw CCompFileException("Stream is not open");
    }
    
    // Save company name
    outFile << name << endl;
    
    // Save crew count and crew members
    outFile << crewsCount << endl;
    for (int i = 0; i < crewsCount; i++) {
        if (crews[i]) {
            CPlaneCrewFactory::SaveCrewMemberToFile(outFile, crews[i]);
        }
    }
    
    // Save plane count and planes
    outFile << planesCount << endl;
    for (int i = 0; i < planesCount; i++) {
        if (planes[i]) {
            CPlaneCrewFactory::SavePlaneToFile(outFile, planes[i]);
        }
    }
    
    // Save the last serial number for planes
    CPlane::SaveLastSerialNumber(outFile);
    
    // Save flight count and flights
    outFile << flightsCount << endl;
    for (int i = 0; i < flightsCount; i++) {
        if (flights[i]) {
            CPlaneCrewFactory::SaveFlightToFile(outFile, flights[i]);
        }
    }
}

// Save company data to file
void CFlightCompany::SaveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw CCompFileException(filename);
    }

    SaveToFile(outFile);
    outFile.close();
}

// Load company data from file
void CFlightCompany::LoadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        throw CCompFileException(filename);
    }
    

    // Clear existing data
    Clear();
    
    // Load company name
    inFile >> name;

    
    // Load crew count and crew members
    inFile >> crewsCount;

    for (int i = 0; i < crewsCount; i++) {
        crews[i] = CPlaneCrewFactory::GetCrewMemberFromFile(inFile);
    }
    
    // Load plane count and planes
    inFile >> planesCount;
    for (int i = 0; i < planesCount; i++) {
        planes[i] = CPlaneCrewFactory::GetPlaneFromFile(inFile);
    }
    
    // Load the last serial number for planes 
    CPlane::LoadLastSerialNumber(inFile);
    int dummy1, dummy2, dummy3;
    inFile >> dummy1 >> dummy2 >> dummy3;
    
    // Load flight count and flights
    inFile >> flightsCount;
    for (int i = 0; i < flightsCount; i++) {
        string dest;
        int fnum, duration, distance, crewCount, planeSeats;
        inFile >> dest >> fnum >> duration >> distance >> crewCount >> planeSeats;
        
        CFlightInfo info(dest, fnum, duration, distance);
        CFlight* flight = new CFlight(info, planes[0]); // Use first plane as default
        flights[i] = flight;
    }
    
    // Load crew assignments for each flight
    for (int i = 0; i < flightsCount; i++) {
        int flightCrewCount;
        inFile >> flightCrewCount;
        for (int j = 0; j < flightCrewCount; j++) {
            CCrewMember* crew = CPlaneCrewFactory::GetCrewMemberFromFile(inFile);
            if (crew && flights[i]) {
                *flights[i] + crew;
            }
        }
    }
    
    inFile.close();
}

void CFlightCompany::LoadFromFile(ifstream& inFile)
{
    if (!inFile.is_open()) {
        throw CCompFileException("Invalid or closed file stream");
    }

    Clear();

    // --- Read company name ---
    inFile >> name;

    // --- Read crew count and crew members ---
    inFile >> crewsCount;
    for (int i = 0; i < crewsCount; ++i) {
        crews[i] = CPlaneCrewFactory::GetCrewMemberFromFile(inFile);
    }

    // --- Read plane count and planes ---
    inFile >> planesCount;
    for (int i = 0; i < planesCount; ++i) {
        planes[i] = CPlaneCrewFactory::GetPlaneFromFile(inFile);
    }

    int lastSerialNumber;
    inFile >> lastSerialNumber;
    CPlane::SetNextSerialNumber(lastSerialNumber);

    // --- Read flights ---
    inFile >> flightsCount;
    for (int i = 0; i < flightsCount; ++i) {
        flights[i] = CPlaneCrewFactory::GetFlightFromFile(inFile, this);
    }
}