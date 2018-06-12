// very stupid function

// class Solution 
// {
// public:
//     bool containsDuplicate(vector<int>& nums) 
//     {
//         if(nums.size() <= 1)
//         {
//             return false;
//         }
//         sort(nums.begin(),nums.end());
//         for(int i = 0;i < nums.size()-1;i++)
//         {
//             if(nums[i] == nums[i+1])
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };


// 正负号问题
// some smart funciton
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        if(nums.size() <= 1)
        {
            return false;
        }
        int iSize = nums.size();
        vector<vector<int>> akCheck(iSize);
        for(int i = 0;i < nums.size();i++)
        {
            int iTest = nums[i] < 0 ? -nums[i] % iSize : nums[i] % iSize;
            for(int j = 0; j < akCheck[iTest].size();j++)
            {
                if(akCheck[iTest][j] == nums[i])
                {
                    return true;
                }
            }
            akCheck[iTest].push_back(nums[i]);
        }
        return false;
    }
};