#include<iostream>
#include<vector>
#include<deque>

using namespace std;


// there has DP solution,but i can't do it.

class Solution 
{
public:
    // this is DFS solution
    int findWay(vector<int>& nums,long S,int iIndex)
    {
        int iWay = 0;
        if(iIndex == nums.size() -1)
        {
            if(S == nums[iIndex])
            {
                iWay++;
            }
            if(S == -nums[iIndex])
            {
                iWay++;
            }
            return iWay;
        }

        iIndex++;

        iWay =  findWay(nums,S - nums[iIndex-1],iIndex) + findWay(nums,S + nums[iIndex-1],iIndex);
        return iWay;
    }

    // we use bfs to finish this.
    int findWay_BFS(vector<int>& nums,int S)
    {
        int iWay = 0;
        if(nums.empty())
            return 0;
        deque<int> bfs;
        bfs.push_back(nums[0]);
        bfs.push_back(-nums[0]);
        for(int i = 1; i < nums.size();i++)
        {
            int m = bfs.size();
            for(int j = 0; j < m;j++)
            {
                bfs.push_back(bfs.front()+ nums[i]);
                bfs.pop_front();
                bfs.push_back(bfs.front()- nums[i]);
                bfs.pop_front();
            }
            
        }
        while(!bfs.empty())
        {
            if(bfs.front() == S)
                iWay++;
            bfs.pop_front();
        }
        return iWay;
    }

    int findTargetSumWays(vector<int>& nums, int S) 
    {
        return findWay(nums,S,0);
    }
};