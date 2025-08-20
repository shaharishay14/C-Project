#pragma once

#include <string>
#include <iostream>
using namespace std;

class CFlightCompany 
{
private:
    string name;

public:
    CFlightCompany() = delete; // Disables the default constructor

    // Constructor: Initializes the flight company with a name
    CFlightCompany(const string& name);

    // Copy constructor and destructor
    CFlightCompany(const CFlightCompany& other);
    ~CFlightCompany();

	// Getters
    const string& GetName() const;

	// Setters
	void SetName(const string& newName);

	// Print the flight company details
    void Print() const;
};
