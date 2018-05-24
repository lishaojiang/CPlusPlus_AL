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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> akRet;
        stack<TreeNode*> akStack;
        while(root)
        {
			akRet.push_back(root->val);
            akStack.push(root->right);
			root = root->left;

			if (root == NULL)
			{
				root = akStack.top();
				akStack.pop();
				while (root == NULL && !akStack.empty())
				{
					root = akStack.top();
					akStack.pop();
				}
			}
        }    
		return akRet;
    }
};