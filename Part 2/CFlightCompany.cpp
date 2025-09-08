#include "CFlightCompany.h"
#include "CCrewMember.h"
#include "CPlane.h"
#include "CFlight.h"


void CFlightCompany::Clear() {
    for (int i = 0; i < crewsCount; ++i) delete crews[i], crews[i] = nullptr;
    for (int i = 0; i < planesCount; ++i) delete planes[i], planes[i] = nullptr;
    for (int i = 0; i < flightsCount; ++i) delete flights[i], flights[i] = nullptr;
    crewsCount = 0;
    planesCount = 0;
    flightsCount = 0;
}

void CFlightCompany::CopyFrom(const CFlightCompany& other) {
    for (int i = 0; i < MAX_CREWS;   ++i) crews[i]   = nullptr;
    for (int i = 0; i < MAX_PLANES;  ++i) planes[i]  = nullptr;
    for (int i = 0; i < MAX_FLIGHTS; ++i) flights[i] = nullptr;

    name = other.name;

    for (int i = 0; i < other.crewsCount; ++i)
        crews[i] = other.crews[i] ? new CCrewMember(*other.crews[i]) : nullptr;
    crewsCount = other.crewsCount;

    for (int i = 0; i < other.planesCount; ++i)
        planes[i] = other.planes[i] ? new CPlane(*other.planes[i]) : nullptr;
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
    for(int i = 0; i < MAX_CREWS; i++) {
        crews[i] = nullptr;
    }
    for(int i = 0; i < MAX_PLANES; i++) {
        planes[i] = nullptr;
    }
    for(int i = 0; i < MAX_FLIGHTS; i++) {
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
const string& CFlightCompany::GetName() const
{
    return name;
}

// Setters
void CFlightCompany::SetName(const string& newName)
{
    if (!newName.empty())
    {
        name = newName;
    }
    // else: ignore invalid (leave as-is if empty)
}

// Assignment operator
void CFlightCompany::operator=(const CFlightCompany &other) {
  if (this == &other) return;
  Clear();
  CopyFrom(other);
}

// Equality operator
bool CFlightCompany::operator==(const CFlightCompany &other) const {
  return name == other.name;
}

// Stream operators
ostream &operator<<(ostream &os, const CFlightCompany &fc) {
    os << "Flight Company: " << fc.GetName() << endl;

    os << "There are " << fc.crewsCount << " Crew members" << endl;
    for (int i = 0; i < fc.crewsCount; ++i) {
        if (fc.crews[i]) os << *fc.crews[i] << endl;
    }

    os << "There are " << fc.planesCount << " Planes" << endl;
    for (int i = 0; i < fc.planesCount; ++i) {
        if (fc.planes[i]) os << *fc.planes[i]; // CPlane << already ends with endl
    }

    os << "There are " << fc.flightsCount << " Flights" << endl;
    for (int i = 0; i < fc.flightsCount; ++i) {
        if (fc.flights[i]) os << *fc.flights[i] << endl;
    }

    return os;
}

bool CFlightCompany::AddCrewMember(const CCrewMember &crewMember) {
    if(crewsCount >= MAX_CREWS) return false;
    if(GetCrewMember(crewMember.GetId()) != nullptr) return false;
    crews[crewsCount++] = new CCrewMember(crewMember);
    return true;
}

CCrewMember* CFlightCompany::GetCrewMember(const int id) {
    for(int i = 0; i < crewsCount; i++) {
        if(crews[i] && crews[i]->GetId() == id) return crews[i];
    }
    return nullptr;
}


CFlight* CFlightCompany::GetFlight(const int flightNumber) {
    for(int i = 0; i < flightsCount; i++) {
        if(flights[i] && flights[i]->GetFlightInfo().GetFNum() == flightNumber) return flights[i];
    }
    return nullptr;
}

bool CFlightCompany::AddCrewToFlight(const int flightNumber, const int id)
{
    CFlight* flight = GetFlight(flightNumber);
    if(flight == nullptr) return false;
    CCrewMember* crewMember = GetCrewMember(id);
    if(crewMember == nullptr) return false;

    int before = flight->GetCrewCount();
    *flight + *crewMember;
    return before < flight->GetCrewCount();
}

CPlane* CFlightCompany::GetPlane(const int index) {
    if(index < 0 || index >= MAX_PLANES) return nullptr;
    if(planes[index] == nullptr) return nullptr;
    return planes[index];
}

bool CFlightCompany::AddPlane(const CPlane &plane) {
    if(planesCount >= MAX_PLANES) return false;
    CPlane* newPlane = new CPlane(plane);
    if(newPlane) {
        planes[planesCount++] = newPlane;
    }
    return true;
}

bool CFlightCompany::AddFlight(const CFlight &flight) {
    if(flightsCount >= MAX_FLIGHTS) return false; 
    CFlight* newFlight = GetFlight(flight.GetFlightInfo().GetFNum());
    if(newFlight == nullptr) {
        newFlight = new CFlight(flight);
        if(newFlight) {
            flights[flightsCount++] = newFlight;
        }
        return true;
    }
    return false;
}
