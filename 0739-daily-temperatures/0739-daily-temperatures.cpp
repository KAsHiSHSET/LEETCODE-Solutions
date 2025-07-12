class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n=temperatures.size();
        vector<int> res(n,0);
        for(int i=n-1;i>=0;i--){//great element ke liye maintain the decreasing order in stack.

            while(!st.empty()&&temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=0;

            }
            else{
                //no of days from the current day, store in the answer array.
                 res[i]=st.top()-i;
            }
            st.push(i);
        }
        return res;     
        
    }
};
//tc - 0(2N)
// Each element is pushed and popped at most once → linear time.
//  SC- O(N) — the result array is required output, not auxiliary.
//auxiliary is only stack