//
//  Set.cpp
//  Project 2
//
//  Created by Jacob on 4/20/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include "Set.h"
#include <iostream>
using namespace std;

Set::Set()
{
    head = NULL;//set head to nullptr
    m_Size = 0;
}

Set::~Set()//destructor
{
    
    if(head==NULL)
    {
        delete head;
    }
    else
    {
    Node *a;
    a = head;
    for(a = head; a != nullptr; )//loop through all the element of list
    {
        Node *temp = a;//using temp to store the value
        a = a->next;
        delete temp;
    }
    }
}

Set::Set(const Set& a)
{
    if(a.size() == 0)//if list a is empty
    {
        head = NULL;//set head to nullptr
        m_Size = 0;
    }
    else
    {
        m_Size = a.size();
        Node *p,*q,*r;
        head = new Node;
        p = head;
        r=head;
        
        for(q = a.head; q != nullptr; q = q->next)
    {
        if(q==a.head)//when q is the only element in the list
            p->prev = nullptr;
        else
            p->prev = r;
        
        p->data =q->data;//store the value of p
        if(q->next!= nullptr)//when q is the last element of the list
        p->next = new Node;
        else
        p->next =nullptr;
        r=p;
        p = p->next;
    }
    }
}

Set& Set::operator=(const Set& a)
{
    if(this != &a)
    {
       Set temp(a);//create an temp using a
       swap(temp);
    }
    return *this;
}

int Set::size() const
{
    return m_Size;
}

bool Set::empty() const
{
    if(m_Size == 0)
        return true;
    else
        return false;
}

bool Set::insert(const ItemType&value)
{
    Node *p;
    Node* tail = nullptr;
    bool result = false;
    if(head == NULL)//when the list is empty
    {
        if(!this->contains(value))
        {
        head = new Node;
            head->data = value;
            head->prev = nullptr;
            head->next = nullptr;
            m_Size++;
            return true; 
        }
        else
            return false;
    }
    for(p = head; p!=nullptr && p->data != value; tail=p, p=p->next)
    {;}
    if(p == nullptr)//now tail is the pointer to the last element
    {
        p = new Node;
        p->data = value;
        tail->next = p;
        p->prev =tail;
        
        p->next = nullptr;//since p now is the last
        result = true;
        m_Size++;
    }
    return result;
}

bool Set::erase(const ItemType&value)
{
    bool result = false;
    Node *p;
    
    if(m_Size==1 && this->contains(value))//the case when the list only has one element
    {
        delete head;
        head = NULL;
        m_Size--;
        return true;
    }
    for(p = head; p != nullptr && p->data != value; p=p->next)
    {;}
    if(p != nullptr)
    {
        result = true;
             if(p->next == nullptr)//tail
        {
            p->prev->next = nullptr;// tail-> prev-> null
            delete p;
        }
        
        else if(p->prev == nullptr)//p is the first element
        {   head =p->next;
            p->next->prev =nullptr;
            delete p;
        }
        else{//when p is not the special case
        p->prev->next = p->next;
        p->next->prev = p->prev;
            delete p;
        }
        m_Size--;
        
    }
    return result;
}

bool Set::contains(const ItemType& value) const
{
    bool result = false;
    Node *p;
    for(p = head; p != nullptr && p->data != value; p= p->next)//loop through the list
    {;}
    if(p != nullptr)//when the list contains the value
    {
        result = true;
    }
    return result;
}

bool Set::get(int pos, ItemType &value) const
{
    if(pos >= m_Size || pos < 0)
        return false;
    Node *p,*q;
    int total = 0;//the rank of the value
    for(p = head; p != nullptr; p = p->next)
    {
        for(q = head; q!= nullptr; q =q->next)
        {
           if(p->data > q->data)
               total++;//total represents the tank of the value
        }
        if(total == pos){
            value = p->data;
            break;
        }
        total = 0;
    }
    return true;
}

void Set::swap(Set&other)
{
    int len;//store size
    len = m_Size;
    m_Size = other.m_Size;
    other.m_Size = len;
    Node *p;
    p = head;//store the pointer
    head = other.head;
    other.head = p;
}

void unite(const Set &s1, const Set &s2, Set &result)
{
    Set A;
   
    ItemType s1value, s2value;
    for(int i = 0; i < s1.size(); i++)//loop through all the value of s1
    {
       s1.get(i, s1value);
        A.insert(s1value);//insert to A
    }
    for(int k = 0; k < s2.size(); k++)
    {
        s2.get(k, s2value);
        if(!s1.contains(s2value))
        {
            A.insert(s2value);//insert the element in s2 that is not in s1
        }
    }
    result =A; //set result to A
}

void subtract(const Set& s1, const Set& s2, Set& result)
{
    Set A;
    
    ItemType s1value, s2value;
    
    
    for(int i = 0; i < s1.size(); i++)
    {
        s1.get(i, s1value);
        A.insert(s1value);//insert all the value of s1 to A
    }
    for(int k = 0; k < s2.size(); k++)
    {
        s2.get(k, s2value);
        if(s1.contains(s2value))
        {
            for(int i = 0; i < s1.size(); i++)
            {
                s1.get(i, s1value);
                if(s1value == s2value)//erase the value in A if s2 also has the value in s1
                A.erase(s1value);
            }
        }
    }
    result =A;
}

