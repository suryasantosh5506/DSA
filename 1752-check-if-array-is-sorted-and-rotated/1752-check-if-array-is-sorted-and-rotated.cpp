class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int bps=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) bps++;
        }

        if(nums[0]<nums[n-1]) bps++;

        return bps<=1;
    }
};