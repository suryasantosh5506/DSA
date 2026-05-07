class Solution {
    public int[] rowAndMaximumOnes(int[][] mat) {
        int row=0;
        int maxi=0;

        int n=mat.length;
        int m=mat[0].length;

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
        return new int[] {row,maxi};
    }
}