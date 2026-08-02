class Solution {
public:

    vector<vector<vector<int>>>dp;

    int solution(int i,int j,int turn,vector<int>piles){
        if(i==j) return piles[j];
        if(i>j) return 0;
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];

        int ans=0;

        if(turn==0){
            ans=max(ans,piles[i]+solution(i+1,j,1,piles));
            ans=max(ans,piles[j]+solution(i,j-1,1,piles));
        }else{
            ans=min(ans,-piles[i]+solution(i+1,j,0,piles));
            ans=min(ans,-piles[j]+solution(i,j-1,0,piles));
        }
        return dp[i][j][turn]=ans;
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solution(0,n-1,0,piles)>=0;
    }
};