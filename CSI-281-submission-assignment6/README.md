# CSI281 Assignment 6

In this assignment you will be creating your own implementations of a hash table. At the top of each file is a note about whether or not you should modify it. Please only modify the files that are indicated as being okay to modify.

You can effectively use a lot of standard library constructs in this assignment including `list`, `pair`, `find_if()`, `remove_if()`, and `optional`.

## Basic Instructions

1. Create your own **private** repository from this repo by hitting the "Use this template" button at the top of the page
2. Add me (@davecom) as a collaborator on your **private** repository.
3. Implement the missing parts where it says "YOUR CODE HERE"
4. Test it on your local computer by following the build directions below
5. Push your code to GitHub. Every push will be automatically tested on both Windows (MSVC) and Linux (GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit.
6. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

Please do not use the hash table or dictionary like data structures included in the standard library. For example, do not use `map` and do not use `unordered_map`. You may use the rest of the standard library as much as you would like (and you are encouraged to).

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, and the make files.
- `/lib` Library testing your work. There's no need to touch this.
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

*indicates do not modify
&indicates you must modify

- `CMakeLists.txt`* CMake "how to build" file
- `README.md`* this file
- `LICENSE` MIT License

- `lib/catch.h`* a unit testing library

- `src/HashTable.h`& the `HashTable` class
- `src/main.cpp` the main file that runs the tests and makes the chart
- `src/test.cpp`* the unit tests to prove your code works

## Building and Running

You can use the command-line CMake tools if you are familiar with them. If you're not, you may find it easier to use one of these IDEs:

### CLion

Open the main directory of your repository (File -> Open). CLion should automatically detect it as a CMake project and allow you to press the run button (right-facing triangle like a play button) to execute the tests.

### Visual Studio

You'll need the "Desktop development with C++" workload installed including the "C++ CMake tools for Windows" (most installs have this). From the Visual Studio home screen select the option to "Open a local folder" and point the open dialog to your repository's main directory. Visual Studio should automatically detect your CMake project and allow you to build and debug it. You find more information in [Microsoft's CMake help documentation](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170).

## Checklist for Submission

- [x] Did you add me (@davecom) as a collaborator on the repository?
- [x] Did you replace every area that said "YOUR CODE HERE" with your code?
- [x] Did you ensure you are passing all of the unit tests? Do you see a green check mark on GitHub?
- [x] Did you cite all sources, especially any place that you copied code from? Put code citations right next to where you inserted them.
- [x] Did you add sufficient comments?
- [x] Did you double check your code for good style?
- [x] Did you put your name below mine at the top of any files you modified and any other appropriate places?
- [x] Did you submit the URL to your repository on Canvas?
