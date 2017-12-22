//
//  globals.hpp
//  Project 3
//
//  Created by Jacob on 5/17/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#ifndef GLOBALS_INCLUDED
#define GLOBALS_INCLUDED

#include <random>

const int MAXROWS = 10;
const int MAXCOLS = 10;

enum Direction {
    HORIZONTAL, VERTICAL
};

class Point
{
public:
    Point() : r(0), c(0) {}
    Point(int rr, int cc) : r(rr), c(cc) {}
    int r;
    int c;
};

// Return a uniformly distributed random int from 0 to limit-1
inline int randInt(int limit)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<> distro(0, limit-1);
    return distro(generator);
}

#endif // GLOBALS_INCLUDED
