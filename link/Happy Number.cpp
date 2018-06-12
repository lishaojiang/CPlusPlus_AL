class Solution 
{
public:
    bool isHappy(int n) 
    {
        int icheck = n;
        set<int> akset;
        while(icheck != 1)
        {
            int isum = 0;
            while(icheck != 0)
            {
                isum += (icheck % 10) * (icheck % 10);
                icheck = icheck / 10;
            }
            if(isum == 1) return true;
            if(akset.find(isum) != akset.end())
            {
                return false;
            }
            akset.insert(isum);
            icheck = isum;
        }
        return true;
    }
};