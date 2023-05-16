#ifndef ACTION_HH
#define ACTION_HH

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4VUserActionInitialization.hh"


#include "generator.hh"
#include "run.hh"

/*
#include "run.hh"
#include "event.hh"
#include "stepping.hh"

*/

class MyActionInitialization : public G4VUserActionInitialization
{
public:
    MyActionInitialization();
    ~MyActionInitialization();
    
    //virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif
