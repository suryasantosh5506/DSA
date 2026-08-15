class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        bool nonzero=false;

        for(int &x:nums){
            xr^=x;
            if(x!=0) nonzero=true;
        }

        if(xr!=0) return n;
        if(nonzero) return n-1;
        return 0;
    }
};