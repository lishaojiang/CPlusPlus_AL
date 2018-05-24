auto io_speed_up =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        bool bAdd = true;
        for(int i = digits.size()-1; i >= 0;i--)
        {
            if(bAdd)
            {
                if(digits[i] >= 9)
                {
                    digits[i] = 0;
                    bAdd = true;
                }
                else
                {
                    digits[i]  = digits[i]+1;
                    bAdd = false;
                }
            }
            else
            {
                break;
            }
        }
        if(bAdd)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};