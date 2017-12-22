//
//  main.cpp
//  newSet
//
//  Created by Jacob on 4/16/17.
//  Copyright © 2017 Jacob. All rights reserved.
//


#include "newSet.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


int main()
{
    ////////////////
    // test cases //
    // for old set//
    ////////////////
    ////////////////
    // test cases //
    // for new set//
    ////////////////
    
    // general test cases
    {
        Set a(1000);   // a can hold at most 1000 distinct items
        Set b(5);      // b can hold at most 5 distinct items
        Set c;         // c can hold at most DEFAULT_MAX_ITEMS distinct items
        
        ItemType v[6] = { 0, 1, 2, 3, 4, 5 };
        
        assert( c.insert(1) );
        c = c;
        assert( c.size() == 1 );
        
        // No failures inserting 5 distinct items into b
        for (int k = 0; k < 5; k++)
            assert(b.insert(v[k]));
        assert(!b.empty());
        assert(b.size()==5);
        // Failure if we try to insert a sixth distinct item into b
        assert(!b.insert(v[5]));
        Set d(b);
        assert(!d.empty());
        assert(d.size()==5);
        // Failure if we try to insert a sixth distinct item into b
        assert(!d.insert(v[5]));
    }
    // test cases for swap
    {
        Set emptySet;
        Set capacitySix(6);
        assert( emptySet.empty() );
        assert( capacitySix.empty() );
        assert( capacitySix.insert(1) );
        assert( capacitySix.insert(2) );
        assert( capacitySix.insert(3) );
        assert( capacitySix.size()==3 );
        
        emptySet.swap( capacitySix );
        ItemType result;
        assert( emptySet.get(0, result) );
        assert( result == 1 );
        assert( emptySet.get(1, result) );
        assert( result == 2 );
        assert( emptySet.get(2, result) );
        assert( result == 3 );
        assert( !emptySet.get(3, result) );
        assert( result == 3 );
        assert( emptySet.size()==3 );
        assert( capacitySix.empty() );
        
        emptySet.swap( capacitySix );
        emptySet.swap( capacitySix );
        capacitySix.swap( emptySet );
        assert( emptySet.empty() );
        assert( capacitySix.size()==3 );
        
        
    }
    // test cases for =
    {
        Set a, b;
        Set c(5), d(4);
        c.insert(1);
        c.insert(2);
        c.insert(3);
        c.insert(4);
        c.insert(5);
        d.insert(1);
        d.insert(2);
        d.insert(3);
        
        assert( c.size() == 5 );
        assert( d.size() == 3 );
        
        ItemType result;
        assert( c.get(0, result) );
        assert( result == 1 );
        assert( c.get(2, result) );
        assert( result == 3 );
        assert( d.get(1, result) );
        assert( result == 2 );
        assert( d.get(2, result) );
        assert( result == 3 );
        
        assert( !c.insert(0) );
        
        a = c;
        b = d;
        assert( a.size() == 5 );
        assert( b.size() == 3 );
        
        assert( a.get(0, result) );
        assert( result == 1 );
        assert( a.get(2, result) );
        assert( result == 3 );
        assert( b.get(1, result) );
        assert( result == 2 );
        assert( b.get(2, result) );
        assert( result == 3 );
        
        assert( !a.insert(0) );
        
    }
    
    cerr << "Passed all tests." << endl;
    return 0;
}
