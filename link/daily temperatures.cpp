#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        vector<int> kRet(T.size(),0);
        stack<int> kStack;
        for(int i = 0; i < T.size(); i++)
        {
            if((i + 1) < T.size())
            {
                if(T[i] < T[i+1])
                {
                    kRet[i] = 1;
                    while(!kStack.empty())
                    {
                        if(T[kStack.top()] < T[i+1])
                        {
                            kRet[kStack.top()] = i+1-kStack.top();
                            kStack.pop();
                        }
                        else
                        {
                            break;
                        }
                        
                    }
                }
                else
                {
                    kStack.push(i);
                }
                
            }
        }
        return kRet;
    }
};

int main(int iG,const char* pcGr[])
{
    vector<int> kIn(5,10);
    kIn[0] = 1;
    kIn[3] = -1;
    
    vector<int> kOut;

    Solution ks;
    kOut = ks.dailyTemperatures(kIn);
    printf("ss");
    return 0;
}

