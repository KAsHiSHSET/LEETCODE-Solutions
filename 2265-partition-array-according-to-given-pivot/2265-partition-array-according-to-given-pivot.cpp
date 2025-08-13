class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> less, equal, greater;

        for (int x : nums) {
            if (x < pivot) less.push_back(x);
            else if (x == pivot) equal.push_back(x);
            else greater.push_back(x);
        }
        for(int i=0;i<less.size();i++){
            ans.push_back(less[i]);
        }
         for(int i=0;i<equal.size();i++){
            ans.push_back(equal[i]);
        }
         for(int i=0;i<greater.size();i++){
            ans.push_back(greater[i]);
        }
        return ans;
    }
};