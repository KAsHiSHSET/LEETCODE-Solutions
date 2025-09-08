class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;  // empty or single node

        // Step 1: find length and tail
        int totallen = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            totallen++;
        }

        // Step 2: reduce k
        k = k % totallen;
        if (k == 0) return head;

        // Step 3: make circular
        tail->next = head;

        // Step 4: find new head
        int last = totallen - k;
        ListNode* temp = head;
        for (int i = 1; i < last; i++) {
            temp = temp->next;
        }

        // Step 5: break circle
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
