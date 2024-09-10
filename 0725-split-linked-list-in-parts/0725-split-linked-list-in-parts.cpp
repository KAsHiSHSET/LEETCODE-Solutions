class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int size = 0;
        ListNode* temp = head;

        while (temp) {
            size++;
            temp = temp->next;
        }

        int q = size / k; 
        int r = size % k; 

        temp = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < k; i++) {
            ans[i] = temp; 
            int partSize = q + (r > 0 ? 1 : 0); 
            r--;

            for (int j = 0; j < partSize; ++j) {
                prev = temp;
                temp = temp ? temp->next : nullptr;
            }

            // Disconnect the current part from the rest of the list
            if (prev) {
                prev->next = nullptr;
            }
        }

        return ans;
    }
};
