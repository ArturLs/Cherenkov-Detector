#include  <iostream>

#include  "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4RunManager.hh"

#include  "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4UImanager.hh"

#include  "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4UIExecutive.hh"

#include  "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4VisManager.hh"

#include  "/home/artur/Documents/geant4/geant4.10.06.p03/geant4.10.06-install/include/Geant4/G4VisExecutive.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"

int main(int argc, char** argv)
{
   G4RunManager *runManager = new G4RunManager();
   
   runManager->SetUserInitialization(new MyPhysicsList());   
   runManager->SetUserInitialization(new MyDetectorConstruction());
   runManager->SetUserInitialization(new MyActionInitialization());
      
   runManager->Initialize();
   
   G4UIExecutive *ui = 0;
   
   if(argc ==1)
   {
       ui = new G4UIExecutive(argc, argv);
   }
   
   G4VisManager *visManager =  new G4VisExecutive();
   visManager->Initialize();
   
   G4UImanager *UImanager =  G4UImanager::GetUIpointer();
   
   if(ui)
   {
   
       UImanager->ApplyCommand("/control/execute vis.mac");
       ui->SessionStart();
   }
   else
   {
   
     G4String command = "/control/execute";
     G4String fileName = argv[1];
     UImanager->ApplyCommand(command+fileName); //rodar um arquico junto, .mac 
     
   }
   
   
   return 0;
   
}

