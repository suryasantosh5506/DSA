class Solution {
public:

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
        for(auto it:edges){
            dist[it[0]][it[1]]=0;
        }

        for(int i=0;i<n;i++) dist[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j]) {
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }

        vector<bool>ans;
        for(auto it:queries){
            ans.emplace_back(dist[it[0]][it[1]]!=INT_MAX);
        }
        return ans;
    }
};