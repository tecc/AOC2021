/**
 * @file main.cpp
 * @author tecc <tecc@tecc.me>
 * @brief Advent of Code 2021<br>
 *        Day 1: Sonar Sweep<br>
 *        Common code
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) tecc 2021. Licensed under the MIT licence.
 * 
 */

#include <iostream>
#include <vector>
#include <cstdint>

typedef struct Result {
    size_t increased;
    size_t decreased;
    size_t noChange;
} Result;

Result puzzle(std::vector<int>& measurements);

int main() {
    std::vector<int> measurements;

    // this part just parses all the measurements from stdin
    while (true) {
        int parsed;
        std::string data;
        std::cin >> data;
        if (data.length() == 0) {
            break;
        }
        parsed = std::stoi(data);
        measurements.push_back(parsed);
    }

    Result result = puzzle(measurements);

    std::cout 
        << "Increased: " << result.increased << std::endl 
        << "Decreased: " << result.decreased << std::endl
        << "No change: " << result.noChange << std::endl;

    return 0;
}
