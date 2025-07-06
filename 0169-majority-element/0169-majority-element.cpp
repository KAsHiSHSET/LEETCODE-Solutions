class Solution {
public:
    int majorityElement(vector<int>& nums) {
    //     int count=0;
    //     int element;
    //     for(int i=0;i<nums.size();i++){
    //          if(count==0){
    //             element=nums[i];
    //          }
    //          if(element==nums[i]){
    //             count++;
    //          }
    //         else if(element!=nums[i]){
    //             count--;
    //          }
    //     }
    //    return element;
     int n= nums.size();
        n= n/2;
        
        unordered_map<int,int> mp;
        for(int n:nums){
            mp[n]++;
        }
        for(auto [a,b]: mp){
            if(b>n){
                return a;
            }
        }
        return -2;
    }
};