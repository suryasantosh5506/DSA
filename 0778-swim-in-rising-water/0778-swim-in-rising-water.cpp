class DisJointSet {
    vector<int> parent, rank;
public:
    DisJointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findUltimateParent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
private:
    bool isValid(int i,int j,int n){
        return (i>=0&&i<n)&&(j>=0&&j<n);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        DisJointSet ds(n*n);
        vector<vector<int>>nodes;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                nodes.push_back({grid[i][j],i,j});
            }
        }
        sort(nodes.begin(),nodes.end());
        vector<int> possrow = {-1,0,1,0};
        vector<int> posscol = {0,1,0,-1};

        vector<vector<int>>visited(n,vector<int>(n,0));
        for(auto node:nodes){
            int t=node[0];
            int row=node[1];
            int col=node[2];

            visited[row][col]=1;

            for(int i=0;i<4;i++){
                int neigh_row=row+possrow[i];
                int neigh_col=col+posscol[i];

                if(isValid(neigh_row,neigh_col,n)&&visited[neigh_row][neigh_col]==1){
                    int nodenum=row*n+col;
                    int neigh_node=neigh_row*n+neigh_col;
                    ds.unionByRank(nodenum,neigh_node);
                }
            }

            if(ds.findUltimateParent(0)==ds.findUltimateParent(n*n-1)){
                return t;
            }
        }
        return -1;
    }
};