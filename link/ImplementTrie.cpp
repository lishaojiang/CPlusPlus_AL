#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TrieNode
{
    TrieNode ()
    {
        c = 0;
        e = 0;
        akChildren.clear();
    }

    char c;
    char e; // if e is one end node,the value is e  > 0
    vector<TrieNode*> akChildren;
};

// // this is can use char
// struct TrieNode
// {
//     TrieNode ()
//     {
//         e = 0;
//         memset(akChildren,0,sizeof(acChildren));
//     }

//     char e; // if e is one end node,the value is e  > 0
//     TrieNode* akChildren[26];
// };

class Trie 
{
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        m_pkRootNode = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
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
                if(pkNode->akChildren[j]->c == word[i])
                {
                    // there have one same, we should all from this
                    pkNode = pkNode->akChildren[j];
                    i++;
                    bFindPrefNode = true;
                    if(i == word.length())
                    {
                        pkNode->e = 1;
                        return;
                    }
                    break;
                }
            }
            if(!bFindPrefNode)
            {
                while(i < word.length())
                {
                    TrieNode* pkNewNode = new TrieNode;
                    pkNewNode->c = word[i++];
                    pkNode->akChildren.push_back(pkNewNode);
                    pkNode = pkNewNode;
                }
                // we have add the node
                pkNode->e = 1;
                return;
            }          
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
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
                if(pkNode->akChildren[j]->c == word[i])
                {
                    // there have one same, we should all from this
                    pkNode = pkNode->akChildren[j];
                    i++;
                    bFindPrefNode = true;
                    if(i == word.length())
                    {
                        // we should check 
                        if(pkNode->e > 0)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                        
                    }
                    break;
                }
            }
            if(!bFindPrefNode)
            {
                return false;
            }          
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
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
                if(pkNode->akChildren[j]->c == prefix[i])
                {
                    // there have one same, we should all from this
                    pkNode = pkNode->akChildren[j];
                    i++;
                    bFindPrefNode = true;
                    if(i == prefix.length())
                    {
                        return true;
                    }
                    break;
                }
            }
            if(!bFindPrefNode)
            {
                return false;
            }          
        }
        return false;
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
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_1 = obj->search("apple");
    bool param_2 = obj->search("app");
    bool param_3 = obj->startsWith("app");
    return 0;
}