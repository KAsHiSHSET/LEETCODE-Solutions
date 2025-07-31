class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i : nums) {
            int digits = log10(i) + 1;//calculate the nuber of dogits
            if (digits % 2 == 0) ++count;//check wheter even or not
        } 
        return count;
    }
};