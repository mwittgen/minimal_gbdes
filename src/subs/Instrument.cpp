#include "Instrument.h"

void Instrument::addDevice(std::string devName) {
        deviceNames.push_back(devName);
        //domains.push_back(devBounds);
        mapNames.push_back("");
        nDevices = deviceNames.size();
        //Assert(mapNames.size() == nDevices);
        //Assert(domains.size() == nDevices);
    }

