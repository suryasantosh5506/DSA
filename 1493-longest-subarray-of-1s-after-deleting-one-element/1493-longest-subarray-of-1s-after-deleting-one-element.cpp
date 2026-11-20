class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        int maxi=0;
        int deleted=0;
        while(j<n){
            deleted+=(nums[j]==0);
            while(deleted>1) deleted-=(nums[i++]==0);
            maxi=max(maxi,j-i+1-deleted);
            j++;
        }
        return (maxi==n)?n-1:maxi;
    }
};