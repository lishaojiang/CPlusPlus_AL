auto io_speed_up =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int iTemp;
        int iIndex =0;
        int k = 0;
        for(int i = 0; i< nums.size();)
        {
            if(nums[i] == 0)
            { 
                int j = i+1;
                while(j < nums.size() && nums[j] == 0)
                {
                    j++;
                }
                if(j >= nums.size())
                {
                    break;
                }

                for(;j <nums.size() && nums[j] != 0;j++)
                {
                    nums[iIndex] = nums[j];
                    iIndex++;
                }
                if(j >= nums.size())
                {
                    break;
                }
                i = j;
            }
            else
            {
                iIndex++;
                i++;
            }
        }
        
        for(int i = iIndex;i < nums.size();i++)
        {
            nums[i] = 0;
        }
    }
};