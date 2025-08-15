#include "CPlane.h"

using namespace std;

void CPlane::validateData() const
{
    if (serialNumber < 0) {
        throw invalid_argument("Serial number must be non negative");
    }
    if (model.empty()) {
        throw invalid_argument("Model cannot be empty");
    }
    if (seats < 0) {
        throw invalid_argument("Seats must be non negative");
    }
}

CPlane::CPlane(int serialNumber, const string& model, int seats)
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

string CPlane::getModel() const
{
    return model;
}

int CPlane::getSeats() const
{
    return seats;
}

string CPlane::print() const
{
    return "Serial Number: " + to_string(serialNumber) + ", Model: " + model + ", Seats: " + to_string(seats);
}

bool CPlane::isEqual(const CPlane& other) const
{
    return serialNumber == other.serialNumber && model == other.model && seats == other.seats;
}