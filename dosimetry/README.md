# STOPPING POWER SIMULATION

This is a very simple simulation of a particle entering a material. We wrote a small C++ routine to automate the calculation of the stopping power, and to study the depence of the particle range on the initial energy. For the physics and detailed code explanation, head to the [dedicated website](http://ppsnippets.tk/) and click "Dosimetry".

This project contains:

* Two simulation source files, `simulation1.cpp` and `simulation2.cpp`
* The results of the simulations, `simulation1results.md` and `simulation2results.md`
* A spreadsheet plotting the results of the range vs initial energy, `simulation2results.xls`

### Basic program structure:

* Asks for the particle and medium data
* Calls a subroutine to calculate the stopping power
* Detects whether the particle is stopped inside the material or leaves
* Prints the relevant info on screen


## SIMULATION1.CPP

The code has a `main()` function that calls two subroutines: `enterData()` and `stoppingPower()`.
To compile and run, type this in a terminal:

``` sh
g++ simulation1.cpp -o simulation1
./simulation1
```

You can try introducing the values we used in `simulation1results.md`.
Even though the stopping power depends on the energy, it is calculated only once (rough approximation approach).

### The `main()` function

If you are compiling in Windows you may need to add a `getch()` before the end of `main()`, to keep MS-DOS windows open (also, remember to include `conio.h` in the header to recognize the `getch()` function).

### The `enterData()` function

Keep these values at hand:

#### For the particle:

* Particle mass in MeV/c2
* Charge in units of e
* Initial kinetic energy in MeV

#### For the material:

* Density of the material in g/cm3
* Atomic number (Z)
* Mass number (A)
* Ionization Potential in MeV
* Medium thickness in cm
* Step size in cm

### The `stoppingPower()` function

We used the **Ziegler formula**. Check the [dedicated website](http://ppsnippets.tk/) for the physics and nicely displayed formulas, as well as illustrations.

### Results

The results are shown in `simulation1results.md`. The example uses a proton entering an aluminium foil.

## SIMULATION2.CPP

Calculates the range of a particle in a medium. If the particle goes out, the stopping power of air is calculated. Unlike `simulation1.cpp`, the stopping power is recalculated each time the energy changes. As a result, a `writeData()` function is added to print the relevant stopping data info.
To compile and run, type this in a terminal:

```sh
$ g++ simulation2.cpp -o simulation2
$ ./simulation2
```

The philosophy is different. It doesn't use  `L` (remaining distance to the exit) but the range, which only takes into account the total distance from the entrance of the material to the position where it is stopped, either inside the material or in the air.

Variables referring to air have an `a`, and fixed values. We pass those values to the stopping function, to calculate the stopping power of air, `SPa`. The initial energy is the value stored in `E` at that moment, which is the energy of the particle when it leaves the material (printed on screen).


## TO DO

- [ ] Read the values in `enterData()` from an external file.

- [ ] The values for air are **effective**. If more precision is needed for the stopping power of air, a function could be added to calculate the stopping power of each component of air (*Oxygen*, *Nytrogen*, etc.). Then, they could be added (weighted by their respective abundance in air) to calculate the total stopping power of air. Next, the line where we do the assingment of `SPa` should be changed to add the `SPi` of each element `i`, calling the `stoppingPower()` function and passing their respective `(roi, Zi, Ai, Ii)`.

- [ ] Fix discrepancies with http://www.physics.nist.gov. Change range units for better comparison.
