// class MinStack {
// public:
//     stack<int> st;
//     int minelement=-1;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if(st.size()==0){
//             st.push(val);
//             minelement=val;
//         }
//         else{
//             if(val>=minelement){
//                 st.push(val);
//             }
//             else if(val<minelement){
//                 st.push(2*val-minelement);
//                 minelement=val;
//             }
//         }
//     }
    
//     void pop() {
//         if(st.size()==0){
//             return;
//         }
//         else{
//             if(st.top()>=minelement){
//                 st.pop();
//             }
//             else if(st.top()<minelement){
//                 minelement=2*minelement-st.top();
//                 st.top();
//             }
//         }

//     }
    
//     int top() {
//         if(st.size()==0){
//             return -1;
//         }
//         else{
//           if(st.top()>=minelement) return st.top();
//           else if(st.top()<minelement)return minelement;
//         }
        
//     }
    
//     int getMin() {
//         if(st.size()==0){
//             return -1;
//         }
//         else{
//             return minelement;
//         }
        
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(val);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */

class MinStack {
public:
    //Pair contains the current value and the current minima 
    stack<int> st1;
    stack<int> st2;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st1.size()==0&&st2.size()==0){
            st1.push(val);
            st2.push(val);
        }
        else
        {
            st1.push(val);
            st2.push(min(val,st2.top()));

        }
    }
    
    void pop() {
        if(!st1.empty()){
            st1.pop(); st2.pop();
        }        
    }
    
    int top() {
      int g= st1.top();
         return g;
    }
    
    int getMin() {
        return st2.top();
    }
};