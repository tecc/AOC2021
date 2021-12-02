## WARNING: THIS REPOSITORY SPOILS SOLUTIONS FOR PROBLEMS. DO *NOT* VIEW THE CODE IF YOU HAVE NOT SOLVED IT YOURSELF.

With that out of the way..

# Advent of Code 2021

This is my crack at the Advent of Code 2021.

Just some general solutions and whatnot.

For those who want to see the results in action, I will add instructions for the usage of each solution.

## Command-line usage of each solution

### Day 1: Sonar Sweep

All input for both of them is read from STDIN.

For example:

```sh
# For a file as the input (in this case the file is "./day1/sample.txt")
cat ./day1/sample.txt | ./build/day1-puzzle1
cat ./day1/sample.txt | ./build/day1-puzzle2
```

Note that the solution for the second puzzle (`day1-puzzle2`) can be configured to use N-length windows.
This is done by modifying the `#define WIDTH 3` line in [puzzle2.cpp](./day1/puzzle2.cpp).
Defining it as `1` will yield the same output as the solution for puzzle 1 (`day1-puzzle1`).

### Day 2: Dive!

For this one there is only one executable.
Use the `day2` programme.

The programme reads the instructions and executes them accordingly. 
To enable the aim found in the second puzzle, pass either the `--enable-aim` or `-a` argument.

Example usage:
```sh
# For a file as the input (in this case the file is "./day2/sample.txt")
cat ./day2/sample.txt | ./build/day2
# The usage with aim mode is the same, except for an extra `--enable-aim` argument
cat ./day2/sample.txt | ./build/day2 --enable-aim
```


## Licence

All code in this repository is licensed under the MIT licence.
Read the full licence text in the [LICENCE file](./LICENCE).