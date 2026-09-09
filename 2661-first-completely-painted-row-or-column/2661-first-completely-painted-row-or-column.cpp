class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>positions;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                positions[mat[i][j]]={i,j};
            }
        }

        vector<int>rows(n,0),cols(m,0);

        for(int i=0;i<arr.size();i++){
            rows[positions[arr[i]].first]++;
            cols[positions[arr[i]].second]++;
            if(rows[positions[arr[i]].first]==m || cols[positions[arr[i]].second]==n) return i;
        }
        return -1;
    }
};