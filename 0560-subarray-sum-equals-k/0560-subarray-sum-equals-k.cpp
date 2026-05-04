class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum=0;
        mpp[0]=1;
        int ans=0;

        for(auto x:nums){
            sum+=x;
            ans+=mpp[sum-k];
            mpp[sum]++;
        }
        return ans;
    }
};