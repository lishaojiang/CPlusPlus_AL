#include<iostream>
#include<vector>
#include<set>
#include<map>
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

class ClasGraphic
{
public:
    struct Node
    {
        int iValue;
        int iTimes;
        set<Node*> kChild;
    };
    
    void DFS_Search(Node* pkNode,int N,int& iTimes)
    {
        if(N == 0)
        {
            iTimes++;
            return;
        }
        if(pkNode && !pkNode->kChild.empty())
        {
            set<Node*>::iterator iter = pkNode->kChild.begin();
            for(;iter != pkNode->kChild.end();iter++)
            {
                (*iter)->iTimes--;
                if((*iter)->iTimes >= 0)
                    DFS_Search(*iter,N-1,iTimes);
                (*iter)->iTimes++;
            }
        }
    }
    
    int numSquarefulPerms(vector<int>& A)
    {
        map<int,Node*> kGraphic;
        int iTimes = 0;
        // make nodes
        for(int i = 0; i < A.size();i++)
        {
            map<int,Node*>::iterator it = kGraphic.find(A[i]);
            if(it == kGraphic.end())
            {
                Node* pkNode = new Node;
                pkNode->iValue = A[i];
                pkNode->iTimes = 1;
                kGraphic[A[i]] = pkNode;
            }
            else
            {
                it->second->iTimes++;
            }
        }
        
        // make path
        for(map<int,Node*>::iterator iterA = kGraphic.begin();iterA != kGraphic.end();iterA++)
        {
            for(map<int,Node*>::iterator iterB = kGraphic.begin();iterB != kGraphic.end();iterB++)
            {
                if(sqrt(float(iterA->first + iterB->first)) == (int)sqrt(float(iterA->first + iterB->first)))
                {
                    iterA->second->kChild.insert(iterB->second);
                }
            }
        }
        
        // DFS search
        map<int,Node*>::iterator iterA = kGraphic.begin();
        for(;iterA != kGraphic.end();iterA++)
        {
            iterA->second->iTimes--;
            DFS_Search(iterA->second,A.size()-1,iTimes);
            iterA->second->iTimes++;
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
	ClasGraphic ks;
	int iRet = ks.numSquarefulPerms(a);
	return 0;
}