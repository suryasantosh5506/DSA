typedef long long ll;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        ll ans=0;
        int n=nums.size();
        int i=0,j=0;
        int maxele=*max_element(nums.begin(),nums.end());
        int cnt=0;
        while(j<n){
            cnt+=(nums[j]==maxele);
            while(cnt>=k){
                ans+=(n-j);
                cnt-=(nums[i]==maxele);
                i++;
            }
            j++;
        }
        return ans;
    }
};