#include <iostream>

#include "Plane.h"

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

CPlane::CPlane(int serialNumber, int seatCount, const std::string& model)
    : serialNumber(serialNumber), seatCount(seatCount), model(model)
{
    ValidateData();
}

CPlane::CPlane(const CPlane& other) = default;
CPlane::~CPlane() = default;

int CPlane::GetSerialNumber() const
{
    return serialNumber;
}

std::string CPlane::GetModel() const 
{
    return model;
}

int CPlane::GetSeatCount() const 
{
    return seatCount;
}

void CPlane::SetModel(const std::string& newModel) 
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

bool CPlane::IsEqual(const CPlane& other) const 
{
    return serialNumber == other.serialNumber; 
}

void CPlane::Print() const {
    std::cout << "Plane " << std::to_string(serialNumber) << " degem: " << model <<
        " seats: " << std::to_string(seatCount) << std::endl;
}
