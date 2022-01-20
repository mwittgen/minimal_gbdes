#include "Instrument.h"

#include <string>
#include <iostream>
#include <sstream>

int main() {
   std::string stringvalues = "125 320 512 750 333";
   std::istringstream iss (stringvalues);
   
   Instrument testI("test");
}
