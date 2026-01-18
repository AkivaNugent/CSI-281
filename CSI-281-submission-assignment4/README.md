# CSI281 Assignment 4

For this assignment, you will be implementing bubble sort, selection sort, and insertion sort. You will also be answering some questions about them. 

You may look at pseudo code such as that provided in the reading or on Wikipedia, but please do yourself a favor and implement these functions yourself without copying someone else's C++. As always, cite your sources.

## Basic Instructions

1. Create your own **private** repository from this repo by hitting the "Use this template" button at the top of the page
2. Add me (@davecom) as a collaborator on your **private** repository.
3. Implement the missing parts where it says "YOUR CODE HERE"
4. Test it on your local computer by following the build directions below
5. Push your code to GitHub. Every push will be automatically tested on both Windows (MSVC) and Linux (GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit.
6. Answer all of the questions in `questions.txt` in your own file `answers.txt`.
7. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

Please do not use the standard library functions `sort()` or `qsort()` for this assignment. You can use the rest of the standard library as much as you want.

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, and `questions.txt`.
- `/lib` Libraries for drawing the charts and testing your work. There's no need to touch this.
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

*indicates do not modify
&indicates you must modify
%indicates you must create

- `CMakeLists.txt`* CMake "how to build" file
- `README.md`* this file
- `LICENSE` MIT License
- `questions.txt`* Questions that you are expected to answer.
- `answers.txt`% Your answers to the questions in `questions.txt`

- `lib/catch.h`* a unit testing library
- `lib/PPlot.cpp`* part of a chart making library
- `lib/PPlot.h`* part of a chart making library
- `lib/SVGPainter.cpp`* part of a chart making library
- `lib/SVGPainter.h`* part of a chart making library

- `src/sort.h`& the sort functions you must implement
- `src/main.cpp` the main file that runs the tests and makes the charts
- `src/test.cpp`* the unit tests to prove your code works

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
- [ ] Did you remember to include your `answers.txt` file with answers to every question?
