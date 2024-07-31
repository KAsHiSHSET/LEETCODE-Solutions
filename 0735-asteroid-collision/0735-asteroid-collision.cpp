class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteriods) {
        vector<int> st;
       for(int i=0;i<asteriods.size();i++){
        if(asteriods[i]>0){
            st.push_back(asteriods[i]);

        }
        else{
            while(!st.empty()&&st.back()>0&&st.back()<abs(asteriods[i])){
                st.pop_back();
            }
            if(!st.empty()&&st.back()==abs(asteriods[i])){
                st.pop_back();
            }
            else if(st.empty()||st.back()<0){
                st.push_back(asteriods[i]);
            }
        }
        
       } 
       return st;
    }
};