//
//  City.cpp
//  TSP-simulated-annealing
//
//  Created by Eugene Zhang on 2016-02-11.
//  Copyright © 2016 Eugene Zhang. All rights reserved.
//

#include "City.hpp"
#include <math.h>
using namespace std;

City::City(string name, int x, int y) {
    this->name = name;
    this->x = x;
    this->y = y;
}

double distanceTo(City& from, City& to) {
    int xd = from.getX() - to.getX();
    int yd = from.getY() - to.getY();
    
    return sqrt(xd * xd + yd * yd);
}

int City::getX() {
    return x;
}

int City::getY() {
    return y;
}

string City::getName() {
    return name;
}