class Solution {
public:

    int n;
    vector<vector<vector<int>>>dp;

    int solution(int i,int j,int turn,vector<int>&nums){
        if(i>j) return 0;
        if(dp[i][j][turn]!=-1) return dp[i][j][turn];

        int ans=(turn==0)?INT_MIN:INT_MAX;

        if(turn==0){
            ans=max(ans,nums[i]+solution(i+1,j,!turn,nums));
            ans=max(ans,nums[j]+solution(i,j-1,!turn,nums));
        }else{
            ans=min(ans,-nums[i]+solution(i+1,j,!turn,nums));
            ans=min(ans,-nums[j]+solution(i,j-1,!turn,nums));
        }
        return dp[i][j][turn]=ans;
    }

    bool predictTheWinner(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solution(0,n-1,0,nums)>=0;
    }
};