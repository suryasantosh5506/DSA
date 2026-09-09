typedef long long ll;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int i=0,j=0;
        int n=nums.size();
        ll sum=0;
        ll ans=LLONG_MIN;
        while(j<n){
            sum+=nums[j];
            mpp[nums[j]]++;
            while((j-i+1)>k || mpp[nums[j]]>1){
                sum-=nums[i];
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                i++;
            }
            if(j-i+1==k) ans=max(ans,sum);
            j++;
        }
        return ans==LLONG_MIN?0:ans;
    }
};