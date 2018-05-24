#include "stdio.h"
struct ListNode
{
    int iVal;
    ListNode* pkNext;
};

ListNode* CreateList(int iMax)
{
    ListNode* pkRet = NULL;
    ListNode* pBefore = NULL;
    for(int i = 0; i < iMax; i++)
    {
        ListNode* pkNode = new ListNode();
        if(pkRet == NULL)
        {
            pkRet = pkNode;
        }
        if(pkBefore)
        {
            pkBefore->pkNext = pkNode;
        }
        pkNode->iVal = i;
        pkNode->pkNext = NULL;
        pkBefore = pkNode;
    }
    return pkRet;
}

void PrintfList(ListNode* L)
{
    while(L)
    {
        printf("%d   ",L->iVal);
        L = L->pkNext;
    }
}

void DeleteOneNodeQuick(ListNode* L,ListNode* pDeleteNode)
{
    if(pDeleteNode == NULL)
    {
        return ;
    }

    if(pDeleteNode->pkNext == NULL)
    {
        delete pDeleteNode;
        pDeleteNode = NULL;
    }

    // change memory
    ListNode* pNextNode = pDeleteNode->pNextNode;
    pDeleteNode->iVal = pNextNode->iVal;
    pDeleteNode->pkNext = pNextNode->pkNext;
    delete pNextNode;
    pNextNode = NULL;

}


ListNode* DeleteListByVal(ListNode* L,int iVal)
{
    ListNode* pCheck = L;
    ListNode* pRet = NULL;
    while(L)
    {
        if(L->iVal == iVal)
        {
            if(L->pkNext && L->pkNext->iVal == iVal)
            {

            }
            else
            {
                pCheck->pkNext = L->pkNext;
            }
        }
        else
        {
            if(pkRet == NULL)
            {
                pkRet = L;
            }
            pCheck = L;
        }
    }
}

void main()
{
    ListNode* L = CreateList(50);
    PrintfList(L);
    L= DeleteListByVal(L,30);
    PrintfList(L);
    system("pause");
}



// hex to ascii
    char GetCharString(int i)
    {
        if(i >= 0 && i <= 9)
        {
            return ('0' + i);
        }
        if(i >= 10 && i < 16)
        {
            retrun ('A' + i - 10);
        }
        return '?';
    }
    string hexConversion(int n, int k) 
    {
        // write your code here
        string kRet = "";
        int iA = n / k;
        int iB = n%k;
        char array[33] = {0};
        int iCount = 0;
        array[iCount] = GetCharString(iB);
        while( iA != 0)
        {
            iB = iA%k;
            iA = iA / k;
            iCount++;
            array[iCount] = GetCharString(iB);
        }
        // 逆序一下字符
        for(int i = 0; i < ((iCount + 1) /2);i++)
        {
            char cTemp = array[i];
            array[i] = array[iCount -i];
            array[iCount - 1] = cTemp;
        }
        kRet = array;

        return kRet;
    }

    class Rectangle
    {
        public:
        Rectangle(int iWidth,int iHeight)
        {
            m_iHeight = iHeight;
            m_iWidth = iWidth;
        }

        inline int getArea()
        {
            return m_iWidth * m_iHeight;
        }

        private:
        int m_iWidth;
        int m_iHeight;
        
    }

    /**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution 
{
public:
    /*
     * @param root: the root of tree
     * @return: the max node
     */
    TreeNode * maxNode(TreeNode * root)
     {
        // write your code here
        m_iMax = 0x80000000;
        vistTreeNode(root);
        return m_pkMaxNode;
    }

    void vistTreeNode(TreeNode* root)
    {
        if(root != NULL)
        {
            if(root->val > m_iMax )
            {
                m_pkMaxNode = root;
                m_iMax = root->val;
            }
            vistTreeNode(root->left);
            vistTreeNode(root->right);
        }
    }
private:
    int m_iMax;
    TreeNode* m_pkMaxNode;
};

class Solution
 {
public:
     struct OnePair
     {
         int iIndex;
         int iValue;
     };
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<OnePair> kBigVec;
        vector<OnePair> kSmallVec;
        for(int i = 0; i < nums.size();i++)
        {

        }
    }
};

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // vector<int> kRet;
        // for(int i = 0; i < nums.size();i++)
        // {
        //     for(int j = i+1; j < nums.size();j++)
        //     {
        //         if(nums[i] + nums[j] == target)
        //         {
        //             kRet.push_back(i);
        //             kRet.push_back(j);
        //             return kRet;
        //         }
        //     }
        // }
        // return kRet;
        vector<int> kRet;
        map<int,int> VecToMap;
        for(int i = 0; i < nums.size();i++)
        {
           int  iValue =nums[i];
           std::map<int,int>::iterator iter = VecToMap.find(target-iValue);
           if(iter != VecToMap.end())
           {
                kRet.push_back(iter->second);
                kRet.push_back(i);
                return kRet;
           }
           else
           {
               VecToMap.insert(make_pair(iValue,i));
           }
        }
        return kRet;
    }

    static int x = []() 
    { 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
    }();

    int reverse(int x)
    {
        long  iOutput = 0;
        int iCount = 0;
        int iArray[10]= {0};
        bool bSmallThanZero = false;
        if(x < 0)
        {
            x = -x;
            bSmallThanZero = true;
        }

        while(x != 0)
        {
            iArray[iCount++] = x % 10;
            x = x / 10;
        }
        

        for(int i= 0; i < iCount;i++)
        {
            iOutput += (iArray[i] * pow(10,iCount-1-i));
        }

        // big check
        int iRet = 0;
        if(iOutput <= 0x7FFFFFFF)
        {
            iRet = iOutput;
        }


        if(bSmallThanZero)
        {
            iRet = -iRet;
        }
        return iRet;        
    }