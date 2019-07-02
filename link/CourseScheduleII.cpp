class Solution
{
public:
	struct Node
	{
		Node(int _Index)
		{
			bRead =false;
			iIndex = _Index;
			akChildren.clear();
		}
		bool bRead;
		int iIndex;
		vector<Node*> akChildren;
	};
	struct Info
	{
		Info(int _Index,int _Times)
		{
			iIndex = _Index;
			iTimes = _Times;
		}
		int iIndex;
		int iTimes;
	};

	struct Info_Compare
	{
		bool operator()(const Info& rkLeft,const Info& rkRight)
		{
			return rkLeft.iTimes > rkRight.iTimes;
		}
	};

	bool DFS(Node* pkNode,int iLevel,bool& bRead,vector<Info>& kVecInfo)
	{
		if(bRead)
		{
			return false;
		}
		if(!pkNode)
		{
			return true;
		}
		if(pkNode->bRead)
		{
			bRead = true;
			return false;
		}
		if(iLevel > kVecInfo[pkNode->iIndex].iTimes )
		{
			kVecInfo[pkNode->iIndex].iTimes = iLevel;
		}
		// we mark this node has been read
		pkNode->bRead = true;
		for(int i = 0; i < pkNode->akChildren.size();i++)
		{
			DFS(pkNode->akChildren[i],iLevel+1,bRead,kVecInfo);
			if(bRead) break;
		}
		pkNode->bRead = false;
		return !bRead;
	}

	void ResetGraphNotRead(map<int,Node*>& kGraph)
	{
		for(map<int,Node*>::iterator iter = kGraph.begin();iter != kGraph.end();iter++)
		{
			(iter->second)->bRead = false;
		}
	}

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
	{
		map<int,Node*> kGraph;
		map<int,Node*> kRealGraph;
		vector<Info> kVecInfo;
		vector<int> kRet;

		// make graph nodes and path
		for(int i = 0; i <prerequisites.size();i++)
		{
			map<int,Node*>::iterator iterP = kGraph.find(prerequisites[i][0]);
			if(iterP == kGraph.end())
			{
				kGraph[prerequisites[i][0]] = new Node(prerequisites[i][0]);
			}
			map<int,Node*>::iterator iterC = kGraph.find(prerequisites[i][1]);
			if(iterC == kGraph.end())
			{
				kGraph[prerequisites[i][1]] = new Node(prerequisites[i][1]);
			}
			kGraph[prerequisites[i][0]]->akChildren.push_back(kGraph[prerequisites[i][1]]);

			map<int,Node*>::iterator iterR = kRealGraph.find(prerequisites[i][1]);
			if(iterR != kRealGraph.end())
			{
				kRealGraph.erase(iterR);
			}
			kRealGraph[prerequisites[i][0]] = kGraph[prerequisites[i][0]]; 
		}

		for(int i = 0; i < numCourses;i++)
		{
			Info kInfo(i,0);
			kVecInfo.push_back(kInfo);
		}

		// check is there are circle
		bool bRead = false;
		for(map<int,Node*>::iterator iter = kGraph.begin();iter != kGraph.end();iter++)
		{
			bRead = false;
			DFS(iter->second,0,bRead,kVecInfo);
			if(bRead)	return kRet;
		}

		// sort 
		std::sort(kVecInfo.begin(),kVecInfo.end(),Info_Compare());
		for(int i = 0; i < numCourses;i++)
		{
			kRet.push_back(kVecInfo[i].iIndex);
		}
		return kRet;
	}
};

