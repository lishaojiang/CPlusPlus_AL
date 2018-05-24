class Solution 
{
public:
    int ClacFun(int iIndex,int iRow)
    {
        if(iRow <= 0)
        {
            return 1;
        }
        if(iIndex > iRow)
        {
            // ilegle data number
            return 1;
        }
        if(iIndex == 0 || iIndex == iRow)
        {
            return 1;
        }
        return ClacFun(iIndex-1,iRow-1) + ClacFun(iIndex,iRow-1);
    }
    // function 1,over time
    // vector<int> getRow(int rowIndex) 
    // {
    //     vector<int> akRetVec(rowIndex+1) ;
    //     for(int i = 0; i <= rowIndex;i++)
    //     {
    //         akRetVec[i] = ClacFun(i,rowIndex);
    //     }
    //     return akRetVec;
    // }

    // function 2,use more space
    // vector<int> getRow(int rowIndex) 
    // {
    //     vector<int> akRetVec(rowIndex+1) ;
    //     if(rowIndex == 0)
    //     {
    //         akRetVec[0] = 1;
    //         return akRetVec;
    //     }
    //     vector<int> akTemp(rowIndex);
    //     akTemp[0] = 1;
    //     for(int i = 1; i <= rowIndex;i++)
    //     {
    //         for(int j = 0; j <=i;j++)
    //         {
    //             if(j ==0 || j == i)
    //             {
    //                 akRetVec[j] = 1;
    //             }
    //             else
    //             {
    //                 akRetVec[j] = akRetVec[j-1] + akRetVec[j];
    //             }
    //         }
    //     }
    //     return akRetVec;
    // }

    // function 3
    vector<int> getRow(int rowIndex) 
    {
        vector<int> akRetVec(rowIndex+1) ;
        if(rowIndex == 0)
        {
            akRetVec[0] = 1;
            return akRetVec;
        }
        vector<int> akTemp(rowIndex);
        akTemp[0] = 1;
        for(int i = 1; i <= rowIndex;i++)
        {
            for(int j = i; j >=0;j--)
            {
                if(j ==0 || j == i)
                {
                    akRetVec[j] = 1;
                }
                else
                {
                    akRetVec[j] = akRetVec[j] + akRetVec[j-1];
                }
            }
        }
        return akRetVec;
    }
};