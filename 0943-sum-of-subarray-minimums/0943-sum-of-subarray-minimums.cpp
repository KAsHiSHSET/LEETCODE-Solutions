class Solution {
public:
    //calculate pse and nse 
    vector<int> nse;
    vector<int> pse;
    int MOD= 1e9 + 7;
    void NSE(vector<int> &arr){
        int nextelement=arr.size();
        stack<int> st;
        nse.resize(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
          while(!st.empty()&& arr[i]<=arr[st.top()]){
            st.pop();
          }
          nse[i]= st.empty()? nextelement : st.top();
          st.push(i);

        }

    }
    void PSE(vector<int> &arr){
        int nextelement=arr.size();
         stack<int> st;
          pse.resize(arr.size());
        for(int i=0;i<arr.size();i++){
          while(!st.empty()&& arr[i]<arr[st.top()]){
            st.pop();
          }
          pse[i]= st.empty()? -1 : st.top();
          st.push(i);

        }

    }

    
    int sumSubarrayMins(vector<int>& arr) {
        int output=0;
        NSE(arr);
        PSE(arr);
        for(int i=0;i<arr.size();i++){
           long long int left= i-pse[i];
          long long int right = nse[i]-i;
           output=( output +((left%MOD * right%MOD * arr[i])%MOD))%MOD;
            
        }
        return output;
    }
};