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
    ListNode *detectCycle(ListNode *head) {
        // ListNode* slow=head;
        // ListNode* fast=head;
        // while(fast!=NULL&&fast->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         //if slow and fast pointer match , initialise slow by head and then move both by one.
            
        //          slow=head;
        //          //when equal, return slow.
        //          while(slow!=fast){
        //          slow=slow->next;
        //          fast=fast->next;
        //          }
        //          return slow;
        //     }
           
        // }
        // return NULL;
        ListNode* temp= head;
        unordered_map<ListNode*,int> mp;
        int count=0;
        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            mp[temp]= 1;
            temp=temp->next;
        }
        return NULL;

    }
};