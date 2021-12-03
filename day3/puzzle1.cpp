/**
 * @file puzzle1.cpp
 * @author tecc <tecc@tecc.me>
 * @brief Advent of Code 2021<br>
 *        Day 3: Binary Diagnostic<br>
 *        Puzzle 1
 * @date 2021-12-03
 * 
 * @copyright Copyright (c) tecc 2021. Licensed under the MIT licence.
 * 
 */

#include "main.cpp"

int puzzle(std::vector<data_t> inputs) {

    size_t halfLength = inputs.size() >> 1;

    BitData bits = getBitData(inputs);

    uint64_t gamma = bits.mostCommon.to_ullong();
    uint64_t epsilon = bits.leastCommon.to_ullong();

    uint64_t powerConsumption = gamma * epsilon;
    std::cout 
        << "Gamma rate: " << gamma << " (" << bits.mostCommon << ")" << std::endl
        << "Epsilon rate: " << epsilon << " (" << bits.leastCommon << ")" << std::endl  
        << "Power consumption: " << powerConsumption << std::endl;

    return 0;
}