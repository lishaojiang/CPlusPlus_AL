class Solution 
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        vector<string> kResult;
        map<string,int> kMap;
        int iSum = list1.size() + list2.size();
        for(int i = 0; i < list2.size();i++)
        {
            kMap[list2[i]] = i;
        }
        for(int i = 0; i < list1.size();i++)
        {
            map<string,int>::iterator iter = kMap.find(list1[i]);
            if(iter != kMap.end())
            {
                if((i + iter->second) <= iSum)
                {
                    if((i + iter->second) == iSum)
                    {
                        kResult.clear();
                        iSum = i + iter->second;
                    }
                    kResult.push_back(list1[i]);
                }
            }
        }
        return kResult;
    }
};