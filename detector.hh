#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4VSensitiveDetector.hh"
#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4RunManager.hh"
#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4SystemOfUnits.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/g4root.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();
    
private:
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);
    
    G4PhysicsOrderedFreeVector *quEff;
};

#endif
