# CSI281 Assignment 7

In this assignment you will be creating your own implementations of a stack and a queue using `std::list` as a backing store. You have less code written for you than in previous assignments and you will be implementing the tests yourself.

Your implementations, `Queue` and `Stack`, will subclass a provided abstract base class called `SequentialCollection`. Please use the intance variables from `SequentialCollection` instead of implementing your own. In fact, you are not allowed to add any instance variables to your subclasses. Please ensure you implement `push()`, `pop()`, and `peek()`. You will also write tests to ensure you have successfully implemented all of the required methods in `test.cpp`.

A large part of the grading of this assignment will be based on the tests you write. Your tests should be comprehensive and should test all of the method implemented in `Stack`, `Queue`, and `SequentialCollection`. You can learn how to write tests by looking at the tests I've written for previous assignments or by checking out the [Catch documentation](https://github.com/catchorg/Catch2).

Finally, there are 4 questions for you to answer in `questions.txt`.

## Basic Instructions

1. Create your own **private** repository from this repo by hitting the "Use this template" button at the top of the page
2. Add me (@davecom) as a collaborator on your **private** repository.
3. Implement the missing parts where it says "YOUR CODE HERE"
4. Test it on your local computer by following the build directions below
5. Push your code to GitHub. Every push will be automatically tested on both Windows (MSVC) and Linux (GCC) through a GitHub Action. You will know your code is correct when you see a green check mark next to the commit.
6. Answer all of the questions in `questions.txt` in your own file `answers.txt`.
7. Submit the URL to your private repository on Canvas. Submit even if you are not passing all tests so you can get partial credit.

## Standard Library Restrictions

Please do not use `<queue>`, `<stack>`, and `<deque>` from the standard library. You may use the rest of the standard library as much as you would like (and you are encouraged to).

## Directory Structure and Files

- `/` Main directory including this `README.md`, the build scripts, the make files, and `questions.txt`.
- `/lib` Library testing your work. There's no need to touch this.
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

- `src/SequentialCollection.h`* the `SequentialCollection` abstract base class
- `src/Stack.h`& the `Stack` class
- `src/Queue.h`& the `Queue` class
- `src/main.cpp` the main file that runs the tests and makes the chart
- `src/test.cpp`& the unit tests to prove your code works

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
- [x] Did you remember to include your `answers.txt` file with answers to every question?

