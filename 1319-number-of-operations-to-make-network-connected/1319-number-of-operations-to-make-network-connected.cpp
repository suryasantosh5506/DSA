class DisJointSet{
public:
    vector<int>parent,rank;

    DisJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findUltimateParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUltimateParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int pu=findUltimateParent(u);
        int pv=findUltimateParent(v);

        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds(n);
        int extraEdges=0;

        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
                ds.unionByRank(u,v);
            }else{
                extraEdges++;
            }
        }

        int noOfComponents=0;

        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) noOfComponents++;
        }

        return (extraEdges>=(noOfComponents-1))?noOfComponents-1:-1;
    }
};