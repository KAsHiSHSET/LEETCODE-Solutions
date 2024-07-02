// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//     int left=0;
//     int right=cardPoints.size()-1;
//     int leftsum=0;
//     int rightsum=0;
//     int maxi=0;
//     if(cardPoints.size()==k){
//         maxi=accumulate(cardPoints.begin(),cardPoints.end(),0);
//         return maxi;
//     }
//     for(int i=0;i<k;i++){
//         leftsum=leftsum+cardPoints[i];
//         left++;
//     }
//     left--;
//     while(left!=0&&right!=(cardPoints.size()-k)){
//         int summation=leftsum+rightsum;
//         maxi=max(summation,maxi);
//         summation=0;
//         leftsum=leftsum-cardPoints[left];
//         left--;
//         rightsum=rightsum+cardPoints[right];  
//         right--;
//         if(left==0&&right==(cardPoints.size()-k)) break;
//     }
//     return maxi;
// }
// };
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int ans=sum;
        k--;
        int i=cardPoints.size()-1;
        while(k>=0){
            sum=sum-cardPoints[k--]+cardPoints[i--];
           
            ans=max(ans,sum);
        }
        return ans;
    }
};
