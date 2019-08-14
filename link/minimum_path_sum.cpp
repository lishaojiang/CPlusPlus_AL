class Solution 
{
public:
    // DP[m*n] = min(DP[m-1][n],DP[m][n-1]) + DP[m][n];
    int minPathSum(vector<vector<int> >& grid) 
    {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();

        for(int i = 1; i < m ;i++)
        {
            grid[0][i] = grid[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < n ;i++)
        {
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }

        for(int i = 1;i < n;i++)
        {
            for(int j = 1; j < m;j++)
            {
                grid[i][j] = grid[i][j] + (grid[i][j-1] < grid[i-1][j] ? grid[i][j-1] : grid[i-1][j]);                   
            }
        }

        return grid[n-1][m-1];

    }
};