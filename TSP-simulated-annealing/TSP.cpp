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
using namespace std;

TSP::TSP(std::string filename) {
    ifstream project(filename);
    if (project.is_open()) {
        cout << "project open" << endl;
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
}

TSP::TSP(int numCities) {
    this->numCities = numCities;
}

void TSP::addCity(std::string name, int x, int y) {
    cout << "city " << name << " added ";
    printf("x: %-3d y: %-3d\n", x, y);
    path.push_back(City(name, x, y));
}

double TSP::calculateDistance() {
    int i = 0;
    double result = 0;
    while (i < numCities) {
        double stepDist = distanceTo(path[i], path[(i + 1) % numCities]);
        cout << stepDist << endl;
        result += stepDist;
        i++;
    }
    return result;
}

void TSP::mutate() {
    int index1 = rand() % numCities;
    int index2 = rand() % numCities;
    while (index2 == index1) {
        index2 = rand() % numCities;
    }
    
    double newDistance = calculateAfterSwap(index1, index2);
    
}

double TSP::calculateAfterSwap(int index1, int index2) {
    City tempCity = path[index1];
    path[index1] = path[index2];
    path[index2] = tempCity;
    
    double result = calculateDistance();
    
    // swap back
    path[index2] = path[index1];
    path[index1] = tempCity;
    return result;
}


void TSP::printTSP() {
    for (int i = 0; i < numCities; ++i) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Distance Travelled in total: " << calculateDistance() << endl;
}