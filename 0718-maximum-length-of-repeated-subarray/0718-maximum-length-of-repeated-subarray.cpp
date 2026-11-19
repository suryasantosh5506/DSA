class Solution {
public:

    vector<int>arr1,arr2;
    int n,m;
    vector<vector<int>>dp;

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1,arr2=nums2;
        n=arr1.size(),m=arr2.size();
        dp.assign(n+1,vector<int>(m+1,0));
        int ans=-1e8;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(arr1[i]==arr2[j]){
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                }
                ans=max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};