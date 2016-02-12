//
//  TSPTest.cpp
//  TSP-simulated-annealing
//
//  Created by Eugene Zhang on 2016-02-11.
//  Copyright © 2016 Eugene Zhang. All rights reserved.
//

#include "TSP.hpp"
#include <iostream>



int main() {
    TSP testTSP("/Users/yujinred/Winter 2016/CS 486/A2/TSP-simulated-annealing/randTSP/5/instance_1.txt");
    testTSP.printTSP();
    return 0;
}