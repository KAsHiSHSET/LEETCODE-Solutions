
class Solution {
public:
 vector<vector<int>> threeSum(vector<int>& nums) {
    // set<vector<int>> st;
    //  for(int i=0;i<nums.size()-2;i++){
    //     for(int j=i+1;j<nums.size()-1;j++){
    //         for(int k=j+1;k<nums.size();k++){
    //             if(nums[i]+nums[j]+nums[k]==0){
    //                 vector<int> temp={nums[i],nums[j],nums[k]};
    //                 sort(temp.begin(),temp.end());
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    //  }
    // vector<vector<int>> ans(st.begin(),st.end());
    //  return ans;
    
    // through set-tle
    // set<vector<int>> st;
   
    // for(int i=0;i<nums.size();i++){
    //      set<int> hashset;
    //     for(int j=i+1;j<nums.size();j++){
    //         int third=-(nums[i]+nums[j]);
    //         if(hashset.find(third)!=hashset.end()){
    //             vector<int> temp={third,nums[i],nums[j]};
    //             sort(temp.begin(),temp.end());
    //             st.insert(temp);
    //         }
    //         hashset.insert(nums[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(),st.end());
    // return ans;
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1]){
            continue;//goes for the next interation
        }
         int j=i+1;
        int k=nums.size()-1;
        while(j<k){
        
        int sum=nums[i]+nums[j]+nums[k];
        if(sum>0){
           k--;
        }
        else if(sum<0){
            j++;
        }
        else{
            ans.push_back({nums[i],nums[j],nums[k]});
              j++;
              k--;
              while(j<k&&nums[j]==nums[j-1])j++;
              while(j<k&&nums[k]==nums[k+1])k--;
        }
    }
    }
    return ans;
 }
};