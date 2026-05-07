class Solution {
public:

    int solution(int col,vector<vector<int>>& mat){
        int maxi=INT_MIN;
        int row=-1;
        int n=mat.size();

        for(int i=0;i<n;i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                row=i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=solution(mid,mat);
            int left=(mid-1>=0)?mat[row][mid-1]:-1;
            int right=(mid+1<m)?mat[row][mid+1]:-1;

            if(left<mat[row][mid] && mat[row][mid]>right) return {row,mid};
            if(left<mat[row][mid]) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};