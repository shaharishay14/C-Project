#include "Plane.h"

// Constructor: Initializes the plane 
CPlane::CPlane(int serialNumberPar, int seatCountPar, const string& modelPar)
	: serialNumber(1)
    , seatCount(0) // (0 allowed for UAVs)
    , model("Unknown")
{
    SetSerialNumber(serialNumberPar); // ignores invalid
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

// Destructor
CPlane::~CPlane()
{
	// Nothing to release
}

// Getters
int CPlane::GetSerialNumber() const
{
    return serialNumber;
}

const string& CPlane::GetModel() const
{
    return model;
}

int CPlane::GetSeatCount() const 
{
    return seatCount;
}

// Setters
void CPlane::SetModel(const string& newModel) 
{
    if (!newModel.empty())
        model = newModel;
    // else: ignore invalid (leave as-is if empty)
}

void CPlane::SetSeatCount(int newSeatCount)
{
    if (newSeatCount >= 0)  
        seatCount = newSeatCount;
    // else: ignore invalid (leave as-is if it is negative)
}

void CPlane::SetSerialNumber(int sn)
{
    if (sn > 0)
        serialNumber = sn;
    // else: ignore invalid (leave as-is if it is non positive)
}

// Checks if two planes are equal based on their serial numbers
bool CPlane::IsEqual(const CPlane& other) const 
{
    return serialNumber == other.serialNumber; 
}

// Prints the plane's details
void CPlane::Print() const {
    cout << "Plane " << to_string(serialNumber) 
         << " degem: " << model 
         << " seats: " << to_string(seatCount) << endl;
}
