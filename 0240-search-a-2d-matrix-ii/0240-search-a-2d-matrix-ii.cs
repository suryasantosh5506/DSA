public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int n=matrix.Length,m=matrix[0].Length;
        int row=0,col=m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            if(matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
}