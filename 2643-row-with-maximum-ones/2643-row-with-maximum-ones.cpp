class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=0;
        int maxi=0;

        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1) cnt++;
            }
            if(cnt>maxi){
                maxi=cnt;
                row=i;
            }
        }
        return {row,maxi};
    }
};