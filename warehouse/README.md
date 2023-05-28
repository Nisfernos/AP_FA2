# Warehouse

## About
This project is an implimantation of a simple warehouse.
It was made for "Summatieve opdracht 2.2: Domain Design & Implementatie".
This project consists of several hpp and cpp files for different classes.
In these files classes are made for a simple warehouse consisting of employees, shelves and pallets.
It also has main.cpp, and testWarehouse.cpp for testing the functionality of the classes.

## How to run
1. Download the fork of this repository.
2. Open the folder Warehouse in an editor (VSCode, is the only editor it is tested on)
3. For the makefile settings set "Build target" to [all]
4. Set "Launch target" to [main] or [test]
5. Run the code from the "Makefile: project outline".

## Credits
Frank van Leijsen
Studentnummer: 1843626
Work: Everything

Tristan de Bree helped on two points: 
-std::swap() in pallets.cpp (I had a,b = b,a, which doesn't work)
-reference & in the for loops in warehouse.cpp::pickItems() (without it, the pallets aren't actually changed)