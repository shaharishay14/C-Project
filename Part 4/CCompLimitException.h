#pragma once

#include "CFlightCompException.h"
#include <iostream>

using namespace std;

class CCompLimitException : public CFlightCompException {
private:
    int maxAmount;

public:
    CCompLimitException(int maxAmount) : maxAmount(maxAmount) {}
    
    virtual void Show() const override {
        cout << "Limit Exception: Valid range is 0 to " << maxAmount << endl;
    }
};