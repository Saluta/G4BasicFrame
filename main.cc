#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"
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
  G4UIExecutive *ui = nullptr;
  if(argc==1)
  {
    ui = new G4UIExecutive(argc, argv);
  }

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

  // VisManager for visualization in this case;
  G4VisManager * visManager = new G4VisExecutive;
  visManager->Initialize();
  
  // UImanager to execute some initial commands
  G4UImanager * UImanager = G4UImanager::GetUIpointer();
  
  if(!ui)
  {
    // batch
    G4String cmd = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(cmd+fileName);
  }
  else
  {
    // interactive mode
    UImanager->ApplyCommand("/control/execute init.mac");
    ui->SessionStart();
    delete ui;
  }
  
  // do clear.
  delete visManager;
  delete runManager;
}
