/**
 * @file solution.cpp
 * @author tecc <tecc@tecc.me>
 * @brief Advent of Code 2021<br>
 *        Day 2: Dive!<br>
 *        Solution
 * @date 2021-12-02
 * 
 * @copyright Copyright (c) tecc 2021. Licensed under the MIT licence.
 * 
 */
#include <cstdint>
#include <string>
#include <iostream>


#define I_FORWARD 1
#define I_DOWN 2
#define I_UP 3

typedef struct Instruction {
    int type;
    int64_t param;
} Instruction;
typedef struct Position {
    int64_t depth = 0;
    int64_t horizontalPosition = 0;
    int64_t aim = 0;
} Position;

// used for debugging
std::string toString(Instruction inst) {
    return "{" + std::to_string(inst.type) + ": " + std::to_string(inst.param) + "}";
}

static bool useAim = false;

void executeInstruction(Position* position, Instruction instruction) {
    switch (instruction.type) {
        case I_FORWARD:
            position->horizontalPosition += instruction.param;
            if (useAim) {
                position->depth += instruction.param * position->aim;
            }
            break;
        case I_DOWN:
            if (useAim) {
                position->aim += instruction.param;
            } else {
                position->depth += instruction.param;
            }
            break;
        case I_UP:
            if (useAim) {
                position->aim -= instruction.param;
            } else {
                position->depth -= instruction.param;
            }
            break;
        default:
            std::cerr << "Unknown instruction " << toString(instruction) << std::endl;
    }
}

bool isWhitespace(char c) {
    return c == ' ' || c == '\r' || c == '\n';
}

Instruction parseNextInstruction() {
    // this variable is just here to store the type string, as that can't be parsed by cin
    std::string typeStr;
    // now, 2 variables - one for the type and one for the parameter
    int type = 0;
    std::string paramStr;
    int64_t param;
    std::cin >> typeStr; // read type
    std::cin >> paramStr; // read parameter

    if (typeStr.size() < 1 && paramStr.size() < 1) {
        return {0, 0};
    }

    param = std::stoi(paramStr);

    // finally parse the type
    if (typeStr == "forward") {
        type = I_FORWARD;
    } else if (typeStr == "down") {
        type = I_DOWN;
    } else if (typeStr == "up") {
        type = I_UP;
    } else {
        // quick else block in case it wasn't a valid instruction
        return {0, param};
    }
    
    // if we got to here, it means the instruction is valid!
    // return it!!
    return {type, param};
}

int main(int argc, char** argv) {
    if (argc > 1) {
        // simple argument parser
        for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];
            /* 
             * --enable-aim, -a
             * enables the aim featured in puzzle 2
             */ 
            if (arg == "--enable-aim" || arg == "-a") {
                useAim = true;
            }
        }
    }

    if (useAim) {
        // make it clear that the aim instruction was received
        std::cout << "Using aim" << std::endl;
    }

    // simple variable to keep track of the position
    Position pos{0, 0, 0};
    // very simple loop to parse and execute each instruction
    while (std::cin) {
        // parse the next instruction
        Instruction instruction = parseNextInstruction();
        // execute the instruction
        if (instruction.type) {
            executeInstruction(&pos, instruction);
        }
    }

    std::cout 
        << "Horizontal position: " << pos.horizontalPosition << std::endl
        << "Depth: " << pos.depth << std::endl;

    if (useAim) {
        std::cout << "Aim: " << pos.aim << std::endl;
    }
    std::cout << "Product: " << (pos.horizontalPosition * pos.depth) << std::endl; 
}