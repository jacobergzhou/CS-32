//
//  main.cpp
//  jj
//
//  Created by Jacob on 5/29/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    char m_grid[10][10];
    
    for(int r = 0; r<10;r++){
        for(int c = 0; c<10;c++){
        
        m_grid[r][c]='.';
        
        }
    }
    
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
