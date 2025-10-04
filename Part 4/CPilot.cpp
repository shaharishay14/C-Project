#include "CPilot.h"
#include <cmath>

// Constructor: Uses the base class constructor and sets the captain flag
CPilot::CPilot(const string& name, bool isCaptain, CAddress* address,
    int airTime)
    : CCrewMember(name, address, airTime) {
    SetIsCaptain(isCaptain);  // Will throw exception if parameters are invalid
}

// Constructor without address
CPilot::CPilot(const string& name, bool isCaptain, int airTime)
    : CCrewMember(name, nullptr, airTime), isCaptain(isCaptain) {
    // Will throw exception if parameters are invalid through parent constructor
}

// File constructor
CPilot::CPilot(ifstream& inFile) : CCrewMember("", nullptr, 0) {
    string name;
    int airTime;
    inFile >> name >> airTime;
    SetName(name);
    SetAirTime(airTime);
    isCaptain = true; // Default to captain
}

// Copy constructor
CPilot::CPilot(const CPilot& other) : CCrewMember(other) {
    SetIsCaptain(other.isCaptain);
}

// Destructor
CPilot::~CPilot() {}

// Setters
void CPilot::SetIsCaptain(bool _isCaptain) {
    if (isCaptain != _isCaptain) {
        this->isCaptain = _isCaptain;
    }
}

// Getters
bool CPilot::GetIsCaptain() const { return isCaptain; }

// Assignment operator
void CPilot::operator=(const CPilot& other) {
    if (this != &other) {
        CCrewMember::operator=(other);
        SetIsCaptain(other.isCaptain);
    }
}

// Addition operator
bool CPilot::operator+=(int deltaMinutes) {
    if (deltaMinutes < 0) {
        throw invalid_argument("Delta minutes cannot be negative: " + to_string(deltaMinutes));
    }
    int total = isCaptain ? deltaMinutes + static_cast<int>(floor(deltaMinutes * 0.1)) : deltaMinutes;
    return CCrewMember::operator+=(total);
}

// Stream operators
void CPilot::toOs(ostream& os) const {
    os << "Pilot: " << GetName() << " Minutes: " << to_string(GetAirTime());

    // Handle address - check if it's not null and dereference it
    const CAddress* addr = GetAddress();
    if (addr != nullptr) {
        os << " Home: " << *addr << endl;
    }
    else {
        os << " " << endl;
    }

    os << " " << (isCaptain ? "a Captain" : "Not a Captain") << endl;
}

void CPilot::ReceiveGift(ostream& os) {
    os << GetName() << " thanking the company for receiving the holiday gift" << endl;
}

void CPilot::ReceiveUniform(ostream& os) {
    os << GetName()
        << " this is the fifth time I get a new uniform, this is a waste of "
        "money!" << endl;
}

void CPilot::ToSimulator(ostream& os) const {
    os << "Pilot " << GetName() << " got the message will come soon" << endl;
}

CCrewMember* CPilot::Clone() const {
    return new CPilot(*this);
}