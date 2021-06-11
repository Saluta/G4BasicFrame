#include "PrimaryGeneratorAction.hh"

#include "G4GeneralParticleSource.hh"
#include "G4Event.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fGPS(nullptr)
{
  fGPS = new G4GeneralParticleSource();
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fGPS;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event * aEvent)
{
  fGPS->GeneratePrimaryVertex(aEvent);
}
