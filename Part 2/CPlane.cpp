#include "CPlane.h"

// Initialize static counter starting at 100
int CPlane::nextSerialNumber = 100;

// Constructor: Initializes the plane 
CPlane::CPlane(int seatCountPar, const string& modelPar)
	: serialNumber(nextSerialNumber++)
    , seatCount(0) // (0 allowed for UAVs)
    , model("Unknown")
{
	SetSeatCount(seatCountPar); // ignores invalid
	SetModel(modelPar); // ignores invalid
}


// Copy constructor 
CPlane::CPlane(const CPlane& other)
    : serialNumber(other.serialNumber)
    , model(other.model)
    , seatCount(other.seatCount)
{
}

// Default destructor
CPlane::~CPlane() = default;

// Getters
int CPlane::GetSerialNumber() const { return serialNumber; }

const string &CPlane::GetModel() const { return model; }

int CPlane::GetSeatCount() const { return seatCount; }

// Setters
void CPlane::SetModel(const string &newModel) {
    if (newModel.empty()) {
        throw invalid_argument("Model cannot be empty");
    }
    model = newModel;
}

void CPlane::SetSeatCount(int newSeatCount) {
    if (newSeatCount < 0) {
        throw invalid_argument("Seat count must be non negative");
    }
    seatCount = newSeatCount;
}

// Checks if two planes are equal based on their serial numbers
// bool CPlane::IsEqual(const CPlane &other) const {
//     return serialNumber == other.serialNumber;
// }

// Prints the plane's details
// void CPlane::Print() const {
//     cout << "Plane " << to_string(serialNumber) << " degem: " << model
//          << " seats: " << to_string(seatCount) << endl;
// }

// Assignment operator
void CPlane::operator=(const CPlane &other) {
    if (this != &other) {
        serialNumber = other.serialNumber;
        model = other.model;
        seatCount = other.seatCount;
    }
}

// Equality operator
bool CPlane::operator==(const CPlane &other) const {
    return serialNumber == other.serialNumber;
}

// Stream operators
ostream &operator<<(ostream &os, const CPlane &plane) {
    cout << plane.GetSerialNumber() << " " << plane.GetModel() << " "
         << plane.GetSeatCount();
    return os;
}

// Increment operator - Prefix increment
const CPlane &CPlane::operator++() {
    seatCount++;
    return *this;
}