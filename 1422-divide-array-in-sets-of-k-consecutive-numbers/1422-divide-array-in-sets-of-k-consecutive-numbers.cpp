class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
      int n=nums.size();
      if(n%k!=0) return false; 
      sort(nums.begin(),nums.end());
      while (!nums.empty()) {
        int start = nums[0];
        for (int i = 0; i < k; ++i) {
            auto it = find(nums.begin(), nums.end(), start + i);
            if (it == nums.end()) {
                return false;
            }
            nums.erase(it);
        }
    }

    return true;
    }
};