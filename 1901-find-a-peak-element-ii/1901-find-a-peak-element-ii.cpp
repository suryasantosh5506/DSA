class Solution {
public:

    int solution(int col,vector<vector<int>>& mat){
        int n=mat.size();
        int m=mat[0].size();
        int row=-1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                row=i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int col=mid;
            int row=solution(col,mat);
            int left=(col-1>=0)?mat[row][col-1]:-1;
            int right=(col+1<m)?mat[row][col+1]:-1;
            if(left<mat[row][col] && mat[row][col]>right) return {row,col};
            if(left>mat[row][col]) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};