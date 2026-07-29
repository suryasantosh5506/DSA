class Solution {
public:

    vector<vector<int>>ans;
    vector<int>seq;

    void solution(int i,vector<int>&nums){
        if(i==nums.size()){
            ans.emplace_back(seq);
            return;
        }

        seq.emplace_back(nums[i]);
        solution(i+1,nums);
        seq.pop_back();
        solution(i+1,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solution(0,nums);
        return ans;
    }
};