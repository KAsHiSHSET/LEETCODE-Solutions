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
        int carry=0;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(temp1||temp2||carry){
            int sum=0;
            if(temp1!=NULL){
                sum=sum+temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=NULL){
                sum=sum+temp2->val;
                temp2=temp2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=newnode;
        }
          return dummy->next;
    }
};