class Solution {
public:
    // Count the number of set bits (1s) in the binary representation of a number.
    static int countBits(int num) {
        int count = 0;
        
        while (num > 0) {
            count++;
            num &= (num - 1);  // Clear the least significant set bit.
        }
        
        return count;
    }
    
    static bool compare(int a, int b) {
        int bitCountA = countBits(a);
        int bitCountB = countBits(b);
        
        if (bitCountA == bitCountB) {
            return a < b;  // If set bit counts are equal, compare numerically.
        }
        
        return bitCountA < bitCountB;  // Sort by the set bit count in ascending order.
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};