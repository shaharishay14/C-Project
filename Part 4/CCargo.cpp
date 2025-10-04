#include "CCargo.h"
#include "CCompStringException.h"
#include "CCompLimitException.h"
#include "CCompFileException.h"

// Constructor
CCargo::CCargo(int seats, const string& model, float maxKg, float maxVolume)
    : CPlane(seats, model), maxKg(maxKg), maxVolume(maxVolume), currentKg(0),
    currentVolume(0) {
    SetMaxKg(maxKg);
    SetMaxVolume(maxVolume);
    SetCurrentKg(0);
    SetCurrentVolume(0);
}

// File constructor
CCargo::CCargo(ifstream& inFile) : CPlane(inFile), maxKg(0), maxVolume(0), currentKg(0), currentVolume(0) {
    inFile >> maxKg >> maxVolume >> currentKg >> currentVolume;
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
    if (maxKg < 0) {
        throw CCompStringException("MaxKg cannot be negative: " + to_string(maxKg));
    }
    this->maxKg = maxKg;
}

void CCargo::SetMaxVolume(float maxVolume) {
    if (maxVolume < 0) {
        throw CCompStringException("MaxVolume cannot be negative: " + to_string(maxVolume));
    }
    this->maxVolume = maxVolume;
}

void CCargo::SetCurrentKg(float currentKg) {
    if (currentKg < 0) {
        throw CCompStringException("CurrentKg cannot be negative: " + to_string(currentKg));
    }
    this->currentKg = currentKg;
}

void CCargo::SetCurrentVolume(float currentVolume) {
    if (currentVolume < 0) {
        throw CCompStringException("CurrentVolume cannot be negative: " + to_string(currentVolume));
    }
    this->currentVolume = currentVolume;
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
    // Validate input parameters
    if (kg < 0) {
        throw CCompStringException("Load kg cannot be negative: " + to_string(kg));
    }
    if (volume < 0) {
        throw CCompStringException("Load volume cannot be negative: " + to_string(volume));
    }
    
    // Check capacity limits
    if (currentKg + kg > maxKg) {
        throw CCompStringException("Exceeds max weight capacity: " + to_string(currentKg + kg) + " > " + to_string(maxKg));
    }
    if (currentVolume + volume > maxVolume) {
        throw CCompStringException("Exceeds max volume capacity: " + to_string(currentVolume + volume) + " > " + to_string(maxVolume));
    }
    
    // Load the cargo
    currentKg += kg;
    currentVolume += volume;
    return true;
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