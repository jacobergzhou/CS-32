//
//  main.cpp
//  Project 2
//
//  Created by Jacob on 4/20/17.
//  Copyright © 2017 Jacob. All rights reserved.
//
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "Set.h"

int main()
{
// constructor
{
    Set s;
}
// copy constructor
{
    Set s;
    // works for empty sets?
    Set empty(s);
    assert( empty.empty() );
    // works for regular sets?
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    for ( int i = 0; i <= 9; i++ )
    {
        assert( s.insert(str[i]) );
    }
    string result;
    assert( s.get( 0, result ) );
    assert( result == "a" );
    assert( s.get( 1, result ) );
    assert( result == "b" );
    assert( s.get( 2, result ) );
    assert( result == "c" );
    assert( s.get( 3, result ) );
    assert( result == "d" );
    assert( s.get( 4, result ) );
    assert( result == "e" );
    assert( s.get( 5, result ) );
    assert( result == "f" );
    assert( s.get( 6, result ) );
    assert( result == "g" );
    assert( s.get( 7, result ) );
    assert( result == "h" );
    assert( s.get( 8, result ) );
    assert( result == "i" );
    assert( s.get( 9, result ) );
    assert( result == "j" );
    
    Set anotherSet(s);
    assert( anotherSet.size() == 10 );
    assert( anotherSet.get( 0, result ) );
    assert( result == "a" );
    assert( anotherSet.get( 1, result ) );
    assert( result == "b" );
    assert( anotherSet.get( 2, result ) );
    assert( result == "c" );
    assert( anotherSet.get( 3, result ) );
    assert( result == "d" );
    assert( anotherSet.get( 4, result ) );
    assert( result == "e" );
    assert( anotherSet.get( 5, result ) );
    assert( result == "f" );
    assert( anotherSet.get( 6, result ) );
    assert( result == "g" );
    assert( anotherSet.get( 7, result ) );
    assert( result == "h" );
    assert( anotherSet.get( 8, result ) );
    assert( result == "i" );
    assert( anotherSet.get( 9, result ) );
    assert( result == "j" );
    
    
}
// destructor

// operator =
{
    Set aSet, anotherSet;
    string result;
    // works for empty sets?
    assert( aSet.empty() );
    assert( anotherSet.empty() );
    anotherSet = aSet;
    assert( aSet.empty() );
    assert( anotherSet.empty() );
    // works of regular sets?
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    for ( int i = 0; i <= 9; i++ )
    {
        assert( aSet.insert(str[i]) );
    }
    anotherSet = aSet;
    assert( anotherSet.size() == 10 );
    assert( anotherSet.get( 0, result ) );
    assert( result == "a" );
    assert( anotherSet.get( 1, result ) );
    assert( result == "b" );
    assert( anotherSet.get( 2, result ) );
    assert( result == "c" );
    assert( anotherSet.get( 3, result ) );
    assert( result == "d" );
    assert( anotherSet.get( 4, result ) );
    assert( result == "e" );
    assert( anotherSet.get( 5, result ) );
    assert( result == "f" );
    assert( anotherSet.get( 6, result ) );
    assert( result == "g" );
    assert( anotherSet.get( 7, result ) );
    assert( result == "h" );
    assert( anotherSet.get( 8, result ) );
    assert( result == "i" );
    assert( anotherSet.get( 9, result ) );
    assert( result == "j" );
    // works for same-item assignment?
    aSet = aSet;
    assert( aSet.size() == 10 );
    assert( aSet.get( 0, result ) );
    assert( result == "a" );
    assert( aSet.get( 1, result ) );
    assert( result == "b" );
    assert( aSet.get( 2, result ) );
    assert( result == "c" );
    assert( aSet.get( 3, result ) );
    assert( result == "d" );
    assert( aSet.get( 4, result ) );
    assert( result == "e" );
    assert( aSet.get( 5, result ) );
    assert( result == "f" );
    assert( aSet.get( 6, result ) );
    assert( result == "g" );
    assert( aSet.get( 7, result ) );
    assert( result == "h" );
    assert( aSet.get( 8, result ) );
    assert( result == "i" );
    assert( aSet.get( 9, result ) );
    assert( result == "j" );
}
// empty()
{
    Set s;
    assert( s.empty() );
    assert( s.insert("0") );
    assert( !s.empty() );
    assert( s.insert("a") );
    assert( !s.empty() );
    assert( s.insert("b") );
    assert( !s.empty() );
    assert( s.insert("c") );
    assert( !s.empty() );
}
// size()
{
    Set s;
    assert( s.size() == 0 );
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    // correct while inserting
    for ( int i = 0; i <= 9; i++ )
    {
        assert( s.insert(str[i]) );
        assert( s.size() == i+1 );
    }
    // correct while erasing
    for ( int i = 9; i >= 0; i-- )
    {
        assert( s.erase(str[i]) );
        assert( s.size() == i );
    }
}
// insert()
{
    Set s;
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    // if a value can be inserted
    for ( int i = 0; i <= 9; i++ )
    {
        assert( s.insert(str[i]) );
    }
    string result;
    assert( s.get( 0, result ) );
    assert( result == "a" );
    assert( s.get( 1, result ) );
    assert( result == "b" );
    assert( s.get( 2, result ) );
    assert( result == "c" );
    assert( s.get( 3, result ) );
    assert( result == "d" );
    assert( s.get( 4, result ) );
    assert( result == "e" );
    assert( s.get( 5, result ) );
    assert( result == "f" );
    assert( s.get( 6, result ) );
    assert( result == "g" );
    assert( s.get( 7, result ) );
    assert( result == "h" );
    assert( s.get( 8, result ) );
    assert( result == "i" );
    assert( s.get( 9, result ) );
    assert( result == "j" );
    // if a value cannot be inserted (already exists)
    for ( int i = 9; i >= 0; i-- )
    {
        assert( !s.insert(str[i]) );
    }
    assert( s.get( 0, result ) );
    assert( result == "a" );
    assert( s.get( 1, result ) );
    assert( result == "b" );
    assert( s.get( 2, result ) );
    assert( result == "c" );
    assert( s.get( 3, result ) );
    assert( result == "d" );
    assert( s.get( 4, result ) );
    assert( result == "e" );
    assert( s.get( 5, result ) );
    assert( result == "f" );
    assert( s.get( 6, result ) );
    assert( result == "g" );
    assert( s.get( 7, result ) );
    assert( result == "h" );
    assert( s.get( 8, result ) );
    assert( result == "i" );
    assert( s.get( 9, result ) );
    assert( result == "j" );
}
// erase()
{
    Set s;
    // works for empty sets?
    assert( !s.erase("") );
    assert( !s.erase("1zxz") );
    assert( !s.erase("ZX") );
    assert( !s.erase("fgbnm") );
    assert( !s.erase("0") );
    assert( !s.erase("12") );
    // works for regular sets?
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    string anotherStr[10] = {"k", "l", "m", "n", "o", "p", "q", "r", "s", "t" };
    for ( int i = 0; i <= 9; i++ )
    {
        assert( s.insert(str[i]) );
    }
    // if a value cannot be erased
    for ( int i = 0; i <= 9; i++ )
    {
        assert( !s.erase(anotherStr[i]) );
    }
    string result;
    assert( s.get( 0, result ) );
    assert( result == "a" );
    assert( s.get( 1, result ) );
    assert( result == "b" );
    assert( s.get( 2, result ) );
    assert( result == "c" );
    assert( s.get( 3, result ) );
    assert( result == "d" );
    assert( s.get( 4, result ) );
    assert( result == "e" );
    assert( s.get( 5, result ) );
    assert( result == "f" );
    assert( s.get( 6, result ) );
    assert( result == "g" );
    assert( s.get( 7, result ) );
    assert( result == "h" );
    assert( s.get( 8, result ) );
    assert( result == "i" );
    assert( s.get( 9, result ) );
    assert( result == "j" );
    // if a value can be erased
    for ( int i = 0; i <= 7; i++ )
    {
        assert( s.erase(str[i]) );
    } // only "i" and "j" should be left
    assert( s.size() == 2 );
    assert( s.get( 0, result ) );
    assert( result == "i" );
    assert( s.get( 1, result ) );
    assert( result == "j" );
}
// contains()
{
    Set s;
    // works for empty sets?
    assert( s.empty() );
    assert( !s.contains("") );
    assert( !s.contains("a") );
    assert( !s.contains("b") );
    assert( !s.contains("0") );
    assert( !s.contains("%") );
    // works for regular sets?
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    string anotherStr[10] = {"k", "l", "m", "n", "o", "p", "q", "r", "s", "t" };
    for ( int i = 0; i <= 9; i++ )
    {
        assert( !s.contains(str[i]) );
        assert( s.insert(str[i]) );
        assert( s.contains(str[i]) );
        assert( !s.contains(anotherStr[i]) );
    }
}
// get()
{
    Set s;
    string result;
    // works for empty sets?
    for ( int i = 0; i <= 5; i++ )
        assert( !s.get( i, result ) );
        // when pos is legal
        string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
        for ( int i = 0; i <= 9; i++ )
        {
            assert( s.insert(str[i]) );
            assert( s.get( i, result ) );
            assert( result == str[i] );
        }
    assert( result == "j" );
    // when pos is out of range
    assert( !s.get( -1, result ) );
    assert( result == "j" );
    assert( !s.get( 10, result ) );
    assert( result == "j" );
    assert( !s.get( 23, result ) );
    assert( result == "j" );
}
// swap()
{
    Set aSet, anotherSet;
    string result;
    // works for empty sets?
    assert( aSet.empty() );
    assert( anotherSet.empty() );
    swap( aSet, anotherSet );
    assert( aSet.empty() );
    assert( anotherSet.empty() );
    // works of regular sets?
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    string anotherStr[8] = {"k", "l", "m", "n", "o", "p", "q", "r"};
    for ( int i = 0; i <= 9; i++ )
    {
        assert( aSet.insert(str[i]) );
    }
    assert( aSet.size() == 10 );
    assert( aSet.get( 0, result ) );
    assert( result == "a" );
    assert( aSet.get( 1, result ) );
    assert( result == "b" );
    assert( aSet.get( 2, result ) );
    assert( result == "c" );
    assert( aSet.get( 3, result ) );
    assert( result == "d" );
    assert( aSet.get( 4, result ) );
    assert( result == "e" );
    assert( aSet.get( 5, result ) );
    assert( result == "f" );
    assert( aSet.get( 6, result ) );
    assert( result == "g" );
    assert( aSet.get( 7, result ) );
    assert( result == "h" );
    assert( aSet.get( 8, result ) );
    assert( result == "i" );
    assert( aSet.get( 9, result ) );
    assert( result == "j" );
    for ( int i = 0; i <= 7; i++ )
    {
        assert( anotherSet.insert(anotherStr[i]) );
    }
    assert( anotherSet.size() == 8 );
    assert( anotherSet.get( 0, result ) );
    assert( result == "k" );
    assert( anotherSet.get( 1, result ) );
    assert( result == "l" );
    assert( anotherSet.get( 2, result ) );
    assert( result == "m" );
    assert( anotherSet.get( 3, result ) );
    assert( result == "n" );
    assert( anotherSet.get( 4, result ) );
    assert( result == "o" );
    assert( anotherSet.get( 5, result ) );
    assert( result == "p" );
    assert( anotherSet.get( 6, result ) );
    assert( result == "q" );
    
    swap( aSet, anotherSet );
    swap( anotherSet, aSet );
    swap( aSet, anotherSet );
    
    // check new anotherSet
    assert( anotherSet.size() == 10 );
    assert( anotherSet.get( 0, result ) );
    assert( result == "a" );
    assert( anotherSet.get( 1, result ) );
    assert( result == "b" );
    assert( anotherSet.get( 2, result ) );
    assert( result == "c" );
    assert( anotherSet.get( 3, result ) );
    assert( result == "d" );
    assert( anotherSet.get( 4, result ) );
    assert( result == "e" );
    assert( anotherSet.get( 5, result ) );
    assert( result == "f" );
    assert( anotherSet.get( 6, result ) );
    assert( result == "g" );
    assert( anotherSet.get( 7, result ) );
    assert( result == "h" );
    assert( anotherSet.get( 8, result ) );
    assert( result == "i" );
    assert( anotherSet.get( 9, result ) );
    assert( result == "j" );
    
    swap( aSet, anotherSet );
    swap( aSet, anotherSet );
    
    // check new aSet
    assert( aSet.size() == 8 );
    assert( aSet.get( 0, result ) );
    assert( result == "k" );
    assert( aSet.get( 1, result ) );
    assert( result == "l" );
    assert( aSet.get( 2, result ) );
    assert( result == "m" );
    assert( aSet.get( 3, result ) );
    assert( result == "n" );
    assert( aSet.get( 4, result ) );
    assert( result == "o" );
    assert( aSet.get( 5, result ) );
    assert( result == "p" );
    assert( aSet.get( 6, result ) );
    assert( result == "q" );
    
}
// unite()
{
    Set a, b;
    Set resultSet;
    string result;
    assert( resultSet.insert("daac") ); // result may not be empty
    assert( resultSet.insert("adaszc") );
    // works for empty sets?
    unite( b, a, resultSet );
    assert( resultSet.empty() );
    unite( a, b, resultSet );
    assert( resultSet.empty() );
    // works for regular sets?
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    string anotherStr[10] = {"k", "l", "e", "f", "g", "m", "a", "b", "c", "d"  };
    for ( int i = 0; i <= 9; i++ )
    {
        assert( a.insert(str[i]) );
        assert( b.insert(anotherStr[i]) );
    }
    unite( a, b, resultSet );
    assert( resultSet.size() == 13 );
    assert( resultSet.get( 0, result ) );
    assert( result == "a" );
    assert( resultSet.get( 1, result ) );
    assert( result == "b" );
    assert( resultSet.get( 2, result ) );
    assert( result == "c" );
    assert( resultSet.get( 3, result ) );
    assert( result == "d" );
    assert( resultSet.get( 4, result ) );
    assert( result == "e" );
    assert( resultSet.get( 5, result ) );
    assert( result == "f" );
    assert( resultSet.get( 6, result ) );
    assert( result == "g" );
    assert( resultSet.get( 7, result ) );
    assert( result == "h" );
    assert( resultSet.get( 8, result ) );
    assert( result == "i" );
    assert( resultSet.get( 9, result ) );
    assert( result == "j" );
    assert( resultSet.get( 10, result ) );
    assert( result == "k" );
    assert( resultSet.get( 11, result ) );
    assert( result == "l" );
    assert( resultSet.get( 12, result ) );
    assert( result == "m" );
    // communicative?
    unite( b, a, resultSet );
    assert( resultSet.size() == 13 );
    assert( resultSet.get( 0, result ) );
    assert( result == "a" );
    assert( resultSet.get( 1, result ) );
    assert( result == "b" );
    assert( resultSet.get( 2, result ) );
    assert( result == "c" );
    assert( resultSet.get( 3, result ) );
    assert( result == "d" );
    assert( resultSet.get( 4, result ) );
    assert( result == "e" );
    assert( resultSet.get( 5, result ) );
    assert( result == "f" );
    assert( resultSet.get( 6, result ) );
    assert( result == "g" );
    assert( resultSet.get( 7, result ) );
    assert( result == "h" );
    assert( resultSet.get( 8, result ) );
    assert( result == "i" );
    assert( resultSet.get( 9, result ) );
    assert( result == "j" );
    assert( resultSet.get( 10, result ) );
    assert( result == "k" );
    assert( resultSet.get( 11, result ) );
    assert( result == "l" );
    assert( resultSet.get( 12, result ) );
    assert( result == "m" );
    // aliasing
    unite( a, b, a );
    assert( a.size() == 13 );
    assert( a.get( 0, result ) );
    assert( result == "a" );
    assert( a.get( 1, result ) );
    assert( result == "b" );
    assert( a.get( 2, result ) );
    assert( result == "c" );
    assert( a.get( 3, result ) );
    assert( result == "d" );
    assert( a.get( 4, result ) );
    assert( result == "e" );
    assert( a.get( 5, result ) );
    assert( result == "f" );
    assert( a.get( 6, result ) );
    assert( result == "g" );
    assert( a.get( 7, result ) );
    assert( result == "h" );
    assert( a.get( 8, result ) );
    assert( result == "i" );
    assert( a.get( 9, result ) );
    assert( result == "j" );
    assert( a.get( 10, result ) );
    assert( result == "k" );
    assert( a.get( 11, result ) );
    assert( result == "l" );
    assert( a.get( 12, result ) );
    assert( result == "m" );
    unite( a, b, b );
    assert( b.size() == 13 );
    assert( b.get( 0, result ) );
    assert( result == "a" );
    assert( b.get( 1, result ) );
    assert( result == "b" );
    assert( b.get( 2, result ) );
    assert( result == "c" );
    assert( b.get( 3, result ) );
    assert( result == "d" );
    assert( b.get( 4, result ) );
    assert( result == "e" );
    assert( b.get( 5, result ) );
    assert( result == "f" );
    assert( b.get( 6, result ) );
    assert( result == "g" );
    assert( b.get( 7, result ) );
    assert( result == "h" );
    assert( b.get( 8, result ) );
    assert( result == "i" );
    assert( b.get( 9, result ) );
    assert( result == "j" );
    assert( b.get( 10, result ) );
    assert( result == "k" );
    assert( b.get( 11, result ) );
    assert( result == "l" );
    assert( b.get( 12, result ) );
    assert( result == "m" );
    unite( b, a, a );
    assert( a.size() == 13 );
    assert( a.get( 0, result ) );
    assert( result == "a" );
    assert( a.get( 1, result ) );
    assert( result == "b" );
    assert( a.get( 2, result ) );
    assert( result == "c" );
    assert( a.get( 3, result ) );
    assert( result == "d" );
    assert( a.get( 4, result ) );
    assert( result == "e" );
    assert( a.get( 5, result ) );
    assert( result == "f" );
    assert( a.get( 6, result ) );
    assert( result == "g" );
    assert( a.get( 7, result ) );
    assert( result == "h" );
    assert( a.get( 8, result ) );
    assert( result == "i" );
    assert( a.get( 9, result ) );
    assert( result == "j" );
    assert( a.get( 10, result ) );
    assert( result == "k" );
    assert( a.get( 11, result ) );
    assert( result == "l" );
    assert( a.get( 12, result ) );
    assert( result == "m" );
    unite( b, a, b );
    assert( b.size() == 13 );
    assert( b.get( 0, result ) );
    assert( result == "a" );
    assert( b.get( 1, result ) );
    assert( result == "b" );
    assert( b.get( 2, result ) );
    assert( result == "c" );
    assert( b.get( 3, result ) );
    assert( result == "d" );
    assert( b.get( 4, result ) );
    assert( result == "e" );
    assert( b.get( 5, result ) );
    assert( result == "f" );
    assert( b.get( 6, result ) );
    assert( result == "g" );
    assert( b.get( 7, result ) );
    assert( result == "h" );
    assert( b.get( 8, result ) );
    assert( result == "i" );
    assert( b.get( 9, result ) );
    assert( result == "j" );
    assert( b.get( 10, result ) );
    assert( result == "k" );
    assert( b.get( 11, result ) );
    assert( result == "l" );
    assert( b.get( 12, result ) );
    assert( result == "m" );
}
//subtract()
{
    Set a, b;
    Set resultSet;
    string result;
    assert( resultSet.insert("daac") ); // result may not be empty
    assert( resultSet.insert("adaszc") );
    // works for empty sets?
    subtract( b, a, resultSet );
    assert( resultSet.empty() );
    subtract( a, b, resultSet );
    assert( resultSet.empty() );
    // works for regular sets?
    string str[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    string anotherStr[10] = {"k", "l", "e", "f", "g", "m", "a", "b", "c", "d"  };
    for ( int i = 0; i <= 9; i++ )
    {
        assert( a.insert(str[i]) );
        assert( b.insert(anotherStr[i]) );
    }
    subtract( a, b, resultSet ); // resultSet: h i j
    assert( resultSet.size() == 3 );
    assert( resultSet.get( 0, result ) );
    assert( result == "h" );
    assert( resultSet.get( 1, result ) );
    assert( result == "i" );
    assert( resultSet.get( 2, result ) );
    assert( result == "j" );
    // not communicative
    subtract( b, a, resultSet ); // resultSet: k l m
    assert( resultSet.size() == 3 );
    assert( resultSet.get( 0, result ) );
    assert( result == "k" );
    assert( resultSet.get( 1, result ) );
    assert( result == "l" );
    assert( resultSet.get( 2, result ) );
    assert( result == "m" );
    // x-x = empty
    subtract( a, a, resultSet );
    assert( resultSet.empty() );
    subtract( b, b, resultSet );
    assert( resultSet.empty() );
    // aliasing
    subtract( a, b, a );  // a: hij b: abcdefg klm
    assert( a.size() == 3 );
    assert( a.get( 0, result ) );
    assert( result == "h" );
    assert( a.get( 1, result ) );
    assert( result == "i" );
    assert( a.get( 2, result ) );
    assert( result == "j" );
    subtract( a, b, b );  // a: hij b: hij
    assert( b.size() == 3 );
    assert( b.get( 0, result ) );
    assert( result == "h" );
    assert( b.get( 1, result ) );
    assert( result == "i" );
    assert( b.get( 2, result ) );
    assert( result == "j" );
    subtract( b, a, a );  // a: empty b: hij
    assert( a.empty() );
    subtract( b, a, b );  // a: empty b: hij
    assert( b.size() == 3 );
    assert( b.get( 0, result ) );
    assert( result == "h" );
    assert( b.get( 1, result ) );
    assert( result == "i" );
    assert( b.get( 2, result ) );
    assert( result == "j" );
}

cerr << "Passed all test" << endl;
}
