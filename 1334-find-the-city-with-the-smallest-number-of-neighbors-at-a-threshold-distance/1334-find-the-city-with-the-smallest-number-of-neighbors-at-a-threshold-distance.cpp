class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>dist(n,vector<int>(n,1e8));

        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        int l=1e8;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=l && dist[k][j]!=l && dist[i][j]>dist[i][k]+dist[k][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        int mini=INT_MAX;
        int ans=-1;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold) cnt++;
            }

            if(cnt<=mini){
                mini=cnt;
                ans=i;
            }
        }
        return ans;
    }
};