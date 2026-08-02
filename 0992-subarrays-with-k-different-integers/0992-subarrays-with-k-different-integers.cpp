class Solution {
public:

    int solution(vector<int>&nums,int k){
        if(k<=0) return 0;
        int i=0,j=0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        int ans=0;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>k){
                if(--mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solution(nums,k)-solution(nums,k-1);
    }
};