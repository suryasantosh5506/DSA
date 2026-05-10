class Solution {
public:

    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);

        dp[n-1]=0;

        for(int i=n-2;i>=0;i--){
            int maxi=INT_MIN;
            for(int j=i+1;j<n;j++){
                int val=nums[j]-nums[i];
                if(val >= -target && val <= target){
                    int next=dp[j];
                    if(next!=INT_MIN) maxi=max(maxi,1+next);
                }
            }
            dp[i]=maxi;
        }

        int ans=dp[0];
        return (ans==INT_MIN)?-1:ans;
    }
};