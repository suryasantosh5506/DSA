class DisJointSet{
    public:
    vector<int>rank;
    vector<int>parent;
    
    DisJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findUltimateParent(int n){
        if(parent[n]==n) return n;
        return parent[n]=findUltimateParent(parent[n]);
    }
    
    void unionByRank(int u,int v){
        int pu=findUltimateParent(u);
        int pv=findUltimateParent(v);
        
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }else{
           parent[pv]=pu;
           rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int extraedges=0;
        for(auto it:connections){
            if(ds.findUltimateParent(it[0])!=ds.findUltimateParent(it[1])){
                ds.unionByRank(it[0],it[1]);
            }else{
                extraedges++;
            }
        }

        int Noofcomponents=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) Noofcomponents++;
        }
        return (extraedges>=Noofcomponents-1)?Noofcomponents-1:-1;
    }
};