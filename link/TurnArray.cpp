    void rotate(vector<int>& nums, int k) 
    {
        if(nums.size() <= 1)
        {
            return;
        }
        // function 1
        // int iSize = nums.size();
        // for(int i=0; i < k; i++)
        // {
        //     int pre = nums[iSize -1];
        //     for(int j = 0; j < nums.size();j++)
        //     {
        //         temp = nums[j];
        //         nums[j] = pre;
        //         pre = temp;
        //     }
        // } 

        // function 2 use  list to copy data

        // funciton 3 ,fast and use less space
        int iSize = nums.size();
        k = k % iSize;
        int iCount = 0;
        for(int i = 0; i <k && iCount < iSize;i++)
        {
            int iIndex = i;
            int iTemp = nums[iIndex];
            while(1)
            {
                int iPos = (iIndex + k ) % iSize;
                // change data
                int iA = iTemp;
                iTemp = nums[iPos];
                nums[iPos] = iA;
                iIndex = iPos;
                iCount++;
                if(iPos == i)
                {
                    break;
                }
            }
        }
    }


    class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
        
    }
};