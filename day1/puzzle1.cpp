/**
 * @file puzzle1.cpp
 * @author tecc <tecc@tecc.me>
 * @brief Advent of Code 2021<br>
 *        Day 1: Sonar Sweep<br>
 *        Puzzle 1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) tecc 2021. Licensed under the MIT licence.
 * 
 */
#include "main.cpp"

Result puzzle(std::vector<int>& measurements) {
    if (measurements.size() < 2) {
        std::cout << "0" << std::endl;
        return {0, 0, 0};
    }

    /* now for the solution */
    // these 3 just keep track of every change
    size_t increased = 0, decreased = 0, noChange = 0;
    int previousMeasurement = measurements[0];
    for (size_t i = 1; i < measurements.size(); i++) {
        int measurement = measurements[i];
        if (measurement > previousMeasurement) {
            increased++;
        }
        if (measurement < previousMeasurement) {
            decreased++;
        }
        if (measurement == previousMeasurement) {
            noChange++;
        }
        previousMeasurement = measurement;
    }

    return {increased, decreased, noChange};
}