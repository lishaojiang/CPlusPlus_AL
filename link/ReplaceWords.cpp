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

class TrieTreeDic
{
public:
	TrieTreeDic();
	void MakeTree(vector<string>& dict);
	void DeleteTree(TrieNode* pkNode);
	string GetPreWord(string word);
private:
	TrieNode* m_pkRoot;
};

TrieTreeDic::TrieTreeDic()
{
	m_pkRoot = NULL;
}

void TrieTreeDic::MakeTree(vector<string>& dict)
{
	DeleteTree(m_pkRoot);
	m_pkRoot = NULL;
	// make the new root node
	m_pkRoot = new TrieNode();

	for(int i = 0; i < dict.size();i++)
	{
		string kWord = dict[i];
		TrieNode* pkParent = m_pkRoot;		
		for(int j = 0;j < kWord.length();j++)
		{
			TrieNode* pkNode = NULL;
			if(pkParent->kChildren[kWord[j] - 'a'] == NULL)
			{
				pkNode = new TrieNode();
				pkParent->kChildren[kWord[j] - 'a'] = pkNode;
			}
			else 
			{
				pkNode = pkParent->kChildren[kWord[j] - 'a'];
			}
			pkParent = pkNode;
		}
		pkParent->iEndNode = 1;
	}
}

void TrieTreeDic::DeleteTree(TrieNode* pkNode)
{
	if(!pkNode)
	{
		return;
	}

	for(int i = 0;i < 26;i++)
	{
		 if(pkNode->kChildren[i])
		 {
			 DeleteTree(pkNode->kChildren[i]);
		 }
	}
	delete pkNode;
}

string TrieTreeDic::GetPreWord(string word)
{
	if(!m_pkRoot)
	{
		return word;
	}
	TrieNode* pkNode = m_pkRoot;
	int i = 0;
	while(pkNode)
	{
		if(i < word.length() && pkNode->kChildren[word[i] - 'a'])
		{
			pkNode = pkNode->kChildren[word[i] - 'a'];
			i++;
			if(pkNode->iEndNode > 0)
			{
				string kS(word,0,i);
				return kS;
			}
		}
		else
		{
			return word;
		}
	}
	return word;
}


string replaceWords(vector<string>& dict, string sentence) 
{
	string kRet = "";
	TrieTreeDic kDic;
	kDic.MakeTree(dict);
	string kOneWord  = "";
	for(int i = 0; i < sentence.length();i++)
	{
		if(sentence[i] != ' ')
		{
			kOneWord += sentence[i];
		}
		else
		{
			kRet += kDic.GetPreWord(kOneWord);
			kRet += " ";
			kOneWord = "";
		}
	}
	if(kOneWord != "")
	{
		kRet += kDic.GetPreWord(kOneWord);
	}
	return kRet;
}
