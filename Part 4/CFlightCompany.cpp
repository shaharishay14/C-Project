#include "CFlightCompany.h"
#include "CCrewMember.h"
#include "CPlane.h"
#include "CFlight.h"
#include "CPilot.h"
#include "CCargo.h"

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



// Setters
void CFlightCompany::SetName(const string& newName)
{
    if (!newName.empty())
    {
        name = newName;
    }
    // else: ignore invalid (leave as-is if empty)
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

// Stream operators
ostream& operator<<(ostream& os, const CFlightCompany& fc) {
    fc.Print(os);
    return os;
}

// Add crew member using reference
bool CFlightCompany::AddCrewMember(const CCrewMember& crewMember) {
    if (crewsCount >= MAX_CREWS) { return false; }

    // Check for duplicates (added check by name)
    for (int i = 0; i < crewsCount; ++i) {
        CCrewMember* temp = GetCrewMember(i);
        if (temp && temp->GetName() == crewMember.GetName()) {
            return false;
        }
    }
    crews[crewsCount++] = crewMember.Clone();
    return true;
}


CCrewMember* CFlightCompany::GetCrewMember(const int index) const {
    if (index < 0 || index >= MAX_CREWS) return nullptr;
    if (crews[index] == nullptr) return nullptr;
    return crews[index];
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
    if (flight == nullptr) return false;
    CCrewMember* crewMember = GetCrewMember(id);
    if (crewMember == nullptr) return false;

    int before = flight->GetCrewCount();
    *flight + *crewMember;
    return before < flight->GetCrewCount();
}

CPlane* CFlightCompany::GetPlane(const int index) const {
    if (index < 0 || index >= MAX_PLANES) return nullptr;
    if (planes[index] == nullptr) return nullptr;
    return planes[index];
}

bool CFlightCompany::AddPlane(const CPlane& plane) {
    if (planesCount >= MAX_PLANES)
        return false;
    for (int i = 0; i < planesCount; i++) {
        CPlane* temp = GetPlane(i);
        if (temp && *temp == plane) {
            return false;
        }
    }
    planes[planesCount++] = plane.Clone();
    return true;
}


bool CFlightCompany::AddFlight(const CFlight& flight) {
    if (flightsCount >= MAX_FLIGHTS) return false;
    CFlight* newFlight = GetFlightByNum(flight.GetFlightInfo().GetFNum());
    if (newFlight == nullptr) {
        newFlight = new CFlight(flight);
        if (newFlight) {
            flights[flightsCount++] = newFlight;
        }
        return true;
    }
    return false;
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


