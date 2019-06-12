class Solution 
{
public:
	struct Point
	{
		Point(int X, int Y, int Value)
		{
			iX = X;
			iY = Y;
			iValue = Value;
		}
		int iX;
		int iY;
		int iValue;
	};
	const int SearchList[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

    // BFS search 
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
	{
		int iHeight = matrix.size();
		int iWidth = matrix[0].size();
		vector<int> kOneLine(iWidth, INT_MAX);
		vector<vector<int>> kRet;
		deque<Point> kDeque;

		for (int i = 0; i < iHeight; i++)
		{
			kRet.push_back(kOneLine);
		}

		for (int i = 0; i < iHeight; i++)
		{
			for (int j = 0; j < iWidth; j++)
			{
				if (matrix[i][j] == 0)
				{
					kRet[i][j] = 0;
					Point kPoint(j,i,0);
					kDeque.push_back(kPoint);
				}
			}
		}

		//BFS_Visit(kRet, iWidth, iHeight);
		while (!kDeque.empty())
		{
			Point kPoint = kDeque.front();
			kDeque.pop_front();

			for (int m = 0; m < 4; m++)
			{
				int x = kPoint.iX + SearchList[m][0];
				int y = kPoint.iY + SearchList[m][1];
				if (x >= 0 && x < iWidth && y >= 0 && y < iHeight)
				{
                    if (kRet[y][x] > (kPoint.iValue + 1))
                    {
                        kRet[y][x] = (kPoint.iValue + 1);
                        Point kNewPoint(x,y,kPoint.iValue+1);
                        kDeque.push_back(kNewPoint);
                    }
				}
			}
		}

		return kRet;

	}
};