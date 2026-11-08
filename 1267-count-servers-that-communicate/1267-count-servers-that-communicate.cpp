class DisJointSet{
public:
    vector<int>size;
    vector<int>parent;

    DisJointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int fup(int u){
        if(parent[u]==u) return u;
        return parent[u]=fup(parent[u]);
    }

    void unionBySize(int u,int v){
        int pu=fup(u);
        int pv=fup(v);

        if(pu==pv) return;
        if(size[pu]>=size[pv]){
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else if(size[pv]>size[pu]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
};


class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size()      ;
        int m=grid[0].size();
        DisJointSet ds(n+m+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ds.unionBySize(i,n+j);
            }
        }

        vector<int>servercount(n+m+1,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int root=ds.fup(i);
                    servercount[root]++;
                }
            }
        }

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int root=ds.fup(i);
                    if(servercount[root]>1) cnt++;
                }
            }
        }

        return cnt;
    }
};