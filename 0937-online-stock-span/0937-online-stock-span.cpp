class StockSpanner {
public:
    StockSpanner() {
        
    }
      stack<pair<int,int>> st;
    int next(int price) {
    //     stack<pair<int,int> st;
    //     vector<int> vec;
    //     for(int i=0;i<vec.size();i++){
    //         if(st.empty()){
    //           vec.push_back(-1);
    //         }
    //         else if(s.size()>0&&s.top().first>vec[i]){
    //             v.push_back(s.top().second);
    //         }
    //         else if(s.size()>0&&s.top().first<=vec[i]){
    //            while(s.size()>0&&s.top().first<=vec[i]){
    //             if(s.size()==0){
    //                 v.push_back(-1);
    //             }
    //             else{
    //                 v.push_back(s.top().second);
    //             }
    //            }
    //         }
    //         st.push(vec[i],i);
    //     }
  
    int span=1;
    while(!st.empty()&&st.top().first<=price){
        span+=st.top().second;
        st.pop();
    }
     st.push({price,span});
    return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */