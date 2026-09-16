class Solution {
public:

    bool possible(int mid,vector<int>& nums, int threshold){
        int t=0;
        for(int &x:nums){
            t+=(x+mid-1)/mid;
            if(t>threshold) return false;
        }
        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,nums,threshold)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};