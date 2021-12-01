## WARNING: THIS REPOSITORY SPOILS SOLUTIONS FOR PROBLEMS. DO *NOT* VIEW THE CODE IF YOU HAVE NOT SOLVED IT YOURSELF.

With that out of the way..

# Advent of Code 2021

This is my crack at the Advent of Code 2021.

Just some general solutions and whatnot.

For those who want to see the results in action, I will add instructions for the usage of each solution.

## Day 1: Sonar Sweep

Both of the puzzles have the same input, and as such have the same way of giving it input.

All input for both of them is read from STDIN.

For example:

```sh
# For a file with the input
cat ./day1/sample.txt | ./build/day1-puzzle1
cat ./day1/sample.txt | ./build/day1-puzzle2
```

Note that the solution for the second puzzle (`day1-puzzle2`) can be configured to use N-length windows.
This is done by modifying the `#define WIDTH 3` line in [puzzle2.cpp](./day1/puzzle2.cpp).
