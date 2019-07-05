/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers_onebyone(ListNode* l1, ListNode* l2) 
    {
        ListNode* pkRet = NULL;
        ListNode* pkCopy = NULL;
        int bJump = 0;
        while(l1 && l2)
        {
            int c = l1->val + l2->val;
            c = c + bJump;
            if(c >= 10)
            {
                c = c % 10;
                bJump = 1;
            }
            else
            {
                bJump = 0;
            }

            if(pkRet == NULL)
            {
                pkRet = new ListNode(c);
                pkCopy = pkRet;
            }
            else 
            {
                pkCopy->next = new ListNode(c);
                pkCopy = pkCopy->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode* pkLeft =  l1;
        if(l1 == NULL)
        {
            pkLeft = l2;
        }
        while(pkLeft || bJump)
        {
            if(pkLeft)
            {
                int c = pkLeft->val;
                c = c + bJump;
                if(c >= 10)
                {
                    c = c % 10;
                    bJump = 1;
                }
                else
                {
                    bJump = 0;
                }

                {
                    pkCopy->next = new ListNode(c);
                    pkCopy = pkCopy->next;
                }
                pkLeft = pkLeft->next;
            }
            else
            {
                pkCopy->next = new ListNode(1);
                bJump = false;
            }
            
        }
        
        return pkRet;  
    }

    // write by the internet,more simple
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
        extra = sum / 10;
        p->next = new ListNode(sum % 10);
        p = p->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return preHead.next;
}
};


