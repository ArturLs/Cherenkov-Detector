#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4VUserDetectorConstruction.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4VPhysicalVolume.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4LogicalVolume.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4Box.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4Tubs.hh"

#include "G4PVPlacement.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4NistManager.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4SystemOfUnits.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4GenericMessenger.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4OpticalSurface.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4LogicalBorderSurface.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4LogicalSkinSurface.hh"

#include "detector.hh"

#include "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4GenericMessenger.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    /*G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }*/

    virtual G4VPhysicalVolume *Construct();
    /*void ConstructCherenkov();
    void ConstructScintillator();
    void ConstructTOF();
    void ConstructAtmosphere();*/

    
    
private:
    G4LogicalVolume *logicDetector;
    virtual void ConstructSDandField();
    
    G4int nCols, nRows;
    
    G4GenericMessenger *fMessenger; 
};

#endif
