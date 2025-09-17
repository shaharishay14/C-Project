#include "CHost.h"

// Constructor: Initializes the host with name, host type, address and optional air time
CHost::CHost(const string &name, eHostType hostType, CAddress *address, int airTime)
    : CCrewMember(name, address, airTime) {
  SetHostType(hostType);
}

// Copy constructor
CHost::CHost(const CHost &other) : CCrewMember(other) {
  SetHostType(other.hostType);
}