#pragma once

#include <string>
#include <iostream>
using namespace std;

class CPlane 
{
private:
    int    serialNumber;
    string model;
    int    seatCount;

public:
    CPlane() = delete; // Disables the default constructor

    // Constructor: Initializes the plane with serial number, seat count, and model
    CPlane(int serialNumber, int seatCount, const string& model);

	// Copy constructor and destructor
    CPlane(const CPlane& other);
    ~CPlane();

    // Getters
    int           GetSerialNumber() const;
    const string& GetModel() const;
    int           GetSeatCount() const;

    // Setters
    void SetModel(const string& newModel);
    void SetSeatCount(int newSeatCount);
    void SetSerialNumber(int sn);

	// Check if two planes are equal
    bool IsEqual(const CPlane& other) const;

	//  Print plane information
    void Print() const;
};
