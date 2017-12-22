//
//  mazequeue.cpp
//  mazequeue
//
//  Created by Jacob on 4/29/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include <queue>
#include <iostream>
#include <cassert>
using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
{
    queue<Coord> Coordqueue;
    Coord start(sr,sc);
    bool result = false;
    Coordqueue.push(start);
    maze[sr][sc] = '#';
    while(!Coordqueue.empty())
    {
        Coord curr = Coordqueue.front();
        Coordqueue.pop();
        if(curr.r() == er && curr.c() == ec)
        {
            result = true;
            break;
        }
        if(maze[curr.r()-1][curr.c()] != 'X' && maze[curr.r()-1][curr.c()] != '#')
        {
            Coord north(curr.r()-1,curr.c());
            Coordqueue.push(north);
            maze[north.r()][north.c()] = '#';
        }
        if(maze[curr.r()][curr.c()+1] != 'X' && maze[curr.r()][curr.c()+1] != '#')
        {
            Coord east(curr.r(),curr.c()+1);
            Coordqueue.push(east);
            maze[east.r()][east.c()] = '#';
        }
        if(maze[curr.r()+1][curr.c()] != 'X'&& maze[curr.r()+1][curr.c()] != '#')
        {
            Coord south(curr.r()+1,curr.c());
            Coordqueue.push(south);
            maze[south.r()][south.c()] = '#';
        }
        if(maze[curr.r()][curr.c()-1] != 'X'&&maze[curr.r()][curr.c()-1] != '#')
        {
            Coord west(curr.r(),curr.c()-1);
            Coordqueue.push(west);
            maze[west.r()][west.c()] = '#';
        }
    }
    return result;
}
// test cases for maze
int main()
{
    // test Coord
    {
        Coord pos(3 , 5);
        assert( pos.r() == 3 && pos.c() == 5 );
    }
    // test pathExists()
    {
        char maze[10][10] = {
            { 'X','X','X','X','X','X','X','X','X','X'},
            { 'X','.','.','.','.','.','.','.','.','X'},
            { 'X','X','.','X','.','X','X','X','X','X'},
            { 'X','.','.','X','.','X','.','.','.','X'},
            { 'X','.','.','X','.','.','.','X','.','X'},
            { 'X','X','X','X','.','X','X','X','.','X'},
            { 'X','.','X','.','.','.','.','X','X','X'},
            { 'X','.','X','X','X','.','X','X','.','X'},
            { 'X','.','.','.','X','.','.','.','.','X'},
            { 'X','X','X','X','X','X','X','X','X','X'}
        };
        assert( pathExists( maze, 6, 4, 6, 4 ) );
        assert( !pathExists( maze, 6, 4, 8, 1 ) );
    }
    {
        char maze[10][10] = {
            { 'X','X','X','X','X','X','X','X','X','X'},
            { 'X','.','.','.','.','.','.','.','.','X'},
            { 'X','X','.','X','.','X','X','X','X','X'},
            { 'X','.','.','X','.','X','.','.','.','X'},
            { 'X','.','.','X','.','.','.','X','.','X'},
            { 'X','X','X','X','.','X','X','X','.','X'},
            { 'X','.','X','.','.','.','.','X','X','X'},
            { 'X','.','X','X','X','.','X','X','.','X'},
            { 'X','.','.','.','X','.','.','.','.','X'},
            { 'X','X','X','X','X','X','X','X','X','X'}
        };
        assert( pathExists( maze, 6, 4, 1, 1 ) );
    }
    {
        char maze[10][10] = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', 'X', 'X', 'X', 'X'}
        };
        assert( pathExists(maze, 3, 1, 1, 1) );
    }
    {
        char maze[10][10] = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', 'X', 'X', 'X', 'X'}
        };
        assert( pathExists(maze, 3, 1, 3, 1) );
    }
    {
        char maze[10][10] = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', 'X', 'X', 'X', 'X'}
        };
        assert( !pathExists(maze, 3, 1, 5, 1) );
    }
    {
        char maze[10][10] = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', '.', '.', '.', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', 'X', 'X', 'X', 'X'}
        };
        assert( pathExists(maze, 3, 1, 3, 3) );
    }
    {
        char maze[10][10] = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', 'X', 'X', 'X', 'X'}
        };
        assert( !pathExists(maze, 3, 1, 3, 3) );
    }
    {
        char maze[10][10] = {
            {'X', 'X', 'X', 'X', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', '.', 'X', '.', 'X'},
            {'X', 'X', 'X', 'X', 'X'}
        };
        assert( pathExists(maze, 3, 1, 1, 1) );
    }
    
    cerr << "Passed All Tests." << endl;
    return 0;
}
