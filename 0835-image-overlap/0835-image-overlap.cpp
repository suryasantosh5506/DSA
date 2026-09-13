class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>>a,b;
        int n=img1.size(),m=img1[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1) a.push_back({i,j});
                if(img2[i][j]==1) b.push_back({i,j});
            }
        }

        map<pair<int,int>,int>mpp;
        int ans=0;
        for(auto it:a){
            for(auto itt:b){
                int dx=itt[0]-it[0];
                int dy=itt[1]-it[1];
                mpp[{dx,dy}]++;
                ans=max(ans,mpp[{dx,dy}]);
            }
        }
        return ans;
    }
};