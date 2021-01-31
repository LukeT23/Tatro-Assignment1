# CSI281 Assignment 1

This assignment will act as a review of C++ concepts from CSI 140 and 240. At the top of each file is a note about whether or not you should modify it. Please only modify the files that are indicated as being okay to modify.

The goal of this assignment is to read a `.csv` file containing temperature data about NYC and Burlington into structs/classes, process it, and draw some charts of it.

## Basic Instructions

1. Create your own **private** repository from this repo by hitting the "Use this template" button at the top of the page
2. Add me (@davecom) as a collaborator on your **private** repository.
3. Implement the missing parts where it says "YOUR CODE HERE"
4. Test it on your local computer by following the build directions below
5. Run `nmake clean` or `make clean` to remove any binary files
6. Push your code to GitHub (Don't push your binary files—the purpose of the prior step is to remove them). Every push will be automatically tested on both Windows (nmake/MSVC) and Linux (GNUMake/GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit.*
7. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

* You are encouraged to also make commits much more frequently than this, earlier in development. Just don't be surprised when seeing an X on GitHub since not all of the tests will pass.

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, and the `.csv` file.
- `/lib` Libraries for drawing the charts and testing your work. There's no need to touch this.
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

*indicates do not modify
&indicates you must modify

- `GNUMakefile`* make file for GNU Make on macOS and GNU/Linux
- `Makefile`* make file for nmake/Visual Studio on Windows
- `README.md`* this file
- `LICENSE` MIT License
- `tempdata.csv`* temperature data about NYC and Burlington. You can open this in a text editor or Excel if you want to browse it.

- `lib/catch.h`* a unit testing library
- `lib/PPlot.cpp`* part of a chart making library
- `lib/PPlot.h`* part of a chart making library
- `lib/SVGPainter.cpp`* part of a chart making library
- `lib/SVGPainter.h`* part of a chart making library

- `src/CityTemperaturedata.h`* defines a structure and a class for holding data
- `src/CityTemperatureData.cpp`& implementation of the class
- `src/csv.h`* function definitions for reading the CSV and turning it into CityTemperatureData
- `src/csv.cpp`& implementations of the above
- `src/main.cpp` the main file that runs the tests and makes the charts
- `src/test.cpp`* the unit tests to prove your code works

## Building and Running

### macOS and GNU/Linux

Run `make` and `./assignment1` to run all of the tests. It will also output two `.svg` files when you are done that show the data nicely plotted. Run `make clean` to remove all objects files, the executable, and the svg files.

### Windows

From the start menu (assuming you have installed Visual Studio 2019) open the "Developer Command Prompt." CD to the appropriate directory and run `nmake` and `assignment1` to run all of the tests. It will also output two `.svg` files when you are done that show the data nicely plotted. Run `nmake clean` to remove all objects files, the executable, and the svg files.

## Checklist for Submission

- [ ] Did you add me (@davecom) as a collaborator on the repository?
- [ ] Did you replace every area that said "YOUR CODE HERE" with your code?
- [ ] Did you ensure you are passing all of the unit tests? Do you see a green check mark on GitHub?
- [ ] Did you cite all sources, especially any place that you copied code from? Put code citations right next to where you inserted them.
- [ ] Did you add sufficient comments?
- [ ] Did you double check your code for good style?
- [ ] Did you remember to free any memory you manually allocated on the heap?
- [ ] Did you put your name below mine at the top of any files you modified and any other appropriate places?
- [ ] Did you try cleaning, building, and running once to make sure everything is in working order before submitting?
- [ ] If you were working with an IDE, did you test building on the command line with make or nmake? I will go by the tests of your work with make or nmake done automatically by the GitHub action.
- [ ] Did you check the repository is free of your object files and other garbage and just contains source files?
- [ ] Did you submit the URL to your repository on Canvas?
