#include "EventAction.hh"
#include "Analysis.hh"


EventAction::EventAction()
: G4UserEventAction(),
  fEdep(0)
{

}

EventAction::~EventAction()
{

}

void EventAction::BeginOfEventAction(const G4Event *)
{
    fEdep = 0;
}

void EventAction::EndOfEventAction(const G4Event *)
{
    // fill the collected energy deposition to the histogram (spectrum)
    G4AnalysisManager * analysisManager = G4AnalysisManager::Instance();

    G4int EspecID = analysisManager->GetH1Id("eDepSpec");
    analysisManager->FillH1(EspecID, fEdep);
}
