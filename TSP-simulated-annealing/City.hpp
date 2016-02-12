//
//  City.hpp
//  TSP-simulated-annealing
//
//  Created by Eugene Zhang on 2016-02-11.
//  Copyright © 2016 Eugene Zhang. All rights reserved.
//

#ifndef City_hpp
#define City_hpp

#include <stdio.h>
#include <string>

class City {
    std::string name;
    int x, y;
    
public:
    City(std::string, int, int);
    int getX();
    int getY();
    std::string getName();
    
};

double distanceTo(City&, City&);

#endif /* City_hpp */
