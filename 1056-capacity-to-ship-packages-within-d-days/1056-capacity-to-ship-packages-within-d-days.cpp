class Solution {
public:
    long long int helper(vector<int> &weights, int mid ){
        int days=1;
       long long int load=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(load+weights[i]>mid){
                days=days+1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
          int low=*max_element(weights.begin(),weights.end());
          int high=accumulate(weights.begin(),weights.end(),0);
          int result=0;
          while(low<=high){
            int mid=(low+high)/2;
            if(helper(weights,mid)<=days){
                   result=mid;
                   high=mid-1;
            }
            else{
                low=mid+1;
            }
          }
          return result;
    }
};