class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int iRet = 0;
        for(int i = 0; i < nums.size();i++)
        {
            iRet ^= nums[i];
        }
        return iRet;
    }
};