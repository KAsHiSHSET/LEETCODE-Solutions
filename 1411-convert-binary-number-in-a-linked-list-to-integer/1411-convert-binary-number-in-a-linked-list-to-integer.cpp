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
//0(n)->tc -> traversal of linked list
//0(1)-> sc 
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int ans=0;
        while(temp!=nullptr){
          ans = (ans<<1) | temp->val;
          temp=temp->next;
        }
        return ans;
    }
};