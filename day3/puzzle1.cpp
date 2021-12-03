/**
 * @file solution.cpp
 * @author tecc <tecc@tecc.me>
 * @brief Advent of Code 2021<br>
 *        Day 3: Binary Diagnostic<br>
 *        Puzzle 1
 * @date 2021-12-02
 * 
 * @copyright Copyright (c) tecc 2021. Licensed under the MIT licence.
 * 
 */

#include <cstdint>
#include <array>
#include <vector>
#include <iostream>

#define FLAG(o) (0x1 << (o))
#define LENGTH 5

typedef uint64_t inputValue;
typedef std::array<bool, LENGTH> data;

data decode(inputValue value) {
    data array;

    for (int i = 0; i < LENGTH; i++) {
        array[i] = value & FLAG(LENGTH - i);
    }

    return array;
}



int main() {
    std::vector<inputValue> inputs;
    while (std::cin) {
        std::string numberStr;
        std::cin >> numberStr;

        if (numberStr.empty()) {
            continue;
        }
        uint64_t number = std::stoull(numberStr, nullptr, 2);
        std::cout << number << std::endl;
        inputs.push_back(number);
    }

    size_t inputLength = inputs.size();
    std::array<uint64_t, LENGTH> numberOfOnes;
    for (size_t i = 0; i < inputLength; i++) {
        data data = decode(inputs[i]);
        for (size_t i = 0; i < LENGTH; i++) {
            numberOfOnes[i] += !!data[i];
        }
    }

    size_t halfLength = inputLength >> 1;
    uint64_t gamma = 0;
    uint64_t epsilon = 0;
    for (size_t i = 0; i < inputLength; i++) {
        uint64_t value = (numberOfOnes[i] > halfLength) << (LENGTH - i);
        gamma = gamma | value;
        epsilon = epsilon | (value ^ (FLAG(LENGTH - i)));
    }

    uint64_t powerConsumption = gamma * epsilon;
    std::cout 
        << "Gamma rate: " << gamma << std::endl
        << "Epsilon rate: " << epsilon << std::endl  
        << "Power consumption: " << powerConsumption << std::endl;
}