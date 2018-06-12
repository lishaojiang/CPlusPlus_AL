/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

 // 我不知道为什么不行，好奇怪
// class Solution {
// public:
//     TreeLinkNode* FindLeftNextNode(TreeLinkNode *root)
//     {
//         TreeLinkNode *check = root;
//         while(check != NULL)
//         {
//             if(check->right)
//             {
//                 check = check->right;
//                 break;
//             }
//             check = check->next;
//             if(check == NULL)
//             {
//                 break;
//             }
//             if(check->left)
//             {
//                 check=check->left;
//                 break;
//             }
//         }
//         return check;
//     }
    
//     TreeLinkNode* FindRightNextNode(TreeLinkNode *root)
//     {
//         TreeLinkNode *check = root;
//         while(check != NULL)
//         {
//             check = check->next;
//             if(check == NULL)
//             {
//                 break;
//             }
//             if(check->left)
//             {
//                 check=check->left;
//                 break;
//             }
//             if(check->right)
//             {
//                 check = check->right;
//                 break;
//             }
//         }
//         return check;
//     }
//     void connect(TreeLinkNode *root) 
//     {
//         if(!root) return;

//         if(root->left)
//         {
//             root->left->next = FindLeftNextNode(root);
//         }
//         if(root->right)
//         {
//             root->right->next = FindRightNextNode(root);
//         }
//         connect(root->left);
//         connect(root->right); 
//     }
// };

void connect(TreeLinkNode *root) {
    TreeLinkNode *now, *tail, *head;
    
    now = root;
    head = tail = NULL;
    while(now)
    {
        if (now->left)
            if (tail) tail = tail->next =now->left;
            else head = tail = now->left;
        if (now->right)
            if (tail) tail = tail->next =now->right;
            else head = tail = now->right;
        if(!(now = now->next))
        {
            now = head;
            head = tail=NULL;
        }
    }
}