#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4VModularPhysicsList.hh"
#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4EmStandardPhysics.hh"
#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4OpticalPhysics.hh"
#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4RadioactiveDecayPhysics.hh"
#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4DecayPhysics.hh"

class MyPhysicsList : public G4VModularPhysicsList
{
public:
    MyPhysicsList();
    ~MyPhysicsList();
};

#endif

