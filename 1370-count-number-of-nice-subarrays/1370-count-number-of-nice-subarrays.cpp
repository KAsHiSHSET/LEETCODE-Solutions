class Solution {
public:
    int countSubarraysWithAtMostKOdds(vector<int>& nums, int k) {
        int l = 0, count = 0, sum = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r] % 2;  // odd => 1, even => 0

            while (sum > k) {
                sum -= nums[l] % 2;
                l++;
            }

            count += (r - l + 1);  // count all valid subarrays ending at r
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKOdds(nums, k) - countSubarraysWithAtMostKOdds(nums, k - 1);
    }
};
// tc- 0(2N)
// SC- 0(1 )