/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// function one，非常的low
// class Solution 
// {
// public:
//     void FindPath(TreeNode* root, TreeNode* p,stack<TreeNode*>& vS,bool& bFind)
//     {
//         if(!root) 
//             return;
//         if(bFind) 
//             return;
//         vS.push(root);
//         if(root == p)
//         {
//             bFind = true;
//         } 
//         if(!bFind) FindPath(root->left,p,vS,bFind);
//         if(!bFind && root->left) vS.pop();
//         if(!bFind) FindPath(root->right,p,vS,bFind);
//         if(!bFind && root->right) vS.pop();

//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
//     {
//         vector<TreeNode*> vP;
//         vector<TreeNode*> vQ;
//         stack<TreeNode*>  sP;
//         stack<TreeNode*> sQ;
//         TreeNode* pkRet = NULL;
//         bool bFindP = false;
//         bool bFindQ = false;
//         FindPath(root,p,sP,bFindP);
//         FindPath(root,q,sQ,bFindQ);
//         while(!sP.empty())
//         {
//             vP.push_back(sP.top());
//             sP.pop();
//         }
//         while(!sQ.empty())
//         {
//             vQ.push_back(sQ.top());
//             sQ.pop();
//         }
//         int i =vP.size() -1;
//         int j = vQ.size()-1;
//         while(i >=0 && j >=0)
//         {
//              if(vP[i] == vQ[j])
//              {
//                  pkRet = vP[i];
//                  i--;
//                  j--;
//              }
//              else
//              {
//                 break;
//              }
//         }
//         return pkRet;

//     }
// };
// function tow ,try use postorder to record Tree path
class Solution 
{
public:
    void FindPath(TreeNode* root, TreeNode* p,stack<TreeNode*>& vS,bool& bFind)
    {
        if(!root) return;
        if(root == p)
        {
            bFind = true;
        } 
        if(!bFind) FindPath(root->left,p,vS,bFind);
        if(!bFind) FindPath(root->right,p,vS,bFind);
        if(bFind) vS.push(root);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        stack<TreeNode*>  sP;
        stack<TreeNode*> sQ;
        TreeNode* pkRet = NULL;
        bool bFindP = false;
        bool bFindQ = false;
        FindPath(root,p,sP,bFindP);
        FindPath(root,q,sQ,bFindQ);
        while(!sP.empty() && !sQ.empty())
        {
             if(sP.top() == sQ.top())
             {
                 pkRet = sP.top();
                 sP.pop();
                 sQ.pop();
             }
             else
             {
                break;
             }
        }
        return pkRet;
    }
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}

TreeNode * dfsTraverse(TreeNode * root, TreeNode * p , TreeNode * q)
{
    if( root == p || root == q || root == NULL)
        return root;
    TreeNode * parent1 = dfsTraverse(root->left, p, q);
    TreeNode * parent2 = dfsTraverse(root->right, p, q);
    if( parent1 && parent2)
        return root;
    else
        return parent1 ? parent1:parent2;
}
TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q)
{
    return dfsTraverse(root, p, q);
}
/*如果root为空，则返回空
如果root等于其中某个node，则返回root 
如果上述两种情况都不满足，则divide，左右子树分别调用该方法
Divide & Conquer中治这一步要考虑清楚，本题三种情况
如果left和right都有结果返回，说明root是最小公共祖先
如果只有left有返回值，说明left的返回值是最小公共祖先
如果只有�right有返回值，说明�right的返回值是最小公共祖*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p==NULL ||q==NULL) return NULL;
        if(p == root || q == root) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL)
            return root;
        return left?left:right;
    }
};