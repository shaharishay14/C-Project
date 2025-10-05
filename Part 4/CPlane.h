#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "CFlightCompException.h"
using namespace std;

class CPlane {
private:
    static int nextSerialNumber; // Auto-incrementing serial counter
    int serialNumber;
    string model;
    int seatCount;
    static const int START_SERIAL = 100;

public:
    CPlane() = delete; // Disables the default constructor

    // Constructor: Initializes the plane with seat count and model
    // Serial number is automatically assigned
    CPlane(int seatCount, const string &model);

    // Constructor: Initializes the plane with seat count, model, and specific serial number
    CPlane(int seatCount, const string& model, int serialNumber);
    
    // File constructor
    CPlane(ifstream& inFile);

    // Copy constructor and destructor
    CPlane(const CPlane& other);
    virtual ~CPlane();

    // Getters
    int GetSerialNumber() const;
    const string& GetModel() const;
    int GetSeatCount() const;

    // Setters
    void SetModel(const string& newModel);
    void SetSeatCount(int newSeatCount);

    // Assignment operator
    void operator=(const CPlane& other);

    // Equality operator
    bool operator==(const CPlane& other) const;

    // Stream operators
    virtual void toOs(ostream& os) const;
    friend ostream& operator<<(ostream& os, const CPlane& plane);

    // Increment operator - Prefix increment
    const CPlane& operator++();

    // Increment operator - Postfix increment
    CPlane operator++(int);

    virtual CPlane* Clone() const;
    
    // Static methods for ID persistence
    static void SaveLastSerialNumber(ofstream& outFile);
    static void LoadLastSerialNumber(ifstream& inFile);
    static void SetNextSerialNumber(int value);
    static int GetLastSerialNumber();

};