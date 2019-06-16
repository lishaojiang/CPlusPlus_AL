#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    void FindSubsets(vector<int>& nums,int n,vector<vector<int> >& kOut)
    {
        if(n == -1)
        {
            vector<int> a;
            kOut.push_back(a);
            return;
        }
        FindSubsets(nums,n-1,kOut);
        vector<vector<int> > kTemp = kOut;
        for(int i = 0; i < kTemp.size(); i++)
        {
            vector<int> kAdd = kTemp[i];
            kAdd.push_back(nums[n]);
            kOut.push_back(kAdd);
        }
    }
    vector<vector<int> > subsets(vector<int>& nums) 
    {
        vector<int> a;
        vector<vector<int> > kOut;
        FindSubsets(nums,nums.size()-1,kOut);
        return kOut;
    }

    // function II,we use BFS to implicate this function,it's a littel difficult
    vector<vector<int> > subsetsBFS(vector<int>& nums) 
    {
        vector<int> a;
        vector<vector<int> > kOut;
        kOut.push_back(a);
        for(int i = 0; i < nums.size();i++)
        {
            vector<vector<int> > kTempVec = kOut;
            for(int j = 0; j < kTempVec.size();j++)
            {
                vector<int> kAdd = kTempVec[j];
                kAdd.push_back(nums[i]);
                kOut.push_back(kAdd);
            }
        }
        return kOut;
    }
};

int main(int agnums,const char* g[])
{
    Solution ks;
    vector<int> a(3,1);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    vector<vector<int> > kOut;
    kOut = ks.subsetsBFS(a);
    return 0;
}