//
//  eval.cpp
//  eval
//
//  Created by Jacob on 4/29/17.
//  Copyright © 2017 Jacob. All rights reserved.
//

#include <stack>
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;

char performoperatoion(char operation, char operand1, char operand2)
{
    if(operation == '&')
    {
       if(operand1 == 'F' && operand2 == 'F')
           return 'F';
       if(operand1 == 'T' && operand2 == 'F')
           return 'F';
        if(operand1 == 'F' && operand2 == 'T')
            return 'F';
      else
         return 'T';
    }
    if(operation == '|')
    {
        if(operand1 == 'T' && operand2 == 'T')
            return 'T';
        if(operand1 == 'F' && operand2 == 'F')
            return 'F';
        if(operand1 == 'T' && operand2 == 'F')
            return 'T';
        else
         return 'T';
    }
    else
        exit(1);
}


int evaluate(string infix, string& postfix, bool& result)
// Evaluates a boolean expression
//   If infix is a syntactically valid infix boolean expression,
//   then set postfix to the postfix form of that expression, set
//   result to the value of the expression, and return zero.  If
//   infix is not a syntactically valid expression, return 1; in
//   that case, postfix may or may not be changed, but result must
//   be unchanged.)
{
    postfix = "";
    stack<char> operatorstack;
    stack<char> operandstack;
    stack<char> parenstack;
    stack<char> checkstack;
    char operand1;
    char operand2;
    char firstchar;
    for(int i = 0; i < infix.size(); i++)//consider the parenthesis
    {
        if(infix[i] == '(')
            parenstack.push(infix[i]);
        if(infix[i] == ')')
        {
            if(parenstack.empty())
                return 1;
            parenstack.pop();
        }
    }
    if(!parenstack.empty())
        return 1;
    if(infix.size() == 0) //when infix is empty string
        return 1;
    for(int i = 0; i < infix.size(); i++ )
    {
        if(infix[i] != ' ')
        {
            firstchar = infix[i];
            break;
        }
    }
    if(firstchar == '&' || firstchar == '|')
        return 1;
    for(int i = 0; i < infix.size(); i++)
    {
        if(infix[i] != ' ')
            checkstack.push(infix[i]);
    }
    char top = checkstack.top();
    if(top == '!' || top == '&' || top == '|')
        return 1;
    
    for(int i = 0; i < infix.size(); i++)
    {
        int k = i;
       switch(infix[i])
        {
         case'T':
                postfix += 'T';
                while(k > 0 && infix[k-1] == ' ')
                {
                    k--;
                }
                if(k > 0)
                {
                    if(infix[k-1] == 'F' || infix[k-1] == 'T' || infix[k-1] == ')')
                        return 1;
                }
                break;
         case 'F':
                postfix += 'F';
                while(k > 0 && infix[k-1] == ' ')
                {
                    k--;
                }
                if(k > 0)
                {
                    if(infix[k-1] == 'F' || infix[k-1] == 'T' || infix[k-1] == ')')
                        return 1;
                }
                break;
        case ' ':
                break;
        case'(':
                operatorstack.push(infix[i]);
                while(k > 0 && infix[k-1] == ' ')
                {
                    k--;
                }
                if(k > 0)
                {
                    if(infix[k-1] == 'F' || infix[k-1] == 'T' || infix[k-1] == ')')
                        return 1;
                }
                break;
        case ')':
                while(operatorstack.top() != '(')
                {
                    postfix += operatorstack.top();
                    operatorstack.pop();
                }
                operatorstack.pop();
                while(k > 0 && infix[k-1] == ' ')
                {
                    k--;
                }
                if(k > 0)
                {
                    if(infix[k-1] == '&' || infix[k-1] == '|' || infix[k-1] == '!' || infix[k-1] == '(')
                        return 1;
                }
                break;
        case '&':
                while(!operatorstack.empty() && operatorstack.top()!='(' && operatorstack.top() != '|')
                {
                    postfix += operatorstack.top();
                    operatorstack.pop();
                }
                operatorstack.push('&');
                while(k > 0 && infix[k-1] == ' ')
                {
                    k--;
                }
                if(k > 0)
                {
                    if(infix[k-1] == '|' || infix[k-1] == '&' || infix[k-1] == '!' || infix[k-1] == '(')
                        return 1;
                }
                break;
        case '|':
                while(!operatorstack.empty() && operatorstack.top()!='(')
                {
                    postfix += operatorstack.top();
                    operatorstack.pop();
                }
                operatorstack.push('|');
                while(k > 0 && infix[k-1] == ' ')
                {
                    k--;
                }
                if(k > 0)
                {
                    if(infix[k-1] == '|' || infix[k-1] == '&' || infix[k-1] == '!' || infix[k-1] == '(')
                        return 1;
                }
                break;
        case '!':
                while(!operatorstack.empty() && operatorstack.top()!='(' && operatorstack.top() != '&' && operatorstack.top() != '|' && operatorstack.top() != '!')
                {
                    postfix += operatorstack.top();
                    operatorstack.pop();
                }
                operatorstack.push('!');
                while(k > 0 && infix[k-1] == ' ')
                {
                    k--;
                }
                if(k > 0)
                {
                    if(infix[k-1] == ')' || infix[k-1] == 'T' || infix[k-1] == 'F')
                        return 1;
                }
                break;
        default:
                return 1;
        }
    }
    while(!operatorstack.empty())
    {
        postfix += operatorstack.top();
        operatorstack.pop();
    }
    for(int i = 0; i < postfix.size(); i++)
    {
       if(postfix[i] == 'T' || postfix[i] == 'F')
           operandstack.push(postfix[i]);
        else
        {
            if(postfix[i] != '!')
            {
            operand2 = operandstack.top();
            operandstack.pop();
            operand1 = operandstack.top();
            operandstack.pop();
            operandstack.push(performoperatoion(postfix[i], operand1, operand2));
            }
            if(postfix[i] == '!')
            {
                operand2 = operandstack.top();
                operandstack.pop();
                if(operand2 == 'T')
                {
                    operandstack.push('F');
                }
                if(operand2 == 'F')
                {
                    operandstack.push('T');
                }
            }
        }
    }
    if(operandstack.top() == 'T')
        result = true;
    else
        result = false;
    return 0;
}


int main()
{
    string pf;
    bool answer;
    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
          &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);

    // TEST CASES FOR eval.cpp
    // CHECK VALIDITY
    {
        string pf = "postfix";
        bool answer = false;
        assert(evaluate("T|F&(F |T  & TT)", pf, answer) == 1);
        assert(evaluate("t|FF&(F |T  & T)", pf, answer) == 1);
        assert(evaluate("T|F&(FT |T  & T)", pf, answer) == 1);
        assert(evaluate("T|FF&(F |T  & T)", pf, answer) == 1);
        assert(evaluate("T&(T &&F)", pf, answer) == 1);
        assert(evaluate("T&|(T &F)", pf, answer) == 1);
        assert(evaluate("T|&(T &F)", pf, answer) == 1);
        assert(evaluate("T&(T ||F)", pf, answer) == 1);
        assert(evaluate("T!&F", pf, answer) == 1);
        assert(evaluate("T!|F", pf, answer) == 1);
        assert(evaluate("(T&F)| (&)", pf, answer) == 1);
        assert(evaluate("(T&F)| (|", pf, answer) == 1);
        assert(evaluate("T(F)&T", pf, answer) == 1);
        assert(evaluate("T&F!", pf, answer) == 1);
        assert(evaluate("F(F)&T", pf, answer) == 1);
        assert(evaluate("T!", pf, answer) == 1);
        assert(evaluate("(T)&()", pf, answer) == 1);
        assert(evaluate("T|!(!(!F)())", pf, answer) == 1);
    }
    // IMPLEMENT VALID OPERATIONS
    {
        string pf;
        bool answer;
        assert(evaluate("T&(F &T)", pf, answer) == 0 &&  pf == "TFT&&"  &&  !answer);
        assert(evaluate("T&(T &F)", pf, answer) == 0 &&  pf == "TTF&&"  &&  !answer);
        assert(evaluate("!T | (F)", pf, answer) == 0 &&  pf == "T!F|"  &&  !answer);
        assert(evaluate("!F & (F)", pf, answer) == 0 &&  pf == "F!F&"  &&  !answer);
        assert(evaluate("((F))|F", pf, answer) == 0 &&  pf == "FF|"  &&  !answer);
        assert(evaluate("(T  &F) | (F  | (T&F))", pf, answer) == 0 &&  pf == "TF&FTF&||"  &&  !answer);
        assert(evaluate("(T  &F) | (F  | (F&T))", pf, answer) == 0 &&  pf == "TF&FFT&||"  &&  !answer);
        assert(evaluate("F&(T| F)", pf, answer) == 0 &&  pf == "FTF|&"  &&  !answer);
        assert(evaluate("!(  T )", pf, answer) == 0 &&  pf == "T!"  &&  !answer);
        assert(evaluate("((F))", pf, answer) == 0 &&  pf == "F"  &&  !answer);
        assert(evaluate("T&(F |T)", pf, answer) == 0 &&  pf == "TFT|&"  &&  answer);
        assert(evaluate("T|(T |F)", pf, answer) == 0 &&  pf == "TTF||"  &&  answer);
        assert(evaluate("(T)", pf, answer) == 0 &&  pf == "T"  &&  answer);
        assert(evaluate("(T  &F) | (F  | (T|F))", pf, answer) == 0 &&  pf == "TF&FTF|||"  &&  answer);
        assert(evaluate("(T  |F) | (F  | (T&F))", pf, answer) == 0 &&  pf == "TF|FTF&||"  &&  answer);
        assert(evaluate("T&!F", pf, answer) == 0 &&  pf == "TF!&"  &&  answer);
        assert(evaluate("F| !F", pf, answer) == 0 &&  pf == "FF!|"  &&  answer);
        assert(evaluate("F|(T| F)", pf, answer) == 0 &&  pf == "FTF||"  &&  answer);
        assert(evaluate("!!T", pf, answer) == 0 &&  pf == "T!!"  &&  answer);
        assert(evaluate("!(!T)", pf, answer) == 0 &&  pf == "T!!"  &&  answer);
        // TEST PRECEDENCE
        assert(evaluate("T|F&F", pf, answer) == 0 &&  pf == "TFF&|"  &&  answer);
        assert(evaluate("T|F&(F|F)", pf, answer) == 0 &&  pf == "TFFF|&|"  &&  answer);
        assert(evaluate("T&F|(F|F)", pf, answer) == 0 &&  pf == "TF&FF||"  &&  !answer);
    }
    
    // TEST CASES FOR eval.cpp
    // CHECK VALIDITY
    {
        string pf = "postfix";
        bool answer = false;
        assert(evaluate("T|F&(F |T  & TT)", pf, answer) == 1);
        assert(evaluate("t|FF&(F |T  & T)", pf, answer) == 1);
        assert(evaluate("T|F&(FT |T  & T)", pf, answer) == 1);
        assert(evaluate("T|FF&(F |T  & T)", pf, answer) == 1);
        assert(evaluate("T&(T &&F)", pf, answer) == 1);
        assert(evaluate("T&|(T &F)", pf, answer) == 1);
        assert(evaluate("T|&(T &F)", pf, answer) == 1);
        assert(evaluate("T&(T ||F)", pf, answer) == 1);
        assert(evaluate("T!&F", pf, answer) == 1);
        assert(evaluate("T!|F", pf, answer) == 1);
        assert(evaluate("(T&F)| (&)", pf, answer) == 1);
        assert(evaluate("(T&F)| (|", pf, answer) == 1);
        assert(evaluate("T(F)&T", pf, answer) == 1);
        assert(evaluate("T&F!", pf, answer) == 1);
        assert(evaluate("F(F)&T", pf, answer) == 1);
        assert(evaluate("T!", pf, answer) == 1);
        assert(evaluate("(T)&()", pf, answer) == 1);
        assert(evaluate("T|!(!(!F)())", pf, answer) == 1);
    }
    // IMPLEMENT VALID OPERATIONS
    {
        string pf;
        bool answer;
        assert(evaluate("T&(F &T)", pf, answer) == 0 &&  pf == "TFT&&"  &&  !answer);
        assert(evaluate("T&(T &F)", pf, answer) == 0 &&  pf == "TTF&&"  &&  !answer);
        assert(evaluate("!T | (F)", pf, answer) == 0 &&  pf == "T!F|"  &&  !answer);
        assert(evaluate("!F & (F)", pf, answer) == 0 &&  pf == "F!F&"  &&  !answer);
        assert(evaluate("((F))|F", pf, answer) == 0 &&  pf == "FF|"  &&  !answer);
        assert(evaluate("(T  &F) | (F  | (T&F))", pf, answer) == 0 &&  pf == "TF&FTF&||"  &&  !answer);
        assert(evaluate("(T  &F) | (F  | (F&T))", pf, answer) == 0 &&  pf == "TF&FFT&||"  &&  !answer);
        assert(evaluate("F&(T| F)", pf, answer) == 0 &&  pf == "FTF|&"  &&  !answer);
        assert(evaluate("!(  T )", pf, answer) == 0 &&  pf == "T!"  &&  !answer);
        assert(evaluate("((F))", pf, answer) == 0 &&  pf == "F"  &&  !answer);
        assert(evaluate("T&(F |T)", pf, answer) == 0 &&  pf == "TFT|&"  &&  answer);
        assert(evaluate("T|(T |F)", pf, answer) == 0 &&  pf == "TTF||"  &&  answer);
        assert(evaluate("(T)", pf, answer) == 0 &&  pf == "T"  &&  answer);
        assert(evaluate("(T  &F) | (F  | (T|F))", pf, answer) == 0 &&  pf == "TF&FTF|||"  &&  answer);
        assert(evaluate("(T  |F) | (F  | (T&F))", pf, answer) == 0 &&  pf == "TF|FTF&||"  &&  answer);
        assert(evaluate("T&!F", pf, answer) == 0 &&  pf == "TF!&"  &&  answer);
        assert(evaluate("F| !F", pf, answer) == 0 &&  pf == "FF!|"  &&  answer);
        assert(evaluate("F|(T| F)", pf, answer) == 0 &&  pf == "FTF||"  &&  answer);
        assert(evaluate("!!T", pf, answer) == 0 &&  pf == "T!!"  &&  answer);
        assert(evaluate("!(!T)", pf, answer) == 0 &&  pf == "T!!"  &&  answer);
        // TEST PRECEDENCE
        assert(evaluate("T|F&F", pf, answer) == 0 &&  pf == "TFF&|"  &&  answer);
        assert(evaluate("T|F&(F|F)", pf, answer) == 0 &&  pf == "TFFF|&|"  &&  answer);
        assert(evaluate("T&F|(F|F)", pf, answer) == 0 &&  pf == "TF&FF||"  &&  !answer);
    }
    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T|F&T|F&", pf, answer) == 1);
    assert(evaluate("T|||||T", pf, answer) == 1);
    assert(evaluate("!!!!!!!!!!(F&T)", pf, answer) == 0 &&  !answer);
    assert(evaluate("F F FTFTFT", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("TT", pf, answer) == 1);
    assert(evaluate("FF", pf, answer) == 1);
    assert(evaluate("()T|F", pf, answer) == 1);
    assert(evaluate("T|F()", pf, answer) == 1);
    assert(evaluate("F", pf, answer) == 0);
    assert(evaluate("T|T", pf, answer) == 0);
    assert(evaluate("T|(T&T)", pf, answer) == 0);
    assert(evaluate("T&  !(F   |T&T|F)|!!!(F&T   &F)|!!!!!!!((F|F|F))",pf,answer) == 0);
    assert(evaluate("T",pf,answer) == 0 && answer);
    assert(evaluate("(     F)",pf,answer) == 0&& !answer);
    assert(evaluate(" T &     !F",pf,answer) == 0);
    assert(evaluate("!(F|    T)",pf,answer) == 0);
    assert(evaluate("!F   |T",pf,answer) == 0);
    assert(evaluate("T|   F&F",pf,answer) == 0);
    assert(evaluate("&F",pf,answer) == 1);
    assert(evaluate("|F",pf,answer) == 1);
    assert(evaluate("F&&F",pf,answer) == 1);
    assert(evaluate("F!",pf,answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("(T&)", pf, answer) == 1);
    assert(evaluate("(T&T)", pf, answer) == 0 &&  pf == "TT&"  &&  answer);
    
    assert(evaluate("(T&     (F     |F))", pf, answer) == 0);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("(T&F|F)", pf, answer) == 0);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
           &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("T!T", pf, answer) == 1);
    assert(evaluate("T!||||||||||", pf, answer) == 1);
    assert(evaluate("(F)(F)(F)(F)(T)", pf, answer) == 1);
    assert(evaluate("(!F)!(!F)!(!F)!(F)(!T)", pf, answer) == 1);
    assert(evaluate("T&F&B", pf, answer) == 1);
    assert(evaluate("&T&F", pf, answer) == 1);
    assert(evaluate("|T&F", pf, answer) == 1);
    assert(evaluate(")(", pf, answer) == 1);
    assert(evaluate("T&F|!F", pf, answer) == 0);
    assert(evaluate("     T       &    F     |    !F", pf, answer) == 0);
    assert(evaluate("shenmejibawanyi", pf, answer) == 1);
    assert(evaluate("T&F()TF", pf, answer) == 1);
    //    string pf;
    //    bool answer;
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate(")(", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("(F|T)T", pf, answer) == 1);
    assert(evaluate("(F|T)！", pf, answer) == 1);
    assert(evaluate("(F|T！)", pf, answer) == 1);
    assert(evaluate("(F！|T)", pf, answer) == 1);
    assert(evaluate("(T!F)|(T&F)&((((!F))))", pf, answer) == 1);
    assert(evaluate("(T&(!F))|(T&F)&((((!F))))", pf, answer) == 0);
    assert(evaluate("(F|（！T)", pf, answer) == 1);
    assert(evaluate("(F|                T)", pf, answer) == 0);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("T(|F)", pf, answer) == 1);
    assert(evaluate("T(!F)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("!!", pf, answer) == 1);
    assert(evaluate("!(    T&F", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
           &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("!(T|F)", pf, answer) == 0 && pf == "TF|!" && !answer);
    assert(evaluate("(!T&F)|F", pf, answer) == 0 && pf == "T!F&F|" && !answer);
    assert(evaluate("(T&!F)|F", pf, answer) == 0 && pf == "TF!&F|" && answer);
    assert(evaluate("T|F", pf, answer) == 0 && pf == "TF|" && answer);
    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("T&(F &T)", pf, answer) == 0 &&  pf == "TFT&&"  &&  !answer);
    assert(evaluate("T&(T &F)", pf, answer) == 0 &&  pf == "TTF&&"  &&  !answer);
    assert(evaluate("!T | (F)", pf, answer) == 0 &&  pf == "T!F|"  &&  !answer);
    assert(evaluate("!F & (F)", pf, answer) == 0 &&  pf == "F!F&"  &&  !answer);
    assert(evaluate("((F))|F", pf, answer) == 0 &&  pf == "FF|"  &&  !answer);
    assert(evaluate("(T  &F) | (F  | (T&F))", pf, answer) == 0 &&  pf == "TF&FTF&||"  &&  !answer);
    assert(evaluate("(T  &F) | (F  | (F&T))", pf, answer) == 0 &&  pf == "TF&FFT&||"  &&  !answer);
    assert(evaluate("F&(T| F)", pf, answer) == 0 &&  pf == "FTF|&"  &&  !answer);
    assert(evaluate("!(  T )", pf, answer) == 0 &&  pf == "T!"  &&  !answer);
    assert(evaluate("((F))", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("T&(F |T)", pf, answer) == 0 &&  pf == "TFT|&"  &&  answer);
    assert(evaluate("T|(T |F)", pf, answer) == 0 &&  pf == "TTF||"  &&  answer);
    assert(evaluate("(T)", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("(T  &F) | (F  | (T|F))", pf, answer) == 0 &&  pf == "TF&FTF|||"  &&  answer);
    assert(evaluate("(T  |F) | (F  | (T&F))", pf, answer) == 0 &&  pf == "TF|FTF&||"  &&  answer);
    assert(evaluate("T&!F", pf, answer) == 0 &&  pf == "TF!&"  &&  answer);
    assert(evaluate("F| !F", pf, answer) == 0 &&  pf == "FF!|"  &&  answer);
    assert(evaluate("F|(T| F)", pf, answer) == 0 &&  pf == "FTF||"  &&  answer);
    assert(evaluate("!!T", pf, answer) == 0 &&  pf == "T!!"  &&  answer);
    assert(evaluate("!(!T)", pf, answer) == 0 &&  pf == "T!!"  &&  answer);
    // TEST PRECEDENCE
    assert(evaluate("T|F&F", pf, answer) == 0 &&  pf == "TFF&|"  &&  answer);
    assert(evaluate("T|F&(F|F)", pf, answer) == 0 &&  pf == "TFFF|&|"  &&  answer);
    assert(evaluate("T&F|(F|F)", pf, answer) == 0 &&  pf == "TF&FF||"  &&  !answer);
    assert(evaluate("T|", pf, answer) == 1);
    assert(evaluate("F F", pf, answer) == 1);
    assert(evaluate("TF", pf, answer) == 1);
    assert(evaluate("()", pf, answer) == 1);
    assert(evaluate(")(", pf, answer) == 1);
    assert(evaluate("T(F|T)", pf, answer) == 1);
    assert(evaluate("(F|T)T", pf, answer) == 1);
    assert(evaluate("T(&T)", pf, answer) == 1);
    assert(evaluate("T(|F)", pf, answer) == 1);
    assert(evaluate("T(!F)", pf, answer) == 1);
    assert(evaluate("(T&(F|F)", pf, answer) == 1);
    assert(evaluate("", pf, answer) == 1);
    assert(evaluate("!!", pf, answer) == 1);
    assert(evaluate("!(    T&F", pf, answer) == 1);
    assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
           &&  pf == "FF!TF&&|"  &&  !answer);
    assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
    assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
    assert(evaluate("!(T|F)", pf, answer) == 0 && pf == "TF|!" && !answer);
    assert(evaluate("(!T&F)|F", pf, answer) == 0 && pf == "T!F&F|" && !answer);
    assert(evaluate("(T&!F)|F", pf, answer) == 0 && pf == "TF!&F|" && answer);
    assert(evaluate("T|F", pf, answer) == 0 && pf == "TF|" && answer);
    assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
    assert(evaluate("  &T", pf, answer) == 1);
    
    cout << "Pass all test!" << endl;
}
