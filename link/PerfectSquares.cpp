#include<iostream>
#include<math.h>
#include<vector>
#include<deque>

using namespace std;


int numSquares_BFS(int n) 
{
    int iStep = 0;
    deque<int> bfs;
    vector<int> akVec;
    for(int i = 1; i<= n;i++)
    {
        int iRet = i * i;

        if(iRet == n)
        {
            return 1;
        }
        else if(iRet < n)
        {
            akVec.push_back(iRet);
        }
        else
        {
            break;
        }
    }

    // BFS serach 
    
    // first step
    int iVecSize = akVec.size();
    iStep = 1;
    for(int i = 0; i < akVec.size(); i++)
    {
        bfs.push_back(akVec[iVecSize - 1 - i]);
    }

    while(!bfs.empty())
    {
        iStep++;
        int bfsSize = bfs.size();
        for(int i = 0; i < bfsSize; i++)
        {
            int iValue = bfs.front();
            bfs.pop_front();

            for(int j = 0; j < akVec.size(); j++)
            {
                int iTemp = iValue + akVec[iVecSize-1-j];
                if(iTemp  == n)
                {
                    return iStep;
                }
                else if(iTemp < n)
                {
                    bfs.push_back(iTemp);
                }
            }
        }
    }

    return 0;
}

int numSquares_DP(int n) 
{
    int iStep = 0;
    std::vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    // the most important dp fuction dp[n] = min(dp[n],dp[i-j*j]+1);
    for(int i = 2; i<= n;i++)
    {
        for(int j = 1;j*j <= i;j++)
        {
            dp[i] = std::min(dp[i],dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

// there is more important dp fuction,but i can't understand

int main(int igrac,const char* pcGrac[])
{
    int iRet = numSquares_DP(32);
    printf("%d",iRet);
    return 0;
}
