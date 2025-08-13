#include "CPlane.h"

void CPlane::validateData() const
{
    if (serialNumber < 0) {
        throw std::invalid_argument("Serial number must be non negative");
    }
    if (model.empty()) {
        throw std::invalid_argument("Model cannot be empty");
    }
    if (seats < 0) {
        throw std::invalid_argument("Seats must be non negative");
    }
}

CPlane::CPlane(int serialNumber, const std::string& model, int seats)
    : serialNumber(serialNumber), model(model), seats(seats)
    {
        validateData();
    }

CPlane::CPlane(const CPlane& other)
    : serialNumber(other.serialNumber), model(other.model), seats(other.seats)
    {

    }

CPlane::~CPlane() {}

int CPlane::getSerialNumber() const
{
    return serialNumber;
}

std::string CPlane::getModel() const
{
    return model;
}

int CPlane::getSeats() const
{
    return seats;
}

std::string CPlane::print() const
{
    return "Serial Number: " + std::to_string(serialNumber) + ", Model: " + model + ", Seats: " + std::to_string(seats);
}

bool CPlane::isEqual(const CPlane& other) const
{
    return serialNumber == other.serialNumber && model == other.model && seats == other.seats;
}