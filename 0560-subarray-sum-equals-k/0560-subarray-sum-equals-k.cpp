class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
     //we dont have to calculate the max len but the total number of arrayss with sum k
     int l=0;
     int r=0;
     int sum=0;
     int count=0;
     int n=nums.size();
     int maxlen=0;
    //  while(r<n){
    //     while(l<=r && sum > k){
    //         sum=sum-nums[l];
    //         l++;
    //     }
    //     if(sum==k){
    //         maxlen=max(maxlen,r-l+1);
    //         count++;
    //     }
    //     if(r<n) sum+=nums[r++];
    //  }
    //  return count;
    // }
    unordered_map<int,int> mp;
    //prefixsum+ hashmap

    for(int i=0;i<n;i++){
         sum=sum+nums[i];
         if(sum==k) count++;
         if(mp.find(sum-k)!=mp.end()){
            count+= mp[sum-k];
         }
         mp[sum]++;
         
    }
    return count;
    }
};