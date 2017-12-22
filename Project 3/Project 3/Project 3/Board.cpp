//
//  Board.cpp
//  Project 3
//
//  Created by Jacob on 5/17/17.
//  Copyright © 2017 Jacob. All rights reserved.
//
#include "Board.h"
#include "Game.h"
#include "globals.h"
#include <iostream>

using namespace std;

class BoardImpl
{
public:
    BoardImpl(const Game& g);
    void clear();
    void block();
    void unblock();
    bool placeShip(Point topOrLeft, int shipId, Direction dir);
    bool unplaceShip(Point topOrLeft, int shipId, Direction dir);
    void display(bool shotsOnly) const;
    bool attack(Point p, bool& shotHit, bool& shipDestroyed, int& shipId);
    bool allShipsDestroyed() const;
    
private:
    // TODO:  Decide what private members you need.  Here's one that's likely
    //        to be useful:
    const Game& m_game;
    int nRow;
    int nCol;
    char m_grid[MAXROWS][MAXCOLS];
    bool blocked[MAXROWS][MAXCOLS];
    struct ship{
        int m_length;
        int shipID;
        vector <Point> m_point;
    };
    vector<ship> m_ship;
};

BoardImpl::BoardImpl(const Game& g)
: m_game(g)
{
    nRow = m_game.rows();
    nCol = m_game.cols();
    clear();
    for(int r = 0; r < m_game.rows(); r++)
        for(int c = 0; c < m_game.cols(); c++)
            blocked[r][c] = false;
}

void BoardImpl::clear()
{
    // This compiles, but may not be correct
    m_ship.erase(m_ship.begin(),m_ship.end());
    for(int r = 0; r < m_game.rows(); r++)
        for(int c = 0; c < m_game.cols(); c++)
        {
            m_grid[r][c] = '.';
            blocked[r][c] = false;
        }
}

void BoardImpl::block()
{
    // Block cells with 50% probability
    for (int r = 0; r < m_game.rows(); r++)
        for (int c = 0; c < m_game.cols(); c++)
            if (randInt(2) == 0)
            {
                blocked[r][c] = true;
            }
}

void BoardImpl::unblock()
{
    for (int r = 0; r < m_game.rows(); r++)
        for (int c = 0; c < m_game.cols(); c++)
        {
            if(blocked[r][c]==true)
                blocked[r][c] = false;
        }
}

bool BoardImpl::placeShip(Point topOrLeft, int shipId, Direction dir)
{
    
    if(shipId >= m_game.nShips() || shipId < 0)
    return false;
    if(topOrLeft.r < 0 || topOrLeft.r >= nRow)
        return false;
    if(topOrLeft.c < 0 || topOrLeft.c >= nCol)
        return false;
    if(dir == VERTICAL && (topOrLeft.r + m_game.shipLength(shipId) > nRow))
        return false;
    if(dir == HORIZONTAL && (topOrLeft.c + m_game.shipLength(shipId)>nCol))
        return false;
    for(int i = 0; i < m_game.shipLength(shipId);i++)
    {
        if(dir == VERTICAL && m_grid[topOrLeft.r+i][topOrLeft.c] != '.')
            return false;
        if(dir == HORIZONTAL && m_grid[topOrLeft.r][topOrLeft.c+i]!='.')
            return false;
        if(dir == VERTICAL && blocked[topOrLeft.r+i][topOrLeft.c] == true)
            return false;
        if(dir == HORIZONTAL && blocked[topOrLeft.r][topOrLeft.c+i] == true)
            return false;
    }
    for(vector<ship>::iterator p = m_ship.begin(); p != m_ship.end();p++)
    {
        if(p->shipID == shipId)
            return false;
    }
    ship A;
    A.m_length = m_game.shipLength(shipId);
    A.shipID = shipId;
      for(int i = 0; i < m_game.shipLength(shipId);i++)
      {
          if(dir == VERTICAL)
          {
              m_grid[topOrLeft.r+i][topOrLeft.c] = m_game.shipSymbol(shipId);
              A.m_point.push_back(Point(topOrLeft.r+i,topOrLeft.c));
          }
          if(dir == HORIZONTAL)
          {
              m_grid[topOrLeft.r][topOrLeft.c+i] = m_game.shipSymbol(shipId);
              A.m_point.push_back(Point(topOrLeft.r,topOrLeft.c+i));
          }
      }
    m_ship.push_back(A);
    return true;
}

bool BoardImpl::unplaceShip(Point topOrLeft, int shipId, Direction dir)
{
    if(shipId < 0 || shipId >= m_game.nShips())
        return false;
    if(dir == VERTICAL && m_grid[topOrLeft.r+1][topOrLeft.c] =='.')
        return false;
    if(dir == HORIZONTAL && m_grid[topOrLeft.r][topOrLeft.c+1] == '.')
        return false;
    for(int i = 0; i < m_game.shipLength(shipId);i++)
    {
        if(dir == VERTICAL)
        {
            m_grid[topOrLeft.r+i][topOrLeft.c] = '.';
        }
        if(dir == HORIZONTAL)
        {
            m_grid[topOrLeft.r][topOrLeft.c+i] = '.';
        }
    }
//    if(!m_ship.empty()){
//    for(vector<ship>::iterator p = m_ship.begin(); p != m_ship.end(); p++)
//    {
//        if(p->m_length == m_game.shipLength(shipId))
//            m_ship.erase(p);
//    }
//}
    return true;
}

void BoardImpl::display(bool shotsOnly) const
{
    if(shotsOnly == false)
    {
        for (int r = 0; r < 11; r++)
        {
            for (int c = 0; c < 12; c++)
            {
                if(r == 0)
                {
                    if((c == 0 )||(c == 1))
                    {
                        cout << ' ';
                        continue;
                    }
                }
                if(r == 0 && c>=2)
                {
                    cout << c-2;
                    continue;
                }
                if(c == 0 && r != 0)
                {
                    cout << r-1;
                    continue;
                }
                if(c == 1 && r != 0)
                {
                    cout << ' ';
                    continue;
                }
                cout << m_grid[r-1][c-2];
            }
            cout<<endl;
        }
    }
    if(shotsOnly == true)
    {
        for (int r = 0; r < 11; r++)
        {
            for (int c = 0; c < 12; c++)
            {
                if(r == 0)
                {
                    if((c == 0 )||(c == 1))
                    {
                        cout << ' ';
                        continue;
                    }
                }
                if(r == 0 && c>=2)
                {
                    cout << c-2;
                    continue;
                }
                if(c == 0 && r != 0)
                {
                    cout << r-1;
                    continue;
                }
                if(c == 1 && r != 0)
                {
                    cout << ' ';
                    continue;
                }
                if(m_grid[r-1][c-2] == 'o' || m_grid[r-1][c-2] == 'X')
                cout << m_grid[r-1][c-2];
                else
                    cout << '.';
            }
            cout<<endl;
        }
    }
}

bool BoardImpl::attack(Point p, bool& shotHit, bool& shipDestroyed, int& shipId)
{
    if(p.r< 0 || p.r >= m_game.rows()||p.c < 0 || p.c >= m_game.cols())
        return false;
    if(m_grid[p.r][p.c] == 'X'||m_grid[p.r][p.c] == 'o')
        return false;
    if(m_grid[p.r][p.c] == 'A' || m_grid[p.r][p.c] == 'B' || m_grid[p.r][p.c] == 'S' || m_grid[p.r][p.c] == 'D' || m_grid[p.r][p.c] == 'P')
    {
        shotHit = true;
        m_grid[p.r][p.c] = 'X';
        
        for(vector<ship>::iterator m = m_ship.begin(); m != m_ship.end(); m++)
        {
            for(vector<Point>::iterator n = m->m_point.begin();n != m->m_point.end(); n++)
            {
                if(n->r == p.r && n->c == p.c){
                    m->m_length--;
                if(m->m_length == 0)
                {
                    shipDestroyed = true;
                    shipId = m->shipID;
                }
                
                }
            }
        }
    }
    else{
       m_grid[p.r][p.c] = 'o';
        shotHit=false;
    }
    
    return true;
}

bool BoardImpl::allShipsDestroyed() const
{
    bool result = true;
    for(vector<ship>::const_iterator m = m_ship.begin(); m != m_ship.end(); m++)
    {
        if(m->m_length!=0)
        {
            result = false;
            break;
        }
    }
    return result; // This compiles, but may not be correct
}

//******************** Board functions ********************************

// These functions simply delegate to BoardImpl's functions.
// You probably don't want to change any of this code.

Board::Board(const Game& g)
{
    m_impl = new BoardImpl(g);
}

Board::~Board()
{
    delete m_impl;
}

void Board::clear()
{
    m_impl->clear();
}

void Board::block()
{
    return m_impl->block();
}

void Board::unblock()
{
    return m_impl->unblock();
}

bool Board::placeShip(Point topOrLeft, int shipId, Direction dir)
{
    return m_impl->placeShip(topOrLeft, shipId, dir);
}

bool Board::unplaceShip(Point topOrLeft, int shipId, Direction dir)
{
    return m_impl->unplaceShip(topOrLeft, shipId, dir);
}

void Board::display(bool shotsOnly) const
{
    m_impl->display(shotsOnly);
}

bool Board::attack(Point p, bool& shotHit, bool& shipDestroyed, int& shipId)
{
    return m_impl->attack(p, shotHit, shipDestroyed, shipId);
}

bool Board::allShipsDestroyed() const
{
    return m_impl->allShipsDestroyed();
}
