#include<iostream>
#include<vector>
#include<map>


using namespace std;


// solution not use graph,the other use graph

class SolutionSimple {
public:
    int findJudge(int N, vector<vector<int> >& trust) 
    {
        if(N== 1 && trust.empty())
        {
            return 1;
        }
        map<int,int> kAllBelieveOne;
        map<int,int> kOneBelieveOthers;
        vector<int> kCheckVec;
        for(int i = 0; i< trust.size();i++)
        {
            vector<int> kOne = trust[i];
            map<int,int>::iterator iterA = kAllBelieveOne.find(kOne[1]);
            if(iterA != kAllBelieveOne.end())
            {
                iterA->second++;
                if(iterA->second == N -1)
                {
                    kCheckVec.push_back(iterA->first);
                }
            }
            else
            {
                kAllBelieveOne[kOne[1]] = 1;
                
                if( N == 2)
                {
                    kCheckVec.push_back(kOne[1]);
                }
            }
            
            kOneBelieveOthers[kOne[0]] = 1;    
        }
        
        for(int i = 0;i < kCheckVec.size();i++)
        {
            map<int,int>::iterator iterA = kAllBelieveOne.find(kCheckVec[i]);
            if(iterA != kAllBelieveOne.end() && iterA->second == N-1)
            {
                if(kOneBelieveOthers.find(kCheckVec[i]) == kOneBelieveOthers.end())
                {
                    return iterA->first;
                }
            }
        }
        return -1;
    }
};

// this is use graph way,the is past
class SolutionGraph
{
public:
    struct Node
    {
        Node(int _Index)
        {
            iIndex = _Index;
            bRead = false;
            akChildren.clear();
        }
        int iIndex;
        bool bRead;
        vector<Node*> akChildren;
    };
    
    bool DFS_Check(Node* pkNode)
    {
        if(pkNode && pkNode->bRead)
        {
            return true;
        }
        if(pkNode && pkNode->bRead == false)
        {
            pkNode->bRead = true;
            bool bCircle = false;
            for(int i = 0; i < pkNode->akChildren.size();i++)
            {
                if(DFS_Check(pkNode->akChildren[i]))
                {
                    bCircle = true;
                    break;
                }
            }
            pkNode->bRead = false;
            if(bCircle)
            {
                return true;
            }
        }
        return false;
    }
    
    bool CheckNode(Node* pkNode,Node* pkCheckNode)
    {
        for(int i = 0; i < pkNode->akChildren.size();i++)
        {
            if(pkNode->akChildren[i] == pkCheckNode)
            {
                return true;
            }
        }
        return false;
    }
    
    
    int findJudge(int N, vector<vector<int> >& trust)
    {
        map<int,Node*> kGraph;
        if(N== 1 && trust.empty())
        {
            return 1;
        }
        
        // make graph nodes and path
        for(int i = 0; i <trust.size();i++)
        {
            map<int,Node*>::iterator iterP = kGraph.find(trust[i][0]);
            if(iterP == kGraph.end())
            {
                kGraph[trust[i][0]] = new Node(trust[i][0]);
            }
            map<int,Node*>::iterator iterC = kGraph.find(trust[i][1]);
            if(iterC == kGraph.end())
            {
                kGraph[trust[i][1]] = new Node(trust[i][1]);
            }
            kGraph[trust[i][1]]->akChildren.push_back(kGraph[trust[i][0]]);
        }
        
        // check is there are circle
        bool bRead = false;
        for(map<int,Node*>::iterator iter = kGraph.begin();iter != kGraph.end();iter++)
        {
            if(iter->second->akChildren.size() == N-1)
            {
                //if( !DFS_Check(iter->second))
                //    return iter->first;
                bool bcircle = false;
                for(map<int,Node*>::iterator iterA = kGraph.begin();iterA != kGraph.end();iterA++)
                {
                    if(CheckNode(iterA->second,iter->second))
                    {
                        bcircle =true;
                        break;
                    }
                }
                if(!bcircle)
                    return iter->first;
            }
        }
        return -1;
    }
};


// graph in out degree,it test fast and use less memory
class Solution {
public:
    int findJudge(int N, vector<vector<int> >& trust) 
    {
        vector<int> In(N,0);
        vector<int> Out(N,0);
    
        for(int i = 0; i< trust.size();i++)
        {
            In[trust[i][0]-1]++;
            Out[trust[i][1]-1]++; 
        }
        
        for(int i = 0;i < N;i++)
        {
            if(Out[i] == N-1 && In[i] == 0)
            {
                return i+1;
            }
        }
        return -1;
    }
};

int main(int,char**)
{
    Solution ks;
    //[[1,2],[3,2],[1,3],[4,1],[3,1],[2,1],[2,3],[4,3],[4,2],[3,4],[2,4]]
    vector<vector<int> > kVec;//={{1,2},{3,2},{4,2},{2,3}};
    vector<int> a;a.push_back(1);a.push_back(2);
    vector<int> b;b.push_back(3);b.push_back(2);
    vector<int> c;c.push_back(1);c.push_back(3);
    vector<int> d;d.push_back(4);d.push_back(1);
    vector<int> e;e.push_back(3);e.push_back(1);
    vector<int> f;f.push_back(2);f.push_back(1);
    vector<int> g;g.push_back(2);g.push_back(3);
    vector<int> h;h.push_back(4);h.push_back(3);
    vector<int> i;i.push_back(4);i.push_back(2);
    vector<int> j;j.push_back(3);j.push_back(4);
    vector<int> k;k.push_back(4);k.push_back(4);
    kVec.push_back(a);kVec.push_back(b);
    kVec.push_back(c);kVec.push_back(d);
    kVec.push_back(e);kVec.push_back(f);
    kVec.push_back(g);kVec.push_back(h);
    kVec.push_back(i);kVec.push_back(j);
    kVec.push_back(k);

    int iRet = ks.findJudge(4,kVec);
    return 0;
}
