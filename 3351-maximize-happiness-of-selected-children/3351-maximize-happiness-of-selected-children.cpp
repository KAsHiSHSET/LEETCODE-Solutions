class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long maxSum = 0;

        // sort in decreasing order
        sort(happiness.begin(), happiness.end(), greater<int>());

        // select the first child
        maxSum += max(0, happiness[0]);

        // iterate through the remaining children
        for (int i = 1; i < k; ++i) {
            if (happiness[i] - i > 0)
                maxSum += happiness[i] - i;
        }

        return maxSum;
    }
};