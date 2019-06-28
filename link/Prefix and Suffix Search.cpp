#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class WordFilter
{
public:
	struct Node
	{
		Node()
		{
			memset(akChildren,0,sizeof(akChildren));
			iEnd = -1;
			s = "";
		}
		Node* akChildren[26];
		string s;
		int iEnd;
	};

	void AddWord(string word,int iIndex)
	{
		// pre order
		{
			if(m_pkPreRoot == NULL)
			{
				m_pkPreRoot = new Node();
			}
			Node* pkNode = m_pkPreRoot;
			for(int i = 0; i < word.length(); i++)
			{
				if(pkNode->akChildren[word[i]-'a'] == NULL)
				{
					pkNode->akChildren[word[i]-'a'] = new Node();
				}
				pkNode = pkNode->akChildren[word[i] - 'a'];
			}
			pkNode->iEnd = iIndex;
			pkNode->s = word;
		}

		// suf order
		{
			if(m_pkSufRoot == NULL)
			{
				m_pkSufRoot = new Node();
			}
			Node* pkNode = m_pkSufRoot;
			for(int i = word.length()-1; i >= 0 ; i--)
			{
				if(pkNode->akChildren[word[i]-'a'] == NULL)
				{
					pkNode->akChildren[word[i]-'a'] = new Node();
				}
				pkNode = pkNode->akChildren[word[i] - 'a'];
			}
			pkNode->iEnd = iIndex;
			pkNode->s = word;
		}
	}

	void DFSWord(Node*pkNode,string checkword,bool bRevert,int& iMaxTimes)
	{
		if(pkNode == NULL)
		{
			return ;
		}
		if(pkNode->iEnd >= 0 )
		{
			int iSize = checkword.size();
			int iIndex = (pkNode->s.size()- checkword.size() >=0) ? (pkNode->s.size()- checkword.size()) : 0;
			if(bRevert)
			{
				iIndex = 0;
			}
			if(pkNode->s.substr(iIndex,iSize) == checkword)
			{
				if(pkNode->iEnd > iMaxTimes)
				{
					iMaxTimes = pkNode->iEnd;
				}
			}
		}

		for(int i = 0;i < 26;i++)
		{
			if(pkNode->akChildren[i])
			{
				DFSWord(pkNode->akChildren[i],checkword,bRevert,iMaxTimes);
			}
		}
	}
	WordFilter(vector<string>& words)
	{
		m_pkPreRoot = NULL;
		m_pkSufRoot = NULL;
		m_iSize = 0;
		for(int i = 0;i  < words.size();i++)
		{
			AddWord(words[i],i);
		}
		m_iSize = words.size() -1;
	}

	int f(string prefix, string suffix)
	{
		if(prefix == "" && suffix == "")
		{
			return m_iSize;
		}

		int iMax = -1;

		if(prefix.size() >= suffix.size())
		{

			Node* pkNode = m_pkPreRoot;
			for(int i = 0; i <prefix.size();i++)
			{
				if(pkNode->akChildren[prefix[i] - 'a'])
				{
					pkNode = pkNode->akChildren[prefix[i]-'a'];
				}
				else
				{
					return iMax;
				}
			}
			DFSWord(pkNode,suffix,false,iMax);
		}
		else
		{
			std::reverse(suffix.begin(),suffix.end());
			Node* pkNode = m_pkSufRoot;
			for(int i = 0; i <suffix.size();i++)
			{
				if(pkNode->akChildren[suffix[i] - 'a'])
				{
					pkNode = pkNode->akChildren[suffix[i]-'a'];
				}
				else
				{
					return iMax;
				}
			}
			DFSWord(pkNode,prefix,true,iMax);
		}
		return iMax;
	}
private:
	Node* m_pkPreRoot;
	Node* m_pkSufRoot;
	int m_iSize;
};


int main(int argc, char **argv)
{
	vector<string>kVec;
	//char* p[] = {"rac","rs","ra","on","r","otif","o","onpdusfsw","rsf","rs","ot","oti","racy","onpd"};
	//for(int i = 0; i < 14;i++)
	//{
	//	kVec.push_back(p[i]);
	//}
	kVec.push_back("apple");
	WordFilter ks(kVec);
	int iREt = ks.f("a","e");
	return 0;
}
