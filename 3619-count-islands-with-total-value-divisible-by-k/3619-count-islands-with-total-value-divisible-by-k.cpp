typedef long long ll;
class Solution {
public:

    int n,m;
    vector<int>dx={0,1,0,-1};
    vector<int>dy={-1,0,1,0};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    ll solution(int i,int j,vector<vector<int>>& grid){
        ll ans=grid[i][j];
        grid[i][j]=0;

        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(isValid(nr,nc) && grid[nr][nc]!=0){
                ans+=solution(nr,nc,grid);
            }
        }

        return ans;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ll sum=solution(i,j,grid);
                    if(sum%k==0) ans++;
                }
            }
        }

        return ans;
    }
};