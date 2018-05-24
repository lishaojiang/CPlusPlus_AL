/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* FindLeftNextNode(TreeLinkNode *root)
    {
        TreeLinkNode *check = root;
        while(check != NULL)
        {
            if(check->right)
            {
                check = check->right;
                break;
            }
            check = check->next;
            if(check == NULL)
            {
                break;
            }
            if(check->left)
            {
                check=check->left;
                break;
            }
        }
        return check;
    }
    
    TreeLinkNode* FindRightNextNode(TreeLinkNode *root)
    {
        TreeLinkNode *check = root;
        while(check != NULL)
        {
            check = check->next;
            if(check == NULL)
            {
                break;
            }
            if(check->left)
            {
                check=check->left;
                break;
            }
            if(check->right)
            {
                check = check->right;
                break;
            }
        }
        return check;
    }
    void connect(TreeLinkNode *root) 
    {
        if(!root) return;

        if(root->left)
        {
            root->left->next = FindLeftNextNode(root);
        }
        if(root->right)
        {
            root->right->next = FindRightNextNode(root);
        }
        connect(root->left);
        connect(root->right); 
    }
};