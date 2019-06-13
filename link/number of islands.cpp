#include<iostream>
#include<vector>
#include<deque>
#include<map>

using namespace std;

static const char director[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

class Solution {
public:
    
    struct Point
    {
        Point(int iX,int iY):x(iX),y(iY){};
        int x,y;
    };
    void DFS(vector< vector<char> >& g,int x,int y,int iWidth,int iHeight)
    {
        if(x < 0 || x >= iWidth || y < 0 || y >= iHeight)
        {
            return;
        }

        if(g[y][x] == '0')
        {
            return;
        }
        g[y][x] = '0';
        DFS(g,x-1,y,iWidth,iHeight);
        DFS(g,x+1,y,iWidth,iHeight);
        DFS(g,x,y-1,iWidth,iHeight);
        DFS(g,x,y+1,iWidth,iHeight);
    }
    int numIslands(vector< vector<char> >& grid) 
    {
        int iIslandNumber = 0;
        int iHeight = grid.size();
        if(iHeight == 0)
            return 0;
        int iWidth = grid[0].size();
        if(iWidth == 0)
            return 0;
        
        for(int i = 0; i < iHeight; i++)
        {
            for(int j = 0; j < iWidth; j++)
            {
                if(grid[i][j] == '1')
                {
                    iIslandNumber++;
                    DFS(grid,j,i,iWidth,iHeight);
                }
            }
        }
        return iIslandNumber;
    }

    // this function has run time over limit
    // after a lit repair,this can past,because i can't unstand bfs deeply
    // it can put some point mulitpre
    // add line 88,109,del line 95, it work well
    int numIslands_BFS(vector< vector<char> >& grid) 
    {
        int iIslandNumber = 0;
        int iHeight = grid.size();
        if(iHeight == 0)
            return 0;
        int iWidth = grid[0].size();
        if(iWidth == 0)
            return 0;

        deque<Point> kPointDeque;      
        for(int i = 0; i < iHeight; i++)
        {
            for(int j = 0; j < iWidth; j++)
            {
                if(grid[i][j] == '0')
                {
                    continue;
                }
                else
                {
                    // this is island
                    iIslandNumber++;
                    kPointDeque.clear();
                    kPointDeque.push_back(Point(j,i));
                    grid[i][j] = '0';
                    // search around
                    while(!kPointDeque.empty())
                    {
                        Point kP = kPointDeque.front();
                        kPointDeque.pop_front();
                        // set this point has visit
                        //grid[kP.y][kP.x] = '0';
                        for(int m = 0; m < 4; m++)
                        {
                            int x = kP.x + director[m][0];
                            int y = kP.y + director[m][1];
                            if(x < 0 || x >= iWidth || y < 0 || y >= iHeight)
                            {
                                continue;
                            }
        
                            if(grid[y][x] == '1')
                            {
                                kPointDeque.push_back(Point(x,y));
                                grid[y][x]='0';
                            }
                        }
                    }

                }
                
            }
        }
        return iIslandNumber;
    }
};

int main(int n,const char* c[])
{
    Solution ks;
    vector<char> a(5,'1');
    vector< vector<char> > grid;
    for(int i = 0; i < 5;i++)
    {
        grid.push_back(a);
    }
    for(int i = 0; i < 5;i++)
    {
        grid[4][i] = '0';
    }
    grid[3][3] = '0';
    int iRet = ks.numIslands(grid);
    printf("%d",iRet);
    return 0;
}