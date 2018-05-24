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
    bool BinTravCheckSum(TreeNode* root,int iCheck)
    {
        // 最后叶子节点，一条路径走完
        if(root && root->left == nullptr && root ->right== nullptr && iCheck == root->val)
        {
            return true;
        }
        else
        {
            if(root)
            {
                if(BinTravCheckSum(root->left,iCheck-root->val))
                {
                    return true;
                }
                if(BinTravCheckSum(root->right,iCheck-root->val))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(!root) return false;
        return BinTravCheckSum(root,sum);
    }
};