#ifndef TrackingAction_HH
#define TrackingAction_HH 1

#include "globals.hh"
#include "G4UserTrackingAction.hh"

class G4Track;

class TrackingAction : public G4UserTrackingAction
{
  public:
    TrackingAction();
    virtual ~TrackingAction();

    virtual void  PreUserTrackingAction(const G4Track*);
    virtual void PostUserTrackingAction(const G4Track*);

    void AddEdep(G4double addE) {fEdep += addE;}

private:
    G4double fEdep;
};


#endif
