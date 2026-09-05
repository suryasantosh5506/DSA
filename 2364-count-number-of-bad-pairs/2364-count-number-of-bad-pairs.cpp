typedef long long ll;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll cnt=0;
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            cnt+=mpp[i-nums[i]];
            mpp[i-nums[i]]++;
        }
        ll total=1LL*n*(n-1)/2;
        return total-cnt;
    }
};