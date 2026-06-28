class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]!=0) return false;

        vector<pair<int,int>>arr(n*m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[grid[i][j]]={i,j};
            }
        }

        for(int i=1;i<n*m;i++){
            bool cond1=abs(arr[i].first-arr[i-1].first)==2 && 
                        abs(arr[i].second-arr[i-1].second)==1;
            bool cond2=abs(arr[i].first-arr[i-1].first)==1 && 
                        abs(arr[i].second-arr[i-1].second)==2;
            if(!cond1 && !cond2) return false;
        }
        return true;
    }
};