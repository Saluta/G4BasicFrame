#include "DetectorConstruction.hh"

#include "G4VPhysicalVolume.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

// Empty Constructor
DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction()
{ }

// Empty Destructor
DetectorConstruction::~DetectorConstruction()
{ }

// Geo-construct
G4VPhysicalVolume * DetectorConstruction::Construct()
{
  G4NistManager * nist = G4NistManager::Instance();
  G4bool checkOverlaps = true;

  // solid item Set
  G4double worldSize = 1.0*m;
  G4Box * solidWorld = new G4Box("World",
		                  0.5*worldSize, 
				  0.5*worldSize,
				  0.5*worldSize);

  // logical item Set
  G4Material * worldMat = nist->FindOrBuildMaterial("G4_AIR");
  G4LogicalVolume * logicWorld = 
    new G4LogicalVolume(solidWorld, worldMat, "World");

  // physical item Set
  G4VPhysicalVolume * physWorld = 
    new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 
		      0, false, 0, checkOverlaps);


  // construct Done
  return physWorld;
}
