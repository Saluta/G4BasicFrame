// this is a Detector Construction class header

#ifndef DETECTORCONSTRUCTION_H
#define DETECTORCONSTRUCTION_H 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;

class DetectorConstruction: public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    virtual ~DetectorConstruction();
    virtual G4VPhysicalVolume * Construct();
};


#endif

