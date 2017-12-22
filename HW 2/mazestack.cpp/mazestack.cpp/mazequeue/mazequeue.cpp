//
//  mazequeue.cpp
//  mazestack.cpp
//
//  Created by Jacob on 4/29/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include <queue>
#include <iostream>
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
int main()
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
    if (pathExists(maze, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}
