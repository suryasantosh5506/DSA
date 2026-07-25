class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>lmin(n),rmax(n);
        lmin[0]=nums[0];
        for(int i=1;i<n;i++){
            lmin[i]=min(nums[i],lmin[i-1]);
        }
        rmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],nums[i]);
        }

        for(int i=1;i<n-1;i++){
            if(lmin[i-1]<nums[i] && nums[i]<rmax[i+1]) return true;
        }
        return false;
    }
};