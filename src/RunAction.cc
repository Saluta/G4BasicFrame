#include "RunAction.hh"

#include "G4Run.hh"

RunAction::RunAction()
: G4UserRunAction()
{

}

RunAction::~RunAction()
{

}

void RunAction::BeginOfRunAction(const G4Run*)
{ 
    G4Random::setTheSeed(time(nullptr));
}

void RunAction::EndOfRunAction(const G4Run* )
{

}


