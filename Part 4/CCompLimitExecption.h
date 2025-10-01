#pragma once

#include "CFlightCompException.h"

class CCompLimitExecption : public CFlightCompException {
private:
  int maxLimit;

public:
  CCompLimitExecption(const int maxLimit) : maxLimit(maxLimit) {}
  virtual const string show() const override { return "Max limit reached: " + to_string(maxLimit) + "\n"; }
};