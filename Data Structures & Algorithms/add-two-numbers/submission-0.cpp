/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        int c=0;

        while(l1!=NULL || l2!=NULL|| c!=0){
            int x=(l1!=NULL)? l1->val:0;
            int y=(l2!=NULL)? l2->val:0;

            int sum=x+y+c;
            c=sum/10;
            int digit=sum%10;

            curr->next=new ListNode(digit);
            curr=curr->next;

            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;

        }
        return dummy->next;
    }
};
