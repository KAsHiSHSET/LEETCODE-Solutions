class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> degree(numCourses,0);
       vector<int> adj[numCourses];
       for(auto it:prerequisites){
         adj[it[1]].push_back(it[0]);

       }
       for(int i=0;i<numCourses;i++){
           for(auto ch:adj[i]){
              degree[ch]++;
           }
       }
       vector<int> ans;
       queue<int> q;
       for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(i);
            }
       }
       while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            degree[it]--;
            if(degree[it]==0)
              q.push(it);
        }

       }
       if(ans.size()==numCourses){
        return true;
       }
       return false;
    }
};