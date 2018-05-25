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
    // void FindPath(TreeNode* root, TreeNode* p,vector<TreeNode*>& vRet,bool& bFind)
    // {
    //     if(!root) 
    //         return;
    //     if(bFind) 
    //         return;
    //     if(root == p)
    //     {
    //         bFind = true;
    //     } 
    //     if(!bFind) FindPath(root->left,p,vRet,bFind);
    //     if(!bFind) FindPath(root->right,p,vRet,bFind);
    //     if(bFind) vRet.push_back(root);
    // }
    void FindPath(TreeNode* root, TreeNode* p,stack<TreeNode*>& vS,bool& bFind)
    {
        if(!root) 
            return;
        if(bFind) 
            return;
        vS.push(root);
        if(root == p)
        {
            bFind = true;
        } 
        if(!bFind) FindPath(root->left,p,vS,bFind);
        if(!bFind && root->left) vS.pop();
        if(!bFind) FindPath(root->right,p,vS,bFind);
        if(!bFind && root->right) vS.pop();

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> vP;
        vector<TreeNode*> vQ;
        stack<TreeNode*>  sP;
        stack<TreeNode*> sQ;
        TreeNode* pkRet = NULL;
        bool bFindP = false;
        bool bFindQ = false;
        FindPath(root,p,sP,bFindP);
        FindPath(root,q,sQ,bFindQ);
        while(!sP.empty())
        {
            vP.push_back(sP.top());
            sP.pop();
        }
        while(!sQ.empty())
        {
            vQ.push_back(sQ.top());
            sQ.pop();
        }
        int i =vP.size() -1;
        int j = vQ.size()-1;
        while(i >=0 && j >=0)
        {
             if(vP[i] == vQ[j])
             {
                 pkRet = vP[i];
                 i--;
                 j--;
             }
             else
             {
                break;
             }
        }
        return pkRet;

    }
};