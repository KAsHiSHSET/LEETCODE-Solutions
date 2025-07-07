class Solution {
public:
    int trap(vector<int>& height) {
       vector<int> left(height.size());
       vector<int> right(height.size());
       if(height.size()==0){
        return 0;
       }
       int trappedwater=0;
       left[0]=height[0];
       //prfix
       for(int i=1;i<left.size();i++){
          left[i]=max(left[i-1],height[i]);
       } 
       //suffix
       right[right.size()-1]=height[height.size()-1];
       for(int i=right.size()-2;i>=0;i--){
         right[i]=max(right[i+1],height[i]);
       }
       for(int i=0;i<height.size();i++){
        trappedwater=trappedwater+min(left[i],right[i])-height[i];
       }
       return trappedwater;
    }
};