class Solution {
public:
    int missingNumber(vector<int>& vec) {
      int n=vec.size();
      int sum=accumulate(vec.begin(),vec.end(),0);
      // accumulate function gives the sum of the elements in a     vector.
      return (n*(n+1)/2)-sum;  
    }
};