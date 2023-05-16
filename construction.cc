#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{

   fMessenger = new G4GenericMessenger(this, "/detector/", "Detector Construction");
   
   fMessenger->DeclareProperty("nCols", nCols, "Number of columns");
   fMessenger->DeclareProperty("nRows", nRows, "Number of rows");
   
   
   nCols = 100; //Define a quantided de detec
   nRows = 100;

}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
   
   G4NistManager *nist = G4NistManager::Instance();
   
   G4Material *SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2);
   SiO2->AddElement(nist->FindOrBuildElement("Si"), 1);
   SiO2->AddElement(nist->FindOrBuildElement("O"), 2);
   
   G4Material *H2O = new G4Material("H2O", 1.000*g/cm3, 2);
   H2O->AddElement(nist->FindOrBuildElement("H"), 2);
   H2O->AddElement(nist->FindOrBuildElement("O"), 1);
   
   G4Element *C = nist->FindOrBuildElement("C");
   
   G4Material *aerogel = new G4Material("aerogel", 0.200*g/cm3, 3);
   aerogel->AddMaterial(SiO2, 62.5*perCent);
   aerogel->AddMaterial(H2O, 37.4*perCent);
   aerogel->AddElement(C, 0.1*perCent);
   
   G4double energy[2] = {1.239841939*eV/0.2, 1.239841939*eV/0.9};
   G4double rindexAerogel[2] = {1.1, 1.1};
   G4double rindexWorld[2] = {1.0, 1.0};
   
   G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
   mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2);
   
   aerogel->SetMaterialPropertiesTable(mptAerogel);
   
   G4Material *worldmat = nist->FindOrBuildMaterial("G4_AIR");
   
   G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
   mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);
   
   worldmat->SetMaterialPropertiesTable(mptWorld);
   
   G4double xWorld = 0.5*m;
   G4double yWorld = 0.5*m;
   G4double zWorld = 0.5*m;   

   
   G4Box *solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld);
   
   G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldmat, "logicalWorld");
   
   G4VPhysicalVolume *physWorld = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.), logicWorld, "phyWorld", 0, false, 0, true);
   
   
   G4Box *solidRadiator = new G4Box("SolidRadiator",0.4*m ,0.4*m, 0.01*m);
   
   G4LogicalVolume *LogicRadiator = new G4LogicalVolume(solidRadiator, aerogel, "LogicRadiator");
   
   G4VPhysicalVolume *physRadiator = new G4PVPlacement(0,G4ThreeVector(0.,0.,0.25*m), LogicRadiator, "physRadiator", logicWorld, false, 0, true);
   
    
   G4Box *solidDetector = new G4Box("SolidDetector", xWorld/nRows, yWorld/nCols, 0.01*m);
   
   logicDetector = new G4LogicalVolume(solidDetector, worldmat, "logicDetector");
   
   for(G4int i = 0; i< nRows; i++)
   {
         for(G4int j  = 0; j < nCols; j++)
         {
            
             G4VPhysicalVolume *physDetector = new G4PVPlacement(0,G4ThreeVector(-0.5*m+(i+0.5)*m/nCols, -0.5*m+(j+0.5)*m/nRows,0.49*m), logicDetector, "physDetector", logicWorld, false, j+i*100, true);
          
         } 
   
   }
   
   
   
   return physWorld;
}




void MyDetectorConstruction::ConstructSDandField()
{

  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
  
  logicDetector->SetSensitiveDetector(sensDet);

}







