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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1=head;
        int count=0;
        while(temp1!=NULL){
            count++;
            temp1=temp1->next;
        }
        ListNode* temp2=head;

        if(n==count){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        
        for(int i=0;i<(count-n-1);i++){
            temp2=temp2->next;
        }
        ListNode* temp3=temp2->next;
        temp2->next=temp3->next;
        temp3->next=NULL;

        return head;
    }
};
