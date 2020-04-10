#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"
#include "G4StepLimiterPhysics.hh"

PhysicsList::PhysicsList()
: G4VModularPhysicsList()
{
    G4int verb = 0;

    RegisterPhysics(new G4EmStandardPhysics(verb));
}

PhysicsList::~PhysicsList()
{

}

void PhysicsList::SetCuts()
{
    SetCutsWithDefault();
}
