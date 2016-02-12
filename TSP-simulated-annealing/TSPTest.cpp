//
//  TSPTest.cpp
//  TSP-simulated-annealing
//
//  Created by Eugene Zhang on 2016-02-11.
//  Copyright © 2016 Eugene Zhang. All rights reserved.
//

#include "TSP.hpp"
#include <iostream>
#include <math.h>
using namespace std;

int totalTest = 0;
int testPassed = 0;

void expect(double actual, double expect) {
    totalTest++;
    if (actual == expect) {
        testPassed++;
    } else {
        cout << "Expected: " << expect << endl;
        cout << "Result:   " << actual << endl;
    }
}

void testResult() {
    cout << testPassed << " out of " << totalTest << " passed!" << endl;
}

void testDistanceTo() {
    TSP t1(0);
    expect(t1.calculateDistance(), 0);
    TSP t2(1);
    t2.addCity("A", 5, 5);
    expect(t1.calculateDistance(), 0);
    TSP t3(2);
    t3.addCity("A", 3, 3);
    t3.addCity("B", 5, 3);
    expect(t3.calculateDistance(), 4);
    TSP t4(2);
    t4.addCity("A", 5, 5);
    t4.addCity("B", 5, 3);
    expect(t4.calculateDistance(), 4);
    TSP t5(2);
    t5.addCity("A", 5, 5);
    t5.addCity("B", 7, 7);
    double result = sqrt(2*2 + 2*2) * 2;
    expect(t5.calculateDistance(), result);
    TSP t6(3);
    t6.addCity("A", 1, 1);
    t6.addCity("B", 4, 1);
    t6.addCity("C", 4, 5);
    double result2 = 3 + 4 + 5;
    expect(t6.calculateDistance(), result2);
}

void testSwapDistance() {
    TSP t3(2);
    t3.addCity("A", 3, 3);
    t3.addCity("B", 5, 3);
    expect(t3.calculateAfterSwap(0, 1), 4);
    expect(t3.calculateAfterSwap(1, 0), 4);
    TSP t6(3);
    t6.addCity("A", 1, 1);
    t6.addCity("B", 4, 1);
    t6.addCity("C", 4, 5);
    double result2 = 3 + 4 + 5;
    expect(t6.calculateAfterSwap(1, 2), result2);
    expect(t6.calculateAfterSwap(2, 0), result2);
    expect(t6.calculateAfterSwap(0, 1), result2);
    TSP t7(4);
    t7.addCity("A", 0, 0);
    t7.addCity("B", 4, 0);
    t7.addCity("C", 0, 3);
    t7.addCity("C", 4, 3);
    double result3 = 4 + 5 + 4 + 5;
    expect(t7.calculateDistance(), result3);
    result3 = 4 + 3 + 4 + 3;
    expect(t7.calculateAfterSwap(3, 2), result3);
}

int main() {
    TSP testTSP("/Users/yujinred/Winter 2016/CS 486/A2/TSP-simulated-annealing/randTSP/5/instance_1.txt");
    testTSP.printTSP();
    testDistanceTo();
    testSwapDistance();
    testResult();
    return 0;
}