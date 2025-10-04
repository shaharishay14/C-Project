#pragma once

#include <exception>
#include <string>
#include <iostream>

using namespace std;

class CFlightCompException : public exception {
public:
    virtual void Show() const = 0;  // Pure virtual
};