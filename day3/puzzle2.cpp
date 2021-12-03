/**
 * @file puzzle2.cpp
 * @author tecc <tecc@tecc.me>
 * @brief Advent of Code 2021<br>
 *        Day 3: Binary Diagnostic<br>
 *        Puzzle 2
 * @date 2021-12-03
 * 
 * @copyright Copyright (c) tecc 2021. Licensed under the MIT licence.
 * 
 */

#include "main.cpp"
#include <algorithm>

template<typename V, typename Predicate>
void filter(std::vector<V>& target, Predicate p) {
    target.erase(std::remove_if(target.begin(), target.end(), p), target.end());
}

int puzzle(std::vector<data_t> inputs) {
    BitData bits;
    std::vector<data_t> mostCommonFiltered{inputs};
    std::vector<data_t> leastCommonFiltered{inputs};
    bool continueFilter = false;
    size_t csize;
    for (int i = length - 1; i >= 0; i--) {
        csize = mostCommonFiltered.size();
        if (csize > 1) {
            bits = getBitData(mostCommonFiltered);
            continueFilter = true;
            filter(mostCommonFiltered,
            [i, &csize, bits](data_t data){
                bool val = (data[i] != bits.mostCommon[i]) && (csize > 1);
                if (val) {
                    csize--;
                }
                return val;
            });
        }
        csize = leastCommonFiltered.size();
        if (csize > 1) {
            bits = getBitData(leastCommonFiltered);
            continueFilter = true;
            filter(leastCommonFiltered, [i, &csize, bits](data_t data){
                bool val = (data[i] != bits.leastCommon[i]) && (csize > 1);
                if (val) {
                    csize--;
                }
                return val;
            });
            
        }
        if (continueFilter) {
            continueFilter = false;
            continue;
        }
        break;
    }
    // equivalent to the oxygen generator rating
    data_t mostCommonBits = mostCommonFiltered[0];
    // equivalent to the CO2 scrubber rating
    data_t leastCommonBits = leastCommonFiltered[0];

    uint64_t mostCommon = mostCommonBits.to_ullong();
    uint64_t leastCommon = leastCommonBits.to_ullong();
    uint64_t product = mostCommon * leastCommon; // life support rating

    std::cout
        << "Most common (oxygen generator rating): " << mostCommon << " (" << mostCommonBits << ")" << std::endl
        << "Least common (CO2 scrubber rating): " << leastCommon << " (" << leastCommonBits << ")" << std::endl
        << "Product (life support rating): " << product << std::endl;

    return 0;
}