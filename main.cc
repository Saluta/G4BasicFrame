#include "G4UIExecutive.hh"
#include "G4VModularPhysicsList.hh"
#include "G4UImanager.hh"

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "PhysicsList.hh"

int main(int argc, char ** argv)
{
  // interaction, we need ui.
  G4UIExecutive *ui = new G4UIExecutive(argc, argv);

  // set runManager
#ifdef G4MULTITHREADED
  G4MTRunManager * runManager = new G4MTRunManager;
#else
  G4RunManager * runManager = new G4RunManager;
#endif
  
  // set mandatory init class
  // GEOmetry
  runManager->SetUserInitialization(new DetectorConstruction);

  // physics list
  G4VModularPhysicsList * physicsList = new PhysicsList;
  runManager->SetUserInitialization(physicsList);
  
  // user Action
  runManager->SetUserInitialization(new ActionInitialization);

  // need no visManager for visualization in this case;
  // UImanager to execute some initial commands
  G4UImanager * UImanager = G4UImanager::GetUIpointer();
  UImanager->ApplyCommand("/control/execute init.mac");

  // start the interaction between program and user
  ui->SessionStart();

  // do clear.
  delete ui;
  delete runManager;
}
