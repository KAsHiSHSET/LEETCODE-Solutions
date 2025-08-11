class Solution {
public:
 typedef pair<long long, pair<int,int>> pt;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pt,vector<pt>> pq;
        for(int i=0;i<points.size();i++){
            //first interate and add in the pq then max heap will adjust automatically , if the size goes beyond k , it        automactically removes large element from top and keeps k elements.
        pq.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
        if(pq.size()>k){
            pq.pop();
        }}
           vector<vector<int>> ans;
           while(!pq.empty()){
            vector<int> elemt;
                pt topElem = pq.top(); // topElem is a pair<long long, pair<int,int>>
elemt.push_back(topElem.second.first);
elemt.push_back(topElem.second.second);
pq.pop();
ans.push_back(elemt);

           }
        
        return ans;
    }
};