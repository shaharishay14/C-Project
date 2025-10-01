#pragma once

#include <exception>
#include <string>

using namespace std;

class CFlightCompException : public exception {
public:
 virtual const string show() const { return "Failed while loading the flight company"; }
};