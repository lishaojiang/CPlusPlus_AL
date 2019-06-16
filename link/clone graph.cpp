#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<deque>

using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
// function I,DFS,test well
    Node* CopyVisit(Node* node,map<Node*,Node*>& kMap)
    {
        Node* pkNewNode = NULL;
        if(node)
        {
            // if one node has visited,we will return it direct
            map<Node*,Node*>::iterator iter = kMap.find(node);
            if(iter != kMap.end())
            {
                return iter->second;
            }
            pkNewNode = new Node();
            pkNewNode->val = node->val;

            kMap[node] = pkNewNode;

            //deal its neighbors
            for(int i = 0; i < node->neighbors.size();i++)
            {
                Node* pkChildNode = CopyVisit(node->neighbors[i],kMap);
                pkNewNode->neighbors.push_back(pkChildNode);
            }
        }
        return pkNewNode;
    }

// funciton II,BFS test well
     Node* CopyVisit_BFS(Node* node,map<Node*,Node*>& kMap)
    {
        Node* pkNewNode = NULL;
        Node* pkRetNode = NULL;
        deque<Node*> kDeque;
        if(node)
        {
            kDeque.push_back(node);
            pkNewNode = new Node();
            pkRetNode = pkNewNode;
            pkNewNode->val = node->val;
            kMap[node] = pkNewNode;
            while(!kDeque.empty())
            {
                node = kDeque.front();
                pkNewNode = kMap[node];
                kDeque.pop_front();
                for(int i = 0;i < node->neighbors.size();i++)
                {
                    Node* pkChildNode = node->neighbors[i];
                    map<Node*,Node*>::iterator iterF = kMap.find(pkChildNode);
                    if(iterF != kMap.end())
                    {
                        pkNewNode->neighbors.push_back(iterF->second);
                    }
                    else
                    {       
                        kDeque.push_back(pkChildNode);
                        Node* pkNewChildNode = new Node();
                        pkNewChildNode->val = pkChildNode->val;
                        kMap[pkChildNode] = pkNewChildNode;
                        // parent must add child node
                        pkNewNode->neighbors.push_back(pkNewChildNode);   
                    }
                }

            }
        }
        return pkRetNode;
    }

    Node* cloneGraph(Node* node) 
    {
        Node* pkRoot = NULL;
        stack<Node*> kNodeStack;
        map<Node*,Node*> kNodeMap;

        pkRoot = CopyVisit(node,kNodeMap);

        return pkRoot;
    }
};