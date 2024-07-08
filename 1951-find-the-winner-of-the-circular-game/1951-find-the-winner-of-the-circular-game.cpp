class Solution {
public:
    int findTheWinner(int n, int k) {
      int i=1;
      for(int j=2;j<=n;j++){
        i=i+k;
        i=(i-1)%j+1;
      }
      return i;
    }
};