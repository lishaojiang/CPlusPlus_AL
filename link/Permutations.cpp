#include<iostream>
#include<vector>

using namespace std;

// my self function,no use back tracing
class SolutionA {
public:
    vector<vector<int> > permute(vector<int>& nums) {
            vector<vector<int> > kOut;
            if(nums.empty())
                return kOut;
            vector<int> a;
            a.push_back(nums[0]);
            kOut.push_back(a);
            for(int i = 1;i < nums.size();i++)
            {
                int iNowKOutSize = kOut.size();
                for(int j = 0; j < iNowKOutSize;j++)
                {
                    for(int k = 0; k <= kOut[j].size();k++)
                    {
                        vector<int> kOne = kOut[j];
                        kOne.insert(kOne.begin()+k,nums[i]);
                        kOut.push_back(kOne);
                    }   
                }
                kOut.erase(kOut.begin(),kOut.begin()+iNowKOutSize);
            }
            return kOut; 
    }
};

class Solution 
{
public:
    vector<vector<int> > permute(vector<int>& nums) 
    {
        int iIndex = 0;
        vector<vector<int> > rkOut;
        dfs(nums,0,rkOut);
        return rkOut;
    }

    void dfs(vector<int> nums,int iIndex,vector<vector<int> >& rkOut)
    {
        if(iIndex == nums.size())
        {
            rkOut.push_back(nums);
        }
        else
        {
            for(int i = iIndex;i < nums.size();i++)
            {
                swap(nums[i],nums[iIndex]);
                dfs(nums,iIndex+1,rkOut);
            }
        }
        
    }
};

int main(int,const char**)
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    Solution ks;
    vector<vector<int> > kRet = ks.permute(a);
    return 0;
}