class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - x;

        if(target==0) return n;
        if(target<0) return -1;

        unordered_map<int, int> mpp;
        mpp[0] = -1;

        int sum=0;
        int maxi=-1;

        for(int i=0;i<n;i++) {
            sum+=nums[i];

            if(mpp.count(sum-target)) maxi=max(maxi,i-mpp[sum-target]);

            if(!mpp.count(sum)) mpp[sum] = i;
        }

        if(maxi == -1) return -1;

        return n-maxi;
    }
};