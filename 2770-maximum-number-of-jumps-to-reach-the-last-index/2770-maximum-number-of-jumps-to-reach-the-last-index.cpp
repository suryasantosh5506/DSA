class Solution {
public:

    int n;
    vector<int>dp;

    int solution(int i,int tgt,vector<int>&nums){
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int maxi=INT_MIN;
        for(int j=i+1;j<n;j++){
            int val=nums[j]-nums[i];
            if(val >= -tgt && val <= tgt){
                int next=solution(j,tgt,nums);
                if(next!=INT_MIN) maxi=max(maxi,1+next);
            }
        }
        return dp[i]=maxi;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n=nums.size();
        dp.assign(n,-1);
        int ans=solution(0,target,nums);
        return (ans==INT_MIN)?-1:ans;
    }
};