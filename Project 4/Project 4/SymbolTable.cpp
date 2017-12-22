// SymbolTable.cpp

// This is a correct but inefficient implementation of
// the SymbolTable functionality.

#include "SymbolTable.h"
#include <string>
#include <vector>
using namespace std;

const int HASH_TABLE_SIZE = 20000;

struct Node//the information that each bucket will hold
{
    Node(string val, int lineNum,int scopeNum):ID(val), line(lineNum),next(nullptr),scope(scopeNum){};
    string ID;
    int line;
    int scope;
    Node* next;
};

// This class does the real work of the implementation.

class SymbolTableImpl
{
public:
    SymbolTableImpl();
    ~SymbolTableImpl();
    void enterScope();
    bool exitScope();
    bool declare(const string& id, int lineNum);
    int find(const string& id) const;
private:
    void insertNode(const string &ID, int lineNum, int scopeNum, Node* &record)
    {
        int h = hashFunction(ID);
        Node* p = m_Bucket[h];
        m_Bucket[h] = new Node(ID,lineNum,scopeNum);
        m_Bucket[h]->next = p;
    }
    Node* m_Bucket[HASH_TABLE_SIZE];
    int hashFunction(string ID) const
    {
        int i, total = 0;
        for(i = 0; i < ID.size();i++)
        {
            total = total +(i+1)*ID[i];
        }
        total = total % HASH_TABLE_SIZE;
        return total;
    };
    vector<int> hashNumber;
    int totalScope;
};



SymbolTableImpl::SymbolTableImpl():totalScope(0)
{
    for(int i = 0; i < HASH_TABLE_SIZE-1;i++)
    {
        m_Bucket[i] = nullptr;
    }
}

SymbolTableImpl::~SymbolTableImpl()
{
    hashNumber.erase(hashNumber.begin(),hashNumber.end());
}
void SymbolTableImpl::enterScope()
{
    totalScope++;
    hashNumber.push_back(-1);
}

bool SymbolTableImpl::exitScope()
{
    if(totalScope == 0)
        return false;
    
    int num = hashNumber.back();
    while(num != -1)
    {
        Node *p = m_Bucket[num];
        if(m_Bucket[num] != nullptr)
        {
            m_Bucket[num] = m_Bucket[num]->next;
            delete p;
        }
        
        hashNumber.pop_back();
        num = hashNumber.back();
    }
    hashNumber.pop_back();
    totalScope--;
    return true;
}

bool SymbolTableImpl::declare(const string& id, int lineNum)
{
    if(id == "")
        return false;
    int scopeNum = totalScope;
    Node *q = m_Bucket[hashFunction(id)];
    if(q != nullptr && q->scope == totalScope && q->ID == id)
    {
        return false;
    }
    else
    {
        Node *p;
        insertNode(id, lineNum, scopeNum, p);
        hashNumber.push_back(hashFunction(id));
        return true;
    }
}

int SymbolTableImpl::find(const string& id) const
{
    if(id.empty())
        return -1;
    int scope=0;
    int lineNum = -1;
    int h = hashFunction(id);
    Node* p = m_Bucket[h];
    while (p != nullptr)
    {
        if (p->ID == id)
        {
            lineNum = p->line; // output: the line and scope of the found item
            scope = p->scope;
            break;
        }
        p = p->next;
    }
    return lineNum;
}

//*********** SymbolTable functions **************

// For the most part, these functions simply delegate to SymbolTableImpl's
// functions.

SymbolTable::SymbolTable()
{
    m_impl = new SymbolTableImpl;
}

SymbolTable::~SymbolTable()
{
    delete m_impl;
}

void SymbolTable::enterScope()
{
    m_impl->enterScope();
}

bool SymbolTable::exitScope()
{
    return m_impl->exitScope();
}

bool SymbolTable::declare(const string& id, int lineNum)
{
    return m_impl->declare(id, lineNum);
}

int SymbolTable::find(const string& id) const
{
    return m_impl->find(id);
}
