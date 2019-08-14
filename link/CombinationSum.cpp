#include<iostream>
#include<vector>

using namespace std;


// it has test success,but it is too slow
// I have change a little,it run
class Solution 
{
public:
    void DFS(vector<int>& candidates,int target,int iSum,int iIndex,vector<int> kOne,vector<vector<int> >& kRet)
    {
        if((iSum + candidates[iIndex]) < target)
        {
            kOne.push_back(candidates[iIndex]);
            iSum = iSum + candidates[iIndex];
            for(int i = 0; i < candidates.size();i++)
            {
                if((iSum + candidates[iIndex]) <= target)
                {
                    DFS(candidates,target,iSum,i,kOne,kRet);
                }
                else 
                {
                    break;
                }
                
            }
        }
        else if((iSum + candidates[iIndex]) == target)
        {
            kOne.push_back(candidates[iIndex]);
            vector<int> kTemp;
            kTemp = kOne;
            sort(kTemp.begin(),kTemp.end());
            // check if has already
            bool bFind = false;
            for(int j = 0; j < kRet.size();j++)
            {
                if(kRet[j].size() == kTemp.size())
                {
                    bool bAllSame = true;
                    for(int k = 0;k < kTemp.size();k++)
                    {
                        if(kTemp[k] != kRet[j][k])
                        {
                            bAllSame = false;
                            break;
                        }
                    }
                    if(bAllSame) 
                    {
                        bFind = true;
                        break;
                    }
                }
            }
            if(!bFind)
                kRet.push_back(kOne);
        }
        else
        {
            
        }
    }

    void DFS_Fast(vector<int>& candidates,int target,int iSum,int iIndex,vector<int> kOne,vector<vector<int> >& kRet)
    {

            kOne.push_back(candidates[iIndex]);
            iSum = iSum + candidates[iIndex];
            if(iSum == target)
            {
                kRet.push_back(kOne);
            }
            else
            {
                for(int i = iIndex; i < candidates.size();i++)
                {
                    if((iSum + candidates[i]) <= target)
                    {
                        DFS_Fast(candidates,target,iSum,i,kOne,kRet);
                    }
                    else 
                    {
                        break;
                    }    
                }                
            }    
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int> > kRet;
        vector<int> kOne;

        sort(candidates.begin(),candidates.end());

        
        for(int i = 0; i < candidates.size();i++)
        {
            int iSum = 0;
            kOne.clear();
            if((iSum + candidates[i]) <= target)
            {
                DFS(candidates,target,iSum,i,kOne,kRet);
            }
        }

        return kRet;
    }
};

int main(int,const char**)
{
    return 0;
}