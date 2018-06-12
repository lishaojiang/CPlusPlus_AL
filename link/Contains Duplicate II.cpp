class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
       bool bRet = false;
       map<int,int> akMap;
       if(nums.size() <= 1) return false;
       akMap[nums[0]] = 0;
       int iDis = INT_MAX;
       for(int i =1;i < nums.size();i++)
       {
           if(akMap.find(nums[i]) != akMap.end())
           {
               if((i -akMap[nums[i]]) < iDis) 
               {
                   iDis = i -akMap[nums[i]];
               }
           }
           akMap[nums[i]] = i;
       }
       return iDis <= k;
    }
};