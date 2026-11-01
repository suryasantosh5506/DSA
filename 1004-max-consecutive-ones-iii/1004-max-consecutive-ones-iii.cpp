class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int zeroes=0;
        int maxi=0;
        while(j<n){
            zeroes+=(nums[j]==0);
            while(zeroes>k) zeroes-=(nums[i++]==0);
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};