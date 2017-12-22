//
//  History.hpp
//  Project 1
//
//  Created by Jacob on 4/8/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#ifndef History_h
#define History_h
#include "globals.h"

class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
private:
    int m_Row;
    int m_Col;
    int m_Grid[MAXROWS][MAXCOLS];
};
#endif /* History_h */
