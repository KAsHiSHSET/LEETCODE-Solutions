//tc -> 0(k)
//sc-> 0(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        // Take first k cards from the left
        for (int i = 0; i < k; ++i) {
            total += cardPoints[i];
        }

        int maxPoints = total;

        // Now shift the window: take from right end and remove from left
        for (int i = 1; i <= k; ++i) {
            total -= cardPoints[k - i];             // remove from left
            total += cardPoints[n - i];             // add from right
            maxPoints = max(maxPoints, total);
        }

        return maxPoints;
    }
};

// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
      
//         int sum=0;
//         for(int i=0;i<k;i++){
//             sum+=cardPoints[i];
//         }
//         int ans=sum;
//         k--;
//         int i=cardPoints.size()-1;
//         while(k>=0){
//             sum=sum-cardPoints[k--]+cardPoints[i--];
           
//             ans=max(ans,sum);
//         }
//         return ans;
//     }
// };
