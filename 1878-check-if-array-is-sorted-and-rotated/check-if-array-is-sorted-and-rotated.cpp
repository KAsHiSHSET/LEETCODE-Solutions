class Solution {
public:
    bool check(vector<int>& nums) {
       int count=0;
       int n= nums.size();
       for(int i=0;i<n;i++){
        //eg-> 5 > 1 
         if(nums[i]>nums[(i+1)%nums.size()]){
            count++;
         }
       }
       return  count<=1;
   
     }

};