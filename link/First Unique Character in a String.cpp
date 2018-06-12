class Solution {
public:
    int firstUniqChar(string s) 
    {
        int iRet = -1;
        unordered_map<char,int> kMap;
        vector<int> kVec;
        for(int i = 0; i < s.size();i++)
        {
            if(kMap.find(s[i]) != kMap.end())
            {
                
               for(vector<int>::iterator iter = kVec.begin(); iter != kVec.end();iter++)
               {
                   if(*iter == kMap[s[i]])
                   {
                       kVec.erase(iter);
                       break;
                   }
               }
            }
            
            else
            {
                kMap[s[i]] = i;
                kVec.push_back(i);
            }
            
        }

        if(kVec.size())
        {
            return kVec[0];
        }
        return iRet;
    }
};