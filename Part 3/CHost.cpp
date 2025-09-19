#include "CHost.h"

// Constructor: Initializes the host with name, host type, address and optional air time
CHost::CHost(const string &name, eHostType hostType, CAddress *address, int airTime)
    : CCrewMember(name, address, airTime) {
  SetHostType(hostType);
}

// Constructor: Initializes the host with name and host type
CHost::CHost(const string &name, eHostType hostType)
    : CCrewMember(name, 0) {
  SetHostType(hostType);
}

// Copy constructor
CHost::CHost(const CHost &other) : CCrewMember(other) {
  SetHostType(other.hostType);
}

// Destructor
CHost::~CHost() {}

// Setters
void CHost::SetHostType(eHostType hostType) {
  this->hostType = hostType;
}

// Getters
CHost::eHostType CHost::GetHostType() const { return hostType; }

// Assignment operator
void CHost::operator=(const CHost &other) {
  if (this != &other) {
    CCrewMember::operator=(other);
    SetHostType(other.hostType);
  }
}

// Stream operators
void CHost::toOs(ostream &os) const {
  os << "Host: " << hostTypeStrings[hostType] << GetName() << " Minutes: " <<
      to_string(GetAirTime()) << endl;
}

void CHost::ReceiveGift(ostream &os) {
  os << GetName() << " thanking the company for receiving the holiday gift. i was'nt expecting it" << endl;
}

void CHost::ReceiveUniform(ostream &os) {
  os << GetName() << " I think the uniform is very nice" << endl;
}

CCrewMember* CHost::Clone() const {
  return new CHost(*this);
}