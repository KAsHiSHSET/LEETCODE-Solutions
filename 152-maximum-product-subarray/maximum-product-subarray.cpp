class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int pref = 1;
        int suff = 1;
        int maxprod = nums[0];

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;

            pref *= nums[i];
            suff *= nums[n - i - 1];

            maxprod = max(maxprod, max(pref, suff));
        }

        return maxprod;
    }
};