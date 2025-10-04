#pragma once

#include "CPlane.h"
#include "CFlightCompException.h"

class CCargo : public CPlane {
private:
    float maxKg;
    float maxVolume;
    float currentKg;
    float currentVolume;

public:
    CCargo() = delete; // Disables the default constructor

    // Constructor: Initializes the cargo with seats, model, max kg and max volume
    CCargo(int seats, const string& model, float maxKg, float maxVolume);
    
    // File constructor
    CCargo(ifstream& inFile);

    // Copy constructor and destructor
    CCargo(const CCargo& other);
    ~CCargo();

    // Getters
    float GetMaxKg() const;
    float GetMaxVolume() const;
    float GetCurrentKg() const;
    float GetCurrentVolume() const;

    // Setters
    void SetMaxKg(float maxKg);
    void SetMaxVolume(float maxVolume);
    void SetCurrentKg(float currentKg);
    void SetCurrentVolume(float currentVolume);

    // Assignment operator
    void operator=(const CCargo& other);

    // Stream operators
    virtual void toOs(ostream& os) const override;

    bool Load(float kg, float volume);

    void UpdateMinutesMessage(int deltaMinutes, ostream& os) const;

    CPlane* Clone() const override;

};