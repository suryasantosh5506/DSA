class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>mpp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                mpp[i+j].emplace_back(nums[i][j]);
            }
        }

        vector<int>ans;
        for(auto it:mpp){
            reverse(it.second.begin(),it.second.end());
            ans.insert(ans.end(),it.second.begin(),it.second.end());
        }
        return ans;
    }
};