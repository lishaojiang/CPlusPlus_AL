class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> akRet;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int ia = 0;
        int ib = 0;
        while(ia < nums1.size()  && ib < nums2.size())
        {
            if(nums1[ia] == nums2[ib])
            {
                akRet.push_back(nums1[ia]);
                ia++;
                ib++;
            }
            else if(nums1[ia] < nums2[ib])
            {
                ia++;
            }
            else 
            {
                ib++;
            }
        }
        return akRet;
    }
};