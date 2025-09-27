class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans = "";
        if(k==num.size()) return "0";
        for(int i=0;i<num.length();i++){
            while(!st.empty()&& k>0 && ((st.top()-'0') > (num[i] -'0'))){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(k>0){
              st.pop();
              k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        //if stack mai sirf 0s the , iss loop ke baaad saare 0 nikal jayenge 
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.empty()) return "0";
        reverse(ans.begin(),ans.end());
        
      
        return ans ;

    }
};