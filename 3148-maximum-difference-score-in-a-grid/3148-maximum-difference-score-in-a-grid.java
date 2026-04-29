class Solution {

    int n,m;
    int dp[][];
    int ans=Integer.MIN_VALUE;

    int solution(int i,int j,List<List<Integer>> grid){
        if(i>=n || j>=m) return Integer.MIN_VALUE;

        if(dp[i][j]!=-1) return dp[i][j];
        int best=grid.get(i).get(j);

        if(i+1<n){
            int bottom=solution(i+1,j,grid);
            int value=grid.get(i).get(j);
            ans=Math.max(ans,bottom-value);
            best=Math.max(best,bottom);
        }

        if(j+1<m){
            int right=solution(i,j+1,grid);
            int value=grid.get(i).get(j);
            ans=Math.max(ans,right-value);
            best=Math.max(best,right);
        }

        return dp[i][j]=best;
    }

    public int maxScore(List<List<Integer>> grid) {
        n=grid.size();
        m=grid.get(0).size();
        dp=new int[n][m];

        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }

        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
            for(int j=0;j<m;j++){
                solution(i,j,grid);
            }
        }
        return ans;
    }
}