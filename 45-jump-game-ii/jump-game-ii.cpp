class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0;
        int r=0;
        int jumps=0;
        
        while(r<nums.size()-1){
           //calculate the farhtest we can go from the element of that window
           int farthest=0;
           for(int i=l;i<=r;i++){
               farthest= max(farthest,i+nums[i]);
           }
           l=r+1;
           r=farthest;
           jumps++;
        }
        //when the r goes beyond n-1(the last index of array , we come out of the loop and return jumps)
        return jumps;
       
    }
};