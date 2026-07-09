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
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(list1 && list2){
            if(list1->val<=list2->val){
                tail->next=list1;
                list1=list1->next;
            }else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        tail->next=list1 ? list1:list2;
        return dummy.next;

    }
    ListNode* mergesort(ListNode* list){
        if(!list || !list->next) return list;

        ListNode* slow=list;
        ListNode* fast=list;
        ListNode* mid=NULL;

        while(fast && fast->next){
            mid=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        mid->next=NULL;
        ListNode* left=mergesort(list);
        ListNode* right=mergesort(slow);

        return merge(left,right);
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail=&dummy;

        for(ListNode* temp:lists){
            while(temp!=NULL){
                tail->next=temp;
                temp=temp->next;
                tail=tail->next;
            }
        }
        return mergesort(dummy.next);
    }
};
