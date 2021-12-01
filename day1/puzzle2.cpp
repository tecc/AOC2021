/**
 * @file puzzle2.cpp
 * @author tecc <tecc@tecc.me>
 * @brief Advent of Code 2021<br>
 *        Day 1: Sonar Sweep<br>
 *        Puzzle 2
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) tecc 2021. Licensed under the MIT licence.
 * 
 */

#include "main.cpp"

// modify this value to change the width of the windows
#define WIDTH 3

inline int sumValues(std::vector<int>& measurements, size_t off) {
    int sum = 0;
    for (size_t i = 0; i < WIDTH; i++) {
        sum += measurements[off + i];
    }
    return sum;
}

Result puzzle(std::vector<int>& measurements) {
    // make sure we've got enough measurements
    if (measurements.size() < (WIDTH + 1)) {
        return {0, 0, 0};
    }

    // first, the number-tracking variables
    size_t increased = 0, decreased = 0, noChange = 0;
    // a previous sum consisiting of the measurement window at 0
    int previousSum = sumValues(measurements, 0);
    
    // and finally loop!
    for (size_t i = 1; i < measurements.size() - (WIDTH - 1); i++) {
        // get the current 3-measurement window
        int sum = sumValues(measurements, i);

        // do the if magic
        if (sum > previousSum) {
            increased++;
        }
        if (sum < previousSum) {
            decreased++;
        }
        if (sum == previousSum) {
            noChange++;
        }
        
        // set the previous sum to this sum
        previousSum = sum;
    }

    return {increased, decreased, noChange};
}