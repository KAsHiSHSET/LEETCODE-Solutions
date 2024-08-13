class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        int left1 = 0, left2 = 0;
        int sum1 = 0, sum2 = 0;

        for (int right = 0; right < n; ++right) {
            sum1 += nums[right];
            sum2 += nums[right];

            // Shrink the window [left1, right] for the first sum to be equal to the goal
            while (left1 <= right && sum1 > goal) {
                sum1 -= nums[left1++];
            }

            // Shrink the window [left2, right] for the second sum to be equal to the goal-1
            while (left2 <= right && sum2 >= goal) {
                sum2 -= nums[left2++];
            }

            count += left2 - left1;
        }

        return count;
    }
};
