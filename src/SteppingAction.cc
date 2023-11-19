#include "SteppingAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "TrackingAction.hh"
#include "Analysis.hh"

#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4VProcess.hh"


SteppingAction::SteppingAction(EventAction * eveAct)
 : G4UserSteppingAction(),
   fEventAction(eveAct)
{

}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
    G4VPhysicalVolume * prePointPV =
            step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();

    if(prePointPV == nullptr)
    {
        return;
    }

    G4String stepPVName = prePointPV->GetName();
    if(stepPVName == "physDetCore")
    {
        fEventAction->AddEdep(step->GetTotalEnergyDeposit());
    }
}
