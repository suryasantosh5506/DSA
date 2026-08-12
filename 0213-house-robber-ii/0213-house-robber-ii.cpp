class Solution {
public:

    int n;
    vector<int>dp;

    int solution(int i,vector<int>&nums){
        if(i==n-1) return nums[i];
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int take=nums[i]+solution(i+2,nums);
        int nottake=solution(i+1,nums);

        return dp[i]=max(take,nottake);
    }

    int sol(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,-1);
        return solution(0,nums);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>first(nums.begin()+1,nums.end());
        vector<int>second(nums.begin(),nums.end()-1);
        return max(sol(first),sol(second));
    }
};