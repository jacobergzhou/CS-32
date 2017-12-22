//
//  testSet.cpp
//  Project 2
//
//  Created by Jacob on 4/16/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include "Set.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;


// unsigned long
int main()
{
    // test cases on class site
    {
        Set s;
        assert(s.empty());
        ItemType x = 9876543;
        assert( !s.get(42, x)  &&  x == 9876543); // x unchanged by get failure
        s.insert(123456789);
        assert(s.size() == 1);
        assert(s.get(0, x)  &&  x == 123456789);
    }
    // test cases for empty()
    {
        Set s;
        assert( s.empty() );
        assert( s.insert(1) );
        assert( !s.empty() );
        assert( s.erase(1) );
        assert ( s.empty() );
    }
    // test cases for size()
    {
        Set s;
        assert( s.size() == 0 );
        for ( int i = 1; i <= 10; i++ )
        {
            assert( s.size() == i-1 );
            assert( s.insert(i) );
            assert( s.size() == i );
        }
        for ( int j = 1; j <= 10; j++ )
        {
            assert( s.size() == 11-j );
            assert( s.erase(j) );
            assert( s.size() == 10-j );
        }
        assert( s.size() == 0 );
    }
    // test cases for contains()
    {
        Set s;
        for ( int i = 1; i <= 50; i++ )
            assert( s.insert(i) );
        for ( int j = 1; j <= 50; j++ )
            assert( s.contains(51-j) );
    }
    // test cases for insert()
    {
        Set s;
        ItemType result(0);
        // insert values that don't already exist
        for ( int i = 1; i<=200; i++ )
        {
            assert( s.insert(i) ); // insert returns true
            assert( s.size() == i );
            for ( int j = 0; j <= i-1; j++ )  // checking if the right value is inserted
            {
                assert( s.get(j, result) );
                assert( result == j+1 );
            }
        }
        // now the set has 1, 2, ... 200, reaching the capacity
        // trying to insert already existing values
        for ( int j = 1; j<=200; j++ )
        {
            assert( !s.insert(201-j) ); // 201-j already exists
            assert( s.size() == 200 );
        }
        // trying to excceed the capacity
        for ( int k = 201; k<=250; k++ )
        {
            assert ( !s.insert(k) );
            assert ( s.size() == 200 );
        }
    }
    // test cases for erase()
    {
        Set s;
        ItemType result(0);
        for ( int i = 1; i <= 50; i++ ) // establish a set with 50 items, 1, 2, ... 50
            assert( s.insert(i) );
        // try erasing not existing values
        for ( int j = 51; j <= 100; j++ )
            assert( !s.erase(j) );
        for ( int k = 1; k <= 50; k++ )
        {
            assert( s.get( k-1, result ) );
            assert( result == k );
        }
        // erase already existing values
        for ( int l = 1; l <= 49; l++ )
        {
            assert ( s.erase(l) );
            assert ( s.get( 0, result ) );
            assert ( result == l+1 );
        }
        assert ( s.erase(50) );
        assert( s.empty() );
    }
    // test cases for get()
    {
        Set s;
        ItemType result(724);
        for ( int i = 1; i <= 20; i++ )
            assert( s.insert(i) );
        // now s has 1, 2, ... 20, with mSize == 20
        for ( int j = -20; j <= 40; j++ )
        {
            if ( j >= 0 && j < 20 ) // if i is legal a.k.a. i>=0 && i<mSize
            {
                assert ( s.get( j, result ) );
                assert ( result == j+1 );
                result = 724;
            }
            else // if i is illegal
            {
                assert( !s.get( j, result ) );
                assert( result == 724 );
            }
        }
    }
    // test cases for swap()
    {
        Set s, t;
        ItemType result;
        for ( int i = 1; i <= 10; i++ )
        {
            assert( s.insert(2*i-1) );  // s: 1, 3, 5, ... 19. |s| == 10
            assert( t.insert(2*(i+10)) );
            assert( t.insert(2*i) );  // t: 2, 4, 6, ... 20, 22, 24, ... 40. |t| == 20
        }
        assert( s.size() == 10 );
        assert( t.size() == 20 );
        for ( int j = 1; j <= 10; j++ )
        {
            assert( s.get( j-1, result ) );
            assert( result == 2*j-1 );
        }
        for ( int k = 1; k <= 20; k++ )
        {
            assert( t.get( k-1, result ) );
            assert( result == 2*k );
        }
        s.swap(t);
        
        s.swap(t);
        t.swap(s);
        t.swap(s);
        t.swap(s);
        
        assert( t.size() == 10 );
        assert( s.size() == 20 );
        for ( int l = 1; l <= 10; l++ )
        {
            assert( t.get( l-1, result ) );
            assert( result == 2*l-1 );
        }
        for ( int m = 1; m <= 20; m++ )
        {
            assert( s.get( m-1, result ) );
            assert( result == 2*m );
        }
    }
    cerr << "Passed all tests.(unsigned long)" << endl;
}
