class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
     
        stack<int> st;
        for(int i=0;i<n;i++){
            //to maintain the stack increasing , if we encounter the smaller element than the stack top , pop the elements from top of the stack 
        while((!st.empty())&&(heights[st.top()]>=heights[i])){
               int height=heights[st.top()];
               st.pop();
               int width;
              if(st.empty()) width=i-0;
              else
                 width=i-st.top()-1;
          


          ans=max(ans,height*width);
        }
        st.push(i);
        }
        while(!st.empty()){
            int nse=heights.size();
         int element= st.top(); st.pop();
            int pse=st.empty()?-1:st.top();
            ans=max(ans,heights[element]*(nse-pse-1));
        }
          return ans;
    }
  
};