class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    //   unordered_map<int,string> mp;
      
    //   for(int i=0;i<heights.size();i++){
    //     mp[heights[i]]=(names[i]);
    //   }
    //   sort(heights.begin(),heights.end(),greater<int>());
    // // sort(heights.rend(),heights.rbegin());
    //   for(int i=0;i<mp.size();i++){
    //       names[i]=mp[heights[i]];
    //   }
      
    //   return names;
    priority_queue<pair<int,string>> pq;
    for(int i=0;i<names.size();i++){
        pq.push({heights[i],names[i]});
    }
    int i=0;
    while(!pq.empty()){
       names[i++]= pq.top().second;
       pq.pop();
    }
    return names;

    }
};