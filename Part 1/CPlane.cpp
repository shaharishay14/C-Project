#include "Plane.h"

// Validates the plane's data (serial number, model, and seat count)
void CPlane::ValidateData() const
{
    if (serialNumber <= 0) {
        throw std::invalid_argument("Serial number must be positive");
    }
    if (model.empty())
    {
        throw std::invalid_argument("Model cannot be empty");
    }
    if (seatCount <= 0)
    {
        throw std::invalid_argument("Seat count must be positive");
    }
}

// Constructor: Initializes the plane and validates the data
CPlane::CPlane(int serialNumber, int seatCount, const string& model)
    : serialNumber(serialNumber), seatCount(seatCount), model(model)
{
    ValidateData();
}

// Default copy constructor 
CPlane::CPlane(const CPlane& other) = default;

// Default destructor
CPlane::~CPlane() = default;

// Getters
int CPlane::GetSerialNumber() const
{
    return serialNumber;
}

string CPlane::GetModel() const 
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
    if (newModel.empty())
    {
        throw std::invalid_argument("Model cannot be empty");
    }
    model = newModel;
}

void CPlane::SetSeatCount(int newSeatCount) 
{
    if (newSeatCount <= 0)
    {
        throw std::invalid_argument("Seat count must be positive number");
    }
    seatCount = newSeatCount;
}

void CPlane::SetFlightNumber(int sn)
{
	if (sn <= 0)
	{
		throw std::invalid_argument("Serial number must be positive number");
	}
	serialNumber = sn;
}

// Checks if two planes are equal based on their serial numbers
bool CPlane::IsEqual(const CPlane& other) const 
{
    return serialNumber == other.serialNumber; 
}

// Prints the plane's details
void CPlane::Print() const {
    std::cout << "Plane " << std::to_string(serialNumber) << " degem: " << model <<
        " seats: " << std::to_string(seatCount) << endl;
}
