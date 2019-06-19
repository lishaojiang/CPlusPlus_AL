#include<iostream>
#include<vector>
#include<deque>
#include<unordered_set>
#include<map>

using namespace std;

class Solution 
{
public:
    int openLock(vector<string>& deadends, string target) 
    {
        // we use BFS to search the road
        int iStep = -1;
        std::deque<string> kDeque;
        unordered_set<string> kDeadSet(deadends.begin(),deadends.end());
        unordered_set<string> kSet;
        if(std::find(deadends.begin(),deadends.end(),"0000") != deadends.end())
        {
            return iStep;
        }
        kDeque.push_back("0000");
        if(target == "0000")
        {
            return iStep;
        }
        while(!kDeque.empty())
        {
            iStep++;
            int iSize = kDeque.size();
            for(int m = 0; m < iSize; m++)
            {
                string kNode = kDeque.front();
                kDeque.pop_front();

                int iIndex = 1;
                for(int i = 0;i < 8;i++)
                {
                    string kNextNode = kNode;
                    (i % 2 > 0) ? iIndex = 1 : iIndex = -1;
                    kNextNode[i / 2] =(kNode[i / 2] - '0' + 10 + iIndex) % 10 + '0';
                    if(kNextNode == target)
                    {
                        return iStep+1;
                    }
                    unordered_set<string>::iterator iter = kSet.find(kNextNode);
                    if(iter != kSet.end())
                    {
                        continue;
                    }
                    if(kDeadSet.find(kNextNode) == kDeadSet.end())
                    {
                        kDeque.push_back(kNextNode);
                        kDeadSet.insert(kNextNode);
                    }

                }
            }
        }

        return -1;
    }
};

int main(int iG,const char* pcNums[])
{
    Solution ks;
    return 0;
}