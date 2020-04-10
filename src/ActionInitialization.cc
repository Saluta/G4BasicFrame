#include "ActionInitialization.hh"

#include "PrimaryGeneratorAction.hh"
#include "G4UserRunAction.hh"

ActionInitialization::ActionInitialization()
 : G4VUserActionInitialization()
{ }

ActionInitialization::~ActionInitialization()
{ }

void ActionInitialization::BuildForMaster() const
{
  SetUserAction(new G4UserRunAction);
}

void ActionInitialization::Build() const
{
  // Action for primary generating.
  SetUserAction(new PrimaryGeneratorAction);
  
  SetUserAction(new G4UserRunAction);
}
