#include<iostream>
#include<string>
#include<stack>

using namespace std;


class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> kStack;
        for(int i = 0; i < s.length();i++)
        {
            if(s[i] == '(')
            {
                kStack.push('(');
            }
            else if(s[i] == '[')
            {
                kStack.push('[');
            }
            else if(s[i] == '{')
            {
                kStack.push('{');
            }
            else if(s[i] == ')')
            {
                if(kStack.empty())
                    return false;
                if(kStack.top() != '(')
                {
                    return false;
                }
                kStack.pop();
            }
            else if(s[i] == ']')
            {
                if(kStack.empty())
                    return false;
                if(kStack.top() != '[')
                {
                    return false;
                }
                kStack.pop();
            }
            else if(s[i] == '}')
            {
                if(kStack.empty())
                    return false;
                if(kStack.top() != '{')
                {
                    return false;
                }
                kStack.pop();
            }
        }
        if(!kStack.empty()) 
            return false;
        
        return true;
    }
};