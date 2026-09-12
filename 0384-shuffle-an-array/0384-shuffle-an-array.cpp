class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int>ans=nums;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=rand()%(i+1);
            swap(ans[i],ans[j]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */