#include "ActionInitialization.hh"

#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "TracingAction.hh"
#include "SteppingAction.hh"

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

  // Action for run, event, track and step
  RunAction * runAction = new RunAction;
  SetUserAction(runAction);

  EventAction * eventAction = new EventAction;
  SetUserAction(eventAction);

  TrackingAction * trackingAction = new TrackingAction;
  SetUserAction(trackingAction);

  SteppingAction * steppingAction = new SteppingActionn;
  SetUserAction(steppingAction);
}
