class WordDictionary 
{
public:
	struct TrieNode
	{
		TrieNode()
		{
			memset(kChildren,0,sizeof(TrieNode*)  * 26);
			iEndNode = 0;
		};

		TrieNode* kChildren[26];
		int iEndNode;
	};

	WordDictionary() 
	{
		m_pkRoot = new TrieNode();
	}

	void addWord(string word) 
	{
		if(word.empty())
		{
			return;
		}
		TrieNode* pkParent = m_pkRoot;		
		for(int j = 0;j < word.length();j++)
		{
			TrieNode* pkNode = NULL;
			if(pkParent->kChildren[word[j] - 'a'] == NULL)
			{
				pkNode = new TrieNode();
				pkParent->kChildren[word[j] - 'a'] = pkNode;
			}
			else 
			{
				pkNode = pkParent->kChildren[word[j] - 'a'];
			}
			pkParent = pkNode;
		}
		pkParent->iEndNode = 1;
	}

	
	bool search(string word) 
	{
		if(!m_pkRoot)
		{
			return false;
		}
		TrieNode* pkNode = m_pkRoot;
		deque<TrieNode*> bfs;
		bfs.push_back(pkNode);
		for(int i = 0;  i < word.length();i++)
		{
			if(word[i] == '.')
			{
				bool bFind = false;
				int iBFSSize = bfs.size();
				for(int m = 0;m < iBFSSize;m++)
				{
					pkNode = bfs.front();
					bfs.pop_front();
					for(int n = 0 ; n < 26; n++)
					{
						if(pkNode->kChildren[n])
						{
							bfs.push_back(pkNode->kChildren[n]);
							bFind = true;
						}
					}
				}
				if(!bFind)
				{
					return false;
				}
			}
			else
			{
				bool bFind = false;
				int iBFSSize = bfs.size();
				for(int m = 0;m < iBFSSize;m++)
				{
					pkNode = bfs.front();
					bfs.pop_front();
					if(pkNode->kChildren[word[i] - 'a'])
					{
						bfs.push_back(pkNode->kChildren[word[i] - 'a']);
						bFind = true;
					}
				}
				if(!bFind)
				{
					return false;
				}
			}
		}

		while(!bfs.empty())
		{
			pkNode = bfs.front();
			bfs.pop_front();
			if(pkNode->iEndNode > 0)
			{
				return true;
			}
		}

		return false;
	}
private:
	TrieNode* m_pkRoot;
};
