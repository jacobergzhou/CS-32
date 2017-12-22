//
//  main.cpp
//  SSNSet
//
//  Created by Jacob on 4/16/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include "SSNSet.h"
#include <iostream>
#include <cassert>
using namespace std;

// To test a Set of string, leave the following line commented out;
// to test a Set of unsigned long, remove the "//".

#define USE_UNSIGNED_LONG

#ifdef USE_UNSIGNED_LONG

const ItemType test1 = 9876;
const ItemType test2 = 900000;
const ItemType test3 = 123456789;
const ItemType test4 = 1234567890;
const ItemType test5 = 96000000000;
const ItemType test6 = 950000000000;
const ItemType test7 = 94000000;
const ItemType test8 = 223322323;
const ItemType test9 = 2456766540;
const ItemType test10 =25434564300;
const ItemType test11 =267849023000;
const ItemType test12 =2789403890000;



#else // assume string

const ItemType test1 = "a";
const ItemType test2 = "ab";
const ItemType test3 = "abc";
const ItemType test4 = "abcd";
const ItemType test5 = "abcde";
const ItemType test6 = "abcdef";
const ItemType test7 = "z";
const ItemType test8 = "za";
const ItemType test9 = "zab";
const ItemType test10 = "zabc";
const ItemType test11 = "zabcd";
const ItemType test12 = "zabcde";



#endif

int main()
{
    Set data1;
    Set data2;
    //test empty
    assert(data1.empty());
    assert(data2.empty());
    //test insert;
    assert(data1.insert(test1));
    assert(data1.size()==1);
    assert(!data1.empty());
    assert(data1.insert(test2));
    assert(data1.size()==2);
    assert(data1.insert(test3));
    assert(data1.size()==3);
    assert(data1.insert(test4));
    assert(data1.size()==4);
    assert(data1.insert(test5));
    assert(data1.size()==5);
    assert(data1.insert(test6));
    
    assert(data2.insert(test7));
    assert(data2.size()==1);
    assert(!data2.empty());
    assert(data2.insert(test8));
    assert(data2.size()==2);
    assert(data2.insert(test9));
    assert(data2.size()==3);
    assert(data2.insert(test10));
    assert(data2.size()==4);
    assert(data2.insert(test11));
    assert(data2.size()==5);
    assert(data2.insert(test12));
    
    //test get
    
    ItemType get;
    assert(data1.get(0,get)&&get==test1);
    assert(data1.get(1,get)&&get==test2);
    assert(data1.get(2,get)&&get==test3);
    assert(data1.get(3,get)&&get==test4);
    assert(data1.get(4,get)&&get==test5);
    assert(data1.get(5,get)&&get==test6);
    assert(data2.get(0,get)&&get==test7);
    assert(data2.get(1,get)&&get==test8);
    assert(data2.get(2,get)&&get==test9);
    assert(data2.get(3,get)&&get==test10);
    assert(data2.get(4,get)&&get==test11);
    assert(data2.get(5,get)&&get==test12);
    
    
    //test size
    assert(data1.size()==6);
    assert(data2.size()==6);
    assert(!data1.insert(test1));
    
    
    
    //test swap and contains
    data1.swap(data2);
    assert(data2.contains(test1));
    assert(data2.contains(test2));
    assert(data2.contains(test3));
    assert(data2.contains(test4));
    assert(data2.contains(test5));
    assert(data2.contains(test6));
    assert(data1.contains(test7));
    assert(data1.contains(test8));
    assert(data1.contains(test9));
    assert(data1.contains(test10));
    assert(data1.contains(test11));
    assert(data1.contains(test12));
    data1.swap(data2);
    assert(data1.contains(test1));
    assert(data1.contains(test2));
    assert(data1.contains(test3));
    assert(data1.contains(test4));
    assert(data1.contains(test5));
    assert(data1.contains(test6));
    assert(data2.contains(test7));
    assert(data2.contains(test8));
    assert(data2.contains(test9));
    assert(data2.contains(test10));
    assert(data2.contains(test11));
    assert(data2.contains(test12));
    
    assert(data1.erase(test1));
    assert(! data1.contains(test1)&&data1.size()==5);
    assert(data1.erase(test2));
    assert(! data1.contains(test2)&&data1.size()==4);
    assert(data1.erase(test3));
    assert(! data1.contains(test3)&&data1.size()==3);
    assert(data1.erase(test4));
    assert(! data1.contains(test4)&&data1.size()==2);
    assert(data1.erase(test5));
    assert(! data1.contains(test5)&&data1.size()==1);
    assert(data1.erase(test6));
    assert(! data1.contains(test6) && data1.size()==0 && data1.empty());
    
    SSNSet set1;
    SSNSet set2;
    //test add function
    assert(set1.add(12345));
    assert(set1.add(123));
    assert(set1.add(1234));
    assert(set1.add(123456));
    assert(!(set1.add(123)));
    assert(set1.add(1234567));
    assert(!set1.add(1234));
    
    //test size function
    assert(set1.size()==5);
    assert(set2.size()==0);
    assert(set2.add(2));
    assert(set2.size()==1);
    assert(set2.add(23));
    assert((set2.size()==2));
    assert(set2.add(234));
    assert(set2.size()==3);
    
    //test print function
    set1.print();
    set2.print();
    
    //test SSN
    SSNSet s;
        
        
        s.add(123456789);
        assert(s.size() == 1);
        s.add(1222222);
        assert(s.size() == 2);
        s.add(123123);
        assert(s.size() == 3);
        s.add(12345);
        assert(s.size() == 4);
        s.add(1234);
        assert(s.size() == 5);
        s.print();
        cerr << "Passed all tests" << endl;
    
    
    
}
