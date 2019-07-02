#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

// this is very similar with Implement Trie.cpp,we just need change a little

struct TrieNode
{
    TrieNode ()
    {
        c = 0;
        e = 0;
        akChildren.clear();
    }

    char c;
    int e; // if e is one end node,the value is e  > 0
    vector<TrieNode*> akChildren;
};

class MapSum 
{
public:
    /** Initialize your data structure here. */
    MapSum() 
    {
        m_pkRootNode = new TrieNode();
    }

    void insert(string key, int val) 
    {
        TrieNode* pkNode = m_pkRootNode;
        int i = 0;
        bool bFindPrefNode = false;
        while(pkNode)
        {
            // compare its children
            bFindPrefNode = false;
            for(int j = 0; j < pkNode->akChildren.size(); j++)
            {
                if(pkNode->akChildren[j]->c == key[i])
                {
                    // there have one same, we should all from this
                    pkNode = pkNode->akChildren[j];
                    i++;
                    bFindPrefNode = true;
                    if(i == key.length())
                    {
                        pkNode->e = val;
                        return;
                    }
                    break;
                }
            }
            if(!bFindPrefNode)
            {
                while(i < key.length())
                {
                    TrieNode* pkNewNode = new TrieNode;
                    pkNewNode->c = key[i++];
                    pkNode->akChildren.push_back(pkNewNode);
                    pkNode = pkNewNode;
                }
                // we have add the node
                pkNode->e = val;
                return;
            }          
        }       
    }
        
    /** Returns if there is any word in the trie that starts with the given prefix. */
    int sum(string prefix) 
    {
        TrieNode* pkNode = m_pkRootNode;
        int i = 0;
        int iSum = 0;
        bool bFindPrefNode = false;
        while(pkNode)
        {
            // compare its children
            bFindPrefNode = false;
            for(int j = 0; j < pkNode->akChildren.size(); j++)
            {
                if(pkNode->akChildren[j]->c == prefix[i])
                {
                    // there have one same, we should all from this
                    pkNode = pkNode->akChildren[j];
                    i++;
                    bFindPrefNode = true;
                    if(i == prefix.length())
                    {
                        // from this node on,we need aclc all the node value
                        stack<TrieNode*> kStack;
                        kStack.push(pkNode);
                        while(!kStack.empty())
                        {
                            pkNode = kStack.top();
                            kStack.pop();
                            iSum += pkNode->e;
                            for(int m = 0;m < pkNode->akChildren.size(); m++)
                            {
                                kStack.push(pkNode->akChildren[m]);
                            }
                        }
                        return iSum;
                    }
                    break;
                }
            }
            if(!bFindPrefNode)
            {
                return 0;
            }          
        }
        return 0;
    }
private:
    TrieNode* m_pkRootNode;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



int main(int iNums,const char* pcGracStr[])
{
    // Trie* obj = new Trie();
    // obj->insert("apple");
    // bool param_1 = obj->search("apple");
    // bool param_2 = obj->search("app");
    // bool param_3 = obj->startsWith("app");
    return 0;
}