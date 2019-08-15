class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
         if(m == n && n == 0)
            return 0;
        int DP[n][m] = {1};

        for(int i = 0; i < m;i++)
        {
            DP[0][i] = 1;
        }

        for(int i = 0; i < n;i++)
        {
            DP[i][0] = 1;
        }

        for(int i = 1;i < m;i++)
            for(int j = 1; j < n;j++)
                DP[j][i] = DP[j][i-1] +DP[j-1][i];
        return DP[n-1][m-1];
    }
};