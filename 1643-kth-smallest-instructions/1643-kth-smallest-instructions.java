class Solution {

    int dp[][];

    int count(int i,int j,int dest[]){
        if(i==dest[0] && j==dest[1]) return 1;
        if(i>dest[0] || j>dest[1]) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int right=count(i,j+1,dest);
        int down=count(i+1,j,dest);

        return dp[i][j]=right+down;
    }

    public String kthSmallestPath(int[] destination, int k) {
        int r=destination[0],c=destination[1];

        dp=new int[r+1][c+1];

        for(int i=0;i<=r;i++){
            Arrays.fill(dp[i],-1);
        }

        int i=0,j=0;
        StringBuilder ans=new StringBuilder();

        while(i<r || j<c){
            if(j<c){
                int cnt=count(i,j+1,destination);

                if(k<=cnt){
                    ans.append('H');
                    j++;
                }else{
                    ans.append('V');
                    i++;
                    k-=cnt;
                }
            }else{
                ans.append('V');
                i++;
            }
        }
        return ans.toString();
    }
}