#pragma once

#include "CFlightCompException.h"
#include <string>
#include <iostream>

using namespace std;

class CCompFileException : public CFlightCompException {
private:
    string filename;

public:
    CCompFileException(const string& filename) : filename(filename) {}
    
    virtual void Show() const override {
        cout << "File Exception: Problem with file '" << filename << "'" << endl;
    }
};