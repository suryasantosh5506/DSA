class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        const int mod=1e9+7;
        vector<int>ones;
        for(int i=0;i<n;i++) if(nums[i]==1) ones.emplace_back(i);
        if(ones.size()==0) return 0;
        if(ones.size()==1 || ones.size()==n) return 1;
        int ans=1;
        for(int i=1;i<ones.size();i++) ans=(1ll*ans*(ones[i]-ones[i-1])%mod)%mod;
        return ans;
    }
};