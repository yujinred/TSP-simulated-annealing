//
//  TSP.cpp
//  TSP-simulated-annealing
//
//  Created by Eugene Zhang on 2016-02-11.
//  Copyright © 2016 Eugene Zhang. All rights reserved.
//

#include "TSP.hpp"
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const double MAX_TEMPERATURE = 1000;
const int ANNEALING_INDEX = 3;
const int ITERATION_NUMBER = 200000;

TSP::TSP(std::string filename) {
    ifstream project(filename);
    if (project.is_open()) {
        project >> numCities;
        for (int i = 0; i < numCities; ++i) {
            string name;
            int x, y;
            project >> name >> x >> y;
            addCity(name, x, y);
        }
    }
    project.close();
    
    totalDistance = calculateDistance();
    temperature = MAX_TEMPERATURE;
    tempCounter = 0;
}

TSP::TSP(int numCities) {
    this->numCities = numCities;
}

void TSP::addCity(std::string name, int x, int y) {
    path.push_back(City(name, x, y));
}

double TSP::calculateDistance() {
    int i = 0;
    double result = 0;
    while (i < numCities) {
        double stepDist = distanceTo(path[i], path[(i + 1) % numCities]);
        result += stepDist;
        i++;
    }
    return result;
}

void TSP::mutate() {
    // don't change first city
    int index1 = rand() % (numCities-1) + 1;
    int index2 = rand() % (numCities-1) + 1;
    while (index2 == index1) {
        index2 = rand() % (numCities-1) + 1;
    }
    
    double newDistance = calculateAfterSwap(index1, index2);
    if (newDistance < totalDistance) {
        swapCities(index1, index2);
        totalDistance = newDistance;
    } else {
        double p = exp((totalDistance - newDistance) / temperature);
        if (rand() % 100 < p * 100) {
            swapCities(index1, index2);
            totalDistance = newDistance;
        }
    }
    annealingSchedule();
    
}

void TSP::swapCities(int index1, int index2) {
    City tempCity = path[index1];
    path[index1] = path[index2];
    path[index2] = tempCity;
}

double TSP::calculateAfterSwap(int index1, int index2) {
    swapCities(index1, index2);
    
    double result = calculateDistance();
    
    // swap back
    swapCities(index1, index2);
    return result;
}

void TSP::annealingSchedule() {
    // different strategy controlled by ANNEALING_INDEX
    switch (ANNEALING_INDEX) {
        case 0:
            temperature = temperature * .95;
            break;
        case 1:
            temperature = temperature - 0.1;
            break;
        case 2:
            temperature = temperature / 2;
            break;
        case 3:
            temperature = MAX_TEMPERATURE / (tempCounter + 1);
        default:
            break;
    }
}

void TSP::runAnnealing() {
    while (temperature > 0 && tempCounter < ITERATION_NUMBER) {
        
        printTSP();
        mutate();
        tempCounter++;
    }
}

void TSP::printTSP() {
    for (int i = 0; i < numCities; ++i) {
        cout << path[i].getName() << " ";
    }
    cout << totalDistance << endl;
}