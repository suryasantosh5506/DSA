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
        if(parent[u]==u) return u;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=INT_MIN;
        int m=INT_MIN;

        for(auto it:stones){
            n=max(n,it[0]);
            m=max(m,it[1]);
        }

        DisJointSet ds(n+m+1);
        unordered_map<int,bool>mpp;
        for(auto it:stones){
            ds.unionByRank(it[0],it[1]+n+1);
            mpp[it[0]]=1;
            mpp[it[1]+n+1]=1;
        }
        int components=0;
        for(auto it:mpp){
            if(ds.fup(it.first)==it.first) components++;
        }
        return stones.size()-components;
    }
};