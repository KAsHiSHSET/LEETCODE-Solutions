//we will make a disjoint set union
class disjoint{
    
    public:
    vector<int> rank,parent, size;
    //calling a constructor 
    disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    //member functions of claass
    int findupar(int node){
        if(node==parent[node]){
            return node;
        }
         parent[node] = findupar(parent[node]);
         return parent[node];
    }
    void unionbyrank(int u,int v){
        int ulp_u = findupar(u);
        int ulp_v= findupar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
         }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
         }
        else {
             parent[ulp_v] = ulp_u;
              rank[ulp_u]++;
        }

        
    }
    void unionbysize(int u, int v) {
    int ulp_u = findupar(u);
    int ulp_v = findupar(v);
    if(ulp_u == ulp_v) return; // already in same set

    if(size[ulp_u] <= size[ulp_v]) {
        parent[ulp_u] = ulp_v;
        size[ulp_v] += size[ulp_u];  // increase size of bigger set
    } 
    else {
        parent[ulp_v] = ulp_u;
        size[ulp_u] += size[ulp_v];
    }
}

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //this is the question on dsu
         disjoint ds(n);
         int extraedge=0;
         int parentcomp=0;
         for(auto it: connections){
            int u = it[0];
            int v= it[1];
            if(ds.findupar(u)==ds.findupar(v)){
                //if they have same parent then count the extraedge
                extraedge++;
            }
            else{
                //if not the ultimate parent then you should make them unite
                ds.unionbysize(u,v);
            }

         }
         // ideallly 
        //  parentcomp - 1 = extraedgs
        for(int i=0;i<n;i++){
    if(ds.parent[i]==i){
        parentcomp++;
    }
}

         int ans = parentcomp-1;
         if(extraedge>= ans ) return ans;
         else {return -1;}

    }
};