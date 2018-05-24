class Solution
 {
public:
    struct VectorLess
    {
        bool operator()(const vector<int>& rkLeft,const vector<int>& rkRight)
        {
            return rkLeft[0] < rkRight[0];
        }
    };

    int  FindLeftNumIndex(vector<vector<int>>& kVec,int iCheck)
    {
        int iRet = -1;
        int iSize = kVec.size();
        int iIndex = 0;
        int iTime = iSize;
        while(iIndex >=0 && iIndex < iSize)
        {
             iTime = iSize / 2;
            if(kVec[iIndex][0] < iCheck)
            {
                if((iIndex +1) >= iSize)
                {
                    return -1;
                }
              else  if(kVec[iIndex +1][0] > iCheck)
               {
                    return -1;
               }
              else  if(kVec[iIndex +1][0] == iCheck)
               {
                    return (iIndex +1);
               }
               else
               {
                    iIndex = iIndex + iTime < 1 ? 1 : iTime;
               }
            }
            else
            {
                iIndex = iIndex -  iTime < 1 ? 1 : iTime;
            }
        }
        return iRet;
    }

    int FindRightNumIndex(vector<vector<int>>& kVec,int iCheck)
    {
        int iRet = -1;
        int iSize = kVec.size();
        int iIndex = iSize-1;
        int iTime = iSize;
        while(iIndex >=0 && iIndex < iSize)
        {
             iTime = iSize / 2;
            if(kVec[iIndex][0] > iCheck)
            {
                if((iIndex -1) < 0)
                {
                    return -1;
                }
              else  if(kVec[iIndex -1][0] < iCheck)
               {
                    return -1;
               }
              else  if(kVec[iIndex -1][0] == iCheck)
               {
                    return iIndex ;
               }
               else
               {
                    iIndex = iIndex - iTime < 1 ? 1 : iTime;
               }
            }
            else
            {
                iIndex = iIndex +  iTime < 1 ? 1 : iTime;
            }
        }
        return iRet;
    }
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        map<int,int> kMapTable;
        map<int,int> kCheckTable;
        vector<vector<int>> kRetVec;
        int iNumSize = nums.size();
        // 先构造表
        for(int i =0; i < iNumSize;i++)
        {
            if(kMapTable.find(nums[i]) != kMapTable.end())
            {
                    kMapTable[nums[i]] = ++kMapTable[nums[i]];
            }
            else
            {
                     kMapTable[nums[i]] = 1;
            }
        }
        for(int i = 0; i < iNumSize;i++)
        {
            // 保证自己是开头
            int iNumA = nums[i];
            int iTraget = -iNumA;
            for(int j = i+1; j <iNumSize;j++)
            {
                int iTraget = 0- nums[i] -nums[j];
                 map<int,int>::iterator iter = kMapTable.find(iTraget);
                 if(iter != kMapTable.end())
                 {
                    // 查重一下
                    int iFind = iter->second;
                    if(iTraget == nums[i])
                    {
                        iFind--;
                    }
                    if(iTraget == nums[j])
                    {
                        iFind--;
                    }

                    if(iFind > 0)
                    {
                        // 真的存在,再进行一次查重
                        vector<int> kFindVec;
                        kFindVec.push_back(nums[i]);
                        kFindVec.push_back(nums[j]);
                        kFindVec.push_back(iTraget);
                        sort(kFindVec.begin(),kFindVec.end());

                        bool bFindRepeat = false;
                        {
                            int iLeft = FindLeftNumIndex(kRetVec,kFindVec[0]);
                            int iRight = FindRightNumIndex(kRetVec,kFindVec[0]);
                            for(int k = iLeft; k >=0 && k <=iRight;k++)
                            {
                                if(kRetVec[k][0] == kFindVec[0] && kRetVec[k][1] == kFindVec[1] && kRetVec[k][2] == kFindVec[2])
                                {
                                    bFindRepeat = true;
                                    break;
                                }
                            }
                        }
                        if(!bFindRepeat)
                        {
                             kRetVec.push_back(kFindVec);
                             sort(kRetVec.begin(),kRetVec.end(),VectorLess());
                        }
                    }
                 }
            }
        }

        return kRetVec;
    }
};