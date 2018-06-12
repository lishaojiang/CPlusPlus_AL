class Solution 
{
public:
	//int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
	//{
	//	int iCount = 0;
	//	for (int i = 0; i < A.size(); i++)
	//	{
	//		for (int j = 0; j < B.size(); j++)
	//		{
	//			for (int k = 0; k < C.size(); k++)
	//			{
	//				for (int l = 0; l < D.size(); l++)
	//				{
	//					if (A[i] + B[j] + C[k] + D[l] == 0)
	//					{
	//						iCount++;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	return iCount;
	//}

	// function two
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
	{
		int iCount = 0;
		unordered_map<int, int> kG1;
		unordered_map<int, int>kG2;
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < B.size(); j++)
			{
				kG1[A[i] + B[j]] = kG1[A[i] + B[j]] + 1;
			}
		}
		for (int i = 0; i < C.size(); i++)
		{
			for (int j = 0; j < D.size(); j++)
			{
				kG2[C[i] + D[j]] = kG2[C[i] + D[j]] + 1;
			}
		}
		if (kG1.size() > kG2.size())
		{
			unordered_map<int, int>::iterator iter1 = kG1.begin();
			while (iter1 != kG1.end())
			{
				unordered_map<int, int>::iterator iter2 = kG2.find(-iter1->first);
				if (iter2 != kG2.end())
				{
					iCount += (iter2->second * iter1->second);
				}
				iter1++;
			}
		}
		else
		{
			unordered_map<int, int>::iterator iter1 = kG2.begin();
			while (iter1 != kG2.end())
			{
				unordered_map<int, int>::iterator iter2 = kG1.find(-iter1->first);
				if (iter2 != kG1.end())
				{
					iCount += (iter2->second * iter1->second);
				}
				iter1++;
			}
		}
		return iCount;
	}
};