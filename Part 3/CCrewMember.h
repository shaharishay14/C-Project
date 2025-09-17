#pragma once

#include "CAddress.h"
#include <stdexcept>
#include <string>

class CCrewMember {
protected:
  static int nextId;
  string name;
  CAddress *address;
  int airTime;


public:

  CCrewMember() = delete; // Disables the default constructor

  // Constructor: Initializes the crew member with name, address and optional
  // default air time (0)
  CCrewMember(const string &name, CAddress *address = nullptr, int airTime = 0);

  // Constructor: Initializes the crew member with name and optional air time
  CCrewMember(const string &name, int airTime = 0);

  // Copy-ctor & Dtor
  CCrewMember(const CCrewMember &other);
  ~CCrewMember();

  // Getters
  const string &GetName() const;
  int GetAirTime() const;
  const CAddress *GetAddress() const;


  // Setters/Updates
  void SetName(const string &newName);
  void SetAddress(CAddress *newAddress);


  // Assignment operator
  void operator=(const CCrewMember &other);

  // Addition operator
  virtual bool operator+=(int deltaMinutes);

  // Equality operator
  bool operator==(const CCrewMember &other) const;

  // Stream operators
  virtual void toOs(ostream &os) const;
  friend ostream &operator<<(ostream &os, const CCrewMember &crewMember);

  // Virtual functions
  virtual void ReceiveGift(ostream &os) = 0;
  virtual void ReceiveUniform(ostream &os) = 0;
};