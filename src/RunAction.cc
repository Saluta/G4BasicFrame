#include "RunAction.hh"
#include "Analysis.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction()
: G4UserRunAction()
{
    // Root Analysis configuring
    G4AnalysisManager * analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);

    // create the 1D histogram for energy spectrum
    analysisManager->CreateH1("eDepSpec", "energy spectrum of detector",
                              100, 10.*keV, 2.5*MeV);

}

RunAction::~RunAction()
{

}

void RunAction::BeginOfRunAction(const G4Run*)
{ 
    G4Random::setTheSeed(time(nullptr));

    G4AnalysisManager * analysisManager = G4AnalysisManager::Instance();
    // set save file
    analysisManager->OpenFile("ESpec.root");
}

void RunAction::EndOfRunAction(const G4Run* )
{
    // Write and close the root file
    G4AnalysisManager * analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}


