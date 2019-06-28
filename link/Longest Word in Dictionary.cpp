#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

class Solution 
{
public:
	struct Node
	{
		Node()
		{
			memset(akChildren,0,sizeof(akChildren));
			iEnd = 0;
		}
		Node* akChildren[26];
		string kStr;
		int iEnd;
	};

	void AddWord(string word)
	{
		if(m_pkRoot == NULL)
		{
			m_pkRoot = new Node();
		}
		Node* pkNode = m_pkRoot;
		for(int i = 0; i < word.length(); i++)
		{
			if(pkNode->akChildren[word[i]-'a'] == NULL)
			{
				pkNode->akChildren[word[i]-'a'] = new Node();
			}
			pkNode = pkNode->akChildren[word[i] - 'a'];
		}
		pkNode->iEnd = 1;
		pkNode->kStr = word;
	}

	void DFSLongsetWord(Node*pkNode,int iTimes,int& iMaxTimes,string& word)
	{
		if(pkNode == NULL)
		{
			return ;
		}
		if(pkNode->iEnd > 0)
		{
			iTimes++;
			if(iTimes > iMaxTimes)
			{
				word = pkNode->kStr;
				iMaxTimes = iTimes;
			}
		}

		for(int i = 0;i < 26;i++)
		{
			if(pkNode->akChildren[i] && pkNode->akChildren[i]->iEnd >0)
			{
				DFSLongsetWord(pkNode->akChildren[i],iTimes,iMaxTimes,word);
			}
		}
	}
	// it's my first funciton,test success
	string longestWordByTree(vector<string>& words) 
	{
		m_pkRoot = NULL;
		for(int i = 0; i <words.size();i++)
		{
			AddWord(words[i]);
		}
		int iMaxTimes = 0;
		string word = "";
		DFSLongsetWord(m_pkRoot,0,iMaxTimes,word);
		return word;
	}

	// it't my second functon,test success
	string longestWord(vector<string>& words) 
	{
		std::sort(words.begin(),words.end());
		set<string> kSet;
		kSet.insert("");
		string s,pre;
		string word;
		int iMaxTimes = 0;
		for(int i = 0; i <words.size();i++)
		{
			s = words[i];
			int isize = s.size();
			if(kSet.find(s.substr(0,isize-1)) != kSet.end())
			{
				if(isize > iMaxTimes)
				{
					word = s;
					iMaxTimes = isize;
				}
				kSet.insert(s);
			}
		}
		return word;
	}

	// it 's by the internet,test success
	string longestWordByNet(vector<string>& words) {
		string best, prefix;
		sort(words.begin(), words.end());
		for (string w: words) {
			int sz = w.size();
			if (w.substr(0, sz - 1) == prefix.substr(0, sz - 1)) {
				prefix = w;
				if (sz > best.size()) best = w;
			}
		}
		return best;
	}

private:
	Node* m_pkRoot;
};


int main(int argc, char **argv)
{
	Solution ks;
	vector<string>kVec;
	//kVec.push_back("a");
	//kVec.push_back("bata");
	//kVec.push_back("ad");
	//kVec.push_back("batas");
	//kVec.push_back("adc");
	char* p[] = {"rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd"};
	for(int i = 0; i < 14;i++)
	{
		kVec.push_back(p[i]);
	}
	string s = ks.longestWord(kVec);
	return 0;
}
