//
//  util.cpp
//
//  Implementation of Timing Tests
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//  Editied 2024 by Akiva Nugent
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include "util.h"
#include "search.h"
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

namespace csi281 {
    
    // Returns a new int array of *length* and filled
    // with numbers between *min* and *max*
    // Suggest using the facilities in STL <random>
    int* randomIntArray(const int length, const int min, const int max) {
        int* array = new int[length];

        // I used this tutorial from youtube.com/@TheBuilder for my information on <random> : https://www.youtube.com/watch?v=oW6iuFbwPDg
        random_device rd;
        uniform_int_distribution<int> dist(min, max);

        for (int i = 0; i < length; i++) {
            int randomNumber = dist(rd);
            array[i] = randomNumber;
        }

        return array;
    }
    
    // Finds the speed of linear versus binary search
    // in a random int array of *length* size
    // by running *numTests* and averaging them
    // Returns a pair indicating the average time it took
    // to do linear search and binary search in nanoseconds
    // Linear search should be first in the pair, and binary search
    // should be second
    //
    // Suggest using the facilities in STL <chrono>
    // For example, you can start a timer using
    // using namespace std::chrono;
    // auto start = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
    // and stop a timer using
    // auto end = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
    // start, end will be results in nanoseconds
    pair<nanoseconds, nanoseconds> arraySearchSpeed(const int length, const int numTests) {
        int *testArray = randomIntArray(length, 0, length);
        int *testKeys = randomIntArray(numTests, 0, length);
        
        using namespace std::chrono;

        // Do numTests linear searches and find the average time
        // Put the result in a variable linearSearchSpeed
        
        // I used this tutorial from youtube.com/@TheBuilder for my information on <chrono> : https://www.youtube.com/watch?v=QYaQStudgnE&t=462s
        auto linearSearchStart = steady_clock::now();

        for (int testIndex = 0; testIndex < numTests; testIndex++) {
            linearSearch(testArray, length, testKeys[testIndex]);
        }

        nanoseconds linearSearchSpeed = steady_clock::now() - linearSearchStart;
        
        // Do numTests binary searches and find the average time
        // Put the result in a variable binarySearchSpeed
        
        auto binarySearchStart = steady_clock::now();
        sort(testArray, testArray + length);

        for (int testIndex = 0; testIndex < numTests; testIndex++) {
            binarySearch(testArray, length, testKeys[testIndex]);
        }

        nanoseconds binarySearchSpeed = steady_clock::now() - binarySearchStart;
        
        linearSearchSpeed /= numTests;
        binarySearchSpeed /= numTests;

        delete testArray;
        delete testKeys;
        
        return pair<nanoseconds, nanoseconds>(linearSearchSpeed, binarySearchSpeed);
    }
}
