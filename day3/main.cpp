/**
 * @file main.cpp
 * @author tecc <tecc@tecc.me>
 * @brief Advent of Code 2021<br>
 *        Day 3: Binary Diagnostic<br>
 *        Common code
 * @date 2021-12-03
 * 
 * @copyright Copyright (c) tecc 2021. Licensed under the MIT licence.
 * 
 */

#include <cstdint>
#include <array>
#include <vector>
#include <iostream>
#include <bitset>

#define FLAG(o) (0x1 << (o))

#define UPPER_LIMIT 64

typedef std::bitset<UPPER_LIMIT> data_t;

static size_t lengthp[1];

#define length (lengthp[0])

typedef struct BitData {
    data_t mostCommon; // gamma
    data_t leastCommon; // epsilon
} BitData;

template<typename V, typename T>
T cmp(V a, V b, T lessThan, T equalTo, T greaterThan) {
    if (a < b) {
        return lessThan;
    }
    if (a > b) {
        return greaterThan;
    }
    return equalTo;
}

BitData getBitData(std::vector<data_t> inputs) {
    size_t inputLength = inputs.size();
    std::array<uint64_t, UPPER_LIMIT> numberOfOnes{0};
    for (size_t i = 0; i < inputLength; i++)
    {
        data_t data = inputs[i];
        for (size_t j = 0; j < length; j++)
        {
            numberOfOnes[j] += data[j] > 0;
        }
    }

    size_t halfLength = inputs.size() >> 1;
    data_t gammaBits = 0;
    data_t epsilonBits = 0;
    for (size_t i = 0; i < length; i++) {
        uint64_t ones = numberOfOnes[i];
        uint64_t zeroes = inputLength - ones;
        gammaBits[i] = cmp(ones, zeroes, 0, 1, 1);
        epsilonBits[i] = cmp(ones, zeroes, 1, 0, 0);
    }
    return {gammaBits, epsilonBits};
}

int puzzle(std::vector<data_t> inputs);

int main() {
    std::string numberStr;
    std::cin >> numberStr;
    lengthp[0] = numberStr.size();
    std::vector<data_t> inputs;
    do
    {
        if (numberStr.empty())
        {
            continue;
        }

        data_t bits{numberStr.c_str(), length, '0', '1'};
        inputs.push_back(bits);

    } while (std::cin && (std::cin >> numberStr));

    return puzzle(inputs);
}