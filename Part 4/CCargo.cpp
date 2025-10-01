#include "CCargo.h"

// Constructor
CCargo::CCargo(int seats, const string& model, float maxKg, float maxVolume)
    : CPlane(seats, model), maxKg(maxKg), maxVolume(maxVolume), currentKg(0),
    currentVolume(0) {
    SetMaxKg(maxKg);
    SetMaxVolume(maxVolume);
    SetCurrentKg(0);
    SetCurrentVolume(0);
}

// Copy constructor
CCargo::CCargo(const CCargo& other)
    : CPlane(other), maxKg(other.maxKg), maxVolume(other.maxVolume),
    currentKg(other.currentKg), currentVolume(other.currentVolume)
{
}

// Destructor
CCargo::~CCargo() {}

// Getters
float CCargo::GetMaxKg() const { return maxKg; }
float CCargo::GetMaxVolume() const { return maxVolume; }
float CCargo::GetCurrentKg() const { return currentKg; }
float CCargo::GetCurrentVolume() const { return currentVolume; }

// Setters
void CCargo::SetMaxKg(float maxKg) {
    if (maxKg >= 0) {
        this->maxKg = maxKg;
    }
}

void CCargo::SetMaxVolume(float maxVolume) {
    if (maxVolume >= 0) {
        this->maxVolume = maxVolume;
    }
}
void CCargo::SetCurrentKg(float currentKg) {
    if (currentKg >= 0) {
        this->currentKg = currentKg;
    }
}
void CCargo::SetCurrentVolume(float currentVolume) {
    if (currentVolume >= 0) {
        this->currentVolume = currentVolume;
    }
}

// Assignment operator
void CCargo::operator=(const CCargo& other) {
    if (this != &other) {
        CPlane::operator=(other);
        maxKg = other.maxKg;
        maxVolume = other.maxVolume;
        currentKg = other.currentKg;
        currentVolume = other.currentVolume;
    }
}

// Load cargo
bool CCargo::Load(float kg, float volume) {
    if (kg >= 0 && volume >= 0) {
        if (currentKg + kg > maxKg || currentVolume + volume > maxVolume) {
            return false;
        }
        currentKg += kg;
        currentVolume += volume;
        return true;
    }
    return false;
}

// Update minutes after flight takes off
void CCargo::UpdateMinutesMessage(int deltaMinutes, ostream& os) const {
    if (deltaMinutes > 0) {
        os << "Need to add " << deltaMinutes << " to my log book" << endl;
    }
}

// Stream operators
void CCargo::toOs(ostream& os) const {
    os << "Cargo " << " Max Kg: " << GetMaxKg() << " Max Volume: " << GetMaxVolume() << " Current Kg: " << GetCurrentKg() << " Current Volume: " << GetCurrentVolume() << endl;
}

CPlane* CCargo::Clone() const {
    return new CCargo(*this);
}