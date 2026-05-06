class Solution {

    int first(int arr[],int tgt){
        int n=arr.length;
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

    int last(int arr[],int tgt){
        int n=arr.length;
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

    public int[] searchRange(int[] nums, int target) {
        int f=first(nums,target);
        if(f==-1) return new int[]{-1,-1};
        return new int[]{f,last(nums,target)};
    }
}