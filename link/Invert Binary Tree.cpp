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

    void invertTreeDFS(TreeNode* root) 
    {
        if(!root) return;
        TreeNode* pkTemp = root->left;
        root->left = root->right;
        root->right = pkTemp;
        invertTreeDFS(root->left);
        invertTreeDFS(root->right);
    }   

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        deque<TreeNode*> bfs;
        bfs.push_back(root);
        while(!bfs.empty())
        {
            int iSize = bfs.size();
            for(int i = 0; i  < iSize; i++)
            {
                TreeNode* pkNode = bfs.front();
                bfs.pop_front();
                TreeNode* pkTemp = pkNode->left;
                pkNode->left = pkNode->right;
                pkNode->right = pkTemp;

                if(pkNode->left) bfs.push_back(pkNode->left);
                if(pkNode->right) bfs.push_back(pkNode->right);
            }
        }

        return root;
    }
};