# CSI281 Assignment 9

In this assignment you will be implementing Dijkstra's algorithm on a weighted graph class. You will also be adding a test case (in addition to two existing test cases) to prove your implementation works.

You should follow the pseudo-code we went over in class. You may not add any additional methods to `WeightedGraph`. The beginning and end of the `dijkstra()` function are already defined. You must reuse this code.

Don't forget to add your test case to the bottom of `test.cpp`!

NOTE: Because the code you need to add to `dijkstra()` is only about 10-15 lines, unlike in previous assignments, I will not be helping you write these few lines. I am happy to answer as many conceptual questions about how the rest of the code works, or how Dijkstra's algorithm works as you would like, but there is so little code to write here, that I don't think it's appropriate for me to help you write it. Again, I am not saying I am not open to questions, just that I won't help you write the literal code for `dijkstra()`.

NOTE: If you prefer to use different pseudocode than we went over in class (Python code really), feel free to. Just cite it next to your `dijkstra()` method. Please do not look at other C++ implementations of dijkstra's algorithm. 

REMINDER: In addition to being covered in class, Dijkstra's algorithm was covered in your book.

## Basic Instructions

1. Create your own **private** repository from this repo by hitting the "Use this template" button at the top of the page
2. Add me (@davecom) as a collaborator on your **private** repository.
3. Implement the missing parts where it says "YOUR CODE HERE"
4. Test it on your local computer by following the build directions below
5. Push your code to GitHub. Every push will be automatically tested on both Windows (MSVC) and Linux (GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit.
6. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

There are no standard library restrictions.

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, and the make files
- `/lib` A library for testing your work. There's no need to touch this.
- `/src` Source files, some of which you should modify and some of which you should not.

### Specific Files

*indicates do not modify
&indicates you must modify

- `CMakeLists.txt`* CMake "how to build" file
- `README.md`* this file
- `LICENSE` MIT License

- `lib/catch.h`* a unit testing library

- `src/WeightedGraph.h`& the `WeightedGraph` class
- `src/main.cpp` the main file that runs the tests and makes the chart
- `src/test.cpp`& the unit tests to prove your code works

## Building and Running

You can use the command-line CMake tools if you are familiar with them. If you're not, you may find it easier to use one of these IDEs:

### CLion

Open the main directory of your repository (File -> Open). CLion should automatically detect it as a CMake project and allow you to press the run button (right-facing triangle like a play button) to execute the tests.

### Visual Studio

You'll need the "Desktop development with C++" workload installed including the "C++ CMake tools for Windows" (most installs have this). From the Visual Studio home screen select the option to "Open a local folder" and point the open dialog to your repository's main directory. Visual Studio should automatically detect your CMake project and allow you to build and debug it. You find more information in [Microsoft's CMake help documentation](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170).

## Checklist for Submission

- [X] Did you add me (@davecom) as a collaborator on the repository?
- [X] Did you replace every area that said "YOUR CODE HERE" with your code?
- [X] Did you ensure you are passing all of the unit tests? Do you see a green check mark on GitHub?
- [X] Did you cite all sources, especially any place that you copied code from? Put code citations right next to where you inserted them.
- [X] Did you add sufficient comments?
- [X] Did you double check your code for good style?
- [X] Did you put your name below mine at the top of any files you modified and any other appropriate places?
- [X] Did you submit the URL to your repository on Canvas?

