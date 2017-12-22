//
//  newSet.cpp
//  newSet
//
//  Created by Jacob on 4/16/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include "newSet.h"
#include <iostream>
#include <string>
using namespace std;

Set :: Set()//create an empty set
{
    m_Size = 0;
    newSet = new ItemType [DEFAULT_MAX_ITEMS];
    m_Capacity = DEFAULT_MAX_ITEMS;
}

Set :: Set(int number)//create a set whose size is decided by the number argument
{
    if(number < 0)
    {
        exit(1);
    }
    newSet = new ItemType [number];
    m_Size = 0;
    m_Capacity = number;
}

Set :: Set(const Set &a)//copy constructor
{
    m_Capacity = a.m_Capacity;
    m_Size = a.m_Size;
    newSet = new ItemType [a.m_Capacity];
    for(int i = 0; i < m_Size; i++)
    {
        newSet[i] = a.newSet[i];
    }
}

Set& Set :: operator=(const Set &a)//equal operator
{
    if(this != &a)
    {
        Set temp(a);
        swap(temp);
    }
    return *this;
}


bool Set :: empty() const
{
    if(m_Size == 0)
        return true;
    else
        return false;
}

int Set :: size() const
{
    return m_Size;
}

bool Set :: insert(const ItemType& value)
{
    if(m_Capacity == m_Size || this-> contains(value))
        return false;
    else
        newSet[m_Size] = value;
    m_Size++;
    return true;
}

bool Set :: erase(const ItemType& value)
{
    bool result = false;
    for(int i = 0; i < m_Size; i++)
    {
        if(newSet[i] == value)
        {
            for(int k = i ; k < m_Size ; k++)
            {
                newSet[k] = newSet[k+1];
                result = true;
            }
            newSet[m_Size-1] = ItemType();
            m_Size--;
        }
    }
    return result;
}

bool Set :: contains(const ItemType& value) const
{
    for(int i = 0; i < m_Size; i++)
    {
        if(newSet[i] == value)
            return true;
    }
    return false;
}

bool Set :: get(int i, ItemType &value) const
{
    ItemType temp;
    ItemType sorted[200];
    
    for(int k = 0; k < m_Size; k++)
    {
        sorted[k] = newSet[k];
    }
    
    for(int k= 0;k < m_Size;k++)
    {
        for(int j=k+1;j < m_Size;j++)
        {
            if(sorted[k] > sorted[j])
            {
                temp = sorted[k];
                sorted[k] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    
    
    if(i >= 0 && i < m_Size)
    {
        value = sorted[i];
        return true;
    }
    else
        return false;
}

void Set :: swap(Set& other)
{
    int temp = 0;
    ItemType* ptr;
    ptr = other.newSet;
    other.newSet = newSet;
    newSet = ptr;
    temp = other.m_Size;
    other.m_Size = m_Size;
    m_Size = temp;
    temp = other.m_Capacity;
    other.m_Capacity = m_Capacity;
    m_Capacity = temp;
}

Set :: ~Set()
{
    delete [] newSet;
}
