class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum=0;
        for(int i=0;i<nums.size();i++){
            if(i>maximum) return false;
            else{
                 maximum=max(maximum,i+nums[i]);
            }
        }
        return true;
    }
};
//tc ->0(n)
//sc -> 0(1)