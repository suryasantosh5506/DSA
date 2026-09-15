class Solution {
public:

    int first(vector<int>&nums,int tgt){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==tgt){
                ans=mid;
                high=mid-1;
            }else if(nums[mid]<tgt) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }

    int last(vector<int>&nums,int tgt){
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==tgt){
                ans=mid;
                low=mid+1;
            }else if(nums[mid]<tgt) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int f=first(nums,target);
        if(f==-1) return {-1,-1};
        return {f,last(nums,target)};
    }
};