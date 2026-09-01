class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(auto &it:nums){
            sort(it.rbegin(),it.rend());
        }
        int ans=0;
        int n=nums.size(),m=nums[0].size();

        for(int j=0;j<m;j++){
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                maxi=max(maxi,nums[i][j]);;
            }
            ans+=maxi;
        }
        return ans;
    }
};