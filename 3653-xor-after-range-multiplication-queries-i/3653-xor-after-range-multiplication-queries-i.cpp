class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto it:queries){
            const int mod = 1e9 + 7;
            for(int i=it[0];i<=it[1];i+=it[2]){
                nums[i]=(1ll*nums[i]*it[3])%mod;
            }
        }

        int ans=0;
        for(auto it:nums){
            ans^=it;
        }
        return ans;
    }
};