class Solution {
public:
//tc -0(2N)
//SC- 0(N)
    vector<int> asteroidCollision(vector<int>& asteriods) {
        vector<int> st;
       for(int i=0;i<asteriods.size();i++){
        if(asteriods[i]>0){
            st.push_back(asteriods[i]);

        }
        //if it is a neagative element , then pop the elements out of the stack 
        else{
            //destroy one with the lesser value .
            while(!st.empty()&&st.back()>0&&st.back()<abs(asteriods[i])){
                st.pop_back();
            }
            //equal 
            if(!st.empty()&&st.back()==abs(asteriods[i])){
                st.pop_back();
            }
            //insert the neagtive element if th top stack elemt is lesse than 0 or if the stack is empty.
            else if(st.empty()||st.back()<0){
                st.push_back(asteriods[i]);
            }
        }
        
       } 
       return st;
    }
};