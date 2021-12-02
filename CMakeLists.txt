cmake_minimum_required(VERSION 3.20)
project(AOC2021)

find_package(Doxygen
             REQUIRED dot
             OPTIONAL_COMPONENTS mscgen dia)

function(add_day id)
    set(base "day${id}")
    set(ONE_SOLUTION OFF)

    foreach(arg IN LISTS ARGN)
        if (arg STREQUAL "ONE_SOLUTION")
            set(${arg} ON)
        endif()
    endforeach()

    if (ONE_SOLUTION)
        add_executable("${base}" "${base}/solution.cpp")
    else()
        add_executable("${base}-puzzle1" "${base}/puzzle1.cpp")
        add_executable("${base}-puzzle2" "${base}/puzzle2.cpp")
    endif()

    doxygen_add_docs(${base}-doc ${base} ALL)
endfunction(add_day)

add_day(1)
add_day(2 ONE_SOLUTION)