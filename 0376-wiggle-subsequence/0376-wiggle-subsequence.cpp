class Solution {
public:

    int n;
    vector<vector<vector<int>>>dp;

    // sign=0->+
    // sign=1->-

    int solution(int i,int sign,int prev,vector<int>&nums){
        if(i==n) return 0;
        if(dp[i][sign][prev]!=-1) return dp[i][sign][prev];

        int ans=0;
        for(int j=i;j<n;j++){
            if(sign==0 && nums[j]-nums[prev]>0){
                ans=max(ans,1+solution(j+1,!sign,j,nums));
            }else if(sign==1 && nums[j]-nums[prev]<0){
                ans=max(ans,1+solution(j+1,!sign,j,nums));
            }
        }
        return dp[i][sign][prev]=ans;
    }

    int wiggleMaxLength(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(n,-1)));
        return 1+max(solution(1,0,0,nums),solution(1,1,0,nums));
    }
};