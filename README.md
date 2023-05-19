# Cherenkov-Detector

### Introduction

Device used to detect Cherenkov radiation, useful for identifying and measuring high-energy<br> 
charged particles such as protons, electrons and muons.

-----------------------------------------------------------------------------
### Instructions

- create a “build” directory:

`$ mkdir build`

- change to this directory:

`$ cd build`

- set the environment variables of your Geant4 version:

`$ source <path/to/geant4/directory>/bin/geant4.sh`

- use “cmake” to compile the source code:

`$ cmake ../source`

`$ make -jX install` (X=2,4,8 as number of cores to use in the compilation)

- execute the simulation:

`./sim`

-----------------------------------------------------------------------------
### Simulation

![Screenshot from 2023-05-18 23-34-54](https://github.com/ArturLs/Cherenkov-Detector/assets/102261011/3abfa000-b683-4e23-850b-be6bacfd2313)
