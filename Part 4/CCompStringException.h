#pragma once

#include "CFlightCompException.h"

class CCompStringException : public CFlightCompException {
private:
  string errorMessage;

public:
  CCompStringException(const string& errorMessage) : errorMessage(errorMessage) {}
  virtual const string show() const override { return errorMessage + "\n"; }
};