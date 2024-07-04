class Solution {
public:
    int maxArea(vector<int>& height) {
       if(height.size()==1){
        return 0;
       }
       int maxarea=INT_MIN;
       int left=0;
       int right=height.size()-1;
       while(left<right){
        int high=min(height[left],height[right]);
        maxarea=max(maxarea,high*(abs(left-right)));
        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }

       }
       return maxarea;
       
    }
};