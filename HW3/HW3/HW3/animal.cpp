//
//  main.cpp
//  HW3
//
//  Created by Jacob on 5/5/17.
//  Copyright © 2017 Jacob. All rights reserved.
//




class Animal
{
public:
    Animal(string name){m_name = name;};
    virtual void speak() const = 0;
    virtual string moveAction() const{
        return  "walk";
    };
    string name() const{
        return m_name;
    };
    virtual ~Animal() {};
private:
    string m_name;
};

class Cat : public Animal
{
public:
    Cat(string name):Animal(name){};
    virtual void speak() const
    {
       cout << "Meow";
    };
     ~Cat(){
        cout << "Destroying ";
        cout << name();
         cout <<" the cat" << endl;
    };
};

class Pig : public Animal
{
public:
    Pig(string name, double weight):Animal(name)
    {
        m_weight = weight;
    };
    virtual void speak() const
    {
        if(m_weight < 170)
            cout << "Oink";
        if(m_weight >= 170)
            cout << "Grunt";
    };
     ~Pig(){
        cout << "Destroying ";
        cout << name();
         cout << " the pig" << endl;
    };
private:
    int m_weight;
};

class Duck : public Animal
{
public:
    Duck(string name):Animal(name){};
    virtual void speak() const
    {
      cout << "Quack";
    };
    virtual string moveAction() const{
      return  "swim";
    };
     ~Duck(){
       cout << "Destroying ";
        cout << name();
         cout << " the duck" << endl;
    };
};
