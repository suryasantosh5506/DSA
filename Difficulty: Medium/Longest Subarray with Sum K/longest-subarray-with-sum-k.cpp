class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum=0;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int n=arr.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(mpp.find(sum-k)!=mpp.end()){
                ans=max(ans,i-mpp[sum-k]);
            }
            if(mpp.find(sum)==mpp.end()) mpp[sum]=i;
        }
        return ans;
    }
};