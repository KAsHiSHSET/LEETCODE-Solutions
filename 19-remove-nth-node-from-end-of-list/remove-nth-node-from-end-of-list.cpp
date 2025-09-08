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
       ListNode* temp = head;
       int totallen=0;
       while(temp!=NULL){
         totallen++;
         temp=temp->next;
       }
       int delfront = totallen-n;
       if(delfront==0){
        temp=head;
        head=head->next;
        delete(temp);
        return head;
       }
       temp=head;
       while(delfront!=1){
          temp=temp->next;
          delfront--;
       }
       ListNode* temo= temp->next;
       temp->next=temp->next->next;
       delete(temo);
       return head;
           }

};