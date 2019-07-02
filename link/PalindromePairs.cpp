#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;


// it is a hard problem for me,i can't do it by myself.but i can do it nearly!
// the most import idea to solove this question is that:

// string A,string B, if A+B or B+A is palindrome, it is right to us.
// you can reverse any A or B, for example,A reverse is A',
// then compare A'[i] == B[i],if it's not ,it is wrong
// then the longer words left ,must be palidrome
// if you can know this,you can do it


// one way: you can do this compare directly by some STL struct

// the other way:use trie tree, i use this,it's a little slowly
// make all the words reverse into a trie tree.
// compare all the word not reverse with reverse words,must compare it's it self.

// function I,it is right,but it's too slow.
/*class Solution 
{
public:
    vector<vector<int> > palindromePairs(vector<string>& words) 
    {
        vector<vector<int> > kOut;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i+1; j < words.size();j++)
            {
                vector<int> a;
                string s = words[i]+words[j];
                if(IsRight(s))
                {
                    a.push_back(i);
                    a.push_back(j);
                    kOut.push_back(a);
                }
                s = words[j]+words[i];
                if(IsRight(s))
                {
                    a.clear();
                    a.push_back(j);
                    a.push_back(i);
                    kOut.push_back(a);
                }
            }
        }
        return kOut;
    }

    bool IsRight(string word)
    {
        map<string,bool>::iterator iter = m_kMap.find(word);
        if(iter != m_kMap.end())
        {
            return iter->second;
        }

        int iLength = word.length();
        bool bRight = true;
        for(int i = 0; i < iLength / 2; i++)
        {
            if(word[i] != word[iLength - 1 - i])
            {
                bRight = false;
                break;
            }
        }
        m_kMap[word] = bRight;
        return bRight;
    }

private:
    map<string,bool> m_kMap;
};
*/


// as i see some answer,i need revesrt the word then put into the trie tree.
class Solution 
{
public:
    struct TrieNode
	{
		TrieNode()
		{
			memset(kChildren, 0, sizeof(TrieNode*) * 26);
			//kEndVec.clear();
            iEndIndex=-1;
		};

		TrieNode* kChildren[26];
        //vector<int> kEndVec;
        int iEndIndex;
	};

	void TrieAddWord(string kWord,int iIndex)
	{
		if (kWord == "")
		{
			return;
		}
		if (m_pkTrieRoot == NULL)
		{
			m_pkTrieRoot = new TrieNode();
		}

		TrieNode* pkParent = m_pkTrieRoot;
		for (int j = kWord.length() -1; j >= 0; j--)
		{
			TrieNode* pkNode = NULL;
			if (pkParent->kChildren[kWord[j] - 'a'] == NULL)
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
		//pkParent->kEndVec.push_back(iIndex);
        pkParent->iEndIndex = iIndex;
	}

	void MakeUpTrieTree(vector<string>& words)
	{
        for(int i = 0; i < words.size();i++)
        {
            TrieAddWord(words[i],i);
        }
	}

    bool IsRight(string word)
    {
        int iLength = word.length();
        bool bRight = true;
        for(int i = 0; i < iLength / 2; i++)
        {
            if(word[i] != word[iLength - 1 - i])
            {
                bRight = false;
                break;
            }
        }
        return bRight;
    }

    void DFS_Extend(TrieNode* pkNode,string s,int iIndex,vector<vector<int> >& kOut)
    {
        for(int i = 0; i < 26;i++)
        {
            if(pkNode->kChildren[i] != NULL)
            {
                //s+= ('a' + i);
                string s1 = s;
                s1+= ('a'+i);
                if(pkNode->kChildren[i]->iEndIndex >= 0 && pkNode->kChildren[i]->iEndIndex != iIndex)
                {
                    // we should check this node
                    if(IsRight(s1))
                    {
                        vector<int> a;
                        a.push_back(iIndex);
                        a.push_back(pkNode->kChildren[i]->iEndIndex);
                        kOut.push_back(a);
                    }
                }
                DFS_Extend(pkNode->kChildren[i],s1,iIndex,kOut);
            }
        }
    }

    bool CheckOneString(string s,int iIndex,vector<vector<int> >& kOut)
    {
        //if(s.empty())
        if(m_pkTrieRoot == NULL)
        {
            return false;
        }

        int i = 0;
        TrieNode* pkNode = m_pkTrieRoot;
        while(i < s.length())
        {
            if(pkNode->kChildren[s[i]-'a']== NULL)
            {
                return false;
            }
            pkNode = pkNode->kChildren[s[i] - 'a'];
            i++;
            if(i == s.length())
            {
                // we should DFS the other node
                if(pkNode->iEndIndex >= 0 && pkNode->iEndIndex != iIndex)
                {
                    vector<int> a;
                    a.push_back(iIndex);
                    a.push_back(pkNode->iEndIndex);
                    kOut.push_back(a);
                }

                // maybe this have other words extend
                DFS_Extend(pkNode,"",iIndex,kOut);
            }
            else
            {
                if(pkNode->iEndIndex >= 0 && pkNode->iEndIndex != iIndex)
                {
                    // one end, we sholud check it is ture or not
                    string s1 = string(s,i,s.length()-i);
                    if(IsRight(s1))
                    {
                        vector<int> a;
                        a.push_back(iIndex);
                        a.push_back(pkNode->iEndIndex);
                        kOut.push_back(a);
                    }       
                }            
            }            
        }

        return true;
    }
public:
    vector<vector<int> > palindromePairs(vector<string>& words) 
    {
        vector<vector<int> > kOut;
        MakeUpTrieTree(words);

        for(int i = 0; i < words.size();i++)
        {
            if(words[i].empty())
            {
                for(int j = 0; j < words.size();j++)
                {
                    if(i != j && IsRight(words[j]))
                    {
                        vector<int> a;
                        a.push_back(i);
                        a.push_back(j);
                        kOut.push_back(a);
                        vector<int> b;
                        b.push_back(j);
                        b.push_back(i);
                        kOut.push_back(b);
                    }
                }
            }
            else
            {
                CheckOneString(words[i],i,kOut);
            }
            
        }
      
        return kOut;
    }

private:
    TrieNode* m_pkTrieRoot;
};


int main(int,const char* [])
{
    Solution kST;
    vector<string> ks;
    // const char* pcData[10] = {"bb","bababab","baab","abaabaa","aaba","","bbaa","aba","baa","b"};
    // for(int i = 0; i < 10; i++)
    // {
    //     ks.push_back(pcData[i]);
    // }
    //ks.push_back("bb");
    //ks.push_back("b");
    //ks.push_back("lls");
    //ks.push_back("s");
    //ks.push_back("sssll");

    vector<vector<int> > kOut;
    kOut = kST.palindromePairs(ks);
    int i = 3;
    return 0;
}