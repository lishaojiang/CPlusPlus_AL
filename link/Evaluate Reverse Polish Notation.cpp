#include<iostream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        int iRet = 0;
        stack<int> kStack;
        for(int i = 0; i < tokens.size();i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int b = kStack.top();
                kStack.pop();
                int a = kStack.top();
                kStack.pop();

                if(tokens[i] == "+")
                {
                    int c = a+b;
                    kStack.push(c);
                }
                else if(tokens[i] == "*")
                {
                    int c = a*b;
                    kStack.push(c);
                }
                else if(tokens[i] == "-")
                {
                    int c = a-b;
                    kStack.push(c);
                }
                else if(tokens[i] == "/")
                {
                    int c = a/b;
                    kStack.push(c);
                }
            }
            else
            {
                int a = atoi(tokens[i].c_str());
                kStack.push(a);
            }
            
        }
        if(!kStack.empty())
        {
            iRet = kStack.top();
        }
        return iRet;
    }
};