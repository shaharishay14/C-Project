#include "CFlight.h"
#include "CCrewMember.h"

// Helper: find crew index; returns -1 if not found
int CFlight::FindCrewIndex(const CCrewMember& candidate) const {
    for (int i = 0; i < crewCount; ++i) {
        if (crew[i] && (*crew[i] == candidate)) {
            return i;
        }
    }
    return -1;
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
        crew[i] = new CCrewMember(*other.crew[i]);
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

// Plane assignment
void CFlight::SetPlane(const CPlane* newPlane) {
    plane = newPlane;
}

// Add crew member
CFlight& CFlight::operator+(const CCrewMember& crewMember) {
    if (crewCount >= MAX_CREW) return *this;
    if (FindCrewIndex(crewMember) != -1) return *this;
    CCrewMember* newMember = new CCrewMember(crewMember);
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
        crew[i] = new CCrewMember(*other.crew[i]);
    }
    crewCount = other.crewCount;

    return *this;
}