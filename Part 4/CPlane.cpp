#include "CPlane.h"
#include "CCompStringException.h"
#include <stdexcept>


// Initialize static counter starting at 100
int CPlane::nextSerialNumber = START_SERIAL;

// Constructor: Initializes the plane 
CPlane::CPlane(int seatCountPar, const string& modelPar)
    : serialNumber(nextSerialNumber++)
    , model("Unknown")
    , seatCount(0) // (0 allowed for UAVs)
{
    SetSeatCount(seatCountPar); // Will throw exception if seatCount is negative
    SetModel(modelPar); // Will throw exception if model is empty
}

// Constructor with specific serial number
CPlane::CPlane(int seatCount, const string& model, int serialNumber)
    : model(model)
    , seatCount(seatCount)
{
    if (seatCount < 0) {
        throw invalid_argument("Seat count cannot be negative");
    }
    
    this->serialNumber = serialNumber;
    // Update the static counter to be higher than this serial number
    if (serialNumber >= nextSerialNumber) {
        nextSerialNumber = serialNumber + 1;
    }
}

// File constructor
CPlane::CPlane(ifstream& inFile) : serialNumber(0), model(""), seatCount(0) {
    inFile >> serialNumber >> seatCount >> model;
    // Note: We don't increment nextSerialNumber here as this is loading existing data
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

const string& CPlane::GetModel() const { return model; }

int CPlane::GetSeatCount() const { return seatCount; }

// Setters
void CPlane::SetModel(const string& newModel) {
    if (newModel.empty()) {
        throw CCompStringException("Plane model cannot be empty");
    }
    model = newModel;
}

void CPlane::SetSeatCount(int newSeatCount) {
    if (newSeatCount < 0) {
        throw invalid_argument("Seat count must be non negative");
    }
    seatCount = newSeatCount;
}

// Assignment operator
void CPlane::operator=(const CPlane& other) {
    if (this != &other) {
        serialNumber = other.serialNumber;
        model = other.model;
        seatCount = other.seatCount;
    }
}

// Equality operator
bool CPlane::operator==(const CPlane& other) const {
    return serialNumber == other.serialNumber;
}

// Stream operators
void CPlane::toOs(ostream& os) const {}

// Stream operators
ostream& operator<<(ostream& os, const CPlane& plane) {
    os << "Plane: " << plane.GetSerialNumber() << " Model: " << plane.GetModel()
        << " Seats: " << plane.GetSeatCount() << endl;
    plane.toOs(os);
    return os;
}

// Increment operator - Prefix increment
const CPlane& CPlane::operator++() {
    seatCount++;
    return *this;
}

// Increment operator - Postfix increment
CPlane CPlane::operator++(int) {
    CPlane temp(*this);
    seatCount++;
    return temp;
}

CPlane* CPlane::Clone() const {
    return new CPlane(*this);
}

// Static methods for ID persistence
void CPlane::SaveLastSerialNumber(ofstream& outFile) {
    outFile << nextSerialNumber << endl;
}

void CPlane::LoadLastSerialNumber(ifstream& inFile) {
    inFile >> nextSerialNumber;
}

void CPlane::SetNextSerialNumber(int value) { nextSerialNumber = value; }

int CPlane::GetLastSerialNumber() { return nextSerialNumber; }