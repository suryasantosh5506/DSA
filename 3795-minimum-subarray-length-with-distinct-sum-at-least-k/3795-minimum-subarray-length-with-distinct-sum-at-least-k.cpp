class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        int i=0,j=0;
        int sum=0;
        unordered_map<int,int>mpp;
        while(j<n){
            if(!mpp.count(nums[j])) sum+=nums[j];
            mpp[nums[j]]++;
            while(sum>=k){
                if(mpp[nums[i]]==1) sum-=nums[i];
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                ans=min(ans,j-i+1);
                i++;
            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};