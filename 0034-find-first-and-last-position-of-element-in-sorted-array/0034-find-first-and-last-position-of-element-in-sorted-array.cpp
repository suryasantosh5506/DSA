class Solution {
public:

    int first(vector<int>&arr,int tgt){
        int n=arr.size();
        int ans=-1;
        int low=0,high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==tgt){
                ans=mid;
                high=mid-1;
            }else if(arr[mid]<tgt) low=mid+1;
            else high=mid-1;
        }
        return ans;
    }

    int last(vector<int>&arr,int tgt){
        int n=arr.size();
        int ans=-1;
        int low=0,high=n-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==tgt){
                ans=mid;
                low=mid+1;
            }else if(arr[mid]<tgt) low=mid+1;
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