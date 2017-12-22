//
//  newSet.cpp
//  Project 2
//
//  Created by Jacob on 4/16/17.
//  Copyright © 2017 Jacob. All rights reserved.
//
/*
#include "newSet.h"
#include <iostream>
#include <string>
using namespace std;

Set :: Set()
{
    m_Size = 0;
}

Set :: Set(int number)
{
    newSet = new ItemType [number];
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
    for(int i = 0; i < m_Size; i++)
    {
        if(m_Set[i] == value)
        {
            break;
            return false;
        }
    }
    m_Size++;
    m_Set[m_Size-1] = value;
    return true;
}

bool Set :: erase(const ItemType& value)
{
    for(int i = 0; i < m_Size; i++)
    {
        if(m_Set[i] == value)
        {
            m_Set[i] = m_Set[i+1];
            return true;
        }
    }
    return false;
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
}

Set :: ~Set()
{
    delete [] newSet;
}

*/



