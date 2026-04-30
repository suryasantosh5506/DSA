class Solution {

    int n,m;
    int dp[][][];

    int solution(int i,int j,int k,int grid[][]){
        if(i>=n || j>=m) return Integer.MIN_VALUE;
        if(k<0) return Integer.MIN_VALUE;;

        int cost=(grid[i][j]==0)?0:1;
        if(cost>k) return Integer.MIN_VALUE;

        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int right=solution(i,j+1,k-cost,grid);
        int bottom=solution(i+1,j,k-cost,grid);

        int best=Math.max(right,bottom);
        if(best==Integer.MIN_VALUE) return dp[i][j][k]=Integer.MIN_VALUE;
        return dp[i][j][k]=best+grid[i][j];
    }

    public int maxPathScore(int[][] grid, int k) {
        n=grid.length;
        m=grid[0].length;

        dp=new int[n][m][k+1];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }

        int ans=solution(0,0,k,grid);
        return ans==Integer.MIN_VALUE?-1:ans;
    }
}