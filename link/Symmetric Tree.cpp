/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    void  CompareTwoTree(TreeNode* left,TreeNode* right,bool& bSame)
    {
        if(left && right && left->val == right->val)
        {
            CompareTwoTree(left->left,right->right,bSame);
            CompareTwoTree(left->right,right->left,bSame);
        }
        else
        {
            if(left == nullptr && right == nullptr)
            {
                return;
            }
            else
            {
                bSame = false;
                return;
            }
        }
    }
    bool isSymmetric(TreeNode* root) 
    {
        bool bRet = true;
        if(root == nullptr)
        {
            return bRet;
        }
        CompareTwoTree(root->left,root->right,bRet);
        return bRet;
    }
};