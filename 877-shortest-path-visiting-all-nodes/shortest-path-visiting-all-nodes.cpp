// class Solution {
// public:
//     int shortestPathLength(vector<vector<int>>& graph) {
//         //bfs + we can revisit the nodes.
//         // {node, decimalvale}
//         //we start with all nodes in  que , then check its neighbour, or the bit values of the node and check whether the node exists or not.
//         //if not, insert it in the que
//         int n=graph.size();
//         //as there is no path to visit.
//         if(n==0||n==1) return 0;


//     }
// };
class Solution {
public:
    
    typedef pair<int, int> P;
    //bfs+ bitmasking
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        if(n == 1 || n == 0)
            return 0;
        
        queue<P> que;
        
        set<P> vis;
        

        int allVisitedState = (1 << n) - 1; // if all nodes visited then
            
        for(int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            
            que.push({i, maskValue});
            
            vis.insert({i, maskValue});
        }
        
        int result = 0;
        
        // Implementing BFS
        while(!que.empty())  {
            
            int N = que.size();
            result++;
            while(N--) {
                
                auto curr = que.front();
                que.pop();
                
                int currNode = curr.first;
                int currMask = curr.second;
                
                for(auto &adj: graph[currNode]) {
                    int nextMask = currMask | (1 << adj);
                    
                    if(nextMask == allVisitedState)
                        return result;
                    
                    if(vis.find({adj, nextMask}) == vis.end()) {
                        vis.insert({adj, nextMask});
                        que.push({adj, nextMask});                      
                    }
                }  
            }
        }

        return -1;
    }
};