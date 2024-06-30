class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
  
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int pop=-1;
        if(!s2.empty()){
          pop=s2.top();
          
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            pop= s2.top();
        }
         s2.pop();
        return pop;
    }
    
    int peek() {
        int g=-1;
        if(!s2.empty()){
          g= s2.top();
          
        }
        else{
            while(s1.size()!=0){
                s2.push(s1.top());
                s1.pop();
            }
            g= s2.top();
        }
        return g;
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */