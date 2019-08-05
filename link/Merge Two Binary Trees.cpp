/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void merge(TreeNode* & pkParent,TreeNode* t1, TreeNode* t2)
    {
        if(t1&&t2)
        {
            pkParent = new  TreeNode(t1->val + t2->val);
            merge(pkParent->left,t1->left,t2->left);
            merge(pkParent->right,t1->right,t2->right);
        }
        else if(t1)
        {
            pkParent = new  TreeNode(t1->val);
            merge(pkParent->left,t1->left,NULL);
            merge(pkParent->right,t1->right,NULL);
        }
        else if(t2)
        {
            pkParent = new  TreeNode(t2->val);
            merge(pkParent->left,NULL,t2->left);
            merge(pkParent->right,NULL,t2->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        TreeNode* pkRetNode = NULL;
        merge(pkRetNode,t1,t2);
        return pkRetNode;
    }
};