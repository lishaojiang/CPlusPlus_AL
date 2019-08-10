#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) 
    {
        // I can't do this by myself,it refrence the answers
        // DP problems

        // the key answer
        // DP[0] = 0;
        // DP[i] = DP[i/2] + 1; i is even
        // DP[i] = DP[i/2]; i is not even
        vector<int> DP(num+1,0);
        for(int i = 1; i <= num; i++)
        {
            if(i%2)
                DP[i] = DP[i/2] + 1;
            else
                DP[i] = DP[i/2];
        }
        return DP;

    }
};

int main(int,const char**)
{
    Solution ks;
    ks.countBits(2);
    return 0;
}