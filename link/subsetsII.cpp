// my first solution,it's was slow
class Solution {
public:
	struct Node
	{
		int iValue;
		map<int,Node*> akChildren;
	};
	Node* m_pkTrieTree;
	void DFS_MakeTree(vector<int>& nums,int index,vector<Node*> kVec)
	{
		vector<Node*> kTempVec;
		if(index == -1)
		{
			m_pkTrieTree = new Node();
			kTempVec.push_back(m_pkTrieTree);
		}
		else if(index >=  nums.size())
		{
			return;
		}
		else
		{
			//Node* pkNode = new Node();
			for(int i = 0; i < kVec.size();i++)
			{
				if(kVec[i]->akChildren.find(nums[index]) == kVec[i]->akChildren.end())
				{
					Node* pkNode = new Node();
					pkNode->iValue = nums[index];
					kTempVec.push_back(pkNode);
					kVec[i]->akChildren[nums[index]] = pkNode;
				}
			}
		}

		for(int i = 0; i < kTempVec.size();i++)
		{
			kVec.push_back(kTempVec[i]);
		}

		DFS_MakeTree(nums,index+1,kVec);
	}


	void DFS_GetTrieTree(vector<vector<int>>& kOut,vector<int> kOne,Node* pkNode)
	{
		if(pkNode)
		{
			map<int,Node*>::iterator iter = pkNode->akChildren.begin();
			for(;iter != pkNode->akChildren.end();iter++)
			{
				Node* pkNodeChild = iter->second;
				vector<int> kTemp = kOne;
				kTemp.push_back(pkNodeChild->iValue);
				kOut.push_back(kTemp);
				DFS_GetTrieTree(kOut,kTemp,pkNodeChild);
			}
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) 
	{
		// make up trie tree
		vector<Node*> kVec;
		vector<vector<int>> kOut;
		vector<int> a;
		kOut.push_back(a);
		sort(nums.begin(),nums.end());
		DFS_MakeTree(nums,-1,kVec);
		DFS_GetTrieTree(kOut,a,m_pkTrieTree);
		return kOut;
	}
};


