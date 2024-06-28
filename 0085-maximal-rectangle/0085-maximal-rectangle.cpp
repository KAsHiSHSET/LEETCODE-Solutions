class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else
                   height[j]=0;
          }
           ans=max(ans,area(height));
        }
        return ans;
    }
    int area(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
     
        stack<int> st;
        for(int i=0;i<=n;i++){
        while((!st.empty())&&(i==n||heights[st.top()]>=heights[i])){
               int height=heights[st.top()];
               st.pop();
               int width;
               if(st.empty()) width=i;
               else
               width=i-st.top()-1;
          


          ans=max(ans,height*width);
        }
        st.push(i);
        }
          return ans;
    }
};