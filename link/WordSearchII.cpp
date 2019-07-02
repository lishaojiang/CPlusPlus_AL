#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<unordered_set>

using namespace std;

// this ia a AC way, I can understand totally,but my set,vector is too much, it use more time 
// I should like this way,use the it's value to reduce this.
// borad[y][x] = 0; this is very good idea.

// one: we build trie tree first,we put all the need check words into the tree.
// two: we search the graph by use DFS,the DFS way compare with the trie tree.
// speed up way is upon words.
class Solution
{
public:
	struct TrieNode
	{
		TrieNode()
		{
			memset(kChildren, 0, sizeof(TrieNode*) * 26);
			iEndNode = 0;
			iTimes = 0;
		};

		TrieNode* kChildren[26];
		int iEndNode;
		int iTimes;
	};

	void TrieAddWord(string kWord)
	{
		if (kWord == "")
		{
			return;
		}
		if (m_pkTrieRoot == NULL)
		{
			m_pkTrieRoot = new TrieNode();
			m_pkTrieRoot->iTimes = -1;
		}

		TrieNode* pkParent = m_pkTrieRoot;
		for (int j = 0; j < kWord.length(); j++)
		{
			TrieNode* pkNode = NULL;
			if (pkParent->kChildren[kWord[j] - 'a'] == NULL)
			{
				pkNode = new TrieNode();
				pkNode->iTimes = 1;
				pkParent->kChildren[kWord[j] - 'a'] = pkNode;
			}
			else
			{
				pkNode = pkParent->kChildren[kWord[j] - 'a'];
				pkNode->iTimes++;
			}
			pkParent = pkNode;
		}
		pkParent->iEndNode = 1;
	}

	void MakeUpTrieTree(vector<string>& kWords)
	{
		for(int i = 0; i < kWords.size();i++)
		{
			TrieAddWord(kWords[i]);
		}
	}

	void DFS_Graphic(vector<vector<char> >& borad,TrieNode* pkTrieNode,string kWord,vector<TrieNode*> kPath,unordered_set<int> kSet,int x,int y,int iWidth,int iHeight,vector<string>& kOut)
	{
        if(pkTrieNode == NULL) return;
		if(x < 0 || x >= iWidth || y < 0 || y >= iHeight)
		{
			return;
		}
		// if(kSet.find(y * iWidth + x) != kSet.end())
		// {
		// 	return;
		// }
		// kSet.insert(y * iWidth + x);
        if(borad[y][x] == 0) return;
        char c = borad[y][x];
		if(pkTrieNode->kChildren[c-'a'] == NULL || pkTrieNode->kChildren[c-'a']->iTimes == 0)
		{
			return;
		}
        borad[y][x] = 0;
		kWord += c;
        //kSet.insert(y * iWidth + x);
		//kPath.push_back(pkTrieNode->kChildren[c-'a']);
		if(pkTrieNode->kChildren[c-'a']->iEndNode > 0)
		{
			// right word
            pkTrieNode->kChildren[c-'a']->iEndNode = 0;
			 kOut.push_back(kWord);
			// for(int i = 0;i < kPath.size();i++)
			// {
			// 	kPath[i]->iTimes--;
			// }
		}
		DFS_Graphic(borad,pkTrieNode->kChildren[c-'a'],kWord,kPath,kSet,x-1,y,iWidth,iHeight,kOut);
		DFS_Graphic(borad,pkTrieNode->kChildren[c-'a'],kWord,kPath,kSet,x+1,y,iWidth,iHeight,kOut);
		DFS_Graphic(borad,pkTrieNode->kChildren[c-'a'],kWord,kPath,kSet,x,y-1,iWidth,iHeight,kOut);
		DFS_Graphic(borad,pkTrieNode->kChildren[c-'a'],kWord,kPath,kSet,x,y+1,iWidth,iHeight,kOut);
        borad[y][x] = c;
	}

	void CheckWordTrie(vector<vector<char> >& borad,vector<string>& kOut)
	{
		if (borad.empty())
		{
			return;
		}
		int iHeight = borad.size();
		int iWidth = borad[0].size();
		if (iWidth == 0)
		{
			return;
		}

		string kWord = "";
		vector<TrieNode*> kPath;
		unordered_set<int> kSet;
		for(int iH = 0; iH < iHeight;iH++)
		{
			for(int iW = 0; iW < iWidth;iW++)
			{
				kWord = "";
				kPath.clear();
				kSet.clear();
				DFS_Graphic(borad,m_pkTrieRoot,kWord,kPath,kSet,iW,iH,iWidth,iHeight,kOut);
			}
		}

	}


	vector<string> findWords(vector<vector<char> >& board, vector<string>& words)
	{
		vector<string> kRet;
		MakeUpTrieTree(words);
		CheckWordTrie(board,kRet);
		return kRet;
	}

private:
	TrieNode*      m_pkTrieRoot;
};


//this is my first funciton,it can work well,but too slowly,we must speed it up

// class Solution
// {
// public:
// 	struct Node
// 	{
// 		Node()
// 		{
// 			c = 0;
// 		}
// 		vector<Node*> kNearNodes;
// 		char c;
// 	};

// 	struct TrieNode
// 	{
// 		TrieNode()
// 		{
// 			memset(kChildren, 0, sizeof(TrieNode*) * 26);
// 			iEndNode = 0;
// 			iTimes = 0;
// 		};

// 		TrieNode* kChildren[26];
// 		int iEndNode;
// 		int iTimes;
// 	};

// 	void TrieAddWord(string kWord)
// 	{
// 		if (kWord == "")
// 		{
// 			return;
// 		}
// 		if (m_pkTrieRoot == NULL)
// 		{
// 			m_pkTrieRoot = new TrieNode();
// 			m_pkTrieRoot->iTimes = -1;
// 		}

// 		TrieNode* pkParent = m_pkTrieRoot;
// 		for (int j = 0; j < kWord.length(); j++)
// 		{
// 			TrieNode* pkNode = NULL;
// 			if (pkParent->kChildren[kWord[j] - 'a'] == NULL)
// 			{
// 				pkNode = new TrieNode();
// 				pkNode->iTimes = 1;
// 				pkParent->kChildren[kWord[j] - 'a'] = pkNode;
// 			}
// 			else
// 			{
// 				pkNode = pkParent->kChildren[kWord[j] - 'a'];
// 				pkNode->iTimes++;
// 			}
// 			pkParent = pkNode;
// 		}
// 		pkParent->iEndNode = 1;
// 	}

// 	void MakeUpTrieTree(vector<string>& kWords)
// 	{
// 		for(int i = 0; i < kWords.size();i++)
// 		{
// 			TrieAddWord(kWords[i]);
// 		}
// 	}

// 	void DFS_Graphic(vector<vector<char> >& borad,TrieNode* pkTrieNode,string kWord,vector<TrieNode*> kPath,int x,int y,int iWidth,int iHeight,vector<string>& kOut)
// 	{
// 		if(x < 0 || x >= iWidth || y < 0 || y >= iHeight)
// 		{
// 			return;
// 		}
// 		char c = borad[y][x];
// 		if(pkTrieNode->kChildren[c-'a'] == NULL || pkTrieNode->kChildren[c-'a']->iTimes == 0)
// 		{
// 			return;
// 		}
// 		kWord += c;
// 		kPath.push_back(pkTrieNode->kChildren[c-'a']);
// 		if(pkTrieNode->kChildren[c-'a']->iEndNode > 0)
// 		{
// 			// right word
// 			kOut.push_back(kWord);
// 			for(int i = 0;i < kPath.size();i++)
// 			{
// 				kPath[i]->iTimes--;
// 			}
// 		}
// 		DFS_Graphic(borad,pkTrieNode->kChildren[c-'a'],kWord,kPath,x-1,y,iWidth,iHeight,kOut);
// 		DFS_Graphic(borad,pkTrieNode->kChildren[c-'a'],kWord,kPath,x+1,y,iWidth,iHeight,kOut);
// 		DFS_Graphic(borad,pkTrieNode->kChildren[c-'a'],kWord,kPath,x,y-1,iWidth,iHeight,kOut);
// 		DFS_Graphic(borad,pkTrieNode->kChildren[c-'a'],kWord,kPath,x,y+1,iWidth,iHeight,kOut);
// 	}

// 	void CheckWordTrie(vector<vector<char> >& borad,vector<string>& kOut)
// 	{
// 		if (borad.empty())
// 		{
// 			return;
// 		}
// 		int iHeight = borad.size();
// 		int iWidth = borad[0].size();
// 		if (iWidth == 0)
// 		{
// 			return;
// 		}

// 		string kWord = "";
// 		vector<TrieNode*> kPath;
// 		for(int iH = 0; iH < iHeight;iH++)
// 		{
// 			for(int iW = 0; iW < iWidth;iW++)
// 			{
// 				kWord = "";
// 				kPath.clear();
// 				DFS_Graphic(borad,m_pkTrieRoot,kWord,kPath,iW,iH,iWidth,iHeight,kOut);
// 			}
// 		}

// 	}



// 	bool TrieGetWord(string word)
// 	{
// 		if (!m_pkTrieRoot)
// 		{
// 			return false;
// 		}
// 		TrieNode* pkNode = m_pkTrieRoot;
// 		int i = 0;
// 		while (pkNode)
// 		{
// 			if (i < word.length() && pkNode->kChildren[word[i] - 'a'])
// 			{
// 				pkNode = pkNode->kChildren[word[i] - 'a'];
// 				i++;
// 			}
// 			else
// 			{
// 				return false;
// 			}
// 		}
// 		if (i == word.length())
// 		{
// 			return true;
// 		}
// 		return false;
// 	}


// 	void MakeUpGraph(vector<vector<char> >& borad)
// 	{
// 		// fill the speed up vector
// 		if (borad.empty())
// 		{
// 			return;
// 		}
// 		int iHeight = borad.size();
// 		int iWidth = borad[0].size();
// 		if (iWidth == 0)
// 		{
// 			return;
// 		}



// 		vector<Node*> kVecNode;
// 		for (int iH = 0; iH < iHeight; iH++)
// 		{
// 			for (int iW = 0; iW < iWidth; iW++)
// 			{
// 				Node* pkNode = new Node();
// 				pkNode->c = borad[iH][iW];
// 				m_kSpeedUp[pkNode->c - 'a'].push_back(pkNode);
// 				kVecNode.push_back(pkNode);
// 			}
// 		}

// 		// make up node connect,to format it's graphic
// 		for (int i = 0; i < kVecNode.size(); i++)
// 		{
// 			Node* pkNode = kVecNode[i];
// 			int iLeft = (i % iWidth) - 1;
// 			if (iLeft >= 0)
// 			{
// 				pkNode->kNearNodes.push_back(kVecNode[i - 1]);
// 			}
// 			int iRight = (i % iWidth) + 1;
// 			if (iRight < iWidth)
// 			{
// 				pkNode->kNearNodes.push_back(kVecNode[i + 1]);
// 			}
// 			int iUp = (i / iWidth) - 1;
// 			if (iUp >= 0)
// 			{
// 				pkNode->kNearNodes.push_back(kVecNode[i - iWidth]);
// 			}
// 			int iDown = (i / iWidth) + 1;
// 			if (iDown < iHeight)
// 			{
// 				pkNode->kNearNodes.push_back(kVecNode[i + iWidth]);
// 			}
// 		}
// 	}

// 	bool IsRightWord(string kWord)
// 	{
// 		if (TrieGetWord(kWord))
// 		{
// 			return true;
// 		}

// 		unordered_set<Node*> kSet;
// 		int iWordIndex = 0;
// 		bool bHas = false;
// 		for (int i = 0; i < m_kSpeedUp[kWord[0] - 'a'].size(); i++)
// 		{
// 			kSet.clear();
// 			iWordIndex = 0;
// 			bHas = false;
// 			DFS_Serach(m_kSpeedUp[kWord[0] - 'a'][i], kSet, kWord, iWordIndex, bHas);
// 			if (bHas)
// 			{
// 				TrieAddWord(kWord);
// 				return true;
// 			}
// 		}
// 		return false;
// 	}

// 	void DFS_Serach(Node* pkNode, unordered_set<Node*> kSet, string& kWord, int iIndex, bool& bRight)
// 	{
// 		if (bRight == true)
// 		{
// 			return;
// 		}
// 		if (pkNode)
// 		{
// 			if (iIndex < kWord.length())
// 			{
// 				kSet.insert(pkNode);
// 				if (pkNode->c == kWord[iIndex])
// 				{
// 					// if find the right path
// 					if (iIndex == kWord.length() - 1)
// 					{
// 						bRight = true;
// 						return;
// 					}
// 					for (int i = 0; i < pkNode->kNearNodes.size(); i++)
// 					{
// 						if (kSet.find(pkNode->kNearNodes[i]) != kSet.end())
// 						{
// 							continue;
// 						}
// 						if ((iIndex + 1) < kWord.length() && pkNode->kNearNodes[i]->c == kWord[iIndex+1])
// 						{
// 							DFS_Serach(pkNode->kNearNodes[i], kSet, kWord, iIndex + 1, bRight);
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}

// 	vector<string> findWords(vector<vector<char> >& board, vector<string>& words)
// 	{
// 		vector<string> kRet;
// 		// MakeUpGraph(board);

// 		// for (int i = 0; i < words.size(); i++)
// 		// {
// 		// 	if (IsRightWord(words[i]))
// 		// 	{
// 		// 		kRet.push_back(words[i]);
// 		// 	}
// 		// }
// 		MakeUpTrieTree(words);
// 		CheckWordTrie(board,kRet);
// 		return kRet;
// 	}

// private:
// 	vector<Node*> m_kSpeedUp[26];
// 	TrieNode*      m_pkTrieRoot;

// };



// funtion II,i try to slove this problem
// class Solution
// {
// public:
// 	struct Node
// 	{
// 		Node()
// 		{
// 			c = 0;
// 		}
// 		vector<Node*> kNearNodes;
// 		char c;
// 	};

// 	struct TrieNode
// 	{
// 		TrieNode()
// 		{
// 			memset(kChildren, 0, sizeof(TrieNode*) * 26);
// 			//            iEndNode = 0;
//             kPaths.clear();
// 		};

// 		TrieNode* kChildren[26];
// 		//int iEndNode;
//         vector<vector<Node*> > kPaths;
// 	};

// 	void TrieAddWord(string kWord,vector<vector<Node*> > kOutPaths)
// 	{
// 		if (kWord == "")
// 		{
// 			return;
// 		}
// 		if (m_pkTrieRoot == NULL)
// 			m_pkTrieRoot = new TrieNode();

// 		TrieNode* pkParent = m_pkTrieRoot;
// 		for (int j = 0; j < kWord.length(); j++)
// 		{
// 			TrieNode* pkNode = NULL;
// 			if (pkParent->kChildren[kWord[j] - 'a'] == NULL)
// 			{
// 				pkNode = new TrieNode();
// 				pkParent->kChildren[kWord[j] - 'a'] = pkNode;
// 			}
// 			else
// 			{
// 				pkNode = pkParent->kChildren[kWord[j] - 'a'];
// 			}
// 			pkParent = pkNode;
// 		}
//         pkParent->kPaths = kOutPaths;
// 	}

// 	bool TrieGetWord(string word,string& kPreWord,vector<vector<Node*> >& kPrePaths)
// 	{
//         kPreWord = "";
//         kPrePaths.clear();
// 		if (!m_pkTrieRoot)
// 		{
// 			return false;
// 		}
// 		TrieNode* pkNode = m_pkTrieRoot;
// 		int i = 0;
// 		while (pkNode)
// 		{
//             if(i < word.length())
//             {
//                 if (pkNode->kChildren[word[i] - 'a'])
//                 {
//                     pkNode = pkNode->kChildren[word[i] - 'a'];
//                     i++;
//                 }
//                 else
//                 {
//                     kPreWord = string(word,0,i);
//                     kPrePaths = pkNode->kPaths;
//                     return false;
//                 }
//             }
// 		}
// 		if (i == word.length())
// 		{
// 			return true;
// 		}
// 		return false;
// 	}


// 	void MakeUpGraph(vector<vector<char> >& borad)
// 	{
// 		// fill the speed up vector
// 		if (borad.empty())
// 		{
// 			return;
// 		}
// 		int iHeight = borad.size();
// 		int iWidth = borad[0].size();
// 		if (iWidth == 0)
// 		{
// 			return;
// 		}



// 		vector<Node*> kVecNode;
// 		for (int iH = 0; iH < iHeight; iH++)
// 		{
// 			for (int iW = 0; iW < iWidth; iW++)
// 			{
// 				Node* pkNode = new Node();
// 				pkNode->c = borad[iH][iW];
// 				m_kSpeedUp[pkNode->c - 'a'].push_back(pkNode);
// 				kVecNode.push_back(pkNode);
// 			}
// 		}

// 		// make up node connect,to format it's graphic
// 		for (int i = 0; i < kVecNode.size(); i++)
// 		{
// 			Node* pkNode = kVecNode[i];
// 			int iLeft = (i % iWidth) - 1;
// 			if (iLeft >= 0)
// 			{
// 				pkNode->kNearNodes.push_back(kVecNode[i - 1]);
// 			}
// 			int iRight = (i % iWidth) + 1;
// 			if (iRight < iWidth)
// 			{
// 				pkNode->kNearNodes.push_back(kVecNode[i + 1]);
// 			}
// 			int iUp = (i / iWidth) - 1;
// 			if (iUp >= 0)
// 			{
// 				pkNode->kNearNodes.push_back(kVecNode[i - iWidth]);
// 			}
// 			int iDown = (i / iWidth) + 1;
// 			if (iDown < iHeight)
// 			{
// 				pkNode->kNearNodes.push_back(kVecNode[i + iWidth]);
// 			}
// 		}
// 	}

// 	bool IsRightWord(string kWord)
// 	{
//         string kPreWord = "";
//         vector<vector<Node*> > kPrePath;
// 		if (TrieGetWord(kWord,kPreWord,kPrePath))
// 		{
// 			return true;
// 		}

//         // if we have the right pre word,we use it
//         if(kPreWord.empty() || kPrePath.empty())
//         {
//             vector<Node*> kVec;
//             vector<vector<Node*> > kAllPaths;
//             vector<vector<Node*> > kOnePath;
//             int iWordIndex = 0;
//             bool bHas = false;
//             for (int i = 0; i < m_kSpeedUp[kWord[0] - 'a'].size(); i++)
//             {
//                 kVec.clear();
//                 kOnePath.clear();
//                 iWordIndex = 0;
//                 bHas = false;
//                 DFS_Serach(m_kSpeedUp[kWord[0] - 'a'][i], kVec, kWord, iWordIndex, bHas,kOnePath);
//                 if (bHas)
//                 {
//                     //TrieAddWord(kWord);
//                     //return true;
//                     for(int j = 0; j < kOnePath.size();j++)
//                     {
//                         kAllPaths.push_back(kOnePath[j]);
//                     }
//                     bHas = false;
//                 }
//             }
//             if(!kAllPaths.empty())
//             {
//                 TrieAddWord(kWord,kAllPaths);
//                 return true;
//             }
//         }
//         else
//         {
//             vector<Node*> kVec;
//             vector<vector<Node*> > kAllPaths;
//             vector<vector<Node*> > kOnePath;
//             int iWordIndex = 0;
//             bool bHas = false;
//             string kNextWord = string(kWord,kPreWord.length()-1,kWord.length() - kPreWord.length()+1);
//             for(int i = 0; i < kPrePath.size();i++)
//             //for (int i = 0; i < m_kSpeedUp[kWord[0] - 'a'].size(); i++)
//             {
//                 kVec = kPrePath[i];
//                 kOnePath.clear();
//                 iWordIndex = 0;
//                 bHas = false;
//                 //DFS_Serach(m_kSpeedUp[kWord[0] - 'a'][i], kVec, kWord, iWordIndex, bHas,kOnePath);
//                 DFS_Serach(kVec[kVec.size()-1], kVec, kNextWord, iWordIndex, bHas,kOnePath);
//                 if (bHas)
//                 {
//                     //TrieAddWord(kWord);
//                     //return true;
//                     for(int j = 0; j < kOnePath.size();j++)
//                     {
//                         kAllPaths.push_back(kOnePath[j]);
//                     }
//                     bHas = false;
//                 }
//             }
//             if(!kAllPaths.empty())
//             {
//                 TrieAddWord(kWord,kAllPaths);
//                 return true;
//             }            
//         }
        


// 		return false;
// 	}

// 	void DFS_Serach(Node* pkNode, vector<Node*> kVec, string& kWord, int iIndex, bool& bRight,vector<vector<Node*> >& kPaths)
// 	{
// 		if (pkNode)
// 		{
// 			if (iIndex < kWord.length())
// 			{
// 				kVec.push_back(pkNode);
// 				if (pkNode->c == kWord[iIndex])
// 				{
// 					// if find the right path
// 					if (iIndex == kWord.length() - 1)
// 					{
// 						bRight = true;
//                         kPaths.push_back(kVec);
// 						return;
// 					}
// 					for (int i = 0; i < pkNode->kNearNodes.size(); i++)
// 					{
// 						if (std::find(kVec.begin(),kVec.end(),pkNode->kNearNodes[i]) != kVec.end())
// 						{
// 							continue;
// 						}
// 						if ((iIndex + 1) < kWord.length() && pkNode->kNearNodes[i]->c == kWord[iIndex+1])
// 						{
// 							DFS_Serach(pkNode->kNearNodes[i], kVec, kWord, iIndex + 1, bRight,kPaths);
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}

// 	vector<string> findWords(vector<vector<char> >& board, vector<string>& words)
// 	{
// 		vector<string> kRet;
// 		MakeUpGraph(board);

// 		for (int i = 0; i < words.size(); i++)
// 		{
// 			if (IsRightWord(words[i]))
// 			{
// 				kRet.push_back(words[i]);
// 			}
// 		}
// 		return kRet;
// 	}

// private:
// 	vector<Node*> m_kSpeedUp[26];
// 	TrieNode*      m_pkTrieRoot;

// };

int main(int XX,const char* xxxxx[])
{
    Solution ks;
    vector<vector<char> > borad;
    vector<char> a,b;
    a.push_back('a');
    a.push_back('b');
    b.push_back('c');
    b.push_back('d');
    borad.push_back(a);
    borad.push_back(b);
    vector<string> kWords;
    kWords.push_back("ab");
    kWords.push_back("cb");
    kWords.push_back("ad");
    kWords.push_back("bd");
    kWords.push_back("ac");
    kWords.push_back("ca");
    kWords.push_back("abb");

    vector<string> kOut;
    kOut = ks.findWords(borad,kWords);
    int i = 3;
    return 0;

}