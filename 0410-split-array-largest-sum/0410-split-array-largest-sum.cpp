class Solution {
public:

    bool possible(int mid,vector<int>& nums, int k){
        int stu=1;
        int sum=0;
        for(int &x:nums){
            if(sum+x>mid){
                stu++;
                sum=0;
            }
            sum+=x;
            if(stu>k) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,nums,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};