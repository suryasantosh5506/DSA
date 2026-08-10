class DisJointSet{
public:
    vector<int>rank;
    vector<int>parent;
    DisJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int fup(int u){
        if(u==parent[u]) return u;
        return parent[u]=fup(parent[u]);
    }
    
    void unionByRank(int u,int v){
        int pu=fup(u);
        int pv=fup(v);
        
        if(pu==pv) return;
        
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n+1);
        int extra=0;
        for(auto it:connections){
            if(ds.fup(it[0])!=ds.fup(it[1])){
                ds.unionByRank(it[0],it[1]);
            }else{
                extra++;
            }
        }

        int total=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) total++;
        }
        return (extra>=total-1)?total-1:-1;
    }
};