class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>diff(n,vector<int>(m,0));

        vector<int>onesrow(n,0);
        vector<int>onescol(m,0);
        vector<int>zerosrow(n,0);
        vector<int>zeroscol(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    zerosrow[i]++;
                    zeroscol[j]++;
                }
                if(grid[i][j]==1){
                    onesrow[i]++;
                    onescol[j]++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                diff[i][j]=onesrow[i]+onescol[j]-zerosrow[i]-zeroscol[j];
            }
        }

        return diff;
    }
};