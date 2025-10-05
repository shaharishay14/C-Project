#pragma once

#include "CFlightCompException.h"
#include <string>
#include <iostream>

using namespace std;

class CCompStringException : public CFlightCompException {
private:
    string problem;

public:
    CCompStringException(const string& problem) : problem(problem) {}
    
    virtual void Show() const override {
        cout << "String Exception: " << problem << endl;
    }
};