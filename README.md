# Artificial Pancreas
This project aims to simulate an artificial pancreas through an arduino.

In this repository you can find:

    - The LabView code for Arduino for the pancreas simulation

    - The codes and plots for the data analysis  


To clone everything:

`git clone https://github.com/ciavanick/ArtificialPancreas.git`

## LabView code
In the LabView folder it can be found the code related to the artificial pancreas simulation.
The code is developed to work with Arduino UNO (or compatible microcontroller boards.

## Plots and data anilysis
In the Graph folder it can be found the codes (that work with the framework ROOT CERN) used for the data analysis, in particular there are two important scripts: `dataset.cpp` and `Analysis.C`.
`dataset.cpp` take all the .csv files with all the data and: define the TGraph objects, create the raw plot for each object, save all the the TGraph objects in a .root file.
`Analysis.C` take the TGraph objects from the .root file (`graph.root`), fit them properly and plot them with the right cosmetic.
