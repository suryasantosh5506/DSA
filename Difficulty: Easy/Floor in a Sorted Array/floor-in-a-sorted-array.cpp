class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=x) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};
