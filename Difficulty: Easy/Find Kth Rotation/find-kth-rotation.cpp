class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0,high=arr.size()-1;
        int ans=INT_MAX;
        int index=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]<=arr[mid]){
                if(arr[low]<ans){
                    ans=arr[low];
                    index=low;
                }
                low=mid+1;
            }else{
                if(arr[mid]<ans){
                    ans=arr[mid];
                    index=mid;
                }
                high=mid-1;
            }
        }
        return index;
    }
};
