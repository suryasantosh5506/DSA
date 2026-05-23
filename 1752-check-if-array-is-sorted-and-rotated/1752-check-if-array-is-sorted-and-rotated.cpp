class Solution {
public:
    bool check(vector<int>& nums) {
        int bp=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) bp++;
        }
        if(nums[0]<nums[n-1]) bp++;
        return bp<=1;
    }
};