class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int zeroes=0;
        int ans=0;

        while(i<n){
            if(nums[i]==0) zeroes++;
            while(zeroes>k){
                if(nums[j]==0) zeroes--;
                j++;
            }
            ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};