class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>occ;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==x) occ.emplace_back(i);
        }
        vector<int>ans;
        for(int x:queries){
            if(x>occ.size()) ans.emplace_back(-1);
            else ans.emplace_back(occ[x-1]);
        }
        return ans;
    }
};