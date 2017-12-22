//
//  History.cpp
//  Project 1
//
//  Created by Jacob on 4/8/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRow, int nCol)
{
    m_Row = nRow;
    m_Col = nCol;
    for(int r = 1; r <= nRow; r++)
        for(int c = 1; c <= nCol; c++)
            m_Grid[r-1][c-1] = 0;
}

bool History::record(int r, int c)
{
   if(r > MAXROWS || r < 1 || c > MAXCOLS || c < 1)
       return false;
    else
    {
        m_Grid[r-1][c-1]++;
        return true;
    }
}

void History::display() const
{
    clearScreen();
    char displayGrid[m_Row][m_Col];
    
    for(int r = 1; r <= m_Row; r++)
    {
        for(int c = 1; c <= m_Col; c++)//12
        {
            if(m_Grid[r-1][c-1] == 0)
                displayGrid[r-1][c-1] = '.';
            else if(m_Grid[r-1][c-1] >= 26)
                displayGrid[r-1][c-1] = 'Z';
            else
                displayGrid[r-1][c-1] ='A'+ m_Grid[r-1][c-1] - 1;
        }
    }
    for( int r = 1; r <= m_Row; r++)
    {
        for(int c = 1; c <= m_Col; c++)//12
        {
            cout << displayGrid[r-1][c-1];
        }
        cout << endl;
    }
    cout << endl;
}
