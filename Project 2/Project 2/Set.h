//
//  Set.hpp
//  Project 2
//
//  Created by Jacob on 4/20/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#ifndef Set_h
#define Set_h
#include <iostream>
#include <string>
typedef std::string ItemType;


class Set
{
public:
    Set();  //constructor
    ~Set(); //destructor
    Set(const Set& a); //copy constructor
    Set &operator=(const Set&a);//assignment operator
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);
private:
    struct Node
    {
        ItemType data;
        Node* prev;
        Node* next;
    };
    Node *head;
    int m_Size;
};

void unite(const Set& s1, const Set& s2, Set& result);
void subtract(const Set& s1, const Set& s2, Set& result);
#endif /* Set_h */
