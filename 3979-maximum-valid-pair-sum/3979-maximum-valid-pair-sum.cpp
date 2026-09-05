class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int ans=INT_MIN,maxi=INT_MIN;
        int n=nums.size();
        for(int i=k;i<n;i++){
            maxi=max(maxi,nums[i-k]);
            ans=max(ans,nums[i]+maxi);
        }
        return ans;
    }
};