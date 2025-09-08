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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        //waise toh initially head par domo 
        //par fast two step ahead
        //correction -> pehle hi head ko 2 points se aaage move kara do 
       
        fast=fast->next->next;
        while(fast!=NULL&&fast->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
        }
      ListNode* mid=slow->next; // mid will be slow pointer ka next 
        slow->next=mid->next;
     delete mid;
        return head;
    }
};