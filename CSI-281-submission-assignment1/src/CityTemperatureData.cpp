//
//  CityTemperatureData.cpp
//
//  Implementation of CityTemperatureData
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
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

#include "CityTemperatureData.h"
#include <cassert>

using namespace std;

namespace csi281 {
    // Fill in all instance variables for CityTemperatureData.
    CityTemperatureData::CityTemperatureData(const string name, CityYear data[], int numYears) : _name(name), _count(numYears) {
        _data = new CityYear[numYears];
        for (int i = 0; i < numYears; i++) {
            _data[i] = data[i];
        }
    }

    CityTemperatureData::CityTemperatureData(const CityTemperatureData& other)
        : _name(other._name), _count(other._count) {
        _data = new CityYear[other._count];
        for (int i = 0; i < other._count; i++) {
            _data[i] = other._data[i];
        }
    }

    CityTemperatureData& CityTemperatureData::operator=(const CityTemperatureData& other) {
        if (this != &other) {
            delete[] _data;
            _name = other._name;
            _count = other._count;
            _data = new CityYear[_count];
            for (int i = 0; i < _count; i++) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Release any memory connected to CityTemperatureData.
    CityTemperatureData::~CityTemperatureData() {
        delete[] _data;
    }

    // Look up a CityYear instance held by CityTemperatureData by its year.
    // Find the right CityYear in the array and return it
    const CityYear CityTemperatureData::operator[](const int year) const {
        const int STARTING_YEAR = 1968;
        int indexYear = year - STARTING_YEAR;

        return _data[indexYear];
    }

    // Get the average (mean) temperature of all time for this city
    // by averaging every CityYear.
    float CityTemperatureData::getAllTimeAverage() const {
        float tempSum = 0.0;
        float tempAverage = 0.0;

        for (int i = 0; i < _count; i++) {
            tempSum += _data[i].averageTemperature;
        }
        tempAverage = tempSum / _count;

        return tempAverage;
    }

    // Sum all of the days below 32 for all years.
    int CityTemperatureData::getTotalDaysBelow32() const {
        int dayCount = 0;

        for (int i = 0; i < _count; i++) {
            dayCount += _data[i].numDaysBelow32;
        }

        return dayCount;
    }

    // Sum all of the days above 90 for all years.
    int CityTemperatureData::getTotalDaysAbove90() const {
        int dayCount = 0;

        for (int i = 0; i < _count; i++) {
            dayCount += _data[i].numDaysAbove90;
        }

        return dayCount;
    }
}
