class Solution {
public:

    int solution(vector<int>&nums,int k){
        int zeroes=0;
        int i=0,j=0;
        int maxi=0;
        int n=nums.size();
        while(j<n){
            zeroes+=(nums[j]%2==0);
            while(zeroes>k) zeroes-=(nums[i++]%2==0);
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }

    int longestOnes(vector<int>& nums, int k) {
        return solution(nums,k);   
    }
};