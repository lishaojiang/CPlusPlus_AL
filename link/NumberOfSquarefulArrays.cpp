#include<iostream>
#include<vector>
#include<set>
#include<math.h>


using namespace std;



class Solution 
{
public:
	void DFS(int iIndex,set<int> kSet,vector<int>& A,int& iTimes)
	{
		kSet.insert(iIndex);
		if(kSet.size() == A.size())
		{
			iTimes++;
			return;
		}
		for(int i = 0; i < A.size();i++)
		{
			if(kSet.find(i) != kSet.end())
			{
				continue;
			}
			set<int> kSetTemp = kSet;
			if(sqrt(float(A[iIndex] + A[i])) == (int)sqrt(float(A[iIndex] + A[i])))
			{
				// if this is right,we must check the new point
				for(int j = i+1; j < A.size();j++)
				{
					if(A[j] == A[i] && kSet.find(j) == kSet.end())
					{
						i= j;
					}
					else
					{
						break;
					}
				}
				DFS(i,kSetTemp,A,iTimes);
			}
		}
	}
	void DFS_Fast(int iIndex,vector<int>& A,int& iTimes)
	{
		int iOrig = A[iIndex];
		vector<int>::iterator iter = A.begin() + iIndex;
		A.erase(iter);
		if(A.empty())
		{
			iTimes++;
			return;
		}
		for(int i = 0; i < A.size();i++)
		{
			if(sqrt(float(iOrig + A[i])) == (int)sqrt(float(iOrig + A[i])))
			{
				// if this is right,we must check the new point
				for(int j = i+1; j < A.size();j++)
				{
					if(A[j] == A[i])
					{
						i= j;
					}
					else
					{
						break;
					}
				}
				vector<int> kTemp = A;
				DFS_Fast(i,kTemp,iTimes);
			}
		}
	}
	int numSquarefulPerms(vector<int>& A) 
	{
		vector<vector<int> > kVec;
		int iTimes = 0;
		set<int> kSet;
		std::sort(A.begin(),A.end());
		for(int i = 0; i < A.size();i++)
		{
			if((i+1) < A.size())
			{
				if(A[i]==A[i+1])
				{
					continue;
				}
			}
			// kSet.clear();
			// DFS(i,kSet,kTemp,iTimes);
			vector<int> ATemp = A;
			DFS_Fast(i,ATemp,iTimes);
		}

		return iTimes;

	}
};

int main(int,const char**)
{
	vector<int> a;
	a.push_back(5);
	a.push_back(11);
	a.push_back(5);
	a.push_back(4);
	a.push_back(5);
	//a.push_back(2);
	//a.push_back(2);
	//a.push_back(2);
	//a.push_back(2);
	Solution ks;
	int iRet = ks.numSquarefulPerms(a);
	return 0;
}