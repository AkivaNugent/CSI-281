# CSI281 Assignment 1

This assignment will act as a review of C++ concepts from CSI 140 and 240. At the top of each file is a note about whether or not you should modify it. Please only modify the files that are indicated as being okay to modify.

The goal of this assignment is to read a `.csv` file containing temperature data about NYC and Burlington into structs/classes, process it, and draw some charts of it.

## Basic Instructions

1. Create your own **private** repository from this repo by hitting the "Use this template" button at the top of the page
2. Add me (@davecom) as a collaborator on your **private** repository.
3. Implement the missing parts where it says "YOUR CODE HERE"
4. Test it on your local computer by following the build directions below
5. Push your code to GitHub. Every push will be automatically tested on both Windows (MSVC) and Linux (GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit.
6. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Directory Structure and Files

- `/` Main directory including this `README.md`, the CMake file with instructions for building, and the `.csv` file.
- `/lib` Libraries for drawing the charts and testing your work. There's no need to touch this.
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

@indicates do not modify
&indicates you must modify

- `CMakeLists.txt`@ CMake "how to build" file
- `README.md`@ this file
- `LICENSE` MIT License
- `tempdata.csv`@ temperature data about NYC and Burlington. You can open this in a text editor or Excel if you want to browse it.

- `lib/catch.h`@ a unit testing library
- `lib/PPlot.cpp`@ part of a chart making library
- `lib/PPlot.h`@ part of a chart making library
- `lib/SVGPainter.cpp`@ part of a chart making library
- `lib/SVGPainter.h`@ part of a chart making library

- `src/CityTemperaturedata.h`@ defines a structure and a class for holding data
- `src/CityTemperatureData.cpp`& implementation of the class
- `src/csv.h`@ function definitions for reading the CSV and turning it into CityTemperatureData
- `src/csv.cpp`& implementations of the above
- `src/main.cpp` the main file that runs the tests and makes the charts
- `src/test.cpp`@ the unit tests to prove your code works

## Building and Running

You can use the command-line CMake tools if you are familiar with them. If you're not, you may find it easier to use one of these IDEs:

### CLion

Open the main directory of your repository (File -> Open). CLion should automatically detect it as a CMake project and allow you to press the run button (right-facing triangle like a play button) to execute the tests.

### Visual Studio

You'll need the "Desktop development with C++" workload installed including the "C++ CMake tools for Windows" (most installs have this). From the Visual Studio home screen select the option to "Open a local folder" and point the open dialog to your repository's main directory. Visual Studio should automatically detect your CMake project and allow you to build and debug it. You find more information in [Microsoft's CMake help documentation](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170).

## Checklist for Submission

- [ ] Did you add me (@davecom) as a collaborator on the repository?
- [ ] Did you replace every area that said "YOUR CODE HERE" with your code?
- [ ] Did you ensure you are passing all of the unit tests? Do you see a green check mark on GitHub?
- [ ] Did you cite all sources, especially any place that you copied code from? Put code citations right next to where you inserted them.
- [ ] Did you add sufficient comments?
- [ ] Did you double check your code for good style?
- [ ] Did you put your name below mine at the top of any files you modified and any other appropriate places?
- [ ] Did you submit the URL to your repository on Canvas?
