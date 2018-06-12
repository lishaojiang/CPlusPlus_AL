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
    int BuildKeyMap(vector<int>& rkVec,map<int,int>& rkMap)
    {
        for(int i = 0;i < rkVec.size();i++)
        {
            rkMap[rkVec[i]] = i;
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        TreeNode* pkTree;
        int iLP = 0;
        int iRP = 0;
        int iMidP = postorder.size()-1;
        int iLI =0;
        int iRI = 0;
        int iMidI = 0;
        map<int,int> rkMapI;
        map<int,int> rkMapP;
        BuildKeyMap(inorder,rkMapI);
        BuildKeyMap(postorder,rkMapP);
        while()
        {
            int iIndexL = rkMapI[postorder[iMidP]];
            TreeNode* pkNode = new TreeNode(postorder[iMidP]);
            iLP = iIndexL -1;
            iRP = iIndexL + 1;
        }

        for()
            
    }
};