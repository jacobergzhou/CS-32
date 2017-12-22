//
//  Game.cpp
//  Project 3
//
//  Created by Jacob on 5/17/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "globals.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

class GameImpl
{
public:
    GameImpl(int nRows, int nCols);
    int rows() const;
    int cols() const;
    bool isValid(Point p) const;
    Point randomPoint() const;
    bool addShip(int length, char symbol, string name);
    int nShips() const;
    int shipLength(int shipId) const;
    char shipSymbol(int shipId) const;
    string shipName(int shipId) const;
    Player* play(Player* p1, Player* p2, Board& b1, Board& b2, bool shouldPause);
private:
    int m_row;
    int m_col;
    struct ship
    {
        int length;
        char symbol;
        string name;
        int shipID;
    };
    vector<ship> m_ship;
};

void waitForEnter()
{
    cout << "Press enter to continue: ";
    cin.ignore(10000, '\n');
}

GameImpl::GameImpl(int nRows, int nCols)
{
    m_row = nRows;
    m_col = nCols;
}

int GameImpl::rows() const
{
    return m_row;
}

int GameImpl::cols() const
{
    return m_col;
}

bool GameImpl::isValid(Point p) const
{
    return p.r >= 0  &&  p.r < rows()  &&  p.c >= 0  &&  p.c < cols();
}

Point GameImpl::randomPoint() const
{
    return Point(randInt(rows()), randInt(cols()));
}

bool GameImpl::addShip(int length, char symbol, string name)
{
    ship p;
    p.length = length;
    p.symbol = symbol;
    p.name = name;
    p.shipID = GameImpl::nShips();
    m_ship.push_back(p);
    return true;
}

int GameImpl::nShips() const
{
    int total = 0;
    for( size_t i = 0; i < m_ship.size();i++)
        total++;
    return total;
}

int GameImpl::shipLength(int shipId) const
{
    int number = 0;
    for(size_t i = 0; i < m_ship.size(); i++)
    {
        if(m_ship[i].shipID == shipId)
             number = m_ship[i].length;
    }
    return number;
}

char GameImpl::shipSymbol(int shipId) const
{
    char value = '\0';
    for(size_t i = 0; i < m_ship.size(); i++)
    {
        if(m_ship[i].shipID == shipId)
            value = m_ship[i].symbol;
    }
    return value;
}

string GameImpl::shipName(int shipId) const
{
    string value;
    for(size_t i = 0; i < m_ship.size(); i++)
    {
        if(m_ship[i].shipID == shipId)
            value = m_ship[i].name;
    }
    return value;
}

Player* GameImpl::play(Player* p1, Player* p2, Board& b1, Board& b2, bool shouldPause=true)
{
   
    if(p1->placeShips(b1) == false || p2-> placeShips(b2) == false)
    return nullptr;
   
    while( !b1.allShipsDestroyed()&&! b2.allShipsDestroyed())
    {
        bool shotHit=false,shipDestroyed=false;
        int shipId=0;
        cout << p1->name() <<"'s turn. Board for " << p2->name() << ":"<<endl;
        if(p1->isHuman())
            b2.display(true);
        else
            b2.display(false);
        Point temp = p1->recommendAttack();
        if(b2.attack(temp, shotHit, shipDestroyed, shipId))
        {
            p1->recordAttackResult(temp, true, shotHit, shipDestroyed, shipId);
            p2->recordAttackByOpponent(temp);
            if(shotHit)
                cout << p1->name() << " attacked (" << temp.r <<"," << temp.c << ") " << "and hit something, resulting in:" << endl;
            else
                cout << p1->name() << " attacked (" << temp.r <<"," << temp.c << ") " << "and missed, resulting in:" << endl;
        }
        else
            cout << p1->name() << " wasted a shot at " << "(" <<temp.r<<"," <<temp.c <<")."<<endl;
        
        if(p1->isHuman())
            b2.display(true);
        else
            b2.display(false);
        if(shouldPause)
            waitForEnter();
        
        shotHit=false;
        shipDestroyed=false;
        shipId=0;
        cout<< p2->name() << "'s turn. Board for "<< p1->name() << ":" << endl;
        if(p2->isHuman())
            b1.display(true);
        else
            b1.display(false);
        Point temp1 = p2->recommendAttack();
        if(b1.attack(temp1, shotHit, shipDestroyed, shipId))
        {
            p2->recordAttackResult(temp1, true, shotHit, shipDestroyed, shipId);
            p1->recordAttackByOpponent(temp1);
            if(shotHit)
                cout << p2->name() << " attacked (" << temp1.r <<"," << temp1.c << ") " << "and hit something, resulting in:" << endl;
            else
                cout << p2->name() << " attacked (" << temp1.r <<"," << temp1.c << ") " << "and missed, resulting in:" << endl;
        }
        else
            cout << p2->name() << " wasted a shot at " << "(" <<temp.r<<"," <<temp.c <<")."<<endl;
        if(p2->isHuman())
            b1.display(true);
        else
            b1.display(false);
        if(shouldPause)
            waitForEnter();
    }
    if(b1.allShipsDestroyed()&&p1->isHuman())
    {
        b2.display(false);
        return p2;
    }
    if(b2.allShipsDestroyed()&&p2->isHuman())
    {
        b1.display(false);
        return p1;
    }
    if(b1.allShipsDestroyed())
        return p2;
    else
        return p1;
}

//******************** Game functions *******************************

// These functions for the most part simply delegate to GameImpl's functions.
// You probably don't want to change any of the code from this point down.

Game::Game(int nRows, int nCols)
{
    if (nRows < 1  ||  nRows > MAXROWS)
    {
        cout << "Number of rows must be >= 1 and <= " << MAXROWS << endl;
        exit(1);
    }
    if (nCols < 1  ||  nCols > MAXCOLS)
    {
        cout << "Number of columns must be >= 1 and <= " << MAXCOLS << endl;
        exit(1);
    }
    m_impl = new GameImpl(nRows, nCols);
}

Game::~Game()
{
    delete m_impl;
}

int Game::rows() const
{
    return m_impl->rows();
}

int Game::cols() const
{
    return m_impl->cols();
}

bool Game::isValid(Point p) const
{
    return m_impl->isValid(p);
}

Point Game::randomPoint() const
{
    return m_impl->randomPoint();
}

bool Game::addShip(int length, char symbol, string name)
{
    if (length < 1)
    {
        cout << "Bad ship length " << length << "; it must be >= 1" << endl;
        return false;
    }
    if (length > rows()  &&  length > cols())
    {
        cout << "Bad ship length " << length << "; it won't fit on the board"
        << endl;
        return false;
    }
    if (!isascii(symbol)  ||  !isprint(symbol))
    {
        cout << "Unprintable character with decimal value " << symbol
        << " must not be used as a ship symbol" << endl;
        return false;
    }
    if (symbol == 'X'  ||  symbol == '.'  ||  symbol == 'o')
    {
        cout << "Character " << symbol << " must not be used as a ship symbol"
        << endl;
        return false;
    }
    int totalOfLengths = 0;
    for (int s = 0; s < nShips(); s++)
    {
        totalOfLengths += shipLength(s);
        if (shipSymbol(s) == symbol)
        {
            cout << "Ship symbol " << symbol
            << " must not be used for more than one ship" << endl;
            return false;
        }
    }
    if (totalOfLengths + length > rows() * cols())
    {
        cout << "Board is too small to fit all ships" << endl;
        return false;
    }
    return m_impl->addShip(length, symbol, name);
}

int Game::nShips() const
{
    return m_impl->nShips();
}

int Game::shipLength(int shipId) const
{
    assert(shipId >= 0  &&  shipId < nShips());
    return m_impl->shipLength(shipId);
}

char Game::shipSymbol(int shipId) const
{
    assert(shipId >= 0  &&  shipId < nShips());
    return m_impl->shipSymbol(shipId);
}

string Game::shipName(int shipId) const
{
    assert(shipId >= 0  &&  shipId < nShips());
    return m_impl->shipName(shipId);
}

Player* Game::play(Player* p1, Player* p2, bool shouldPause)
{
    if (p1 == nullptr  ||  p2 == nullptr  ||  nShips() == 0)
        return nullptr;
    Board b1(*this);
    Board b2(*this);
    return m_impl->play(p1, p2, b1, b2, shouldPause);
}

