class Solution
{
public:
	struct Point
	{
		Point(int X, int Y)
		{
			iX = X;
			iY = Y;
		}
		int iX;
		int iY;
	};
	const int SearchList[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

	// BFS search 
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
	{
		// BFS deal
		int iHeight = image.size();
		if (iHeight == 0) return image;
		int iWidth = image[0].size();
		if (iWidth == 0) return image;

		if (sc >= iWidth || sc < 0 || sr >= iHeight || sr < 0)
		{
			return image;
		}

		deque<Point> kDeque;
		int iOriColor = image[sr][sc];
		image[sr][sc] = newColor;
		kDeque.push_back(Point(sc, sr));

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
					if (image[y][x] == iOriColor && image[y][x] != newColor)
					{
						image[y][x] = newColor;
						kDeque.push_back(Point(x,y));
					}
				}
			}
		}

		return image;
	}
};