//
//  maze.cpp
//  HW3
//
//  Created by Jacob on 5/8/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

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


bool pathExists(char maze[][10], int sr, int sc, int er, int ec)        //Checks to see if a 10x10 maze is solvable given the start and end coordinates
{
    if (sr == er && sc == ec)   //If our start coordinates match our end coordinates then it is solvable
        return true;
    
    maze[sr][sc] = '#';     //Upadate the maze of new start coordinates
    
    if (sr != 0 && maze[sr - 1][sc] != 'X' && maze[sr-1][sc] != '#')   //NORTH
        if (pathExists(maze, sr -1, sc, er, ec))
            return true;
    
    if (sc != 9 && maze[sr][sc + 1] != 'X' && maze[sr][sc + 1] != '#')   //EAST
        if (pathExists(maze, sr, sc + 1, er, ec))
            return true;
    
    if (sr != 9 && maze[sr + 1][sc] != 'X' && maze[sr+1][sc] != '#')   //SOUTH
        if (pathExists(maze, sr +1, sc, er, ec))
            return true;
 
    if (sc != 0 && maze[sr][sc - 1] != 'X' && maze[sr][sc - 1] != '#')   //WEST
        if (pathExists(maze, sr, sc - 1, er, ec))
            return true;
    
    return false;
}
