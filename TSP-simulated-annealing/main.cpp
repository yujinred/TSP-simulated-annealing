//
//  main.cpp
//  TSP-simulated-annealing
//
//  Created by Eugene Zhang on 2016-02-11.
//  Copyright © 2016 Eugene Zhang. All rights reserved.
//

#include <iostream>
#include "TSP.hpp"

int main(int argc, const char * argv[]) {
    // replace the file path to try other files
    TSP problem("randTSP/problem36");
    problem.runAnnealing();
    return 0;
}
