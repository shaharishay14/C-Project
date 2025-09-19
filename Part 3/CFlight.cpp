#include "CFlight.h"
#include "CCrewMember.h"
#include "CPilot.h"
#include "CHost.h"
#include "CCargo.h"

// Helper: find crew index; returns -1 if not found
int CFlight::FindCrewIndex(const CCrewMember& candidate) const {
    for (int i = 0; i < crewCount; ++i) {
        if (crew[i] && (*crew[i] == candidate)) {
            return i;
        }
    }
    return -1;
}


// Helper to count pilots and superior hosts
void CFlight::CountPilotsAndSuperiorHosts(int& pilotCount, int& superiorHostCount) const {
    for (int i = 0; i < crewCount; ++i) {
        if (crew[i]) {
            if (typeid(*crew[i]) == typeid(CPilot)) { ++pilotCount; }
            if (typeid(*crew[i]) == typeid(CHost) && 
                dynamic_cast<CHost*>(crew[i])->GetHostType() == CHost::eSuper) { 
                ++superiorHostCount; 
            }
        }
    }
}

// Constructor: Initializes the flight with flight info and plane
CFlight::CFlight(const CFlightInfo& flightInfoPar, const CPlane* planePar)
    : flightInfo(flightInfoPar)
    , plane(planePar)
    , crewCount(0)
{
    for (int i = 0; i < MAX_CREW; ++i) {
        crew[i] = nullptr;
    }
}

// Copy constructor
CFlight::CFlight(const CFlight& other)
    : flightInfo(other.flightInfo)
    , plane(other.plane)
    , crewCount(0)
{
    for (int i = 0; i < MAX_CREW; ++i) {
        crew[i] = nullptr;
    }
    for (int i = 0; i < other.crewCount; ++i) {
        crew[i] = other.crew[i]->Clone();
    }
    crewCount = other.crewCount;
}

// Destructor
CFlight::~CFlight()
{
    for (int i = 0; i < crewCount; ++i) {
        delete crew[i];
        crew[i] = nullptr;
    }
    crewCount = 0;
    // CFlight does not own the plane; just clear the pointer
    plane = nullptr;
}

// Getters
const CFlightInfo& CFlight::GetFlightInfo() const { return flightInfo; }
const CPlane* CFlight::GetPlane() const { return plane; }
int CFlight::GetCrewCount() const { return crewCount; }
CCrewMember* CFlight::GetCrewMember(int index) const { return crew[index]; }

// Plane assignment
void CFlight::SetPlane(const CPlane* newPlane) {
    plane = newPlane;
}

// Add crew member
CFlight& CFlight::operator+(const CCrewMember& crewMember) {
    if (crewCount >= MAX_CREW) return *this;
    if (FindCrewIndex(crewMember) != -1) return *this;
    CCrewMember* newMember = crewMember.Clone();
    if (newMember) {
        crew[crewCount++] = newMember;
    }
    return *this;
}

CFlight& CFlight::operator+(CCrewMember *crewMember) {
    if (crewCount >= MAX_CREW) return *this;
    if (FindCrewIndex(*crewMember) != -1) return *this;
    CCrewMember* newMember = crewMember->Clone();
    if (newMember) {
        crew[crewCount++] = newMember;
    }
    return *this;
}

// Equality by flight info
bool CFlight::operator==(const CFlight& other) const {
    return flightInfo == other.flightInfo;
}

// Stream output
ostream& operator<<(ostream& os, const CFlight& flight) {
    os << flight.flightInfo << " ";
    if (flight.plane) {
        os << *flight.plane;
    }
    else {
        os << "No plane assigned yet" << endl;
    }
    os << "There are " << to_string(flight.crewCount) << " crew members in flight" << endl;
    for (int i = 0; i < flight.crewCount; ++i) {
        if (flight.crew[i]) {
            os << " " << *flight.crew[i];
        }
    }
    os << endl;
    return os;
}

// Copy assignment operator (Rule of Three)
CFlight& CFlight::operator=(const CFlight& other) {
    if (this == &other) return *this;

    // Copy simple members
    flightInfo = other.flightInfo;
    plane = other.plane; // non-owning

    // Delete existing crew
    for (int i = 0; i < crewCount; ++i) {
        delete crew[i];
        crew[i] = nullptr;
    }
    crewCount = 0;

    // Deep copy crew
    for (int i = 0; i < other.crewCount; ++i) {
        crew[i] = other.crew[i]->Clone();
    }
    crewCount = other.crewCount;

    return *this;
}

bool CFlight::TakeOff() {
  if (plane == nullptr) return false;

  int minutes = GetFlightInfo().GetDurationMinutes();  
  int pilotCount = 0;
  int superiorHostCount = 0;
  CountPilotsAndSuperiorHosts(pilotCount, superiorHostCount);

  if (typeid(*plane) == typeid(CCargo)) {
    // plane is cargo
    const CCargo *cargo = dynamic_cast<const CCargo *>(plane);
    cargo->UpdateMinutesMessage(minutes, cout);
    if (pilotCount < 1)
      return false;
  } else {
    // plane is not cargo
    if (pilotCount != 1 || superiorHostCount != 1) return false;
  }

  // update crew minutes
  for (int i = 0; i < crewCount; ++i) {
    crew[i]+=(minutes);
  }

  return true;
}