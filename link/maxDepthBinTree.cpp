/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// function 1 top-down
// class Solution 
// {
// public:
//     void BTDepth(TreeNode* tree,int iDepth,int & iMaxDepth)
//     {
//         if(tree == nullptr)
//         {
//            if(iDepth > iMaxDepth)
//            {
//                iMaxDepth = iDepth;
//            }
//            return;
//         }
//         BTDepth(tree->left,iDepth +1,iMaxDepth);
//         BTDepth(tree->right,iDepth +1,iMaxDepth);
//     }
//     int maxDepth(TreeNode* root) 
//     {
//         int iMaxDepth = 0;
//         BTDepth(root,0,iMaxDepth);
//         return iMaxDepth;
//     }
// };

// function 2 bottom to up
// 这个简单但是难理解，我没有理解透
class Solution 
{
public:

    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return 0;
        }
        int iLeft = maxDepth(root->left);
        int iRight = maxDepth(root->right);
        return max(iLeft,iRight) +1;
    }
};