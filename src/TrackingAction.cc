#include "TrackingAction.hh"
#include "Analysis.hh"

#include "G4Track.hh"
#include "G4TrackingManager.hh"
#include "G4VProcess.hh"
#include "G4SystemOfUnits.hh"


TrackingAction::TrackingAction()
 : G4UserTrackingAction(),
   fEdep(0.)
{
}

TrackingAction::~TrackingAction()
{

}

void TrackingAction::PreUserTrackingAction(const G4Track * )
{
    fEdep = 0;
}

void TrackingAction::PostUserTrackingAction(const G4Track * )
{
//    // fill the collected energy deposition to the histogram (spectrum)
//    G4AnalysisManager * analysisManager = G4AnalysisManager::Instance();

//    G4int EspecID = analysisManager->GetH1Id("RingESpec");
//    analysisManager->FillH1(EspecID, fEdep);
}
