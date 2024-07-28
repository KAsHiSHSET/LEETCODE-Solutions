class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size=graph.size();
        vector<int> adjrev[size];
        queue<int> q;
        vector<int> ans;
        vector<int> indegree(size,0);
    for(int i=0;i<size;i++){
        for(auto it: graph[i]){
            adjrev[it].push_back(i);
            indegree[i]++;
        }}
    
    for(int i=0;i<size;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
      int node=q.front();
      q.pop();
      ans.push_back(node);
      for(auto it:adjrev[node]){
        indegree[it]--;
        if(indegree[it]==0) q.push(it);
      }
    }
    sort(ans.begin(),ans.end());
    return ans;}
    };