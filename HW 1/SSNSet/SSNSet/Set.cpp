//
//  Set.cpp
//  Project 2
//
//  Created by Jacob on 4/15/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include "Set.h"
#include <iostream>
#include <string>
using namespace std;

Set :: Set()
{
    m_Size = 0;
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
    if(DEFAULT_MAX_ITEMS <= m_Size || this-> contains(value))
        return false;
    else
        m_Set[m_Size] = value;
    m_Size++;
    return true;
}

bool Set :: erase(const ItemType& value)
{
    bool result = false;
    for(int i = 0; i < m_Size; i++)
    {
        if(m_Set[i] == value)
        {
            for(int k = i ; k < m_Size ; k++)
            {
                m_Set[k] = m_Set[k+1];
                result = true;
            }
            m_Set[m_Size-1] = ItemType();
            m_Size--;
        }
    }
    return result;
}

bool Set :: contains(const ItemType& value) const
{
    for(int i = 0; i < m_Size; i++)
    {
        if(m_Set[i] == value)
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
        sorted[k] = m_Set[k];
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
    int size = 0;
    ItemType temp;
    int tempsize;
    if(m_Size >= other.size())
        size = m_Size;
    else
        size = other.size();
    for(int i = 0; i < size; i++)
    {
        temp = m_Set[i];
        m_Set[i] = other.m_Set[i];
        other.m_Set[i] = temp;
    }
    tempsize = m_Size;
    m_Size = other.size();
    other.m_Size = tempsize;
}






