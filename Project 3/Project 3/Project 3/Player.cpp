//
//  Player.cpp
//  Project 3
//
//  Created by Jacob on 5/17/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include "Player.h"
#include "Board.h"
#include "Game.h"
#include "globals.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//*********************************************************************
//  AwfulPlayer
//*********************************************************************

class AwfulPlayer : public Player
{
public:
    AwfulPlayer(string nm, const Game& g);
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit,
                                    bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
private:
    Point m_lastCellAttacked;
};

AwfulPlayer::AwfulPlayer(string nm, const Game& g)
: Player(nm, g), m_lastCellAttacked(0, 0)
{}

bool AwfulPlayer::placeShips(Board& b)
{
    // Clustering ships is bad strategy
    for (int k = 0; k < game().nShips(); k++)
        if ( ! b.placeShip(Point(k,0), k, HORIZONTAL))
            return false;
    return true;
}

Point AwfulPlayer::recommendAttack()
{
    if (m_lastCellAttacked.c > 0)
        m_lastCellAttacked.c--;
    else
    {
        m_lastCellAttacked.c = game().cols() - 1;
        if (m_lastCellAttacked.r > 0)
            m_lastCellAttacked.r--;
        else
            m_lastCellAttacked.r = game().rows() - 1;
    }
    return m_lastCellAttacked;
}

void AwfulPlayer::recordAttackResult(Point /* p */, bool /* validShot */,
                                     bool /* shotHit */, bool /* shipDestroyed */,
                                     int /* shipId */)
{
    // AwfulPlayer completely ignores the result of any attack
}

void AwfulPlayer::recordAttackByOpponent(Point /* p */)
{
    // AwfulPlayer completely ignores what the opponent does
}

//*********************************************************************
//  HumanPlayer
//*********************************************************************

bool getLineWithTwoIntegers(int& r, int& c)
{
    bool result(cin >> r >> c);
    if (!result)
        cin.clear();  // clear error state so can do more input operations
    cin.ignore(10000, '\n');
    return result;
}

class HumanPlayer: public Player
{
    public:
        HumanPlayer(string name, const Game&g);
    virtual bool isHuman() const{
        return true;
    }
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit,
                                    bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
};

HumanPlayer::HumanPlayer(string name, const Game&g):Player(name,g)
{}

bool HumanPlayer::placeShips(Board &b)
{
    string dir;
    int r,c,ID=0;
    cout << name() << " must place " << game().nShips() << " ships." << endl;
    b.display(false);
    while(ID <5)
    {
        cout << "Enter h or v for direction of " << game().shipName(ID) <<" (length " << game().shipLength(ID) <<"):";
        getline(cin, dir);
        while(dir[0] != 'h' &&dir[0] != 'v')
        {
            cout << "Direction must be h or v."<< endl;
            cout << "Enter h or v for direction of "<< game().shipName(ID) <<" (length " << game().shipLength(ID) <<"):" << endl;
            getline(cin, dir);
        }
        cout << "Enter row and column of leftmost cell (e.g. 3 5): " << endl;
        getLineWithTwoIntegers(r, c);
        while(r < 0 || r > game().rows() || c < 0 || c > game().rows())
        {
            cout << "The ship can not be placed there." << endl;
            cout <<"Enter row and column of leftmost cell (e.g. 3 5): " << endl;
            getLineWithTwoIntegers(r, c);
        }
        Point p(r,c);
        if(dir == "h")
        {
            while(b.placeShip(p, ID, HORIZONTAL) == false)
            {
                cout << "The ship can not be placed there." << endl;
                cout <<"Enter row and column of leftmost cell (e.g. 3 5): " << endl;
                getLineWithTwoIntegers(r, c);
                p = Point(r,c);
                
            }
        }
        if(dir == "v")
        {
            while(b.placeShip(p, ID, VERTICAL) == false)
            {
                cout << "The ship can not be placed there." << endl;
                cout <<"Enter row and column of leftmost cell (e.g. 3 5): " << endl;
                getLineWithTwoIntegers(r, c);
                p = Point(r,c);
            }
        }
        if(ID != game().nShips()-1)
        b.display(false);
        ID++;
    }
    return true;
}

Point HumanPlayer::recommendAttack()
{
    int r,c;
    cout << "Enter the row and column to attack (e.g, 3 5): " << endl;
    cin >> r;
    cin >> c;
    return (Point(r,c));
}
void HumanPlayer::recordAttackResult(Point p, bool validShot, bool shotHit,bool shipDestroyed, int shipId)
{}

void HumanPlayer::recordAttackByOpponent(Point p)
{}
//*********************************************************************
//  MediocrePlayer
//*********************************************************************

class MediocrePlayer: public Player
{
public:
    MediocrePlayer(string name, const Game&g);
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit,
                                    bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
private:
    bool recursiveCall(Board &b,vector<Point> placable,int allpoints, int shipID){
//        if(p == placable.end())
//            return false;
//        if(shipID == game().nShips())
//            return true;
//        
//        if(b.placeShip(*p, shipID, HORIZONTAL) == true)//horizontal
//        {
//            if(recursiveCall(b, placable.begin(), placable, shipID+1) == false)
//            {
//                b.unplaceShip(*p, shipID, HORIZONTAL);
//                if(b.placeShip(*p, shipID, VERTICAL) == false)
//                    return recursiveCall(b, p+1, placable, shipID);
//            }
//            else
//                return true;
//        }
//       else if(b.placeShip(*p, shipID, VERTICAL) == true)
//       {  
//            if(recursiveCall(b, placable.begin(), placable, shipID+1) == false){
//                b.unplaceShip(*p, shipID, VERTICAL);
//            return recursiveCall(b, p+1, placable, shipID);
//            }
//           else
//            return true;
//        }
//        
//        
//        if(p->r==game().rows()-1&&p->c==game().rows()-1){
//            return false;
//        }
//        
//        return recursiveCall(b, p+1, placable, shipID);
//
        if(shipID == 4)
        {
            for(int i = 0; allpoints; i++)
            {
                
                    if(b.placeShip(placable[i], shipID+1, HORIZONTAL) == true)
                        return true;
                    if(b.placeShip(placable[i], shipID, VERTICAL)==true)
                        return true;
                
            }
            return false;
        }
        
        for(int i = 0; i < allpoints; i++)
        {
           
                if(b.placeShip(placable[i],shipID, HORIZONTAL) == true)
                {
                    if(recursiveCall(b, placable, allpoints, shipID+1) == false)
                        b.unplaceShip(placable[i], shipID, HORIZONTAL);
                    else
                        return true;
                }
                if(b.placeShip(placable[i], shipID, VERTICAL) == true)
                {
                    if(recursiveCall(b, placable, allpoints, shipID+1) == false)
                        b.unplaceShip(placable[i], shipID, VERTICAL);
                    else
                        return true;
                }
        }
        return false;
    };
    int state;
    vector<Point> record;
    vector<Point> useful;
};

MediocrePlayer::MediocrePlayer(string name, const Game&g):Player(name,g)
{
    state = 1;
}

bool MediocrePlayer::placeShips(Board &b)
{
    vector<Point> placable;
    int shipID=0,total = 0;
    bool result = false;
    int allpoints = game().rows()*game().cols();
    for(int i = 0; i < game().rows();i++)
    {
        for(int k = 0; k < game().cols();k++)
            placable.push_back(Point(i,k));
    }
    while(total != 50)
    {
        b.clear();
         b.block();
        result = recursiveCall(b,placable,allpoints, shipID);
        if(result==true)
        {
            b.unblock();
            break;
        }
        total ++;
    b.unblock();
    }
    return result;
}
Point MediocrePlayer::recommendAttack()
{
    if(state == 1)
    {
        Point p = Point(randInt(game().rows()),randInt(game().cols()));
        for(vector<Point>::iterator q = record.begin(); q != record.end(); q++){
            if(q->r == p.r && q->c == p.c){
                p = Point(randInt(game().rows()),randInt(game().cols()));
                q = record.begin();
            }
        }
        if(p.r==0&&p.c==0){
        
        }
        record.push_back(p);
        return p;
    }
    else if(useful.empty()){
        state = 1;
        Point p = Point(randInt(game().rows()),randInt(game().cols()));
        for(vector<Point>::iterator q = record.begin(); q != record.end(); q++){
            if(q->r == p.r && q->c == p.c){
                p = Point(randInt(game().rows()),randInt(game().cols()));
                q = record.begin();
            }
        }
        record.push_back(p);
        return p;
    }
   else
    {   //while loop check if target point matches any point in record
        
        size_t n = useful.size();
        Point result = useful[randInt(n)];
        
        for(vector<Point>::iterator q = record.begin(); q != record.end(); q++){
            if(q->r == result.r && q->c == result.c){
                for(vector<Point>::iterator l = useful.begin(); l != useful.end();){
                    if(l->r==result.r&&l->c==result.c)
                        l =  useful.erase(l);
                    else
                        l++;
                }
                if(useful.empty()){
                    state = 1;
                    Point p = Point(randInt(game().rows()),randInt(game().cols()));
                    for(vector<Point>::iterator q = record.begin(); q != record.end(); q++){
                        if(q->r == p.r && q->c == p.c){
                            p = Point(randInt(game().rows()),randInt(game().cols()));
                            q = record.begin();
                        }
                    }
                    record.push_back(p);
                    return p;
                }
                result = useful[randInt(n)];
                q = record.begin();
            }
        }
        
        for(vector<Point>::iterator q = useful.begin(); q != useful.end();){
           if(q->r==result.r&&q->c==result.c)
              q =  useful.erase(q);
            else
                q++;
        }
        
        return result;
    }
}

void MediocrePlayer::recordAttackResult(Point p, bool validShot, bool shotHit, bool shipDestroyed, int shipId)
{
    int minrow, maxrow, mincol, maxcol;
    record.push_back(p);
    
    if(shotHit && shipDestroyed){
        useful.erase(useful.begin(),useful.end());
        state=1;
        return;
    }
    if(shotHit && !shipDestroyed && state == 1)
    {
        state=2;
        if(p.r-4 <= 0)
            minrow = 0;
        else
        minrow = p.r - 4;
        if(p.c-4 <= 0)
            mincol = 0;
        else
        mincol = p.c - 4;
        if(p.r+4 >=9)
            maxrow = 9;
        else
        maxrow = p.r+4;
        if(p.c+4 >= 9)
            maxcol = 9;
        else
        maxcol = p.c+4;
        
        for(int r = minrow; r <=maxrow ; r++)
                useful.push_back(Point(r,p.c));
        for(int c = mincol; c <=maxcol; c++){
            useful.push_back(Point(p.r,c));
        }
    }
   }

void MediocrePlayer::recordAttackByOpponent(Point p)
{
    return;

}
// Remember that Mediocre::placeShips(Board& b) must start by calling
// b.block(), and must call b.unblock() just before returning.

//*********************************************************************
//  GoodPlayer
//*********************************************************************
class GoodPlayer: public Player
{
public:
    GoodPlayer(string name, const Game&g);
    virtual bool placeShips(Board& b);
    virtual Point recommendAttack();
    virtual void recordAttackResult(Point p, bool validShot, bool shotHit,
                                    bool shipDestroyed, int shipId);
    virtual void recordAttackByOpponent(Point p);
private:
    vector<Point> ship;
    vector<Point> record;
    int state;
    vector<Point> target;
    bool recursiveCall(Board &b,vector<Point> placable,int allpoints, int shipID){
        if(shipID == 4)
        {
            for(int i = 0; allpoints; i++)
            {
                
                if(b.placeShip(placable[i], shipID+1, HORIZONTAL) == true)
                    return true;
                if(b.placeShip(placable[i], shipID, VERTICAL)==true)
                    return true;
                
            }
            return false;
        }
        
        for(int i = 0; i < allpoints; i++)
        {
            
            if(b.placeShip(placable[i],shipID, HORIZONTAL) == true)
            {
                if(recursiveCall(b, placable, allpoints, shipID+1) == false)
                    b.unplaceShip(placable[i], shipID, HORIZONTAL);
                else
                    return true;
            }
            if(b.placeShip(placable[i], shipID, VERTICAL) == true)
            {
                if(recursiveCall(b, placable, allpoints, shipID+1) == false)
                    b.unplaceShip(placable[i], shipID, VERTICAL);
                else
                    return true;
            }
        }
        return false;
    }
    bool recordContains(int r, int c){
        for(int i = 0; i < record.size();i++)
        {
            if(record[i].r == r&& record[i].c == c)
                return true;
        }
        return false;
    }
    bool guessDir = false;
    Direction direction;
};

GoodPlayer::GoodPlayer(string name, const Game&g):Player(name,g){
    state = 1;
}

bool GoodPlayer::placeShips(Board &b)
{
//    int shipId = 0;
//    while(shipId != 5)
//    {
//    Point p = Point(randInt(game().rows()),randInt(game().cols()));
//        int randnum = randInt(2);
//        if(randnum==0)
//            while(!b.placeShip(p, shipId, HORIZONTAL))
//            {
//                p = Point(randInt(game().rows()),randInt(game().cols()));
//            }
//            if(randnum==1)
//            while(!b.placeShip(p, shipId, VERTICAL))
//            {
//                p= Point(randInt(game().rows()),randInt(game().cols()));
//            }
//        record.push_back(p);
//        shipId++;
//    }
//    return true;
    
    vector<Point> placable;
    int shipID=0;
    bool result = false;
    int allpoints = game().rows()*game().cols();
    for(int i = 0; i < game().rows();i++)
    {
        for(int k = 0; k < game().cols();k++)
            placable.push_back(Point(i,k));
    }
    b.clear();
        result = recursiveCall(b,placable,allpoints,shipID);
    return result;
    
}
Point GoodPlayer::recommendAttack()
{
    
    Point p = Point(randInt(game().rows()),game().cols());
    if(state == 1)
    {
        for(;;)
        {
            Point p = Point(randInt(game().rows()),randInt(game().cols()));
            if(!recordContains(p.r, p.c))
            {
                return p;
            }
        }
        //        if(possibleTarget.empty())
//        {
//            for(int i = 0; i < game().rows(); i++)
//            {
//                for(int k = 0; k < game().cols();k++)
//                {
//                    if((i-k)%2 == 0)
//                        possibleTarget.push_back(Point(i,k));
//                }
//            }
//            p = possibleTarget.back();
//            possibleTarget.pop_back();
//            return p;
//        }
//        else
//        {
//        p = possibleTarget.back();
//            
//            for(int i = 0;i < record.size();i++)
//            {
//                if(record[i].r == p.r && record[i].c == p.c)
//                {
//                    possibleTarget.pop_back();
//                    p = possibleTarget.back();
//                    i = 0;
//                }
//            }
//        possibleTarget.pop_back();
//            return p;
//        }
    }
    else
    {
        if(target.size()==0)
        {
            state = 1;
            for(;;)
            {
                Point p = Point(randInt(game().rows()),randInt(game().cols()));
                if(!recordContains(p.r, p.c))
                {
                    return p;
                }
            }
        }
//            state = 1;
//            if(possibleTarget.empty())
//            {
//                for(int i = 0; i < game().rows(); i++)
//                {
//                    for(int k = 0; k < game().cols();k++)
//                    {
//                        if((i-k)%2 == 0)
//                            possibleTarget.push_back(Point(i,k));
//                    }
//                }
//                p = possibleTarget.back();
//                possibleTarget.pop_back();
//                return p;
//            }
//            else
//            {
//                p = possibleTarget.back();
//                
//                for(int i = 0;i < record.size();i++)
//                {
//                    if(record[i].r == p.r && record[i].c == p.c)
//                    {
//                        possibleTarget.pop_back();
//                        p = possibleTarget.back();
//                        i = 0;
//                    }
//                }
//                possibleTarget.pop_back();
//                return p;
//            }
        
        
//        for(vector<Point>::iterator q = record.begin(); q != record.end();q++){
//            for(vector<Point>::iterator r = target.begin(); r!=target.end();){
//          if(r->r==q->r&&r->c==q->c){
//              if(!target.empty())
//              r= target.erase(r);
//            }
//            else
//                r++;
        
    
        p = target.back();
        target.pop_back();
        }
    if ( !recordContains(p.r, p.c) )
    {
        return p;
    }
    else
    {
        return recommendAttack();
    }

}
void GoodPlayer:: recordAttackResult(Point p, bool validShot, bool shotHit,
                        bool shipDestroyed, int shipId){
    
    record.push_back(p);
    if( shotHit )
    {
        state = 2;
        if(p.r-1>=0 && !recordContains(p.r-1, p.c))
            target.push_back(Point(p.r-1,p.c));
        if(p.r+1 <=9 && !recordContains(p.r+1, p.c))
            target.push_back(Point(p.r+1,p.c));
        if(p.c+1 <= 9&&!recordContains(p.r, p.c+1))
            target.push_back(Point(p.r,p.c+1));
        if(p.c-1 >=0&&!recordContains(p.r, p.c-1))
            target.push_back(Point(p.r,p.c-1));
        }
}
void GoodPlayer::recordAttackByOpponent(Point p){
    return;
}

//*********************************************************************
//  createPlayer
//*********************************************************************

Player* createPlayer(string type, string nm, const Game& g)
{
    static string types[] = {
        "human", "awful", "mediocre", "good"
    };
    
    int pos;
    for (pos = 0; pos != sizeof(types)/sizeof(types[0])  &&
         type != types[pos]; pos++)
        ;
    switch (pos)
    {
        case 0:  return new HumanPlayer(nm, g);
        case 1:  return new AwfulPlayer(nm, g);
        case 2:  return new MediocrePlayer(nm, g);
        case 3:  return new GoodPlayer(nm, g);
        default: return nullptr;
    }
}
