#ifndef PHYSICSLIST_H
#define PHYSICSLIST_H 1

#include "G4VModularPhysicsList.hh"

class PhysicsList : public G4VModularPhysicsList
{
  public:
    PhysicsList();
    virtual ~PhysicsList();

  public:
    // virtual void ConstructProcess();
    // virtual void ConstructParticle();
    
    virtual void SetCuts();
};


#endif
