#ifndef RUN_HH
#define RUN_HH

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4UserRunAction.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4Run.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/g4root.hh"

class MyRunAction : public G4UserRunAction
{
public:
    MyRunAction();
    ~MyRunAction();
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif
