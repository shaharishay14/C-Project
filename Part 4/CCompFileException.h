#pragma once

#include "CFlightCompException.h"

class CCompFileException : public CFlightCompException {
private:
  string fileName;

public:
  CCompFileException(const string& fileName) : fileName(fileName) {}
  virtual const string show() const override { return "Error in file: " + fileName + "\n"; }
};