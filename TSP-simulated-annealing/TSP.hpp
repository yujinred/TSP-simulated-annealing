//
//  TSP.hpp
//  TSP-simulated-annealing
//
//  Created by Eugene Zhang on 2016-02-11.
//  Copyright © 2016 Eugene Zhang. All rights reserved.
//

#ifndef TSP_hpp
#define TSP_hpp

#include <stdio.h>
#include <vector>
#include "City.hpp"


class TSP {
    int numCities;
    std::vector<City> path;
    double totalDistance;
    
public:
    TSP(std::string);
    // initialize a TSP with a static number of cities
    TSP(int);
    // add city from input
    void addCity(std::string, int, int);
    // go through all the cities and add up the distance travelled
    double calculateDistance();
    
    // change a path and see if we're improved our outcome
    void mutate();
    
    // calculate the new distance after swapping two path
    double calculateAfterSwap(int, int);
    
    void printTSP();
    
};


#endif /* TSP_hpp */
