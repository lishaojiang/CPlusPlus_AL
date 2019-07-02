class SolutionI
{
public:
	struct Node
	{
		Node()
		{
			bRead =false;
			akChildren.clear();
		}
		bool bRead;
		vector<Node*> akChildren;
	};
	bool DFS(Node* pkNode,bool& bRead)
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
		// we mark this node has been read
		pkNode->bRead = true;
		for(int i = 0; i < pkNode->akChildren.size();i++)
		{
			DFS(pkNode->akChildren[i],bRead);
			if(bRead) break;
		}
		pkNode->bRead = false;
		return !bRead;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
	{
		map<int,Node*> kGraph;
		map<int,Node*> kRealGraph;

		// make graph nodes and path
		for(int i = 0; i <prerequisites.size();i++)
		{
			map<int,Node*>::iterator iterP = kGraph.find(prerequisites[i][0]);
			if(iterP == kGraph.end())
			{
				kGraph[prerequisites[i][0]] = new Node();
			}
			map<int,Node*>::iterator iterC = kGraph.find(prerequisites[i][1]);
			if(iterC == kGraph.end())
			{
				kGraph[prerequisites[i][1]] = new Node();
			}
			kGraph[prerequisites[i][0]]->akChildren.push_back(kGraph[prerequisites[i][1]]);

			map<int,Node*>::iterator iterR = kRealGraph.find(prerequisites[i][1]);
			if(iterR != kRealGraph.end())
			{
				kRealGraph.erase(iterR);
			}
			kRealGraph[prerequisites[i][0]] = kGraph[prerequisites[i][0]]; 

		}

		// check is there are circle
		bool bRead = false;
		for(map<int,Node*>::iterator iter = kRealGraph.begin();iter != kRealGraph.end();iter++)
		{
			bRead = false;
			DFS(iter->second,bRead);
			if(bRead)	return false;
		}
		return true;
	}
};

