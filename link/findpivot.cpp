auto io_speed_up =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution 
{
public:
    int pivotIndex(vector<int>& nums) 
    {
        if(nums.size() <= 2)
        {
            return -1;
        }
        int iSumLeft  = 0;
        int iSumRight =0;
        for(int i = 1; i < nums.size();i++)
        {
            iSumRight += nums[i];
        }
        for(int i = 0;i <nums.size();i++)
        {
            if(iSumLeft == iSumRight)
            {
                return i;
            }
            else
            {
                iSumLeft = iSumLeft+nums[i];
                iSumRight = iSumRight - nums[i+1];
            }
        }
        return -1;
    }
};