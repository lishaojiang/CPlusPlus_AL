#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int iLeft = 0;
        int iRight = nums.size() - 1;
        int iMiddle = iLeft;
        vector<int> kRet;
        

        if(nums.size() == 1 && target == nums[0])
        {
            kRet.push_back(0);
            kRet.push_back(0);
            return kRet;
        }
        kRet.push_back(-1);
        kRet.push_back(-1);
        if(iLeft >= iRight)
        {
            return kRet;
        }
        
        while(iLeft <= iRight)
        {
            iMiddle = (iLeft + iRight) / 2;
            if(nums[iMiddle] < target)
            {
                iLeft = iMiddle+1;
            }
            else if(nums[iMiddle] > target)
            {
                iRight = iMiddle-1;
            }
            else
            {
                int iFindLeft = iMiddle;
                int iFindRight = iMiddle;
                while(iFindLeft >=0)
                {
                    if(nums[iFindLeft] == target)
                    {
                        iFindLeft--;
                    }
                    else
                    {
                        break;
                    }
                }
                while(iFindRight < nums.size())
                {
                    if(nums[iFindRight] == target)
                    {
                        iFindRight++;
                    }
                    else
                    {
                        break;
                    }
                }
                kRet.clear();
                kRet.push_back(iFindLeft+1);
                kRet.push_back(iFindRight-1);
                break;
            }
        }

        return kRet;
        
        
    }
};

int main(int argc,const char* pcParam[])
{
    cout<< "hello wordl" << endl;
    Solution kS;
    vector<int> kVec;
    kVec.push_back(5);
    kVec.push_back(7);
    kVec.push_back(7);
    kVec.push_back(8);
    kVec.push_back(8);
    kVec.push_back(10);

    vector<int> kRet;
    kRet = kS.searchRange(kVec,8);

    cout << kRet[0] << "->" << kRet[1] << endl;
    return 0;
}