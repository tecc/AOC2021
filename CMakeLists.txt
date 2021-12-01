cmake_minimum_required(VERSION 3.20)
project(AOC2021)

find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)

function(add_day id)
    set(base "day${id}")
    add_executable("${base}-puzzle1" "${base}/puzzle1.cpp")
    add_executable("${base}-puzzle2" "${base}/puzzle2.cpp")

    doxygen_add_docs(${base} ${base} ALL)
endfunction(add_day)

add_day(1)