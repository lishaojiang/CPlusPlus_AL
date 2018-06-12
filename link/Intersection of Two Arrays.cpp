class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> akRet;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i = 0,j = 0;i < nums1.size() && j < nums2.size();)
        {
            while(i +1 < nums1.size())
            {
                if(nums1[i] != nums1[i+1]) break;
                i++;
            }
            while(j +1 < nums2.size())
            {
                if(nums2[j] != nums2[j+1]) break;
                j++;
            }
            if(nums1[i] == nums2[j])
            {
                akRet.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return akRet;
    }
};