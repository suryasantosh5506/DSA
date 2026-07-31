class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int total=pow(2,n);
        vector<vector<int>>ans;
        for(int i=0;i<total;i++){
            vector<int>seq;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) seq.emplace_back(nums[j]);
            }
            ans.emplace_back(seq);
        }
        return ans;
    }
};