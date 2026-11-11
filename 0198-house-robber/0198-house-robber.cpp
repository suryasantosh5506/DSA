class Solution {
public:

    int n;
    vector<int>dp;

    int solution(int i,vector<int>&arr){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int maxi=0;
        maxi=max(maxi,arr[i]+solution(i+2,arr));
        maxi=max(maxi,solution(i+1,arr));
        return dp[i]=maxi;
    }

    int rob(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,-1);
        return solution(0,nums);
    }
};