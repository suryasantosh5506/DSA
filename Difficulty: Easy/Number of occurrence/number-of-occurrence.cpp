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
  
    int countFreq(vector<int>& arr, int target) {
        // code here
        int f=first(arr,target);
        if(f==-1) return 0;
        return last(arr,target)-f+1;
        
    }
};
