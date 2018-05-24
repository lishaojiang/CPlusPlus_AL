auto io_speed_up =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int dominantIndex(vector<int>& nums) 
    {
        if(nums.size() ==1)
        {
            return 0;
        }
        int iIndexOne= 0;
        int iIndexSecond = -1;
        for(int i = 1; i < nums.size();i++)
        {
            if(nums[i] > nums[iIndexOne])
            {
                iIndexSecond = iIndexOne;
                iIndexOne = i;
            }
            else
            {
                if(iIndexSecond == -1)
                {
                     iIndexSecond = i;
                }
                else
                {
                    if(nums[i] > nums[iIndexSecond])
                    {
                        iIndexSecond = i;
                    }
                }
            }


        }

        if(nums[iIndexOne] > nums[iIndexSecond] && nums[iIndexOne] >= (nums[iIndexSecond] * 2))
        {
            return iIndexOne;
        }
        return -1;
    }
};