/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// my first function
// use more queue 


// class Solution 
// {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root)
//     {
//         vector<int> kOne;
//         vector<vector<int>> kRet;
//         if(root == nullptr) return kRet;
//         queue<TreeNode*> kTree;
//         queue<TreeNode*> kNext;
//         kTree.push(root);
//         // if(root->left != nullptr) kNext.push(root->left);
//         // if(root->right != nullptr) kNext.push(root->right);
//         while(1)
//         {
//             kOne.clear();
//             kNext = queue<TreeNode*>();
//             while(!kTree.empty())
//             {
//                 TreeNode* pkNode = kTree.front();
//                 kOne.push_back(pkNode->val);
//                 kTree.pop();
//                 if(pkNode->left != nullptr) kNext.push(pkNode->left);
//                 if(pkNode->right != nullptr) kNext.push(pkNode->right);
//             }
//             if(!kOne.empty())
//             {
//                 kRet.push_back(kOne);
//             }
//             kTree = kNext;
//             if(kTree.empty())
//             {
//                 break;
//             }
//         }
//         return kRet;
//     }
// };

// function 2,don't use more queque
//class Solution 
//{
//public:
//    vector<vector<int>> levelOrder(TreeNode* root)
//    {
//        vector<int> kOne;
//        vector<vector<int>> kRet;
//        if(root == nullptr) return kRet;
//        queue<TreeNode*> kTree;
//        kTree.push(root);
//        kTree.push(nullptr);
//        while(!kTree.empty())
//        {
//            TreeNode* pkNode = kTree.front();
//			kTree.pop();
//            if(pkNode)
//            {
//                kOne.push_back(pkNode->val);
//                if(pkNode->left != nullptr) kTree.push(pkNode->left);
//                if(pkNode->right != nullptr) kTree.push(pkNode->right);          
//            }
//            else
//            {
//                if(!kOne.empty())
//                {
//                    kRet.push_back(kOne);
//                    kTree.push(nullptr);
//                }
//                kOne.clear();
//            }
//        }
//        return kRet;
//    }
//};

// function 3 ,很烂的递归方法
class Solution
{
public:
	void BFS_TravelTree(vector<TreeNode*> kNodeVec, vector<vector<int>>& rkRet)
	{
		vector<int> kOne;
		vector<TreeNode*> kNextNodeVec;
		for (int i = 0; i < kNodeVec.size(); i++)
		{
			if (kNodeVec[i])
			{
				kOne.push_back(kNodeVec[i]->val);
				if (kNodeVec[i]->left) kNextNodeVec.push_back(kNodeVec[i]->left);
				if (kNodeVec[i]->right) kNextNodeVec.push_back(kNodeVec[i]->right);
			}
		}
		if (!kOne.empty())
		{
			rkRet.push_back(kOne);
		}
		if (!kNextNodeVec.empty())
		{
			BFS_TravelTree(kNextNodeVec, rkRet);
		}
	}
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> kRet;
		if (root == nullptr) return kRet;
		vector<TreeNode*> kTree;
		kTree.push_back(root);
		BFS_TravelTree(kTree, kRet);
		return kRet;
	}
};