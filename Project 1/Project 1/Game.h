//
//  Game.hpp
//  Project 1
//
//  Created by Jacob on 4/8/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <string>
using namespace std;

class Arena;
class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nRats);
    ~Game();
    
    // Mutators
    void play();
    
private:
    Arena* m_arena;
    
    // Helper functions
    string takePlayerTurn();
};

bool decodeDirection(char ch, int& dir);
bool recommendMove(const Arena& a, int r, int c, int& bestDir);
int computeDanger(const Arena& a, int r, int c);
#endif /* Game_h */
