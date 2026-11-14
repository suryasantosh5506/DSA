class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans;
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};
        bool pac=true;
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        function<bool(int,int)>isvalid=[&](int i,int j){
            return (i>=0 && i<n) && (j>=0 && j<m);
        };

        function<void(int,int)>dfs=[&](int i,int j){
            if(pac) pacific[i][j]=1;
            else atlantic[i][j]=1;

            for(int k=0;k<4;k++){
                int nr=i+dx[k];
                int nc=j+dy[k];

                if(isvalid(nr,nc) && heights[nr][nc]>=heights[i][j] &&
                    ((pac && !pacific[nr][nc]) || (!pac && !atlantic[nr][nc]))){
                    dfs(nr,nc);
                }
            }
        };

        // pacific
        for(int j=0;j<m;j++) if(!pacific[0][j]) dfs(0,j);
        for(int i=0;i<n;i++) if(!pacific[i][0]) dfs(i,0);
        pac=false;
        for(int j=0;j<m;j++) if(!atlantic[n-1][j]) dfs(n-1,j);
        for(int i=0;i<n;i++) if(!atlantic[i][m-1]) dfs(i,m-1);

        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
        return ans;
    }
};