class DisJointSet{
public:
    vector<int>rank;
    vector<int>parent;
    DisJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findUltimateParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUltimateParent(parent[u]);
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
            parent[pu]=pv;
            rank[pv]++;
        }
    }
};


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>first,second,parent(n+1,-1);
        DisJointSet ds(n+1);

        for(auto it:edges){
            int u=it[0],v=it[1];

            if(parent[v]!=-1){
                first={parent[v],v};
                second={u,v};
            }else parent[v]=u;
        }

        for(auto &it:edges){

            if(it==second) continue;

            if(ds.findUltimateParent(it[0])!=ds.findUltimateParent(it[1])){
                ds.unionByRank(it[0],it[1]);
            }else{
                if(first.empty()) return it;
                return first;
            }
        }

        return second;
    }
};