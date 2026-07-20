public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int n=matrix.Length;
        int m=matrix[0].Length;

        int low=0,high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m,col=mid%m;
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
}