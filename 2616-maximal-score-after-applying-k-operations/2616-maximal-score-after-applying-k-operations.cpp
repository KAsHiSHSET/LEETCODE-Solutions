#include <queue>
#include <vector>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long score = 0;

        // Use a max heap (priority queue)
        std::priority_queue<int> maxHeap(nums.begin(), nums.end());

        // Perform k operations
        while (k > 0) {
            // Get the largest element
            int largest = maxHeap.top();
            maxHeap.pop();

            // Add its value to the score
            score += largest;

            // Reduce it and push it back into the heap
            largest = (largest / 3) + (largest % 3 != 0); // Reduce by one-third (rounding up)
            maxHeap.push(largest);

            // Decrement the number of operations left
            k--;
        }

        return score;
    }
};
