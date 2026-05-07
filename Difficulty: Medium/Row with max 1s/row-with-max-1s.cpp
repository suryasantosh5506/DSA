// User function template for C++
class Solution {
  public:
  
    int blackbox(vector<int>&arr){
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==1) high=mid-1;
            else low=mid+1;
        }
        return n-low;
    }
  
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int maxi=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            int ones=blackbox(arr[i]);
            if(ones>maxi){
                maxi=ones;
                ans=i;
            }
        }
        return ans;
    }
};